/***
 * Demonstrike Core
 */

#include "StdAfx.h"

#define BANNER "Sandshroud Hearthstone %s::%s r%u/%s-%s-%s :: World Server\n"

createFileSingleton( Master );
std::string LogFileName;
bool bLogChat;
bool crashed = false;

volatile bool Master::m_stopEvent;

// Database defines.
SERVER_DECL Database* Database_Character;
SERVER_DECL Database* Database_World;
SERVER_DECL Database* Database_Log;

void Master::_OnSignal(int s)
{
	switch (s)
	{
#ifndef WIN32
	case SIGHUP:
		sWorld.Rehash(true);
		break;
#endif
	case SIGINT:
	case SIGTERM:
	case SIGABRT:
#ifdef _WIN32
	case SIGBREAK:
#endif
		remove( "hearthstone-world.pid" );
		Master::m_stopEvent = true;
		break;
	}

	signal(s, _OnSignal);
}

Master::Master()
{

}

Master::~Master()
{

}

struct Addr
{
	unsigned short sa_family;
	/* sa_data */
	unsigned short Port;
	unsigned long IP; // inet_addr
	unsigned long unusedA;
	unsigned long unusedB;
};

#define DEF_VALUE_NOT_SET 0xDEADBEEF

#ifdef WIN32
static const char* default_config_file = "./hearthstone-world.ini";
#else
static const char* default_config_file = (char*)CONFDIR "/hearthstone-world.ini";
#endif

bool bServerShutdown = false;
bool StartConsoleListener();
void CloseConsoleListener();
ThreadContext * GetConsoleListener();

bool Master::Run(int argc, char ** argv)
{
	m_stopEvent = false;
	char * config_file = (char*)default_config_file;
	int screen_log_level = DEF_VALUE_NOT_SET;
	int do_check_conf = 0;
	int do_version = 0;
	int do_cheater_check = 0;
	int do_database_clean = 0;
	time_t curTime;

	struct hearthstone_option longopts[] =
	{
		{ "checkconf",			hearthstone_no_argument,			&do_check_conf,			1		},
		{ "screenloglevel",		hearthstone_required_argument,		&screen_log_level,		1		},
		{ "version",			hearthstone_no_argument,			&do_version,			1		},
		{ "cheater",			hearthstone_no_argument,			&do_cheater_check,		1		},
		{ "cleandb",			hearthstone_no_argument,			&do_database_clean,		1		},
		{ "conf",				hearthstone_required_argument,		NULL,					'c'		},
		{ "realmconf",			hearthstone_required_argument,		NULL,					'r'		},
		{ 0, 0, 0, 0 }
	};

	char c;
	while ((c = hearthstone_getopt_long_only(argc, argv, ":f:", longopts, NULL)) != -1)
	{
		switch (c)
		{
		case 'c':
			config_file = new char[strlen(hearthstone_optarg)];
			strcpy(config_file, hearthstone_optarg);
			break;
		case 0:
			break;
		default:
			sLog.m_screenLogLevel = 3;
			printf("Usage: %s [--checkconf] [--conf <filename>] [--realmconf <filename>] [--version]\n", argv[0]);
			return true;
		}
	}

	/* set new log levels if used as argument*/
	if( screen_log_level != (int)DEF_VALUE_NOT_SET )
		sLog.SetScreenLoggingLevel(screen_log_level);

	// Startup banner
	UNIXTIME = time(NULL);
	g_localTime = *localtime(&UNIXTIME);

	printf(BANNER, BUILD_TAG, BUILD_HASH_STR, BUILD_REVISION, CONFIG, PLATFORM_TEXT, ARCH);
	Log.Line();

	printf( "The key combination <Ctrl-C> will safely shut down the server at any time.\n" );
	Log.Line();

#ifndef WIN32
	if(geteuid() == 0 || getegid() == 0)
		Log.LargeErrorMessage( LARGERRORMESSAGE_WARNING, "You are running Hearthstone as root.", "This is not needed, and may be a possible security risk.", "It is advised to hit CTRL+C now and", "start as a non-privileged user.", NULL);
#endif

	InitRandomNumberGenerators();
	Log.Success( "Rnd", "Initialized Random Number Generators." );

	mainIni = new CIniFile(config_file);
	uint32 LoadingTime = getMSTime();
	Log.Notice( "Config", "Loading Config Files..." );
	if( !mainIni->ParseError() )
		Log.Success( "Config", ">> hearthstone-world.conf" );
	else
	{
		Log.Error( "Config", ">> hearthstone-world.conf" );
		return false;
	}

	//use these log_level until we are fully started up.
	if(mainIni->ReadInteger("LogLevel", "Screen", 1) == -1)
	{
		Log.Notice("Master", "Running silent mode...");
		sLog.Init(-1);
	}
	else
#ifdef _DEBUG
		sLog.Init(3);
#else
		sLog.Init(1);
#endif // _DEBUG

	sDBEngine.Init(false);

	if(!_StartDB())
	{
		Database::CleanupLibs();
		return false;
	}

	Log.Line();
	sLog.outString("");

	new EventMgr();
	EventableObjectHolder* m_Holder = new EventableObjectHolder(-1);

	new World();

	/* load the config file */
	sWorld.Rehash(true);

	// Because of our log DB system, these have to be initialized different then rehash.
	sWorld.LogCheaters = mainIni->ReadBoolean("Log", "Cheaters", false);
	sWorld.LogCommands = mainIni->ReadBoolean("Log", "GMCommands", false);
	sWorld.LogPlayers = mainIni->ReadBoolean("Log", "Player", false);
	sWorld.LogChats = mainIni->ReadBoolean("Log", "Chat", false);

	//Update sLog to obey config setting
	sLog.Init(mainIni->ReadInteger("LogLevel", "Screen", 1));

	// Initialize Opcode Table
	WorldSession::InitPacketHandlerTable();

	string host = mainIni->ReadString( "Listen", "Host", DEFAULT_HOST );
	int wsport = mainIni->ReadInteger( "ServerSettings", "WorldServerPort", DEFAULT_WORLDSERVER_PORT );

	new ScriptMgr();

	if( !sWorld.SetInitialWorldSettings() )
	{
		Log.Error( "Server", "SetInitialWorldSettings() failed. Something went wrong? Exiting." );
		return false;
	}

	sWorld.SetStartTime(uint32(UNIXTIME));

	WorldRunnable * wr = new WorldRunnable(m_Holder);
	ThreadPool.ExecuteTask("WorldRunnable", wr);

	_HookSignals();

	ConsoleThread* console = new ConsoleThread();
	ThreadPool.ExecuteTask("ConsoleThread", console);

	uint32 realCurrTime, realPrevTime;
	realCurrTime = realPrevTime = getMSTime();

	// Socket loop!
	uint32 start = 0, last_time = getMSTime(), etime = 0;

	// Start Network Subsystem
	DEBUG_LOG("Server","Starting network subsystem..." );
	CreateSocketEngine(8);
	sSocketEngine.SpawnThreads();

	if( StartConsoleListener() )
		Log.Success("RemoteConsole", "Started and listening on port %i", mainIni->ReadInteger("RemoteConsole", "Port", 8092));
	else
		DEBUG_LOG("RemoteConsole", "Not enabled or failed listen.");

	LoadingTime = getMSTime() - LoadingTime;
	Log.Success("Server","Ready for connections. Startup time: %ums\n", LoadingTime );

	/* write pid file */
	FILE * fPid = fopen( "hearthstone-world.pid", "w" );
	if( fPid )
	{
		uint32 pid;
#ifdef WIN32
		pid = GetCurrentProcessId();
#else
		pid = getpid();
#endif
		fprintf( fPid, "%u", uint(pid) );
		fclose( fPid );
	}
#ifdef WIN32
	HANDLE hThread = GetCurrentThread();
#endif

	uint32 loopcounter = 0, LastLogonUpdate = getMSTime();
	if(mainIni->ReadInteger("LogLevel", "Screen", 1) == -1)
	{
		sLog.Init(1);
		Log.Notice("Master", "Leaving Silent Mode...");
	}

	/* Connect to realmlist servers / logon servers */
	new LogonCommHandler();
	sLogonCommHandler.Startup();

	ListenSocket<WorldSocket> * ls = new ListenSocket<WorldSocket>();
	bool listnersockcreate = ls->Open(host.c_str(), wsport);

	while( !m_stopEvent && listnersockcreate )
	{
		start = getMSTime();

		/* since time() is an expensive system call, we only update it once per server loop */
		curTime = time(NULL);
		if( UNIXTIME != curTime )
		{
			UNIXTIME = time(NULL);
			g_localTime = *localtime(&curTime);
			UpdateRandomNumberGenerators();
		}

		sLogonCommHandler.UpdateSockets(getMSTime()-LastLogonUpdate);
		LastLogonUpdate = getMSTime();
		sSocketDeleter.Update();

		/* UPDATE */
		last_time = getMSTime();
		etime = last_time - start;
		if( 25 > etime )
		{
#if PLATFORM == PLATFORM_WIN
			WaitForSingleObject( hThread, 25 - etime );
#else
			Sleep( 25 - etime );
#endif
		}
	}
	// begin server shutdown
	Log.Notice( "Shutdown", "Initiated at %s", ConvertTimeStampToDataTime( (uint32)UNIXTIME).c_str() );
	bServerShutdown = true;

	if( lootmgr.is_loading )
	{
		Log.Notice( "Shutdown", "Waiting for loot to finish loading..." );
		while( lootmgr.is_loading )
			Sleep( 100 );
	}

	sDBEngine.EndThreads();

	if(sWorld.LacrimiThread != NULL) // Shut this down first...
	{
		sWorld.LacrimiThread->SelfTerminate();

		Log.Notice( "Shutdown", "Waiting for Lacrimi to finish shutting down..." );
		while(sWorld.LacrimiThread->GetThreadState() == THREADSTATE_SELF_TERMINATE)
			Sleep(100);
	}

	Log.Notice( "Database", "Clearing all pending queries..." );

	// kill the database thread first so we don't lose any queries/data
	CharacterDatabase.EndThreads();
	WorldDatabase.EndThreads();

	if(Database_Log)
		LogDatabase.EndThreads();

	guildmgr.SaveAllGuilds();
	sWorld.LogoutPlayers(); //(Also saves players).
	CharacterDatabase.Execute("UPDATE characters SET online = 0");

	Log.Notice("Server", "Shutting down random generator.");
	CleanupRandomNumberGenerators();

	ls->Disconnect();

	Log.Notice( "Network", "Shutting down network subsystem." );
	sSocketEngine.Shutdown();

	sAddonMgr.SaveToDB();
	Log.Notice("AddonMgr", "~AddonMgr()");
	delete AddonMgr::getSingletonPtr();

	Log.Notice("LootMgr", "~LootMgr()");
	delete LootMgr::getSingletonPtr();

	Log.Notice("MailSystem", "~MailSystem()");
	delete MailSystem::getSingletonPtr();

	/* Shut down console system */
	CloseConsoleListener();
	console->terminate();
	delete console;

	Log.Notice("Thread", "Terminating thread pool...");
	ThreadPool.Shutdown();

	ls = NULL;

	Log.Notice( "Network", "Deleting Network Subsystem..." );
	{
		/* delete the socket deleter */
		delete SocketDeleter::getSingletonPtr();

		/* delete the socket engine */
		delete SocketEngine::getSingletonPtr();

		/* WSA network cleanup */
		WSACleanup();
	}

	Log.Notice("InsertQueueLoader", "~InsertQueueLoader()");
	delete InsertQueueLoader::getSingletonPtr();

	Log.Notice("LogonComm", "~LogonCommHandler()");
	delete LogonCommHandler::getSingletonPtr();

	Log.Notice( "World", "~World()" );
	sWorld.Destruct();
//	delete World::getSingletonPtr();

	Log.Notice( "ScriptMgr", "~ScriptMgr()" );
	sScriptMgr.UnloadScripts();
	delete ScriptMgr::getSingletonPtr();

	Log.Notice( "EventMgr", "~EventMgr()" );
	delete EventMgr::getSingletonPtr();

	Log.Notice( "Database", "Closing Connections..." );
	_StopDB();

	_UnhookSignals();

	// remove pid
	remove( "hearthstone-world.pid" );

	Log.Notice( "Shutdown", "Shutdown complete." );
	return true;
}

bool Master::_StartDB()
{
	SYSTEM_INFO sysinfo;
	GetSystemInfo( &sysinfo );

	string error;
	// Configure World Database...
	string hostname = mainIni->ReadString("WorldDatabase", "Hostname", "ERROR");
	string username = mainIni->ReadString("WorldDatabase", "Username", "ERROR");
	string password = mainIni->ReadString("WorldDatabase", "Password", "ERROR");
	string database = mainIni->ReadString("WorldDatabase", "Name", "ERROR");
	int port = mainIni->ReadInteger("WorldDatabase", "Port", 0);
	int type = mainIni->ReadInteger("WorldDatabase", "Type", 0);
	if(strcmp(hostname.c_str(), "ERROR") == 0)
		error.append("Hostname");
	else if(strcmp(username.c_str(), "ERROR") == 0)
		error.append("Username");
	else if(strcmp(password.c_str(), "ERROR") == 0)
		error.append("Password");
	else if(strcmp(database.c_str(), "ERROR") == 0)
		error.append("DatabaseName");
	else if(port == 0 || type == 0)
		error.append("Port/Type");
	if(error.length())
	{
		sLog.outError("sql: World database parameter not found for %s.", error.c_str());
		return false;
	}

	Database_World = Database::Create();
	// Initialize it
	if( !WorldDatabase.Initialize(hostname.c_str(), uint(port), username.c_str(),
		password.c_str(), database.c_str(), mainIni->ReadInteger("WorldDatabase", "ConnectionCount", sysinfo.dwNumberOfProcessors), 16384 ) )
	{
		OUT_DEBUG( "sql: Main database initialization failed. Exiting." );
		return false;
	}

	hostname = mainIni->ReadString("CharacterDatabase", "Hostname", "ERROR");
	username = mainIni->ReadString("CharacterDatabase", "Username", "ERROR");
	password = mainIni->ReadString("CharacterDatabase", "Password", "ERROR");
	database = mainIni->ReadString("CharacterDatabase", "Name", "ERROR");
	port = mainIni->ReadInteger("CharacterDatabase", "Port", 0);
	type = mainIni->ReadInteger("CharacterDatabase", "Type", 0);
	if(strcmp(hostname.c_str(), "ERROR") == 0)
		error.append("Hostname");
	else if(strcmp(username.c_str(), "ERROR") == 0)
		error.append("Username");
	else if(strcmp(password.c_str(), "ERROR") == 0)
		error.append("Password");
	else if(strcmp(database.c_str(), "ERROR") == 0)
		error.append("DatabaseName");
	else if(port == 0 || type == 0)
		error.append("Port/Type");
	if(error.length())
	{
		sLog.outError("sql: Character database parameter not found for %s.", error.c_str());
		return false;
	}

	Database_Character = Database::Create();
	// Initialize it
	if( !CharacterDatabase.Initialize( hostname.c_str(), uint(port), username.c_str(),
		password.c_str(), database.c_str(), mainIni->ReadInteger( "CharacterDatabase", "ConnectionCount", sysinfo.dwNumberOfProcessors), 16384 ) )
	{
		OUT_DEBUG( "sql: Main database initialization failed. Exiting." );
		return false;
	}

	Database_Log = NULL;
	if(mainIni->ReadBoolean("Log", "Cheaters", false) || mainIni->ReadBoolean("Log", "GMCommands", false)
		|| mainIni->ReadBoolean("Log", "Player", false) || mainIni->ReadBoolean("Log", "Chat", false))
	{
		hostname = mainIni->ReadString("LogDatabase", "Hostname", "ERROR");
		username = mainIni->ReadString("LogDatabase", "Username", "ERROR");
		password = mainIni->ReadString("LogDatabase", "Password", "ERROR");
		database = mainIni->ReadString("LogDatabase", "Name", "ERROR");
		port = mainIni->ReadInteger("LogDatabase", "Port", 0);
		type = mainIni->ReadInteger("LogDatabase", "Type", 0);
		if(strcmp(hostname.c_str(), "ERROR") == 0)
			error.append("Hostname");
		else if(strcmp(username.c_str(), "ERROR") == 0)
			error.append("Username");
		else if(strcmp(password.c_str(), "ERROR") == 0)
			error.append("Password");
		else if(strcmp(database.c_str(), "ERROR") == 0)
			error.append("DatabaseName");
		else if(port == 0 || type == 0)
			error.append("Port/Type");
		if(error.length())
		{
			sLog.outError("sql: Log database parameter not found for %s.", error.c_str());
			return false;
		}

		Database_Log = Database::Create();
		// Initialize it
		if( !(LogDatabase.Initialize( hostname.c_str(), uint(port), username.c_str(),
			password.c_str(), database.c_str(), mainIni->ReadInteger( "LogDatabase", "ConnectionCount", 2 ), 16384 )) )
		{
			OUT_DEBUG( "sql: Log database initialization failed. Exiting." );
			return false;
		}
	}

	return true;
}

void Master::_StopDB()
{
	delete Database_World;
	delete Database_Character;

	if(Database_Log)
		delete Database_Log;
}

#ifndef WIN32
// Unix crash handler :oOoOoOoOoOo
volatile bool m_crashed = false;
void segfault_handler(int c)
{
	if( m_crashed )
	{
		abort();
		return;		// not reached
	}

	m_crashed = true;

	printf ("Segfault handler entered...\n");
	try
	{
		if( World::getSingletonPtr() != 0 )
		{
			sLog.outString( "Waiting for all database queries to finish..." );
			if(Database_Log)
				LogDatabase.EndThreads();
			WorldDatabase.EndThreads();

			sLog.outString( "All pending database operations cleared.\n" );
			sWorld.SaveAllPlayers();
			guildmgr.SaveAllGuilds();
			objmgr.CorpseCollectorUnload(true);
			CharacterDatabase.EndThreads();
			sLog.outString( "Data saved." );
		}
	}
	catch(...)
	{
		sLog.outString( "Threw an exception while attempting to save all data." );
	}

	printf("Writing coredump...\n");
	abort();
}
#endif


void Master::_HookSignals()
{
	signal( SIGINT, _OnSignal );
	signal( SIGTERM, _OnSignal );
	signal( SIGABRT, _OnSignal );
#ifdef _WIN32
	signal( SIGBREAK, _OnSignal );
#else
	signal( SIGHUP, _OnSignal );
	signal(SIGUSR1, _OnSignal);

	// crash handler
	signal(SIGSEGV, segfault_handler);
	signal(SIGFPE, segfault_handler);
	signal(SIGILL, segfault_handler);
	signal(SIGBUS, segfault_handler);
#endif
}

void Master::_UnhookSignals()
{
	signal( SIGINT, 0 );
	signal( SIGTERM, 0 );
	signal( SIGABRT, 0 );
#ifdef _WIN32
	signal( SIGBREAK, 0 );
#else
	signal( SIGHUP, 0 );
#endif
}

#ifdef WIN32

Mutex m_crashedMutex;

// Crash Handler
void OnCrash( bool Terminate )
{
	sLog.outString( "Advanced crash handler initialized." );

	if( !m_crashedMutex.AttemptAcquire() )
		TerminateThread( GetCurrentThread(), 0 );

	try
	{
		if( World::getSingletonPtr() != 0 )
		{
			sLog.outString( "Waiting for all database queries to finish..." );
			if(Database_Log)
				LogDatabase.EndThreads();

			WorldDatabase.EndThreads();
			sWorld.SaveAllPlayers();
			guildmgr.SaveAllGuilds();
			objmgr.CorpseCollectorUnload(true);
			CharacterDatabase.EndThreads();

			sLog.outString( "All pending database operations cleared.\n" );
			sLog.outString( "Data saved." );
		}
	}
	catch(...)
	{
		sLog.outString( "Threw an exception while attempting to save all data." );
	}

	sLog.outString( "Closing." );

	// Terminate Entire Application
	if( Terminate )
	{
		HANDLE pH = OpenProcess( PROCESS_TERMINATE, TRUE, GetCurrentProcessId() );
		TerminateProcess( pH, 1 );
		CloseHandle( pH );
	}
}

#endif