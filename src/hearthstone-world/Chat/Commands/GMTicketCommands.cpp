/***
 * Demonstrike Core
 */

#include "StdAfx.h"

#ifdef GM_TICKET_MY_MASTER_COMPATIBLE

bool ChatHandler::HandleGMTicketListCommand(const char* args, WorldSession *m_session)
{
    Player *cplr = m_session->GetPlayer();

    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    chn->Say(cplr, "GmTicket 2", cplr, true);

    for(GmTicketList::iterator itr = objmgr.GM_TicketList.begin(); itr != objmgr.GM_TicketList.end(); itr++)
    {
        if((*itr)->deleted)
            continue;

        Player* plr = objmgr.GetPlayer((uint32)(*itr)->playerGuid);

        if( plr == NULLPLR )
            continue;

        std::stringstream ss;

        uint32 zone = 0;
        if(plr->IsInWorld())
        {
            zone = plr->GetZoneId();
        }
        ss << "GmTicket 0," << (*itr)->name << "," << (*itr)->level << ",0," << zone;
        chn->Say(cplr, ss.str().c_str(), cplr, true);
    }

    return true;
}

bool ChatHandler::HandleGMTicketGetByIdCommand(const char* args, WorldSession *m_session)
{
    if(!*args)
        return false;

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    Player *plr = objmgr.GetPlayer(args, false);
    if(plr == NULLPLR)
    {
        RedSystemMessage(m_session, "Player not found.");
        return true;
    }
    GM_Ticket *ticket = objmgr.GetGMTicketByPlayer(plr->GetGUID());
    if(ticket == NULL || ticket->deleted)
    {
        RedSystemMessage(m_session, "Ticket not found.");
        return true;
    }

    char* msg = new char[ticket->message.size() + 1];
    strcpy(msg, ticket->message.c_str());
    char * start = msg, *end;
    bool firstLine = true;
    for(;;)
    {
        end = strchr(start, '\n');
        if(!end)
            break;

        *end = '\0';

        std::stringstream ss;
        ss << "GmTicket " << (firstLine ? "3" : "4") << "," << ticket->name << "," << start;
        chn->Say(cplr, ss.str().c_str(), cplr, true);

        firstLine = false;

        start = end + 1;
    }
    if(*start != '\0')
    {
        std::stringstream ss;
        ss << "GmTicket " << (firstLine ? "3" : "4") << "," << ticket->name << "," << start;
        chn->Say(cplr, ss.str().c_str(), cplr, true);
    }
    delete[] msg;

    return true;
}

bool ChatHandler::HandleGMTicketRemoveByIdCommand(const char* args, WorldSession *m_session)
{
    if(!*args)
        return false;

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    Player *plr = objmgr.GetPlayer(args, true);
    if(plr == NULLPLR)
    {
        RedSystemMessage(m_session, "Player not found.");
        return true;
    }

    GM_Ticket *ticket = objmgr.GetGMTicketByPlayer(plr->GetGUID());
    if(ticket == NULL || ticket->deleted)
    {
        RedSystemMessage(m_session, "Ticket not found.");
        return true;
    }

    std::stringstream ss;
    ss << "GmTicket 1," << ticket->name;
    chn->Say(cplr, ss.str().c_str(), NULLPLR, true);

    objmgr.RemoveGMTicket(ticket->guid);

    if(!plr)
        return true;

    if(!plr->IsInWorld())
        return true;

    // Notify player about removing ticket
    WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
    data << uint32(9);
    plr->GetSession()->SendPacket( &data );
    // Response - Send GM Survey
    WorldPacket datab(SMSG_GM_TICKET_STATUS_UPDATE, 1);
    datab << uint32(3);
    plr->GetSession()->SendPacket( &datab );

    return true;
}

#else

void ChatHandler::SendGMSurvey()
{

}

bool ChatHandler::HandleGMTicketListCommand(const char* args, WorldSession *m_session)
{
    Player *cplr = m_session->GetPlayer();

    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    std::stringstream ss0;
    ss0 << "GmTicket:" << GM_TICKET_CHAT_OPCODE_LISTSTART;
    chn->Say(cplr, ss0.str().c_str(), cplr, true);

    for(GmTicketList::iterator itr = objmgr.GM_TicketList.begin(); itr != objmgr.GM_TicketList.end(); itr++)
    {
        if((*itr)->deleted)
            continue;

        Player* plr = objmgr.GetPlayer((uint32)(*itr)->playerGuid);

        Player* aplr = NULLPLR;
        PlayerInfo* aplri = NULL;
        if((*itr)->assignedToPlayer != 0)
        {
            aplr = objmgr.GetPlayer((uint32)(*itr)->assignedToPlayer);
            if(aplr == NULLPLR)
                aplri = objmgr.GetPlayerInfo((uint32)(*itr)->assignedToPlayer);
        }

        std::stringstream ss;
        ss << "GmTicket:" << GM_TICKET_CHAT_OPCODE_LISTENTRY;
        ss << ":" << (*itr)->guid;
        ss << ":" << (plr == NULLPLR ? (*itr)->level : plr->getLevel());
        ss << ":" << (plr == NULLPLR ? 0 : plr->IsInWorld());
        ss << ":" << (aplr == NULLPLR ? (aplri == NULL ? "" : aplri->name) : aplr->GetName());
        ss << ":" << (plr == NULLPLR ? (*itr)->name : plr->GetName());
        ss << ":" << (*itr)->comment;
        chn->Say(cplr, ss.str().c_str(), cplr, true);
    }

    return true;
}

bool ChatHandler::HandleGMTicketGetByIdCommand(const char* args, WorldSession *m_session)
{
    uint64 ticketGuid = (args ? atoi(args) : 0);
    if(!ticketGuid)
    {
        RedSystemMessage(m_session, "You must specify a ticket id.");
        return true;
    }

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    GM_Ticket *ticket = objmgr.GetGMTicket(ticketGuid);
    if(ticket == NULL || ticket->deleted)
    {
        chn->Say(cplr, "GmTicket:0:Ticket not found.", cplr, true);
        return true;
    }

    char* msg = new char[ticket->message.size() + 1];
    strcpy(msg, ticket->message.c_str());
    char * start = msg, *end;
    bool firstLine = true;
    for(;;)
    {
        end = strchr(start, '\n');
        if(!end)
            break;

        *end = '\0';

        std::stringstream ss;
        ss << "GmTicket:" << (firstLine ? GM_TICKET_CHAT_OPCODE_CONTENT : GM_TICKET_CHAT_OPCODE_APPENDCONTENT);
        ss << ":" << ticket->guid;
        ss << ":" << start;
        chn->Say(cplr, ss.str().c_str(), cplr, true);

        firstLine = false;

        start = end + 1;
    }
    if(*start != '\0')
    {
        std::stringstream ss;
        ss << "GmTicket:" << (firstLine ? GM_TICKET_CHAT_OPCODE_CONTENT : GM_TICKET_CHAT_OPCODE_APPENDCONTENT);
        ss << ":" << ticket->guid;
        ss << ":" << start;
        chn->Say(cplr, ss.str().c_str(), cplr, true);
    }
    delete[] msg;

    return true;
}

bool ChatHandler::HandleGMTicketRemoveByIdCommand(const char* args, WorldSession *m_session)
{
    uint64 ticketGuid = (args ? atoi(args) : 0);
    if(!ticketGuid)
    {
        RedSystemMessage(m_session, "You must specify a ticket id.");
        return true;
    }

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    GM_Ticket *ticket = objmgr.GetGMTicket(ticketGuid);
    if(ticket == NULL || ticket->deleted)
    {
        chn->Say(cplr, "GmTicket:0:Ticket not found.", cplr, true);
        return true;
    }

    if(ticket->assignedToPlayer != 0 && ticket->assignedToPlayer != cplr->GetGUID() && !cplr->GetSession()->CanUseCommand('z'))
    {
        chn->Say(cplr, "GmTicket:0:Ticket is assigned to another GM.", cplr, true);
        return true;
    }

    Player* plr = objmgr.GetPlayer((uint32)ticket->playerGuid);

    std::stringstream ss;
    ss << "GmTicket:" << GM_TICKET_CHAT_OPCODE_REMOVED;
    ss << ":" << ticket->guid;
    chn->Say(cplr, ss.str().c_str(), NULLPLR, true);

    objmgr.RemoveGMTicket(ticket->guid);

    if(!plr)
        return true;

    if(!plr->IsInWorld())
        return true;

    // Notify player about removing ticket
    WorldPacket data( SMSG_GMTICKET_DELETETICKET, 4 );
    data << uint32(9);
    plr->GetSession()->SendPacket( &data );
    // Response - Send GM Survey
    WorldPacket datab( SMSG_GM_TICKET_STATUS_UPDATE, 1 );
    datab << uint32(3);
    plr->GetSession()->SendPacket( &datab );
    return true;
}


bool ChatHandler::HandleGMTicketAssignToCommand(const char* args, WorldSession *m_session)
{
    uint64 ticketGuid;
    char guidString[100], name[100];
    int argc = sscanf(args,"%s %s", guidString, name);
    if(argc < 1 || argc > 2)
        return false;

    ticketGuid = atoi(guidString);
    if(!ticketGuid)
    {
        RedSystemMessage(m_session, "You must specify a ticket id.");
        return true;
    }

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    GM_Ticket *ticket = objmgr.GetGMTicket(ticketGuid);

    if(ticket == NULL || ticket->deleted)
    {
        chn->Say(cplr, "GmTicket:0:Ticket not found.", cplr, true);
        return true;
    }

    Player* mplr = objmgr.GetPlayer((uint32)ticket->playerGuid);
    Player *plr = (argc == 1 ? cplr : objmgr.GetPlayer(name, false));
    if(plr == NULLPLR)
    {
        chn->Say(cplr, "GmTicket:0:Player not found.", cplr, true);
        return true;
    }

    if(!plr->IsInWorld())
    {
        chn->Say(cplr, "GmTicket:0:Player isn't online.", cplr, true);
        return true;
    }

    if(plr->GetSession()->GetPermissionCount() == 0)
    {
        chn->Say(cplr, "GmTicket:0:Player is not a GM.", cplr, true);
        return true;
    }

    if(ticket->assignedToPlayer == plr->GetGUID())
    {
        chn->Say(cplr, "GmTicket:0:Ticket already assigned to this GM.", cplr, true);
        return true;
    }

    if(ticket->assignedToPlayer != 0 && ticket->assignedToPlayer != cplr->GetGUID())
    {
        Player *aplr = objmgr.GetPlayer((uint32)ticket->assignedToPlayer);
        if(aplr != NULLPLR && aplr->IsInWorld() && !cplr->GetSession()->CanUseCommand('z'))
        {
            chn->Say(cplr, "GmTicket:0:Ticket already assigned to another GM.", cplr, true);
            return true;
        }
    }

    ticket->assignedToPlayer = plr->GetGUID();
    objmgr.UpdateGMTicket(ticket);

    std::stringstream ss;
    ss << "GmTicket:" << GM_TICKET_CHAT_OPCODE_ASSIGNED;
    ss << ":" << ticket->guid;
    ss << ":" << plr->GetName();
    chn->Say(cplr, ss.str().c_str(), NULLPLR, true);
    //Send Response Packet to update Ticket
    //WorldPacket data(SMSG_GMTICKET_GETTICKET, 400);
    //data << uint32(6); // Packet Status
    //data << uint8(0x7);//static Category
    //data << ticket->message.c_str();//ticketDescription
    //data << float(0.0);//ticketAge - days //update time =  last time ticket was modified?
    //data << float(0.0);//oldestTicketTime - days
    //data << float(0.0);//updateTime - days | How recent is the data for oldest ticket time, measured in days.  If this number 1 hour, we have bad data.
    //data << unit64(2);//assignedToGM |0 - ticket is not currently assigned to a gm | 1 - ticket is assigned to a normal gm |  2 - ticket is in the escalation queue
    //data << uint64(1);//openedByGM | 0 - ticket has never been opened by a gm | 1 - ticket has been opened by a gm
    //mplr->GetSession()->SendPacket( &data );
    SystemMessageToPlr(mplr, "SYSTEM: Your ticket has been escalated. A Senior Game Master will be with you shortly!");
    return true;
}

bool ChatHandler::HandleGMTicketReleaseCommand(const char* args, WorldSession *m_session)
{
    uint64 ticketGuid = (args ? atoi(args) : 0);
    if(!ticketGuid)
    {
        RedSystemMessage(m_session, "You must specify a ticket id.");
        return true;
    }

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    GM_Ticket *ticket = objmgr.GetGMTicket(ticketGuid);
    if(ticket == NULL || ticket->deleted)
    {
        chn->Say(cplr, "GmTicket:0:Ticket not found.", cplr, true);
        return true;
    }

    if(ticket->assignedToPlayer == 0)
    {
        chn->Say(cplr, "GmTicket:0:Ticket not assigned to a GM.", cplr, true);
        return true;
    }

    Player *plr = objmgr.GetPlayer((uint32)ticket->assignedToPlayer);
    if(!cplr->GetSession()->CanUseCommand('z') && plr != NULLPLR && plr->IsInWorld() && plr->GetSession()->CanUseCommand('z'))
    {
        chn->Say(cplr, "GmTicket:0:You can not release tickets from Senior Game Masters.", cplr, true);
        return true;
    }

    ticket->assignedToPlayer = 0;
    objmgr.UpdateGMTicket(ticket);

    std::stringstream ss;
    ss << "GmTicket:" << GM_TICKET_CHAT_OPCODE_RELEASED;
    ss << ":" << ticket->guid;
    chn->Say(cplr, ss.str().c_str(), NULLPLR, true);

    return true;
}

bool ChatHandler::HandleGMTicketCommentCommand(const char* args, WorldSession *m_session)
{
    uint64 ticketGuid;
    int argc = 1;
    char* comment = NULL;
    char* guidString = (char*)args;

    // Parse arguments
    char* space = (char*)strchr(args, ' ');
    if(space)
    {
        *space = '\0';
        comment = space + 1;
        argc = 2;
    }

    ticketGuid = atoi(guidString);
    if(!ticketGuid)
    {
        RedSystemMessage(m_session, "You must specify a ticket id.");
        return true;
    }

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    GM_Ticket *ticket = objmgr.GetGMTicket(ticketGuid);
    if(ticket == NULL || ticket->deleted)
    {
        chn->Say(cplr, "GmTicket:0:Ticket not found.", cplr, true);
        return true;
    }

    if(ticket->assignedToPlayer != 0 && ticket->assignedToPlayer != cplr->GetGUID() && !cplr->GetSession()->CanUseCommand('z'))
    {
        chn->Say(cplr, "GmTicket:0:Ticket is assigned to another GM.", cplr, true);
        return true;
    }

    ticket->comment = (argc == 1 ? "" : comment);
    objmgr.UpdateGMTicket(ticket);

    std::stringstream ss;
    ss << "GmTicket:" << GM_TICKET_CHAT_OPCODE_COMMENT;
    ss << ":" << ticket->guid;
    ss << ":" << cplr->GetName();
    ss << ":" << ticket->comment;
    chn->Say(cplr, ss.str().c_str(), NULLPLR, true);

    return true;
}

bool ChatHandler::HandleGMTicketDeletePermanentCommand(const char* args, WorldSession *m_session)
{
    uint64 ticketGuid = (args ? atoi(args) : 0);
    if(!ticketGuid)
    {
        RedSystemMessage(m_session, "You must specify a ticket id.");
        return true;
    }

    Player *cplr = m_session->GetPlayer();
    Channel *chn = channelmgr.GetChannel(sWorld.getGmClientChannel().c_str(), cplr);
    if(!chn)
        return false;

    GM_Ticket *ticket = objmgr.GetGMTicket(ticketGuid);
    if(ticket == NULL)
    {
        chn->Say(cplr, "GmTicket:0:Ticket not found.", cplr, true);
        return true;
    }

    Player* plr = NULLPLR;

    if(!ticket->deleted)
    {
        plr = objmgr.GetPlayer((uint32)ticket->playerGuid);

        std::stringstream ss;
        ss << "GmTicket:" << GM_TICKET_CHAT_OPCODE_REMOVED;
        ss << ":" << ticket->guid;
        chn->Say(cplr, ss.str().c_str(), NULLPLR, true);

        objmgr.RemoveGMTicket(ticket->guid);
    }

    objmgr.DeleteGMTicketPermanently(ticket->guid);
    ticket = NULL;
    if(plr != NULLPLR && plr->IsInWorld())
    {
        // Notify player about removing ticket
        WorldPacket data(SMSG_GMTICKET_DELETETICKET, 4);
        data << uint32(9);
        plr->GetSession()->SendPacket( &data );

        // Response - Send GM Survey
        WorldPacket datab(SMSG_GM_TICKET_STATUS_UPDATE, 1);
        datab << uint32(3);
        plr->GetSession()->SendPacket( &datab );
    }

    return true;
}

#endif
