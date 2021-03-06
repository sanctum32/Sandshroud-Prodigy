/***
 * Demonstrike Core
 */

#include "StdAfx.h"

void ApplySingleSpellFixes(SpellEntry *sp)
{
    /* Note: when applying spell hackfixes, please follow a template */
    switch(sp->Id)
    {
    case 3286: // BIND HARDCODING
        {
            sp->Effect[0] = 11; sp->Effect[1] = 24;
            sp->EffectImplicitTargetA[0] = sp->EffectImplicitTargetA[1] = 149;
        }break;

    case 196: // 1H Axes
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_PALADIN|CLASSMASK_HUNTER|CLASSMASK_ROGUE|CLASSMASK_DEATHKNIGHT|CLASSMASK_SHAMAN;
        break;

    case 197: // 2H Axes
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_PALADIN|CLASSMASK_HUNTER|CLASSMASK_DEATHKNIGHT|CLASSMASK_SHAMAN;
        break;

    case 198: // 1H Maces
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_PALADIN|CLASSMASK_ROGUE|CLASSMASK_PRIEST|CLASSMASK_DEATHKNIGHT|CLASSMASK_SHAMAN|CLASSMASK_DRUID;
        break;

    case 199: // 2H Maces
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_PALADIN|CLASSMASK_DEATHKNIGHT|CLASSMASK_SHAMAN|CLASSMASK_DRUID;
        break;

    case 200: // Polearms
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_PALADIN|CLASSMASK_HUNTER|CLASSMASK_DEATHKNIGHT|CLASSMASK_DRUID;
        break;

    case 201: // 1H Swords
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_PALADIN|CLASSMASK_HUNTER|CLASSMASK_ROGUE|CLASSMASK_DEATHKNIGHT|CLASSMASK_MAGE|CLASSMASK_WARLOCK;
        break;

    case 202: // 2H Swords
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_PALADIN|CLASSMASK_HUNTER|CLASSMASK_DEATHKNIGHT;
        break;

    case 227: // Staves
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_HUNTER|CLASSMASK_PRIEST|CLASSMASK_SHAMAN|CLASSMASK_MAGE|CLASSMASK_WARLOCK|CLASSMASK_DRUID;
        break;

    case 1180: // Daggers
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_HUNTER|CLASSMASK_ROGUE|CLASSMASK_PRIEST|CLASSMASK_SHAMAN|CLASSMASK_MAGE|CLASSMASK_WARLOCK|CLASSMASK_DRUID;
        break;

    case 15590: // Fist Weapons
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_HUNTER|CLASSMASK_ROGUE|CLASSMASK_SHAMAN|CLASSMASK_DRUID;
        break;

    case 5009: // Wands
        sp->trnr_req_clsmsk = CLASSMASK_PRIEST|CLASSMASK_MAGE|CLASSMASK_WARLOCK;
        break;

    case 264: // Bows
    case 266: // Guns
    case 2567: // Thrown
    case 5011: // Crossbows
        sp->trnr_req_clsmsk = CLASSMASK_WARRIOR|CLASSMASK_HUNTER|CLASSMASK_ROGUE;
        break;

    case 1455: // Spell 1455 Proc Chance (Life Tap Rank 2:
    case 1456: // Spell 1456 Proc Chance (Life Tap Rank 3:
    case 8182: // Spell 8182 Proc Chance (Frost Resistance Rank 1:
    case 8185: // Spell 8185 Proc Chance (Fire Resistance Rank 1:
    case 10476: // Spell 10476 Proc Chance (Frost Resistance Rank 2:
    case 10477: // Spell 10477 Proc Chance (Frost Resistance Rank 3:
    case 10534: // Spell 10534 Proc Chance (Fire Resistance Rank 2:
    case 10535: // Spell 10535 Proc Chance (Fire Resistance Rank 3:
    case 11687: // Spell 11687 Proc Chance (Life Tap Rank 4:
    case 11688: // Spell 11688 Proc Chance (Life Tap Rank 5:
    case 11689: // Spell 11689 Proc Chance (Life Tap Rank 6:
    case 12292: // Spell 12292 Proc Chance (Death Wish :
    case 18803: // Spell 18803 Proc Chance (Focus :
            sp->procChance = 100;
        break;

    case 3391: // Spell 3391 Proc Chance (Thrash :
    case 15494: // Spell 15494 Proc Chance (Fury of Forgewright :
    case 15601: // Spell 15601 Proc Chance (Hand of Justice :
    case 15642: // Spell 15642 Proc Chance (Ironfoe :
    case 16843: // Spell 16843 Proc Chance (Crimson Fury :
    case 18797: // Spell 18797 Proc Chance (Flurry Axe :
    case 19105: // Spell 19105 Proc Chance (MHTest01 Effect :
    case 19109: // Spell 19109 Proc Chance (MHTest02 Effect :
    case 27035: // Spell 27035 Proc Chance (Sword Specialization (OLD: :
    case 21919: // Spell 21919 Proc Chance (Thrash :
            sp->procChance = 10;
        break;

        // Spell 12284 Proc Chance (Mace Specialization Rank 1:
    case 12284:
            sp->procChance = 1;
        break;

        // Spell 12322 Proc Chance (Unbridled Wrath Rank 1:
    case 12322:
            sp->ProcsPerMinute = 3;
        break;

        // Spell 12701 Proc Chance (Mace Specialization Rank 2:
    case 12701:
            sp->procChance = 2;
        break;

        // Spell 12702 Proc Chance (Mace Specialization Rank 3:
    case 12702:
            sp->procChance = 3;
        break;

        // Spell 12703 Proc Chance (Mace Specialization Rank 4:
    case 12703:
            sp->procChance = 4;
        break;

        // Spell 12704 Proc Chance (Mace Specialization Rank 5:
    case 12704:
            sp->procChance = 6;
        break;

        // Spell 12999 Proc Chance (Unbridled Wrath Rank 2:
    case 12999:
            sp->ProcsPerMinute = 6;
        break;

        // Spell 13000 Proc Chance (Unbridled Wrath Rank 3:
    case 13000:
            sp->ProcsPerMinute = 9;
        break;

        // Spell 13001 Proc Chance (Unbridled Wrath Rank 4:
    case 13001:
            sp->ProcsPerMinute = 12;
        break;

        // Spell 13002 Proc Chance (Unbridled Wrath Rank 5:
    case 13002:
            sp->ProcsPerMinute = 15;
        break;

        // Spell 14076 Proc Chance (Dirty Tricks Rank 1:
    case 14076:
            sp->procChance = 30;
        break;

        // Spell 14094 Proc Chance (Dirty Tricks Rank 2:
    case 14094:
            sp->procChance = 60;
        break;

        // Spell 15600 Proc Chance (Hand of Justice :
    case 15600:
            sp->procChance = 2;
        break;

        // Spell 23158 Proc Chance (Concussive Shot Cooldown Reduction :
    case 23158:
            sp->procChance = 4;
        break;

        // Spell 27521 Proc Chance (Mana Restore :
    case 27521:
            sp->procChance = 2;
        break;

        // Spell 27867 Proc Chance (Freeze :
    case 27867:
            sp->procChance = 2;
        break;

        // Spell 27498 Crusader's Wrath
    case 27498:
            sp->procChance = 7;
        break;

        //Martyrdom
    case 14531:
    case 14774:
        {
            sp->procFlags = PROC_ON_CRIT_HIT_VICTIM | PROC_ON_RANGED_CRIT_ATTACK_VICTIM;
        }break;

        // Impact proc
    case 64343:
        {
            sp->AuraInterruptFlags  |= AURA_INTERRUPT_ON_CAST_SPELL;
        }break;

        // Elemental Focus
    case 16164:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 16246:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procCharges++; //   first   charge gets lost when   it gets procced
        }break;

        //shaman - Stormstrike
    case 17364:
        {
            sp->procFlags=PROC_ON_SPELL_HIT_VICTIM;
        }break;

        //shaman - Improved Stormstrike
    case 51521:
    case 51522:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

        //shaman - Hex
    case 51514:
        {
                // Damage   caused may interrupt the effect.
            sp->AuraInterruptFlags |=   AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN;
        }break;

    case 52752:
        {
            sp->spell_can_crit = false;
            sp->logsId = sp->Id;
        }break;

        // shaman   -   Maelstrom   Weapon
    case 51528:
        {
            sp->procChance = 0;
            sp->ProcsPerMinute = 1.3f;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;
    case 51529:
        {
            sp->procChance = 0;
            sp->ProcsPerMinute = 2.6f;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;
    case 51530:
        {
            sp->procChance = 0;
            sp->ProcsPerMinute = 3.9f;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;
    case 51531:
        {
            sp->procChance = 0;
            sp->ProcsPerMinute = 5.2f;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;
    case 51532:
        {
            sp->procChance = 0;
            sp->ProcsPerMinute = 6.5f;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;

        // Maelstorm proc   charge removal
    case 53817:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        // Astral   Shift
    case 52179:
        {
            sp->EffectAmplitude[0] = 0;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN;
            sp->EffectMiscValue[0] = 127;
        }break;

        // Shamanistic Rage
    case 30823:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
            sp->procflags2 = PROC_TARGET_SELF;
        }break;

    case 51479:
    case 51478:
    case 51474: // Astral Shift
        {
            sp->procChance = 100;
            sp->EffectImplicitTargetA[0] = 1;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags = PROC_ON_SPELL_LAND_VICTIM;
            sp->EffectTriggerSpell[0] = 52179;
            sp->Effect[1] = 0;
        }break;

    case 51975:// shaman    -   Poison Cleansing Totem
    case 52025:// shaman    -   Disease Cleansing   Totem
        {
                
            SpellEntry*  sp2 = dbcSpell.LookupEntryForced( 58780 );
            if( sp2 != NULL)
            {
                sp->EffectRadiusIndex[0] = sp2->EffectRadiusIndex[0];   //30 yards
                sp->EffectImplicitTargetA[0] = EFF_TARGET_ALL_PARTY_IN_AREA;
            }
        }break;

        // Fire Nova Totem visual   fix
    case 8349:
    case 8502:
    case 8503:
    case 11306:
    case 11307:
    case 25535:
    case 25537:
    case 61650:
    case 61654:
        {
            sp->Effect[1]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1]   =   19823;
        }break;

    case 64395:
        {
            sp->School = SCHOOL_ARCANE;
        }break;

        // Flurry
    case 12319:
    case 12971:
    case 12972:
    case 12973:
    case 12974:
    case 16256:
    case 16281:
    case 16282:
    case 16283:
    case 16284:
        {
            sp->procFlags   =   PROC_ON_CRIT_ATTACK;
        }break;

        // Flurry   proc
    case 12966:
    case 12967:
    case 12968:
    case 12969:
    case 12970:
    case 16257:
    case 16277:
    case 16278:
    case 16279:
    case 16280:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->procCharges++; //   first   charge gets lost when   it gets procced
        }break;

        //Minor Glyph Research + Northrend Inscription Research
    case 61177:
    case 61288:
    case 60893:
        {
            sp->Effect[1]   =   0;
            sp->EffectBasePoints[1] =   0;
            sp->EffectImplicitTargetA[1]    =   0;
            sp->EffectDieSides[1]   =   0;
        }break;

        // Shaman   Totem   items   fixes
        // Totem of Survival,   Totem   of the Tundra
    case 46097:
    case 43860:
    case 43861:
    case 43862:
    case 60564:
    case 60571:
    case 60572:
    case 37575:
        {
            sp->EffectSpellClassMask[0][0] = 0x00100000 |   0x10000000 | 0x80000000; //Earth + Flame + Frost Shocks
            sp->EffectSpellClassMask[0][1] = 0x08000000;    // Wind Shock
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_SELF;
        }break;
    case 60567:
        {
            sp->EffectImplicitTargetA[1] = EFF_TARGET_SELF;
        }break;

        // Totem of Third   Wind
    case 46098:
    case 34138:
    case 42370:
    case 43728:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x00000080;    // Lesser   Healing Wave
        }break;

        // Totem of the Elemental   Plane
    case 60770:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x00000001;    // Lightning Bolt
        }break;

        // Fathom-Brooch of the Tidewalker
    case 37247:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->proc_interval   =   45000;
        }break;

        //Warlock: Backlash
    case 34935:
    case 34938:
    case 34939:
        {
            sp->proc_interval   =   8000;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_TARGET_SELF;
        }break;

    case 34936:
        {
            sp->AuraInterruptFlags |=   AURA_INTERRUPT_ON_CAST_SPELL;
        }break;

        //Priest - Holy Nova
    case 15237:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 23455;
        }break;

    case 15430:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 23458;
        }break;

    case 15431:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 23459;
        }break;

    case 25331:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 27803;
        }break;

    case 27799:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 27804;
        }break;

    case 27800:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 27805;
        }break;

    case 27801:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 25329;
        }break;

    case 48077:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 48075;
        }break;

    case 48078:
        {
            sp->Effect[0] = sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectTriggerSpell[1] = 48076;
        }break;

        // Moroes' garrote targets a single enemy   instead of us
    case 37066:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SINGLE_ENEMY;
        }break;

        // Penance
    case 47540:
    case 53005:
    case 53006:
    case 53007:
        {
            sp->AttributesEx = 0;
            sp->DurationIndex = 566; // Change to instant cast as script will cast the real channeled spell.
            sp->ChannelInterruptFlags = 0; // Remove channeling behaviour.
        }break;

        // Penance triggered healing spells have wrong targets.
    case 47750:
    case 52983:
    case 52984:
    case 52985:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SINGLE_FRIEND;
        }break;

        // Hymn of Hope
    case 60931:
    case 60933:
        {
            sp->EffectImplicitTargetA[0] = 37;
        }break;

        //paladin   -   Reckoning
    case 20177:
    case 20179:
    case 20180:
    case 20181:
    case 20182:
        {
            sp->procFlags   =   PROC_ON_ANY_DAMAGE_VICTIM;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        //paladin   -   Reckoning   Effect = proc   on proc
    case 20178:
        {
            sp->procChance = 100;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        //paladin   -   Judgement   of Wisdom
    case 20186:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 20268;
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
            sp->procChance = 35;
            sp->Effect[1] = 0;
            sp->EffectApplyAuraName[1] = 0;
        }break;

        //paladin   -   Judgement   of Light
    case 20185:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 20267;
            sp->procChance = 35;
            sp->Effect[1] = 0;
            sp->EffectApplyAuraName[1] = 0;
        }break;

    case 20267:
    case 20268:
    case 20341:
    case 20342:
    case 20343:
    case 27163:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SINGLE_ENEMY;
        }break;
        //paladin   -   Eye for an Eye
    case 9799:
    case 25988:
        {
            sp->procFlags   =   PROC_ON_SPELL_CRIT_HIT_VICTIM | PROC_ON_CRIT_HIT_VICTIM;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   25997;
        }break;

        //paladin Blessed Life
    case 31828:
    case 31829:
    case 31830:
        {
            sp->procFlags   =   PROC_ON_ANY_DAMAGE_VICTIM;
            sp->EffectTriggerSpell[0]   =   31828;
        }break;

        //paladin   -   Light's Grace
    case 31833:
    case 31835:
    case 31836:
        {
            sp->EffectSpellClassMask[0][0]=0x80000000;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        //Paladin - Sacred Cleansing
    case 53551:
    case 53552:
    case 53553:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x00001000;
            sp->EffectSpellClassMask[0][1] = 0x00001000;
            sp->EffectSpellClassMask[0][2] = 0x00001000;
        }break;
        //Shield of the Templar
    case 53709:
    case 53710:
    case 53711:
        {
            sp->EffectSpellClassMask[0][0] = 64;
            sp->EffectSpellClassMask[0][1] = 16384;
            sp->EffectSpellClassMask[0][2] = 1048576;
            sp->EffectSpellClassMask[1][0] = 64;
            sp->EffectSpellClassMask[1][1] = 16384;
            sp->EffectSpellClassMask[1][2] = 1048576;
            sp->EffectSpellClassMask[2][0] = 64;
            sp->EffectSpellClassMask[2][1] = 16384;
            sp->EffectSpellClassMask[2][2] = 1048576;
        }break;
        //Paladin - Infusion of light
    case 53569:
    case 53576:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 53672:
    case 54149:
        {
            sp->AuraInterruptFlags  =   AURA_INTERRUPT_ON_CAST_SPELL;
        }break;
        //Paladin - Vindication
    case 9452:
    case 26016:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK | PROC_ON_ANY_HOSTILE_ACTION;
            sp->procChance  =   25;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA; // hoax
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
            sp->maxstack = 1;
        }break;
        //Paladin - Art of War
    case 53486:
        {
            sp->procFlags   =   PROC_ON_CRIT_ATTACK;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
            sp->EffectApplyAuraName[2]  =   SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[2]   =   53489;
        }break;
    case 53488:
        {
            sp->procFlags   =   PROC_ON_CRIT_ATTACK;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
            sp->EffectApplyAuraName[2]  =   SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[2]   =   59578;
        }break;
    case 53489:
    case 59578:
        {
                 sp->AuraInterruptFlags |= AURA_INTERRUPT_ON_CAST_SPELL;
        }break;

        //shaman - Lightning Overload
    case 30675: // rank 1
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   39805;//proc something (we will owerride this)
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 4;
        }break;

    case 30678:  // rank 2
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   39805;//proc something (we will owerride this)
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 8;
        }break;

    case 30679: // rank 3
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   39805;//proc something (we will owerride this)
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 12;
        }break;

    case 30680: // rank 4
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   39805;//proc something (we will owerride this)
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 16;
        }break;

    case 30681: // rank 5
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   39805;//proc something (we will owerride this)
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 20;
        }break;

        //shaman - Purge
    case 370:
    case 8012:
    case 27626:
    case 33625:
        {
            sp->DispelType = DISPEL_MAGIC;
        }break;

    case 57663: // Totem of Wrath
        {
            sp->AreaAuraTarget = AA_TARGET_RAID;
        }break;

        //Shaman - Eye of   the Storm
    case 29062:
    case 29064:
    case 29065:
        {
            sp->procFlags   =   PROC_ON_CRIT_HIT_VICTIM;
        }break;

        //shaman - Elemental Devastation
    case 29179:
    case 29180:
    case 30160:
        //shaman - Ancestral healing
    case 16176:
    case 16235:
    case 16240:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

        //shaman - Ancestral healing proc   spell
    case 16177:
    case 16236:
    case 16237:
        {
            sp->rangeIndex = 4;
        }break;

    case 1856: // Vanish r1
    case 1857: // Vanish r2
    case 11305: // Sprint
    case 14183: // Premeditation
    case 14185: // Preparation
    case 26889: // Vanish r3
    case 31665: // Master of Sub
    case 36554: // Shadow Step
    case 46784: // Shadowsong Panther
    case 51724: // Sap
    case 58427: // Overkill
        {
            sp->AttributesEx |= ATTRIBUTESEX_NOT_BREAK_STEALTH;
        }break;

        //rogue -   Find Weakness.
    case 31233:
    case 31239:
    case 31240:
    case 31241:
    case 31242:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        //rogue -   Cheap   Shot
    case 1833:
        {
            sp->Flags3 &=   ~FLAGS3_REQ_BEHIND_TARGET;  //Doesn't   require to be   behind target
        }break;

        //rogue -   Camouflage.
    case 13975:
    case 14062:
    case 14063:
    case 14064:
    case 14065:
        {
            sp->EffectMiscValue[0] = SMT_MISC_EFFECT;
        }break;

        //rogue -   Mace Specialization.
    case 13709:
    case 13800:
    case 13801:
    case 13802:
    case 13803:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;

        //rogue - Shadowstep
    case 36563:
        {
            sp->EffectMiscValue[1] = SMT_MISC_EFFECT;
            sp->procFlags   =   0;
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
            sp->AttributesEx |= ATTRIBUTESEX_NOT_BREAK_STEALTH;
        }break;

    case 44373:
        {
            sp->procFlags   =   0;
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
            sp->AttributesEx |= ATTRIBUTESEX_NOT_BREAK_STEALTH;
        }break;

        //Rogue  - Ruthlessness
    case 14156:
    case 14160:
    case 14161:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;//proc   spell
            sp->EffectTriggerSpell[0] = 14157;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procflags2 = PROC_TARGET_SELF;
        }break;

        //priest    -   Holy Concentration
    case 34753:
    case 34859:
    case 34860:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 34754://Make it similar to Mage Clearcasting
        {
            sp->procCharges =   2;
            sp->Flags3  =   4;
            sp->Flags4  =   1073741824;
            sp->procFlags   =   87376;
        }break;

        //guardian spirit
    case 47788:
        {
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_DUMMY;
            sp->AuraInterruptFlags = 0;
        }break;

    case 48153:
        {
            sp->EffectBasePoints[0] = 50;
        }break;

        //Priest:   Blessed Recovery
    case 27811:
        {
            sp->EffectTriggerSpell[0]   =   27813;
            sp->procFlags   =   PROC_ON_CRIT_HIT_VICTIM;
        }break;

    case 27815:
        {
            sp->EffectTriggerSpell[0]   =   27817;
            sp->procFlags   =   PROC_ON_CRIT_HIT_VICTIM;
        }break;

    case 27816:
        {
            sp->EffectTriggerSpell[0]   =   27818;
            sp->procFlags   =   PROC_ON_CRIT_HIT_VICTIM;
        }break;

        //priest-   Blessed Resilience
    case 33142:
    case 33145:
    case 33146:
        //priest-   Focused Will
    case 45234:
    case 45243:
    case 45244:
        {
            sp->procFlags   =   PROC_ON_CRIT_HIT_VICTIM;
        }break;
        //Priest:   Improved Vampiric Embrace (Rank1)
    case 27839:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_PCT_MODIFIER;
        }break;

    case 20154: // Seal of Righteousness
    case 21084: // Seal of Righteousness
    case 20164: // Seal of Justice
    case 20165: // Seal of Light
    case 20166: // Seal of Wisdom
    case 31801: // Seal of Vengeance
    case 53736: // Seal of Corruption
        //LEGACY - These aren't ingame anymore... or are they?
    case 38008: // Seal of Blood(30s)
    case 31892: // Seal of Blood(30m)
    case 53720: // Seal of the Martyr
        {
            sp->Effect[0] = sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = sp->EffectApplyAuraName[2] = SPELL_AURA_DUMMY;
        }break;
    case 20375: // Seal of Command
        {
            sp->ProcsPerMinute = 7;
            sp->Effect[0] = sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = sp->EffectApplyAuraName[2] = SPELL_AURA_DUMMY;
        }break;
    case 57770:
        {
            sp->rangeIndex = 1;
        }break;

        //paladin - hammer of the righteous
    case 53595:
        {
            sp->speed = 0;
            sp->is_melee_spell = true;
        }break;

        //paladin   -   Spiritual   Attunement
    case 31785:
    case 33776:
        {
            sp->procFlags   =   PROC_ON_SPELL_LAND_VICTIM;
            sp->procflags2  =   PROC_TARGET_SELF;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   31786;
        }break;

        //fix   for the right   Enchant ID for Enchant Cloak - Major Resistance
    case 27962:
    case 36285:
        {
            sp->EffectMiscValue[0] = 2998;
        }break;

        //muhaha,   rewriting   Retaliation spell   as old one :D
    case 20230:
        {
            sp->Effect[0]   =   6; //aura
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   22858; //evil   ,   but this is good for us :D
            sp->procFlags   =   PROC_ON_MELEE_ATTACK_VICTIM; //add procflag here since this was not processed   with the others !
        }break;

        //"bloodthirst" new version is ok   but old version is wrong from   now on :(
    case 23881:
        {
            sp->Effect[1]   =   64; //cast on   us, it is   good
            sp->EffectTriggerSpell[1]   =   23885; //evil   ,   but this is good for us :D
        }break;

    case 23892:
        {
            sp->Effect[1]   =   64;
            sp->EffectTriggerSpell[1]   =   23886; //evil   ,   but this is good for us :D
        }break;

    case 23893:
        {
            sp->Effect[1]   =   64; //
            sp->EffectTriggerSpell[1]   =   23887; //evil   ,   but this is good for us :D
        }break;

    case 23894:
        {
            sp->Effect[1]   =   64; //
            sp->EffectTriggerSpell[1]   =   23888; //evil   ,   but this is good for us :D
        }break;

    case 25251:
        {
            sp->Effect[1]   =   64; //aura
            sp->EffectTriggerSpell[1]   =   25252; //evil   ,   but this is good for us :D
        }break;

    case 30335:
        {
            sp->Effect[1]   =   64; //aura
            sp->EffectTriggerSpell[1]   =   30339; //evil   ,   but this is good for us :D
        }break;

        // Hunter   -   Master Tactician
    case 34506:
    case 34507:
    case 34508:
    case 34838:
    case 34839:
        {
            sp->procFlags   =   PROC_ON_RANGED_ATTACK;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        // Hunter   -   T.N.T
    case 56333:
    case 56336:
    case 56337:
        {
            sp->procFlags = PROC_ON_TRAP_TRIGGER | PROC_ON_CAST_SPECIFIC_SPELL | PROC_ON_CRIT_ATTACK | PROC_ON_PHYSICAL_ATTACK | PROC_ON_RANGED_ATTACK;
            sp->EffectSpellClassMask[0][0] = 0x00000004;
            sp->EffectSpellClassMask[0][1] = sp->EffectSpellClassMask[1][1];
            sp->EffectSpellClassMask[1][0] = 0x0;
        }break;

        // Hunter   -   Spirit Bond
    case 19578:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER | SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   19579;
        }break;

    case 20895:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER | SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   24529;
        }break;

    case 19579:
    case 24529:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA; //we   should do   the same for player too as we   did for pet
            sp->EffectApplyAuraName[1] = sp->EffectApplyAuraName[0];
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PET;
            sp->EffectBasePoints[1] =   sp->EffectBasePoints[0];
            sp->EffectAmplitude[1] = sp->EffectAmplitude[0];
            sp->EffectDieSides[1]   =   sp->EffectDieSides[0];
        }break;

        // Hunter   -   Animal Handler
    case 34453:
    case 34454:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
            sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_HIT_CHANCE;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PET;
        }break;

        // Hunter   -   Catlike Reflexes
    case 34462:
    case 34464:
    case 34465:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
            sp->EffectApplyAuraName[1] = sp->EffectApplyAuraName[0];
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PET;
        }break;

        // Hunter   -   Serpent's   Swiftness
    case 34466:
    case 34467:
    case 34468:
    case 34469:
    case 34470:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
            sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_MELEE_HASTE;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PET;
        }break;

        // Hunter   -   Ferocious   Inspiration
    case 34455:
    case 34459:
    case 34460:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
            sp->EffectTriggerSpell[0]   =   34456;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT | PROC_TARGET_SELF;
            sp->Effect[1]   =   0; //remove this
        }break;

        // Hunter   -   Focused Fire
    case 35029:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER | SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   35060;
        }break;
    case 35030:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER | SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   35061;
        }break;
    case 35060:
    case 35061:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_EXPIREING_WITH_PET;
        }break;

        // Hunter   -   Thick   Hide
    case 19609:
    case 19610:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER ;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_RESISTANCE; //we do not support armor   rating for pets yet !
            sp->EffectBasePoints[0] *= 10; //just   give it a   little juice :P
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        // Hunter   -   Ferocity
    case 19612:
    case 19599:
    case 19600:
    case 19601:
    case 19602:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_WEAPON_CRIT_PERCENT;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        // Hunter   -   Bestial Swiftness
    case 19596:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_INCREASE_SPEED;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        // Hunter   -   Endurance   Training
    case 19583:
    case 19584:
    case 19585:
    case 19586:
    case 19587:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER ;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;
        // Hunter - Thrill of the Hunt
    case 34497:
    case 34498:
    case 34499:
        {
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->procChance = sp->EffectBasePoints[0]+1;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 34720;
        }break;

        // Hunter   -   Expose Weakness
    case 34500:
    case 34502:
    case 34503:
        {
            sp->procFlags   =   PROC_ON_RANGED_CRIT_ATTACK;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;
        // hunter - Wild Quiver
    case 53215:
    case 53216:
    case 53217:
        {
            sp->procFlags = PROC_ON_RANGED_ATTACK;
        }break;

        //Hunter - Frenzy
    case 19621:
    case 19622:
    case 19623:
    case 19624:
    case 19625:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   19615;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
            sp->procChance = sp->EffectBasePoints[0];
            sp->procFlags   =   PROC_ON_CRIT_ATTACK;
            sp->c_is_flags  =   SPELL_FLAG_IS_EXPIREING_WITH_PET | SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
        }break;

    case 56641:
    case 34120:
    case 49051:
    case 49052: //Steady Shot cast time fix
        {
            sp->CastingTimeIndex = 5; // Set 2 sec cast time
        }break;

    case 61846:
    case 61847: // Aspect of the Dragonhawk
        {   // need to copy Mod Dodge Percent aura from a separate spell
            CopyEffect(dbcSpell.LookupEntryForced(61848), 0, sp, 2);
        }break;

        //Hunter - Unleashed Fury
    case 19616:
    case 19617:
    case 19618:
    case 19619:
    case 19620:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_DAMAGE_PERCENT_DONE;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
            sp->EffectMiscValue[0] = 1; //tweekign melee dmg
            sp->c_is_flags |=   SPELL_FLAG_IS_EXPIREING_WITH_PET | SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET;
        }break;

        //Hunter : Pathfinding
    case 19559:
    case 19560:
        {
            sp->EffectMiscValue[0] = SMT_MISC_EFFECT;
        }break;

        //Hunter : Rapid Killing - might need   to add honor trigger too here. I'm guessing you receive Xp too so   i'm avoiding double proc
    case 34948:
    case 34949:
        {
            sp->procFlags   =   PROC_ON_GAIN_EXPIERIENCE;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        // Winter's chill
    case 12579:
        {
            sp->c_is_flags |=   SPELL_FLAG_CANNOT_PROC_ON_SELF;
        }break;

        //Mage - Icy Veins
    case 12472:
        {
            sp->EffectMiscValue[1] = SMT_PROC_CHANCE;
        }break;

        //Mage - Ignite
    case 11119:
    case 11120:
    case 12846:
    case 12847:
    case 12848:
        {
            sp->EffectTriggerSpell[0]   =   12654;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;

        //Mage - Wand   Specialization. Not the forst   thing   we messed   up. Blizz   uses attack as magic and wandds as weapons :S
    case 6057:
    case 6085:
        //Priest - Wand Specialization
    case 14524:
    case 14525:
    case 14526:
    case 14527:
    case 14528:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_PCT_MODIFIER;
            sp->EffectMiscValue[0] = SMT_MISC_EFFECT;
        }break;

        //Mage - Elemental Precision
    case 29438:
    case 29439:
    case 29440:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_PCT_MODIFIER;
            sp->EffectMiscValue[0] = SMT_COST;
        }break;

        //Mage - Arcane Concentration
    case 11213:
    case 12574:
    case 12575:
    case 12576:
    case 12577:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        //Mage - ClearCasting   Effect
        //Druid - Clearcasting Effect
        //Druid - Nature's Grace effect
    case 16870:
    case 12536:
    case 16886:
        {
            sp->procCharges =   2;
        }break;

        //Mage - Arcane Blast
    case 36032:
        {
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
            sp->procflags2 = PROC_TARGET_SELF;
            sp->c_is_flags = SPELL_FLAG_IS_FORCEDDEBUFF;
        }break;

        //rogue - Prey on the weak
    case 51685:
    case 51686:
    case 51687:
    case 51688:
    case 51689:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;

        //rogue -   Seal Fate
    case 14186:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 20;
        }break;
    case 14190:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 40;
        }break;
    case 14193:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 60;
        }break;
    case 14194:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 80;
        }break;
    case 14195:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 100;
        }break;

        // druid - Nature's Grace
    case 16880:
    case 61345:
    case 61346:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

        //druid -   Blood   Frenzy
    case 16954:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 100;
        }break;
    case 16952:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 50;
        }break;

        //druid -   Primal Fury
    case 16961:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 100;
        }break;
    case 16958:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procChance = 50;
        }break;

        //druid -   Intensity
    case 17106:
    case 17107:
    case 17108:
        {
            sp->EffectApplyAuraName[1]  =   SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
        
    // Druid - Nurturing Instinct
    case 33872:
        {
            sp->AdditionalAura = 47179;
        }break;
    case 33873:
        {
            sp->AdditionalAura = 47180;
        }break;

        //Improved Sprint
    case 13743:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 50;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
        }break;
    case 13875:
        {
            sp->procChance = 100;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
        }break;

        //Warlock - healthstones
    case 6201:
    case 6202:
    case 5699:
    case 11729:
    case 11730:
    case 27230:
    case 47871:
    case 47878:
        {
            sp->Reagent[1] = 0;
            sp->ReagentCount[1] = 0;
        }break;
        //warlock   -    Seed   of Corruption
    case 27243:
        {
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1]   =   27285;
            sp->procFlags   =   PROC_ON_SPELL_HIT_VICTIM;
            sp->procflags2  =   PROC_ON_DIE;
            sp->procChance = 100;
        }break;
        //warlock - soul link
    case 19028:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_SPLIT_DAMAGE_PCT;
            sp->EffectBasePoints[0] = 20;
            sp->EffectMiscValue[0] = 127;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
            sp->c_is_flags |= SPELL_FLAG_IS_EXPIREING_WITH_PET;

            sp->Effect[1] = 6;
            sp->EffectApplyAuraName[1] = 79;
            sp->EffectBasePoints[1] = 4;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_SELF;
            sp->EffectImplicitTargetB[1] = EFF_TARGET_PET;
            sp->c_is_flags |= SPELL_FLAG_IS_EXPIREING_WITH_PET;
        }break;

        //warlock: Nightfall
    case 18094:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 17941;
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION;
            sp->procChance = 2;
            sp->EffectSpellClassMask[0][0] = 0x0;
        }break;
    case 18095:
    {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 17941;
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION;
            sp->procChance = 4;
            sp->EffectSpellClassMask[0][0] = 0x0;
        }break;

        //Warlock - Backdraft
    case 47258:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   54274;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 100;
            sp->procCharges = 4;
            sp->EffectSpellClassMask[0][0]=0x00800000;
            sp->EffectSpellClassMask[0][1]=0x00800000;
        }break;
    case 47269:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   54276;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 100;
            sp->procCharges = 4;
            sp->EffectSpellClassMask[0][0]=0x00800000;
            sp->EffectSpellClassMask[0][1]=0x00800000;
        }break;
    case 47260:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   54277;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 100;
            sp->procCharges = 4;
            sp->EffectSpellClassMask[0][0]=0x00800000;
            sp->EffectSpellClassMask[0][1]=0x00800000;
        }break;
        //Warlock - Eradication
    case 47195:
    case 47196:
    case 47197:
        {
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION;
            sp->EffectSpellClassMask[0][0] = 2;
            sp->proc_interval = 30000;
        }break;

        //warlock: Improved Enslave Demon
    case 18821:
        {
            sp->EffectMiscValue[0]=SMT_SPELL_VALUE_PCT;
            sp->EffectBasePoints[0] =   -(sp->EffectBasePoints[0]+2);
        }break;
        //Mage - Improved   Blizzard
    case 11185:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   12484;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;
    case 12487:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   12485;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;
    case 12488:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   12486;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        //mage - Combustion
    case 11129:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT | PROC_TARGET_SELF;
            sp->procCharges =   0;
            sp->c_is_flags |=   SPELL_FLAG_IS_REQUIRECOOLDOWNUPDATE;
        }break;

        //mage - Master of Elements
    case 29074:
    case 29075:
    case 29076:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1] = 29077;
            sp->EffectImplicitTargetA[1] = 1;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->procChance = 100;
        }break;

        //mage: Blazing Speed
    case 31641:
    case 31642:
            {
            sp->EffectTriggerSpell[0]   =   31643;
        }break;

        //mage talent   "frostbyte". we make it to be   dummy
    case 11071:
    case 12496:
    case 12497:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 12494;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = sp->EffectBasePoints[0];
        }break;

        //rogue-shiv -> add 1   combo   point
    case 5938:
        {
            sp->Effect[1]=80;
            sp->Flags3 &=   ~FLAGS3_REQ_BEHIND_TARGET;  //Doesn't   require to be   behind target
            sp->is_melee_spell = true;
        }break;

        //warlock   -   Demonic Sacrifice
    case 18789:
    case 18790:
    case 18791:
    case 18792:
    case 35701:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_EXPIREING_ON_PET;
        }break;


        //warlock   -   Demonic Tactics
    case 30242:
        {
            sp->Effect[0]   =   0; //disble this.   This is just blizz crap. Pure   proove that they suck   :P
            sp->EffectImplicitTargetB[1] = EFF_TARGET_PET;
            sp->EffectApplyAuraName[2] = SPELL_AURA_MOD_SPELL_CRIT_CHANCE; //lvl 1 has it   fucked up   :O
            sp->EffectImplicitTargetB[2] = EFF_TARGET_PET;
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER ;
        }break;
    case 30245:
    case 30246:
    case 30247:
    case 30248:
        {
            sp->Effect[0]   =   0; //disble this.   This is just blizz crap. Pure   proove that they suck   :P
            sp->EffectImplicitTargetB[1] = EFF_TARGET_PET;
            sp->EffectImplicitTargetB[2] = EFF_TARGET_PET;
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER ;
        }break;

        //warlock   -   Demonic Resilience
    case 30319:
    case 30320:
    case 30321:
        {
            sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PET;
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_PET_OWNER ;
        }break;

        //warlock   -   Improved Imp
    case 18694:
    case 18695:
    case 18696:
    case 18705:
    case 18706:
    case 18707:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   ;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        //warlock   -   Improved Succubus
    case 18754:
    case 18755:
    case 18756:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   ;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PET;
        }break;

        //warlock   -   Fel Intellect
    case 18731:
    case 18743:
    case 18744:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   ;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_PERCENT_STAT;
            sp->EffectMiscValue[0] = 3;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        //warlock   -   Fel Stamina
    case 18748:
    case 18749:
    case 18750:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   ;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_PERCENT_STAT;
            sp->EffectMiscValue[0] = 2;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        //warlock   -   Unholy Power
    case 18769:
    case 18770:
    case 18771:
    case 18772:
    case 18773:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   ;
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_PCT_MODIFIER;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
            //this is   required since blizz uses   spells for melee attacks while we   use fixed   functions
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_DAMAGE_PERCENT_DONE;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PET;
            sp->EffectMiscValue[1] = SCHOOL_NORMAL;
            sp->EffectBasePoints[1] =   sp->EffectBasePoints[0] ;
        }break;

        //warlock   -   Master Demonologist -   25 spells   here
    case 23785:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   |   SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   23784;
        }break;
    case 23822:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   |   SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   23830;
        }break;
    case 23823:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   |   SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   23831;
        }break;
    case 23824:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   |   SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   23832;
        }break;
    case 23825:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_CASTED_ON_PET_SUMMON_ON_PET   |   SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   35708;
        }break;
        //and   the rest
    case 23784:
    case 23830:
    case 23831:
    case 23832:
    case 35708:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

    case 23759:
    case 23760:
    case 23761:
    case 23762:
    case 23826:
    case 23827:
    case 23828:
    case 23829:
    case 23833:
    case 23834:
    case 23835:
    case 23836:
    case 23837:
    case 23838:
    case 23839:
    case 23840:
    case 23841:
    case 23842:
    case 23843:
    case 23844:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0]   =   SPELL_EFFECT_APPLY_AURA;
        }break;

    case 35702:
    case 35703:
    case 35704:
    case 35705:
    case 35706:
        {
            sp->c_is_flags |= SPELL_FLAG_IS_EXPIREING_WITH_PET;
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
        }break;
        //warlock   -   Improved Healthstone
    case 18692:
    case 18693:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_PCT_MODIFIER;
            sp->EffectMiscValue[0] = SMT_MISC_EFFECT;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SELF;
        }break;
        //warlock   -   Improved Drain Soul
    case 18213:
    case 18372:
        {
            sp->procFlags   =   PROC_ON_TARGET_DIE;
            sp->procflags2  =   PROC_TARGET_SELF;
            sp->procChance = 100;
            sp->Effect[0]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   18371;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SELF;
            sp->Effect[2]   =   0   ;   //remove this   effect
        }break;

        //warlock   -   Shadow Embrace
    case 32385:
    case 32387:
    case 32392:
    case 32393:
    case 32394:
        {
            sp->procChance = 100;
            sp->procFlags = PROC_ON_SPELL_LAND;
            sp->Effect[1] = 0;  //remove this   effect ? Maybe remove   the other   one :P xD
        }break;
        //warlock - soul leech
    case 30293:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 30294;
            sp->procChance = 10;
            sp->procFlags = PROC_ON_SPELL_LAND;
        }break;
    case 30295:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 30294;
            sp->procChance = 20;
            sp->procFlags = PROC_ON_SPELL_LAND;
        }break;
    case 30296:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 30294;
            sp->procChance = 30;
            sp->procFlags = PROC_ON_SPELL_LAND;
        }break;
        //warlock   -   Pyroclasm
    case 18073:
    case 18096:
    case 63245:
        {
            sp->Effect[0]   =   0; //delete this owerride   effect :P
            sp->EffectTriggerSpell[1]   =   18093; //trigger spell was wrong :P
            sp->procFlags   =   PROC_ON_ANY_HOSTILE_ACTION;
            sp->procChance = 26; //god, save us from fixed values   !
        }break;

        //Mage - Improved Scorch
    case 11095:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 33;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case 12872:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance =66;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;
    case 12873:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance =100;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        //Nature's Grasp
    case 16689:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   339;
            sp->Effect[1]   =   0;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_REMOVEONUSE;
            sp->AuraInterruptFlags = 0; //we remove it on   proc or timeout
            sp->procChance = 100;
        }break;
    case 16810:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   1062;
            sp->Effect[1]   =   0;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_REMOVEONUSE;
            sp->AuraInterruptFlags = 0; //we remove it on   proc or timeout
            sp->procChance = 100;
        }break;
    case 16811:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   5195;
            sp->Effect[1]   =   0;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_REMOVEONUSE;
            sp->AuraInterruptFlags = 0; //we remove it on   proc or timeout
            sp->procChance = 100;
        }break;
    case 16812:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   5196;
            sp->Effect[1]   =   0;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_REMOVEONUSE;
            sp->AuraInterruptFlags = 0; //we remove it on   proc or timeout
            sp->procChance = 100;
        }break;
    case 16813:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   9852;
            sp->Effect[1]   =   0;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_REMOVEONUSE;
            sp->AuraInterruptFlags = 0; //we remove it on   proc or timeout
            sp->procChance = 100;
        }break;
    case 17329:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   9853;
            sp->Effect[1]   =   0;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_REMOVEONUSE;
            sp->AuraInterruptFlags = 0; //we remove it on   proc or timeout
            sp->procChance = 100;
        }break;
    case 27009:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   26989;
            sp->Effect[1]   =   0;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_REMOVEONUSE;
            sp->AuraInterruptFlags = 0; //we remove it on   proc or timeout
            sp->procChance = 100;
        }break;

        //wrath of air totem targets sorounding creatures   instead of us
    case 2895:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SELF;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_SELF;
            sp->EffectImplicitTargetA[2] = 0;
            sp->EffectImplicitTargetB[0] = 0;
            sp->EffectImplicitTargetB[1] = 0;
            sp->EffectImplicitTargetB[2] = 0;
        }break;
        //Druid: Natural Shapeshifter
    case 16833:
    case 16834:
    case 16835:
        {
            sp->DurationIndex   =   0;
        }break;


        //Priest - Inspiration proc spell
    case 14893:
    case 15357:
    case 15359:
        {
            sp->rangeIndex = 4;
        }break;

        //Relentless Strikes
    case 14179:
    case 58422:
    case 58423:
    case 58424:
    case 58425:
        {
            sp->EffectApplyAuraName[0]  =   SPELL_AURA_PROC_TRIGGER_SPELL;//proc    spell
            sp->EffectTriggerSpell[0]   =   14181;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procflags2  =   PROC_TARGET_SELF;
            sp->procChance = 100;
        }break;

        //priest - surge of light
    case 33150:
    case 33154:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

    case 33151:
        {
            sp->procCharges =   2;
        }break;

        //Seal of   Justice -lowered proc   chance (experimental values !)
    case 31895:
        {
            sp->procChance = 20;
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_DUMMY;
        }break;
        // judgement of command shit
    case 20425:
        {
            sp->Effect[1] = 2;
            sp->EffectImplicitTargetA[1] = 6;
        }break;
        //Berserking
    case 26635:
        {
            sp->Attributes  =   327680;
            sp->CasterAuraState =   0;
        }break;
        //Escape Artist
    case 20589:
        {
            sp->Attributes = 65552;
            sp->Flags3 = 0;
            sp->Effect[0] = 108;
            sp->Effect[1] = 108;
            sp->EffectDieSides[0] = 1;
            sp->EffectDieSides[1] = 1;
            sp->EffectBasePoints[0] = 9;
            sp->EffectBasePoints[1] = 9;
            sp->EffectMiscValue[0] = 7;
            sp->EffectMiscValue[1] = 11;
        }break;
        //Zapthrottle Mote Extractor
    case 30427:
        {
            sp->Effect[0] = SPELL_EFFECT_DUMMY;
        }break;
        //Goblin Jumper Cable
    case 22999:
    case 8342:
    case 54732:
        {
            sp->Effect[0] = 113;
            sp->EffectMiscValue[0] = 120;
        }break;
        //rogue -   intiative
    case 13976:
    case 13979:
    case 13980:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        //this an   on equip item   spell(2824) :    ice arrow(29501)
    case 29501:
        {
            sp->procChance = 30;//some say it   is triggered every now and then
            sp->procFlags   =   PROC_ON_RANGED_ATTACK;
        }break;

        //deep wounds
    case 12834:
    case 12849:
    case 12867:
        {
            sp->EffectTriggerSpell[0] = 12868;
            sp->procFlags = PROC_ON_CRIT_ATTACK | PROC_ON_RANGED_CRIT_ATTACK;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;

        //warrior   -   second wind should trigger on   self
    case 29841:
    case 29842:
        {
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        // Improved Revenge
    case 12797:
    case 12799:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

        //warrior   -   berserker   rage is missing 1   effect = regenerate rage
    case 18499:
        {
            sp->Effect[2]   =   6;
            sp->EffectApplyAuraName[2] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[2]   =   37521; //not sure   if this is the one. In my   time this   adds 30 rage
            sp->procFlags   =   PROC_ON_ANY_DAMAGE_VICTIM;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        //warrior   -   improved berserker rage
    case 20500:
    case 20501:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procflags2  =   PROC_TARGET_SELF;
        }break;

        // warrior - Spell Reflection
    case 23920:
        {
            sp->procFlags   =   PROC_NULL; //   No need to proc
        }break;


        // warrior - Titan's Grip
    case 46917: // main spell
        {
            SpellEntry * sp2 = dbcSpell.LookupEntryForced(  49152   );  // move this aura   into main   spell
                if(sp != NULL)
                {
                sp->Effect[1] = sp2->Effect[0];
                sp->EffectApplyAuraName[1] = sp2->EffectApplyAuraName[0];
                sp->EffectMiscValue[1] = sp2->EffectMiscValue[0];
                sp->EffectSpellClassMask[1][0] = sp2->EffectSpellClassMask[0][0];
                sp->EffectSpellClassMask[1][1] = sp2->EffectSpellClassMask[0][1];
                sp->EffectSpellClassMask[1][2] = sp2->EffectSpellClassMask[0][2];
                sp->EffectBasePoints[1] = sp2->EffectBasePoints[0];
                sp->EffectDieSides[1]= sp2->EffectDieSides[0];
                }
        }break;

        // Charge   -   Changing from   dummy   for the power   regen
    case 100:
    case 6178:
    case 11578:
        {
            sp->Effect[1]   =   SPELL_EFFECT_ENERGIZE;
            sp->EffectMiscValue[1] = 1;
        }break;

        //warrior   -   Rampage
    case 30030:
    case 30033:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->procflags2  =   PROC_TARGET_SELF;
            sp->EffectTriggerSpell[0]   =   sp->EffectTriggerSpell[1];
//          sp->Unique = true; // Crow: It should be, but what if we have 2 warriors?
        }break;

        // warrior - overpower
    case 7384:
    case 7887:
    case 11584:
    case 11585:
        {
            sp->Attributes |=   ATTRIBUTES_CANT_BE_DPB;
        }break;

        // warrior - heroic fury
    case 60970:
        {
            sp->Effect[1]   =   SPELL_EFFECT_DUMMY;
        }break;

    case 20608: //Reincarnation
            {
                for(uint32 i=0;i<8;++i)
                {
                        if(sp->Reagent[i])
                        {
                        sp->Reagent[i] = 0;
                        sp->ReagentCount[i] =   0;
                        }
                }
            }break;

        // druid - travel   form
    case 5419:
            {
            sp->Attributes |=   ATTRIBUTES_MOUNT_CASTABLE;
            }break;

        // druid - Naturalist
    case 17069:
    case 17070:
    case 17071:
    case 17072:
    case 17073:
        {
            sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_DAMAGE_PERCENT_DONE;
            sp->EffectMiscValue[1] = 1;
        }break;

        // Druid: Omen of Clarity
    case 16864:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_CAST_SPELL;
            sp->procChance = 6;
            sp->proc_interval = 10000;
        }break;

        //Serpent-Coil Braid
    case 37447:
    case 61062://Heroes' Frostfire Garb AND Valorous Frostfire Garb
        {
            sp->Effect[0] = 6;
            sp->Effect[1] = 6;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 100;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[1]   =   37445;
            sp->maxstack = 1;
        }break;

        // Mark of Conquest
    case 33510:
        {
            sp->procChance = 7;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;

        //Paladin   -   Improved Lay on Hands
    case 20234:
    case 20235:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        // Sudden   Death
    case 29724:
    case 29725:
    case 29723:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;

        // Taste for Blood
    case 56638:
    case 56637:
    case 56636:
        {
            sp->procFlags   =   PROC_ON_ANY_HOSTILE_ACTION;
            sp->EffectSpellClassMask[0][0]  = 0x0;
            sp->EffectSpellClassMask[1][0]  = 0x0;
        }break;

        // Flametongue weapon
    case 58792:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   58788;
        }break;
    case 58791:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   58787;
        }break;
    case 58784:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   58786;
        }break;
    case 16313:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   25488;
        }break;
    case 16312:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   16344;
        }break;
    case 16311:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   16343;
        }break;
    case 15569:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   10445;
        }break;
    case 15568:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   8029;
        }break;
    case 15567:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   8028;
        }break;
    case 10400:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   8026;
        }break;

        //windfury weapon
    case 33757:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->EffectTriggerSpell[0]   =   25504;
            sp->procChance = 20;
            sp->proc_interval   =   3000;
            sp->maxstack = 1;
            // Current proc system doesn't support common proc_interval for 2
            // procs making dual wielding WF overpowered. So it is disabled for now
            //sp->always_apply = true; 
            //so that   we can apply 2 wf   auras   while   dual-wielding
        }break;

        // dot heals
    case 38394:
        {
            sp->procFlags   =   1024;
                //sp->SpellGroupType = 6;
        }break;

    case 16972:
    case 16974:
    case 16975:
        {   //fix   for Predatory   Strikes
            sp->RequiredShapeShift = (1<<(FORM_BEAR-1))|(1<<(FORM_DIREBEAR-1))|(1<<(FORM_CAT-1));
        }break;

    case 20134:
        {
            sp->procChance = 50;
        }break;

    /* aspect   of the pack -   change to   AA */
    case 13159:
        {
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AREA_AURA;
            sp->procFlags   =   PROC_ON_ANY_DAMAGE_VICTIM;
        }break;

    /* aspect   of the cheetah - add proc   flags   */
    case 5118:
            {
            sp->procFlags   =   PROC_ON_ANY_DAMAGE_VICTIM;;
        }break;


    case SPELL_RANGED_GENERAL:
    case SPELL_RANGED_THROW:
    case 26679:
    case 29436:
    case 37074:
    case 41182:
    case 41346:
        {
            if( sp->RecoveryTime==0 && sp->StartRecoveryTime == 0   )
            sp->RecoveryTime = 1600;
        }break;

    case SPELL_RANGED_WAND:
        {
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_RANGED;
                if( sp->RecoveryTime==0 && sp->StartRecoveryTime == 0   )
                sp->RecoveryTime = 1600;
        }break;

    /**********************************************************
    *   Misc stuff (NPC SPELLS)
    **********************************************************/

    case 5106:
        {
            sp->AuraInterruptFlags |= AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN;
        }break;

    /**********************************************************
    *   Misc stuff (QUEST)
    **********************************************************/
        // Bat Net
    case 52151:
        {
            sp->EffectImplicitTargetA[0] = 6;
        }break;

        // queststuff
    case 30877:
        {
            sp->EffectImplicitTargetB[0]=0;
        }break;

        // quest stuff
    case 23179:
        {
            sp->EffectMiscValue[0] = 1434;
        }break;

        // arcane charges
    case 45072:
        {
            sp->Attributes |= ATTRIBUTES_MOUNT_CASTABLE;
        }break;

    case 48252: //Prototype Neural Needle
    case 45634: //Neural Needle
        {
            sp->Effect[1] = 0;
        }break;
        //Tuber whistle
    case 36652:
        {
            sp->Effect[1] = 3;
        }break;
        //Cure Caribou Hide
    case 46387:
        {
            sp->ReagentCount[0] = 1;
            sp->ReagentCount[1] = 0;
            sp->Reagent[1] = 0;
        }break;
        //Create Totem of Issliruk
    case 46816:
        {
            sp->Reagent[0] = 0;
            sp->ReagentCount[0] = 0;
        }break;
    /**********************************************************
    *   Misc stuff (ITEMS)
    **********************************************************/

        // Nitro Boosts
    case 55004:
        {
            CopyEffect(dbcSpell.LookupEntryForced(54861), 0, sp, 2);
            sp->DurationIndex = 39;
        }break;

        // Gnomish Lightning Generator
    case 55039:
        {
            sp->InterruptFlags = 0;
            sp->AuraInterruptFlags = 0;
            sp->ChannelInterruptFlags = 0;
        }break;

        // Libram of Divinity
    case 28853:
        // Libram of Light
    case 28851:
        // Blessed Book of Nagrand
    case 32403:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_FLAT_MODIFIER;
            sp->EffectMiscValue[0] = 0;
            sp->EffectSpellClassMask[0][0] = 1073741824;
        }break;
        // Libram of Mending
    case 43741:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 100;
            sp->EffectSpellClassMask[0][0] = 0x80000000;
            sp->EffectSpellClassMask[0][1] = 0x0;
            sp->EffectSpellClassMask[0][2] = 0x0;
            sp->EffectSpellClassMask[1][0] = 0x0;
            sp->EffectSpellClassMask[1][1] = 0x0;
            sp->EffectSpellClassMask[1][2] = 0x0;
            sp->EffectSpellClassMask[2][0] = 0x0;
            sp->EffectSpellClassMask[2][1] = 0x0;
            sp->EffectSpellClassMask[2][2] = 0x0;
        }break;

        // Druid Trinket Living Root of the Wildheart
    case 37336:
        {
            sp->Effect[0] = SPELL_EFFECT_DUMMY;// oh noez, we   make it DUMMY, no   other   way to fix it   atm
        }break;

        // Palla trinket
    case 43745:
    case 34258:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 8388608 | 520;
            sp->procChance = 100;
        }break;

        // Lesser Rune of Warding / Grater Rune of Warding
    case 42135:
    case 42136:
        {
            sp->EffectImplicitTargetA[1] = 6;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
        }break;

        //Idol of terror
    case 43737:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
        // Lesser   Heroism (Tenacious Earthstorm   Diamond)
    case 32844:
        {
            sp->procChance = 5;
            sp->procFlags    = PROC_ON_MELEE_ATTACK;
        }break;

        // Darkmoon Card:   Heroism
    case 23689:
        {
            sp->ProcsPerMinute = 2.5f;
            sp->procFlags    = PROC_ON_MELEE_ATTACK;
        }break;

        // Darkmoon Card:   Maelstrom
    case 23686:
        {
            sp->ProcsPerMinute = 2.5f;
            sp->procFlags    = PROC_ON_MELEE_ATTACK;
        }break;

        // dragonspine trophy
    case 34774:
        {
            sp->ProcsPerMinute = 1.5f;
            sp->proc_interval   =   20000;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;

        // Romulo's Poison Vial
    case 34586:
        {
            sp->ProcsPerMinute = 1.6f;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;

        // madness of   the betrayer
    case 40475:
        {
            sp->procChance = 50;
            sp->ProcsPerMinute = 1.0f;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;

        // Band of the Eternal Defender
    case 35077:
        {
            sp->proc_interval   =   55000;
            sp->procFlags   =   PROC_ON_ANY_DAMAGE_VICTIM;
        }break;
        // Band of the Eternal Champion
    case 35080:
        {
            sp->proc_interval   =   55000;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;
        // Band of the Eternal Restorer
    case 35086:
        // Band of the Eternal Sage
    case 35083:
        {
            sp->proc_interval   =   55000;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;
        // Sonic Booster
    case 54707:
        {
            sp->ProcsPerMinute = 1.0f;
            sp->proc_interval   =   60000;
            sp->procFlags = PROC_ON_MELEE_ATTACK;
        }break;
    case 60301: // Meteorite Whetstone
    case 60317: // Signet of Edward the Odd
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;
        // Bandit's Insignia
    case 60442:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;
        // Fury of the Five Flights
    case 60313:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;
        // Grim Toll
    case 60436:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;
        // Illustration of the Dragon Soul
    case 60485:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
        // Soul of the Dead
    case 60537:
        {
            sp->proc_interval   =   45000;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
        // Anvil of Titans
    case 62115:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;
        // Embrace of the Spider
    case 60490:
        // Flow of Knowledge
    case 62114:
        // Forge Ember
    case 60473:
        // Mystical Skyfire Diamond
    case 32837:
        // Sundial of the Exiled
    case 60063:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

        // Majestic Dragon Figurine
    case 60524:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
        // Mirror of Truth
    case 33648:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_CRIT_ATTACK;
        }break;

        // Vestige of Haldor
    case 60306:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;

        //Energized
    case 43750:
            {
            sp->procFlags = PROC_ON_CAST_SPELL;
            }break;


        //Spell Haste   Trinket
    case 33297:
            {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procflags2  =   PROC_TARGET_SELF;
            }break;
    case 57345: // Darkmoon Card: Greatness
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->proc_interval = 45000;
        }break;

    case 67702: // Death's Choice/Verdict
        {
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
            sp->proc_interval = 45000;
        }break;

    case 67771: // Death's Choice/Verdict (heroic)
        {
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
            sp->proc_interval = 45000;
        }break;

    case 72413: //Ashen Bands
        {
            sp->procChance = 10;
        }break;

        // Swordguard Embroidery
    case 55776:
        {
            sp->proc_interval   =   60000;
            sp->procFlags = PROC_ON_MELEE_ATTACK;
        }break;
        // Chuchu's Tiny Box of Horrors
    case 61618:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_MELEE_ATTACK;
        }break;

    case 57351: // Darkmoon Card: Berserker!
        {
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION | PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK | PROC_ON_ANY_DAMAGE_VICTIM;; // when you strike, or are struck in combat
        }break;
    case 60196:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SELF;
        }break;
        // Darkmoon Card: Death
    case 57352:
        {
            sp->proc_interval   =   45000;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK | PROC_ON_CAST_SPELL;
        }break;
    case 60493: //Dying Curse
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->proc_interval = 45000;
        }break;

        // Ashtongue Talisman   of Shadows
    case 40478:
        {
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION;
        }break;

        // Ashtongue Talisman   of Swiftness
    case 40485:
        // Ashtongue Talisman   of Valor
    case 40458:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;
        //Ashtongue Talisman of Zeal
    case 40470:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 50;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[0] = 40472;
            sp->maxstack = 1;
        }break;

        // Memento of   Tyrande
    case 37655:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 10;
            sp->proc_interval   =   45000;
        }break;

        // Ashtongue Talisman   of Insight
    case 40482:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
            }break;


        //Ashtongue Talisman of Equilibrium
    case 40442:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 40;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[0]   =   40452;
            sp->maxstack = 1;
            sp->Effect[1]   =   6;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 25;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[1]   =   40445;
            sp->maxstack = 1;
            sp->Effect[2]   =   6;
            sp->EffectApplyAuraName[2] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 25;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[2]   =   40446;
            sp->maxstack = 1;
        }break;

        //Ashtongue Talisman of Acumen
    case 40438:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 10;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[0]   =   40441;
            sp->maxstack = 1;
            sp->Effect[1]   =   6;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 10;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[1]   =   40440;
            sp->maxstack = 1;
        }break;

        //Ashtongue Talisman of Lethality
    case 40460:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 20;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectTriggerSpell[0]   =   40461;
            sp->maxstack = 1;
        }break;
        //Leatherworking Drums
    case 35475://Drums of War
    case 35476://Drums of Battle
    case 35478://Drums of Restoration
    case 35477://Drums of Speed
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_ALL_PARTY;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_ALL_PARTY;
            sp->EffectImplicitTargetA[2] = EFF_TARGET_NONE;
            sp->EffectImplicitTargetB[0] = EFF_TARGET_NONE;
            sp->EffectImplicitTargetB[1] = EFF_TARGET_NONE;
            sp->EffectImplicitTargetB[2] = EFF_TARGET_NONE;
        }break;

    case 46699:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ABILITY_CONSUME_NO_AMMO;
        }break;
    /**********************************************************
    *   Misc stuff (ITEM SETS)
    **********************************************************/

        //Item Set: Malorne Harness
    case 37306:
    case 37311:
        //Item Set: Deathmantle
    case 37170:
        {
            sp->procChance = 4;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;

        //Item Set: Netherblade
    case 37168:
        {
            sp->procChance = 15;
        }break;

        //Item Set: Tirisfal Regalia
    case 37443:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

        //Item Set: Avatar Regalia
    case 37600:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 6;
        }break;

        //Item Set: Incarnate   Raiment
    case 37568:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        //Item Set: Voidheart   Raiment
    case 37377:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 5;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->proc_interval   =   20;
            sp->EffectTriggerSpell[0]   =   37379;
        }break;
    case 39437:
        {
            sp->Effect[0]   =   6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 5;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->proc_interval   =   20;
            sp->EffectTriggerSpell[0]   =   37378;
        }break;

        //Item Set: Cataclysm   Raiment
    case 37227:
        {
            sp->proc_interval   =   60000;
            sp->procChance = 100;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

        //Item Set: Cataclysm   Regalia
    case 37228:
        {
            sp->procChance = 7;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;
    case 37237:
        {
            sp->procChance = 25;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

        //Item Set: Cataclysm   Harness
    case 37239:
        {
            sp->procChance = 2;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
        }break;

        //Item Set: Cyclone Regalia
    case 37213:
        {
            sp->procChance = 11;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

        //Item Set: Lightbringer Battlegear
    case 38427:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->procChance = 20;
        }break;

        //Item Set: Crystalforge Battlegear
    case 37195:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 6;
        }break;

        //Item Set: Crystalforge Raiment
    case 37189:
        {
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
            sp->proc_interval   =   60000;
        }break;

    case 37188:
        //Item Set: Crystalforge Armor
    case 37191:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;

        //Item Set: Destroyer   Armor
    case 37525:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procChance = 7;
        }break;

        //Item Set: Destroyer   Battlegear
    case 37528:
        //Item Set: Warbringer Armor
    case 37516:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 100;
        }break;

    /**********************************************************
    *   Misc stuff (GLYPH)
    **********************************************************/

    case 55680:// Glyph of Prayer of Healing
    case 56176:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   56161;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
        }break;
    case 58631: // Glyph of Icy Touch
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

        // Glyph of reneved life
    case 58059:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;

        // Glyph of Vigor
    case 56805:
        {
            CopyEffect(dbcSpell.LookupEntryForced(21975), 0, sp, 2);
        }break;

        // Glyph of Lesser Healing Wave
    case 55438:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;

        // Glyph of Frostbolt
    case 56370:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;

        // Glyph of Revenge
    case 58364:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0]=0x0;
            sp->EffectSpellClassMask[0][1]=0x0;
        }break;
        // Glyph of Revenge Proc
    case 58363:
        {
            sp->AuraInterruptFlags  =   AURA_INTERRUPT_ON_CAST_SPELL;
        }break;
    case 56218://Glyph of Corruption
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   17941;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 4;
            sp->EffectSpellClassMask[0][0]=0x0;
        }break;

        //////////////////////////////////////////////////////
        // CLASS-SPECIFIC   SPELL   FIXES                           //
        //////////////////////////////////////////////////////

    /* Note: when   applying spell hackfixes,   please follow   a   template */

        //////////////////////////////////////////
        // WARRIOR                                  //
        //////////////////////////////////////////
    case 7405: //   Sunder Armor
    case 7386: //   Sunder Armor
    case 8380: //   Sunder Armor
    case 11596: // Sunder   Armor
    case 11597: // Sunder   Armor
    case 25225: // Sunder   Armor
    case 30330: // Mortal   Strike Ranks
    case 25248: // Mortal   Strike Ranks
    case 21553: // Mortal   Strike Ranks
    case 21552: // Mortal   Strike Ranks
    case 21551: // Mortal   Strike Ranks
    case 12294: // Mortal   Strike Ranks
    case 16511: // Hemo Rank 1
    case 17347: // Hemo Rank 2
    case 17348: // Hemo Rank 3
    case 26864: // Hemo Rank 4
        {
            sp->Unique = true;
        }break;
        // Wrecking Crew
    case 46867:
    case 56611:
    case 56612:
    case 56613:
    case 56614:
        {
            sp->procFlags   =    PROC_ON_CRIT_ATTACK;
        }break;
        // Enrage
    case 12317:
    case 13045:
    case 13046:
    case 13047:
    case 13048:
        {
            sp->procFlags   =    PROC_ON_ANY_DAMAGE_VICTIM;
        }break;
        // Improved Defensive Stance (Missing Parry Flag)
    case 29593:
    case 29594:
        {
            sp->procflags2  =    PROC_ON_BLOCK_VICTIM | PROC_ON_DODGE_VICTIM;
        }break;
        // Sword and Board
    case 46951:
    case 46952:
    case 46953:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
        // Sword and Board Refresh
    case 50227:
        {
            sp->Effect[1]   =   3;
        }break;
        // Sword specialization
    case 12281:
    case 13960:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
            sp->procChance = 1;
        }break;
    case 12812:
    case 13961:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
            sp->procChance = 2;
        }break;
    case 12813:
    case 13962:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
            sp->procChance = 3;
        }break;
    case 12814:
    case 13963:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
            sp->procChance = 4;
        }break;
    case 12815:
    case 13964:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
            sp->procChance = 5;
        }break;
        // vigilance
    case 50720:
        {
            sp->MaxTargets = 1;
            sp->Unique = true;
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_MOD_MAX_AFFECTED_TARGETS;
            sp->EffectImplicitTargetA[2] = 57;
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
        }break;

        // Damage Shield
    case 58872:
    case 58874 :
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK_VICTIM;
            sp->procflags2 = PROC_ON_BLOCK_VICTIM;
            sp->procChance = 100;
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectImplicitTargetA[2] = 1;
            sp->EffectTriggerSpell[2] = 59653;
        }break;

        // Improved Hamstring
    case 12289:
    case 12668:
    case 23695:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 2;
        }break;

        // Whirlwind
    case 1680:
        {
            sp->AllowBackAttack = true;
        }break;

        // Shockwave
    case 46968:
        {
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MELEE;
        }break;

        // Blood Craze
    case 16487:
    case 16489:
    case 16492:
        {
            sp->procFlags = PROC_ON_SPELL_CRIT_HIT_VICTIM | PROC_ON_CRIT_HIT_VICTIM;
        }break;

        // Gag Order
    case 12311:
    case 12958:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

        //////////////////////////////////////////
        // PALADIN                                  //
        //////////////////////////////////////////

        // Insert   paladin spell   fixes   here
        // Light's Grace PROC
    case 31834:
        {
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
        }break;

        // Seal of Command - Holy   damage, but melee   mechanics   (crit   damage, chance, etc)
    case 20424:
        {
            sp->rangeIndex = 4;
            sp->is_melee_spell = true;
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MAGIC;
            sp->School = SCHOOL_HOLY;
        }break;

        // Illumination
    case 20210:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 18350;
            sp->procChance = 20;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 20212:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 18350;
            sp->procChance = 40;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 20213:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 18350;
            sp->procChance = 60;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 20214:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 18350;
            sp->procChance = 80;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 20215:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 18350;
            sp->procChance = 100;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;

        // Heart of the Crusader rank 1
    case 20335:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 21183;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 8388608;
        }break;

        // Heart of the Crusader rank 2
    case 20336:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 54498;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 8388608;
        }break;

        // Heart of the Crusader rank 3
    case 20337:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 54499;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 8388608;
        }break;

        // Pursuit of Justice rank 1
    case 26022:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED;
            sp->EffectImplicitTargetA[1] = 1;
            sp->EffectBasePoints[1] = 8;
        }break;

        // Pursuit of Justice rank 2
    case 26023:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED;
            sp->EffectImplicitTargetA[1] = 1;
            sp->EffectBasePoints[1] = 15;
        }break;

        // Righteous Vengeance
    case 53380:
    case 53381:
    case 53382:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 61840;
            sp->procFlags = PROC_ON_CRIT_ATTACK;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->EffectSpellClassMask[0][0] = 0xE14BFF42;
        }break;

        // Sheat of Light (Hot Effect)
    case 53501:
    case 53502:
    case 53503:
        {
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1]   =   54203;
            sp->procflags2  =   PROC_ON_SPELL_CRIT_HIT;
        }break;

    case 54203:
        {
            sp->logsId = sp->Id;
        }break;


        // Sacred Shield
    case 53601:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
            sp->procflags2  =   PROC_TARGET_SELF;
            sp->EffectTriggerSpell[0] = 58597;
            sp->proc_interval = 6000;
        }break;

        // SoC/SoV Dot's
    case 31803:
    case 53742:
        {
            sp->School = SCHOOL_HOLY;
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MAGIC;
            sp->Unique = true;
        }break;

        // Judgement of righteousness
    case 20187:
        // Judgement of command
    case 20467:
        // Judgement of Justice/Wisdom/Light
    case 53733:
        // Judgement of Blood
    case 31898:
        // Judgement of Martyr
    case 53726:
        // Judgement of Corruption/Vengeance
    case 31804:
        {
            sp->School = SCHOOL_HOLY;
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MAGIC;
        }break;

        // Shield of Righteousness
    case 53600:
    case 61411:
        {
            sp->School = SCHOOL_HOLY;
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MAGIC;
        }break;

        // Beacon of the Light (Dummy Aura)
    case 53563:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
            sp->c_is_flags = SPELL_FLAG_IS_FORCEDBUFF;
        }break;

        //////////////////////////////////////////
        // HUNTER                               //
        //////////////////////////////////////////

        //Hunter - Go for the Throat
    case 34950:
    case 34954:
        {
            sp->procFlags = PROC_ON_RANGED_CRIT_ATTACK;
        }break;
    case 34952:
    case 34953:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        //Ranged Weapon Specialization
    case 19507:
    case 19508:
    case 19509:
    case 19510:
    case 19511:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_DAMAGE_PERCENT_DONE;
            sp->EffectMiscValue[0] = 1;
        }break;
        //Two Handed Weapon Specialization and One Handed Weapon Specializacion
        //Warrior and Paladin and Death Knight - this will change on 3.1.0
    case 20111:
    case 20112:
    case 20113:
    case 12163:
    case 12711:
    case 12712:
    case 16538:
    case 16539:
    case 16540:
    case 16541:
    case 16542:
    case 20196:
    case 20197:
    case 20198:
    case 20199:
    case 20200:
    case 55107:
    case 55108:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_DAMAGE_PERCENT_DONE;
            sp->EffectMiscValue[0] = 2;
        }break;
        //Frost Trap
    case 13809:
        {
            sp->procFlags = PROC_ON_TRAP_TRIGGER;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;

        //Snakes from Snake Trap cast this, shouldn't stack
    case 25810:
    case 25809:
        {
            sp->maxstack = 1;
        }break;

    case 27065:
    case 20904:
    case 20903:
    case 20902:
    case 20901:
    case 20900:
    case 19434:
        {
            sp->Unique = true;
        }break;

        //Hunter : Entrapment
    case 19184:
    case 19387:
    case 19388:
        {
            sp->procFlags = PROC_ON_TRAP_TRIGGER;
        }break;
        // Hunter - Arcane Shot  - Rank 6 to 11
    case 14285:
    case 14286:
    case 14287:
    case 27019:
    case 49044:
    case 49045:
        {
            sp->Effect[0] = 2;
            sp->Effect[1] = 0;
            sp->EffectBasePoints[0] = sp->EffectBasePoints[1];
            sp->EffectBasePoints[1] = 0;
            sp->EffectImplicitTargetA[0] = 6;
            sp->EffectImplicitTargetA[1] = 0;
        }break;

        // Misdirection
    case 34477:
        {
            sp->MaxTargets = 1;
            sp->Unique = true;
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_MOD_MAX_AFFECTED_TARGETS;
        }break;

        // Misdirection proc
    case 35079:
        {
            sp->MaxTargets = 1;
            sp->Unique = true;
        }break;
        // Aspect of the Viper
    case 34074:
        {
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[2] = 34075;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
        }break;
        // Viper String
    case 3034:
        {
            sp->EffectMultipleValue[0] = 3;
        }break;
        // Improved Steady Shot
    case 53221:
    case 53222:
    case 53224:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x0;
            sp->EffectSpellClassMask[0][1] = 0x0;
        }break;


        // Lock and Load
    case 56342:
    case 56343:
    case 56344:
        {
            sp->procFlags = PROC_ON_TRAP_TRIGGER;
            sp->procChance = sp->EffectBasePoints[0] + 1;
        }break;

        // Lock and load proc
    case 56453:
        {
            sp->DurationIndex = 9;
        }break;

        // Master's Call
    case 53271:
        {
            sp->Effect[0] = SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 54216;
            sp->Effect[1] = SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1] = 54216;
        }break;

        // Haunting party
    case 53290:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 57669;
            sp->EffectImplicitTargetA[0] = 1;
            sp->procChance = 33;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 53291:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 57669;
            sp->EffectImplicitTargetA[0] = 1;
            sp->procChance = 66;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 53292:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 57669;
            sp->EffectImplicitTargetA[0] = 1;
            sp->procChance = 100;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;

        // Flare
    case 1543:
        {
            sp->c_is_flags |= SPELL_FLAG_IS_FORCEDDEBUFF | SPELL_FLAG_IS_TARGETINGSTEALTHED;
        }break;


        //////////////////////////////////////////
        // ROGUE                                    //
        //////////////////////////////////////////

        // Cheat Death
    case 31228:
    case 31229:
    case 31230:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;

        // Cloack of shadows
        // Cloack of shadows PROC
    case 31224:
    case 35729:
        {
            sp->DispelType = DISPEL_MAGIC;
            sp->AttributesEx |= 1024;
        }break;

        // Honor Among Thieves PROC
    case 52916:
        {
            sp->proc_interval = 4000; //workaround
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->procFlags = PROC_ON_CRIT_ATTACK | PROC_ON_RANGED_CRIT_ATTACK;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectImplicitTargetA[1] = 38;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1] = 51699;
        }break;

        // Shadow Dance
    case 51713:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;

        // Let's hack   the entire cheating death   effect to   damage perc resist ;)
    case 45182: // Cheating Death   buff
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN;
            sp->EffectMiscValue[0] = uint32(-91);
        }break;

        // Wound Poison Stuff
    case 27189:
    case 13224:
    case 13223:
    case 13222:
    case 13218:
        {
            sp->Unique = true;
        }break;

        // Killing Spree
    case 51690:
        {
            sp->Effect[0]   =   SPELL_EFFECT_APPLY_AURA;
            sp->Effect[1]   =   0;
            sp->Effect[2]   =   0;
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
            sp->AttributesEx |= ATTRIBUTESEX_NOT_BREAK_STEALTH;
        }break;

        // Focused Attacks
    case 51634:
    case 51635:
    case 51636:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
        }break;

        // Setup
    case 13983:
        {
            sp->proc_interval = 1000;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->procflags2 = PROC_ON_FULL_RESIST;
            sp->procChance = 33;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;
    case 14070:
        {
            sp->proc_interval = 1000;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->procflags2 = PROC_ON_FULL_RESIST;
            sp->procChance = 66;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;
    case 14071:
        {
            sp->proc_interval = 1000;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->procflags2 = PROC_ON_FULL_RESIST;
            sp->procChance = 100;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;

        // Setup PROC
    case 15250:
        {
            sp->proc_interval = 1000;
        }break;

        // Mutilate
    case 1329:
    case 34411:
    case 34412:
    case 34413:
    case 48663:
    case 48666:
        {
            sp->Effect[1] = 0;
            sp->procChance = 0;
            sp->Flags3 &=   ~FLAGS3_REQ_BEHIND_TARGET;
        }break;

    case 35541:
    case 35550:
    case 35551:
    case 35552:
    case 35553:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->procChance  =   20;
        }break;

        //////////////////////////////////////////
        // PRIEST                                   //
        //////////////////////////////////////////

        // Dispersion (org spell)
    case 47585:
        {
            sp->AdditionalAura = 47218;
        }break;

        // Dispersion (remove im effects, in 3.1 there is a spell for this)
    case 47218:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MECHANIC_IMMUNITY;
            sp->EffectApplyAuraName[1] = SPELL_AURA_MECHANIC_IMMUNITY;
            sp->EffectMiscValue[0] = 7;
            sp->EffectMiscValue[1] = 11;
            sp->EffectImplicitTargetA[0] = 1;
            sp->EffectImplicitTargetA[1] = 1;
        }break;

        // Mass dispel
    case 32375:
    case 32592:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 100;
            sp->EffectImplicitTargetA[1] = 1;
        }break;

            // Power Infusion
    case 10060:
        {
            sp->c_is_flags = SPELL_FLAG_IS_FORCEDBUFF;
        }break;

        // Prayer of mending (tricky one :() rank 1
    case 33076:
        {
            sp->Effect[0] = SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 41635;
            sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PARTY_MEMBER;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PARTY_MEMBER;
            sp->EffectImplicitTargetB[0] = 0;
            sp->EffectImplicitTargetB[1] = 0;
        }break;

        // Prayer of mending (tricky one :() rank 2
    case 48112:
        {
            sp->Effect[0] = SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 48110;
            sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PARTY_MEMBER;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PARTY_MEMBER;
            sp->EffectImplicitTargetB[0] = 0;
            sp->EffectImplicitTargetB[1] = 0;
        }break;

        // Prayer of mending (tricky one :() rank 3
    case 48113:
        {
            sp->Effect[0] = SPELL_EFFECT_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 48111;
            sp->Effect[1] = SPELL_EFFECT_DUMMY;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PARTY_MEMBER;
            sp->EffectImplicitTargetA[1] = EFF_TARGET_PARTY_MEMBER;
            sp->EffectImplicitTargetB[0] = 0;
            sp->EffectImplicitTargetB[1] = 0;
        }break;

        // triggered spell, rank 1
    case 41635:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 41637;
            sp->EffectBasePoints[0] = 800;
            sp->procCharges = 0;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
        }break;

        // triggered spell, rank 2
    case 48110:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 41637;
            sp->EffectBasePoints[0] = 905;
            sp->procCharges = 0;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
        }break;

        // triggered spell, rank 3
    case 48111:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 41637;
            sp->EffectBasePoints[0] = 1043;
            sp->procCharges = 0;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
        }break;

        // triggered on hit, this   is the spell that   does the healing/jump
    case 41637:
        {
            sp->Effect[0]   =   SPELL_EFFECT_DUMMY;
            sp->EffectBasePoints[0] =   5;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SELF;
            sp->EffectImplicitTargetB[0] = 0;
        }break;

        // Inner Focus
    case 14751:
        {
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
        }break;

        // Divine Aegis
    case 47509:
    case 47511:
    case 47515:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectImplicitTargetA[0] = 21;
            sp->EffectTriggerSpell[0] = 47753;
        }break;

        // Insert   priest spell fixes here

        //////////////////////////////////////////
        // SHAMAN                                   //
        //////////////////////////////////////////
    case 51466:
    case 51470: //Elemental Oath
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_ADD_FLAT_MODIFIER;
            sp->EffectMiscValue[1] = SMT_LAST_EFFECT_BONUS;
            sp->EffectSpellClassMask[1][0] = 0;
            sp->EffectSpellClassMask[1][1] = 0x00004000; // Clearcasting
        }break;
    case 51562:
    case 51563:
    case 51564:
    case 51565:
    case 51566: // Tidal Waves
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x00000100;    // Chain heal
            sp->EffectSpellClassMask[0][1] = 0x00000000;
            sp->EffectSpellClassMask[0][2] = 0x00000010;    // Riptide
        }break;
    case 53390:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case 51940:
    case 51989:
    case 52004:
    case 52005:
    case 52007:
    case 52008: // Earthliving Weapon
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 20;
        }break;
    case 51945:
    case 51990:
    case 51997:
    case 51998:
    case 51999:
    case 52000:
        {
            sp->logsId = sp->Id;
        }break;
    case 55198: // Tidal Force
        {
            sp->Effect[0] = SPELL_EFFECT_DUMMY;
            sp->EffectApplyAuraName[0] = 0;
            sp->EffectTriggerSpell[0] = 55166;
        }break;
    case 55166:
        {
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case 51525:
    case 51526:
    case 51527: // Static Shock
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = sp->Id;
            sp->EffectSpellClassMask[0][0] = 0;
        }break;
    case 16180:
    case 16196:
    case 16198: // Improved Water Shield
        {
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x000000C0; // Healing Wave and Lesser Healing Wave
            sp->EffectSpellClassMask[0][2] = 0x00000010; //Riptide
            sp->EffectTriggerSpell[0] = sp->Id;
        }break;
    case 16187:
    case 16205:
    case 16206:
    case 16207:
    case 16208: // Restorative Totems
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_PCT_MODIFIER;
            sp->EffectMiscValue[0] = SMT_DAMAGE_DONE;
            sp->EffectApplyAuraName[1] = SPELL_AURA_ADD_PCT_MODIFIER;
        }break;
    case 31616: // Nature's Guardian
        {
            sp->logsId = sp->Id;
            sp->spell_can_crit = false;
        }break;

        // Improved firenova totem
    case 16086:
    case 16544:
        {
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;

        //////////////////////////////////////////
        // MAGE                                 //
        //////////////////////////////////////////

        // Insert   mage spell fixes here

        // Invisibility
    case 66:
        {
            sp->EffectTriggerSpell[1] = 32612;
            sp->EffectAmplitude[1]  =   3000;
        }break;

        // Invisibility part    2
    case 32612:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
            sp->Effect[2] = 0;
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL | AURA_INTERRUPT_ON_START_ATTACK | AURA_INTERRUPT_ON_HOSTILE_SPELL_INFLICTED;
        }break;

        //improved blink
    case 31569:
    case 31570:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

        // Magic Absorption
    case 29441:
    case 29444:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 29442;
        }break;

        //Missile Barrage
    case 44404:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 4;
        }break;
    case 54486:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 8;
        }break;
    case 54488:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 12;
        }break;
    case 54489:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 16;
        }break;
    case 54490:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = 20;
        }break;
        //Fiery Payback
    case 44440:
    case 44441:
        {
            sp->procChance  =   100;
            sp->procFlags = PROC_ON_SPELL_HIT_VICTIM | PROC_ON_MELEE_ATTACK_VICTIM | PROC_ON_RANGED_ATTACK_VICTIM | PROC_ON_ANY_DAMAGE_VICTIM;
        }break;

        //Fingers of Frost
    case 44543:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance  =   7;
        }break;
    case 44545:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance  =   15;
        }break;

        //Conjure Refreshment table
    case 43985:
    case 58661:
        {
            sp->EffectImplicitTargetA[0]    =   EFF_TARGET_DYNAMIC_OBJECT;
        }break;

        // Ritual of Refreshment
    case 43987:
    case 58659:
        {
            sp->c_is_flags |= SPELL_FLAG_IS_REQUIRECOOLDOWNUPDATE;
        }break;

        // Living bomb
    case 44457:
    case 55359:
    case 55360:
        {
            sp->c_is_flags |= SPELL_FLAG_ON_ONLY_ONE_TARGET;
        }break;

        // Arcane Potency proc
    case 57529:
    case 57531:
        {
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
        }break;

        // Burnout
    case 44449:
    case 44469:
    case 44470:
    case 44471:
    case 44472:
        {
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1] = 44450;
            sp->EffectImplicitTargetA[1] = 1;
            sp->procChance = 100;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;

        //////////////////////////////////////////
        // WARLOCK                                  //
        //////////////////////////////////////////

        // Insert   warlock spell   fixes   here
    // Demonic Knowledge
    case 35691:
    case 35692:
    case 35693:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = 100;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectImplicitTargetA[1] = 5;
            sp->EffectTriggerSpell[1] = 35696;
        }break;

        // Demonic Knowledge PROC
    case 35696:
        {
            sp->EffectImplicitTargetA[0] = 1;
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;

        // Demonic Pact AA
    case 48090:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AREA_AURA;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AREA_AURA;
            sp->AreaAuraTarget = AA_TARGET_RAID;
        }break;

        // Demonic Pact
    case 53646:
        {
            sp->procChance = 100;
            sp->procFlags = PROC_ON_MELEE_ATTACK;
        }break;
        // Unstable Affliction
    case 30108:
    case 30404:
    case 30405:
    case 47841:
    case 47843:
        {
            sp->procFlags = PROC_ON_DISPEL_AURA_VICTIM;
            sp->procChance = 100;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectImplicitTargetA[1] = 6;
            sp->EffectTriggerSpell[1] = 31117;
        }break;

        // Death's Embrace
    case 47198:
    case 47199:
    case 47200:
        {
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_DUMMY;
            sp->EffectImplicitTargetA[2] = 1;
        }break;

        // Everlasting affliction
    case 47201:
    case 47202:
    case 47203:
    case 47204:
    case 47205:
        {
            sp->procFlags = PROC_ON_SPELL_LAND;
        }break;

        //warlock - Molten Core
    case 47245:
    case 47246:
    case 47247:
        {
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION;
        }break;

        // pandemic
    case 58435:
    case 58436:
    case 58437:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 58691;
            sp->EffectImplicitTargetA[0] = 6;
        }break;

        // Mana Feed
    case 30326:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 32554;
            sp->EffectImplicitTargetA[0] = EFF_TARGET_PET;
        }break;

        // Fel Synergy
    case 47230:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 54181;
        }break;
    case 47231:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 54181;
        }break;

        //////////////////////////////////////////
        // DRUID                                    //
        //////////////////////////////////////////

        // Insert   druid   spell   fixes   here
    case 22570:
    case 49802: // Maim
        {
            sp->AuraInterruptFlags |=   AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN;
            sp->Attributes |=   ATTRIBUTES_STOP_ATTACK;
        }break;

        // RAVAGE
    case 6785:
        {
            sp->EffectBasePoints[0] = 162;              //r1
        }break;
    case 6787:
        {
            sp->EffectBasePoints[0] = 239;              //r2
        }break;
    case 9866:
        {
            sp->EffectBasePoints[0] = 300;              //r3
        }break;
    case 9867:
        {
            sp->EffectBasePoints[0] = 377;              //r4
        }break;
    case 27005:
        {
            sp->EffectBasePoints[0] = 566;              //r5
        }break;
    case 48578:
        {
            sp->EffectBasePoints[0] = 1405;             //r6
        }break;
    case 48579:
        {
            sp->EffectBasePoints[0] = 1770;             //r7
        }break;

        //SHRED
    case 5221:
        {
            sp->EffectBasePoints[0] = 54;               //r1
        }break;
    case 6800:
        {
            sp->EffectBasePoints[0] = 72;               //r2
        }break;
    case 8992:
        {
            sp->EffectBasePoints[0] = 99;               //r3
        }break;
    case 9829:
        {
            sp->EffectBasePoints[0] = 144;              //r4
        }break;
    case 9830:
        {
            sp->EffectBasePoints[0] = 180;              //r5
        }break;
    case 27001:
        {
            sp->EffectBasePoints[0] = 236;              //r6
        }break;
    case 27002:
        {
            sp->EffectBasePoints[0] = 405;              //r7
        }break;
    case 48571:
        {
            sp->EffectBasePoints[0] = 630;              //r8
        }break;
    case 48572:
        {
            sp->EffectBasePoints[0] = 742;              //r9
        }break;

        // Natural reaction
    case 57878:
    case 57880:
    case 57881:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->procFlags = 0;
            sp->procChance = 0;
            sp->EffectTriggerSpell[1] = 0;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;

        // Dash
    case 1850:
    case 9821:
    case 33357:
        {
            sp->RequiredShapeShift  =   1;
        }break;

        // Totem of Wrath
    case 30708:
        {
            sp->Effect[0] = 6;
            sp->EffectImplicitTargetA[0] = 22;
            sp->EffectImplicitTargetB[0] = 15;
            sp->EffectRadiusIndex[0] = 10;
            sp->AreaAuraTarget = AA_TARGET_ALLENEMIES;
        }break;

        // Mangle - Cat
    case 33876:
        {
            sp->EffectBasePoints[0] = 198; //rank 1
        }break;
    case 33982:
        {
            sp->EffectBasePoints[0] = 256; //rank 2
        }break;
    case 33983:
        {
            sp->EffectBasePoints[0] = 330; //rank 3
        }break;
    case 48565:
        {
            sp->EffectBasePoints[0] = 536; //rank 4
        }break;
    case 48566:
        {
            sp->EffectBasePoints[0] = 634; //rank 5
        }break;
        // Mangle - Bear
    case 33878:
        {
            sp->EffectBasePoints[0] = 86; //rank 1
        }break;
    case 33986:
        {
            sp->EffectBasePoints[0] = 120; //rank 2
        }break;
    case 33987:
        {
            sp->EffectBasePoints[0] = 155; //rank 3
        }break;
    case 48563:
        {
            sp->EffectBasePoints[0] = 251; //rank 4
        }break;
    case 48564:
        {
            sp->EffectBasePoints[0] = 299; //rank 5
        }break;

        //Druid - Master Shapeshifter
    case 48411:
    case 48412:
        {
            sp->Effect[0]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0]  =   SPELL_AURA_DUMMY;
            sp->Effect[1]   =   0;
            sp->Effect[2]   =   0;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance  =   100;
        }break;
    case 48418:
        {
            sp->RequiredShapeShift  =   (uint32)(1<<(FORM_BEAR-1))|(1<<(FORM_DIREBEAR-1));
        }break;
    case 48420:
        {
            sp->RequiredShapeShift  =   (uint32)(1<<(FORM_CAT-1));
        }break;
    case 48421:
        {
            sp->RequiredShapeShift  =   (uint32)1 << (FORM_MOONKIN-1);
        }break;
    case 48422:
        {
            sp->RequiredShapeShift  =   (uint32)1 << (FORM_TREE-1);
        }break;
        //Owlkin Frenzy
    case 48389:
    case 48392:
    case 48393:
        {
            sp->procFlags   =   PROC_ON_ANY_HOSTILE_ACTION | PROC_ON_MELEE_ATTACK | PROC_ON_RANGED_ATTACK;
            sp->EffectSpellClassMask[0][0]  =   0x0;
        }break;
        // Infected Wounds
    case 48483:
    case 48484:
    case 48485:
        {
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION | PROC_ON_MELEE_ATTACK;
        }break;
        // Swipe (cat) max targets, fixed in 3.1
    case 62078:
        {
            sp->MaxTargets = 10;
        }break;
        // faerie fire (feral dmg)
    case 16857:
        {
            sp->Effect[1] = SPELL_EFFECT_SCHOOL_DAMAGE;
            sp->EffectBasePoints[1] = 1;
            sp->EffectImplicitTargetA[1] = 6;
        }break;

        // King of the jungle dmg buff
    case 51185:
        {
            sp->DurationIndex = 1;
            sp->RequiredShapeShift = (uint32)(1<<(FORM_BEAR-1))|(1<<(FORM_DIREBEAR-1));
        }break;
    case 60200:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;

        // Eclipse
    case 48516:
    case 48521:
    case 48525:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 48517;
            sp->EffectTriggerSpell[1] = 48518;
        }break;

        // Living Seed
    case 48496:
    case 48499:
    case 48500:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectImplicitTargetA[0] = 21;
            sp->EffectTriggerSpell[0] = 48503;
        }break;

        // Healing way
    case 29203:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = 108; //ADD PCT MOD
            sp->EffectMiscValue[0] = 0;
            sp->EffectSpellClassMask[0][0] = 64;
            sp->EffectSpellClassMask[0][1] = 0;
            sp->EffectSpellClassMask[0][2] = 0;
        }break;

    case 50334:
        {
            sp->AdditionalAura = 58923;
        }break;

    case 17002:
        {
            sp->AdditionalAura = 24867;
        }break;
    case 24866:
        {
            sp->AdditionalAura = 24864;
        }break;

    case 24867:
    case 24864:
        {
            sp->apply_on_shapeshift_change = true;
        }break;

    case 24905:
        {
            sp->procFlags = PROC_ON_SPELL_CRIT_HIT;
        }break;

    case 33881:
    case 33882:
    case 33883:
        {
            sp->procFlags = PROC_ON_CRIT_HIT_VICTIM;
        }break;

    case 22842:
    case 22895:
    case 22896:
    case 26999:
        {
            sp->Effect[0] = 6;
            sp->EffectApplyAuraName[0] = SPELL_AURA_PERIODIC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 22845;
        }break;

    case 16850:
        {
            sp->procChance = 3;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case 16923:
        {
            sp->procChance = 6;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case 16924:
        {
            sp->procChance = 9;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

    case 24932:
        {
            sp->Effect[1] = 0;
            sp->Effect[2] = 0; //removing strange effects.
            sp->AreaAuraTarget = AA_TARGET_PARTY;
        }break;

    case 34299:
        {
            sp->proc_interval = 6000;//6 secs
        }break;
    case 49376:
        {
            sp->Effect[1] = 41;
            sp->EffectImplicitTargetA[1] = 6;
        }break;

        //////////////////////////////////////////
        // DEATH KNIGHT                         //
        //////////////////////////////////////////

        // Merciless Combat
    case 49024:
    case 49538:
        {
            sp->EffectMiscValue[0] = 7278;
        }break;

    case 46619:
        {
            sp->Effect[0] = SPELL_EFFECT_NULL;
        }break;

    //Desecration
    case 55666: 
    case 55667:
        {
            sp->proc_interval = 15000;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

    case 50397:
        {
            sp->NameHash = 0;
        }break;

        //////////////////////////////////////////
        // BOSSES                               //
        //////////////////////////////////////////

        // Insert   boss spell fixes here

        // War Stomp
    case 20549:
        {
            sp->RequiredShapeShift = 0;
        }break;

        // Dark Glare
    case 26029:
        {
            sp->cone_width = 15.0f; // 15   degree cone
        }break;

        // Commendation of Kael'thas
    case 45057:
        {
            sp->proc_interval   =   30000;
        }break;

        // Recently Dropped Flag
    case 42792:
        {
            sp->c_is_flags |=   SPELL_FLAG_IS_FORCEDDEBUFF;
        }break;

    case 43958:
        {
            sp->Effect[0]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
            sp->DurationIndex   =   6; //   10 minutes.
            sp->c_is_flags |=   SPELL_FLAG_IS_FORCEDDEBUFF;
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_ADD_PCT_MODIFIER;
            sp->EffectMiscValue[1] = SMT_RESIST_DISPEL;
            sp->EffectBasePoints[1] =   90;
        }break;

        // Recently Dropped Flag
    case 43869:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
            sp->c_is_flags |=   SPELL_FLAG_IS_FORCEDDEBUFF;
        }break;

    case 48978:
    case 61216:
        {
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
            sp->EffectMiscValue[1] = 1;
        }break;

    case 49390:
    case 61221:
        {
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
            sp->EffectMiscValue[1] = 2;
        }break;

    case 49391:
    case 61222:
        {
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
            sp->EffectMiscValue[1] = 3;
        }break;

    case 49392:
        {
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
            sp->EffectMiscValue[1] = 4;
        }break;

    case 49393:
        {
            sp->Effect[1]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
            sp->EffectMiscValue[1] = 5;
        }break;

        // Furious Attacks
    case 46910:
        {
            sp->EffectTriggerSpell[0]   =   56112;
            sp->procChance = 50;
            sp->procFlags   |= PROC_ON_MELEE_ATTACK;
        }break;

    case 46911:
        {
            sp->EffectTriggerSpell[0]   =   56112;
            sp->procChance = 100;
            sp->procFlags   |= PROC_ON_MELEE_ATTACK;
        }break;

        // Rogue:   Hunger for Blood!
    case 51662:
        {
            sp->Effect[1]   =   SPELL_EFFECT_DUMMY;
        }break;

        // Mage: Focus Magic
    case 54646:
        {
            sp->c_is_flags = SPELL_FLAG_ON_ONLY_ONE_TARGET;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->procChance = 100;
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[1] = 54648;
        }break;

        // Mage: Hot Streak
    case 44445:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 48108;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->procChance = 33;
            sp->EffectSpellClassMask[0][0] = 0x0;
        }break;
    case 44446:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 48108;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->procChance = 66;
            sp->EffectSpellClassMask[0][0] = 0x0;
        }break;
    case 44448:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0] = 48108;
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
            sp->procChance = 100;
            sp->EffectSpellClassMask[0][0] = 0x0;
        }break;

    case 1122:
        {
            sp->EffectBasePoints[0] =   0;
        }break;

    case 1860:
    case 20719:
        {
            sp->Effect[0]   =   SPELL_EFFECT_DUMMY;
        }break;
        // Bloodsurge
    case 46913:
    case 46914:
    case 46915:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK | PROC_ON_ANY_HOSTILE_ACTION | PROC_ON_CAST_SPELL;
        }break;
    case 46916:
        {
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
        }break;
        //Waylay
    case 51692:
    case 51696:
        {
            sp->procFlags   =   PROC_ON_CRIT_ATTACK;
        }break;
        // Cold Blood
    case 14177:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
        }break;
        // priest   -   mind flay
    case 15407:
    case 17311:
    case 17312:
    case 17313:
    case 17314:
    case 18807:
    case 25387:
    case 48155:
    case 48156:
        {
            sp->EffectImplicitTargetA[0] = EFF_TARGET_SINGLE_ENEMY;
            sp->logsId = 58381;
        }break;

    case 1464:
    case 8820:
    case 11604:
    case 11605:
    case 25241:
    case 25242:
    case 47474:
    case 47475:
        {   // LogID Fix
            sp->logsId = 50782;
        }break;

        // Death and Decay
    case 43265:
    case 49936:
    case 49937:
    case 49938:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PERIODIC_DAMAGE;
        }break;
        //Warlock   Chaos   bolt
    case 50796:
    case 59170:
    case 59171:
    case 59172:
        {
            sp->Attributes = ATTRIBUTES_IGNORE_INVULNERABILITY;
        }break;
        //Force debuff's
        // Hypothermia
    case 41425:
        // Forbearance
    case 25771:
        // Weakened Soul
    case 6788:
        {
            sp->c_is_flags = SPELL_FLAG_IS_FORCEDDEBUFF;
        }break;
        // Death Knight spell   fixes
        //Blade Barrier
    case 49182:
    case 49500:
    case 49501:
    case 55225:
    case 55226:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance = 100;
        }break;
        // Killing Machine
    case 51123:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->ProcsPerMinute = 1;
        }break;
    case 51127:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->ProcsPerMinute = 2;
        }break;
    case 51128:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->ProcsPerMinute = 3;
        }break;
    case 51129:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->ProcsPerMinute = 4;
        }break;
    case 51130:
        {
            sp->procFlags   =   PROC_ON_MELEE_ATTACK;
            sp->ProcsPerMinute = 5;
        }break;
    case 49175:
    case 50031:
    case 51456: // Improved Icy Touch
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_ADD_PCT_MODIFIER;
        }break;
    case 49143:
    case 51416:
    case 51417:
    case 51418:
    case 51419:
    case 55268: // Frost Strike
        {
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MAGIC;
        }break;
    case 55090:
    case 55265:
    case 55270:
    case 55271: // Scourge Strike
        {
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MAGIC;
        }break;
    case 1843:  // Disarm
        {
            sp->Effect[0] = 0;  // to prevent abuse at Arathi
        }break;
        // Bone Shield
    case 49222:
        {
            sp->procFlags   =   PROC_ON_ANY_DAMAGE_VICTIM;
            sp->proc_interval   =   3000;
        }break;
        // Shadow   of Death
    case 49157:
        {
            sp->Effect[0]   =   0;  // don't want   DKs to be   always invincible
        }break;
        // Death Grip
    case 49576:
        {
            sp->FacingCasterFlags   =   0;
        }break;
        // shadow   of death
    case 54223:
        {
            sp->Effect[2]   =   SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_DUMMY;
            sp->Flags4 |=   FLAGS4_DEATH_PERSISTENT;
        }break;
    case 54749://Burning Determination
    case 54747:
        {
            sp->procFlags = PROC_ON_SPELL_LAND_VICTIM;
        }break;
    case 48266://blood presence
        {
            sp->EffectTriggerSpell[1] = 50475;
            sp->procFlags = PROC_ON_ANY_HOSTILE_ACTION | PROC_ON_MELEE_ATTACK;
        }break;
    case 50475:
        {
            sp->Effect[0] = SPELL_EFFECT_NULL;
        }break;
    case 48263://Frost Presence
        {
            sp->AdditionalAura = 61261;
        }break;
    case 48265://Unholy Presence
        {
            sp->AdditionalAura = 49772;
        }break;
    case 56364:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case 44443://Firestarter
    case 44442:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x0;
            sp->EffectSpellClassMask[0][1] = 0x0;
        }break;
        //Mage - Brain Freeze
    case 44546:
    case 44584:
    case 44549:
        {
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x0;
            sp->EffectSpellClassMask[0][1] = 0x0;
        }break;
    case 54741:
        {
            sp->AuraInterruptFlags  =   AURA_INTERRUPT_ON_CAST_SPELL;
        }break;

    case 56368:
        {
            sp->Effect[1] = sp->Effect[0];
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;
    case 48020:
        {
            sp->Effect[1] = SPELL_EFFECT_DUMMY;
        }break;
    case 48018: // Demonic Circle dummy shit.
        {
            sp->AdditionalAura = 62388;
            sp->EffectImplicitTargetA[0] = 1;
        }break;

        //Noise Machine - Sonic Shield
    case 54808:
        {
            sp->EffectApplyAuraName[0]  =   SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   55019;
            sp->procFlags   =   PROC_ON_MELEE_ATTACK_VICTIM;
            sp->proc_interval   =   60000;
            sp->procChance  =   50;
        }break;
        //Pendulum of Telluric Currents
    case 60482:
        {
            sp->EffectApplyAuraName[0]  =   SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   60483;
            sp->procFlags   =   PROC_ON_CAST_SPELL;
            sp->procChance  =   15;
        }break;
        //Tears of Bitter Anguish
    case 58901:
        {
            sp->EffectApplyAuraName[0]  =   SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->EffectTriggerSpell[0]   =   58904;
            sp->procFlags   =   PROC_ON_CRIT_ATTACK;
            sp->procChance  =   10;
        }break;
    case 20578:
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_MOVEMENT|AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN;
        break;
    case 51729:
        {
            sp->buffIndexType = 0;
            sp->buffType = 0;
            sp->AreaGroupId = 0;
        }break;
    case 58691://Pandemic
        {
            sp->spell_can_crit = false;
        }break;
    case 54197:
        {
            sp->Effect[0] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;
        //Warlock - Nether Protection
    case 30299:
    case 30301:
    case 30302:
        {
            sp->procFlags = PROC_ON_SPELL_HIT_VICTIM;
        }break;

    case 71905:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;

        //////////////////////////////////////////
        // ITEMSETS                             //
        //////////////////////////////////////////

    case 70765: // Divine Storm Cooldown Clear
        {
//#define STORM_NERF
#ifdef STORM_NERF
            sp->procChance = 20; // Crow: I got a feeling...
#else
            sp->procChance = 40; // Current blizzlike settings.
#endif
        }break;

        //////////////////////////////////////////////////////////////////
        //AREA AURA TARGETS - START
        //////////////////////////////////////////////////////////////////

    case 57658: // Shaman - totem of the wrath
    case 57660:
    case 57662:
    case 34123: // Druid - tree of life
        {
            sp->AreaAuraTarget = AA_TARGET_RAID;
        }break;
    
    //Spells using Aura 109
    case 50040:
    case 50041:
    case 50043:
    case 64745:
    case 60675:
    case 60685:
    case 60686:
    case 60687:
    case 60688:
    case 60690:
    case 64936:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procChance = sp->EffectBasePoints[0]+1;
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;

        // Glyph of hex
    case 63291:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_DUMMY;
        }break;
    }

    switch( sp->NameHash )
    {
        //Pal
    case SPELL_HASH_CONCENTRATION_AURA:
    case SPELL_HASH_RETRIBUTION_AURA:
    case SPELL_HASH_DIVINE_GUARDIAN:
        //Hunter
    case SPELL_HASH_ASPECT_OF_THE_WILD:
    case SPELL_HASH_TRUESHOT_AURA:
        //Death knight
    case SPELL_HASH_PATH_OF_FROST:
        //Druid
    case SPELL_HASH_MOONKIN_AURA:
    case SPELL_HASH_IMPROVED_MOONKIN_FORM:
        //Warlock
    case SPELL_HASH_BLOOD_PACT:
    case SPELL_HASH_FEL_INTELLIGENCE:
        {
            sp->AreaAuraTarget = AA_TARGET_RAID;
        }break;

        //Pal
    case SPELL_HASH_DEVOTION_AURA:
    case SPELL_HASH_CRUSADER_AURA:
    case SPELL_HASH_SHADOW_RESISTANCE_AURA:
    case SPELL_HASH_FROST_RESISTANCE_AURA:
    case SPELL_HASH_FIRE_RESISTANCE_AURA:
        //Hunter
    case SPELL_HASH_ASPECT_OF_THE_PACK:
        //Shaman
    case SPELL_HASH_FIRE_RESISTANCE:
    case SPELL_HASH_FROST_RESISTANCE:
    case SPELL_HASH_NATURE_RESISTANCE:
    case SPELL_HASH_STONESKIN:
    case SPELL_HASH_STRENGTH_OF_EARTH:
    case SPELL_HASH_WINDFURY_TOTEM:
    case SPELL_HASH_WRATH_OF_AIR_TOTEM:
        //Priest
    case SPELL_HASH_PRAYER_OF_FORTITUDE:
    case SPELL_HASH_PRAYER_OF_SHADOW_PROTECTION:
    case SPELL_HASH_PRAYER_OF_SPIRIT:
        //Warrior
    case SPELL_HASH_BATTLE_SHOUT:
    case SPELL_HASH_COMMANDING_SHOUT:
        {
            sp->AreaAuraTarget = AA_TARGET_PARTY;
        }break;

        //Hunter
    case SPELL_HASH_ASPECT_OF_THE_BEAST:
        {
            sp->AreaAuraTarget = AA_TARGET_PET;
        }break;
        //Rogue
    case SPELL_HASH_HONOR_AMONG_THIEVES:
        {
            sp->AreaAuraTarget = AA_TARGET_NOTSELF | AA_TARGET_PARTY;
        }break;

        //////////////////////////////////////////////////////
        // CLASS-SPECIFIC NAMEHASH FIXES                    //
        //////////////////////////////////////////////////////
        ////////////// WARRIOR ///////////////////

    case SPELL_HASH_BLADESTORM:
        sp->AllowBackAttack = true;
        break;

    case SPELL_HASH_MORTAL_STRIKE:
        sp->maxstack = 1; // Healing reduction shouldn't stack
        break;

    case SPELL_HASH_TRAUMA:
        sp->procFlags = PROC_ON_CRIT_ATTACK;
        break;

    case SPELL_HASH_SLAM:
        sp->Effect[0] = SPELL_EFFECT_SCHOOL_DAMAGE;
        break;

    case SPELL_HASH_HOLY_SHIELD:
        sp->procflags2 = PROC_ON_BLOCK_VICTIM;
        break;

        ////////////// PALADIN ///////////////////

    case SPELL_HASH_JUDGEMENT_OF_WISDOM:
    case SPELL_HASH_JUDGEMENT_OF_LIGHT:
    case SPELL_HASH_JUDGEMENT_OF_JUSTICE:
    case SPELL_HASH_HEART_OF_THE_CRUSADER:
        sp->maxstack = 1;
        break;

    case SPELL_HASH_SEAL_OF_LIGHT:
        {
            sp->Effect[2] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[2] = SPELL_AURA_DUMMY;
            sp->ProcsPerMinute = 10;    /* this will do */
        }break;

    case SPELL_HASH_SEALS_OF_THE_PURE:
        {
            sp->EffectSpellClassMask[0][0] = 8389632 | 4194312 | 512;
            sp->EffectSpellClassMask[0][1] = 134217728 | 536870912;
            sp->EffectSpellClassMask[0][2] = 0;
            sp->EffectSpellClassMask[1][0] = 2048;
            sp->EffectSpellClassMask[1][1] = 0;
            sp->EffectSpellClassMask[1][2] = 0;
        }break;

    case SPELL_HASH_JUDGEMENTS_OF_THE_PURE:
        {   // Ignore our triggered spells.
            if(sp->Id != 54153 && sp->Id != 53655 && sp->Id != 53656 && sp->Id != 53657 && sp->Id != 54152 )
            {
                sp->EffectSpellClassMask[0][0] = 8388608;
                sp->EffectSpellClassMask[0][1] = 0;
                sp->EffectSpellClassMask[0][2] = 0;
                sp->EffectSpellClassMask[1][0] = 8389632 | 4194312 | 512;
                sp->EffectSpellClassMask[1][1] = 134217728 | 536870912 | 33554432;
                sp->EffectSpellClassMask[1][2] = 0;
                sp->EffectSpellClassMask[2][0] = 2048;
                sp->EffectSpellClassMask[2][1] = 0;
                sp->EffectSpellClassMask[2][2] = 0;
                sp->procFlags = PROC_ON_CAST_SPELL;
            }
        }break;
    case SPELL_HASH_DEVOURING_PLAGUE:
        {
            sp->MaxTargets = 1;
        }break;
    case SPELL_HASH_IMPROVED_DEVOTION_AURA:
        {
                sp->EffectApplyAuraName[1] = SPELL_AURA_MOD_HEALING_PCT;
                sp->EffectBasePoints[1] = 6;
                sp->EffectMiscValue[1] = 127;
        }break;
    case SPELL_HASH_AVENGER_S_SHIELD:
        {
            sp->Spell_Dmg_Type = SPELL_DMG_TYPE_MAGIC;
        }break;
    case SPELL_HASH_SHIELD_OF_RIGHTEOUSNESS:
        {
            sp->EffectChainTarget[0] = 0;
        }break;
    case SPELL_HASH_AIMED_SHOT:
        {
            sp->maxstack = 1; // Healing reduction shouldn't stack
        }break;
    case SPELL_HASH_EXPLOSIVE_SHOT:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PERIODIC_DAMAGE;
        }break;
    case SPELL_HASH_MORTAL_SHOTS:
        {
            sp->EffectSpellClassMask[0][0] += 1;
        }break;
    case SPELL_HASH_MEND_PET:
        {
            sp->ChannelInterruptFlags = 0;
        }break;
    case SPELL_HASH_EAGLE_EYE:
        {
            sp->Effect[1] = 0;
        }break;
    case SPELL_HASH_ENTRAPMENT:
        {
            if(sp->EffectApplyAuraName[0] == SPELL_AURA_MOD_ROOT)
            {
                sp->EffectImplicitTargetA[0] = 15;
                sp->EffectRadiusIndex[0] = 13;
            }
        }break;
    case SPELL_HASH_WILD_QUIVER:
        {
            sp->EffectApplyAuraName[1] = 0;
        }break;
    case SPELL_HASH_REMORSELESS_ATTACKS:
        {
            sp->procFlags = PROC_ON_GAIN_EXPIERIENCE;
        }break;
    case SPELL_HASH_UNFAIR_ADVANTAGE:
        {
            sp->procflags2 = PROC_ON_DODGE_VICTIM;
        }break;
    case SPELL_HASH_COMBAT_POTENCY:
        {
            sp->procFlags = PROC_ON_MELEE_ATTACK;
        }break;
    case SPELL_HASH_PAIN_AND_SUFFERING:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case SPELL_HASH_FOCUSED_ATTACKS:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
        }break;
    case SPELL_HASH_SEAL_FATE:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;
    case SPELL_HASH_VILE_POISONS:
        {
            sp->EffectSpellClassMask[0][0] = 8388608; // envenom
            sp->EffectSpellClassMask[0][1] = 8;
            sp->EffectSpellClassMask[1][0] = 8192 | 268435456 | 65536; //poisons
            sp->EffectSpellClassMask[1][1] = 524288;
        }break;
    case SPELL_HASH_STEALTH:
        {
            if( !(sp->AuraInterruptFlags & AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN ) )
                sp->AuraInterruptFlags |= AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN;

            // fuck this
            sp->EffectBasePoints[1] = 0;
        }break;
    case SPELL_HASH_NERVES_OF_STEEL:
        {
            sp->CasterAuraState = 6;
            sp->EffectBasePoints[0] = -31;
            sp->EffectApplyAuraName[0] = SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN;
        }break;
    case SPELL_HASH_DISARM_TRAP:
        {
            sp->Effect[0] = SPELL_EFFECT_DUMMY;
        }break;
    case SPELL_HASH_BORROWED_TIME:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectApplyAuraName[1] = SPELL_AURA_ADD_PCT_MODIFIER;
        }break;
    case SPELL_HASH_IMPROVED_SPIRIT_TAP:
        {
            sp->procflags2 = PROC_ON_SPELL_CRIT_HIT;
        }break;
    case SPELL_HASH_MISERY:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case SPELL_HASH_POWER_INFUSION:
    case SPELL_HASH_HEROISM:
    case SPELL_HASH_BLOODLUST:
        {
            sp->buffType = SPELL_TYPE_HASTE;
        }break;
    case SPELL_HASH_HEX:
        {
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN;
        }break;
    case SPELL_HASH_LIGHTNING_SHIELD:
        {
            sp->spell_can_crit = false;
        }break;
    case SPELL_HASH_FROSTBRAND_WEAPON:
        {
            sp->ProcsPerMinute = 9.0f;
            sp->Flags3 |= FLAGS3_ENCHANT_OWN_ONLY;
        }break;
    case SPELL_HASH_NATURE_S_GUARDIAN:
        {
            sp->procFlags = PROC_ON_SPELL_HIT_VICTIM | PROC_ON_MELEE_ATTACK_VICTIM | PROC_ON_RANGED_ATTACK_VICTIM | PROC_ON_ANY_DAMAGE_VICTIM;
            sp->proc_interval = 8000;
            sp->EffectTriggerSpell[0] = 31616;
        }break;
    case SPELL_HASH_WINDFURY_WEAPON:
    case SPELL_HASH_FLAMETONGUE_WEAPON:
    case SPELL_HASH_ROCKBITER_WEAPON:
    case SPELL_HASH_EARTHLIVING_WEAPON:
        {
            sp->Flags3 |= FLAGS3_ENCHANT_OWN_ONLY;
        }break;
    case SPELL_HASH_STONECLAW_TOTEM_PASSIVE:
        {
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
        }break;
    case SPELL_HASH_FLAMETONGUE_TOTEM:
        {
            sp->AreaAuraTarget = AA_TARGET_PARTY;
            if(sp->Attributes & ATTRIBUTES_PASSIVE)
            {
                sp->EffectImplicitTargetA[0] = EFF_TARGET_SELF;
                sp->EffectImplicitTargetB[0] = 0;
                sp->EffectImplicitTargetA[1] = EFF_TARGET_SELF;
                sp->EffectImplicitTargetB[1] = 0;
            }
        }break;
    case SPELL_HASH_UNLEASHED_RAGE:
        {
            sp->procFlags = PROC_ON_CRIT_ATTACK;
        }break;
    case SPELL_HASH_HEALING_STREAM_TOTEM:
        {
            if(sp->Effect[0] == SPELL_EFFECT_DUMMY)
            {
                sp->EffectRadiusIndex[0] = 10; // 30 yards
                sp->Effect[0] = SPELL_EFFECT_HEAL;
                sp->logsId = 5394;
            }
        }break;
    case SPELL_HASH_MANA_SPRING_TOTEM:
        {
            if(sp->Effect[0] == SPELL_EFFECT_DUMMY)
            {
                sp->Effect[0] = SPELL_EFFECT_ENERGIZE;
                sp->EffectMiscValue[0] = POWER_TYPE_MANA;
                sp->logsId = 5675;
            }
        }break;
    case SPELL_HASH_FAR_SIGHT:
        {
            sp->Effect[1] = 0;
        }break;
    case SPELL_HASH_HYPOTHERMIA:
        {
            sp->c_is_flags |= SPELL_FLAG_IS_FORCEDDEBUFF;
        }break;
    case SPELL_HASH_IMPROVED_COUNTERSPELL:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->EffectSpellClassMask[0][0] = 0x00004000;    // Proc on counterspell only
        }break;
    case SPELL_HASH_SHADOW_WEAVING:
        {
            sp->EffectApplyAuraName[0] = SPELL_AURA_PROC_TRIGGER_SPELL;
            sp->procFlags = PROC_ON_CAST_SPELL;
            sp->procChance = sp->EffectBasePoints[0] + 1;
        }break;
    case SPELL_HASH_SHADOW_TRANCE:
        {
            sp->AuraInterruptFlags = AURA_INTERRUPT_ON_CAST_SPELL;
        }break;
    case SPELL_HASH_ERADICATION:
        {
            sp->EffectTriggerSpell[0] = 54370;
            sp->procFlags = PROC_ON_SPELL_LAND;
        }break;
    case SPELL_HASH_INFECTED_WOUNDS:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case SPELL_HASH_POUNCE:
        {
            sp->always_apply = true;
        }break;
    case SPELL_HASH_OWLKIN_FRENZY:
        {
            sp->procFlags = PROC_ON_ANY_DAMAGE_VICTIM;
        }break;
    case SPELL_HASH_EARTH_AND_MOON:
        {
            sp->procFlags = PROC_ON_CAST_SPELL;
        }break;
    case SPELL_HASH_STARFALL:
        {
            if(sp->Effect[1] == SPELL_EFFECT_TRIGGER_SPELL )
            {//we can only attack one target with main star
                sp->MaxTargets = 1;
            }
        }break;
    case SPELL_HASH_SHRED:
        {
            sp->MechanicsType = MECHANIC_BLEEDING;
        }break;
    case SPELL_HASH_NURTURING_INSTINCT:
        {
            sp->Effect[1] = SPELL_EFFECT_APPLY_AURA;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;
    case SPELL_HASH_PRIMAL_TENACITY:
        {
            sp->DurationIndex = 21;
            sp->EffectBasePoints[1] = 0;
            sp->EffectApplyAuraName[1] = SPELL_AURA_DUMMY;
        }break;
    case SPELL_HASH_PROWL:
        {
            sp->EffectBasePoints[0] = 0;
        }break;
    }

    if( sp->EquippedItemClass == 2 && sp->EquippedItemSubClass & 262156 ) // 4 + 8 + 262144 ( becomes item classes 2, 3 and 18 which correspond to bow, gun and crossbow respectively)
        sp->is_ranged_spell = true;

    //////////////////////////////////////////////////////////////////
    //AREA AURA TARGETS - END
    //////////////////////////////////////////////////////////////////

    if( IsDamagingSpell( sp ) )
        sp->c_is_flags |= SPELL_FLAG_IS_DAMAGING;
    if( IsHealingSpell( sp ) )
        sp->c_is_flags |= SPELL_FLAG_IS_HEALING;
    if( IsTargetingStealthed( sp ) )
        sp->c_is_flags |= SPELL_FLAG_IS_TARGETINGSTEALTHED;
    if( IsFlyingSpell(sp) )
        sp->c_is_flags |= SPELL_FLAG_IS_FLYING;
    if( IsCastedOnFriends(sp) )
        sp->c_is_flags |= SPELL_FLAG_CASTED_ON_FRIENDS;
    if( IsCastedOnEnemies(sp) )
        sp->c_is_flags |= SPELL_FLAG_CASTED_ON_ENEMIES;
    if(sp->Flags3 & FLAGS3_CANT_CRIT) //I can haz hacky? :O
        sp->spell_can_crit = false;
}
