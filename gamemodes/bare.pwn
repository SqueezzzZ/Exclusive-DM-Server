#include <a_samp>
#undef MAX_PLAYERS
#define MAX_PLAYERS 5
#include <core>
#include <float>
#include <streamer>
#include <mxINI>
#include <a_mysql>
#include <filemanager>
#include <mxINI>

//#pragma dynamic 100000

#define mysql_empty(%1,%2) mysql_tquery(%1, %2, "", "")
#pragma tabsize 0

#define mysql_empty(%1,%2) mysql_tquery(%1, %2, "", "")

#define MAX_PROPERTY 501
#define MAX_FILE_NAME 64
#define MAX_3DTEXT 255
#define MAX_BASE 101 //Максимум штабов. Указывается на 1 больше
#define MAX_CLAN 501 //Максимум кланов. Указывается на 1 больше
#define MAX_GZONE 21 //+1 всего зон
new MaxClanID=0;

forward StopFreeze(playerid, Float: x, Float: y, Float: z);
forward UploadHouse(hd);
forward UploadBase(hd);
forward UploadZone(hd);
forward UploadClan(hd);
new connects;

enum pInfo
{
	HID,
	pOwner[MAX_PLAYER_NAME],
	pName[MAX_PLAYER_NAME],
	pPrice,
	Float:pPosEnterX,
	Float:pPosEnterY,
	Float:pPosEnterZ,
	Float:pPosEnterA,
	Float:pPosRespawnX,
	Float:pPosRespawnY,
	Float:pPosRespawnZ,
	Float:pPosRespawnA,
	pOpened,
	pBuyBlock,
}
new Property[MAX_PROPERTY][pInfo];
enum bInfo
{
	BID,
	bClan,
	bPrice,
	Float:bPosEnterX,
	Float:bPosEnterY,
	Float:bPosEnterZ,
	Float:bPosEnterA,
	Float:bPosRespawnX,
	Float:bPosRespawnY,
	Float:bPosRespawnZ,
	Float:bPosRespawnA,
}
new Base[MAX_BASE][bInfo];
enum GZInfo
{
	ZID,
	GZName[MAX_PLAYER_NAME],
	GZOwner,
	GZColor,
	GZLevel,
	Float:GMaxX,
	Float:GMinX,
	Float:GMaxY,
	Float:GMinY,
	GZClanTime,
	GZExp,
	GZCash,
	//
	ZoneAttacked,
	ClanAttacker,
}
new GangZones[MAX_GZONE][GZInfo];
enum cInfo
{
	CID,
	cLevel,
	cLider[MAX_PLAYER_NAME],
	cName[MAX_PLAYER_NAME],
	cMessage[125],
	cColor,
	cBase,
	cXP,
	cLastDay,
	cEnemyClan,
	cCWwin,
	ClanBank,
	ClanZones,
	cTag[20],
}
new Clan[MAX_CLAN][cInfo];
new CMember[MAX_CLAN][26][MAX_PLAYER_NAME];

enum Info
{
	SID,
	Model,
	Admin,
	Level,
	Exp,
	Spawn,
	SpawnStyle,
	Invisible,
	Time,
	Cash,
	Bank,
	Banned,
	Muted,
	Slot1, // Оружие
	Slot2,
	Slot3,
	Slot4,
	Slot5,
	Slot6,
	Slot7,
	Slot8,
	Slot9,
	Slot10,
	MyClan,
	Member,
	Leader,
	Home,
	Account,
	CarSlot1,
	CarSlot1Color1,
	CarSlot1Color2,
	CarSlot1PaintJob,
	CarSlot1Neon,
	CarSlot1Fire,
	CarSlot1Sir,
	CarSlot1Mig,
	CarSlot1Component0,
	CarSlot1Component1,
	CarSlot1Component2,
	CarSlot1Component3,
	CarSlot1Component4,
	CarSlot1Component5,
	CarSlot1Component6,
	CarSlot1Component7,
	CarSlot1Component8,
	CarSlot1Component9,
	CarSlot1Component10,
	CarSlot1Component11,
	CarSlot1Component12,
	CarSlot1Component13,
	CarSlot1NitroX,
	CarSlot2,
	CarSlot2Color1,
	CarSlot2Color2,
	CarSlot2PaintJob,
	CarSlot2Neon,
	CarSlot2Fire,
	CarSlot2Sir,
	CarSlot2Mig,
	CarSlot2Component0,
	CarSlot2Component1,
	CarSlot2Component2,
	CarSlot2Component3,
	CarSlot2Component4,
	CarSlot2Component5,
	CarSlot2Component6,
	CarSlot2Component7,
	CarSlot2Component8,
	CarSlot2Component9,
	CarSlot2Component10,
	CarSlot2Component11,
	CarSlot2Component12,
	CarSlot2Component13,
	CarSlot2NitroX,
	CarSlot3,
	CarSlot3Color1,
	CarSlot3Color2,
	Float: GameGold,
	Float: GameGoldTotal,
	GPremium,
	SkillHP,
	SkillRepair,
	ActiveSkillPerson,
	ActiveSkillCar1,
	ActiveSkillCar2,
	ActiveSkillHCar1,
	ActiveSkillHCar2,
	Prestige,
	PrestigeSkillN,
	PrestigeSkillY,
	PrestigeSkillH,
	Karma,
	KarmaTime,
	Float: PosX,
	Float: PosY,
	Float: PosZ,
	Float: PosA,
	ConPM,
	ConInviteClan,
	ConInvitePVP,
	ConMesPVP,
	ConMesEnterExit,
	ConSpeedo,
	LastHourExp,
	LastHourReferalExp,
	HelpTime,
	EventChangeTime,
	LeaveZM,
	ClanWarTime,
	CasinoBalance,
	GiveCashBalance,
	BuddhaTime,
	PrestigeColor,
	Medals,
	CompletedQuests,
	Float: GGFromMedals,
	Float: GGFromMedalsTotal,
	Float: GGFromMedalsLastDay,
	FindPack,
	ReadObnovlenie,
	Bonus,
	SlivBlock,
	RadarSwitch,
	Mrf1,
	Type,
	Tag,
	//Переменные, которые НЕ сохраняются в файл
	CarActive,
	//Всё, что связано синхронизацией здоровья, брони и нанесением урона
	Float: PHealth,
	Float: PArmour,
}
new Player[1][Info];
new PlayerPass[MAX_PLAYERS][30];//пароль игрока
new BannedBy[MAX_PLAYERS][25], BanReason[MAX_PLAYERS][41], MutedBy[MAX_PLAYERS][25];
new PlayerLimitXPDate[MAX_PLAYERS][80];
new RegisterDate[MAX_PLAYERS][16];
new RegisterIP[MAX_PLAYERS][16];
new ChatName[MAX_PLAYERS][80];
new Quest[MAX_PLAYERS][3], QuestScore[MAX_PLAYERS][3], QuestTime[MAX_PLAYERS][3];//квесты
new PlayerIP[MAX_PLAYERS][16];//IP игроков

main()
{
	print("\n----------------------------------");
	print("  DATABASE REWRITE SCRIPT\n");
	print("----------------------------------\n");
}
stock ResetProperty(houseid)
{
	Property[houseid][pOwner] = 0;
	Property[houseid][pName] = 0;
	Property[houseid][pPrice] = 1;
	Property[houseid][pPosEnterX] = 0.0;
	Property[houseid][pPosEnterY] = 0.0;
	Property[houseid][pPosEnterZ] = 0.0;
	Property[houseid][pPosEnterA] = 0.0;
	Property[houseid][pPosRespawnX] = 0.0;
	Property[houseid][pPosRespawnY] = 0.0;
	Property[houseid][pPosRespawnZ] = 0.0;
	Property[houseid][pPosRespawnA] = 0.0;
	Property[houseid][pOpened] = 0;
	Property[houseid][pBuyBlock] = 0;
}
public OnPlayerConnect(playerid)
{
	GameTextForPlayer(playerid,"~w~SA-MP: ~r~Bare Script",5000,5);
	return 1;
}

public OnPlayerCommandText(playerid, cmdtext[])
{
	new idx;
	new cmd[256];
	
	cmd = strtok(cmdtext, idx);

	if(strcmp(cmd, "/rhouse", true) == 0)
	{
	    new tmup = GetTickCount();
		new query_string[3000];
		
		for(new i=1; i < MAX_PROPERTY; i++)
		{
		    //if(strcmp(Property[i][pOwner], "Никто")) {strmid(Property[i][pOwner], "Null", 0, strlen("Null"), 6);}
		    
			format(query_string, sizeof(query_string), "INSERT INTO `houses` (`Owner`,`Name`,`Price`,`PosEnterX`,`PosEnterY`,`PosEnterZ`,`PosEnterA`,`PosRespawnX`,`PosRespawnY`,`PosRespawnZ`,`PosRespawnA`,`Opened`,`BuyBlock`)");
			format(query_string, sizeof(query_string), "%s VALUES ('%s','%s','%d','%f','%f','%f','%f','%f','%f','%f','%f','%d','%d')", query_string, Property[i][pOwner], Property[i][pName], Property[i][pPrice], Property[i][pPosEnterX],Property[i][pPosEnterY],Property[i][pPosEnterZ],Property[i][pPosEnterA],Property[i][pPosRespawnX], Property[i][pPosRespawnY],Property[i][pPosRespawnZ],Property[i][pPosRespawnA],Property[i][pOpened],Property[i][pBuyBlock]);
    		mysql_function_query(connects, query_string, false, "UploadHouse", "d", i);
		}
		
		new string[140];
		format(string,sizeof(string),"Дома перезаписаны за{ffffff} %d", GetTickCount()-tmup);
		SendClientMessage(playerid,0xFF0000FF,string);
    	return 1;
	}
	
	if(strcmp(cmd, "/rbase", true) == 0)
	{
	    new tmup = GetTickCount();
		new query_string[2000];

		for(new i=1; i < MAX_BASE; i++)
		{
			format(query_string, sizeof(query_string), "INSERT INTO `bases` (`Clan`,`Price`,`PosEnterX`,`PosEnterY`,`PosEnterZ`,`PosEnterA`,`PosRespawnX`,`PosRespawnY`,`PosRespawnZ`,`PosRespawnA`)");
			format(query_string, sizeof(query_string), "%s VALUES ('%d','%d','%f','%f','%f','%f','%f','%f','%f','%f')", query_string, Base[i][bClan], Base[i][bPrice], Base[i][bPosEnterX], Base[i][bPosEnterY], Base[i][bPosEnterZ], Base[i][bPosEnterA],Base[i][bPosRespawnX],Base[i][bPosRespawnY],Base[i][bPosRespawnZ],Base[i][bPosRespawnA]);
    		mysql_function_query(connects, query_string, false, "UploadBase", "d", i);
		}

		new string[140];
		format(string,sizeof(string),"Базы перезаписаны за{ffffff} %d", GetTickCount()-tmup);
		SendClientMessage(playerid,0xFF0000FF,string);
    	return 1;
	}

	if(strcmp(cmd, "/rzone", true) == 0)
	{
	    new tmup = GetTickCount();
		new query_string[2000];

		for(new i=1; i < MAX_GZONE; i++)
		{
			format(query_string, sizeof(query_string), "INSERT INTO `zones` (`ZName`,`ZOwner`,`ZColor`,`ZLevel`,`MinX`,`MaxX`,`MinY`,`MaxY`,`ZCTime`,`ZExp`,`ZCash`)");
			format(query_string, sizeof(query_string), "%s VALUES ('%s','%d','%d','%d','%f','%f','%f','%f','%d','%d','%d')", query_string, GangZones[i][GZName],GangZones[i][GZOwner],GangZones[i][GZColor],GangZones[i][GZLevel],GangZones[i][GMinX],GangZones[i][GMaxX],GangZones[i][GMinY],GangZones[i][GMaxY],GangZones[i][GZClanTime],GangZones[i][GZExp],GangZones[i][GZCash]);

			mysql_function_query(connects, query_string, false, "UploadZone", "d", i);
		}

		new string[140];
		format(string,sizeof(string),"Зоны перезаписаны за{ffffff} %d", GetTickCount()-tmup);
		SendClientMessage(playerid,0xFF0000FF,string);
    	return 1;
	}
	
	if(strcmp(cmd, "/rclan", true) == 0)
	{
	    new tmup = GetTickCount();
		new query_string[4000];

		for(new i=1; i < MaxClanID; i++)
		{
			if(Clan[i][cLevel] == 0) continue;
			new str[140];
			mysql_real_escape_string(Clan[i][cMessage],str);
			format(query_string, sizeof(query_string), "`m1`,`m2`,`m3`,`m4`,`m5`,`m6`,`m7`,`m8`,`m9`,`m10`,`m11`,`m12`,`m13`,`m14`,`m15`,`m16`,`m17`,`m18`,`m19`,`m20`");
			format(query_string, sizeof(query_string), "INSERT INTO `clans` (`CID`,`Level`,`Lider`,`Name`,`Message`,`Color`,`Base`,`XP`,`LastDay`,`EClan`,`CWwin`,`CBank`,`CZones`,`CTag`,%s)", query_string);
			format(query_string, sizeof(query_string), "%s VALUES ('%d','%d','%s','%s','%s','%d','%d','%d','%d','%d','%d','%d','%d','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s');", query_string, i, Clan[i][cLevel],Clan[i][cLider],Clan[i][cName],str,Clan[i][cColor],Clan[i][cBase],Clan[i][cXP],Clan[i][cLastDay],Clan[i][cEnemyClan],Clan[i][cCWwin],Clan[i][ClanBank],Clan[i][ClanZones],
			Clan[i][cTag], CMember[i][1], CMember[i][2], CMember[i][3], CMember[i][4], CMember[i][5],CMember[i][6],CMember[i][7],CMember[i][8],CMember[i][9],CMember[i][10],CMember[i][11],CMember[i][12],CMember[i][13],CMember[i][14],CMember[i][15],CMember[i][16],CMember[i][17],CMember[i][18],CMember[i][19],CMember[i][20]);
            //printf(query_string);
			mysql_empty(connects, query_string);
    		
		}

		new string[140];
		format(string,sizeof(string),"Кланы перезаписаны за{ffffff} %d. ", GetTickCount()-tmup);
		SendClientMessage(playerid,0xFF0000FF,string);
    	return 1;
	}
	
	if(strcmp(cmd, "/start", true) == 0)
	{
	    if(playerid != 0) return SendClientMessage(playerid,0xFF0000FF,"Ты шо, ты шо а... Одному ток можно!");
	    new tmup = GetTickCount();
		new /*query_string[4000],*/string[140];
		new Count,CCount,BCount;
		
		SendClientMessage(playerid,0xFF0000FF,"Открываем директорию...");
		new dir:dHandle = dir_open("./scriptfiles/accounts/");
		format(string,sizeof(string),"Директория открыта за{ffffff} %d", GetTickCount()-tmup);
		SendClientMessage(playerid,0xFF0000FF,string);
		tmup = GetTickCount();
		new item[40],type;
        SendClientMessage(playerid,0xFF0000FF,"Перезапись аккаунтов началась!");
		while(dir_list(dHandle, item, type))
		{
			if (type == FM_FILE)
			{
				ResetPlayer(playerid);
			    new filename[MAX_FILE_NAME], file;
				format(filename, sizeof(filename), "accounts/%s", item);
				file = ini_openFile(filename);
				//запишем данные в массив
				ini_getString(file,"Password", PlayerPass[playerid]);
				ini_getInteger(file, "Model", Player[playerid][Model]);
				ini_getInteger(file, "Admin", Player[playerid][Admin]);
				ini_getInteger(file, "Level", Player[playerid][Level]);
				ini_getInteger(file, "Exp", Player[playerid][Exp]);
				ini_getInteger(file, "Spawn", Player[playerid][Spawn]);
				ini_getInteger(file, "SpawnStyle", Player[playerid][SpawnStyle]);
				ini_getInteger(file, "Invisible", Player[playerid][Invisible]);
				ini_getInteger(file, "Time", Player[playerid][Time]);
				ini_getInteger(file, "Cash", Player[playerid][Cash]);
				ini_getInteger(file, "Bank", Player[playerid][Bank]);
				ini_getInteger(file, "Banned", Player[playerid][Banned]);
				ini_getString(file,"BannedBy", BannedBy[playerid]);
				ini_getString(file,"BanReason", BanReason[playerid]);
				ini_getInteger(file, "Muted", Player[playerid][Muted]);
				ini_getString(file,"MutedBy", MutedBy[playerid]);
				ini_getInteger(file, "Slot1", Player[playerid][Slot1]);
				ini_getInteger(file, "Slot2", Player[playerid][Slot2]);
				ini_getInteger(file, "Slot3", Player[playerid][Slot3]);
				ini_getInteger(file, "Slot4", Player[playerid][Slot4]);
				ini_getInteger(file, "Slot5", Player[playerid][Slot5]);
				ini_getInteger(file, "Slot6", Player[playerid][Slot6]);
				ini_getInteger(file, "Slot7", Player[playerid][Slot7]);
				ini_getInteger(file, "Slot8", Player[playerid][Slot8]);
				ini_getInteger(file, "Slot9", Player[playerid][Slot9]);
				ini_getInteger(file, "Slot10", Player[playerid][Slot10]);
				ini_getInteger(file, "MyClan", Player[playerid][MyClan]);
				ini_getInteger(file, "Member", Player[playerid][Member]);
				ini_getInteger(file, "Leader", Player[playerid][Leader]);
				ini_getInteger(file, "Home", Player[playerid][Home]);
				ini_getInteger(file, "Account", Player[playerid][Account]);
				ini_getInteger(file, "CarSlot1", Player[playerid][CarSlot1]);
				ini_getInteger(file, "CarSlot1Color1", Player[playerid][CarSlot1Color1]);
				ini_getInteger(file, "CarSlot1Color2", Player[playerid][CarSlot1Color2]);
				ini_getInteger(file, "CarSlot1PaintJob", Player[playerid][CarSlot1PaintJob]);
				ini_getInteger(file, "CarSlot1Neon", Player[playerid][CarSlot1Neon]);
				ini_getInteger(file, "CarSlot1Fire", Player[playerid][CarSlot1Fire]);
				ini_getInteger(file, "CS1Sir", Player[playerid][CarSlot1Sir]);
				ini_getInteger(file, "CS1Mig", Player[playerid][CarSlot1Mig]);
				ini_getInteger(file, "CarSlot1Component0", Player[playerid][CarSlot1Component0]);
				ini_getInteger(file, "CarSlot1Component1", Player[playerid][CarSlot1Component1]);
				ini_getInteger(file, "CarSlot1Component2", Player[playerid][CarSlot1Component2]);
				ini_getInteger(file, "CarSlot1Component3", Player[playerid][CarSlot1Component3]);
				ini_getInteger(file, "CarSlot1Component4", Player[playerid][CarSlot1Component4]);
				ini_getInteger(file, "CarSlot1Component5", Player[playerid][CarSlot1Component5]);
				ini_getInteger(file, "CarSlot1Component6", Player[playerid][CarSlot1Component6]);
				ini_getInteger(file, "CarSlot1Component7", Player[playerid][CarSlot1Component7]);
				ini_getInteger(file, "CarSlot1Component8", Player[playerid][CarSlot1Component8]);
				ini_getInteger(file, "CarSlot1Component9", Player[playerid][CarSlot1Component9]);
				ini_getInteger(file, "CarSlot1Component10", Player[playerid][CarSlot1Component10]);
				ini_getInteger(file, "CarSlot1Component11", Player[playerid][CarSlot1Component11]);
				ini_getInteger(file, "CarSlot1Component12", Player[playerid][CarSlot1Component12]);
				ini_getInteger(file, "CarSlot1Component13", Player[playerid][CarSlot1Component13]);
				ini_getInteger(file, "CarSlot1NitroX", Player[playerid][CarSlot1NitroX]);
				ini_getInteger(file, "CarSlot2", Player[playerid][CarSlot2]);
				ini_getInteger(file, "CarSlot2Color1", Player[playerid][CarSlot2Color1]);
				ini_getInteger(file, "CarSlot2Color2", Player[playerid][CarSlot2Color2]);
				ini_getInteger(file, "CarSlot2PaintJob", Player[playerid][CarSlot2PaintJob]);
				ini_getInteger(file, "CarSlot2Neon", Player[playerid][CarSlot2Neon]);
				ini_getInteger(file, "CarSlot2Fire", Player[playerid][CarSlot2Fire]);
				ini_getInteger(file, "CS2Sir", Player[playerid][CarSlot2Sir]);
				ini_getInteger(file, "CS2Mig", Player[playerid][CarSlot2Mig]);
				ini_getInteger(file, "CarSlot2Component0", Player[playerid][CarSlot2Component0]);
				ini_getInteger(file, "CarSlot2Component1", Player[playerid][CarSlot2Component1]);
				ini_getInteger(file, "CarSlot2Component2", Player[playerid][CarSlot2Component2]);
				ini_getInteger(file, "CarSlot2Component3", Player[playerid][CarSlot2Component3]);
				ini_getInteger(file, "CarSlot2Component4", Player[playerid][CarSlot2Component4]);
				ini_getInteger(file, "CarSlot2Component5", Player[playerid][CarSlot2Component5]);
				ini_getInteger(file, "CarSlot2Component6", Player[playerid][CarSlot2Component6]);
				ini_getInteger(file, "CarSlot2Component7", Player[playerid][CarSlot2Component7]);
				ini_getInteger(file, "CarSlot2Component8", Player[playerid][CarSlot2Component8]);
				ini_getInteger(file, "CarSlot2Component9", Player[playerid][CarSlot2Component9]);
				ini_getInteger(file, "CarSlot2Component10", Player[playerid][CarSlot2Component10]);
				ini_getInteger(file, "CarSlot2Component11", Player[playerid][CarSlot2Component11]);
				ini_getInteger(file, "CarSlot2Component12", Player[playerid][CarSlot2Component12]);
				ini_getInteger(file, "CarSlot2Component13", Player[playerid][CarSlot2Component13]);
				ini_getInteger(file, "CarSlot2NitroX", Player[playerid][CarSlot2NitroX]);
				ini_getInteger(file, "CarSlot3", Player[playerid][CarSlot3]);
				ini_getInteger(file, "CarSlot3Color1", Player[playerid][CarSlot3Color1]);
				ini_getInteger(file, "CarSlot3Color2", Player[playerid][CarSlot3Color2]);
				ini_getFloat(file, "GameGold", Player[playerid][GameGold]);
				ini_getFloat(file, "GameGoldTotal", Player[playerid][GameGoldTotal]);
				ini_getInteger(file, "GPremium", Player[playerid][GPremium]);
				ini_getInteger(file, "SkillHP", Player[playerid][SkillHP]);
				ini_getInteger(file, "SkillRepair", Player[playerid][SkillRepair]);
				ini_getInteger(file, "ActiveSkillPerson", Player[playerid][ActiveSkillPerson]);
				ini_getInteger(file, "ActiveSkillCar1", Player[playerid][ActiveSkillCar1]);
    			ini_getInteger(file, "ActiveSkillCar2", Player[playerid][ActiveSkillCar2]);
    			ini_getInteger(file, "ActiveSkillHCar1", Player[playerid][ActiveSkillHCar1]);
    			ini_getInteger(file, "ActiveSkillHCar2", Player[playerid][ActiveSkillHCar2]);
				ini_getInteger(file, "Prestige", Player[playerid][Prestige]);
				ini_getInteger(file, "Karma", Player[playerid][Karma]);
				ini_getInteger(file, "KarmaTime", Player[playerid][KarmaTime]);
				ini_getFloat(file, "PosX", Player[playerid][PosX]);
				ini_getFloat(file, "PosY", Player[playerid][PosY]);
				ini_getFloat(file, "PosZ", Player[playerid][PosZ]);
				ini_getFloat(file, "PosA", Player[playerid][PosA]);
				ini_getInteger(file, "ConPM", Player[playerid][ConPM]);
				ini_getInteger(file, "ConInviteClan", Player[playerid][ConInviteClan]);
    			ini_getInteger(file, "ConInvitePVP", Player[playerid][ConInvitePVP]);
    			ini_getInteger(file, "ConMesPVP", Player[playerid][ConMesPVP]);
    			ini_getInteger(file, "ConMesEnterExit", Player[playerid][ConMesEnterExit]);
    			ini_getInteger(file, "ConSpeedo", Player[playerid][ConSpeedo]);
    			ini_getInteger(file, "LastHourExp", Player[playerid][LastHourExp]);
    			ini_getInteger(file, "LastHourReferalExp", Player[playerid][LastHourReferalExp]);
    			ini_getString(file,"PlayerLimitXPDate", PlayerLimitXPDate[playerid]);
    			ini_setString(file,"LastIP", PlayerIP[playerid]);
    			ini_getInteger(file, "HelpTime", Player[playerid][HelpTime]);
    			ini_getInteger(file, "EventChangeTime", Player[playerid][EventChangeTime]);
    			ini_getString(file,"RegisterDate", RegisterDate[playerid]);
    			ini_getString(file,"RegisterIP", RegisterIP[playerid]);
    			ini_getInteger(file, "LeaveZM", Player[playerid][LeaveZM]);
    			ini_getInteger(file, "ClanWarTime", Player[playerid][ClanWarTime]);
    			ini_getInteger(file, "CasinoBalance", Player[playerid][CasinoBalance]);
    			ini_getInteger(file, "GiveCashBalance", Player[playerid][GiveCashBalance]);
    			ini_getString(file,"ChatName", ChatName[playerid]);
    			ini_getInteger(file, "BuddhaTime", Player[playerid][BuddhaTime]);
    			ini_getInteger(file, "PrestigeColor", Player[playerid][PrestigeColor]);
    			ini_getInteger(file, "Quest1", Quest[playerid][0]);
    			ini_getInteger(file, "Quest1Score", QuestScore[playerid][0]);
    			ini_getInteger(file, "Quest1Time", QuestTime[playerid][0]);
    			ini_getInteger(file, "Quest2", Quest[playerid][1]);
    			ini_getInteger(file, "Quest2Score", QuestScore[playerid][1]);
    			ini_getInteger(file, "Quest2Time", QuestTime[playerid][1]);
    			ini_getInteger(file, "Quest3", Quest[playerid][2]);
    			ini_getInteger(file, "Quest3Score", QuestScore[playerid][2]);
    			ini_getInteger(file, "Quest3Time", QuestTime[playerid][2]);
    			ini_getInteger(file, "Medals", Player[playerid][Medals]);
    			ini_getInteger(file, "CompletedQuests", Player[playerid][CompletedQuests]);
    			ini_getFloat(file, "GGFromMedals", Player[playerid][GGFromMedals]);
    			ini_getFloat(file, "GGFromMedalsTotal", Player[playerid][GGFromMedalsTotal]);
    			ini_getFloat(file, "GGFromMedalsLastDay", Player[playerid][GGFromMedalsLastDay]);
    			ini_getInteger(file, "FindPack", Player[playerid][FindPack]);
    			ini_getInteger(file, "ReadObnov", Player[playerid][ReadObnovlenie]);
    			ini_getInteger(file, "Bonus", Player[playerid][Bonus]);
    			ini_getInteger(file, "SlivBlock", Player[playerid][SlivBlock]);
    			ini_getInteger(file, "Radar", Player[playerid][RadarSwitch]);
    			ini_getInteger(file, "Mrf2", Player[playerid][Mrf1]);
    			ini_getInteger(file, "Types", Player[playerid][Type]);
    			ini_getInteger(file, "Tag", Player[playerid][Tag]);
				ini_closeFile(file);
				
				if(Player[playerid][Level]<3 && Player[playerid][Cash] < 1000 && Player[playerid][Bank] < 1000 && Player[playerid][Prestige] == 0 && Player[playerid][GPremium] == 0)
				{
				    CCount++;
				}
				else if(strfind(PlayerPass[playerid], "`", true) != -1 || strfind(PlayerPass[playerid], "'", true) != -1)
				{
				    BCount++;
                    WriteLog("Broken", item);
				}
				else
				{
				    strdel(item, strlen(item)-4, strlen(item));
					//запишем данные из массива в бд
					new query[4000];
					strcat(query, "INSERT INTO `accounts`(");
					strcat(query, "`PName`,`Password`,`Model`,`Admin`,`Level`,`Exp`,`Spawn`,`SpawnStyle`,`Invisible`,`Time`,`Cash`,");
					strcat(query,"`Bank`,`Banned`,`BannedBy`,`BanReason`,`Muted`,`MutedBy`,`Slot1`,`Slot2`,`Slot3`,`Slot4`,`Slot5`,`Slot6`,");
					strcat(query,"`Slot7`,`Slot8`,`Slot9`,`Slot10`,`MyClan`,`Member`,`Leader`,`Home`,`Account`,`CarSlot1`,`CarSlot1Color1`,`CarSlot1Color2`,");
					strcat(query,"`CS1PJ`,`CS1Neon`,`CS1Fire`,`CS1Sir`,`CS1Mig`,`CS1C0`,`CS1C1`,`CS1C2`,`CS1C3`,`CS1C4`,`CS1C5`,`CS1C6`,`CS1C7`,");
					strcat(query,"`CS1C8`,`CS1C9`,`CS1C10`,`CS1C11`,`CS1C12`,`CS1C13`,`CS1NitroX`,`CarSlot2`,`CarSlot2Color1`,`CarSlot2Color2`,");
					strcat(query,"`CS2PJ`,`CS2Neon`,`CS2Fire`,`CS2Sir`,`CS2Mig`,`CS2C0`,`CS2C1`,`CS2C2`,`CS2C3`,`CS2C4`,`CS2C5`,`CS2C6`,`CS2C7`,`CS2C8`,`CS2C9`,");
					strcat(query,"`CS2C10`,`CS2C11`,`CS2C12`,`CS2C13`,`CS2NitroX`,`CarSlot3`,`CarSlot3Color1`,`CarSlot3Color2`,`GameGold`,`GameGoldTotal`,`GPremium`,");
					strcat(query,"`SkillHP`,`SkillRepair`,`ActiveSkillPerson`,`ActiveSkillCar1`,`ActiveSkillCar2`,`ActiveSkillHCar1`,`ActiveSkillHCar2`,`Prestige`,");
					strcat(query,"`Karma`,`KarmaTime`,`PosX`,`PosY`,`PosZ`,`PosA`,`ConPM`,`ConInviteClan`,`ConInvitePVP`,`ConMesPVP`,`ConMesEnterExit`,");
    				strcat(query,"`ConSpeedo`,`LastHourExp`,`LastHourReferalExp`,`PlayerLimitXPDate`,`HelpTime`,`EventChangeTime`,`RegisterDate`,`RegisterIP`,");
    				strcat(query,"`LeaveZM`,`ClanWarTime`,`CasinoBalance`,`GiveCashBalance`,`ChatName`,`BuddhaTime`,`PrestigeColor`,`Quest1`,`Quest1Score`,`Quest1Time`,");
    				strcat(query,"`Quest2`,`Quest2Score`,`Quest2Time`,`Quest3`,`Quest3Score`,`Quest3Time`,`Medals`,`CompletedQuests`,`GGFromMedals`,`GGFromMedalsTotal`,");
    				strcat(query,"`GGFromMedalsLastDay`,`FindPack`,`ReadObnov`,`Bonus`,`SlivBlock`,`Radar`,`Mrf2`,`Types`,`Tag`,`LastIP`)");
    			
    			    format(query, sizeof(query),"%s VALUES ('%s'", query, item);
    			    
			    	format(query, sizeof(query),"%s,'%s'", query,PlayerPass[playerid]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Model]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Admin]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Level]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Exp]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Spawn]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][SpawnStyle]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Invisible]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Time]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Cash]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Bank]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Banned]);
					format(query, sizeof(query),"%s,'%s'", query,BannedBy[playerid]);
					format(query, sizeof(query),"%s,'%s'", query,BanReason[playerid]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Muted]);
					format(query, sizeof(query),"%s,'%s'", query,MutedBy[playerid]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot1]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot2]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot3]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot4]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot5]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot6]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot7]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot8]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot9]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Slot10]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][MyClan]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Member]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Leader]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Home]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Account]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Color1]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Color2]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1PaintJob]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Neon]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Fire]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Sir]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Mig]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component0]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component1]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component2]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component3]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component4]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component5]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component6]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component7]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component8]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component9]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component10]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component11]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component12]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1Component13]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot1NitroX]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Color1]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Color2]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2PaintJob]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Neon]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Fire]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Sir]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Mig]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component0]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component1]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component2]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component3]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component4]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component5]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component6]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component7]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component8]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component9]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component10]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component11]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component12]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2Component13]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot2NitroX]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot3]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot3Color1]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CarSlot3Color2]);
					format(query, sizeof(query),"%s,'%f'", query,Player[playerid][GameGold]);
					format(query, sizeof(query),"%s,'%f'", query,Player[playerid][GameGoldTotal]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][GPremium]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][SkillHP]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][SkillRepair]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ActiveSkillPerson]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ActiveSkillCar1]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ActiveSkillCar2]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ActiveSkillHCar1]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ActiveSkillHCar2]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Prestige]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Karma]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][KarmaTime]);
					format(query, sizeof(query),"%s,'%f'", query,Player[playerid][PosX]);
					format(query, sizeof(query),"%s,'%f'", query,Player[playerid][PosY]);
					format(query, sizeof(query),"%s,'%f'", query,Player[playerid][PosZ]);
					format(query, sizeof(query),"%s,'%f'", query,Player[playerid][PosA]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ConPM]);
					format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ConInviteClan]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ConInvitePVP]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ConMesPVP]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ConMesEnterExit]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ConSpeedo]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][LastHourExp]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][LastHourReferalExp]);
    				format(query, sizeof(query),"%s,'%s'", query,PlayerLimitXPDate[playerid]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][HelpTime]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][EventChangeTime]);
    				format(query, sizeof(query),"%s,'%s'", query,RegisterDate[playerid]);
    				format(query, sizeof(query),"%s,'%s'", query,RegisterIP[playerid]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][LeaveZM]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ClanWarTime]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CasinoBalance]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][GiveCashBalance]);
    				format(query, sizeof(query),"%s,'%s'", query,ChatName[playerid]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][BuddhaTime]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][PrestigeColor]);
    				format(query, sizeof(query),"%s,'%d'", query,Quest[playerid][0]);
    				format(query, sizeof(query),"%s,'%d'", query,QuestScore[playerid][0]);
    				format(query, sizeof(query),"%s,'%d'", query,QuestTime[playerid][0]);
    				format(query, sizeof(query),"%s,'%d'", query,Quest[playerid][1]);
    				format(query, sizeof(query),"%s,'%d'", query,QuestScore[playerid][1]);
    				format(query, sizeof(query),"%s,'%d'", query,QuestTime[playerid][1]);
    				format(query, sizeof(query),"%s,'%d'", query,Quest[playerid][2]);
    				format(query, sizeof(query),"%s,'%d'", query,QuestScore[playerid][2]);
    				format(query, sizeof(query),"%s,'%d'", query,QuestTime[playerid][2]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Medals]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][CompletedQuests]);
    				format(query, sizeof(query),"%s,'%f'", query,Player[playerid][GGFromMedals]);
    				format(query, sizeof(query),"%s,'%f'", query,Player[playerid][GGFromMedalsTotal]);
    				format(query, sizeof(query),"%s,'%f'", query,Player[playerid][GGFromMedalsLastDay]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][FindPack]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][ReadObnovlenie]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Bonus]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][SlivBlock]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][RadarSwitch]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Mrf1]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Type]);
    				format(query, sizeof(query),"%s,'%d'", query,Player[playerid][Tag]);
    				format(query, sizeof(query),"%s,'%s');",query,PlayerIP[playerid]);
    				
    				//printf(query);

                    mysql_format(connects, query, sizeof(query), query);
					mysql_empty(connects, query);
				}
			    Count++;
			}
		}
		dir_close(dHandle);
		
		printf("Всего: %d, пусто %d",Count, CCount);
		
		format(string,sizeof(string),"Игроки перезаписаны за %d мс. Всего: %d . Нормальных: %d. Запрещенных: %d", GetTickCount()-tmup, Count,Count-CCount,BCount);
		SendClientMessage(playerid,0xFF0000FF,string);
    	return 1;
	}

	return 0;
}

//временное
public UploadHouse(hd) Property[hd][HID] = cache_insert_id(connects);
public UploadBase(hd) Base[hd][BID] = cache_insert_id(connects);
public UploadZone(hd) GangZones[hd][ZID] = cache_insert_id(connects);
public UploadClan(hd) Clan[hd][CID] = cache_insert_id(connects);

public OnPlayerSpawn(playerid)
{
	SetPlayerInterior(playerid,0);
	TogglePlayerClock(playerid,0);
	return 1;
}

public OnPlayerDeath(playerid, killerid, reason)
{
   	return 1;
}

SetupPlayerForClassSelection(playerid)
{
 	SetPlayerInterior(playerid,14);
	SetPlayerPos(playerid,258.4893,-41.4008,1002.0234);
	SetPlayerFacingAngle(playerid, 270.0);
	SetPlayerCameraPos(playerid,256.0815,-43.0475,1004.0234);
	SetPlayerCameraLookAt(playerid,258.4893,-41.4008,1002.0234);
}

public OnPlayerRequestClass(playerid, classid)
{
	SetupPlayerForClassSelection(playerid);
	return 1;
}

public OnGameModeInit()
{
    ///------------MySQL connecton---------------
    connects = mysql_connect("triniti.ru-hoster.com", "exrolf2n", "exrolf2n", "4fFe72gHq22");
    //connects = mysql_connect("127.0.0.1", "root", "exdm", "");
	mysql_empty(connects, "SET CHARACTER SET cp1251");
	mysql_log(LOG_ERROR | LOG_WARNING, LOG_TYPE_TEXT);
	if(!mysql_errno()) printf("Подключение к базе успешно");
	else return printf("Подключиться к базе не удалось");
	///------------MySQL connecton---------------
	
	SendRconCommand("password kilowatt");
    SendRconCommand("hostname ИДУТ ТЕХНИЧЕСКИЕ РАБОТЫ! ОЖИДАЙТЕ...");
	SetGameModeText("Тех. раб.");
	ShowPlayerMarkers(1);
	ShowNameTags(1);

    LoadAllPropertyINI();
    LoadAllBaseINI();
    LoadGangZonesINI();
    LoadAllClansINI();

	AddPlayerClass(265,1958.3783,1343.1572,15.3746,270.1425,0,0,0,0,-1,-1);
	return 1;
}

strtok(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}

	new offset = index;
	new result[20];
	while ((index < length) && (string[index] > ' ') && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

stock SetPlayerFreezePos(playerid, time, interior, Float: x, Float: y, Float: z, Float: a)
{
    SetPlayerInterior(playerid,interior);
    SetPlayerPos(playerid,x,y,z);
	SetPlayerFacingAngle(playerid, a);
	TogglePlayerControllable(playerid,0);
	SetTimerEx("StopFreeze",time*1000,false,"ifff",playerid,x,y,z);
}
public StopFreeze(playerid, Float: x, Float: y, Float: z)
{
    SetPlayerPos(playerid,x,y,z);
    TogglePlayerControllable(playerid,1);
}

stock LoadAllPropertyINI()
{
	for(new i = 1; i < MAX_PROPERTY; i++)
	{
		new filename[MAX_FILE_NAME], file;
		format(filename, sizeof(filename), "PlayerHouses/%i.ini", i);
		if(!fexist(filename)) continue;
		ResetProperty(i);//Чтобы можно было с новыми обновами добавлять новые переменные без вайпа домов.
		file = ini_openFile(filename);
		ini_getString(file, "Owner", Property[i][pOwner], MAX_PLAYER_NAME);
		ini_getString(file, "Name", Property[i][pName], 32);
		ini_getInteger(file, "Price", Property[i][pPrice]);
		ini_getFloat(file, "PosEnterX", Property[i][pPosEnterX]);
		ini_getFloat(file, "PosEnterY", Property[i][pPosEnterY]);
		ini_getFloat(file, "PosEnterZ", Property[i][pPosEnterZ]);
		ini_getFloat(file, "PosEnterA", Property[i][pPosEnterA]);
		ini_getFloat(file, "PosRespawnX", Property[i][pPosRespawnX]);
		ini_getFloat(file, "PosRespawnY", Property[i][pPosRespawnY]);
		ini_getFloat(file, "PosRespawnZ", Property[i][pPosRespawnZ]);
		ini_getFloat(file, "PosRespawnA", Property[i][pPosRespawnA]);
		ini_getInteger(file, "Opened", Property[i][pOpened]);
		ini_getInteger(file, "BuyBlock", Property[i][pBuyBlock]);
		ini_closeFile(file);
	}
}

stock LoadAllBaseINI()
{
	for(new i = 1; i < MAX_BASE; i++)
	{
		new filename[MAX_FILE_NAME], file;
		format(filename, sizeof(filename), "Base/%i.ini", i);
		if(!fexist(filename)) continue;
		file = ini_openFile(filename);
		ini_getInteger(file, "Clan", Base[i][bClan]);
		ini_getInteger(file, "Price", Base[i][bPrice]);
		ini_getFloat(file, "PosEnterX", Base[i][bPosEnterX]);
		ini_getFloat(file, "PosEnterY", Base[i][bPosEnterY]);
		ini_getFloat(file, "PosEnterZ", Base[i][bPosEnterZ]);
		ini_getFloat(file, "PosEnterA", Base[i][bPosEnterA]);
		ini_getFloat(file, "PosRespawnX", Base[i][bPosRespawnX]);
		ini_getFloat(file, "PosRespawnY", Base[i][bPosRespawnY]);
		ini_getFloat(file, "PosRespawnZ", Base[i][bPosRespawnZ]);
		ini_getFloat(file, "PosRespawnA", Base[i][bPosRespawnA]);
		ini_closeFile(file);
		}
}

stock LoadGangZonesINI()
{
	for(new i = 1; i < MAX_GZONE; i++)
	{
		new filename[MAX_FILE_NAME], file;
		format(filename, sizeof(filename), "GangZones/%i.ini", i);
		if(!fexist(filename)) continue;
		file = ini_openFile(filename);
		ini_getString(file, "ZName", GangZones[i][GZName], 32);
		ini_getInteger(file, "ZOwner", GangZones[i][GZOwner]);
		ini_getInteger(file, "ZColor", GangZones[i][GZColor]);
		ini_getInteger(file, "ZLevel", GangZones[i][GZLevel]);
		ini_getFloat(file, "MinX", GangZones[i][GMinX]);
		ini_getFloat(file, "MaxX", GangZones[i][GMaxX]);
		ini_getFloat(file, "MinY", GangZones[i][GMinY]);
		ini_getFloat(file, "MaxY", GangZones[i][GMaxY]);
        ini_getInteger(file, "ZCTime", GangZones[i][GZClanTime]);
        ini_getInteger(file, "ZExp", GangZones[i][GZExp]);
        ini_getInteger(file, "ZCash", GangZones[i][GZCash]);
		ini_closeFile(file);
	}
}

stock LoadAllClansINI()
{
    new filename[MAX_FILE_NAME], file, LastClan = 0;
	for(new i = 1; i < MAX_CLAN; i++)
	{
		format(filename, sizeof(filename), "Clans/%d.ini", i); LastClan++;
		if(!fexist(filename)) {Clan[i][cLevel] = 0; continue;} //несуществующий клан
		else
		{//клан существует
		    file = ini_openFile(filename);
		    ini_getInteger(file, "Level", Clan[i][cLevel]);
			ini_getString(file, "Lider", Clan[i][cLider], MAX_PLAYER_NAME);
			ini_getString(file, "Name", Clan[i][cName], MAX_PLAYER_NAME);
			ini_getString(file, "Message", Clan[i][cMessage], 125);
			ini_getInteger(file, "Color", Clan[i][cColor]);
			ini_getInteger(file, "Base", Clan[i][cBase]);
			ini_getInteger(file, "XP", Clan[i][cXP]);
			ini_getInteger(file, "LastDay", Clan[i][cLastDay]);
			ini_getInteger(file, "EnemyClan", Clan[i][cEnemyClan]);
			ini_getInteger(file, "CWwin", Clan[i][cCWwin]);

			for(new memb=1; memb<21; memb++)
			{
				new str[16];
				format(str, sizeof(str), "Member%d", memb);
				ini_getString(file, str, CMember[i][memb], MAX_PLAYER_NAME);
				if(!strcmp(CMember[i][memb], "Пусто", true)) strmid(CMember[i][memb], "No", 0, strlen("No"), 20);
			}

			ini_getInteger(file, "ClanBank", Clan[i][ClanBank]);
			ini_getInteger(file, "ClanZones", Clan[i][ClanZones]);
			ini_getString(file, "CTag", Clan[i][cTag], 20);
			//ini_getInteger(file, "Slots", Clan[i][cSlots]);
			//if(Clan[i][cSlots] < 20) Clan[i][cSlots] = 20;
			if(strlen(Clan[i][cTag]) == 0) {strmid(Clan[i][cTag], "Пусто", 0, strlen("Пусто"), 6);}
		    ini_closeFile(file);
		    MaxClanID = i;
		}//клан существует
	}

}
/*
			format(query_string, sizeof(query_string), "`Mem1`,`Mem2`,`Mem3`,`Mem4`,`Mem5`,`Mem6`,`Mem7`,`Mem8`,`Mem9`,`Mem10`,`Mem11`,`Mem12`,`Mem13`,`Mem14`,`Mem15`,`Mem16`,`Mem17`,`Mem18`,`Mem19`,`Mem20`");
			format(query_string, sizeof(query_string), "INSERT INTO `clans` (`Level`,`Lider`,`Name`,`Message`,`Color`,`Base`,`XP`,`LastDay`,`EnemyClan`,`CWwin`,`ClanBank`,`ClanZones`,`CTag`,%s)", query_string);
			format(query_string, sizeof(query_string), "%s VALUES (				'%d',	'%s','%s',	'%s',		'%d','%d',	'%d',	'%d',	'%d',		'%d',	'%d',		'%d',		'%s',	'%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s','%s')", query_string, Clan[i][cLevel],Clan[i][cLider],Clan[i][cName],Clan[i][cMessage],Clan[i][cColor],Clan[i][cBase],Clan[i][cXP],Clan[i][cLastDay],Clan[i][cEnemyClan],Clan[i][cCWwin],Clan[i][ClanBank],Clan[i][ClanZones],
			Clan[i][cTag], CMember[i][1], CMember[i][2], CMember[i][3], CMember[i][4], CMember[i][5], CMember[i][6], CMember[i][7], CMember[i][8], CMember[i][9], CMember[i][10], CMember[i][11], CMember[i][12], CMember[i][13], CMember[i][14], CMember[i][15], CMember[i][16], CMember[i][17], CMember[i][18], CMember[i][19], CMember[i][20]);
    		mysql_function_query(connects, query_string, false, "UploadClan", "d", i);
		}
*/

stock ResetPlayer(playerid)
{
    Player[playerid][SID] = 0;
	Player[playerid][Model] = 0;
	Player[playerid][Admin] = 0;
	Player[playerid][Level] = 0;
	Player[playerid][Exp] = 0;
	Player[playerid][Spawn] = 0;
	Player[playerid][SpawnStyle] = 0;
	Player[playerid][Invisible] = 0;
	Player[playerid][Time] = 0;
	Player[playerid][Cash] = 0;
	Player[playerid][Bank] = 0;
	Player[playerid][Slot1] = 0;
	Player[playerid][Slot2] = 0;
	Player[playerid][Slot3] = 0;
	Player[playerid][Slot4] = 0;
	Player[playerid][Slot5] = 0;
	Player[playerid][Slot6] = 0;
	Player[playerid][Slot7] = 0;
	Player[playerid][Slot8] = 0;
	Player[playerid][Slot9] = 0;
	Player[playerid][Slot10] = 0;
	Player[playerid][MyClan] = 0;
	Player[playerid][Member] = 0;
	Player[playerid][Leader] = 0;
	Player[playerid][Home] = 0;
	Player[playerid][Account] = 0;
	Player[playerid][Banned] = 0;
	strmid(BannedBy[playerid], "ПУСТО", 0, strlen("ПУСТО"), 5);
	strmid(BanReason[playerid], "ПУСТО", 0, strlen("ПУСТО"), 5);
	Player[playerid][Muted] = 0;
	strmid(MutedBy[playerid], "ПУСТО", 0, strlen("ПУСТО"), 5);
	Player[playerid][CarSlot1] = 462;
	Player[playerid][CarSlot1Color1] = 0;
	Player[playerid][CarSlot1Color2] = 0;
	Player[playerid][CarSlot1PaintJob] = -1;
	Player[playerid][CarSlot1Neon] = 0;
	Player[playerid][CarSlot1Fire] = 0;
	Player[playerid][CarSlot1Sir] = 0;
	Player[playerid][CarSlot1Mig] = 0;
	Player[playerid][CarSlot1Component0] = 0;
	Player[playerid][CarSlot1Component1] = 0;
	Player[playerid][CarSlot1Component2] = 0;
	Player[playerid][CarSlot1Component3] = 0;
	Player[playerid][CarSlot1Component4] = 0;
	Player[playerid][CarSlot1Component5] = 0;
	Player[playerid][CarSlot1Component6] = 0;
	Player[playerid][CarSlot1Component7] = 0;
	Player[playerid][CarSlot1Component8] = 0;
	Player[playerid][CarSlot1Component9] = 0;
	Player[playerid][CarSlot1Component10] = 0;
	Player[playerid][CarSlot1Component11] = 0;
	Player[playerid][CarSlot1Component12] = 0;
	Player[playerid][CarSlot1Component13] = 0;
	Player[playerid][CarSlot1NitroX] = 0;
	Player[playerid][CarSlot2] = 0;
	Player[playerid][CarSlot2Color1] = 0;
	Player[playerid][CarSlot2Color2] = 0;
	Player[playerid][CarSlot2PaintJob] = -1;
	Player[playerid][CarSlot2Neon] = 0;
	Player[playerid][CarSlot2Fire] = 0;
	Player[playerid][CarSlot2Sir] = 0;
	Player[playerid][CarSlot2Mig] = 0;
	Player[playerid][CarSlot2Component0] = 0;
	Player[playerid][CarSlot2Component1] = 0;
	Player[playerid][CarSlot2Component2] = 0;
	Player[playerid][CarSlot2Component3] = 0;
	Player[playerid][CarSlot2Component4] = 0;
	Player[playerid][CarSlot2Component5] = 0;
	Player[playerid][CarSlot2Component6] = 0;
	Player[playerid][CarSlot2Component7] = 0;
	Player[playerid][CarSlot2Component8] = 0;
	Player[playerid][CarSlot2Component9] = 0;
	Player[playerid][CarSlot2Component10] = 0;
	Player[playerid][CarSlot2Component11] = 0;
	Player[playerid][CarSlot2Component12] = 0;
	Player[playerid][CarSlot2Component13] = 0;
	Player[playerid][CarSlot2NitroX] = 0;
	Player[playerid][CarSlot3] = 0;
	Player[playerid][CarSlot3Color1] = 0;
	Player[playerid][CarSlot3Color2] = 0;
	Player[playerid][GameGold] = 0;
	Player[playerid][GameGoldTotal] = 0;
	Player[playerid][GPremium] = 0;
	Player[playerid][SkillHP] = 0;
	Player[playerid][SkillRepair] = 0;
	Player[playerid][ActiveSkillPerson] = 0;
	Player[playerid][ActiveSkillCar1] = 0;
	Player[playerid][ActiveSkillCar2] = 0;
	Player[playerid][ActiveSkillHCar1] = 0;
	Player[playerid][ActiveSkillHCar2] = 0;
	Player[playerid][Prestige] = 0;
	Player[playerid][Karma] = 250;
	Player[playerid][KarmaTime] = 0;
	Player[playerid][PosX] = 0.0;
	Player[playerid][PosY] = 0.0;
	Player[playerid][PosZ] = 0.0;
	Player[playerid][PosA] = 0.0;
	Player[playerid][ConPM] = 1;
	Player[playerid][FindPack] = 0;
	Player[playerid][SlivBlock] = -1;
	Player[playerid][ReadObnovlenie] = 0;
	Player[playerid][Bonus] = 0;
	Player[playerid][ConInviteClan] = 1;
	Player[playerid][ConInvitePVP] = 1;
	Player[playerid][ConMesPVP] = 1;
	Player[playerid][ConMesEnterExit] = 0; //По умолчанию сообщения о входе/выходе на сервер не отображаются
	Player[playerid][ConSpeedo] = 1;
	Player[playerid][RadarSwitch] = 1;
	Player[playerid][Mrf1] = 0;
	Player[playerid][Type] = 0;
	Player[playerid][Tag] = 0;
	Player[playerid][LastHourExp] = 0;
	Player[playerid][LastHourReferalExp] = 0;
	Player[playerid][HelpTime] = 500;
	Player[playerid][EventChangeTime] = 0;
	Player[playerid][LeaveZM] = 0;
	Player[playerid][ClanWarTime] = 0;
	Player[playerid][CasinoBalance] = 0;
	Player[playerid][GiveCashBalance] = 0;
	Player[playerid][BuddhaTime] = 0;
	Player[playerid][PrestigeColor] = -1;
	Quest[playerid][0] = random(10) + 1;
	QuestScore[playerid][0] = 0;
	QuestTime[playerid][0] = 0;
	Quest[playerid][1] = random(10) + 11;
	QuestScore[playerid][1] = 0;
	QuestTime[playerid][1] = 0;
	Quest[playerid][2] = 25;//quest: Проведите на сервере 60 минут.
	QuestScore[playerid][2] = 0;
	QuestTime[playerid][2] = 0;
	Player[playerid][Medals] = 0;
	Player[playerid][CompletedQuests] = 0;
	Player[playerid][GGFromMedals] = 0;
	Player[playerid][GGFromMedalsTotal] = 0;
	Player[playerid][GGFromMedalsLastDay] = 0;

	//Переменные, которые НЕ сохраняются в файл
	Player[playerid][CarActive] = 0;
	Player[playerid][PHealth] = 100.0;
	Player[playerid][PArmour] = 100.0;

	//О регистрации
	RegisterDate[playerid] = "Null";
	RegisterIP[playerid] = "Null";
	//RegisterISP[playerid] = "?";
	//RegisterHost[playerid] = "?";
	//RegisterLocation[playerid] = "?";
}

stock WriteLog(LogName[], string[])
{//Запись в лог. Например WriteLog("Файл", "Привет Мир!"); запишет в лог "Файл.ini" фразу "Привет Мир!"
	new entry[256], LogWay[120], i;
	format(entry,sizeof entry,"\r\n%s",string);format(LogWay,sizeof LogWay, "Logs/%s.log",LogName);
	new File: hfile = fopen(LogWay, io_append);
	while (entry[i] != EOS) {fputchar(hfile,entry[i],false); i++;}
	fclose(hfile);
}//Запись в лог. Например WriteLog("Файл", "Привет Мир!"); запишет в лог "Файл.ini" фразу "Привет Мир!"

