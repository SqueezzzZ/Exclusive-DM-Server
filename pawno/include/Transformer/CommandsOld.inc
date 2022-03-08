

/*if(!strcmp(cmd, "/speedtest", true))
{
    new currenttime = GetTickCount();
    for(new i = 0;i<100000;i++)
    {
        SendCommand(playerid, "/add", "",1);
    }
    new string[140],time = GetTickCount()-currenttime;
    format(string,sizeof(string),"1) Вызов другой команды - скорость: %d мс",time);
    SendClientMessage(playerid,COLOR_RED,string);
    
    currenttime = GetTickCount();
    for(new i = 0;i<100000;i++)
    {
        Addd();
    }
    time = GetTickCount()-currenttime;
    format(string,sizeof(string),"2) Вызов функции - скорость: %d мс",time);
    SendClientMessage(playerid,COLOR_RED,string);
    
	return 1;
}

if(!strcmp(cmd, "/add", true))
{
	new keks;
	keks = 5+4;
	return 1;
}
*/
if(!strcmp(cmd, "/marafon", true))
{
	ShowMarafonDialog(playerid);
	return 1;
}

if(!strcmp(cmd, "/ytbonus17", true))
{
    if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
    if (Player[playerid][Banned] > 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы забанены!");

    if(strcmp(PlayerName[playerid], "reserv"))
    {
		if(Player[playerid][Level] > 5 || Player[playerid][Prestige] > 0) return SendClientMessage(playerid,COLOR_RED,"Этот бонус-код доступен только новичкам до 5 уровня!");
	}
	
	Player[playerid][Level]+=5;
	Player[playerid][GameGold] += 10.0;
	Player[playerid][Karma] += 100;
	new xDay = DateToIntDate(Day, Month, Year);
	Player[playerid][SlivBlock] = xDay + 3;
	
	ShowPlayerDialog(playerid, 999, 0, "{ffff00}Бонус-код:", "{ffffff}Поздравляем! Вы получили бонус!\n\nВ состав бонуса входят:\n\n{ffff00} 1) +5 уровней\n 2) +10 доната (/shop)\n 3) +100 к карме (/karma)\n 4) 3 дня защиты от потери денег (несливайка)", "ОК", "");
	
	
	return 1;
}



if(!strcmp(cmd, "/zones", true))
{
    if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
    if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы забанены! Купить разбан можно в {FFFFFF}/shop");
	ShowZones(playerid);
	return 1;
}

/*if(!strcmp(cmd, "/lol", true))
{
	new String[1500] = "";
	strcat(String, "{ffff00}_________[Общие данные]_________\n");

	strcat(String, "{ffffff}Название: \tProGovnari\n");
	strcat(String, "ИД: 12\t\t ЦВЕТ: 8\n");
	strcat(String, "ЛИДЕР: \tSashka_Boroda\n");
	strcat(String, "ШТАБ: \t\tЕсть\n\n");
	strcat(String, "{ffff00}______[Информация об уровне]______\n");
	strcat(String, "{ffffff}Уровень: \t8\n");
	strcat(String, "ХП набрано: \t61244\n");
	strcat(String, "ХП осталось: \t34234325\n\n");
	strcat(String, "{ffff00}______________[Зоны]______________\n");
	strcat(String, "{ffffff}Захвачено: \t2\n");
	strcat(String, "Доходы: \t150 хп, 1433$\n\n");
	strcat(String, "{ffff00}_________[Дополнительно]__________\n");
	strcat(String, "{ffffff}Казна: \t343222$\n");
	strcat(String, "Тег: \t[SOS]\n");
	strcat(String, "Места: \t12/20\n");

	ShowPlayerDialog(playerid, 999, 0, "Cтатистика клана:", String, "Состав", "Выход"); return 1;
}*/

/*if(!strcmp(cmd, "/lol1", true))
{
	new String[1500] = "";
	strcat(String, "{ffff00}Общие данные:\n");
	strcat(String, "{5882FA}Название: \t{ffff00}ProGovnari\n");
	strcat(String, "{5882FA}ЛИДЕР: {ffff00}\tSashka_Boroda4\n");
	strcat(String, "{5882FA}ШТАБ: {ffff00}\t\tЕсть\n");
	strcat(String, "{58D3F7}ИД: 12\t\tЦВЕТ: 8\n\n");
	strcat(String, "{ffff00}Информация об уровне:\n");
	strcat(String, "{ffffff}Уровень: \t8\n");
	strcat(String, "ХП набрано: \t61244\n");
	strcat(String, "ХП осталось: \t34234325\n\n");
	strcat(String, "{ffff00}Зоны:\n");
	strcat(String, "{ffffff}Захвачено: \t2\n");
	strcat(String, "Доходы: \t150 хп, 1433$\n\n");
	strcat(String, "{ffff00}Дополнительно:\n");
	strcat(String, "{ffffff}Казна: \t\t343222$\n");
	strcat(String, "Тег: \t\t[SOS]\n");
	strcat(String, "Места: \t12/20\n");
	ShowPlayerDialog(playerid, 999, 0, "Cтатистика клана:", String, "Состав", "Выход"); return 1;
}*/

if(!strcmp(cmd, "/topclans", true))
{
	TopClanShow(playerid);
	return 1;
}

if(!strcmp(cmd, "/members", true))
{
    if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
	if (Player[playerid][Member] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы не в клане."); return 1;}
	ShowClanMembers(playerid, Player[playerid][MyClan]);
	return 1;
}
if(!strcmp(cmd, "/t", true)) // zcmd command
{
	if (Player[playerid][Muted] != 0) return SendClientMessage(playerid,COLOR_RED,"Вам запрещено отправлять сообщения");
	if (!strlen(params)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используйте /t [text]");
	if (FTimeToEnd < 1) return SendClientMessage(playerid,COLOR_RED,"Вы не можете писать в командный чат, т.к. битва еще не началась!");
	if (FStarted[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"Вы не можете писать в командный чат, т.к. вы не в битве!");
	new string[140];
	new cid;
	format(string,sizeof(string),"%s(%d)[КОМАНДЕ]: %s",PlayerName[playerid],playerid,params);
	for (new i = 0; i < 25; i++)
	{
		cid = FPlayersList[i];
		if (!IsPlayerConnected(cid) || FStarted[cid] == 0) continue;
		if (FPlayerTeam[cid] == 0 && FPlayerTeam[playerid] == 0)
		{
           SendClientMessage(cid, 0x819FF7FF, string);
		}
		if (FPlayerTeam[cid] == 1 && FPlayerTeam[playerid] == 1)
		{
			SendClientMessage(cid, 0xFA5858FF, string);
		}
	}
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   TEAMCTF: %s[%d] ввел /t %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, params);
	WriteLog("GlobalLog", string);
	return 1;
}
if(!strcmp(cmd, "/attack", true))
{
	if (InEvent[playerid] > 0){SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях");return 1;}
	if (Player[playerid][Member] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы не в клане."); return 1;}
	if(Player[playerid][Leader] < 2) {SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Для начала захвата нужен 2 ранг!"); return 1;}
	
	new ZoneID = OnZone[playerid];
	if(ZoneID == -1) {SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы не в зоне захвата."); return 1;}
	new PlayerClan = Player[playerid][MyClan];
	
	if(GangZones[ZoneID][GZOwner] == PlayerClan && GangZones[ZoneID][ZoneAttacked] == 0)//атакующий - владелец и зона не атакована
	{
 		SendClientMessage(playerid,COLOR_RED,"Эта зона и так принадлежит вашему клану! Информация о зоне: /zoneinfo");
   		return 1;
	}
	
	if(Clan[PlayerClan][cLevel] < GangZones[ZoneID][GZLevel]) //уровень не подходит
 	{
		new string[140];
		format(string,sizeof(string),"Минимальный уровень клана для захвата этой зоны: {ffffff}%d. {ff0000}Ваш:{ffffff} %d", GangZones[ZoneID][GZLevel], Clan[PlayerClan][cLevel]);
		SendClientMessage(playerid,COLOR_RED,string);
	    return 1;
	}
	
	if(Clan[PlayerClan][ClanZones] > 2)
	{
		if(GangZones[ZoneID][GZOwner] != PlayerClan)
		{
	    	SendClientMessage(playerid,COLOR_RED,"Максимальное кол-во зон клана - 3!");
			return 1;
		}
	}
	
	if(GangZones[ZoneID][GZClanTime] > 0)//не вышло время для начала захвата
	{
	    new string[140];
		format(string,sizeof(string),"Зона будет доступна для захвата через: {ffffff}%s.", TimeConvert(GangZones[ZoneID][GZClanTime]));
	    SendClientMessage(playerid,COLOR_RED,string);
		return 1;
	}
			
	if(GangZones[ZoneID][ZoneAttacked] > 0 && Clan[PlayerClan][NowWarZone] > 0) //зона уже атакована и клан уже атакует зону
	{
	    SendClientMessage(playerid,COLOR_RED,"Эта зона уже атакована!");
		return 1;
	}
	
	if(Clan[Player[playerid][MyClan]][NowWarZone] > 0) {SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Ваш клан атакует другую территорию!"); return 1;}
	
	if(ZAtt[ZoneID] == MAX_ATTACK)
	{
	    SendClientMessage(playerid,COLOR_RED,"Превышен лимит атакующих кланов!"); //лимит атакующих
		return 1;
	}
			
	Clan[PlayerClan][NowWarZone] = ZoneID;
	ZoneAttacker[ZoneID][ZAtt[ZoneID]] = PlayerClan;
	if(ZoneAttacker[ZoneID][0] == PlayerClan)
	{
        GangZones[ZoneID][ZoneAttacked] = 1;
        GangZoneFlashForAll(ClanZoneID[ZoneID],0xFF0000AA);
        ZonePrepareTime[ZoneID] = 120;
        new stext[140];
        format(stext, sizeof(stext), "CLANWAR: Клан {ffffff}%s{008E00}[%d] атаковал '{ffffff}%s{008E00}'! Уровень зоны: {ffffff}%d", Clan[PlayerClan][cName], PlayerClan, GangZones[ZoneID][GZName],GangZones[ZoneID][GZLevel]);
        SendClientMessageToAll(0x008E00FF,stext);
        SendClientMessageToAll(0x008E00FF,"У кланов есть {ffffff}2 минуты,{008E00} чтобы прибыть на захват и атаковать (/attack)!");
		if(GangZones[ZoneID][GZOwner] != 0)
		{
			format(stext, sizeof(stext), "CLANWAR: Нашу территорию '{ffffff}%s{FFA500}' атаковали! У клана есть {ffffff}%s{FFA500} на подготовку!", GangZones[ZoneID][GZName], TimeConvert(ZonePrepareTime[ZoneID]));
			foreach(Player, cid) if (Player[cid][MyClan] == GangZones[ZoneID][GZOwner] && Logged[cid] == 1){SendClientMessage(cid, COLOUR_GANG_CHAT, stext);}
		}
	}
	else
	{
		new stext[140];
		format(stext, sizeof(stext), "CLANWAR: Мы атаковали зону '{ffffff}%s{FFA500}'. У клана есть {ffffff}%s{FFA500} на подготовку!", GangZones[ZoneID][GZName], TimeConvert(ZonePrepareTime[ZoneID]));
		foreach(Player, cid) if (Player[cid][MyClan] == Player[playerid][MyClan] && Logged[cid] == 1){SendClientMessage(cid, COLOUR_GANG_CHAT, stext);}
	}
	ZAtt[ZoneID]++;
	return 1;
}

if(!strcmp(cmd, "/zoneinfo", true))
{
    if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
    new ZoneID = OnZone[playerid];
    if(ZoneID == -1) {SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны находиться в захватываемой территории!"); return 1;}
	new String[400],str1[30],str2[30];
	if(GangZones[ZoneID][GZOwner] > 0) format(str1, sizeof str1, "%s", Clan[GangZones[ZoneID][GZOwner]][cName]);
	else {format(str1, sizeof str1, "{00ff00}Владелец отсутствует");}
	
	if(GangZones[ZoneID][GZClanTime] > 0) format(str2, sizeof str2, "Можно атаковать через %s", TimeConvert(GangZones[ZoneID][GZClanTime]));
	else {format(str2, sizeof str2, "{00ff00}Доступна для захвата");}
	
    format(String, sizeof String, "{04B404}Название: {ffffff}%s [ID: %d]\n{04B404}Уровень территории: {ffffff}%d\n{04B404}Доход опыта: {ffffff}%d ХП\n{04B404}Доход денег: {ffffff}%d$\n\n{ff0000}Владелец: {ffffff}%s\n{ff0000}Доступ:{ffffff} %s", GangZones[ZoneID][GZName], ZoneID,GangZones[ZoneID][GZLevel], GangZones[ZoneID][GZExp], GangZones[ZoneID][GZCash], str1,str2);
    ShowPlayerDialog(playerid, 999, 0, "{ffff00}Информация о территории:", String, "ОК", "");
    return 1;
}
/*if(!strcmp(cmd, "/rnick", true))
{
	if(Player[playerid][Level] == 0) return SendClientMessage(playerid,COLOR_RED,"Недоступно.");
    strmid(ChatName[playerid], PlayerName[playerid], 0, strlen(PlayerName[playerid]), 100);
    Player[playerid][Tag] = 0;
    new query[120];
	format(query,sizeof(query),"UPDATE `accounts` SET `ChatName` = '%s', `Tag` = '0' WHERE `SID` = '%i'",PlayerName[playerid],Player[playerid][SID]);
	mysql_tquery(connects, query);
	//WriteLog("GlobalLog", query);
	SendClientMessage(playerid,COLOR_GG,"Ваш ник в чате был установлен в стандартное состояние!");
	return 1;
}*/
/*
if(!strcmp(cmd, "/ex", true)) // zcmd command
{
	if (PlayerExt[playerid] < 1) return 1;
	if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
	if (Player[playerid][Muted] != 0) return SendClientMessage(playerid,COLOR_RED,"Вам запрещено отправлять сообщения");
	if (!strlen(params)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используйте /ex [ид]");
	new string[140];
	format(string,sizeof(string),"Ex7Plays: %s",params);
	SendClientMessageToAll(0xFFA500FF,string);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   EX7: %s[%d] ввел /ex %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, params);
	WriteLog("GlobalLog", string);
	return 1;
}

if(!strcmp(cmd, "/setex", true))
{//команды надо вводить без "/"
	if (Player[playerid][Admin] < 4) return 1;//Как минимум обычный модер
	if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
	new targetid;
	if(sscanf(params,"i", targetid))//занесем значение которе ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА! Lol kek!!!");
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
    PlayerExt[targetid] = 1;
	SendClientMessage(playerid,COLOR_RED,"Setted!");
	return 1;
}*/

/*if(!strcmp(cmd, "/chatoff", true))
{//команды надо вводить без "/"
	if (Player[playerid][Admin] < 4) return 1;//Как минимум обычный модер
	if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
	if(ChatOff == 0)
	{
		ChatOff = 1;
		SendClientMessageToAll(0xFFA500FF,"Администратор выключил общий чат для игроков до 10 уровня!");
	}
	else
	{
	    SendClientMessageToAll(0xFFA500FF,"Администратор включил общий чат для всех!");
		ChatOff = 0;
	}
	return 1;
}*/

if(!strcmp(cmd, "/ranginfo", true))
{
	new String[1000] = "";
	strcat(String, "{819FF7}Информация о рангах кланов (/clan - Управление - Назначение):\n\n");
	strcat(String, "{ffff00}[1 ранг] (обычный член клана)\n");
	strcat(String, "{ffffff} - может ложить деньги в банк (меню в банке)\n - может включать/отключать свой тег в настройках\n\n");
	strcat(String, "{ffff00}[2 ранг]\n");
	strcat(String, "{ffffff} - может атаковать территории (/attack)\n\n");
	strcat(String, "{ffff00}[3 ранг]\n");
	strcat(String, "{ffffff} - может объявлять войну другому клану\n\n");
	strcat(String, " - может брать деньги из общака (меню в банке)\n");
	strcat(String, "{ffff00}[4 ранг]\n");
	strcat(String, "{ffffff} - может принимать/удалять игроков в клан\n\n");
	strcat(String, "{ffff00}[5 ранг]\n");
	strcat(String, "{ffffff} - может изменять цвет клана\n");
	strcat(String, " - может изменять клановый тег\n\n");
	strcat(String, "{ff0000}[Лидер]\n");
	strcat(String, "{ffffff} - может покупать/продавать штаб\n");
	strcat(String, " - может удалять клан\n");
	strcat(String, " - управляет рангами клана\n");
	strcat(String, " - может менять название клана\n");
	strcat(String, " - может менять лидера клана\n");

	ShowPlayerDialog(playerid, 999, 0, "{ff0000}Информация о рангах:", String, "ОК", ""); return 1;
}

if(!strcmp(cmd, "/commands", true))
{
	DialogCommands(playerid);
	return 1;
}


if(!strcmp(cmd, "/sm", true))
{
	SendClientMessage(playerid,COLOR_RED,"SERVER: Воспроизведние остановлено.");
 	StopAudioStreamForPlayer(playerid);
 	return 1;
}

if(!strcmp(cmd, "/help", true)){return ShowPlayerDialog(playerid, DIALOG_HELP, 2, "Помощь (/help)", "{FFFF00}Часто Задаваемые Вопросы (FAQ){FFFFFF}\nИгровые команды, Чат\nИнформация об уровнях\nУровни ViP", "ОК", "Закрыть");}

if(!strcmp(cmd, "/status", true)) return ShowStats(playerid,playerid);
if(!strcmp(cmd, "/stat", true)) return ShowStats(playerid,playerid);
if(!strcmp(cmd, "/level", true)) return ShowStats(playerid,playerid);
if(!strcmp(cmd, "/stats", true)) return ShowStats(playerid,playerid);

if(!strcmp(cmd, "/pm", true))
{
	new pmid, text[140];
	if(sscanf(params,"is[140]", pmid, text))//
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /pm [id игрока] [Сообщение]");//если игрок не ввел значение то выдаем собщение 
	if (Logged[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");
	if (Player[playerid][Muted] != 0) return SendClientMessage(playerid,COLOR_RED,"Вам запрещено отправлять личные сообщения");
	if (Player[playerid][ConPM] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Сначала вам нужно включить систему личных сообщений ({FFFFFF}/config{FF0000})");
	if (!IsPlayerConnected(pmid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (Player[pmid][ConPM] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Этот игрок отключил систему личных сообщений");
	if (pmid == playerid) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя отправлять сообщения самому себе!");
	if (strlen(text) > 100) strmid(text, text, 0, 99);//Обрезаем сообщение, если оно слишком длинное
	
	if (strfind(text, "exclusivedm1", true)!=-1) {BanEx(playerid, "засранец"); return 1;}
	
	//Ниже идет проверка сообщения
	new count;
	if (Player[playerid][Admin] < 4) for (new i; i < strlen(text); i++)
	{//--- Цифры в тексте
	    if (text[i] >= '0' && text[i] <= '9')
	    {
	        count++; if (count > 5) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Сообщение не должно содержать больше 5 цифр!");
	    }
	}//--- Цифры в тексте
	//Защита от флуда
	
	if (FloodTime[playerid] == 0) FloodTime[playerid] = 5;
	FloodMessages[playerid] += 1;
	if (FloodMessages[playerid] >= 3)
	{
		SendClientMessage(playerid, COLOR_GREY, "Не флуди!");
		return 1;
	}

	//Ниже идет отправка сообщения
	new String[140];
	format(String,sizeof(String),"PM от %s[%d]: %s",PlayerName[playerid],playerid, text); SendClientMessage(pmid, COLOR_YELLOW, String);
	format(String,sizeof(String),"PM для %s[%d]: %s",PlayerName[pmid],pmid, text); SendClientMessage(playerid, 0xFFD700FF, String);
	PlayerPlaySound(pmid,1083,0.0,0.0,0.0);//caoe auea?uoa
	//отправка сообщения гл. админу.
	format(String,sizeof(String),"PM %s[%d] >> %s[%d]: %s",PlayerName[playerid],playerid, PlayerName[pmid], pmid, text);
	foreach(Player, cid) if (Player[cid][Admin] >= 3 && Logged[cid] == 1 && cid != playerid && cid != pmid){SendClientMessage(cid, 0xFB98DAFF, String);}
	//Запись в лог
	format(String, 200, "%d.%d.%d в %d:%d:%d |   PM %s[%d] >> %s[%d]: %s", Day, Month, Year, hour, minute, second, PlayerName[playerid],playerid, PlayerName[pmid], pmid, text); WriteLog("GlobalLog", String);
    
	if (LAFK[pmid] >= 4) SendClientMessage(playerid,COLOR_RED,"Внимание! Этот игрок может не увидеть ваше сообщение, так как он AFK.");
	if (LAFK[pmid] < 4 && InEvent[pmid] > 0) SendClientMessage(playerid,COLOR_NICEORANGE,"Внимание! Игрок может не сразу ответить на ваше сообщение, так как участвует в соревновании.");
	return 1;
}

if(!strcmp(cmd, "/skydive", true))
{
	new skdv=SkydiveTime[playerid]-unixtime;
	if (skdv > 0)
	{
		new string[120];
		format(string, sizeof(string), "{FF0000}Команда будет доступна через {FFFFFF}%d{FF0000} секунд.", skdv);
		SendClientMessage(playerid,COLOR_RED,string);return 1;
	}
	if (Player[playerid][Level] < 2) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 2-го уровня, чтобы использовать эту команду");
	if (InEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Нельзя использовать эту команду в соревнованиях!");
	if (GetPlayerInterior(playerid) != 0 || IsPlayerInRangeOfPoint(playerid, 13.0, 2311.6953,-7.4206,26.7422)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть на улице, чтобы использовать эту команду");
	
	if(Clan[Player[playerid][MyClan]][NowWarZone] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Эта команда запрещена во время войны за территорию.");
	
	if (Player[playerid][Cash] < 5000 && Player[playerid][Karma] < 400) return ShowMoneyWant(playerid,1,"5000");
	if (OnFly[playerid] == 1) StopFly(playerid);
	new Float:x,Float:y,Float:z,string[120];
	if (Player[playerid][Karma] < 400) Player[playerid][Cash] -= 5000;
	format(string, sizeof(string), "SERVER: %s[%d] прыгнул с парашютом (/skydive).", PlayerName[playerid],playerid);
	SendClientMessageToAll(COLOR_WHITE,string);
	GetPlayerPos(playerid,x,y,z); SetPlayerPos(playerid, x, y, z + 1300);   
	GiveWeapon(playerid,46,1);
	LACFlyOff[playerid] = 45; //Исправляет от ложных срабатываний LAC на FlyHack
	SkydiveTime[playerid] = unixtime+300;
	return 1; 
}

if(!strcmp(cmd, "/bg", true)) {SendCommand(playerid, "/buygun", "",1); return 1;}
if(!strcmp(cmd, "/gg", true)) {SendCommand(playerid, "/gungame", "",1); return 1;}
if(!strcmp(cmd, "/buygun", true))
{
	if (InEvent[playerid] > 0){SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя покупать оружие в соревнованиях");return 1;}
	ShowModelSelectionMenu(playerid, MenuBuyGun, "Buy Gun");
	return 1;
}

if(!strcmp(cmd, "/style", true))
{
	if (Player[playerid][Level] < 36){SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Вы должны быть как минимум 36-го уровня, чтобы изменять стиль драки");return 1;}
	ShowPlayerDialog(playerid, DIALOG_STYLE, 2, "Стиль драки", "{FFFFFF}Обычный\nBoxing\nKungFu\nKneeHead\nGrabKick\nElbow\n{007FFF}MixFight (все вместе)", "ОК", "");
	return 1;
}

if(!strcmp(cmd, "/myspawn", true))
{
	new StringX[1024];
	if (Player[playerid][Level] < 15) strcat(StringX, "{FFFFFF}Стандартное место спавна: {AFAFAF}Лос Сантос (Уровни 1-14)");
	else if (Player[playerid][Level] < 25) strcat(StringX, "{FFFFFF}Стандартное место спавна: {AFAFAF}Сан Фиерро (Уровни 15-24)");
	else if (Player[playerid][Level] < 69) strcat(StringX, "{FFFFFF}Стандартное место спавна: {AFAFAF}Лас Вентурас (Уровни 25-68)");
	else strcat(StringX, "{FFFFFF}Стандартное место спавна: {AFAFAF}Гора Chilliad (Уровни 69-100)");
	strcat(StringX, "\n{00FF00}Личный дом (Снаружи)\n{00FF00}Личный дом (Внутри)\n{007FFF}Штаб клана (Снаружи)\n{007FFF}Штаб клана (Внутри)\n{FFFF00}Ваше текущее местоположение (ViP)");
	ShowPlayerDialog(playerid, DIALOG_MYSPAWN, 2, "Настройки респавна - Место", StringX, "ОК", "");
	return 1;
}

if(!strcmp(cmd, "/invisible", true))
{
	new String[80];
	if (Player[playerid][Invisible] == 0) String = "{AFAFAF}Невидимость [{FF0000}Отключена{AFAFAF}]";
	else String = "{AFAFAF}Невидимость [{008D00}На радаре{AFAFAF}]";
	ShowPlayerDialog(playerid, DIALOG_INVISIBLE, 2, String, "Нет\nНа радаре", "ОК", "");
	return 1;
}

if(!strcmp(cmd, "/mygun", true))
{
	new StringX[800], String[100], zWeapon[48];	
	
	GetWeaponName(Player[playerid][Slot1], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}8{FFFFFF}] Холодное Оружие ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot2], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}16{FFFFFF}] Пистолеты ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot3], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}17{FFFFFF}] Дробовики ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot4], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}18{FFFFFF}] Пистолет-Пулеметы ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot5], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}19{FFFFFF}] Автоматы ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot8], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}23{FFFFFF}] Метательное ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot6], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}34{FFFFFF}] Винтовки ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot7], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}40{FFFFFF}] Тяжелое оружие ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);
	
	GetWeaponName(Player[playerid][Slot10], zWeapon, sizeof zWeapon);
	format(String, sizeof String, "{FFFFFF}[{FFFF00}4{FFFFFF}] Прочее ({007FFF}%s{FFFFFF})\n", zWeapon);
	strcat(StringX, String);

	ShowPlayerDialog(playerid, DIALOG_MYGUN, 2, "Личное Оружие", StringX, "ВЫБРАТЬ", "ЗАКРЫТЬ");
	return 1;
}

if(!strcmp(cmd, "/jetpack", true))
{
	if (Player[playerid][Level] < 38){SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Вы должны быть как минимум 38-го уровня");return 1;}
	if (GetPlayerWeapon(playerid) == 46) return SendClientMessage(playerid,COLOR_RED,"Смените оружие! Нельзя надевать JetPack с парашютом за спиной.");

	if (OnFly[playerid] == 1) StopFly(playerid);
	if (IsPlayerInAnyVehicle(playerid)){SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя надеть JetPack сидя в машине!");return 1;}
	if(InEvent[playerid] > 0){SendClientMessage(playerid,COLOR_RED,"Нельзя надевать JetPack в соревнованиях!"); return 1;}
	if (GetPlayerInterior(playerid) != 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть на улице, чтобы надеть JetPack!");return 1;}
	if(QuestActive[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Нельзя надевать JetPack во время выполнения работы!");
	JetpackUsed[playerid] = 1;SetPlayerSpecialAction(playerid,SPECIAL_ACTION_USEJETPACK);
	return 1;
}

if(!strcmp(cmd, "/givecash", true))
{
	if (Player[playerid][Banned] > 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Забаненные игроки не могут передавать деньги");
	new plid; new money;//переменая куда занесется значение которое введет игрок 
	new string[180];
	if(sscanf(params,"dd", plid, money))//занесем значение которе ввел игрок в переменую skinid 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /givecash [id] [сумма]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(plid)){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); return 1;} 
	if (Logged[plid] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID не авторизировался"); return 1;} 
	if (plid == playerid){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя отправлять деньги самому себе."); return 1;} 
	if (Player[plid][Banned] > 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя передавать деньги забаненному игроку");
	if (Player[plid][GiveCashBalance] >= 100000000) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Этому игроку нельзя передавать деньги!");
	if (LastPlayerTuneStatus[plid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя передавать деньги игроку, который он находится в автомастерской. Попробуйте позднее.");
	if (money < 1000){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Минимальная сумма перевода: 1000$"); return 1;}
	if (money > Player[playerid][Cash]){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: У вас нет такой суммы денег"); return 1;}
	if (money > 100000000 - Player[plid][GiveCashBalance]) money = 100000000 - Player[plid][GiveCashBalance];//Если игрок может получить лишь 20к по балансу - то эта строка правит сумму перевода на 20к
	Player[plid][Cash] += money;Player[playerid][Cash] -= money;
	Player[playerid][GiveCashBalance] -= money; Player[plid][GiveCashBalance] += money;
	format(string, sizeof(string), "{FFFF00}Игрок %s[%d] передал вам {FFFFFF}%d$ {FFFF00}денег", PlayerName[playerid], playerid, money);
	SendClientMessage(plid,COLOR_YELLOW,string);
	format(string, sizeof(string), "{FFFF00}Вы успешно передали {FFFFFF}%d$ {FFFF00}денег игроку %s[%d]", money, PlayerName[plid], plid);
	SendClientMessage(playerid,COLOR_YELLOW,string); 
	QuestUpdate(playerid, 15, money);//Обновление квеста Подарите другим игрокам 50 000$
	SavePlayer(playerid);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   CASH: %s[%d] передал %d$ игроку %s[%d]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, money, PlayerName[plid], plid);
	WriteLog("GlobalLog", string); WriteLog("CashOperations", string);
	return 1;
}

if(!strcmp(cmd, "/paintid", true))
{
	new col1; new col2;//переменая куда занесется значение которое введет игрок 
	new string[120];
	if (Player[playerid][Level] < 47){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 47-го уровня"); return 1;}
	if(sscanf(params,"dd", col1, col2))//занесем значение которе ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /paintid [id] [id]");//если игрок не ввел значение то выдаем собщение 
	if (col1 < 0 || col1 > 255 || col2 < 0 || col2 > 255){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Значение цветов должно быть в диапозоне от 0 до 255"); return 1;}
	if (!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть за рулем транспорта");
	format(string, sizeof(string), "Вы перекрасили ваш транспорт {FFFFFF}%d{FFFF00}. Новые цвета: {FFFFFF}%d{FFFF00} и {FFFFFF}%d", Player[playerid][CarActive], col1, col2);
	SendClientMessage(playerid, COLOR_YELLOW, string);
	if (Player[playerid][CarActive] > 0)
	{
		if (Player[playerid][CarActive] == 1){Player[playerid][CarSlot1Color1] = col1;Player[playerid][CarSlot1Color2] = col2;}
		if (Player[playerid][CarActive] == 2){Player[playerid][CarSlot2Color1] = col1;Player[playerid][CarSlot2Color2] = col2;}
		if (Player[playerid][CarActive] == 3){Player[playerid][CarSlot3Color1] = col1;Player[playerid][CarSlot3Color2] = col2;}
	}
	ChangeVehicleColor(GetPlayerVehicleID(playerid), col1, col2);
	SetPlayerChatBubble(playerid, "Перекрасил свою машину", COLOR_GREEN, 250.0, 3000);PlayerPlaySound(playerid,1134,0.0,0.0,0.0);
	return 1;
}

if(!strcmp(cmd, "/paint", true))
{
	new col1 = random (256); new col2 = random (256);//переменая куда занесется значение которое введет игрок 
	new string[120];
	if (Player[playerid][Level] < 47){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 47-го уровня"); return 1;}
	if (!IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть за рулем транспорта");
	format(string, sizeof(string), "Вы перекрасили ваш транспорт {FFFFFF}%d{FFFF00}. Новые цвета: {FFFFFF}%d{FFFF00} и {FFFFFF}%d", Player[playerid][CarActive], col1, col2);
	SendClientMessage(playerid, COLOR_YELLOW, string);
	if (Player[playerid][CarActive] > 0)
	{
		if (Player[playerid][CarActive] == 1){Player[playerid][CarSlot1Color1] = col1;Player[playerid][CarSlot1Color2] = col2;}
		if (Player[playerid][CarActive] == 2){Player[playerid][CarSlot2Color1] = col1;Player[playerid][CarSlot2Color2] = col2;}
		if (Player[playerid][CarActive] == 3){Player[playerid][CarSlot3Color1] = col1;Player[playerid][CarSlot3Color2] = col2;}
	}
	ChangeVehicleColor(GetPlayerVehicleID(playerid), col1, col2);//SavePlayer(playerid);
	SetPlayerChatBubble(playerid, "Перекрасил свою машину", COLOR_GREEN, 250.0, 3000);PlayerPlaySound(playerid,1134,0.0,0.0,0.0);
	return 1;
}

if(!strcmp(cmd, "/events", true)){ShowEvents(playerid);return 1;}
if(!strcmp(cmd, "/quests", true)){ShowQuests(playerid);return 1;}

//--added by SqueezZ--
//version 0.1
if(!strcmp(cmd, "/pt", true))
{
    if (Player[playerid][Muted] != 0) return SendClientMessage(playerid,COLOR_RED,"Вам запрещено использовать эту команду!");
    new StringX[120],ptbb=TimePTBB[playerid] - unixtime;
    if (ptbb > 0)
    {
        format(StringX,sizeof(StringX),"Команду можно будет использовать через %d секунд.", ptbb);
        SendClientMessage(playerid,COLOR_RED,StringX);
		return 1;
    }
	format(StringX,sizeof(StringX)," ..::: %s приветствует всех игроков! :::..", PlayerName[playerid]);
	SendClientMessageToAll(COLOR_YELLOW,StringX);
    TimePTBB[playerid] = unixtime+60;
	return 1;
}

if(!strcmp(cmd, "/bb", true))
{
    if (Player[playerid][Muted] != 0) return SendClientMessage(playerid,COLOR_RED,"Вам запрещено использовать эту команду!");
    new StringX[120],ptbb=TimePTBB[playerid] - unixtime;
    if (ptbb > 0)
    {
        format(StringX,sizeof(StringX),"Команду можно будет использовать через %d секунд.", ptbb);
        SendClientMessage(playerid,COLOR_RED,StringX);
		return 1;
    }
	format(StringX,sizeof(StringX)," ..::: %s прощается со всеми игроками! :::..", PlayerName[playerid]);
	SendClientMessageToAll(COLOR_ADMIN,StringX);
    TimePTBB[playerid] = unixtime+60;
	return 1;
}
if(!strcmp(cmd, "/afk", true))
{
	SendClientMessage(playerid,COLOR_ADMIN,"Игроки на паузе:");
	new count=0,stri[80];
   	foreach(Player, x)
   	{
   		if(LAFK[x] > 4)
   		{
			count++;
			format(stri,sizeof(stri),"[AFK]: {ffffff}%s(%d){00BFFF} [%s]",PlayerName[x], x, TimeConvert(LAFK[x]));
			SendClientMessage(playerid,COLOR_ADMIN,stri);
		}
	}
	if(count == 0)
	{
		SendClientMessage(playerid,COLOR_YELLOW,"Игроков в АФК нет!");
		return 1;
	}
	return 1;
}
if(!strcmp(cmd, "/version", true))
{
    ShowObovDialog(playerid);
    return 1;
}
//------------
//version (next)

//--
if(!strcmp(cmd, "/out", true))
{
    if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение, прежде чем  использовать эту функцию!");return 1;}
    if (JoinEvent[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы не участвуете ни в одном соревновании!");
    
    switch (JoinEvent[playerid])
	{
		case EVENT_DM: 		SendCommand(playerid, "/dm", "",1);
		case EVENT_DERBY: 	SendCommand(playerid, "/derby", "",1);
		case EVENT_ZOMBIE: 	SendCommand(playerid, "/zombie", "",1);
		case EVENT_RACE: 	SendCommand(playerid, "/race", "",1);
		case EVENT_XRACE: 	SendCommand(playerid, "/xrace", "",1);
		case EVENT_GUNGAME: SendCommand(playerid, "/gungame", "",1);
		case EVENT_FLAG: 	SendCommand(playerid, "/flag", "",1);
		case EVENT_PARK: 	SendCommand(playerid, "/park", "",1);
		case EVENT_DRACE: 	SendCommand(playerid, "/drace", "",1);
	}
    
	return 1;
}


if(!strcmp(cmd, "/dm", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_DM && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в десматче");
	if (JoinEvent[playerid] == 0)
	{
		if (DMTimer > 180) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы не можете присоединиться к десматчу, когда он еще не объявлен");
		if (DMPlayers == DMLimit) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");
		if (LeaveDM[playerid]-unixtime > 0) return SendClientMessage(playerid, COLOR_RED, "Вы только что покинули десматч! Пожалуйста, подождите несколько секунд...");
		if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
		if (DMTimeToEnd <= 0) SendClientMessage(playerid,COLOR_DM,"Вы присоединились к десматчу. Ждите старт..");
		JoinEvent[playerid] = EVENT_DM; DMPlayers++;
		new String[120];
		format(String,sizeof(String),"%s[%d] присоединился к десматчу.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_DM) SendClientMessage(cid,COLOR_DM,String);
		}
		if (DMTimeToEnd > 0)
		{//Если уже начался
			OnStartEvent[playerid] = 5; InEvent[playerid] = EVENT_DM; LSpawnPlayer(playerid);
			SendClientMessage(playerid,COLOR_DM,"Вы присоединились к десматчу.");
		}//Если уже начался
		else TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_DM]);
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_DM)
	{
		JoinEvent[playerid] = 0; InEvent[playerid] = 0; SendClientMessage(playerid,COLOR_DM,"Вы покинули десматч.");
		if (DMTimeToEnd > 0){ResetPlayerWeapons(playerid);LSpawnPlayer(playerid);}
		DMPlayers--;
		if (DMTimeToEnd > 0) LeaveDM[playerid] = unixtime+15;
		new String[120];
		format(String,sizeof(String),"%s[%d] покинул десматч.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[playerid] == EVENT_DM) SendClientMessage(cid,COLOR_DM,String);
		}	
	}
	return 1;
}



if(!strcmp(cmd, "/derby", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_DERBY && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в дерби");
	if (JoinEvent[playerid] == 0)
	{
		if (DerbyTimer < 180 && DerbyTimer > 0)
		{
			if (DerbyPlayers == DerbyLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
			if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
			JoinEvent[playerid] = EVENT_DERBY; SendClientMessage(playerid,COLOR_DERBY,"Вы присоединились к дерби. Ждите старт..");
			new String[120];
			DerbyPlayers++;
			format(String,sizeof(String),"%s[%d] присоединился к дерби.", PlayerName[playerid], playerid);
			TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_DERBY]);
			foreach(Player, cid)
			{
				if(cid != playerid && JoinEvent[cid] == EVENT_DERBY) SendClientMessage(cid,COLOR_DERBY,String);
			}	
		}
		if (DerbyTimer > 180){SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к дерби, когда оно еще не объявлено");}
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_DERBY)
	{
		JoinEvent[playerid] = 0; InEvent[playerid] = 0; SendClientMessage(playerid,COLOR_DERBY,"Вы покинули дерби.");
		LACSH[playerid] = 5;DerbyPlayers--;
		if (DerbyTimeToEnd > 0){ResetPlayerWeapons(playerid);LSpawnPlayer(playerid);}
		new String[120];
		format(String,sizeof(String),"%s[%d] покинул дерби.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_DERBY) SendClientMessage(cid,COLOR_DERBY,String);
		}	
	}
	return 1;
}

if(!strcmp(cmd, "/drace", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_DRACE && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в гонке на выживание");
	if (JoinEvent[playerid] == 0)
	{
		if (DRTimer < 180 && DRTimer > 0)
		{
			if (DRPlayers == DRLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
			if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
			JoinEvent[playerid] = EVENT_DRACE;
			SendClientMessage(playerid,COLOR_DRACE,"Вы присоединились к гонке на выживание. Ждите старт..");
			new String[120];
			DRPlayers++;
			format(String,sizeof(String),"%s[%d] присоединился к гонке на выживание.", PlayerName[playerid], playerid);
			TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_DRACE]);
			foreach(Player, cid)
			{
				if(cid != playerid && JoinEvent[cid] == EVENT_DRACE) SendClientMessage(cid,COLOR_DRACE,String);
			}
		}
		if (DRTimer > 180){SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к гонке на выживание, когда она еще не объявлена");}
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_DRACE)
	{
		JoinEvent[playerid] = 0; InEvent[playerid] = 0; SendClientMessage(playerid,COLOR_DRACE,"Вы покинули гонку на выживание.");
		LACSH[playerid] = 5;DRPlayers--;
		if (DRTimeToEnd > 0){ResetPlayerWeapons(playerid);LSpawnPlayer(playerid);}
		new String[120];
		format(String,sizeof(String),"%s[%d] покинул гонку на выживание.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_DRACE) SendClientMessage(cid,COLOR_DRACE,String);
		}
	}
	return 1;
}

if(!strcmp(cmd, "/radio", true))
{
	if (Player[playerid][Level] == 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Завершите обучение, прежде чем пользоваться радио!");
	new StringX[1024];
	strcat(StringX, "{FF0000}Выключить радио{FFFFFF}\nEuropa Plus\nMAKS FM\nSmoothJazz\nIDOBI RADIO: Alternative, Pop, Rock\n");
	strcat(StringX, "Radio Shanson\nCINEMIX (SoundTracks)\nDubbase.FM\nRadio Record\n");
	strcat(StringX, "Зайцев.FM | Pop\nЗайцев.FM | NewRock\nЗайцев.FM | Club\nЗайцев.FM | Disco\nЗайцев.FM | RnB\n");
	strcat(StringX, "Наше Радио");
	ShowPlayerDialog(playerid, 9, 2, "Радио", StringX, "ОК", "Отмена");
	return 1;
}


if(!strcmp(cmd, "/clan", true))
{//клан
	if (strlen(Player[playerid][MyClan]) == 0)
	{//если игрок не в клане
		if (Player[playerid][Level] < 20){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы сможете создать свой клан, когда достигнете 20-го уровня.");SendClientMessage(playerid,COLOR_RED,"Но вы можете вступить в любой клан без ограничений по уровню.");return 1;}
		ShowPlayerDialog(playerid, DIALOG_CLANCREATE, 0, "Создание клана", "{008E00}Вы не в клане. Но вы можете создать свой за 500 000$\n\n{FFFFFF}Вы хотите создать свой клан?", "Да", "Отмена");
	}//если игрок не в клане
	else
	{//игрок в клане
		new StringX[120], clanid = Player[playerid][MyClan], cNeedXP = Clan[clanid][cLevel] * 100000 + 100000;
		if (Clan[clanid][cXP] >= cNeedXP && Clan[clanid][cLevel] < 100) {Clan[clanid][cXP] -= cNeedXP; Clan[clanid][cLevel] += 1; SaveClan(clanid);}
		format(StringX,sizeof(StringX),"{008E00}Меню клана '{FFFFFF}%s{008E00}'",Clan[clanid][cName]);
		ShowPlayerDialog(playerid, DIALOG_CLANMENU, 2, StringX, "Информация о клане\nСостав клана\nУправление кланом\nОтношения с другими кланами\n{FF0000}Выйти из клана", "Ок", "Отмена");
	}//игрок в клане
	return 1;
}//клан


if(!strcmp(cmd, "/zombie", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_ZOMBIE && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в зомби-выживании");
	if (JoinEvent[playerid] == 0)
	{
		if (ZMTimer == -1){SendClientMessage(playerid,COLOR_RED,"Вы не можете присоединиться к зомби-выживанию, так как оно уже началось"); return 1;} 
		if (Player[playerid][LeaveZM] > 0){new String[120];format(String,sizeof String,"Вы сможете участвовать в зомби-выживании через %d минут.",Player[playerid][LeaveZM]/60 + 1);return SendClientMessage(playerid,COLOR_RED,String);}
		if (ZMTimer < 180)
		{
			if (ZMPlayers == ZMLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
			if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
			SendClientMessage(playerid,COLOR_ZOMBIE,"Вы присоединились к зомби-выживанию. Ждите старт..");
			JoinEvent[playerid] = EVENT_ZOMBIE; ZMStarted[playerid] = 0; ZMIsPlayerIsZombie[playerid] = 0; ZMIsPlayerIsTank[playerid] = 0;
			new String[120];
			ZMPlayers++;
			FarmedXP[playerid] = 0; FarmedMoney[playerid] = 0;
			format(String,sizeof(String),"%s[%d] присоединился к зомби-выживанию.", PlayerName[playerid], playerid);
			TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_ZOMBIE]);
			foreach(Player, cid)
			{
				if(cid != playerid && JoinEvent[cid] == EVENT_ZOMBIE) SendClientMessage(cid,COLOR_ZOMBIE,String);
			}	
		}
		if (ZMTimer > 180){SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к Зомби-Выживанию, когда оно еще не объявлено");}
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_ZOMBIE)
	{
		if (ZMTimeToEnd > 0) //Если зомби-выживание уже стартовало
			return ShowPlayerDialog(playerid, DIALOG_LEAVEZM, 0, "Покинуть зомби-выживание?", "{FF0000}Внимание! Покинув зомби-выживание вы подставите свою команду!\nВ следствие чего вам будет запрещено участвовать в зомби-выживании в течение получаса!\n\n{FFFFFF}Вы уверены, что хотите покинуть зомби-выживание?", "Да", "Отмена");
	
		JoinEvent[playerid] = 0; ZMStarted[playerid] = 0; InEvent[playerid] = 0; ZMIsPlayerIsZombie[playerid] = 0; ZMIsPlayerIsTank[playerid] = 0;
		SendClientMessage(playerid,COLOR_ZOMBIE,"Вы покинули Зомби-Выживание.");
		ZMPlayers--;
		new String[120]; format(String,sizeof(String),"%s[%d] покинул зомби-выживание.", PlayerName[playerid], playerid);
		foreach(Player, cid) if (cid != playerid && JoinEvent[cid] == EVENT_ZOMBIE) SendClientMessage(cid,COLOR_ZOMBIE,String);
	}
	return 1;
}



if(!strcmp(cmd, "/race", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_RACE && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в гонке");
	if (JoinEvent[playerid] == 0)
	{
		if (FRTimer <= -1){SendClientMessage(playerid,COLOR_RED,"Вы не можете присоединиться к гонке, так как она уже началась"); return 1;} 
		if (FRTimer > 180){SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к гонке, когда она еще не объявлена"); return 1;}
		if (FRPlayers == FRLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
		Player[playerid][CarActive] = 0; //Исправление бага с убернитро в гонке
		StopFly(playerid);StopVehFly(playerid);
		SetPlayerInterior(playerid,0);Player[playerid][CarActive] = 0;
		new Float: rx, Float: ry;
		if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
		SendClientMessage(playerid,COLOR_RACE,"Вы присоединились к гонке и были телепортированы на место старта. Займите позицию и ждите..");
		//DisableRemoteVehicleCollisions(playerid, 1);
		JoinEvent[playerid] = EVENT_RACE; FlipCount[playerid] = 3;
		SendClientMessage(playerid,COLOR_CYAN,"Подсказка: Нажмите клавишу {FFFFFF}Alt{00CCCC} чтобы вызвать транспорт в гонке.");
		ResetWeapons(playerid); SetPlayerVirtualWorld(playerid, 661);
		rx = random(20) - 10;ry = random(20) - 10;SpecUpdate(playerid);
		if (FRTimer <= 600 && FRStart == 1 && FRTimer > 1){SetPlayerCheckpoint(playerid,419.9553,2502.6494,17.2076, 15);SetPlayerPos(playerid,419.9553 + rx,2502.6494 + ry,17.2076);}
		if (FRTimer <= 600 && FRStart == 2 && FRTimer > 1){SetPlayerCheckpoint(playerid,-59.6410,2504.3281,17.2076, 15);SetPlayerPos(playerid,-59.6410 + rx,2504.3281 + ry,17.2076);}
		if (FRTimer <= 600 && FRStart == 3 && FRTimer > 1){SetPlayerCheckpoint(playerid,-716.3835,2322.8191,127.9989, 15);SetPlayerPos(playerid,-716.3835 + rx,2322.8191 + ry,127.9989);}
		if (FRTimer <= 600 && FRStart == 4 && FRTimer > 1){SetPlayerCheckpoint(playerid,-1113.1007,379.5110,14.8707, 15);SetPlayerPos(playerid,-1113.1007 + rx,379.5110 + ry,14.8707);}
		if (FRTimer <= 600 && FRStart == 5 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2318.7227,-1630.5919,484.4261, 15);SetPlayerPos(playerid,-2318.7227 + rx,-1630.5919 + ry,484.42);}
		if (FRTimer <= 600 && FRStart == 6 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2423.3645,-608.0591,133.2852, 15);SetPlayerPos(playerid,-2423.3645 + rx,-608.0591 + ry,133.2852);}
		if (FRTimer <= 600 && FRStart == 7 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2628.4731,1360.0398,7.8186, 15);SetPlayerPos(playerid,-2628.4731 + rx,1360.0398 + ry,7.8186);}
		if (FRTimer <= 600 && FRStart == 8 && FRTimer > 1){SetPlayerCheckpoint(playerid,822.8941,848.3994,11.9871, 15);SetPlayerPos(playerid,822.8941 + rx,848.3994 + ry,11.9871);}
		if (FRTimer <= 600 && FRStart == 9 && FRTimer > 1){SetPlayerCheckpoint(playerid,2455.8059,-1658.7832,12.8714, 15);SetPlayerPos(playerid,2455.8059 + rx,-1658.7832 + ry,12.8714);}
		if (FRTimer <= 600 && FRStart == 10 && FRTimer > 1){SetPlayerCheckpoint(playerid,2196.0867,-1642.7052,14.8736, 15);SetPlayerPos(playerid,2196.0867 + rx,-1642.7052 + ry,14.8736);}
		if (FRTimer <= 600 && FRStart == 11 && FRTimer > 1){SetPlayerCheckpoint(playerid,153.9650,-1938.4340,3.3319, 15);SetPlayerPos(playerid,153.9650 + rx,-1938.4340 + ry,3.3319);}
		if (FRTimer <= 600 && FRStart == 12 && FRTimer > 1){SetPlayerCheckpoint(playerid,2761.1501,-2453.0867,14.2697, 15);SetPlayerPos(playerid,2761.1501 + rx,-2453.0867 + ry,14.2697);}
		if (FRTimer <= 600 && FRStart == 13 && FRTimer > 1){SetPlayerCheckpoint(playerid,2031.7867,-2493.7588,13.2681, 15);SetPlayerPos(playerid,2031.7867 + rx,-2493.7588 + ry,13.2681);}
		if (FRTimer <= 600 && FRStart == 14 && FRTimer > 1){SetPlayerCheckpoint(playerid,1529.9385,-1675.8372,13.1099, 15);SetPlayerPos(playerid,1529.9385 + rx,-1675.8372 + ry,13.1099);}
		if (FRTimer <= 600 && FRStart == 15 && FRTimer > 1){SetPlayerCheckpoint(playerid,2171.5645,1683.1047,10.3822, 15);SetPlayerPos(playerid,2171.5645 + rx,1683.1047 + ry,10.3822);}
		if (FRTimer <= 600 && FRStart == 16 && FRTimer > 1){SetPlayerCheckpoint(playerid,1517.9435,2231.4575,10.3948, 15);SetPlayerPos(playerid,1517.9435 + rx,2231.4575 + ry,10.3948);}
		if (FRTimer <= 600 && FRStart == 17 && FRTimer > 1){SetPlayerCheckpoint(playerid,2628.7495,2299.8401,10.3120, 15);SetPlayerPos(playerid,2628.7495 + rx,2299.8401 + ry,10.3120);}
		if (FRTimer <= 600 && FRStart == 18 && FRTimer > 1){SetPlayerCheckpoint(playerid,2343.8784,319.6856,32.3911, 15);SetPlayerPos(playerid,2343.8784 + rx,319.6856 + ry,32.3911);}
		if (FRTimer <= 600 && FRStart == 19 && FRTimer > 1){SetPlayerCheckpoint(playerid,-25.7401,-299.4633,5.1533, 15);SetPlayerPos(playerid,-25.7401 + rx,-299.4633 + ry,5.1533);}
		if (FRTimer <= 600 && FRStart == 20 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2006.8792,-71.4555,35.1719, 15);SetPlayerPos(playerid,-2006.8792 + rx,-71.4555 + ry,35.1719);}
		if (FRTimer <= 600 && FRStart == 21 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2604.4465,566.0416,14.1875, 15);SetPlayerPos(playerid,-2604.4465 + rx,566.0416 + ry,14.1875);}
		if (FRTimer <= 600 && FRStart == 22 && FRTimer > 1){SetPlayerCheckpoint(playerid,-1260.5172,457.8165,6.9146, 15);SetPlayerPos(playerid,-1260.5172 + rx,457.8165 + ry,6.9146);}
		if (FRTimer <= 600 && FRStart == 23 && FRTimer > 1){SetPlayerCheckpoint(playerid,836.0139,-2051.3135,12.4215, 15);SetPlayerPos(playerid,836.0139 + rx,-2051.3135 + ry,12.4215);}
		if (FRTimer <= 600 && FRStart == 24 && FRTimer > 1){SetPlayerCheckpoint(playerid,1797.6271,843.2887,10.3677, 15);SetPlayerPos(playerid,1797.6271 + rx,843.2887 + ry,10.3677);}
		if (FRTimer <= 600 && FRStart == 25 && FRTimer > 1){SetPlayerCheckpoint(playerid,2826.7703,1354.3590,10.3259, 15);SetPlayerPos(playerid,2826.7703 + rx,1354.3590 + ry,10.3259);}
		if (FRTimer <= 600 && FRStart == 26 && FRTimer > 1){SetPlayerCheckpoint(playerid,2469.8474,2773.4763,10.2574, 15);SetPlayerPos(playerid,2469.8474 + rx,2773.4763 + ry,10.2574);}
		if (FRTimer <= 600 && FRStart == 27 && FRTimer > 1){SetPlayerCheckpoint(playerid,135.4260,1967.8726,19.2429, 15);SetPlayerPos(playerid,135.4260 + rx,1967.8726 + ry,19.2429);}
		if (FRTimer <= 600 && FRStart == 28 && FRTimer > 1){SetPlayerCheckpoint(playerid,1057.1550,1753.6602,10.5474, 15);SetPlayerPos(playerid,1057.1550 + rx,1753.6602 + ry,10.5474);}
		if (FRTimer <= 600 && FRStart == 29 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2262.1436,2311.0701,5.5402, 15);SetPlayerPos(playerid,-2262.1436 + rx,2311.0701 + ry,5.5402);}
		if (FRTimer <= 600 && FRStart == 30 && FRTimer > 1){SetPlayerCheckpoint(playerid,2831.4766,-1771.9731,10.4509, 15);SetPlayerPos(playerid,2831.4766 + rx,-1771.9731 + ry,10.4509);}
		if (FRTimer <= 600 && FRStart == 31 && FRTimer > 1){SetPlayerCheckpoint(playerid,1263.6404,-2033.9982,59.0424, 15);SetPlayerPos(playerid,1263.6404 + rx,-2033.9982 + ry,59.0424);}
		if (FRTimer <= 600 && FRStart == 32 && FRTimer > 1){SetPlayerCheckpoint(playerid,-1020.1862,-648.5829,31.7349, 15);SetPlayerPos(playerid,-1020.1862 + rx,-648.5829 + ry,31.7349);}
		if (FRTimer <= 600 && FRStart == 33 && FRTimer > 1){SetPlayerCheckpoint(playerid,-490.1095,-528.8505,25.2436, 15);SetPlayerPos(playerid,-490.1095 + rx,-528.8505 + ry,25.2436);}
		if (FRTimer <= 600 && FRStart == 34 && FRTimer > 1){SetPlayerCheckpoint(playerid,1426.4532,-2286.4304,13.1099, 15);SetPlayerPos(playerid,1426.4532 + rx,-2286.4304 + ry,13.1099);}
		if (FRTimer <= 600 && FRStart == 35 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2146.5259,-2411.5569,30.2014, 15);SetPlayerPos(playerid,-2146.5259 + rx,-2411.5569 + ry,30.2014);}
		if (FRTimer <= 600 && FRStart == 36 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2134.3315,-413.9892,35.0630, 15);SetPlayerPos(playerid,-2134.3315 + rx,-413.9892 + ry,35.0630);}
		if (FRTimer <= 600 && FRStart == 37 && FRTimer > 1){SetPlayerCheckpoint(playerid,-1982.8717,845.4196,45.0240, 15);SetPlayerPos(playerid,-1982.8717 + rx,845.4196 + ry,45.0240);}
		if (FRTimer <= 600 && FRStart == 38 && FRTimer > 1){SetPlayerCheckpoint(playerid,-2004.1323,1076.3872,55.1300, 15);SetPlayerPos(playerid,-2004.1323 + rx,1076.3872 + ry,55.13);}
		if (FRTimer <= 600 && FRStart == 39 && FRTimer > 1){SetPlayerCheckpoint(playerid,1477.4835,1797.2253,10.5396, 15);SetPlayerPos(playerid,1477.4835 + rx,1797.2253 + ry,10.5396);}
		if (FRTimer <= 600 && FRStart == 40 && FRTimer > 1){SetPlayerCheckpoint(playerid,-711.4286,2062.5952,60.1099, 15);SetPlayerPos(playerid,-711.4286 + rx,2062.5952 + ry,60.1099);}	
		
		TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_RACE]);
		new String[140];
		format(String,sizeof(String),"%s[%d] присоединился к гонке.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_RACE) SendClientMessage(cid,COLOR_RACE,String);
		}	
		
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_RACE)
	{
		DestroyVehicle(FRCarID[playerid]);
		LACSH[playerid] = 5;FRPlayers--;
		JoinEvent[playerid] = 0; FRStarted[playerid] = 0; InEvent[playerid] = 0;
		SendClientMessage(playerid,COLOR_RACE,"Вы покинули гонку.");
		//DisableRemoteVehicleCollisions(playerid, 0);
		SetPlayerVirtualWorld(playerid,0);LSpawnPlayer(playerid);
		DisablePlayerCheckpoint(playerid);
		new String[120];
		format(String,sizeof(String),"%s[%d] покинул гонку.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_RACE) SendClientMessage(cid,COLOR_RACE,String);
		}	
	}
	return 1;
}

if(!strcmp(cmd, "/xrace", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_XRACE && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в легендарной гонке");
	if (JoinEvent[playerid] == 0)
	{
		if (XRTimer <= 1){SendClientMessage(playerid,COLOR_RED,"Вы не можете присоединиться к легендарной гонке, так как она уже началась"); return 1;} 
		if (XRTimer > 180){SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к легендарной гонке, когда она еще не объявлена"); return 1;}
		if (XRPlayers == XRLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
		Player[playerid][CarActive] = 0; //Исправление бага с убернитро в гонке
		StopFly(playerid);StopVehFly(playerid);ResetPlayerWeapons(playerid);
		SetPlayerInterior(playerid,0);Player[playerid][CarActive] = 0;
		new Float: rx, Float: ry; XRPlayers++;
		if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
		SendClientMessage(playerid,COLOR_XR,"Вы присоединились к легендарной гонке и были телепортированы на место старта. Займите позицию и ждите.."); 
		JoinEvent[playerid] = EVENT_XRACE; XRStarted[playerid] = 0;	FlipCount[playerid] = 3;
		SendClientMessage(playerid,COLOR_CYAN,"Подсказка: Нажмите клавишу {FFFFFF}Alt{00CCCC} чтобы вызвать транспорт в гонке.");
		//DisableRemoteVehicleCollisions(playerid, 1);
		ResetPlayerWeapons(playerid);SetPlayerVirtualWorld(playerid, 700);
		rx = random(20) - 10;ry = random(20) - 10;SpecUpdate(playerid);
		
		if (XRid == 1){XRPlayerCar[playerid] = 448;SetPlayerRaceCheckpoint(playerid,2,XRACE1[0][0],XRACE1[0][1],XRACE1[0][2],XRACE1[1][0],XRACE1[1][1],XRACE1[1][2],15);SetPlayerPos(playerid,1707.9244 + rx,-488.0639 + ry,33.2454);SetPlayerFacingAngle(playerid,0);}
		if (XRid == 2){XRPlayerCar[playerid] = 473;SetPlayerRaceCheckpoint(playerid,2,XRACE2[0][0],XRACE2[0][1],XRACE2[0][2],XRACE2[1][0],XRACE2[1][1],XRACE2[1][2],15);SetPlayerPos(playerid,-704.0422 + rx,1948.8749 + ry,1.0);SetPlayerFacingAngle(playerid,193);}
		if (XRid == 3){XRPlayerCar[playerid] = 461;SetPlayerRaceCheckpoint(playerid,2,XRACE3[0][0],XRACE3[0][1],XRACE3[0][2],XRACE3[1][0],XRACE3[1][1],XRACE3[1][2],15);SetPlayerPos(playerid,1451.7262 + rx,-2494.0071 + ry,13.1204);SetPlayerFacingAngle(playerid,270);}
		if (XRid == 4){XRPlayerCar[playerid] = 541;SetPlayerRaceCheckpoint(playerid,2,XRACE4[0][0],XRACE4[0][1],XRACE4[0][2],XRACE4[1][0],XRACE4[1][1],XRACE4[1][2],15);SetPlayerPos(playerid,2471.3347 + rx,-1658.8896 + ry,13.0208);SetPlayerFacingAngle(playerid,90);}
		if (XRid == 5){XRPlayerCar[playerid] = 471;SetPlayerRaceCheckpoint(playerid,2,XRACE5[0][0],XRACE5[0][1],XRACE5[0][2],XRACE5[1][0],XRACE5[1][1],XRACE5[1][2],15);SetPlayerPos(playerid,2798.4011 + rx,1313.5854 + ry,10.4349);SetPlayerFacingAngle(playerid,90);}
		if (XRid == 6){XRPlayerCar[playerid] = 441;SetPlayerRaceCheckpoint(playerid,2,XRACE6[0][0],XRACE6[0][1],XRACE6[0][2],XRACE6[1][0],XRACE6[1][1],XRACE6[1][2],15);SetPlayerPos(playerid,2026.8115 + rx,2147.6819 + ry,10.4415);SetPlayerFacingAngle(playerid,211);}
		if (XRid == 7){XRPlayerCar[playerid] = 461;SetPlayerRaceCheckpoint(playerid,2,XRACE7[0][0],XRACE7[0][1],XRACE7[0][2],XRACE7[1][0],XRACE7[1][1],XRACE7[1][2],15);SetPlayerPos(playerid,407.7658 + rx,2502.2483 + ry,16.1055);SetPlayerFacingAngle(playerid,90);}
		if (XRid == 8){XRPlayerCar[playerid] = 471;SetPlayerRaceCheckpoint(playerid,2,XRACE8[0][0],XRACE8[0][1],XRACE8[0][2],XRACE8[1][0],XRACE8[1][1],XRACE8[1][2],15);SetPlayerPos(playerid,-2323.7883 + rx,-1625.2687 + ry,483.3277);SetPlayerFacingAngle(playerid,211);}
		if (XRid == 9){XRPlayerCar[playerid] = 521;SetPlayerRaceCheckpoint(playerid,2,XRACE9[0][0],XRACE9[0][1],XRACE9[0][2],XRACE9[1][0],XRACE9[1][1],XRACE9[1][2],15);SetPlayerPos(playerid,2380.6506 + rx,-2275.0532 + ry,5.6841);SetPlayerFacingAngle(playerid,45);}
		if (XRid == 10){XRPlayerCar[playerid] = 509;SetPlayerRaceCheckpoint(playerid,2,XRACE10[0][0],XRACE10[0][1],XRACE10[0][2],XRACE10[1][0],XRACE10[1][1],XRACE10[1][2],15);SetPlayerPos(playerid,-2004.1439 + rx,1049.2727 + ry,55.1882);SetPlayerFacingAngle(playerid,180);}
		if (XRid == 11){XRPlayerCar[playerid] = 468;SetPlayerRaceCheckpoint(playerid,2,XRACE11[0][0],XRACE11[0][1],XRACE11[0][2],XRACE11[1][0],XRACE11[1][1],XRACE11[1][2],15);SetPlayerPos(playerid,-2392.6331 + rx,-2203.5129 + ry,33.0);SetPlayerFacingAngle(playerid,294);}
		if (XRid == 12){XRPlayerCar[playerid] = 522;SetPlayerRaceCheckpoint(playerid,2,XRACE12[0][0],XRACE12[0][1],XRACE12[0][2],XRACE12[1][0],XRACE12[1][1],XRACE12[1][2],15);SetPlayerPos(playerid,-1136.9459 + rx,1091.7295 + ry,39.0);SetPlayerFacingAngle(playerid,135);}
		if (XRid == 13){XRPlayerCar[playerid] = 461;SetPlayerRaceCheckpoint(playerid,2,XRACE13[0][0],XRACE13[0][1],XRACE13[0][2],XRACE13[1][0],XRACE13[1][1],XRACE13[1][2],15);SetPlayerPos(playerid,380.2271 + rx,-1716.8245 + ry,8.0);SetPlayerFacingAngle(playerid,270);}
		if (XRid == 14){XRPlayerCar[playerid] = 471;SetPlayerRaceCheckpoint(playerid,2,XRACE14[0][0],XRACE14[0][1],XRACE14[0][2],XRACE14[1][0],XRACE14[1][1],XRACE14[1][2],15);SetPlayerPos(playerid,1477.7278 + rx,1814.1685 + ry,11.0);SetPlayerFacingAngle(playerid,180);}
		if (XRid == 15){XRPlayerCar[playerid] = 510;SetPlayerRaceCheckpoint(playerid,2,XRACE15[0][0],XRACE15[0][1],XRACE15[0][2],XRACE15[1][0],XRACE15[1][1],XRACE15[1][2],15);SetPlayerPos(playerid,-2404.5793 + rx,-597.2061 + ry,133.0);SetPlayerFacingAngle(playerid,124.3816);}
		if (XRid == 16){XRPlayerCar[playerid] = 468;SetPlayerRaceCheckpoint(playerid,2,XRACE16[0][0],XRACE16[0][1],XRACE16[0][2],XRACE16[1][0],XRACE16[1][1],XRACE16[1][2],15);SetPlayerPos(playerid,-1887.9729 + rx,-1711.1455 + ry,22.0);SetPlayerFacingAngle(playerid,142.1913);}
		if (XRid == 17){XRPlayerCar[playerid] = 481;SetPlayerRaceCheckpoint(playerid,2,XRACE17[0][0],XRACE17[0][1],XRACE17[0][2],XRACE17[1][0],XRACE17[1][1],XRACE17[1][2],15);SetPlayerPos(playerid,-369.9781 + rx,2180.2761 + ry,42.0);SetPlayerFacingAngle(playerid,14);}
		if (XRid == 18){XRPlayerCar[playerid] = 468;SetPlayerRaceCheckpoint(playerid,2,XRACE18[0][0],XRACE18[0][1],XRACE18[0][2],XRACE18[1][0],XRACE18[1][1],XRACE18[1][2],15);SetPlayerPos(playerid,1559.5736 + rx,18.0319 + ry,24.5);SetPlayerFacingAngle(playerid,180);}
		if (XRid == 19){XRPlayerCar[playerid] = 571;SetPlayerRaceCheckpoint(playerid,2,XRACE19[0][0],XRACE19[0][1],XRACE19[0][2],XRACE19[1][0],XRACE19[1][1],XRACE19[1][2],15);SetPlayerPos(playerid,1655.3647 + rx,292.3838 + ry,21.2);SetPlayerFacingAngle(playerid,255);}
		if (XRid == 20){XRPlayerCar[playerid] = 522;SetPlayerRaceCheckpoint(playerid,2,XRACE20[0][0],XRACE20[0][1],XRACE20[0][2],XRACE20[1][0],XRACE20[1][1],XRACE20[1][2],15);SetPlayerPos(playerid,-1103.8287 + rx,388.9995 + ry,14.2);SetPlayerFacingAngle(playerid,135);}
		SetCameraBehindPlayer(playerid);
	
		TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_XRACE]);
		if (XRid == 17 || XRid == 7) SendClientMessage(playerid,COLOR_CYAN,"Подсказка: Отпускайте клавишу газа на опасных участках трассы!");
		new String[120];
		format(String,sizeof(String),"%s[%d] присоединился к легендарной гонке.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_XRACE) SendClientMessage(cid,COLOR_XR,String);
		}

		return 1;
	}
	if (JoinEvent[playerid] == EVENT_XRACE)
	{
		DestroyVehicle(XRCarID[playerid]);XRCarID[playerid] = 0;
		LACSH[playerid] = 5;XRPlayers--;
		JoinEvent[playerid] = 0; XRStarted[playerid] = 0; InEvent[playerid] = 0;
		SendClientMessage(playerid,COLOR_XR,"Вы покинули легендарную гонку.");
		SetPlayerVirtualWorld(playerid,0);LSpawnPlayer(playerid);
		//DisableRemoteVehicleCollisions(playerid, 0);
		DisablePlayerRaceCheckpoint(playerid);
		new String[120];
		format(String,sizeof(String),"%s[%d] покинул легендарную гонку.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_XRACE) SendClientMessage(cid,COLOR_XR,String);
		}	
	}
	return 1;
}

if(!strcmp(cmd, "/gungame", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_GUNGAME && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в гонке вооружений");
	if (JoinEvent[playerid] == 0)
	{
		if (GGTimer < 180 || GGTimeToEnd > 0)
		{
			if (GGPlayers == GGLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
			if (LeaveGG[playerid]-unixtime > 0) return SendClientMessage(playerid, COLOR_RED, "Вы только что покинули гонку вооружений! Пожалуйста, подождите несколько секунд...");
			if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
			if (GGTimeToEnd <= 0) SendClientMessage(playerid,COLOR_GG,"Вы присоединились к Гонке Вооружений. Ждите старт..");
			JoinEvent[playerid] = EVENT_GUNGAME; GGPlayers++;
			new String[120];
			format(String,sizeof(String),"%s[%d] присоединился к гонке вооружений.", PlayerName[playerid], playerid);
			foreach(Player, cid)
			{
				if(cid != playerid && JoinEvent[cid] == EVENT_GUNGAME) SendClientMessage(cid,COLOR_GG,String);
			}	
			if (GGTimeToEnd > 0) 
			{//Если гангейм уже начался
				OnStartEvent[playerid] = 5; InEvent[playerid] = EVENT_GUNGAME; LSpawnPlayer(playerid); FarmedXP[playerid] = 0;
				SendClientMessage(playerid,COLOR_GG,"Вы присоединились к Гонке Вооружений.");
			}//Если гангейм уже начался
			else TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_GUNGAME]);
		}
		else SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к Гонке Вооружений, когда она еще не объявлена");
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_GUNGAME)
	{
		JoinEvent[playerid] = 0; InEvent[playerid] = 0; SendClientMessage(playerid,COLOR_GG,"Вы покинули Гонку Вооружений."); GGPlayers--;
		if (GGTimeToEnd > 0){SetPlayerVirtualWorld(playerid,0);ResetPlayerWeapons(playerid);LSpawnPlayer(playerid); LeaveGG[playerid] = unixtime+15;}
		new String[120];
		format(String,sizeof(String),"%s[%d] покинул гонку вооружений.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_GUNGAME) SendClientMessage(cid,COLOR_GG,String);
		}	
	}
	return 1;
}
/*
if(!strcmp(cmd, "/flag", true))
{
	if (Logged[playerid] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны авторизироваться, чтобы использовать эту команду");return 1;}
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_FLAG && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в CTF!");
	if (JoinEvent[playerid] == 0)
	{
		if (FTimer > 180) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы не можете присоединиться к CTF, когда он еще не объявлен");
		if (FTimer == -1){SendClientMessage(playerid,COLOR_RED,"Вы не можете присоединиться к CTF, так как оно уже началось"); return 1;}
		if (FPlayers == FLimit) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");
		if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "");
		if (FTimeToEnd <= 0) SendClientMessage(playerid,COLOR_FLAG,"Вы присоединились к CTF. Ждите старт..");
		JoinEvent[playerid] = EVENT_FLAG; FPlayers++;
		new String[120];
		format(String,sizeof(String),"%s[%d] присоединился к CTF.", GetName(playerid), playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_FLAG) SendClientMessage(cid,COLOR_FLAG,String);
		}
		//if (FTimeToEnd > 0)
		//{//Если уже начался
		//	OnStartEvent[playerid] = 5; InEvent[playerid] = EVENT_FLAG; LSpawnPlayer(playerid);
		//	SendClientMessage(playerid,COLOR_DM,"Вы присоединились к десматчу.");
		//}//Если уже начался
		TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_FLAG]);
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_FLAG)
	{
		JoinEvent[playerid] = 0; InEvent[playerid] = 0; SendClientMessage(playerid,COLOR_DM,"Вы покинули CTF.");
		if (FTimeToEnd > 0){ResetPlayerWeapons(playerid);LSpawnPlayer(playerid);}
		FPlayers--;
		//if (FTimeToEnd > 0) LeaveDM[playerid] = 15;
		new pname[25], String[120];GetPlayerName(playerid, pname, sizeof(pname));
		format(String,sizeof(String),"%s[%d] покинул CTF.", pname, playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[playerid] == EVENT_FLAG) SendClientMessage(cid,COLOR_DM,String);
		}
	}
	return 1;
}
*/

if(!strcmp(cmd, "/flag", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_FLAG && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в битве!");
	if (JoinEvent[playerid] == 0)
	{
		if (FTimer < 180 && FTimer > 0)
		{
			if (FPlayers == FLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
			if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "",1);
			JoinEvent[playerid] = EVENT_FLAG; SendClientMessage(playerid,COLOR_FLAG,"Вы присоединились к битве за флаг. Ждите старт..");
			FarmedXP[playerid] = 0; FarmedMoney[playerid] = 0;
			new String[120];
			FPlayers++;
			format(String,sizeof(String),"%s[%d] присоединился к битве за флаг.", PlayerName[playerid], playerid);
			TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_FLAG]);
			foreach(Player, cid)
			{
				if(cid != playerid && JoinEvent[cid] == EVENT_FLAG) SendClientMessage(cid,COLOR_FLAG,String);
			}
		}
		if (FTimer > 180){SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к битве за флаг, когда она еще не объявлена");}
		return 1;
	}
	if (JoinEvent[playerid] == EVENT_FLAG)
	{
		if (FTimeToEnd > 0) //Если зомби-выживание уже стартовало
			return ShowPlayerDialog(playerid, DIALOG_LEAVEF, 0, "Покинуть битву?", "{FF0000}Внимание! Покинув битву вы подставите свою команду!\n\n{FFFFFF}Вы уверены, что хотите покинуть битву?", "Да", "Отмена");

		JoinEvent[playerid] = 0; FStarted[playerid] = 0; InEvent[playerid] = 0;
		SendClientMessage(playerid,COLOR_FLAG,"Вы покинули битву за флаг.");
		FPlayers--;
		new String[120]; format(String,sizeof(String),"%s[%d] покинул битву за флаг.", PlayerName[playerid], playerid);
		foreach(Player, cid) if (cid != playerid && JoinEvent[cid] == EVENT_FLAG) SendClientMessage(cid,COLOR_FLAG,String);
	}
	return 1;
}

if(!strcmp(cmd, "/park", true))
{
	if (Player[playerid][Banned] != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам запрещено участвовать в соревнованиях, так как вы забанены! Купить разбан можно в {FFFFFF}/shop");
	if (Player[playerid][Level] == 0){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Пройдите обучение прежде чем участвовать в соревнованиях!");return 1;}
	if (JoinEvent[playerid] != EVENT_PARK && JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Вы должны выйти из других соревнований, чтобы участвовать в паркуре");
	if (JoinEvent[playerid] == 0)
	{
		if (PRTimer <= -1){SendClientMessage(playerid,COLOR_RED,"Вы не можете присоединиться к паркуру, так как он уже начался"); return 1;}
		if (PRTimer > 180){SendClientMessage(playerid,COLOR_RED,"Ошибка: Вы не можете присоединиться к паркуру, когда он еще не объявлен"); return 1;}
		if (PRPlayers == PRLimit){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В этом соревновании превышен лимит игроков");return 1;}
		//Player[playerid][CarActive] = 0; //Исправление бага с убернитро в гонке
		
		//StopFly(playerid);StopVehFly(playerid);
		//SetPlayerInterior(playerid,0);Player[playerid][CarActive] = 0;
		//new Float: rx, Float: ry;
		//if (LSpecID[playerid] != -1) SendCommand(playerid, "/specoff", "");
		SendClientMessage(playerid,COLOR_PARK,"Вы присоединились к паркуру! Ожидайте начала соревнования..");
		JoinEvent[playerid] = EVENT_PARK;

		TextDrawShowForPlayer(playerid, TextDrawEvent[EVENT_PARK]);
		new String[140];
		format(String,sizeof(String),"%s[%d] присоединился к паркуру.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_PARK) SendClientMessage(cid,COLOR_PARK,String);
		}

		return 1;
	}
	if (JoinEvent[playerid] == EVENT_PARK)
	{
		PRPlayers--;
		JoinEvent[playerid] = 0; PRStarted[playerid] = 0; InEvent[playerid] = 0;
		if (PRTimeToEnd > 0)
		{
			SetPlayerVirtualWorld(playerid,0);
			ResetPlayerWeapons(playerid);
			LSpawnPlayer(playerid);
			DestroyDynamicPickup(PRPickup[playerid]);
		}
		SendClientMessage(playerid,COLOR_PARK,"Вы покинули паркур.");
		new String[120];
		format(String,sizeof(String),"%s[%d] покинул паркур.", PlayerName[playerid], playerid);
		foreach(Player, cid)
		{
			if(cid != playerid && JoinEvent[cid] == EVENT_PARK) SendClientMessage(cid,COLOR_PARK,String);
		}
	}
	return 1;
}

/*if(!strcmp(cmd, "/admins", true))
{
	new String[120], StringX[1024], onl = 0;
	foreach(Player, cid)
	{//цикл
	    if (Player[cid][Admin] > 0 && Player[cid][Admin] < 5)
	    {
	        format(String,sizeof(String),"%s%s: %s[%d]\n",AdminInfo[Player[cid][Admin]][StrColor],AdminInfo[Player[cid][Admin]][StatName],PlayerName[cid], cid);
	        strcat(StringX,String);
			onl=1;
		}
	}

	if (onl == 0) strcat(StringX,"На сервере нет администраторов.");
	ShowPlayerDialog(playerid, 999, 0, "Администраторы онлайн", StringX, "ОК", "");
	return 1;
}*/

if(!strcmp(cmd, "/admins", true))
{
	new String[120], StringX[1024], onl = 0;
	foreach(Player, cid)
	{//цикл
		if (Player[cid][Admin] == 4)
		{
			format(String,sizeof(String),"{FF7F50}Главный Администратор: %s[%d]\n",PlayerName[cid], cid);
			strcat(StringX,String);
			onl++;
		}
	}//цикл
	foreach(Player, cid)
	{//цикл
		if (Player[cid][Admin] == 3)
		{
			format(String,sizeof(String),"{00BFFF}Администратор: %s[%d]\n",PlayerName[cid], cid);
			strcat(StringX,String);
			onl++;
		}
	}//цикл
	foreach(Player, cid)
	{//цикл
		if (Player[cid][Admin] == 2)
		{
			format(String,sizeof(String),"{7EFE6D}Супер-Модератор: %s[%d]\n",PlayerName[cid], cid);
			strcat(StringX,String);
			onl++;
		}
	}//цикл
	foreach(Player, cid)
	{//цикл
		if (Player[cid][Admin] == 1)
		{
			format(String,sizeof(String),"{03FDAA}Модератор: %s[%d]\n",PlayerName[cid], cid);
			strcat(StringX,String);
			onl++;
		}
	}//цикл
	if (onl == 0) strcat(StringX,"На сервере нет администраторов.");
	ShowPlayerDialog(playerid, 999, 0, "Администраторы онлайн", StringX, "ОК", "");
	return 1;
}


if(!strcmp(cmd, "/myskin", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Level] < 52){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 52-го уровня, чтобы использовать эту команду");return 1;}
	//ShowModelSelectionMenuEx(playerid, items_array[], item_amount, header_text[], extraid, Float:Xrot = 0.0, Float:Yrot = 0.0, Float:Zrot = 0.0, Float:mZoom = 1.0, dialogBGcolor = 0x4A5A6BBB, previewBGcolor = 0x88888899 , tdSelectionColor = 0xFFFF00AA)
	ShowModelSelectionMenu(playerid, MenuMyskin, "MySkin");
	return 1;
}

if(!strcmp(cmd, "/myskinid", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Level] < 52){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 52-го уровня, чтобы использовать эту команду");return 1;}
	new skinid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", skinid))//занесем значение которе ввел игрок в переменую skinid 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /myskinid [id модели] (от 0 до 311)");//если игрок не ввел значение то выдаем собщение 
	if (skinid < 0 || skinid > 311){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /myskinid [id модели] (от 0 до 311)"); return 1;} 
	Player[playerid][Model] = skinid;SetPlayerSkin(playerid,skinid);//меняем игроку скин на который он выбрал
	SendClientMessage(playerid, COLOR_YELLOW, "Модель персонажа успешно изменена"); 
	return 1;
}

if(!strcmp(cmd, "/shop", true))
{
	ShowShopDialog(playerid);
	return 1;
}

if(!strcmp(cmd, "/mytime", true))
{
	new x;new string[120];
	if (Player[playerid][Level] < 25){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 25-го уровня"); return 1;}
	if(sscanf(params,"d", x))//занесем значение которе ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /mytime [часов] ('{FFFFFF}-1{FF0000}' для реального времени)");//если игрок не ввел значение то выдаем собщение 
	if (x < -1 || x > 23)return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /mytime [часов] ('{FFFFFF}-1{FF0000}' для реального времени)");
	PlayerTime[playerid] = x;
	format(string, sizeof(string), "SERVER: Вы поменяли игровое время на %d:00.", PlayerTime[playerid]);
	if (x != -1){SendClientMessage(playerid, COLOR_YELLOW, string);}else{SendClientMessage(playerid,COLOR_YELLOW,"SERVER: Установлено реальное время.");}
	return 1;
}

if(!strcmp(cmd, "/prestige", true))
{
	if (Player[playerid][Prestige] >= 10) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: У вас максимальный уровень Престижа!");
	if (Player[playerid][Level] < 100) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть 100-го уровня");
	if (Player[playerid][Medals] < 10) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нужно 10 медалей, чтобы повысить уровень Престижа! Смотри {FFFFFF}/quests");
	return ShowPlayerDialog(playerid,DIALOG_PRESTIGE,0,"Престиж","{FF0000}Внимание!{AFAFAF} При повышении {FFFF00}Престижа{AFAFAF} вы будет понижены до 1-го уровня!\nВы также потеряете все навыки, оружие и транспорт!\n{FF0000}ОБРАТНОЙ ДОРОГИ НЕ БУДЕТ!\n\n{AFAFAF}Вы уверены, что хотите повысить уровень {FFFF00}Престижа{AFAFAF}?","Да","Нет");
}

if(!strcmp(cmd, "/eject", true))
{//команды надо вводить без "/" 
	new ejid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", ejid))//занесем значение которе ввел игрок в переменую skinid 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /eject [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(ejid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	new String[120], iSeat = GetPlayerVehicleSeat(playerid), vid = GetPlayerVehicleID(playerid);
	if(!IsPlayerInAnyVehicle(playerid) || iSeat != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны находиться за рулем транспорта");
	if(!IsPlayerInVehicle(ejid, vid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрок не находится в вашем транспорте");
	if (playerid == ejid) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя выбрасывать самого себя");
	RemovePlayerFromVehicle(ejid);
	format(String,sizeof(String),"Игрок %s[%d] выбросил вас из машины",PlayerName[playerid],playerid);SendClientMessage(ejid,COLOR_RED,String);
	format(String,sizeof(String),"Вы выбросили игрока %s[%d] из машины",PlayerName[ejid],ejid);SendClientMessage(playerid,COLOR_YELLOW,String);
	return 1;
}

if(!strcmp(cmd, "/specp", true))
{//команды надо вводить без "/"
	if (Player[playerid][Prestige] < 6 && Player[playerid][Admin] == 0){return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 6-го уровня Престижа");}
	if (Player[playerid][Admin] == 0 && GetPlayerInterior(playerid) == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть в доме, банке или в казино, чтобы включить режим слежки.");
	new specplayerid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", specplayerid))//занесем значение которе ввел игрок в переменую skinid 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /specp [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(specplayerid)){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); return 1;} 
	if (LSpecID[specplayerid] > -1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Этот игрок сам находится в режиме слежки.");
	if (JoinEvent[playerid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя войти в режим слежки, когда вы присоединились к соревнованиям.");
	if(Player[playerid][Admin] < 4)
	{
		new stext[140];
		format(stext, sizeof(stext), "SPECTATE: %s(%d) начал следить за %s(%d).", PlayerName[playerid], playerid,PlayerName[specplayerid],specplayerid);
		foreach(Player, cid) if (Player[cid][Admin] > 0 && Logged[cid] == 1){SendClientMessage(cid, 0xafafafFF, stext);}
	}
	TogglePlayerSpectating(playerid, 1);
	Player[playerid][CarActive] = 0;
	if (LSpecID[playerid] == -1) SetTimerEx("SpecTextDrawPub" , 500, false, "i", playerid);//Запускаем таймер обновления слежки если ДО этого игрок был не в слежке
	LSpecID[playerid] = specplayerid;
	LSpectators[specplayerid]++;
	LSpecMode[playerid] = 0;
	SetPlayerInterior(playerid,GetPlayerInterior(specplayerid));	
	SetPlayerVirtualWorld(playerid,GetPlayerVirtualWorld(specplayerid));	
	if (IsPlayerInAnyVehicle(specplayerid)) PlayerSpectateVehicle(playerid, GetPlayerVehicleID(specplayerid));
	else PlayerSpectatePlayer(playerid, specplayerid);
	SendClientMessage(playerid, COLOR_CYAN, "Подсказка: {FFFFFF}Правая{00CCCC} и {FFFFFF}левая{00CCCC} кнопки мыши - быстрая смена подозреваемых.");
	SendClientMessage(playerid, COLOR_CYAN, "Подсказка: {FFFFFF}Левый Shift{00CCCC} - выйти из режима слежки.");
	return 1;
} 


if(!strcmp(cmd, "/specoff", true))
{//команды надо вводить без "/"
	if (LSpecID[playerid] == -1) return 1;
	TogglePlayerSpectating(playerid, 0);
	LSpecID[playerid] = -1; PlayerWeather[playerid] = -1; LSpawnPlayer(playerid);
	return 1;
}


if(!strcmp(cmd, "/karma", true)){ShowKarma(playerid);return  1;}


if(!strcmp(cmd, "/pvp", true))
{
	if (JoinEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы не можете принять вызов на дуэль так как присоединены к соревнованиям.");
	if (CanStartPVP[playerid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Никто не вызывал вас на дуэль либо время действия приглашения истекло.");
	new inviter = PlayerPVP[playerid][Invite];
	if(Player[playerid][Cash] < PlayerPVP[inviter][Stavka] || Player[inviter][Cash] < PlayerPVP[inviter][Stavka])
	{
		SendClientMessage(playerid, COLOR_RED,"{FF9E27}PVP: {AFAFAF}Недостаточно денег для ставки у вас или у вашего соперника!");
		SendClientMessage(inviter, COLOR_RED,"{FF9E27}PVP: {AFAFAF}Недостаточно денег для ставки у вас или у вашего соперника!");
		return 1;
	}
	if (PlayerPVP[inviter][Invite] == playerid)
	{
	    PlayerPVP[playerid][Stavka] = PlayerPVP[inviter][Stavka]; //чтоб была одинаковая
	    Player[playerid][Cash] -= PlayerPVP[inviter][Stavka]; //забираем бабки у принявшего
	    Player[inviter][Cash] -= PlayerPVP[inviter][Stavka]; //и у того, кто кинул
	    
		PlayerPVP[inviter][Status] = 2;
		PlayerPVP[playerid][Status] = 2;
		PlayerPVP[playerid][TimeOut] = 0;
		PlayerPVP[inviter][TimeOut] = 0;
		ResetPlayerWeapons(playerid);
		ResetPlayerWeapons(inviter);
		JoinEvent[playerid] = EVENT_PVP;
		InEvent[playerid] = EVENT_PVP;
		InEvent[inviter] = EVENT_PVP;
		new int = random(1000);
		SetPlayerVirtualWorld(playerid,int);
		SetPlayerVirtualWorld(inviter,int);
		TogglePlayerControllable(playerid,0);
		TogglePlayerControllable(inviter,0);
		CanStartPVP[playerid] = 0;
		SendClientMessage(playerid, COLOR_RED,"{FF9E27}PVP: {AFAFAF}Дуэль стартовала. Убей или умри!");
		SendClientMessage(inviter, COLOR_RED,"{FF9E27}PVP: {AFAFAF}Дуэль стартовала. Убей или умри!");
		if (TimeAfterSpawn[playerid] < 5) TimeAfterSpawn[playerid] = 5;
		if (TimeAfterSpawn[inviter] < 5) TimeAfterSpawn[inviter] = 5;
		if (PlayerPVP[playerid][PlayMap] == 1)
		{
			SetPlayerPos(inviter, -1362.0715,1258.8948,1039.8672);SetPlayerFacingAngle(inviter, 110);
			SetPlayerPos(playerid, -1426.1758,1232.9880,1039.8672);SetPlayerFacingAngle(playerid, 290);
			SetPlayerInterior(inviter, 16);SetPlayerInterior(playerid, 16);
		}
		if (PlayerPVP[playerid][PlayMap] == 2)
		{
			SetPlayerPos(inviter, -1393.4266,681.3375,3.0703);SetPlayerFacingAngle(inviter, 213);
			SetPlayerPos(playerid, -1378.0645,659.6877,3.0703);SetPlayerFacingAngle(playerid, 33);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 3)
		{
			SetPlayerPos(inviter, -1543.4636,698.6234,139.2734);SetPlayerFacingAngle(inviter, 224);
			SetPlayerPos(playerid, -1520.1078,676.0916,139.2734);SetPlayerFacingAngle(playerid, 43);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 4)
		{
			SetPlayerPos(inviter, 2515.8926,2184.3599,80.3984);SetPlayerFacingAngle(inviter, 90);
			SetPlayerPos(playerid, 2369.5652,2206.1394,80.3984);SetPlayerFacingAngle(playerid, 270);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 5)
		{
			SetPlayerPos(inviter, 2415.1479,2498.6660,68.5670);SetPlayerFacingAngle(inviter, 180);
			SetPlayerPos(playerid, 2415.3857,2443.7102,68.5670);SetPlayerFacingAngle(playerid, 0);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 6)
		{
			SetPlayerPos(inviter, 2093.2153,2404.8672,74.5786);SetPlayerFacingAngle(inviter, 0);
			SetPlayerPos(playerid, 2093.1311,2425.0190,74.5786);SetPlayerFacingAngle(playerid, 180);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 7)
		{
			SetPlayerPos(inviter, -2670.5837,311.9174,22.6094);SetPlayerFacingAngle(inviter, 90);
			SetPlayerPos(playerid, -2741.8979,311.9203,22.7239);SetPlayerFacingAngle(playerid, 270);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 8)
		{
			SetPlayerPos(inviter, -755.3179,2039.4158,77.8984);SetPlayerFacingAngle(inviter, 270);
			SetPlayerPos(playerid, -675.3208,2043.8615,77.8984);SetPlayerFacingAngle(playerid, 90);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 9)
		{
			SetPlayerPos(inviter, -1478.1135,1489.4518,8.2578);SetPlayerFacingAngle(inviter, 270);
			SetPlayerPos(playerid, -1364.1504,1489.7205,11.0391);SetPlayerFacingAngle(playerid, 90);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}
		if (PlayerPVP[playerid][PlayMap] == 10)
		{
			SetPlayerPos(inviter, 1481.1232,-1780.8931,146.8984);SetPlayerFacingAngle(inviter, 180);
			SetPlayerPos(playerid, 1481.0101,-1799.5681,146.8984);SetPlayerFacingAngle(playerid, 0);
			SetPlayerInterior(inviter, 0);SetPlayerInterior(playerid, 0);
		}			
	}	
	return 1;
}

if(!strcmp(cmd, "/vips", true))
{
	new String[120], StringX[1024], onl = 0;
	foreach(Player, cid)
	{//цикл
		if (Player[cid][GPremium] > 0)
		{
			format(String,sizeof(String),"{FFFF00}• %s[%d]   Уровень ViP: %d\n",PlayerName[cid], cid,Player[cid][GPremium]);
			strcat(StringX,String);onl = 1;
		}				
	}//цикл
	if (onl == 0){strcat(StringX,"На сервере нет ViP игроков онлайн.");}
	ShowPlayerDialog(playerid, 999, 0, "ViP-игроки онлайн", StringX, "ОК", "");
	return 1;
}

if(!strcmp(cmd, "/vip", true))
{
	new String[2048];
	strcat(String, "{FF0000}{FFFF00}Повысить свой уровень ViP можно в '/shop'\n{FFFFFF}");
	strcat(String, "ViP 1-го уровня: Вы получаете на 15 процентов больше ХР каждый раз, когда они начисляются. Лимит ХР также увеличивается.\n");
	strcat(String, "ViP 2-го уровня: Вы можете отправлять в чат разноцветные сообщения.\n");
	strcat(String, "ViP 3-го уровня: Каждый час вы получаете бонус в размере 100 000$.\n");
	strcat(String, "ViP 4-го уровня: Вы можете респавниться в любом месте, в котором пожелаете.\n");
	strcat(String, "ViP 5-го уровня: Вы получаете на 20 процентов больше ХР каждый раз, когда они начисляются. Лимит ХР также увеличивается.\n");
	strcat(String, "ViP 6-го уровня: Вы получаете деньги в 15 раз больше ХР каждый раз, когда ХР начисляется.\n");
	strcat(String, "ViP 7-го уровня: Карма увеличивается в 1.5 раза быстрее.\n");
	strcat(String, "ViP 8-го уровня: Вы получаете на 35 процентов больше ХР каждый раз, когда они начисляются. Лимит ХР также увеличивается.\n");
	strcat(String, "ViP 9-го уровня: Вы получаете деньги в 30 раз больше ХР каждый раз, когда ХР начисляется.\n");
	strcat(String, "ViP 10-го уровня: Вы получаете на 50 процентов больше ХР каждый раз, когда они начисляются. Лимит ХР также увеличивается.\n");
	strcat(String, "ViP 11-го уровня: Лимит ХР больше не действует! Качайся без ограничений!\n");
	strcat(String, "ViP 12-го уровня: Вы получаете на 65 процентов больше ХР каждый раз, когда они начисляются.\n");
	strcat(String, "ViP 13-го уровня: Теперь при смерти вы теряете не все деньги: 25 процентов сохраняется.\n");
	strcat(String, "ViP 14-го уровня: Вы можете телепортироваться по карте.\n");
	strcat(String, "ViP 15-го уровня: Вы получаете на 75 процентов больше ХР каждый раз, когда они начисляются.\n");
	strcat(String, "ViP 16-го уровня: Вы получаете деньги в 60 раз больше ХР каждый раз, когда ХР начисляется.\n");
	strcat(String, "ViP 17-го уровня: Вы получаете на 85 процентов больше ХР каждый раз, когда они начисляются.\n");
	strcat(String, "ViP 18-го уровня: Вы можете менять соревнования (команда '/change').\n");
	strcat(String, "ViP 19-го уровня: Уровень Престижа увеличивается на 1.\n");
	strcat(String, "ViP 20-го уровня: Вы получаете на 100 процентов больше ХР каждый раз, когда они начисляются.\n");
	
	ShowPlayerDialog(playerid, 999, 0, "Уровни ViP", String, "ОК", "");return 1;
}

if(!strcmp(cmd, "/config", true))
{
	new StringX[1024];
	if (Player[playerid][ConPM] == 1) strcat(StringX, "{FFFFFF}Личные сообщения (/pm): {008E00}Включены\n"); else strcat(StringX, "{FFFFFF}Личные сообщения (/pm): {FF0000}Отключены\n");
	if (Player[playerid][ConInviteClan] == 1) strcat(StringX, "{FFFFFF}Разрешить приглашать меня в клан: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Разрешить приглашать меня в клан: {FF0000}Нет\n");
	if (Player[playerid][ConInvitePVP] == 1) strcat(StringX, "{FFFFFF}Разрешить вызывать меня на PvP: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Разрешить приглашать меня на PvP: {FF0000}Нет\n");
	if (Player[playerid][ConMesPVP] == 1) strcat(StringX, "{FFFFFF}Отображать результаты PvP других игроков: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Отображать результаты PvP других игроков: {FF0000}Нет\n");
	if (Player[playerid][ConMesEnterExit] == 1) strcat(StringX, "{FFFFFF}Отображать сообщения о входе/выходе на сервер: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Отображать сообщения о входе/выходе на сервер: {FF0000}Нет\n");
	if (Player[playerid][ConSpeedo] == 1) strcat(StringX, "{FFFFFF}Отображать спидометр: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Отображать спидометр: {FF0000}Нет\n");
	if (Player[playerid][RadarSwitch] == 1) strcat(StringX, "{FFFFFF}Отображать время и дату: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Отображать время и дату: {FF0000}Нет\n");
	if (Player[playerid][MyClan] == 0 || Clan[Player[playerid][MyClan]][cLevel] < 5) strcat(StringX, "{afafaf}Включить клановый тег: {ff0000}Недоступно\n");
	else
	{
		if(Player[playerid][Tag] == 1) strcat(StringX, "{FFFFFF}Включить клановый тег: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Включить клановый тег: {FF0000}Нет\n");
	}
	if (Player[playerid][FindPack] != 1) strcat(StringX, "{FFFFFF}Слушать музыку от игроков: {008E00}Да\n"); else strcat(StringX, "{FFFFFF}Слушать музыку от игроков: {FF0000}Нет\n");
    strcat(StringX, "{FF8000}Сменить пароль\n");
	strcat(StringX, "{007FFF}Сохранить и закрыть\n"); 
	
	ShowPlayerDialog(playerid, DIALOG_CONFIG, 2, "Настройки аккаунта", StringX, "ОК", "");
	return 1;
}

if(!strcmp(cmd, "/myweather", true))
{
	if (Player[playerid][Level] < 67) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 67-го уровня.");
	else return ShowPlayerDialog(playerid, DIALOG_MYWEATHER, 2, "Настройки погоды", "Оставить текущую погоду\nУстановить серверную (общую) погоду\nУстановить свою погоду", "ОК", "");
}

if(!strcmp(cmd, "/gps", true))
{
	return ShowPlayerDialog(playerid, DIALOG_GPS, 2, "GPS", "Работа\nБанк\nКазино\nАвтомастерские\nМагазин Одежды\nАэропорт\nЛичный дом\nШтаб клана\nОстров 'FarCry'\n{FF0000}Удалить маркер", "ОК", "Отмена");
}

if(!strcmp(cmd, "/claninfo", true))
{
	new clanid;
	if(sscanf(params,"i", clanid))//
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /claninfo [id клана]");//если игрок не ввел значение то выдаем собщение 
	return ShowClanStats(playerid, clanid);
}

if(!strcmp(cmd, "/gold", true))
{
	GoldDialog(playerid);
	return 1;
}

if(!strcmp(cmd, "/action", true))
{
	if (IsPlayerInAnyVehicle(playerid)) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду в транспорте!");
	if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
	new String[500];
	new actionid;
	if(sscanf(params,"i", actionid))
	{//Если не ввел никакого ID
		strcat(String, "{FFFFFF}Для активации специальных действий используйте {FFFF00}/action [ID]\n\n{FFFFFF}");
		strcat(String, "            ID {FF0000}0{FFFFFF}: Отменить все\n");
		strcat(String, "ID {FFFF00}1{FFFFFF}: Танец №1         ");
		strcat(String, "ID {FFFF00}2{FFFFFF}: Танец №2\n");
		strcat(String, "ID {FFFF00}3{FFFFFF}: Танец №3         ");
		strcat(String, "ID {FFFF00}4{FFFFFF}: Танец №4\n");
		strcat(String, "ID {FFFF00}5{FFFFFF}: Руки вверх       ");
		strcat(String, "ID {FFFF00}6{FFFFFF}: Пить пиво\n");
		strcat(String, "ID {FFFF00}7{FFFFFF}: Пить вино         ");
		strcat(String, "ID {FFFF00}8{FFFFFF}: Пить газированую воду\n");
		strcat(String, "ID {FFFF00}9{FFFFFF}: Купить сигару  ");
		strcat(String, "ID {FFFF00}10{FFFFFF}: Мочиться\n");		
		return ShowPlayerDialog(playerid, 999, 0, "Специальные действия", String, "ОК", "");
	}//Если не ввел никакого ID
	switch(actionid)
	{
		case 0: SetPlayerSpecialAction(playerid, 0);
		case 1: SetPlayerSpecialAction(playerid, 5);
		case 2: SetPlayerSpecialAction(playerid, 6);
		case 3: SetPlayerSpecialAction(playerid, 7);
		case 4: SetPlayerSpecialAction(playerid, 8);
		case 5: SetPlayerSpecialAction(playerid, 10);
		case 6: SetPlayerSpecialAction(playerid, 20);
		case 7: SetPlayerSpecialAction(playerid, 22);
		case 8: SetPlayerSpecialAction(playerid, 23);
		case 9: SetPlayerSpecialAction(playerid, 21);
		case 10: SetPlayerSpecialAction(playerid, 68);
		default: return SendClientMessage(playerid, COLOR_RED,"ОШИБКА: Используй /action [id] (от 0 до 10)");
	}
	return SetPlayerChatBubble(playerid, "Использовал /action", COLOR_YELLOW, 200.0, 3000);
}


///-------------------------------АНИМАЦИИ------------------------------------------
if(!strcmp(cmd, "/anim", true))
{
	SendClientMessage(playerid, COLOR_RED,"____________ Список анимаций __________");
	SendClientMessage(playerid, COLOR_WHITE," /seat /eat [1-5] /swat [0-16] /bomber");
	SendClientMessage(playerid, COLOR_WHITE," /rap [0-3] /bro [0-2] /robman ");
	
//	SendClientMessage(playerid, COLOR_WHITE," /cops [1-4] /coplook [1-5] /walk [1-3] /bomb /look [1-4]");
//	SendClientMessage(playerid, COLOR_WHITE," /chase [1-4] /jump [1-6] /rap [1-3] /food [1-5] /down [1-14]");
//	SendClientMessage(playerid, COLOR_WHITE," /crack [1-5] /smoke [1-2] /chat [1-6] /dance [1-9] /strip [1-5]");
//	SendClientMessage(playerid, COLOR_WHITE," /bro [1-3] /wave [1-3] /robman /handsup /gsigs /swat [1-21]");
//	SendClientMessage(playerid, COLOR_WHITE," /attack [1-16] /vending [1-5] /seat");
	return true;
}

if(!strcmp(cmd, "/kiss", true))
{
	if(GetPlayerState(playerid)!=PLAYER_STATE_ONFOOT) return true;
	if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
    if (InEvent[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях!");
	if (InEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Нельзя использовать эту команду в соревнованиях!");
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /kiss [ID игрока]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА! Игрок не в сети.");
	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Себя целовать собрался?)");
	new giveplayerid = params[0];
	if(GetDistanceBetweenPlayers(playerid,giveplayerid) > 2.0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА! Игрок далеко.");
	
	SetPosInFrontOfPlayer(playerid,giveplayerid,1);
	new Float:a;
	GetPlayerFacingAngle(playerid,a);
	SetPlayerFacingAngle(giveplayerid,180+a);
	ApplyAnimation(giveplayerid,"BD_FIRE","GRLFRD_KISS_03",4.0,0,0,0,0,0,1);
	ApplyAnimation(playerid,"BD_FIRE","PLAYA_KISS_03",4.0,0,0,0,0,0,1);
	return true;
}

if(!strcmp(cmd, "/eat", true))
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
    if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
    if (InEvent[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях!");
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /eat [номер (1-5)]");
	switch(params[0])
	{
	    //case 0: ApplyAnimation( playerid, "PED", "SEAT_down", 4.1, 0, 1, 1, 1, 1 );
	    case 1: ApplyAnimation( playerid, "FOOD", "EAT_Burger", 4.1, 0, 1, 1, 1, 1 );
	    case 2: ApplyAnimation( playerid, "FOOD", "EAT_Chicken", 4.1, 0, 1, 1, 1, 1 );
	    case 3: ApplyAnimation( playerid, "FOOD", "EAT_Pizza", 4.1, 0, 1, 1, 1, 1 );
	    case 4: ApplyAnimation( playerid, "FOOD", "EAT_Vomit_P", 4.1, 0, 1, 1, 1, 1 );
	    case 5: ApplyAnimation( playerid, "FOOD", "EAT_Vomit_SK", 4.1, 0, 1, 1, 1, 1 );
	    default: SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /eat [номер (1-5)]");
	}
	return true;
}

if(!strcmp(cmd, "/seat", true))
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
    ApplyAnimation( playerid, "PED", "SEAT_down", 4.1, 0, 1, 1, 1, 1 );
	return true;
}

if(!strcmp(cmd, "/swat", true))
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
    if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
    if (InEvent[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях!");
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /swat [номер (0-16)]");
	switch(params[0])
	{
		case 0: ApplyAnimation( playerid, "SWAT", "gnstwall_injurd", 4.1, 0, 1, 1, 1, 1 );
		case 1: ApplyAnimation( playerid, "SWAT", "JMP_Wall1m_180", 4.1, 0, 1, 1, 1, 1 );
		case 2: ApplyAnimation( playerid, "SWAT", "Rail_fall_crawl", 4.1, 0, 1, 1, 1, 1 );
		case 3: ApplyAnimation( playerid, "SWAT", "swt_breach_01", 4.1, 0, 1, 1, 1, 1 );
		case 4: ApplyAnimation( playerid, "SWAT", "swt_breach_02", 4.1, 0, 1, 1, 1, 1 );
		case 5: ApplyAnimation( playerid, "SWAT", "swt_breach_03", 4.1, 0, 1, 1, 1, 1 );
		case 6: ApplyAnimation( playerid, "SWAT", "swt_go", 4.1, 0, 1, 1, 1, 1 );
		case 7: ApplyAnimation( playerid, "SWAT", "swt_lkt", 4.1, 0, 1, 1, 1, 1 );
		case 8: ApplyAnimation( playerid, "SWAT", "swt_sty", 4.1, 0, 1, 1, 1, 1 );
		case 9: ApplyAnimation( playerid, "SWAT", "swt_wllpk_L_back", 4.1, 0, 1, 1, 1, 1 );
		case 10: ApplyAnimation( playerid, "SWAT", "swt_wllpk_L", 4.1, 0, 1, 1, 1, 1 );
		case 11: ApplyAnimation( playerid, "SWAT", "swt_wllshoot_in_L", 4.1, 0, 1, 1, 1, 1 );
		case 12: ApplyAnimation( playerid, "SWAT", "swt_wllshoot_out_L", 4.1, 0, 1, 1, 1, 1 );
		case 13: ApplyAnimation( playerid, "SWAT", "swt_wllpk_R_back", 4.1, 0, 1, 1, 1, 1 );
		case 14: ApplyAnimation( playerid, "SWAT", "swt_wllpk_R", 4.1, 0, 1, 1, 1, 1 );
		case 15: ApplyAnimation( playerid, "SWAT", "swt_wllshoot_in_R", 4.0, 1, 1, 1, 1, 1 );
		case 16: ApplyAnimation( playerid, "SWAT", "swt_wllshoot_out_R", 4.0, 1, 1, 1, 1, 1 );
		default: SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /swat [номер (0-16)]");
	}
	return true;
}

if(!strcmp(cmd, "/bomber", true))
{
    if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
    if (InEvent[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях!");
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
    ApplyAnimation(playerid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 0);
    return 1;
}

if(!strcmp(cmd, "/rap", true))
{
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
	if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
    if (InEvent[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях!");
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /rap [номер (0-3)]");
	switch(params[0])
	{
		case 0: ApplyAnimation(playerid,"benchpress","gym_bp_celebrate",4.1,1,1,1,1,1);
		case 1: ApplyAnimation(playerid,"MD_END","END_SC2_RYD",4.1,1,1,1,1,1);
		case 2: ApplyAnimation(playerid,"MD_END","END_SC2_SWE",4.1,0,1,1,1,1);
		case 3:  ApplyAnimation(playerid,"Freeweights","gym_free_celebrate",4.1,0,0,0,0,0);
        default: SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /rap [номер (0-3)]");
	}
	return true;
}

if(!strcmp(cmd, "/bro", true))
{
	if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
	if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
    if (InEvent[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях!");
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /bro [номер (0-2)]");
	switch(params[0])
	{
		case 0: ApplyAnimation(playerid,"GANGS","hndshkaa",4.0, 0, 0, 0, 0, 0);
		case 1: ApplyAnimation(playerid,"GANGS","hndshkfa",4.0, 0, 0, 0, 0, 0);
		case 2: ApplyAnimation(playerid,"GANGS","hndshkfa_swt",4.0, 0, 0, 0, 0, 0);
        default: SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /bro [номер (0-2)]");
	}
	return true;
}

if(!strcmp(cmd, "/robman", true))
{
    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
    if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
    if (InEvent[playerid] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Эта команда запрещена в соревнованиях!");
    ApplyAnimation(playerid, "SHOP", "ROB_Loop_Threat", 4.0, 1, 0, 0, 0, 0);
    return 1;
}
	/*
	
	else if(strcmp(cmd, "/gsigs", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /gsigs [номер (0-10)]");
		if(params[0] == 1) ApplyAnimation(playerid,"GHANDS","gsign1",4.1,0,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"GHANDS","gsign1LH",4.1,0,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"GHANDS","gsign2",4.1,0,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"GHANDS","gsign2LH",4.1,0,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"GHANDS","gsign3",4.1,0,1,1,1,1);
		else if(params[0] == 6) ApplyAnimation(playerid,"GHANDS","gsign3LH",4.1,0,1,1,1,1);
		else if(params[0] == 7) ApplyAnimation(playerid,"GHANDS","gsign4",4.1,0,1,1,1,1);
		else if(params[0] == 8) ApplyAnimation(playerid,"GHANDS","gsign4LH",4.1,0,1,1,1,1);
		else if(params[0] == 9) ApplyAnimation(playerid,"GHANDS","gsign5",4.1,0,1,1,1,1);
		else if(params[0] == 10) ApplyAnimation(playerid,"GHANDS","gsign5LH",4.1,0,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /gsigs [номер (0-10)]");

		return true;
	}
	else if(strcmp(cmd, "/dance", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /dance [номер (0-9)]");
		if(params[0] == 1) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE1);
		else if(params[0] == 2) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE2);
		else if(params[0] == 3) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE3);
		else if(params[0] == 4) SetPlayerSpecialAction(playerid,SPECIAL_ACTION_DANCE4);
		else if(params[0] == 5) ApplyAnimation( playerid, "DANCING", "DAN_Loop_A", 4.1, 0, 1, 1, 1, 0 ,1);
		else if(params[0] == 6) ApplyAnimation( playerid, "DANCING", "DAN_Left_A", 4.1, 0, 1, 1, 1, 0 ,1);
		else if(params[0] == 7) ApplyAnimation( playerid, "DANCING", "DAN_Down_A", 4.1, 0, 1, 1, 1, 0 ,1);
		else if(params[0] == 8) ApplyAnimation( playerid, "DANCING", "dnce_M_b", 4.1, 0, 1, 1, 1, 0 ,1);
		else if(params[0] == 9) ApplyAnimation( playerid, "DANCING", "dnce_M_a", 4.1, 0, 1, 1, 1, 0 ,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /dance [номер (0-9)]");

		return true;
	}
	else if(strcmp(cmd, "/food", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /food [номер (0-7)]");
		if(params[0] == 1) ApplyAnimation(playerid,"FOOD","FF_Sit_Eat1",4.1,1,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"FOOD","FF_Die_Fwd",4.1,0,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"FOOD","SHP_Thank",4.1,0,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"FOOD","EAT_Burger",4.1,1,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"INT_HOUSE","wash_up",4.1,1,1,1,1,1);
		else if(params[0] == 6) ApplyAnimation(playerid,"BAR","dnk_stndF_loop",4.1,1,1,1,1,1);
		else if(params[0] == 7) ApplyAnimation(playerid,"FOOD", "EAT_Vomit_P", 4.1,0,0,0,0,0);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /food [номер (0-7)]");

		return true;
	}
	else if(strcmp(cmd, "/down", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /down [номер (0-14)]");
		if(params[0] == 1) ApplyAnimation(playerid,"PED","KD_left",4.1,0,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"PED","KD_right",4.1,0,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"PED","KO_shot_face",4.1,0,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"PED","KO_shot_front",4.1,0,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"PED","KO_shot_stom",4.1,0,1,1,1,1);
		else if(params[0] == 6) ApplyAnimation(playerid,"PED","KO_skid_back",4.1,0,1,1,1,1);
		else if(params[0] == 7) ApplyAnimation(playerid,"PED","KO_skid_front",4.1,0,1,1,1,1);
		else if(params[0] == 8) ApplyAnimation(playerid,"PED","KO_spin_L",4.1,0,1,1,1,1);
		else if(params[0] == 9) ApplyAnimation(playerid,"PED","KO_spin_R",4.1,0,0,0,1,1);
		else if(params[0] == 10) ApplyAnimation(playerid,"PED","BIKE_fallR",4.1,0,1,1,1,1);
		else if(params[0] == 11) ApplyAnimation(playerid,"PED","BIKE_fall_off",4.1,0,1,1,1,1);
		else if(params[0] == 12) ApplyAnimation(playerid,"GYMNASIUM","gym_jog_falloff",4.1,0,1,1,1,1);
		else if(params[0] == 13) ApplyAnimation(playerid,"SWAT","gnstwall_injurd",4.1,0,1,1,1,1);
		else if(params[0] == 14) ApplyAnimation(playerid,"PED","BIKE_pickupL",4.1,0,0,0,0,0);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /down [номер (0-14)]");

		return true;
	}

	else if(strcmp(cmd, "/gangs", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /gangs [номер (0-9)]");
		if(params[0] == 1) ApplyAnimation(playerid,"GANGS","drnkbr_prtl",4.1,0,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"GANGS","drnkbr_prtl_F",4.1,0,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"GANGS","DRUGS_BUY",4.1,0,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"GANGS","hndshkaa",4.1,0,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"GANGS","hndshkba",4.1,0,1,1,1,1);
		else if(params[0] == 6) ApplyAnimation(playerid,"GANGS","hndshkca",4.1,0,1,1,1,1);
		else if(params[0] == 7) ApplyAnimation(playerid,"GANGS","hndshkcb",4.1,0,1,1,1,1);
		else if(params[0] == 8) ApplyAnimation(playerid,"GANGS","hndshkda",4.1,0,1,1,1,1);
		else if(params[0] == 9) ApplyAnimation(playerid,"GANGS","prtial_gngtlkD",4.1,0,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /gangs [номер (0-9)]");

		return true;
	}
	else if(strcmp(cmd, "/handsup", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		SetPlayerSpecialAction(playerid,SPECIAL_ACTION_HANDSUP);

		return true;
	}

	else if(strcmp(cmd, "/strip", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /strip [номер (0-5)]");
		if(params[0] == 1) ApplyAnimation(playerid,"STRIP","strip_G",4.1,1,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"STRIP","STR_A2B",4.1,1,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"STRIP","STR_B2C",4.1,1,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"STRIP","STR_C1",4.1,1,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"STRIP","STR_C2",4.1,1,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /strip [номер (0-5)]");

		return true;
	}
	else if(strcmp(cmd, "/cops", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /cops [номер (0-4)]");
		if(params[0] == 1) ApplyAnimation(playerid, "COP_AMBIENT", "Coplook_loop", 4.1, 1, 1, 1, 1, -1);
		else if(params[0] == 2) ApplyAnimation(playerid,"COP_AMBIENT","Coplook_shake", 4.0, 0, 0, 0, 0, 0);
		else if(params[0] == 3) ApplyAnimation(playerid,"COP_AMBIENT","Coplook_think", 4.0, 0, 0, 0, 0, 0);
		else if(params[0] == 4) ApplyAnimation(playerid,"COP_AMBIENT","Coplook_watch", 4.0, 0, 0, 0, 0, 0);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /cops [номер (0-4)]");

		return true;
	}
	else if(strcmp(cmd, "/coplook", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /coplook [номер (0-5)]");
		if(params[0] == 1) ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_in", 4.0, 0, 0, 0, 0, 0);
		else if(params[0] == 2) ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_loop",4.1,1,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_nod",4.1,1,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_out", 4.0, 0, 0, 0, 0, 0);
		else if(params[0] == 5) ApplyAnimation(playerid,"COP_AMBIENT","Copbrowse_shake", 4.0, 0, 0, 0, 0, 0);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /coplook [номер (0-5)]");

		return true;
	}
	else if(strcmp(cmd, "/chase", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /chase [номер (0-4)]");
		if(params[0] == 1) ApplyAnimation(playerid,"MD_CHASE","Carhit_Tumble",4.1,0,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll",4.1,0,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"MD_CHASE","MD_BIKE_Lnd_Roll_F",4.1,0,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"MD_CHASE","MD_HANG_Lnd_Roll",4.1,0,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /chase [номер (0-4)]");

		return true;
	}
	else if(strcmp(cmd, "/crack", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /crack [номер (0-5)]");
		if(params[0] == 1) ApplyAnimation(playerid,"CRACK","crckdeth2",4.1,1,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"CRACK","crckdeth1",4.1,0,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"CRACK","crckdeth3",4.1,0,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"CRACK","crckdeth4",4.1,0,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"CRACK","crckidle1",4.1,0,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /crack [номер (0-5)]");

		return true;
	}
	else if(strcmp(cmd, "/walk", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /walk [номер (0-3)]");
		if(params[0] == 1) ApplyAnimation(playerid,"FAT","FatWalk",4.1,1,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"PED","WALK_DRUNK",4.1,1,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"PED","CAR_crawloutRHS",4.1,0,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /walk [номер (0-3)]");

		return true;
	}
	else if(strcmp(cmd, "/look", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /look [номер (0-5)]");
		if(params[0] == 1) ApplyAnimation(playerid, "SHOP", "ROB_Shifty", 4.0, 0, 0, 0, 0, 0);
		else if(params[0] == 2) ApplyAnimation(playerid,"ON_LOOKERS","panic_point",4.1,1,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"ON_LOOKERS","Pointup_loop",4.1,1,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"ON_LOOKERS","point_loop",4.1,1,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"PED","flee_lkaround_01",4.1,0,0,0,0,0);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /look [номер (0-5)]");

		return true;
	}
	else if(strcmp(cmd, "/chat", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /chat [номер (0-12)]");
		if(params[0] == 1) ApplyAnimation(playerid,"PED","IDLE_CHAT",4.1,1,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_BR",4.1,1,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"CAR_CHAT","CAR_Sc3_FL",4.0,0,0,0,0,0);
		else if(params[0] == 4) ApplyAnimation(playerid,"CAR_CHAT","car_talkm_in",4.1,0,1,1,1,1);
		else if(params[0] == 5) ApplyAnimation(playerid,"CAR_CHAT","car_talkm_out",4.0,0,0,0,0,0);
		else if(params[0] == 6) ApplyAnimation(playerid, "RAPPING", "Laugh_01", 4.1,0,0,0,0,0);
		else if(params[0] == 7) ApplyAnimation(playerid,"PED","endchat_01",4.1,0,0,0,0,0);
		else if(params[0] == 8) ApplyAnimation(playerid,"PED","endchat_02", 4.1,0,0,0,0,0);
		else if(params[0] == 9) ApplyAnimation(playerid,"PED","Shove_Partial",4.1,0,0,0,0,0);
		else if(params[0] == 10) ApplyAnimation(playerid,"BAR","Barcustom_order",4.1,0,0,0,0,0);
		else if(params[0] == 11) ApplyAnimation(playerid, "DEALER", "DEALER_DEAL", 4.1, 0, 0, 0, 0, 0);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /chat [номер (0-12)]");

		return true;
	}
	else if(strcmp(cmd, "/jump", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /jump [номер (0-4)]");
		if(params[0] == 1) ApplyAnimation(playerid,"DODGE","Crush_Jump",4.1,0,1,1,1,1);
		else if(params[0] == 2) ApplyAnimation(playerid,"PED","CAR_rollout_LHS",4.1,0,1,1,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"PED","CAR_rollout_RHS",4.1,0,1,1,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"PED","EV_dive",4.1,0,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /jump [номер (0-4)]");

		return true;
	}
	else if(strcmp(cmd, "/wave", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /wave [номер (0-3)]");
		if(params[0] == 1) ApplyAnimation(playerid, "ON_LOOKERS", "wave_loop", 4.1, 1, 1, 1, 1, 1);
		else if(params[0] == 2) ApplyAnimation(playerid,"PED","endchat_03",4.1,0,0,0,0,0);
		else if(params[0] == 3) ApplyAnimation(playerid,"SCRATCHING","scdrulp",4.1,1,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /wave [номер (0-3)]");

		return true;
	}
	else if(strcmp(cmd, "/stay", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /stay [номер (0-8)]");
		if(params[0] == 1) ApplyAnimation(playerid,"RAPPING","RAP_A_OUT",4.0, 0, 0, 0, 0, 0);
		else if(params[0] == 2) ApplyAnimation(playerid,"BAR","BARman_idle",4.1,0,0,0,0,0);
		else if(params[0] == 3) ApplyAnimation(playerid,"FAT","IDLE_tired",4.1,0,0,0,0,0);
		else if(params[0] == 4) ApplyAnimation(playerid,"PED","car_hookertalk",4.1,0,0,0,0,0);
		else if(params[0] == 5) ApplyAnimation(playerid,"PED","IDLE_armed",4.1,0,1,1,1,1);
		else if(params[0] == 6) ApplyAnimation(playerid,"PED","Gun_stand",4.1,0,1,1,1,1);
		else if(params[0] == 7) ApplyAnimation(playerid,"PED","Idlestance_fat",4.1,0,0,0,0,0);
		else if(params[0] == 8) ApplyAnimation(playerid,"PED","IDLE_ROCKET",4.1,0,1,1,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /stay [номер (0-8)]");

		return true;
	}
	else if(strcmp(cmd, "/opla", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /opla [номер (0-4)]");
		if(params[0] == 1) ApplyAnimation(playerid,"BEACH", "ParkSit_M_loop", 4.0, 0, 0, 0, 1, 1);
		else if(params[0] == 2) ApplyAnimation(playerid,"JST_BUISNESS","girl_02",4.1,0,0,0,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"INT_HOUSE","LOU_In",4.1,0,0,0,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"PED","SEAT_down",4.1,0,0,0,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /opla [номер (0-4)]");

		return true;
	}
	else if(strcmp(cmd, "/lay", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /lay [номер (0-4)]");
		if(params[0] == 1) ApplyAnimation(playerid,"BEACH", "bather", 4.0, 1, 0, 0, 1, 1);
		else if(params[0] == 2) ApplyAnimation(playerid,"BEACH","Lay_Bac_Loop",4.1,0,0,0,1,1);
		else if(params[0] == 3) ApplyAnimation(playerid,"BEACH","ParkSit_W_loop",4.1,0,0,0,1,1);
		else if(params[0] == 4) ApplyAnimation(playerid,"BEACH","SitnWait_loop_W",4.1,0,0,0,1,1);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /lay [номер (0-4)]");

		return true;
	}
	else if(strcmp(cmd, "/cool", true) == 0)
	{
	    if(GetPlayerState(playerid) != PLAYER_STATE_ONFOOT) return true;
		if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /cool [номер (0-9)]");
		if(params[0] == 1) ApplyAnimation(playerid,"PLAYIDLES","time",4.1,0,0,0,0,0);
		else if(params[0] == 2) ApplyAnimation(playerid,"PED","XPRESSscratch",4.1,0,0,0,0,0);
		else if(params[0] == 3) ApplyAnimation(playerid,"OTB","wtchrace_cmon",4.1,0,0,0,0,0);
		else if(params[0] == 4) ApplyAnimation(playerid,"OTB","wtchrace_in",4.1,0,0,0,0,0);
		else if(params[0] == 5) ApplyAnimation(playerid,"OTB","wtchrace_win",4.1,0,0,0,0,0);
		else if(params[0] == 6) ApplyAnimation(playerid,"PLAYIDLES","shift",4.1,0,0,0,0,0);
		else if(params[0] == 7) ApplyAnimation(playerid,"PLAYIDLES","shldr",4.1,0,0,0,0,0);
		else if(params[0] == 8) ApplyAnimation(playerid,"PLAYIDLES","stretch",4.1,0,0,0,0,0);
		else if(params[0] == 9) ApplyAnimation(playerid,"PLAYIDLES","strleg",4.1,0,0,0,0,0);
		else return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /cool [номер (0-9)]");

		return true;
	}*/

if(!strcmp(cmd, "/hi", true))
{
    if(GetPlayerState(playerid)!=PLAYER_STATE_ONFOOT) return true;
	if (InEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Нельзя использовать эту команду в соревнованиях!");
	if(sscanf(params, "d", params[0])) return SendClientMessage(playerid, COLOR_RED, "Используйте: {FFFFFF} /hi [ID игрока]");
	if(!IsPlayerConnected(params[0])) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА! Игрок не в сети.");
	if(params[0] == playerid) return SendClientMessage(playerid, COLOR_RED, "Себя приветствовать собрался?)");
	if (GetPlayerSpecialAction(playerid) == 2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать эту команду с JetPack`ом!");
	new giveplayerid = params[0];
	if(GetDistanceBetweenPlayers(playerid,giveplayerid) > 2.0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА! Игрок далеко.");
	if(GetPlayerState(giveplayerid)!=PLAYER_STATE_ONFOOT) return true;

	SetPosInFrontOfPlayer(playerid,giveplayerid,1);
	new Float:a;
	GetPlayerFacingAngle(playerid,a);
	SetPlayerFacingAngle(giveplayerid,180+a);

	ApplyAnimation(playerid,"GANGS","hndshkfa",4.0,0,0,0,0,0,1);
	ApplyAnimation(params[0],"GANGS","hndshkfa",4.0,0,0,0,0,0,1);
	return true;
}
//-----------------------------//АНИМАЦИИ//--------------------------------------


if(!strcmp(cmd, "/chatname", true))
{
	if (Player[playerid][Prestige] < 3 && Player[playerid][Admin] < 4) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Вы должны быть как минимум 3-го уровня Престижа!");

	new StringX[2048];
	strcat(StringX, "{FFFFFF}Вы можете установить себе разноцветный ник для чата при помощи HEX-кодов цветов.\n");
	strcat(StringX, "Если вы впервые слышите о HEX-кодах цветов, то рекомендуем почитать о них в интернете.\n\n");
	strcat(StringX, "Указывайте коды цветов между двумя символами {FF0000}*{FFFFFF} или в фигурных скобках.\n");
	strcat(StringX, "Ниже приведено несколько самых популярных HEX-кодов цветов:\n");
	strcat(StringX, "\t{FF0000}*FF0000* - Красный \t{007FFF}*007FFF* - Голубой \t{00FF00}*00FF00* - Зеленый\n");
	strcat(StringX, "\t{FFFFFF}*FFFFFF* - Белый \t{FFFF00}*FFFF00* - Желтый \t{9966CC}*9966CC* - Фиолетовый\n");

	strcat(StringX, "\n{AFAFAF}Допустим, что ваш ник 'Player'. Тогда, введя следующие коды:\n");
	strcat(StringX, "\t{FFFFFF}*FFFFFF*{AFAFAF}Pl{007FFF}*007FFF*{AFAFAF}ay{FF0000}*FF0000*{AFAFAF}er\n");
	strcat(StringX, "Вы получите следующий ник: {FFFFFF}Pl{007FFF}ay{FF0000}er \n\n");
	strcat(StringX, "{FFFF00}Удачи в экспериментах! Если хотите вернуть простой ник - введите его без кодов!");
	
	return ShowPlayerDialog(playerid, DIALOG_CHATNAME, 1, "Ник в чате", StringX, "ОК", "Отмена");
}

if(!strcmp(cmd, "/mycolor", true) || !strcmp(cmd, "/mycolour", true))
{
	if (Player[playerid][Prestige] < 7) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вы должны быть как минимум 7-го уровня Престижа.");
	new StringX[1024];
	strcat(StringX, "{AFAFAF}Цвет №0\n{FFFF99}Цвет №1\n{FFFF00}Цвет №2\n{FF99FF}Цвет №3\n{FF9999}Цвет №4\n{FFCC00}Цвет №5\n{FF66CC}Цвет №6\n{FF6600}Цвет №7\n{FF00FF}Цвет №8\n{CCFFFF}Цвет №9\n{00A0C1}Цвет №10\n");
	strcat(StringX, "{E5004F}Цвет №11\n{CCFF00}Цвет №12\n{CC66FF}Цвет №13\n{CC3366}Цвет №14\n{CC6600}Цвет №15\n{9999FF}Цвет №16\n{9925FF}Цвет №17\n{99CCCC}Цвет №18\n{99FF66}Цвет №19\n{99FF00}Цвет №20\n");
	strcat(StringX, "{993300}Цвет №21\n{990066}Цвет №22\n{66FFFF}Цвет №23\n{6666FF}Цвет №24\n{EB6100}Цвет №25\n{666633}Цвет №26\n{33FFFF}Цвет №27\n{3399FF}Цвет №28\n{33CC99}Цвет №29\n{33FF66}Цвет №30\n");
	strcat(StringX, "{339900}Цвет №31\n{457EFF}Цвет №32\n{FFCC00}Цвет №33\n{976D3D}Цвет №34\n{FF8800}Цвет №35\n{FF6666}Цвет №36\n{0015FF}Цвет №37\n{DDAA00}Цвет №38\n{FFFFFF}Цвет №39\n{FF8000}Цвет №40\n{FF0000}Вернуть стандартный цвет");
	return ShowPlayerDialog(playerid, DIALOG_PRESTIGECOLOR, 2, "Выберите ваш новый цвет", StringX, "Выбрать", "Отмена");
}



if(!strcmp(cmd, "/pgun", true))
{
    if(Player[playerid][SPN1] < 1) return SendClientMessage(playerid,COLOR_RED,"Вам не доступна эта функция!");
    if(GetPlayerState(playerid)!=PLAYER_STATE_ONFOOT) return true;
	if (InEvent[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"Нельзя использовать эту команду в соревнованиях!");
	if(PGunActiv[playerid] == 1) {PGunActiv[playerid] = 0; GiveWeapon(playerid,Player[playerid][Slot2],200); SetPlayerArmedWeapon(playerid, 0);RemovePlayerAttachedObject(playerid,9);return 1;}
	//if(PGunTime[playerid] > unixtime) return SendClientMessage(playerid,COLOR_RED,"Портальную пушку можно использовать раз в 5 секунд!");
	if(GetPlayerInterior(playerid) != 0) return SendClientMessage(playerid,COLOR_RED,"Портальную пушку можно использовать только в общем игровом мире!");
	
	GivePlayerWeapon(playerid, 23, 1);
	SetPlayerArmedWeapon(playerid, 23);
	SetPlayerAttachedObject(playerid, 9, 18643, 6, 0.108249, 0.030232, 0.118051, 1.468254, 350.512573, 364.284240);
	PGunActiv[playerid] = 1;
	PGunTime[playerid] = unixtime+5;
	return 1;
}








//--- КОМАНДЫ, КОТОРЫЕ НЕИСПОЛЬЗУЮТСЯ НАПРЯМУЮ И СКРЫТЫ ОТ ИГРОКА
/*if(!strcmp(cmd, "/house", true))
{//дом
	new id = LastHouseVisited[playerid];
	if (id < 1 || id == MAX_PROPERTY) return 1;
	if (PlayerToPoint(3.0,playerid, Property[id][pPosEnterX], Property[id][pPosEnterY], Property[id][pPosEnterZ]))
	{//игрок рядом с домом
		if (Player[playerid][Home] == id) //это его дом
			ShowPlayerDialog(playerid, DIALOG_HOUSEMENU, 2, "{00FF00}Дом", "{007FFF}Войти в дом{FFFFFF}\nИнформация о доме\nКупить дом\nПродать дом\nУвеличить цену дома\nОткрыть / Закрыть дом\nСделать местом респавна (Снаружи дома)\nСделать местом респавна (Внутри дома)", "ОК", "Отмена");
		else
			ShowPlayerDialog(playerid, DIALOG_HOUSEMENU, 2, "{00FF00}Дом", "{007FFF}Войти в дом{FFFFFF}\nИнформация о доме\nКупить дом", "ОК", "Отмена");
		}//игрок рядом с домом
	return 1;
}//дом*/

if(!strcmp(cmd, "/enterhouse", true))
{//вход в дом
	if (GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid, COLOR_RED, "Заходить в дома можно только в общем игровом мире!");
	new i = LastHouseVisited[playerid];
	if (i < 1 || i == MAX_PROPERTY) return 1;
	if (PlayerToPoint(3.0,playerid, Property[i][pPosEnterX], Property[i][pPosEnterY], Property[i][pPosEnterZ]))
	{
		if(Player[playerid][Home] != i && Property[i][pOpened] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Этот дом закрыт.");
		if (Property[i][pPrice] < 20000000)//10kk dom
		{
		    SetPlayerPos(playerid, 243.7173,304.9818,999.1484); SetPlayerFacingAngle(playerid, 270.0); SetPlayerInterior(playerid,1);
		}
		else if (Property[i][pPrice] >= 20000000 && Property[i][pPrice] < 40000000)//20kk dom
		{
		    SetPlayerPos(playerid, 2218.4033,-1076.2634,1050.4844); SetPlayerFacingAngle(playerid, 90.0); SetPlayerInterior(playerid,1);
		}
		else if (Property[i][pPrice] >= 40000000 && Property[i][pPrice] < 60000000)//40kk dom
		{
		    SetPlayerPos(playerid, 2365.3140,-1135.5983,1050.8826); SetPlayerFacingAngle(playerid, 0.0); SetPlayerInterior(playerid,8);
		}
		else if (Property[i][pPrice] >= 60000000 && Property[i][pPrice] < 80000000)//60kk dom
		{
		    SetPlayerPos(playerid, 2496.0002,-1692.0852,1014.7422); SetPlayerFacingAngle(playerid, 180.0); SetPlayerInterior(playerid,3);
		}
		else if (Property[i][pPrice] >= 80000000)//80kk dom
		{
		    SetPlayerPos(playerid, 2270.4172,-1210.4956,1047.5625); SetPlayerFacingAngle(playerid, 90.0); SetPlayerInterior(playerid,10);
		}
		if (Property[i][pBuyBlock] > 0)//Неперекупаемый дом
		{
		    SetPlayerPos(playerid, 2324.4902,-1149.5474,1050.7101); SetPlayerFacingAngle(playerid, 0.0); SetPlayerInterior(playerid,12);
		}
		SetCameraBehindPlayer(playerid);SetPlayerVirtualWorld(playerid, 1000 + i);
		InPeacefulZone[playerid] = 1;
	}
	return 1;
}//вход в дом

if(!strcmp(cmd, "/openhouse", true))
{//открыть\закрыть дом
    new i = LastHouseVisited[playerid];
	if (i < 1 || i == MAX_PROPERTY) return 1;
	if (PlayerToPoint(3.0,playerid, Property[i][pPosEnterX], Property[i][pPosEnterY], Property[i][pPosEnterZ]))
	{
   		if(strcmp(Property[i][pOwner], PlayerName[playerid], true)) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Это не ваш дом");
		if (Property[i][pOpened] == 0)
		{//Открываем дом
		    Property[i][pOpened] = 1; SaveProperty(i);
		    SendClientMessage(playerid, COLOR_CLAN, "Теперь любой желающий может войти в ваш дом!");
		}//Открываем дом
		else
		{//закрываем дом
		    Property[i][pOpened] = 0; SaveProperty(i);
		    SendClientMessage(playerid, COLOR_RED, "Теперь только вы можете зайти в ваш дом!");
		}//закрываем дом
	}
	return 1;
}//открыть\закрыть дом

/*if(!strcmp(cmd, "/base", true))
{//штаб
	new i = LastBaseVisited[playerid], clanid = Player[playerid][MyClan];
	if (i < 1 || i == MAX_BASE) return 1;
	if (PlayerToPoint(3.0,playerid, Base[i][bPosEnterX], Base[i][bPosEnterY], Base[i][bPosEnterZ]))
	{//игрок рядом со штабом
		if (Clan[clanid][cBase] == i)//штаб клана игрока
			ShowPlayerDialog(playerid, DIALOG_BASEMENU, 2, "{007FFF}Штаб", "{008D00}Войти в штаб{FFFFFF}\nИнформация о штабе\nКупить штаб\nПродать штаб\nУвеличить цену штаба\nСделать местом респавна (Снаружи штаба)\nСделать местом респавна (Внутри штаба)", "ОК", "Отмена");
		else //чужой штаб
			ShowPlayerDialog(playerid, DIALOG_BASEMENU, 2, "{007FFF}Штаб", "{008D00}Войти в штаб{FFFFFF}\nИнформация о штабе\nКупить штаб", "ОК", "Отмена");
	}//игрок рядом со штабом
	return 1;
}//штаб*/


if(!strcmp(cmd, "/buyhouse", true))
{//покупка дома
    if (GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Покупать недвижимость можно только в общем игровом мире.");
	if (PrestigeGM[playerid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя покупать недвижимость в режиме Бога.");
	if (Player[playerid][Level] < 10 && Player[playerid][Prestige] == 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Вам нужен как минимум 10 уровень чтобы купить дом.");
	new i = LastHouseVisited[playerid];
	if (i < 1 || i == MAX_PROPERTY) return 1;
	if (PlayerToPoint(3.0,playerid, Property[i][pPosEnterX], Property[i][pPosEnterY], Property[i][pPosEnterZ]))
	{
		new text3d[MAX_3DTEXT];
		if(Player[playerid][Home] > 0)return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: У вас уже есть дом");
		if(Property[i][pBuyBlock] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Этот дом не продается");
		if(Property[i][pPrice] > Player[playerid][Cash]) return ShowMoneyWant(playerid,0);
        if (strcmp(Property[i][pOwner], "Unknown"))
        {//Дом кому-то принадлежит
            new OwnerOnline = 0;
            foreach(Player, cid)
            {//цикл
                if (!strcmp(PlayerName[cid], Property[i][pOwner]) && Logged[cid])
                {//старый владелец дома
                    Player[cid][Bank] += Property[i][pPrice] / 100 * 85;//Возврат денег в банк (учитывая налог -15%)
                    Player[cid][Home] = 0;
					SavePlayer(cid);
					OwnerOnline = 1;
                    if (Player[cid][Spawn] == 4 || Player[cid][Spawn] == 6 || Player[cid][Spawn] == 7) Player[cid][Spawn] = 0;
					new String[80];
					format(String,sizeof(String),"Ваш дом перекупили! На ваш банковский счет было возвращено {FFFFFF}%d{FF0000}$",Property[i][pPrice] / 100 * 85);
					SendClientMessage(playerid,COLOR_RED,String);
				}//старый владелец дома
            }//цикл
            if (OwnerOnline == 0)
            {//Владелец дома не в сети
                new stringer[120];
				mysql_format(connects, stringer, 120, "SELECT `Bank`,`Spawn` FROM `accounts` WHERE `PName` = '%s'", Property[i][pOwner]);
				mysql_tquery(connects, stringer, "OffHUpdate", "sd", Property[i][pOwner],i);
            }//Владелец дома не в сети
        }//Дом кому-то принадлежит

		Player[playerid][Cash] -= Property[i][pPrice];
		strmid(Property[i][pOwner], PlayerName[playerid], 0, strlen(PlayerName[playerid]), MAX_PLAYER_NAME);
		Player[playerid][Home] = i; Property[i][pOpened] = 0;
		format(text3d, sizeof(text3d), "{00FF00}Дом ({FFFFFF}%d${00FF00})\n{007FFF}Владелец:{FFFFFF} %s\nНажмите [{FFFF00}Alt{FFFFFF}] чтобы использовать", Property[i][pPrice], Property[i][pOwner]);
		UpdateDynamic3DTextLabelText(PropertyText3D[i], 0xFFFFFFFF, text3d);
		SendClientMessage(playerid, COLOR_GREEN, "Поздравляем! Вы успешно купили дом!");
		SavePlayer(playerid); SaveProperty(i);
	}
	return 1;
}//покупка дома

if(!strcmp(cmd, "/buybase", true))
{//покупка штаба
    if (GetPlayerVirtualWorld(playerid) != 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Покупать недвижимость можно только в общем игровом мире.");
	if (PrestigeGM[playerid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя покупать недвижимость в режиме Бога.");
	new i = LastBaseVisited[playerid];
	if (i < 1 || i == MAX_BASE) return 1;
	if (PlayerToPoint(3.0,playerid, Base[i][bPosEnterX], Base[i][bPosEnterY], Base[i][bPosEnterZ]))
	{
	    if(Player[playerid][Leader] != 100)return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Только лидер клана может покупать штаб");
	    if(Player[playerid][MyClan] == 0)return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Вы не в клане");
	    new clanid = Player[playerid][MyClan];
		if(strcmp(Clan[clanid][cLider], PlayerName[playerid])) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Только лидер клана может покупать штаб");
	    if(Clan[clanid][cBase] > 0)return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: У клана уже есть штаб");
		if(Base[i][bPrice] < 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Этот штаб не продается");
		if(Base[i][bPrice] > Player[playerid][Cash]) return ShowMoneyWant(playerid,0);

		if(Base[i][bClan] > 0)
		{//если штаб кому-то принадлежит
		    new LiderOnline = 0, victimclan = Base[i][bClan];
		    Clan[victimclan][cLastDay] = DateToIntDate(Day, Month, Year) + 7;//Удаление клана через неделю
		    foreach(Player, cid)
			{//цикл
				if(!strcmp(Clan[victimclan][cLider], PlayerName[cid]) && Logged[cid])
				{//лидер клана, у которого перекупили штаб - онлайн
					new String[80]; format(String, sizeof String, "Ваш штаб перекупили! На ваш банковский счет было возвращено {FFFFFF}%d{FF0000}$", Base[i][bPrice] / 100 * 85);
				    SendClientMessage(cid,COLOR_RED,String);
				    Player[cid][Bank] += Base[i][bPrice] / 100 * 85; LiderOnline = 1;
				    if (Player[cid][Spawn] == 5 || Player[cid][Spawn] == 8) Player[cid][Spawn] = 0;
				}//лидер клана, у которого перекупили штаб - онлайн
			}//цикл
			if (LiderOnline == 0) Clan[victimclan][cBase] = Base[i][bPrice] / 100 * 85; //Если лидер офлайн - ему вернутся деньги за штаб при входе с учетом комиссии -15%
			else Clan[victimclan][cBase] = 0; 
			SaveClan(victimclan);
		}//если штаб кому-то принадлежит

		Player[playerid][Cash] -= Base[i][bPrice];
		Base[i][bClan] = Player[playerid][MyClan]; SaveBase(i);//записался клан в файл штаба
		Clan[clanid][cBase] = i; Clan[clanid][cLastDay] = 0; SaveClan(clanid);
		new text3d[MAX_3DTEXT], ccolor = Clan[clanid][cColor];
		format(text3d, sizeof(text3d), "{007FFF}Штаб ({FFFFFF}%d${007FFF})\n{008E00}Клан:{FFFFFF} %s\nНажмите [{FFFF00}Alt{FFFFFF}] чтобы использовать", Base[i][bPrice], Clan[clanid][cName]);
		UpdateDynamic3DTextLabelText(BaseText3D[i], 0xFFFFFFFF, text3d);
		SendClientMessage(playerid, ClanColor[ccolor], "Поздравляем! Вы успешно купили штаб!");
		SavePlayer(playerid);
	}
	return 1;
}//покупка штаба


if(!strcmp(cmd, "/sellhouse", true))
{
	new i = LastHouseVisited[playerid];
	if (i < 1 || i == MAX_PROPERTY) return 1;
	if (PlayerToPoint(3.0,playerid, Property[i][pPosEnterX], Property[i][pPosEnterY], Property[i][pPosEnterZ]))
	{
		new text3d[MAX_3DTEXT], String[140];
		if(strcmp(Property[i][pOwner], PlayerName[playerid], true)) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Это не ваш дом");
		if (Property[i][pBuyBlock] > 0)
		{//Если дом неперекупаемый
		    new days = Property[i][pBuyBlock] - DateToIntDate(Day, Month, Year), rmedals = 0;
		    Property[i][pBuyBlock] = 0;//чтобы дом стал перекупаемым
			if (days >= 0)
			{
			    if (days <= 1) rmedals = 1; else rmedals = days * 2;
			    Player[playerid][Medals] += rmedals;
			    format(String, sizeof String, "Вам было возвращено {FFFFFF}%d Медалей{FFFF00} за оставшиеся дни услуги 'Неперекупаемый дом'.", rmedals);
			    SendClientMessage(playerid, COLOR_YELLOW, String);
			}
		}//Если дом неперекупаемый

		Property[i][pPrice] -= Property[i][pPrice] / 100 * 15;//При продаже дома взымается налог 15% от его стоимости
		Player[playerid][Cash] += Property[i][pPrice];
		format(String,sizeof(String),"{00FF00}Вы успешно продали свой дом за {FFFFFF}%d{00FF00}$",Property[i][pPrice]);
		SendClientMessage(playerid,COLOR_GREEN,String);
		Property[i][pPrice] = 10000000; Property[i][pOpened] = 0; Player[playerid][Home] = 0;
		strmid(Property[i][pOwner], "Unknown", 0, strlen("Unknown"), 9);
		//strmid(Property[i][pOwner], GetName(playerid), 0, strlen(GetName(playerid)), MAX_PLAYER_NAME);
		format(text3d, sizeof(text3d), "{00FF00}Дом ({FFFFFF}%d${00FF00})\n{007FFF}Владелец:{FFFFFF} %s\nНажмите [{FFFF00}Alt{FFFFFF}] чтобы использовать", Property[i][pPrice], Property[i][pOwner]);
		UpdateDynamic3DTextLabelText(PropertyText3D[i], 0xFFFFFFFF, text3d);
		if (Player[playerid][Spawn] == 4 || Player[playerid][Spawn] == 6 || Player[playerid][Spawn] == 7){Player[playerid][Spawn] = 0;}
		SavePlayer(playerid); SaveProperty(i);
	}
	return 1;
}

if(!strcmp(cmd, "/sellbase", true))
{
new i = LastBaseVisited[playerid];
	if (i < 1 || i == MAX_BASE) return 1;
	if (PlayerToPoint(3.0,playerid, Base[i][bPosEnterX], Base[i][bPosEnterY], Base[i][bPosEnterZ]))
	{
		if(Base[i][bClan] != Player[playerid][MyClan]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Этот штаб не принадлежит вашему клану");
		if(Player[playerid][Leader] != 100) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Только лидер клана может продавать штаб");
	    new text3d[MAX_3DTEXT], clanid = Player[playerid][MyClan];
		if(strcmp(Clan[clanid][cLider], PlayerName[playerid])) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Только лидер клана может продавать штаб");
		
		Base[i][bPrice] -= Base[i][bPrice] / 100 * 15;//При продаже штаба взымается налог 15% от его стоимости
		Player[playerid][Cash] += Base[i][bPrice];
		new String[80]; format(String,sizeof(String),"{008E00}Вы успешно продали свой штаб за {FFFFFF}%d{008E00}$",Base[i][bPrice]);
		SendClientMessage(playerid,COLOR_GREEN,String);
		Base[i][bPrice] = 10000000; Base[i][bClan] = 0; Clan[clanid][cBase] = 0;	
		format(text3d, sizeof(text3d), "{007FFF}Штаб ({FFFFFF}%d${007FFF})\n{008E00}Клан:{FFFFFF} Никто\nНажмите [{FFFF00}Alt{FFFFFF}] чтобы использовать", Base[i][bPrice]);
		UpdateDynamic3DTextLabelText(BaseText3D[i], 0xFFFFFFFF, text3d);
		if(Player[playerid][Spawn] == 5 || Player[playerid][Spawn] == 8) Player[playerid][Spawn] = 0;
		Clan[clanid][cLastDay] = DateToIntDate(Day, Month, Year) + 7;//Удаление клана через неделю
		SavePlayer(playerid); SaveBase(i); SaveClan(clanid);
	}
	return 1;
}



if(!strcmp(cmd, "/houseinfo", true))
{
	new i = LastHouseVisited[playerid];
	if (i < 1 || i == MAX_PROPERTY) return 1;
	if (PlayerToPoint(3.0,playerid, Property[i][pPosEnterX], Property[i][pPosEnterY], Property[i][pPosEnterZ]))
	{
		new string[MAX_DIALOG_INFO];
		if(Property[i][pBuyBlock] > 0) {format(string, sizeof(string), "{FF0000}Не продается до %s\n{FFFF00}Тип: {00FF00}Дом\n{FFFF00}ID: {FFFFFF}%d\n{FFFF00}Стоимость: {FFFFFF}%d$\n{FFFF00}Владелец:{FFFFFF} %s", IntDateToStringDate(Property[i][pBuyBlock]), i, Property[i][pPrice], Property[i][pOwner]);}
		else {format(string, sizeof(string), "{FFFF00}Тип: {00FF00}Дом\n{FFFF00}ID: {FFFFFF}%d\n{FFFF00}Стоимость: {FFFFFF}%d$\n{FFFF00}Владелец:{FFFFFF} %s", i, Property[i][pPrice], Property[i][pOwner]);}
		ShowPlayerDialog(playerid, DIALOG_OTHER, DIALOG_STYLE_MSGBOX, "Информация о собственности", string, "Закрыть", "");
	}
	return 1;
}

if(!strcmp(cmd, "/baseinfo", true))
{
	new i = LastBaseVisited[playerid];
	if (i < 1 || i == MAX_BASE) return 1;
	if (PlayerToPoint(3.0,playerid, Base[i][bPosEnterX], Base[i][bPosEnterY], Base[i][bPosEnterZ]))
	{
		new string[MAX_DIALOG_INFO], clanid = Base[i][bClan];
		if(Base[i][bPrice] <= 0 && clanid > 0) {format(string, sizeof(string), "{FFFF00}Тип: {007FFF}Штаб\n{FFFF00}ID: {FFFFFF}%d\n{FFFF00}Стоимость: {FF0000}Не продается\n{FFFF00}Клан:{FFFFFF} %s {008E00}[ID:{FFFFFF}%d{008E00}]", i, Clan[clanid][cName], clanid);}
		if(Base[i][bPrice] <= 0 && clanid == 0) {format(string, sizeof(string), "{FFFF00}Тип: {007FFF}Штаб\n{FFFF00}ID: {FFFFFF}%d\n{FFFF00}Стоимость: {FF0000}Не продается\n{FFFF00}Клан:{FFFFFF} Никто", i);}
		if(Base[i][bPrice] >= 1 && clanid > 0) {format(string, sizeof(string), "{FFFF00}Тип: {007FFF}Штаб\n{FFFF00}ID: {FFFFFF}%d\n{FFFF00}Стоимость: {FFFFFF}%d$\n{FFFF00}Клан:{FFFFFF} %s {008E00}[ID:{FFFFFF}%d{008E00}]", i, Base[i][bPrice], Clan[clanid][cName], clanid);}
		if(Base[i][bPrice] >= 1 && clanid == 0) {format(string, sizeof(string), "{FFFF00}Тип: {007FFF}Штаб\n{FFFF00}ID: {FFFFFF}%d\n{FFFF00}Стоимость: {FFFFFF}%d$\n{FFFF00}Клан:{FFFFFF} Никто", i, Base[i][bPrice]);}
		ShowPlayerDialog(playerid, DIALOG_OTHER, DIALOG_STYLE_MSGBOX, "Информация о собственности", string, "Закрыть", "");
	}
	return 1;
}


// Админка
/*if(!strcmp(cmd, "/addhouse", true))
{
	if(Player[playerid][Admin] < 4) return 1;
	if(sscanf(params,"s[32]", Property[LastProperty][pName]))
	return SendClientMessage(playerid, COLOR_WHITE, "Используйте: /addhouse [name]");
	Property[LastProperty][pPrice] = 10000000;
	new filename[MAX_FILE_NAME], file, text3d[MAX_3DTEXT];
	GetPlayerPos(playerid, Property[LastProperty][pPosEnterX], Property[LastProperty][pPosEnterY], Property[LastProperty][pPosEnterZ]);
	GetPlayerFacingAngle(playerid, Property[LastProperty][pPosEnterA]);
	strmid(Property[LastProperty][pOwner], "Никто", 0, strlen("Никто"), 7);

	format(text3d, sizeof(text3d), "{00FF00}Дом ({FFFFFF}%d${00FF00})\n{007FFF}Владелец:{FFFFFF} %s\nНажмите [{FFFF00}Alt{FFFFFF}] чтобы использовать", Property[LastProperty][pPrice], Property[LastProperty][pOwner]);
	PropertyText3D[LastProperty] = CreateDynamic3DTextLabel(text3d, COLOR_WHITE, Property[LastProperty][pPosEnterX], Property[LastProperty][pPosEnterY], Property[LastProperty][pPosEnterZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
	PropertyPickup[LastProperty] = CreateDynamicPickup(1273, 1, Property[LastProperty][pPosEnterX], Property[LastProperty][pPosEnterY], Property[LastProperty][pPosEnterZ], -1, -1, -1, 100.0);
	PropertyMapIcon[LastProperty] = CreateDynamicMapIcon(Property[LastProperty][pPosEnterX], Property[LastProperty][pPosEnterY], Property[LastProperty][pPosEnterZ], 31, 0, -1, -1, -1, 100.0);

	format(filename, sizeof(filename), "PlayerHouses/%i.ini", LastProperty);
	file = ini_createFile(filename);
	if(file < 0) file = ini_openFile (filename);
	if(file >= 0)
	{
		ini_setString(file, "Name", Property[LastProperty][pName]);
		ini_closeFile(file);
	}

	new String[80];format(String,sizeof(String),"ID дома: {FFFFFF}%d",LastProperty);
	SendClientMessage(playerid,COLOR_GREEN,String);

	SaveAllProperty();LastProperty++;
	return 1;
}*/
/*
if(!strcmp(cmd, "/addbase", true))
{
	if(Player[playerid][Admin] < 4) return 1;
	new filename[MAX_FILE_NAME], file, text3d[MAX_3DTEXT];
	GetPlayerPos(playerid, Base[LastBase][bPosEnterX], Base[LastBase][bPosEnterY], Base[LastBase][bPosEnterZ]);
	GetPlayerFacingAngle(playerid, Base[LastBase][bPosEnterA]);
	Base[LastBase][bClan] = 0;
    Base[LastBase][bPrice] = 10000000;
	format(text3d, sizeof(text3d), "{007FFF}Штаб ({FFFFFF}%d${007FFF})\n{008E00}Клан:{FFFFFF} Никто\nНажмите [{FFFF00}Alt{FFFFFF}] чтобы использовать", Base[LastBase][bPrice]);
	BaseText3D[LastBase] = CreateDynamic3DTextLabel(text3d, COLOR_WHITE, Base[LastBase][bPosEnterX], Base[LastBase][bPosEnterY], Base[LastBase][bPosEnterZ], 10.0, INVALID_PLAYER_ID, INVALID_VEHICLE_ID, 0, 0, 0, -1);
	BasePickup[LastBase] = CreateDynamicPickup(1272, 1, Base[LastBase][bPosEnterX], Base[LastBase][bPosEnterY], Base[LastBase][bPosEnterZ], -1, -1, -1, 100.0);
	BaseMapIcon[LastBase] = CreateDynamicMapIcon(Base[LastBase][bPosEnterX], Base[LastBase][bPosEnterY], Base[LastBase][bPosEnterZ], 32, 0, -1, -1, -1, 100.0);

	format(filename, sizeof(filename), "Base/%i.ini", LastBase);
	file = ini_createFile(filename);
	if(file < 0) file = ini_openFile (filename);
	if(file >= 0)
	{
		ini_setInteger(file, "Price", Base[LastBase][bPrice]);
		ini_closeFile(file);
	}

	new String[80];format(String,sizeof(String),"ID штаба: {FFFFFF}%d",LastBase);
	SendClientMessage(playerid,COLOR_GREEN,String);

	SaveAllBase();LastBase++;
	return 1;
}
*/
/*
if(!strcmp(cmd, "/ahouse", true))
{
	if(Player[playerid][Admin] < 4) return 1;
	new option[MAX_STRING], houseid;
	if(sscanf(params,"is[32]", houseid, option))
	return SendClientMessage(playerid, COLOR_WHITE, "Используйте: /ahouse [id] respawn или /ahouse [id] setrespawn");
	if(!strcmp(option, "setrespawn"))
	{
		GetPlayerPos(playerid, Property[houseid][pPosRespawnX], Property[houseid][pPosRespawnY], Property[houseid][pPosRespawnZ]);
		GetPlayerFacingAngle(playerid, Property[houseid][pPosRespawnA]);
		SendClientMessage(playerid, 0xFF0000AA, "Респавн установлен");
		SaveProperty(houseid);
		return 1;
	}
	if(!strcmp(option, "respawn"))
	{
		SetPlayerPos(playerid, Property[houseid][pPosRespawnX], Property[houseid][pPosRespawnY], Property[houseid][pPosRespawnZ]);
		SetPlayerFacingAngle(playerid, Property[houseid][pPosRespawnA]);
		SendClientMessage(playerid, 0xFF0000AA, "Вы перемещены на респавн этого дома");
		return 1;
	}
	return 1;
}
*/
/*
if(!strcmp(cmd, "/abase", true))
{
	if(Player[playerid][Admin] < 4) return 1;
	new option[MAX_STRING], houseid;
	if(sscanf(params,"is[32]", houseid, option))
	return SendClientMessage(playerid, COLOR_WHITE, "Используйте: /abase [id] respawn или /abase [id] setrespawn");
	if(!strcmp(option, "setrespawn"))
	{
		GetPlayerPos(playerid, Base[houseid][bPosRespawnX], Base[houseid][bPosRespawnY], Base[houseid][bPosRespawnZ]);
		GetPlayerFacingAngle(playerid, Base[houseid][bPosRespawnA]);
		SendClientMessage(playerid, 0xFF0000AA, "Респавн установлен");
		SaveBase(houseid);
		return 1;
	}
	if(!strcmp(option, "respawn"))
	{
		SetPlayerPos(playerid, Base[houseid][bPosRespawnX], Base[houseid][bPosRespawnY], Base[houseid][bPosRespawnZ]);
		SetPlayerFacingAngle(playerid, Base[houseid][bPosRespawnA]);
		SendClientMessage(playerid, 0xFF0000AA, "Вы перемещены на респавн этого штаба");
		return 1;
	}
	return 1;
}*/

/*if(!strcmp(cmd, "/resclan", true))
{
    if (Player[playerid][Admin] != 4) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА!");
    new summ=0;
    for(new i = 1; i < MAX_CLAN; i++)
	{//все возможные id`ы кланов
		if (Clan[i][cLevel] == 0) continue; //Пропускаем несуществующие кланы
		summ=0;
		summ += Clan[i][ClanBank];
    	if(Clan[i][cBase] > 0 && Clan[i][cBase] < MAX_BASE)
    	{
    	    new basa = Clan[i][cBase];
    	    summ += Base[basa][bPrice];
		}
		if(summ != 0)
		{
		    new query[256];
			mysql_format(connects,query, sizeof(query), "UPDATE `pupdate` SET `ABank` = '%d' WHERE `PName` = '%s';",summ,Clan[i][cLider]);
			mysql_tquery(connects, query);
		}
	SendClientMessage(playerid,COLOR_RED,"готово");
	}//все возможные id`ы кланов
	return 1;
}*/
