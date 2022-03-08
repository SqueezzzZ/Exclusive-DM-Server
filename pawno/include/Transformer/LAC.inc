if (Logged[playerid] > 0)
{//игрок залогинен
	if (LACWeaponOff[playerid] > 0) LACWeaponOff[playerid]--;//таймер LAC на оружие
	
	//---------------------- LAC v2.0
	if (LACPanic[playerid] > 0)
	{//Какой-то из LAC заподозрил игрока в читерстве
		if (LACPanic[playerid] == 1)
		{//игрок заподозрен в читерстве 1 раз
			LACPanicTime[playerid]++;
			//Если с момента подозрения в читерстве прошло 30 секунд - снимаем все подозрения
			if (LACPanicTime[playerid] == 30) {LACPanicTime[playerid] = 0; LACPanic[playerid] = 0;}
		}//игрок заподозрен в читерстве 1 раз
		if (LACPanic[playerid] >= 2)
		{//Игрок заподозрен в читерстве более 1 раза в течение 30 секунд
			new String[140];
			format(String,sizeof String, "{FF0000}LAC: {AFAFAF}%s[%d] был кикнут с сервера по подозрению в читерстве.", PlayerName[playerid], playerid);
			SendClientMessageToAll(COLOR_GREY,String);GKick(playerid);
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] был кикнут с сервера по подозрению в читерстве: %d срабатываний LAC за %d секунд.", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, LACPanic[playerid], LACPanicTime[playerid]);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
			LACPanic[playerid] = 0; LACPanicTime[playerid] = 0;
			return 1;
		}//Игрок заподозрен в читерстве более 1 раза в течение 30 секунд
	}//Какой-то из LAC заподозрил игрока в читерстве
	//---------------------- LAC v2.0
	
	//---------------------- Античит на телепорт
	if (GetPlayerVehicleID(playerid) == 0 && GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
	{//------ Телепорт пешком. Проверка IsPlayerInAnyVehicle почему-то иногда считает, что игрок НЕ в авто, когда он в авто.
		new Float: Distance = GetPlayerDistanceFromPoint(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
		new Float: newx, Float: newy, Float: newz, cheat = 0, String[140];GetPlayerPos(playerid, newx, newy, newz);
		if (Distance > 50.0) cheat = 1;
		if (Distance == 0.0) Player[playerid][DMove]++;
		else Player[playerid][DMove]=0;

		//new st[120];
		//format(st, sizeof st, "Dist: %.3f DMove: %d ", Distance, Player[playerid][DMove]);
		//SendClientMessage(playerid, -1, st);
		
		if (Distance < 100.0 && newz  < LastPlayerZ[playerid] - 5.0) cheat = 0;//падение вниз
		if (OnFly[playerid] == 1 || GetPlayerSurfingVehicleID(playerid) != INVALID_VEHICLE_ID || newz < -15.0 || LSpecID[playerid] != -1 || Player[playerid][Banned] == 1) LACTeleportOff[playerid] = 3;
		//Если игрок в режиме супермена или на крыше авто или упал под карту или в спектре или уже забанен
		if (LACTeleportOff[playerid] > 0) cheat = 0;//Если LAC на телепорт не должен работать		
		if (cheat == 0) GetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
		if (cheat == 1)
		{//игрок читер
			SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
			LACTeleportOff[playerid] = 0; LACPanic[playerid]++;//LAC v2.0
			format(String,sizeof(String), "[АДМИНАМ]LAC:{AFAFAF} %s[%d] возможно использует чит на Телепорт (Пешком)",PlayerName[playerid], playerid);
            foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
  			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} Вы телепортированы на последнюю сохраненную позицию. {FF0000}Причина: {AFAFAF}Возможно чит на Телепорт (Пешком)");
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] возможно использует чит на Телепорт (Пешком)", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}//игрок читер		
	}//------ Телепорт пешком 
	else
	{//------ Телепорт в машине
		new Float: Distance = GetPlayerDistanceFromPoint(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
		new Float: newx, Float: newy, Float: newz, cheat = 0, String[120];GetPlayerPos(playerid, newx, newy, newz);
		if (Distance == 0.0) Player[playerid][DMove]++;
		else Player[playerid][DMove]=0;
		if (Distance > 100.0) cheat = 1;
		if (Distance < 200.0 && newz - LastPlayerZ[playerid] < -15.0) cheat = 0;//падение вниз
		if (newz < -15.0 || GetPlayerVehicleSeat(playerid) != 0 || LSpecID[playerid] != -1 || Player[playerid][Banned] == 1) LACTeleportOff[playerid] = 3;
		//Если игрок упал под карту или в спектре или уже забанен	
		//--- Добавленная позже часть: LAC на AirBrake
		if (cheat != 1)
		{//Если уже обнаружен чит на телепорт, то на AirBrake не проверяет
			new Float: SPD; GetVehicleVelocity(GetPlayerVehicleID(playerid), newx,newy,newz);
		    SPD = floatsqroot(((newx*newx)+(newy*newy))+(newz*newz))*200;
			if (SPD < 1.0) TimeWithZeroSpeed[playerid]++; else TimeWithZeroSpeed[playerid] = 0;
			if (Distance > 5.0 && TimeWithZeroSpeed[playerid] >= 2) cheat = 2;//машина игрока переместилась, хотя скорость была 0 уже больше секунды
		}//Если уже обнаружен чит на телепорт, то на AirBrake не проверяет
			//--- Добавленная позже часть: LAC на AirBrake
		if (GetPlayerTuneStatus(playerid) > 0 && LastPlayerTuneStatus[playerid] < 0) cheat = 0; //Игрок ВЪЕХАЛ внутрь тюнинга
		if (GetPlayerTuneStatus(playerid) < 0 && LastPlayerTuneStatus[playerid] > 0) cheat = 0; //Игрок ВЫЕХАЛ из тюнинга
		if (LACTeleportOff[playerid] > 0) {cheat = 0; TimeWithZeroSpeed[playerid] = 0;}//Если LAC на телепорт не должен работать		
		if (cheat == 0) GetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);		
		LastPlayerTuneStatus[playerid] = GetPlayerTuneStatus(playerid);	TunesPerSecond[playerid] = 0;	
		if (cheat == 1)
		{//игрок читер TP
			if (GetVehicleModel(GetPlayerVehicleID(playerid)) != 537 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 538)
			{//не в поезде			
				SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
				DestroyVehicle(GetPlayerVehicleID(playerid)); TimeTransform[playerid] = 5;
				LACTeleportOff[playerid] = 0; LACPanic[playerid]++;//LAC v2.0
				format(String,sizeof(String), "[АДМИНАМ]LAC:{AFAFAF} %s[%d] возможно использует чит на Телепорт",PlayerName[playerid], playerid);
				foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
				SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} Вы телепортированы на последнюю сохраненную позицию. {FF0000}Причина: {AFAFAF}Возможно чит на Телепорт");
				format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] возможно использует чит на Телепорт", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
				WriteLog("GlobalLog", String);WriteLog("LAC", String);
			}//не в поезде	
		}//игрок читер TP		
		if (cheat == 2)
		{//игрок читер AirBrake (добавлено позже)
			if (GetVehicleModel(GetPlayerVehicleID(playerid)) != 537 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 538)
			{//не в поезде
				SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
				DestroyVehicle(GetPlayerVehicleID(playerid)); TimeTransform[playerid] = 5;
				LACTeleportOff[playerid] = 0; LACPanic[playerid]++;//LAC v2.0
				format(String,sizeof(String), "[АДМИНАМ]LAC:{AFAFAF} Транспорт игрока %s[%d] уничтожен. {FF0000}Причина: {AFAFAF}Возможно AirBrake",PlayerName[playerid], playerid);
                foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
    			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} Ваш транспорт был уничтожен. {FF0000}Причина: {AFAFAF}Возможно чит AirBrake");
				format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: Транспорт игрока %s[%d] уничтожен. Причина: Возможно чит AirBrake", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
				WriteLog("GlobalLog", String);WriteLog("LAC", String);
			}//не в поезде
		}//игрок читер AirBrake	(добавлено позже)
		
		//format(String,sizeof String, "Дистанция: %d", floatround(Distance));SendClientMessage(playerid,-1,String);
	}//------ Телепорт в машине
	if (LACTeleportOff[playerid] > 0) LACTeleportOff[playerid]--; 
	//---------------------- Античит на телепорт
	
	//------ Античит на FlyHack
	new AnimLib[30], AnimName[30];
	GetAnimationName(GetPlayerAnimationIndex(playerid) , AnimLib, sizeof(AnimLib), AnimName, sizeof(AnimName));
	if (LACFlyOff[playerid] > 0 && LAFK[playerid] < 4) LACFlyOff[playerid] --;
	if (GetPlayerWeapon(playerid) == 46) LACFlyOff[playerid] = 45; //чтобы не было ложных срабатываний после открытия парашюта
	if (GetPlayerSpeed(playerid) > 60 && Player[playerid][Banned] == 0 && OnFly[playerid] == 0 && (strcmp(AnimLib, "SWIM", true) == 0 || strcmp(AnimLib, "PARACHUTE", true) == 0) && LACFlyOff[playerid] == 0)
	{
		new cheat = 1, String[120];		
		if (CheatFlySec[playerid] < 2){CheatFlySec[playerid] += 1;cheat = 0;}
		if (strcmp(AnimLib, "PARACHUTE", true) == 0 && GetPlayerWeapon(playerid) == 46) cheat = 0;
		if (cheat == 1)
		{
			ResetPlayerWeapons(playerid); LSpawnPlayer(playerid); LACFlyOff[playerid] = 3;
			LACPanic[playerid]++;//LAC v2.0
			format(String,sizeof(String), "[АДМИНАМ]LAC:{AFAFAF} %s[%d] возможно использует чит FlyHack",PlayerName[playerid], playerid);
			foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} Вы были заново зареспавнены. {FF0000}Причина: {AFAFAF}Возможно чит FlyHack");
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] возможно использует чит FlyHack", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}

	}
	else{CheatFlySec[playerid] = 0;}
	//------ Античит на FlyHack

	if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK && JetpackUsed[playerid] == 0 && Player[playerid][Banned] == 0)
	{//Защита на читерство джетпака
		new String[140]; Player[playerid][Banned] = 1; strmid(BannedBy[playerid], "LAC на JetPack", 0, 25, 25); strmid(BanReason[playerid], "Чит на JetPack", 0, 25, 25); SavePlayer(playerid);
		format(String,sizeof(String), "{FF0000}LAC: {AFAFAF}%s[%d] был автоматически забанен. {FF0000}Причина:{AFAFAF} Чит на Jetpack",PlayerName[playerid], playerid);
		SendClientMessageToAll(COLOR_RED,String);
		InEvent[playerid] = 0; JoinEvent[playerid] = 0;
		format(String, 120, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] был автоматически забанен. Причина: Чит на JetPack", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
		WriteLog("GlobalLog", String);WriteLog("LAC", String);WriteLog("Bans", String);
	}//Защита на читерство джетпака
	
	//------ Античит на SpeedHack Пешком (и Slapper)
	if (LACPedSHOff[playerid] > 0 && LAFK[playerid] < 4) LACPedSHOff[playerid] --;
	if (GetPlayerSurfingVehicleID(playerid) != INVALID_VEHICLE_ID) LACPedSHOff[playerid] = 3;
	new Float:Speed, Float:vvx, Float:vvy, Float:vvz;
	GetPlayerVelocity(playerid, vvx,vvy,vvz);
	Speed = floatsqroot(((vvx*vvx)+(vvy*vvy)));
	if (Speed > 0.60 && OnFly[playerid] == 0 && LACPedSHOff[playerid] == 0 && Player[playerid][Banned] == 0)
	{
		LACPedSHTime[playerid]++;
		if (LACPedSHTime[playerid] >= 3)
		{	
			new String[140]; SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
			LACPedSHOff[playerid] = 3; LACPanic[playerid]++;//LAC v2.0
			format(String,sizeof(String), "[АДМИНАМ]LAC:{AFAFAF} %s[%d] возможно использует чит SpeedHack (Пешком)",PlayerName[playerid], playerid);
			foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} Вы были перемещены. {FF0000}Причина: {AFAFAF}Возможно чит SpeedHack (Пешком)");
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] возможно использует чит SpeedHack (Пешком). Speed: %0.2f", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, Speed);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}
	} 
	else LACPedSHTime[playerid] = 0;
	//------ Античит на SpeedHack Пешком (и Slapper)
	
	//------ Синхронизация здоровья и брони
	if (NOPSetPlayerHealthAndArmourOff[playerid] > 0) NOPSetPlayerHealthAndArmourOff[playerid]--;
	new Float:xhealth, Float: xarmour;
    GetPlayerHealth(playerid,xhealth); GetPlayerArmour(playerid,xarmour);
	if (xhealth >= 1 && LAFK[playerid] < 4 && NOPSetPlayerHealthAndArmourOff[playerid] == 0 && PrestigeGM[playerid] == 0 && LSpecID[playerid] == -1)
	{//Игрок жив и залогинился
		new Float: deltahealth, Float: deltaarmour; //на сколько отличаются показатели между клиентом и сервером
		deltahealth = xhealth - Player[playerid][PHealth];//на сколько показатель здоровья со стороны клиента больше, чем со стороны сервера
		deltaarmour = xarmour - Player[playerid][PArmour];//на сколько показатель брони со стороны клиента больше, чем со стороны сервера
/*
		new st[120];
		format(st, sizeof st, "ClientHealth: %d ServerHealth: %d HealthKick: %d/5", floatround(xhealth, floatround_round), floatround(Player[playerid][PHealth], floatround_round), NOPSetPlayerHealth[playerid]);
		SendClientMessage(playerid, -1, st);
		format(st, sizeof st, "ClientArmour: %d ServerArmour: %d ArmourKick: %d/5", floatround(xarmour, floatround_round), floatround(Player[playerid][PArmour], floatround_round), NOPSetPlayerArmour[playerid]);
		SendClientMessage(playerid, -1, st);
*/		
		if (deltahealth > 1.0 || deltahealth < -1.0) NOPSetPlayerHealth[playerid]++; else NOPSetPlayerHealth[playerid] = 0;
		if (deltaarmour > 1.0 || deltaarmour < -1.0) NOPSetPlayerArmour[playerid]++; else NOPSetPlayerArmour[playerid] = 0;
		SetPlayerHealth(playerid, Player[playerid][PHealth]);
		SetPlayerArmour(playerid, Player[playerid][PArmour]);
		
		if (NOPSetPlayerHealth[playerid] == 5)
		{//Рассинхронизация здоровья
			SetPlayerChatBubble(playerid, "Рассинхронизация здоровья", COLOR_RED, 225.0, 1000);
			//new String[140]; LSpawnPlayer(playerid); LACPanic[playerid]++;//LAC v2.0
			//NOPSetPlayerHealth[playerid] = 0; NOPSetPlayerArmour[playerid] = 0; 
			//format(String,sizeof(String), "[АДМИНАМ]LAC:{AFAFAF} Здоровье игрока %s[%d] рассинхронизировано. Возможно чит на Бессмертие",PlayerName[playerid], playerid);
			//foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			//SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} Вы были заново зареспавнены. {FF0000}Причина: {AFAFAF}Рассинхронизация здоровья");
			//format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: Здоровье игрока %s[%d] рассинхронизировано. Возможно чит на Бессмертие", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			//WriteLog("GlobalLog", String);WriteLog("LAC", String);
			//
		}//Рассинхронизация здоровья
		else if (NOPSetPlayerArmour[playerid] == 5)
		{//Рассинхронизация брони
			SetPlayerChatBubble(playerid, "Рассинхронизация брони", COLOR_RED, 225.0, 1000);
			//new String[140]; LSpawnPlayer(playerid); //LACPanic[playerid]++;//LAC v2.0
			//NOPSetPlayerHealth[playerid] = 0; NOPSetPlayerArmour[playerid] = 0; 
			//format(String,sizeof(String), "[АДМИНАМ]LAC:{AFAFAF} Броня игрока %s[%d] рассинхронизирована. Возможно чит на Бессмертие",PlayerName[playerid], playerid);
			//foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			//SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} Вы были заново зареспавнены. {FF0000}Причина: {AFAFAF}Рассинхронизация брони");
			//format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: Броня игрока %s[%d] рассинхронизирована. Возможно чит на Бессмертие", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			//WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}//Рассинхронизация брони
	}//Игрок жив и залогинился
	else {NOPSetPlayerHealth[playerid] = 0; NOPSetPlayerArmour[playerid] = 0;}
	//------ Синхронизация здоровья и брони
	
}//игрок залогинен
