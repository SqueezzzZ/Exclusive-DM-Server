if(!strcmp(cmd, "/say", true)) // zcmd command
{
	if (Player[playerid][Admin] < 1) return 1;
	if (Player[playerid][Muted] != 0) return SendClientMessage(playerid,COLOR_RED,"Вам запрещено отправлять сообщения");
	if (!strlen(params)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используйте /say [text]");
	new string[140];
	if (Player[playerid][Admin] == 1)
	{
		format(string,sizeof(string),"MODER: %s",params);
		SendClientMessageToAll(COLOR_MODER,string);
	}
	if (Player[playerid][Admin] == 2)
	{
		format(string,sizeof(string),"SUPERMODER: %s",params);
		SendClientMessageToAll(COLOR_SUPERMODER,string);
	}
	if (Player[playerid][Admin] == 3)
	{
		format(string,sizeof(string),"ADMIN: %s",params);
		SendClientMessageToAll(COLOR_ADMIN,string);
	}
	if (Player[playerid][Admin] >= 4)
	{
		format(string,sizeof(string),"Главный ADMIN: %s",params);
		SendClientMessageToAll(COLOR_ROOT,string);
	}
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /say %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, params);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}


/////////////Модераторские команды
if(!strcmp(cmd, "/tele", true)) // zcmd command
{
	if (Player[playerid][Admin] < 1) return 1;
	if (InEvent[playerid] == 1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя телепортироваться в соревнованиях");
	if (QuestActive[playerid] > 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя телепортироваться при выполнении задания");
	if (LSpecID[playerid] > -1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя телепортироваться во время слежки");
	new targetid, option[10];//переменая куда занесется значение которое введет игрок 
	new Float:posX, Float:posY, Float:posZ, string[140],int,wrld;
	if(sscanf(params,"s[10]i", option, targetid))//
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй '/tele to [id игрока]' или '/tele here [id игрока]'");//если игрок не ввел значение то выдаем собщение 
	if (InEvent[playerid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать телепортацию во время участия в соревнованиях");
	if(!strcmp(option, "to"))
	{//to
		if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
		if (InEvent[targetid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя телепортироваться к этому игроку так как он участвует в соревнованиях");
		if (LSpecID[targetid] > -1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Этот игрок находится в режиме слежки.");
		GetPlayerPos(targetid,posX,posY,posZ);wrld = GetPlayerVirtualWorld(targetid);int = GetPlayerInterior(targetid);
		SetPlayerPos(playerid,posX+1,posY,posZ); SetPlayerVirtualWorld(playerid,wrld); SetPlayerInterior(playerid,int);
		SetPlayerWeather(playerid, 10);
		format(string, sizeof(string), "SERVER: Вы телепортировались к игроку %s[%d]", PlayerName[targetid], targetid); SendClientMessage(playerid,COLOR_MODER,string);
		SetPlayerChatBubble(playerid, "Телепортировался", 0x00FF00FF, 300.0, 3000);
		LACSH[playerid] = 3;AdminTPCantKill[playerid] = 20;
		format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /tele %s %s[%i]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, option, PlayerName[targetid], targetid);
		WriteLog("GlobalLog", string);WriteLog("Admin", string);
	}//to
	if(!strcmp(option, "here"))
	{//here
		if (Player[playerid][Admin] < 2) return SendClientMessage(playerid, COLOR_RED, "Вы должны быть супер-модератором, чтобы телепортировать к себе других игроков");
		if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
		if (Player[targetid][Admin] > Player[playerid][Admin] && Player[targetid][Admin] != 5) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя телепортировать игрока, который выше вас по статусу");
		if (InEvent[targetid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя телепортировать этого игрока так как он участвует в соревнованиях");
		GetPlayerPos(playerid,posX,posY,posZ);wrld = GetPlayerVirtualWorld(playerid);int = GetPlayerInterior(playerid);
		SetPlayerPos(targetid,posX+1,posY,posZ); SetPlayerVirtualWorld(targetid,wrld); SetPlayerInterior(targetid,int);
		SetPlayerWeather(targetid, 10);
		if (wrld == 666){SetPlayerWeather(targetid, -66);}
		format(string, sizeof(string), "SERVER: Вы телепортировали к себе игрока %s[%d]", PlayerName[targetid], targetid); SendClientMessage(playerid,COLOR_MODER,string);
		if (Player[playerid][Admin] < 3) {format(string, sizeof(string), "SERVER: Модератор %s[%d] телепортировал вас к себе", PlayerName[playerid], playerid); SendClientMessage(targetid,COLOR_MODER,string);}
		else {format(string, sizeof(string), "SERVER: Администратор %s[%d] телепортировал вас к себе", PlayerName[playerid], playerid); SendClientMessage(targetid,COLOR_MODER,string);}
		SetPlayerChatBubble(targetid, "Телепортировался", 0x00FF00FF, 300.0, 3000);
		LACSH[targetid] = 3;AdminTPCantKill[targetid] = 20;AdminTPCantKill[playerid] = 20;
		format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /tele %s %s[%i]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, option, PlayerName[targetid], targetid);
		WriteLog("GlobalLog", string);WriteLog("Admin", string);
	}//here	
	return 1;
}

if(!strcmp(cmd, "/mute", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] == 0) return 1;
	new targetid, string[140], mtime;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"id", targetid, mtime))//занесем значение которе ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /Muted [id игрока] [минут]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	if (Player[targetid][Admin] > Player[playerid][Admin] && Player[targetid][Admin] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя заткнуть игрока, который выше вас по статусу");
	if (Player[targetid][Muted] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Этот игрок уже имеет затычку чата");
	if (mtime < 5) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Срок 'муты' должен быть от 5 минут до 15 часов");
	if (mtime > 900) mtime = 900;//макс. 15 часов
	if (mtime < 60)
	{
		if (Player[playerid][Admin] <= 2) format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был заткнут модератором %s[%d] на %d минут.", PlayerName[targetid],targetid, PlayerName[playerid], playerid, mtime);
		else format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был заткнут администратором %s[%d] на %d минут.", PlayerName[targetid],targetid, PlayerName[playerid], playerid, mtime);
	}
	else
	{
		new hourM = mtime / 60;
		if (Player[playerid][Admin] <= 2) format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был заткнут модератором %s[%d] на %d часов %d минут.", PlayerName[targetid],targetid, PlayerName[playerid], playerid, hourM, mtime - hourM*60);
		else format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был заткнут администратором %s[%d] на %d часов %d минут.", PlayerName[targetid],targetid, PlayerName[playerid], playerid, hourM, mtime - hourM*60);
	}
	if (Player[playerid][Admin] != 5) {SendClientMessageToAll(COLOR_MODER,string);}
	
	Player[targetid][Muted] = mtime * 60;
	if (Player[playerid][Admin] != 5) {strmid(MutedBy[targetid], PlayerName[playerid], 0, 25, 25);}
	else {strmid(MutedBy[targetid], "SERVER", 0, 25, 25);}
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /mute %s[%i] %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid, mtime);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/unmute", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 1){return 1;}//Как минимум обычный модер
	new targetid, string[140];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"i", targetid))//занесем значение которе ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /unmute [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); return 1;} 
	if (Player[targetid][Muted] == 0) return SendClientMessage(playerid, COLOR_RED, "Этот игрок итак не заткнут");
	if (Player[playerid][Admin] < 3 && strcmp(PlayerName[playerid], MutedBy[targetid])) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Вы можете снимать только свои затычки");

	if (Player[playerid][Admin] <= 2) format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] получил свободу слова от модератора %s[%d].", PlayerName[targetid],targetid, PlayerName[playerid], playerid);
	else format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] получил свободу слова от администратора %s[%d].", PlayerName[targetid],targetid, PlayerName[playerid], playerid);
	if (Player[playerid][Admin] != 5) {SendClientMessageToAll(COLOR_MODER,string);}
	Player[targetid][Muted] = 0;
	strmid(MutedBy[targetid], "ПУСТО", 0, strlen("ПУСТО"), 5);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /unmute %s[%i]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/ban", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 1) return 1;//Как минимум обычный модер
	new targetid, string[140], stringP[41];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"is[40]", targetid, stringP) || strlen(stringP) < 2)//занесем значение которе ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /ban [id игрока] [причина]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	if (Player[targetid][Admin] > Player[playerid][Admin]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя забанить игрока, который выше вас по статусу");
	if (Player[targetid][Banned] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Этот игрок уже забанен");

	if (Player[playerid][Admin] <= 2) format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был забанен модератором %s[%d]. {FF0000}Причина: {AFAFAF}%s.", PlayerName[targetid], targetid, PlayerName[playerid], playerid, stringP);
	else format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был забанен администратором %s[%d]. {FF0000}Причина: {AFAFAF}%s.", PlayerName[targetid], targetid, PlayerName[playerid], playerid, stringP);
	if (Player[playerid][Admin] != 5) {SendClientMessageToAll(COLOR_MODER,string);}
	InEvent[targetid] = 0;
	JoinEvent[targetid] = 0;
	Player[targetid][Banned] = 1;
	
	strmid(BanReason[targetid], stringP, 0, 41, 41);
	if (Player[playerid][Admin] != 5) {strmid(BannedBy[targetid], PlayerName[playerid], 0, 25, 25);}
	else strmid(BannedBy[targetid], "SERVER", 0, 25, 25);

	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /ban %s[%i] %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid, stringP);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);WriteLog("Bans", string);
	return 1;
}

if(!strcmp(cmd, "/kick", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 1) return 1;//Как минимум обычный модер
	new targetid, string[180], stringP[80];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"is[80]", targetid, stringP) || strlen(stringP) < 3)//занесем значение которе ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /kick [id игрока] [причина]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	if (Player[targetid][Admin] > Player[playerid][Admin]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя кикнуть игрока, который выше вас по статусу");

	if (Player[playerid][Admin] <= 2) format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был кикнут модератором %s[%d]. {FF0000}Причина: {AFAFAF}%s.", PlayerName[targetid], targetid, PlayerName[playerid], playerid, stringP);
	else format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был кикнут администратором %s[%d]. {FF0000}Причина: {AFAFAF}%s.", PlayerName[targetid], targetid, PlayerName[playerid], playerid, stringP);
	if (Player[playerid][Admin] != 5) {SendClientMessageToAll(COLOR_MODER,string);}
	SavePlayer(targetid);
	GKick(targetid);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /kick %s[%i] %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid, stringP);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/cc", true)) return SendCommand(playerid, "/clearchat", "");
if(!strcmp(cmd, "/cchat", true)) return SendCommand(playerid, "/clearchat", "");
if(!strcmp(cmd, "/chatclear", true)) return SendCommand(playerid, "/clearchat", "");
if(!strcmp(cmd, "/clearchat", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 1){return 1;}//Как минимум обычный модер
	for(new i = 0; i < 100; i++){SendClientMessageToAll(-1,"");}
	SendClientMessageToAll(-1,"{AFAFAF}SERVER: Чат был очищен.");
	new string[120];format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /clearchat", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/aplay", true))
{
	if (Player[playerid][Admin] < 3)
	{
		if(Player[playerid][Mrf1] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Вам недоступна эта команда!");
		new mtime = gettime()-APlayTime;
		if(mtime < 240)
		{
		    new string[120];format(string, sizeof string, "Заказ музыки будет доступен через {ffffff}%d{ff0000} сек.", 240-mtime);
		    SendClientMessage(playerid,COLOR_RED,string);
		    return 1;
		}
	}
	ShowPlayerDialog(playerid, DIALOG_APLAY, DIALOG_STYLE_INPUT, "{2E9AFE}Музыкальный плеер:", "{ffffff}Введите ссылку на музыку или радио!\n\nРазрешены ссылки с GoogleDrive, f-bit.ru или прямые ссылки на радио!\n\n{FAAC58}Внимание! Инструкцию по воспроизведению можно найти в группе vk.com/esampdm!","Играть!", "Закрыть");
	return 1;
}

if(!strcmp(cmd, "/fixzones", true))
{
	if (Player[playerid][Admin] != 4) return 1;//Как минимум гл. admin
	for(new i = 1; i <= MaxClanID; i++) {if (Clan[i][cLevel] > 0) Clan[i][ClanZones]=0;}
	for (new Zone=1; Zone<MAX_GZONE;Zone++)
 	{
 	    if(GangZones[Zone][GZOwner] > 0) {Clan[GangZones[Zone][GZOwner]][ClanZones]++; SaveClan(GangZones[Zone][GZOwner]);}
 	}
 	SendClientMessage(playerid,COLOR_RED,"Территории успешно зафиксированы!");
	return 1;
}

if(!strcmp(cmd, "/kickall", true))
{
	if (Player[playerid][Admin] != 4) return 1;
	new String[140];
	format(String,sizeof(String),"Главный администратор %s[%d] кикнул всех с сервера!",PlayerName[playerid], playerid);
	SendClientMessageToAll(COLOR_GG,String);
	foreach(Player, i)
	{
	    if(i == playerid) continue;
		GKick(i);
	}
	
	return 1;
}

if(!strcmp(cmd, "/setdbonus", true))
{
	if (Player[playerid][Admin] != 4) return 1;
	new Float:bns;
	if(sscanf(params,"%f", bns))//занесем значение которе ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА!");
	if (bns < 1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Бонус должен быть > 1.");
	DBonus = bns;
	
	new String[140];
	format(String,sizeof(String),"Главный администратор %s установил бонус на донат: x %.1f!",PlayerName[playerid], DBonus);
	SendClientMessageToAll(COLOR_GREEN,String);
	SaveServerConfig();
	return 1;
}

if(!strcmp(cmd, "/incar", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 1){return 1;}//Как минимум обычный модер
	if (InEvent[playerid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя использовать телепортацию во время участия в соревнованиях");
	new targetid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"i", targetid))//занесем значение которе ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /incar [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (InEvent[targetid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя телепортироваться к этому игроку так как он участвует в соревнованиях");	
	if (!IsPlayerInAnyVehicle(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрок не находится в транспорте");
	//if (InEvent[targetid] > 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрок участвует в соревновании");
	//if (QuestActive[targetid] > 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрок выполняет задание");
	new targetcar = GetPlayerVehicleID(targetid); new Seats = GetPassengerSeats(targetcar);new wrld = GetPlayerVirtualWorld(targetid);new int = GetPlayerInterior(targetid);
	new S1 = -1, S2 = -1, S3 = -1;
	if (Seats == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В транспорте игрока нет свободного места");
	foreach(Player, cid)
	{//цикл
		if(GetPlayerVehicleID(cid) == targetcar && GetPlayerVehicleSeat(cid) > 0)
		{//кто-то на пассажирском сидении в нужной нам машине
			if(GetPlayerVehicleSeat(cid) == 1){S1 = cid;}
			if(GetPlayerVehicleSeat(cid) == 2){S2 = cid;}
			if(GetPlayerVehicleSeat(cid) == 3){S3 = cid;}
		}//кто-то на пассажирском сидении в нужной нам машине
	}//цикл	
	if (Seats == 1)
	{//если 1 сиденье
		if(S1 > -1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В транспорте игрока нет свободного места");
		else{SetPlayerVirtualWorld(playerid,wrld);PutPlayerInVehicle(playerid,targetcar,1);SetPlayerInterior(playerid,int);SetPlayerChatBubble(playerid, "Телепортировался", 0x00FF00FF, 300.0, 3000);}
	}//если 1 сиденье
	else
	{//если 3 сиденья
		if(S1 == -1){SetPlayerVirtualWorld(playerid,wrld);PutPlayerInVehicle(playerid,targetcar,1);SetPlayerInterior(playerid,int);SetPlayerChatBubble(playerid, "Телепортировался", 0x00FF00FF, 300.0, 3000);}
		else
		{
			if(S2 == -1){SetPlayerVirtualWorld(playerid,wrld);PutPlayerInVehicle(playerid,targetcar,2);SetPlayerInterior(playerid,int);SetPlayerChatBubble(playerid, "Телепортировался", 0x00FF00FF, 300.0, 3000);}
			else
			{
				if(S3 == -1){SetPlayerVirtualWorld(playerid,wrld);PutPlayerInVehicle(playerid,targetcar,3);SetPlayerInterior(playerid,int);SetPlayerChatBubble(playerid, "Телепортировался", 0x00FF00FF, 300.0, 3000);}
				else return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: В транспорте игрока нет свободного места");
			}
		}
	}//если 3 сиденья	
	new string[120], pname[24];GetPlayerName(targetid, pname, sizeof(pname));
	format(string,sizeof(string),"SERVER: Вы телепортировались в машину игрока %s[%d]",pname,targetid);SendClientMessage(playerid,COLOR_MODER,string);
	Player[playerid][CarActive] = 0;LACSH[playerid] = 2; AdminTPCantKill[playerid] = 20;
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /incar %s[%i]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/gmtest", true))
{//команды надо вводить без "/"
	if (Player[playerid][Admin] < 1) return 1;//Как минимум обычный модер
	
	new specplayerid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", specplayerid))//занесем значение которе ввел игрок в переменую skinid 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /gmtest [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(specplayerid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	if (PrestigeGM[specplayerid] == 1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Этот игрок находится в режиме Бога (Престиж 10)");
	if (LSpecID[specplayerid] > -1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Этот игрок находится в режиме слежки...");
	if (IsPlayerInAnyVehicle(specplayerid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Этот игрок находится в транспорте...");
	new string[120], pname[24];GetPlayerName(specplayerid, pname, sizeof(pname));
	format(string,sizeof(string),"GMTest: Началось тестирование игрока %s[%d] на бессмертие..",pname,specplayerid);
	SendClientMessage(playerid,COLOR_YELLOW,string);
	GetPlayerHealth(specplayerid, GMTestHealthOld[specplayerid]);GetPlayerArmour(specplayerid, GMTestArmourOld[specplayerid]);//записываем старые хп и броню
	SetPlayerHealth(specplayerid, 100);SetPlayerArmour(specplayerid,0);
	if (IsPlayerInAnyVehicle(specplayerid)){DestroyVehicle(GetPlayerVehicleID(specplayerid));}
	GMTestStage[specplayerid] = 1;GMTestTime[specplayerid] = 3;//первая стадия: проверка NOP`ов
	GMTesterID[specplayerid] = playerid;
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /gmtest %s[%d]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[specplayerid], specplayerid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/sinfo", true))
{//команды надо вводить без "/"
	if (Player[playerid][Admin] < 1){return 1;}//Любой модер
	
	ShowServerInfo(playerid);
	//new string[120];format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /sinfo", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
	//WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}



if(!strcmp(cmd, "/pinfo", true))
{//команды надо вводить без "/"
	if (Player[playerid][Admin] < 1){return 1;}//Как минимум обычный модер
	
	new targetid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", targetid))//занесем значение которе ввел игрок в переменую skinid 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /pinfo [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); return 1;} 
	ShowPInfo(playerid, targetid);
	//new string[120];format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /pinfo %s[%d]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid);
	//WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
} 




/////////////Супер-Модераторские команды
if(!strcmp(cmd, "/unban", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 1) return 1;
	
	new targetid, string[140], stringP[40];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"is[40]", targetid, stringP) || strlen(stringP) < 3)//занесем значение которе ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /unban [id игрока] [причина]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	if (Player[targetid][Banned] == 0) return SendClientMessage(playerid, COLOR_RED, "Этот игрок не забанен.");
	if (Player[playerid][Admin] < 3 && strcmp(PlayerName[playerid], BannedBy[targetid])) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Вы можете снимать только свои баны");

	if (Player[playerid][Admin] <= 2) format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был разбанен модератором %s[%d]. {FF0000}Причина: {AFAFAF}%s.",  PlayerName[targetid], targetid, PlayerName[playerid], playerid, stringP);
	else format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был разбанен администратором %s[%d]. {FF0000}Причина: {AFAFAF}%s.", PlayerName[targetid], targetid, PlayerName[playerid], playerid, stringP);
	if (Player[playerid][Admin] != 5) {SendClientMessageToAll(COLOR_MODER,string);}
	SetPlayerVirtualWorld(targetid,0);
	SetPlayerInterior(targetid,0);
	SetPlayerWeather(targetid, 10);
	Player[targetid][Banned] = 0;
	strmid(BannedBy[targetid], "ПУСТО", 0, strlen("ПУСТО"), 5);
	strmid(BanReason[targetid], "ПУСТО", 0, strlen("ПУСТО"), 5);
	PlayerWeather[targetid] = -1;
	OnPlayerSpawn(targetid);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /unban %s[%i] %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid, stringP);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/banip", true))
{
	if (Player[playerid][Admin] < 2){return 1;}
	
	new string[120], pid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", pid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /banip [ID Игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(pid)){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); return 1;} 
	if (Player[pid][Admin] > Player[playerid][Admin]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя забанить игрока, который выше вас по статусу");
	format(string, sizeof(string),"Вы забанили игрока %s[%d] по IP", PlayerName[pid], pid);
	SendClientMessage(playerid,COLOR_MODER,string);
	format(string,sizeof(string),"ban %d",pid);	SendRconCommand(string);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /banip %s[%d]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[pid], pid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/setweather", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 2){return 1;}
	
	new targetid, string[120];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"i", targetid) || targetid < 0 || targetid > 19)//занесем значение которе ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /setweather [id погоды] (от 0 до 19)");//если игрок не ввел значение то выдаем собщение 
	ServerWeather = targetid;
	format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] изменил погоду на сервере.", PlayerName[playerid], playerid); SendClientMessageToAll(COLOR_SUPERMODER,string);

	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /setweather %i", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, targetid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/crash", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 4){return 1;}
	
	new targetid, string[140];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"i", targetid))//занесем значение которое ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /crash [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (Player[targetid][Admin] > Player[playerid][Admin]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя применить на игрока, который выше вас по статусу");
	format(string, sizeof(string), "{AFAFAF}SERVER: Вы успешно вызвали samp crash у %s[%d]", PlayerName[targetid],targetid);SendClientMessage(playerid,COLOR_MODER,string); 
	GameTextForPlayer(targetid, "•¤¶§!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/", 1000, 0);
    GameTextForPlayer(targetid, "•¤¶§!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/", 2000, 1);
    GameTextForPlayer(targetid, "•¤¶§!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/", 3000, 2);
    GameTextForPlayer(targetid, "•¤¶§!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/", 4000, 3);
    GameTextForPlayer(targetid, "•¤¶§!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/", 5000, 4);
    GameTextForPlayer(targetid, "•¤¶§!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/", 6000, 5);
    GameTextForPlayer(targetid, "•¤¶§!$$%&'()*+,-./01~!@#$^&*()_-+={[}]:;'<,>.?/", 7000, 6);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /crash %s[%i]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/setskin", true))
{
	if (Player[playerid][Admin] < 2){return 1;}
	
	new modelid; new levelid;//переменые, куда занесутся значения которые введет игрок 
	if(sscanf(params,"dd", modelid,levelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /setskin [id игрока] [0 - 311]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(modelid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (Player[modelid][Admin] > Player[playerid][Admin]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя применить на игрока, который выше вас по статусу");
	if (levelid > 311 || levelid < 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Номер скина должен быть в диапозоне от 0 до 311");
	Player[modelid][Model] = levelid; SetPlayerSkin(modelid, Player[modelid][Model]); new string[120];
	format(string, sizeof(string), "SERVER: Вы установили игроку %s[%d] скин №%d", PlayerName[modelid], modelid, levelid); SendClientMessage(playerid,COLOR_MODER,string); 
	if (Player[playerid][Admin] < 3) {format(string, sizeof(string), "SERVER: Модератор %s[%d] установил вам скин №%d", PlayerName[playerid], playerid, levelid); SendClientMessage(modelid,COLOR_MODER,string);}
	else {format(string, sizeof(string), "SERVER: Администратор %s[%d] установил вам скин №%d", PlayerName[playerid], playerid, levelid); SendClientMessage(modelid,COLOR_MODER,string);}
	
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /setskin %s[%d] %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid, levelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}





/////////////Админские команды
if(!strcmp(cmd, "/supermute", true))
{//команды надо вводить без "/" 
	if (Player[playerid][Admin] < 3) return 1;
	
	new targetid, string[140];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"i", targetid))//занесем значение которе ввел игрок в переменую 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /supermute [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	if (Player[targetid][Admin] > Player[playerid][Admin]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя заткнуть игрока, который выше вас по статусу");
	if (Player[targetid][Muted] != 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Этот игрок уже имеет затычку чата");

	format(string, sizeof(string), "{AFAFAF}SERVER: %s[%d] был заткнут администратором %s[%d] на неопределенный срок.", PlayerName[targetid], targetid, PlayerName[playerid], playerid);
	SendClientMessageToAll(COLOR_MODER,string); 
	Player[targetid][Muted] = -1;
	strmid(MutedBy[targetid], PlayerName[playerid], 0, 25, 25);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /supermute %s[%i]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/akill", true))
{
	if (Player[playerid][Admin] < 3){return 1;}
	
	new modelid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", modelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /akill [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(modelid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	SetPlayerHealth(modelid, 0); new string[120];
	format(string, sizeof(string), "SERVER: Вы убили игрока %s[%d]", PlayerName[modelid], modelid); SendClientMessage(playerid,COLOR_ADMIN,string); 
	
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /akill %s[%d]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/givegun", true))
{
	if (Player[playerid][Admin] < 3){return 1;}
	
	new targetid, weapon, ammo, string[120];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"ddd", targetid, weapon, ammo))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /givegun [id игрока] [id оружия] [кол-во патронов]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(targetid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (weapon < 0 || weapon > 46) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: ID оружия указан неверно");	
	GivePlayerWeapon(targetid,weapon,ammo);
	format(string, sizeof(string), "SERVER: Вы выдали игроку %s[%d] оружие ID %d с %d патронами", PlayerName[targetid],targetid, weapon, ammo); SendClientMessage(playerid,COLOR_ADMIN,string); 

	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /givegun %s[%d] %d %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[targetid], targetid, weapon, ammo);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/ssay", true)) // zcmd command
{
	if (Player[playerid][Admin] < 3){return 1;}
	
	if (Player[playerid][Muted] != 0) return SendClientMessage(playerid,COLOR_RED,"Вам запрещено отправлять сообщения");
	new string[256];
	if (!strlen(params)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используйте /ssay [text]");
	format(string,sizeof(string),"{FFFF00}SERVER: %s",params);
	SendClientMessageToAll(COLOR_YELLOW,string);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /ssay %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, params);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/setworld", true))
{
	if (Player[playerid][Admin] < 3){return 1;}
	
	new modelid, intid, string[256];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"dd", modelid, intid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /setworld [id игрока] [id мира] (0 - общий игровой мир)");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(modelid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (Player[modelid][Admin] > Player[playerid][Admin]) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя применить на игрока, который выше вас по статусу");
	format(string, sizeof(string), "{FFFF00}Вы установили игроку %s[%d] виртуальный мир {FFFFFF}%d", PlayerName[modelid], modelid, intid);
	SendClientMessage(playerid,COLOR_WHITE,string); SetPlayerVirtualWorld(modelid, intid);
	if (Player[playerid][Admin] < 3) {format(string, sizeof(string), "SERVER: Модератор %s[%d] переместил вас в виртуальный мир №%d", PlayerName[playerid], playerid, intid); SendClientMessage(modelid,COLOR_MODER,string);}
	else {format(string, sizeof(string), "SERVER: Администратор %s[%d] переместил вас в виртуальный мир №%d", PlayerName[playerid], playerid, intid); SendClientMessage(modelid,COLOR_MODER,string);}

	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /setworld %s[%d] %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid, intid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/change", true)) // zcmd command
{//change
    new chng=Player[playerid][EventChangeTime]-unixtime;
    if (chng > 0 && Player[playerid][Admin] < 3){new string[100]; format(string,sizeof string, "ОШИБКА: Вы не можете изменять соревнования еще %d минут", chng / 60 + 1);return SendClientMessage(playerid, COLOR_RED, string);}
	ChangeDialog(playerid);
	return 1;
}//change
/*
if(!strcmp(cmd, "/changeid", true)) // zcmd command
{//change
	if (Player[playerid][Admin] < 3 && Player[playerid][GPremium] < 18) return 1;
	new string[120];
	if (Player[playerid][EventChangeTime] > 0 && Player[playerid][Admin] < 3){format(string,sizeof string, "ОШИБКА: Вы не можете изменять соревнования еще %d минут", Player[playerid][EventChangeTime] / 60 + 1);return SendClientMessage(playerid, COLOR_RED, string);}
	new option[10], lolid;
	if(sscanf(params,"s[10]i", option, lolid))//
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /changeid [dm/derby/zombie/xrace/gungame/park/drace/flag] [id]");//если игрок не ввел значение то выдаем собщение
	if(!strcmp(option, "dm"))
	{//dm
		if (DMTimer > 300) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить десматч пока он не объявлен");
		if (DMTimer > 2 && DMTimer < 300)
		{
			if (lolid < 1 || lolid > 20) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] десматча (от 1 до 20)");
			new String[140];DMid = lolid;PrevDM = lolid;format(String,sizeof(String),"Десматч был изменен на <<{FFFFFF}%s{FF8C00}>>",DMName[DMid]);
			SendClientMessageToAll(COLOR_DM,String);
		}
	}//dm
	if(!strcmp(option, "derby"))
	{//derby
		if (DerbyTimer > 300) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить дерби пока оно не объявлено");
		if (DerbyTimer > 2 && DerbyTimer < 300)
		{
			if (lolid < 1 || lolid > MAX_DERBYS) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] дерби!");
			new String[140];Derbyid = lolid;PrevDerby = lolid;format(String,sizeof(String),"Дерби было изменено на <<{FFFFFF}%s{9966CC}>>",DerbyName[Derbyid]);
			SendClientMessageToAll(COLOR_DERBY,String);
			//Выбор модели авто для дерби, где оно у всех одинаковое
			if (Derbyid == 1) {new modelid = random(123);DerbyModelAll = DerbyCars[modelid];}
			if (Derbyid == 3) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
			if (Derbyid == 7) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
			if (Derbyid == 9) DerbyModelAll = 432; //World Of Tanks
			if (Derbyid == 10) DerbyModelAll = 557;
			if (Derbyid == 11) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
			if (Derbyid == 12) DerbyModelAll = 411;
			if (Derbyid == 13) DerbyModelAll = 489;
			for(new cid = 0; cid < MAX_PLAYERS; cid++) DerbyModelCar[cid] = DerbyModelAll; //обязательно обычный for
		}
	}//derby
	if(!strcmp(option, "zombie"))
	{//zombie
		if (ZMTimer > 300) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить зомби-выживание пока оно не объявлено");
		if (ZMTimer > 2 && ZMTimer < 300)
		{
			if (lolid < 1 || lolid > MAX_ZOMBIE) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] зомби-выживания!");
			new String[140];ZMid = lolid;PrevZM = lolid;format(String,sizeof(String),"Зомби-Выживание было изменено на <<{FFFFFF}%s{E60020}>>",ZMName[ZMid]);
			SendClientMessageToAll(COLOR_ZOMBIE,String);
		}
	}//zombie
	if(!strcmp(option, "xrace"))
	{//xrace
		if (XRTimer > 599) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить  легендарную гонку пока она не объявлена");
		if (XRTimer > 2 && XRTimer <= 30) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить легендарную гонку так как до старта осталось меньше 30 секунд");
		if (XRTimer > 2 && XRTimer < 600)
		{
			if(lolid == 1)
			{
				XRCPs = 32;//кол-во чекпоинтов вместе со стартом и финишем
				new xrmodel;
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				for(new i = 1; i < XRCPs; i+=3)
				{//определение транспорта для чеков
					xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];
				}//определение транспорта для чеков
				XRCarCP[0] = 448;
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 1;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Around San Andreas{FFD700}>>");
			}
			if(lolid == 2)
			{
				XRCPs = 30;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				XRCarCP[0] = 473;//старт обязательно на надувной лодке
				XRCarCP[1] = 446;//squallo на первом чеке
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 2;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Bon Voyage{FFD700}>>");
			}
			if(lolid == 3)
			{
				XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRTypeCP[XRCPs-1] = 4;//воздушный финиш
				XRCarCP[0] = 461;//старт на PCJ
				XRCarCP[3] = 513;XRCarCP[4] = 451;XRCarCP[10] = 568;XRCarCP[21] = 513;//stuntplane, turismo, bandito, stuntplane
				XRTypeCP[3] = 3;XRTypeCP[4] = 3;XRTypeCP[21] = 3;//Воздушные чекпоинты	
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 3;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Up And Down{FFD700}>>");
			}
			if(lolid == 4)
			{
				XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				XRCarCP[0] = 541;//старт на Bullet
				XRCarCP[9] = 541;//bullet
				XRCarCP[5] = 473;XRCarCP[16] = 473;//надувные лодки
				XRCarCP[6] = 446;XRCarCP[17] = 446;//squallo
				XRTypeCP[5] = 3;XRTypeCP[16] = 3;//воздушные чекпоинты
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 4;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Riders On The Storm{FFD700}>>");
			}
			if(lolid == 5)
			{
				XRCPs = 62;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				new xrmodel;
				for(new i = 1; i < XRCPs; i+=4)
				{//чеки смены транспорта
					xrmodel = random(126);XRCarCP[i] = XRCars1[xrmodel];
				}//чеки смены транспорта
				XRCarCP[0] = 471;//старт на квадрацикле
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 5;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Crazy Turns{FFD700}>>");
			}
			if(lolid == 6)
			{
				XRCPs = 35;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRTypeCP[XRCPs-1] = 1;//наземный финиш	
				XRCarCP[0] = 441;//старт на RC Bandit
				XRCarCP[22] = 441;XRCarCP[23] = 464;//RC на крыше гаража
				XRCarCP[2] = 559;XRCarCP[8] = 522;XRCarCP[12] = 560;XRCarCP[28] = 562;//Jester, NRG, Sultan, Elegy
				XRTypeCP[23] = 3;XRTypeCP[24] = 3;XRTypeCP[25] = 3;XRTypeCP[26] = 3;XRTypeCP[27] = 3;//воздушные чекпоинты
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 6;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Vegas Race{FFD700}>>");
			}
			if(lolid == 7)
			{
				XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 3;//воздушные чеки
				}//определение транспорта для чеков
				XRTypeCP[XRCPs-1] = 4;//воздушный финиш	
				XRCarCP[0] = 461;//старт на PCJ	
				XRCarCP[1] = 464;XRCarCP[4] = 464;XRCarCP[8] = 464;XRCarCP[10] = 464;//RC
				XRCarCP[2] = 513;XRCarCP[5] = 513;XRCarCP[9] = 513;XRCarCP[12] = 513;//StuntPlane
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 7;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Dead Air{FFD700}>>");
			}
			if(lolid == 8)
			{
				XRCPs = 43;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//обычные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 471;//старт на квадрацикле
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				XRTypeCP[1] = 3;//воздушный чек вортекса
				XRCarCP[1] = 539;XRCarCP[2] = 560;XRCarCP[29] = 495;//Vortex, Sultan, SandKing
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 8;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Road To Farm{FFD700}>>");
			}
			if(lolid == 9)
			{
				XRCPs = 29;new xrmodel;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					if(i == 1 || i == 7 || i == 15 || i == 24){xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];}//чеки смены авто		
					XRTypeCP[i] = 0;//обычные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 521;//стартовый транспорт
				XRTypeCP[XRCPs-1] = 1;XRTypeCP[22] = 3;//наземный финиш и круглый чек при прыжке в воду
				XRCarCP[22] = 473;//Надувная лодка
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE){SendCommand(cid, "/xrace", "");}
				}//цикл
				XRid = 9;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}UnderGround{FFD700}>>");
			}
			if(lolid == 10)
			{
				XRCPs = 25;new xrmodel;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					if(i == 1 || i == 5 || i == 15 || i == 17){xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];}//чеки смены авто		
					XRTypeCP[i] = 0;//обычные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 509;//стартовый транспорт
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 10;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}San Fierro Tour{FFD700}>>");
			}
			if(lolid == 11)
			{
				XRCPs = 35;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//обычные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 468;//стартовый транспорт - Sanchez
				XRCarCP[10] = 471;//cp 10 - Quad
				XRCarCP[21] = 444;//cp 21 - Monster
				XRCarCP[31] = 468;//cp 31 - Sanchez
				
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 11;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Into The Wild{FFD700}>>");
			}
			if(lolid == 12)
			{
				XRCPs = 10; new xrmodel;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 522;
				xrmodel = random(20);XRCarCP[1] = XRCars9[xrmodel];
				xrmodel = random(20);XRCarCP[6] = XRCars9[xrmodel];
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 12;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Drag Race{FFD700}>>");
			}
			if(lolid == 13)
			{
				XRCPs = 30;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 461; //стартовое авто
				XRCarCP[1] = 411; //infernus на первом чеке
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 13;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Need For Speed{FFD700}>>");
			}
			if(lolid == 14)
			{
				XRCPs = 66;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				new xrmodel;
				for(new i = 4; i < XRCPs; i+=4)
				{//чеки смены транспорта
					xrmodel = random(126);XRCarCP[i] = XRCars1[xrmodel];
				}//чеки смены транспорта
				XRCarCP[0] = 471;//старт на квадрацикле
				XRTypeCP[XRCPs-1] = 4;//воздушный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 14;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Восьмерка{FFD700}>>");
			}
			if(lolid == 15)
			{
				XRCPs = 54;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 510; //стартовое авто
				XRCarCP[5] = 562; //elegy на пятом чеке
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 15;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}San Fierro Drift{FFD700}>>");
			}
			if(lolid == 16)
			{
				XRCPs = 36;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				XRCarCP[0] = 468;//старт на sanchez
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 16;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Mountain{FFD700}>>");
			}
			if(lolid == 17)
			{
				XRCPs = 34;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					if (5 <= i <= 32) XRTypeCP[i] = 3; //воздушные чеки
					else XRTypeCP[i] = 0; //наземные чеки
					XRCarCP[i] = -1;//без трансформации
				}//определение транспорта для чеков
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				XRCarCP[0] = 481; XRCarCP[32] = 481;//BMX	
				XRCarCP[5] = 464;//RC
				XRCarCP[8] = 476;//Rustler
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 17;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Не для слабаков{FFD700}>>");
			}
			if(lolid == 18)
			{
				XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				new xrmodel;
				xrmodel = random(20);XRCarCP[3] = XRCars9[xrmodel];
				xrmodel = random(20);XRCarCP[14] = XRCars9[xrmodel];
				XRCarCP[0] = 468; XRCarCP[21] = 468;//sanchez
				XRTypeCP[XRCPs-1] = 4;//воздушный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 18;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Dirt And Dust{FFD700}>>");
			}
			if(lolid == 19)
			{
				XRCPs = 37;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				new xrmodel;
				xrmodel = random(20);XRCarCP[1] = XRCars9[xrmodel];
				xrmodel = random(20);XRCarCP[13] = XRCars9[xrmodel];
				xrmodel = random(20);XRCarCP[25] = XRCars9[xrmodel];
				XRCarCP[0] = 571;//kart
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 19;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Los Santos Highway{FFD700}>>");
			}
			if(lolid == 20)
			{
				XRCPs = 33;//кол-во чекпоинтов вместе со стартом и финишем
				for(new i = 0; i < XRCPs; i++)
				{//определение транспорта для чеков
					XRCarCP[i] = -1;//без трансформации
					XRTypeCP[i] = 0;//наземные чеки
				}//определение транспорта для чеков
				new xrmodel;
				for(new i = 1; i < XRCPs; i+=6)
				{//определение транспорта для чеков
					xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];
				}//определение транспорта для чеков
				XRCarCP[0] = 522;//nrg
				XRTypeCP[XRCPs-1] = 1;//наземный финиш
				foreach(Player, cid)
				{//цикл
					if (JoinEvent[cid] == EVENT_XRACE) SendCommand(cid, "/xrace", "");
				}//цикл
				XRid = 20;PrevXRid = XRid; SendClientMessageToAll(COLOR_XR, "Легендарная Гонка была изменена на <<{FFFFFF}Fast And Furious{FFD700}>>");
			}
		
		if (lolid > 20 || lolid < 1) SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] легендарной гонки (от 1 до 20)");
		}
	}//xrace
	if(!strcmp(option, "gungame"))
	{//gungame
		if (GGTimer > 599){GGTimer = 601; return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить гонку вооружений пока она не объявлена");}
		if (GGTimer > 2 && GGTimer < 600)
		{
			if (lolid < 1 || lolid > 20) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] гонки вооружений (от 1 до 20)");
			new String[140];GGid = lolid;PrevGGid = lolid;format(String,sizeof(String),"Гонка Вооружений была изменена на <<{FFFFFF}%s{FF6347}>>",GGName[GGid]);
			SendClientMessageToAll(COLOR_GG,String);
		}
	}//gungame
	if(!strcmp(option, "flag"))
	{//ctf
		if (FTimer > 300) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить битву пока она не объявлена");
		if (FTimer > 2 && FTimer < 300)
		{
			if (lolid < 1 || lolid > MAX_CTF) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] флага (от 1 до 5)");
			new String[140];Fid = lolid;PrevF = lolid;format(String,sizeof(String),"Битва за флаг была изменена на <<{FFFFFF}%s{00D40A}>>",FName[Fid]);
			SendClientMessageToAll(COLOR_FLAG,String);
		}
	}//ctf
	
	if(!strcmp(option, "park"))
	{//паркур
		if (PRTimer > 300) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить паркур пока он не объявлен");
		if (PRTimer > 2 && PRTimer < 300)
		{
			if (lolid < 1 || lolid > MAX_PARK) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] паркура!");
			new String[140];PRid = lolid;PrevPR = lolid;format(String,sizeof(String),"Паркур был изменен на <<{FFFFFF}%s{58FAF4}>>",PRName[PRid]);
			SendClientMessageToAll(COLOR_PARK,String);
		}
	}//паркур
	
	if(!strcmp(option, "drace"))
	{//derby
		if (DRTimer > 300) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить гонку на выживание пока она не объявлена");
		if (DRTimer > 2 && DRTimer < 300)
		{
			if (lolid < 1 || lolid > MAX_DRACE) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Неверный [id] гонки!");
			new String[140];
			DRid = lolid;
			PrevDR = lolid;
			format(String,sizeof(String),"Гонка на выживание была изменена на <<{FFFFFF}%s{4C73E6}>>",DRName[DRid]);
			SendClientMessageToAll(COLOR_DRACE,String);
			SetRandomGVVeh();
		}
	}//derby
	if (Player[playerid][Admin] < 3) Player[playerid][EventChangeTime] = 3600;
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /change %s %i", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, option, lolid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}//change
*/
if(!strcmp(cmd, "/changeraceid", true)) // zcmd command
{//changeraceid
	if (Player[playerid][Admin] < 3 && Player[playerid][GPremium] < 18) return 1;
	
	new string[120];
	//if (Player[playerid][EventChangeTime] > 0 && Player[playerid][Admin] < 3){format(string,sizeof string, "ОШИБКА: Вы не можете изменять соревнования еще %d минут", Player[playerid][EventChangeTime] / 60 + 1);return SendClientMessage(playerid, COLOR_RED, string);}
	new id1, id2;
	if(sscanf(params,"ii", id1, id2))//
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /changeraceid [id] [id]");//если игрок не ввел значение то выдаем собщение 
	if (FRTimer > 300) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить гонку пока она не объявлена");
	if (FRTimer > 2 && FRTimer <= 30) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Нельзя изменить гонку так как до старта осталось меньше 30 секунд");
	if (FRStart == id1 && FRFinish == id2) return 1;
	if (FRTimer > 2 && FRTimer < 300)
	{
		if (id1 < 1 || id2 < 1 || id1 > 40 || id2 > 40) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Один из [id] указан неверно (используйте значения 1 до 40)");
		if (id1 == id2) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Старт и финиш гонки не может быть в одном и том же месте");
		foreach(Player, cid) if (JoinEvent[cid] == EVENT_RACE) SendCommand(cid, "/race", "");//
		new String[140];FRStart = id1;PrevFRStart = id1;FRFinish = id2;PrevFRFinish = id2;
		format(String,sizeof(String),"Гонка была изменена. Старт: {FFFFFF}%s{007FFF}. Финиш: {FFFFFF}%s{007FFF}.",FRName[FRStart], FRName[FRFinish]);
		SendClientMessageToAll(COLOR_RACE,String);
		if (Player[playerid][Admin] < 3) Player[playerid][EventChangeTime] = 3600;
		format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /changeraceid %i %i", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, id1, id2);
		WriteLog("GlobalLog", string);WriteLog("Admin", string);return 1;
	}
	return 1;
}//changeraceid






/////////////Root-команды
if(!strcmp(cmd, "/levelup", true))
{
	if (Player[playerid][Admin] < 4){return 1;}
	
	new modelid;//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"d", modelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /levelup [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(modelid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (Player[modelid][Level] >= 99999)return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: У этого игрока максимальный уровень");
	Player[modelid][Exp] += NeedXP[modelid]; PlayerLevelUp(modelid); new string[120];
	format(string, sizeof(string), "SERVER: Вы повысили уровень игрока %s[%d]", PlayerName[modelid],modelid);SendClientMessage(playerid,COLOR_ROOT,string); 
	format(string, sizeof(string), "SERVER: Администратор %s[%d] повысил ваш уровень", PlayerName[playerid], playerid);SendClientMessage(modelid,COLOR_YELLOW,string); 
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /levelup %s[%d]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/setlvl", true) || !strcmp(cmd, "/setlevel", true))
{
	if (Player[playerid][Admin] < 4){return 1;}
	
	new modelid; new levelid;//переменые, куда занесутся значения которые введет игрок 
	if(sscanf(params,"dd", modelid,levelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /setlevel [id игрока] [level]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(modelid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (levelid > 999999999 || levelid < 1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Уровень должен быть в диапозоне от 1 до 999999999");
	Player[modelid][Level] = levelid - 1;
	new Lvl = Player[modelid][Level], string[140];
	if (Player[modelid][Prestige] < 10 || Lvl < 100) NeedXP[modelid] = Levels[Lvl];
	else NeedXP[modelid] = (Lvl - 99) * 100 + 30000;	
	Player[modelid][Exp] = NeedXP[modelid]; PlayerLevelUp(modelid);	
	format(string, sizeof(string), "SERVER: Вы изменили уровень игрока %s[%d] на %d", PlayerName[modelid], modelid, levelid); SendClientMessage(playerid,COLOR_ROOT,string); 
	format(string,sizeof(string),"{FFFF00}SERVER: Администратор %s[%d] установил вам {FFFFFF}%d {FFFF00}уровень", PlayerName[playerid], playerid,levelid);
	SendClientMessage(modelid,COLOR_YELLOW,string);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /setlevel %s[%d] %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid, levelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}


if(!strcmp(cmd, "/agivecash", true))
{ 
	if (Player[playerid][Admin] < 4){return 1;}
	
	new plid; new money;//переменая куда занесется значение которое введет игрок 
	new string[120];
	if(sscanf(params,"dd", plid, money))//занесем значение которе ввел игрок в переменую skinid 
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /agivecash [id] [сумма]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(plid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (Logged[plid] == 0) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID не авторизировался");
	if (LastPlayerTuneStatus[plid] > 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Нельзя давать деньги игроку, когда он находится в автомастерской. Попробуйте позднее.");
	Player[plid][Cash] += money;SavePlayer(plid);
	format(string, sizeof(string), "{00BFFF}SERVER: Администратор %s[%d] дал вам {FFFFFF}%d$ {00BFFF}денег", PlayerName[playerid], playerid, money);
	SendClientMessage(plid,COLOR_YELLOW,string);
	format(string, sizeof(string), "SERVER: Вы успешно подарили %d$ денег игроку %s[%d]", money, PlayerName[plid], plid);
	SendClientMessage(playerid,COLOR_ROOT,string); 
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /agivecash %s[%d] %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[plid], plid, money);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/agivexp", true))
{
	if (Player[playerid][Admin] < 4){return 1;}
	
	new modelid; new levelid;//переменые, куда занесутся значения которые введет игрок 
	if(sscanf(params,"dd", modelid,levelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /agivexp [id игрока] [xp]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(modelid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); 
	if (levelid > 1000000 || levelid < 1) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: XP должно быть в диапозоне от 1 до 1 000 000");
	Player[modelid][Exp] += levelid; 
	if (Player[modelid][Exp] >= NeedXP[modelid]) PlayerLevelUp(modelid);
	new string[120];
	format(string, sizeof(string), "SERVER: Вы дали %d XP игроку %s[%d]", levelid, PlayerName[modelid],modelid);SendClientMessage(playerid,COLOR_ROOT,string); 
	format(string,sizeof(string),"{FFFF00}SERVER: Администратор %s[%d] дал вам {FFFFFF}%d{FFFF00} XP", PlayerName[playerid], playerid, levelid);
	SendClientMessage(modelid,COLOR_YELLOW,string);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /agivexp %s[%d] %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid, levelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/setadmin", true))
{
	if (Player[playerid][Admin] != 4) return 1;
	
	new modelid; new levelid;//переменые, куда занесутся значения которые введет игрок 
	if(sscanf(params,"dd", modelid,levelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /setadmin [id игрока] [0-4] 5 - hideadmin");//если игрок не ввел значение то выдаем собщение
	if (!IsPlayerConnected(modelid)){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети"); return 1;} 
	if (levelid == Player[modelid][Admin]){SendClientMessage(playerid,COLOR_RED,"ОШИБКА: У этого игрока уже установлен такой уровень админки"); return 1;}
	Player[modelid][Admin] = levelid;//устанавливается админ-лвл
	new string[120];
	if (levelid == 0){format(string, sizeof(string), "{FFFF00}Вы лишили игрока %s админ-статуса", PlayerName[modelid]);}
	if (levelid == 1){format(string, sizeof(string), "{FFFF00}Вы установили игроку %s статус {66CDAA}Модератора", PlayerName[modelid]);}
	if (levelid == 2){format(string, sizeof(string), "{FFFF00}Вы установили игроку %s статус {9ACD32}Супер-Модератора", PlayerName[modelid]);}
	if (levelid == 3){format(string, sizeof(string), "{FFFF00}Вы установили игроку %s статус {00BFFF}Администратора", PlayerName[modelid]);}
	if (levelid == 4){format(string, sizeof(string), "{FFFF00}Вы установили игроку %s статус {FF7F50}Главного Администратора", PlayerName[modelid]);}
	SendClientMessage(playerid,COLOR_WHITE,string);
	if (levelid == 0){format(string, sizeof(string), "{FF0000}%s лишил вас админ-статуса", PlayerName[playerid]);}
	if (levelid == 1){format(string, sizeof(string), "{FFFF00}%s установил вам статус {66CDAA}Модератора", PlayerName[playerid]);}
	if (levelid == 2){format(string, sizeof(string), "{FFFF00}%s установил вам статус {9ACD32}Супер-Модератора", PlayerName[playerid]);}
	if (levelid == 3){format(string, sizeof(string), "{FFFF00}%s установил вам статус {00BFFF}Администратора", PlayerName[playerid]);}
	if (levelid == 4){format(string, sizeof(string), "{FFFF00}%s установил вам статус {FF7F50}Главного Администратора", PlayerName[playerid]);}
	if (levelid == 5){format(string, sizeof(string), "{FFFF00}%s установил вам статус Скрытого Администратора", PlayerName[playerid]);}
	SendClientMessage(modelid,COLOR_WHITE,string);
	
	new query[100];
	mysql_format(connects,query, sizeof(query), "UPDATE `accounts` SET `Admin` = '%d' WHERE `SID` = '%d'",levelid, Player[modelid][SID]);
	mysql_empty(connects, query);
	
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /setadmin %s[%d] %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid, levelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}


if(!strcmp(cmd, "/start", true)) // zcmd command
{//start
	if (Player[playerid][Admin] < 4) return 1;
	
	new option[10];
	if(sscanf(params,"s[10]", option))//
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /start [dm/derby/race/zombie/xrace/gungame/flag]");//если игрок не ввел значение то выдаем собщение
	if(!strcmp(option, "dm"))
	{//dm
		if (DMTimer > 61) DMTimer = 61;
		if (DMTimer > 2 && DMTimer < 60) DMTimer = 2;
	}//dm
	if(!strcmp(option, "zombie"))
	{//zombie
		if (ZMTimer > 61) ZMTimer = 61;
		if (ZMTimer > 2 && ZMTimer < 60) ZMTimer = 2;
	}//zombie
	if(!strcmp(option, "derby"))
	{//derby
		if (DerbyTimer > 61) DerbyTimer = 61;
		if (DerbyTimer > 2 && DerbyTimer < 60) DerbyTimer = 2;
	}//derby
	if(!strcmp(option, "race"))
	{//race
		if (FRTimer > 61) FRTimer = 61;
		if (FRTimer > 2 && FRTimer < 60) FRTimer = 2;
	}//race
	if(!strcmp(option, "xrace"))
	{//race
		if (XRTimer > 61) XRTimer = 61;
		if (XRTimer > 2 && XRTimer < 60) XRTimer = 2;
	}//race
	if(!strcmp(option, "gungame"))
	{//gungame
		if (GGTimer > 61) GGTimer = 61;
		if (GGTimer > 2 && GGTimer < 60) GGTimer = 2;
	}//gungame
	if(!strcmp(option, "flag"))
	{//ctf
		if (FTimer > 61) FTimer = 61;
		if (FTimer > 2 && FTimer < 60) FTimer = 2;
	}//ctf
	if(!strcmp(option, "park"))
	{//parkour
		if (PRTimer > 61) PRTimer = 61;
		if (PRTimer > 2 && PRTimer < 60) PRTimer = 2;
	}//parkour
	if(!strcmp(option, "drace"))
	{//drace
		if (DRTimer > 61) DRTimer = 61;
		if (DRTimer > 2 && DRTimer < 60) DRTimer = 2;
	}//drace
	new string[120];format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /start %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, option);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}//start

if(!strcmp(cmd, "/killserver", true))
{
	if (Player[playerid][Admin] < 4){return 1;}
	 
	new string[120];format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /killserver", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	SendClientMessageToAll(COLOR_RED,"SERVER: Выключение сервера...");
	SendRconCommand("exit");
	return 1;
}

if(!strcmp(cmd, "/arcon", true))
{
	if (Player[playerid][Admin] < 4){return 1;}
	
	new modelid[120];//переменая куда занесется значение которое введет игрок 
	if(sscanf(params,"s", modelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /arcon [RCON-Команда]");//если игрок не ввел значение то выдаем собщение 
	new string[120];format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /arcon %s", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, modelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	SendRconCommand(modelid);
	return 1;
}

if(!strcmp(cmd, "/changepass", true))
{//клеймо позора
	if (Player[playerid][Admin] < 4) return 1;
	
	new modelid, string[480]; //переменые, куда занесутся значения которые введет игрок 
	if(sscanf(params,"d", modelid))//занесем значение которое ввел игрок в переменую
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /changepass [id игрока]");//если игрок не ввел значение то выдаем собщение 
	if (!IsPlayerConnected(modelid)) return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Игрока с указанным ID нет в сети");
	if (Logged[modelid] == 0) return SendClientMessage(playerid, COLOR_RED, "ОШИБКА: Игрок не авторизировался");
	format(string, sizeof string, "SERVER: Вы вызвали окно смены пароля у игрока %s[%d]", PlayerName[modelid], modelid);
	SendClientMessage(playerid, COLOR_YELLOW, string);
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /changepass %d", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, modelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);	
	format(string, sizeof(string), "{FFFFFF}Введите новый пароль:\n\n     {008000}Примечание:\n     - Пароль должен быть сложным (Пример: s9cQ17)\n     {FF0000}- Длина пароля должна быть от 6 до 24 символов\n     {FF0000}- Запрещено использовать '=' в пароле");
	ShowPlayerDialog(modelid, DIALOG_CHANGEPASS, DIALOG_STYLE_INPUT, "{FF0000}Смена пароля", string, "ОК", "Отмена");
	format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /changepass %s[%d]", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, PlayerName[modelid], modelid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	return 1;
}

if(!strcmp(cmd, "/restart", true))
{
	if (Player[playerid][Admin] < 4){return 1;}
	 
	new string[120];format(string, sizeof string, "%d.%d.%d в %d:%d:%d |   ADMIN: %s[%d] ввел /restart", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
	WriteLog("GlobalLog", string);WriteLog("Admin", string);
	SendClientMessageToAll(COLOR_RED,"SERVER: Рестарт сервера. Пожалуйста, подождите несколько секунд...");
	IsServerRestaring = 1;
	SendRconCommand("gmx");
	return 1;
}

if(!strcmp(cmd, "/sconfig", true))
{
	if (Player[playerid][Admin] < 4){return 1;}

	ConfigDialog(playerid);
	return 1;
}























/////////////Системные команды
if(!strcmp(cmd, "/sysanim", true)) // zcmd command
{//anim
		new animlib[32];new animname[32];new msg[128];
        GetAnimationName(GetPlayerAnimationIndex(playerid),animlib,32,animname,32);
        format(msg, 128, "SYSTEM: Это анимация ID: {FFFFFF}%d{DDAA00} из библиотеки '{FFFFFF}%s{DDAA00}'. Название: '{FFFFFF}%s{DDAA00}'", GetPlayerAnimationIndex(playerid), animlib, animname);
        return SendClientMessage(playerid, COLOR_SYSTEM, msg);
}//anim

if(!strcmp(cmd, "/syssound", true)) // zcmd command
{//anim
	new sid, string[80];
	if(sscanf(params,"%d", sid))//
	return SendClientMessage(playerid,COLOR_RED,"ОШИБКА: Используй /syssound ID");//если игрок не ввел значение то выдаем собщение 
	PlayerPlaySound(playerid, sid, 0.0,0.0,0.0);
    format(string, 80, "SYSTEM: Вы включили прослушивание звука ID %d", sid); SendClientMessage(playerid, COLOR_SYSTEM, string);return 1;
}//anim
