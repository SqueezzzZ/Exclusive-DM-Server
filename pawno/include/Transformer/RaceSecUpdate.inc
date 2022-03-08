if (FRTimer != 0) 
{
	FRTimer--; new String[60];
	format(String, sizeof String, "RACE:~w~ %d sec. Players: %d", FRTimer, FRPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_RACE], String);
}
if (FRTimeToEnd >= 0) FRTimeToEnd--;
if (FRTimer == 0)
{
	FRTimer = GetEventRestartTime();
	new modelid = random(sizeof(FRCars)); FRModelCar = FRCars[modelid];//выбор модели авто
	while (FRStart == PrevFRStart || FRFinish == PrevFRFinish) {FRStart = random(40) + 1; FRFinish = random(40) + 1;} //выбор новой трассы
	PrevFRStart = FRStart; PrevFRFinish = FRFinish;
}
if (FRTimeTransform > 0) FRTimeTransform -= 1;
if (FRTimer == 60)
{
	SendClientMessageToAll(COLOR_RACE,"| Гонка начнется через {FFFFFF}минуту{007FFF}! Используйте {FFFFFF}/race{007FFF}, если хотите участвовать.");
	new String[120];format(String,sizeof(String),"| Старт: {FFFFFF}%s{007FFF}. Финиш: {FFFFFF}%s{007FFF}.",FRName[FRStart],FRName[FRFinish]);SendClientMessageToAll(COLOR_RACE,String);
}


if (FRTimer <= -1)
{//Во время проведения гонки
	if (FRTimeTransform == 0){new modelid = random(sizeof(FRCars));FRModelCar = FRCars[modelid];}
	new eid;
	for (new i = 0; i < 25; i++) 
	{//Цикл для участников гонки
		eid = FRPlayersList[i];
		if (!IsPlayerConnected(eid) || FRStarted[eid] == 0) continue;
		
		if (LAFK[eid] >= 30)
		{
			FRCarID[eid] = 0;JoinEvent[eid] = 0;FRStarted[eid] = 0;
			SendClientMessage(eid,COLOR_RED,"Вы были кикнуты из игры за AFK на гонке более 30 секунд");DisablePlayerCheckpoint(eid);
			Kick(eid); continue;
		}
		else if (LAFK[eid] >= 20) SendClientMessage(eid,COLOR_RED,"Вы будете выброшены из гонки, если не начнете двигаться!");
		if (FRStarted[eid] == 1)
		{//после старта гонки
			new Float: hp;	GetPlayerHealth(eid,hp); if (hp < 1.0) LeaveEvent(eid,EVENT_RACE);//Если игрок умер - покидает гонку
			if (IsPlayerInAnyVehicle(eid) && GetPlayerVehicleID(eid) != FRCarID[eid]) RemovePlayerFromVehicle(eid);
			if (GetPlayerSurfingVehicleID(eid) != INVALID_VEHICLE_ID)
			{//Игрок на крыше чьего-то авто
				new Float: x, Float: y, Float: z; GetPlayerPos(eid, x, y, z); SetPlayerPos(eid, x, y, z + 2);
				SendClientMessage(eid, COLOR_RED, "Во время гонки запрещено стоять на крыше чужого транспорта!");
			}//Игрок на крыше чьего-то авто
		}//после старта гонки
		if (FRTimeToEnd == 899 && FRStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (FRTimeToEnd == 898 && FRStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6);}
		if (FRTimeToEnd == 897 && FRStarted[eid] == 1)
		{//В момент, когда игроки начинают ехать
		    ResetPlayerWeapons(eid);
			PlayerPlaySound(eid,1057,0.0,0.0,0.0);
			GameTextForPlayer(eid, "GO",1000,6);
			TogglePlayerControllable(eid,1);
		}//В момент, когда игроки начинают ехать
		if (FRTimeTransform == 0 && IsPlayerInAnyVehicle(eid))
		{//трансформация авто
			LastSpeed[eid] = 999; NeedSpeedDown[eid] = 1; LACSH[eid] = 3;//чтобы не работал LAC на SpeedHack (ложные срабатывания)
			new Float: x, Float: y, Float: z, Float: Angle;
			new Float: vx, Float: vy, Float: vz;
			GetPlayerPos(eid,x,y,z);GetVehicleVelocity(FRCarID[eid], vx, vy, vz);GetVehicleZAngle(FRCarID[eid], Angle);
			DestroyVehicle(FRCarID[eid]);new col1 = random(187), col2 = random(187);
			FRCarID[eid] = LCreateVehicle(FRModelCar, x, y, z, Angle, col1, col2, 0);
			SetVehicleVirtualWorld(FRCarID[eid], 661);PutPlayerInVehicle(eid, FRCarID[eid], 0);
			SetVehicleVelocity(FRCarID[eid], vx, vy, vz);SpecUpdate(eid);	
			new rand = random(3);ChangeVehiclePaintjob(GetPlayerVehicleID(eid), rand);//случайный paintjob
			//Ниже закрываем двери
			new engine, lights, alarm, doors, bonnet, boot, objective;
			GetVehicleParamsEx(FRCarID[eid], engine, lights, alarm, doors, bonnet, boot, objective);
			SetVehicleParamsEx(FRCarID[eid], engine, lights, alarm, true, bonnet, boot, objective);
		}//трансформация авто
		if (FRTimeToEnd == 1)
		{//лимит по времени
			DestroyVehicle(FRCarID[eid]);FRCarID[eid] = 0;	
			SendClientMessage(eid,COLOR_RACE,"Гонка завершена (Лимит по времени: {FFFFFF}15{007FFF} минут)");	 
			FRTimeToEnd = -1; FRTimer = 0;JoinEvent[eid] = 0;FRStarted[eid] = 0;SetPlayerVirtualWorld(eid,0);
			DisablePlayerCheckpoint(eid);
			ShowClanZones(eid); // покажем клановые зоны
		}//лимит по времени
	}//Цикл для участников гонки
	if (FRTimeTransform == 0){FRTimeTransform = random(15) + 20;}
	if (FRPlayers == 0) {SendClientMessageToAll(COLOR_RACE,"Гонка завершена"); FRTimer = 0; FRTimeToEnd = 0;}
}//Во время гонки


if (FRTimer == 1)
{//Старт гонки
	for (new i = 0; i < 25; i++) FRPlayersList[i] = -1;//очищаем список игроков на гонке
	new i = 0; //Ниже заполняем список игроков на гонке
	foreach(Player, cid) if (JoinEvent[cid] == EVENT_RACE) {FRPlayersList[i] = cid; i++;} //Заполняем список игроков на гонке

	new cid, String[140];
	format(String,sizeof(String),"Гонка стартовала. Постарайтесь добраться до {FFFFFF}%s{007FFF} раньше других", FRName[FRFinish]);
	for (i = 0; i < 25; i++) 
	{//Цикл для участников гонки
		cid = FRPlayersList[i];
		if (!IsPlayerConnected(cid)) continue;
		
		if (JoinEvent[cid] == EVENT_RACE)
		{//игрок присоединен к гонке
			if (IsPlayerInCheckpoint(cid))
			{//игрок в чеке старта
				FlipCount[cid] = 3;FRTimeTransform = 10;
				FRStarted[cid] = 1;LAFK[cid] = 0;FRpos = 0; FRTimer = -1; FRTimeToEnd = 900;
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_RACE]);
	
				switch (FRFinish)
				{
					case 1: SetPlayerCheckpoint(cid,419.9553,2502.6494,17.2076, 15);
					case 2: SetPlayerCheckpoint(cid,-59.6410,2504.3281,17.2076, 15);
					case 3: SetPlayerCheckpoint(cid,-716.3835,2322.8191,127.9989, 15);
					case 4: SetPlayerCheckpoint(cid,-1113.1007,379.5110,14.8707, 15);
					case 5: SetPlayerCheckpoint(cid,-2318.7227,-1630.5919,484.4261, 15);
					case 6: SetPlayerCheckpoint(cid,-2423.3645,-608.0591,133.2852, 15);
					case 7: SetPlayerCheckpoint(cid,-2628.4731,1360.0398,7.8186, 15);
					case 8: SetPlayerCheckpoint(cid,822.8941,848.3994,11.9871, 15);
					case 9: SetPlayerCheckpoint(cid,2455.8059,-1658.7832,12.8714, 15);
					case 10: SetPlayerCheckpoint(cid,2196.0867,-1642.7052,14.8736, 15);
					case 11: SetPlayerCheckpoint(cid,153.9650,-1938.4340,3.3319, 15);
					case 12: SetPlayerCheckpoint(cid,2761.1501,-2453.0867,14.2697, 15);
					case 13: SetPlayerCheckpoint(cid,2031.7867,-2493.7588,13.2681, 15);
					case 14: SetPlayerCheckpoint(cid,1529.9385,-1675.8372,13.1099, 15);
					case 15: SetPlayerCheckpoint(cid,2171.5645,1683.1047,10.3822, 15);
					case 16: SetPlayerCheckpoint(cid,1517.9435,2231.4575,10.3948, 15);
					case 17: SetPlayerCheckpoint(cid,2628.7495,2299.8401,10.3120, 15);
					case 18: SetPlayerCheckpoint(cid,2343.8784,319.6856,32.3911, 15);
					case 19: SetPlayerCheckpoint(cid,-25.7401,-299.4633,5.1533, 15);
					case 20: SetPlayerCheckpoint(cid,-2006.8792,-71.4555,35.1719, 15);
					case 21: SetPlayerCheckpoint(cid,-2604.4465,566.0416,14.1875, 15);
					case 22: SetPlayerCheckpoint(cid,-1260.5172,457.8165,6.9146, 15);
					case 23: SetPlayerCheckpoint(cid,836.0139,-2051.3135,12.4215, 15);
					case 24: SetPlayerCheckpoint(cid,1797.6271,843.2887,10.3677, 15);
					case 25: SetPlayerCheckpoint(cid,2826.7703,1354.3590,10.3259, 15);
					case 26: SetPlayerCheckpoint(cid,2469.8474,2773.4763,10.2574, 15);
					case 27: SetPlayerCheckpoint(cid,135.4260,1967.8726,19.2429, 15);
					case 28: SetPlayerCheckpoint(cid,1057.1550,1753.6602,10.5474, 15);
					case 29: SetPlayerCheckpoint(cid,-2262.1436,2311.0701,5.5402, 15);
					case 30: SetPlayerCheckpoint(cid,2831.4766,-1771.9731,10.4509, 15);
					case 31: SetPlayerCheckpoint(cid,1263.6404,-2033.9982,59.0424, 15);
					case 32: SetPlayerCheckpoint(cid,-1020.1862,-648.5829,31.7349, 15);
					case 33: SetPlayerCheckpoint(cid,-490.1095,-528.8505,25.2436, 15);
					case 34: SetPlayerCheckpoint(cid,1426.4532,-2286.4304,13.1099, 15);
					case 35: SetPlayerCheckpoint(cid,-2146.5259,-2411.5569,30.2014, 15);
					case 36: SetPlayerCheckpoint(cid,-2134.3315,-413.9892,35.0630, 15);
					case 37: SetPlayerCheckpoint(cid,-1982.8717,845.4196,45.0240, 15);
					case 38: SetPlayerCheckpoint(cid,-2004.1323,1076.3872,55.1300, 15);
					case 39: SetPlayerCheckpoint(cid,1477.4835,1797.2253,10.5396, 15);
					case 40: SetPlayerCheckpoint(cid,-711.4286,2062.5952,60.1099, 15);	
				}
				
				SendClientMessage(cid,COLOR_RACE,String);
				TogglePlayerControllable(cid,0);PlayerPlaySound(cid,1056,0.0,0.0,0.0);GameTextForPlayer(cid, "3",1000,6);
				SetCameraBehindPlayer(cid);SetVehicleVelocity(GetPlayerVehicleID(cid), 0.0, 0.0, 0.0);
			}//игрок в чеке старта
			else
			{
				SendClientMessage(cid,COLOR_RED,"Внимание! Вы не были на старте гонки");
				JoinEvent[cid] = 0; InEvent[cid] = 0; DisablePlayerCheckpoint(cid); LSpawnPlayer(cid); ShowClanZones(cid); // покажем клановые зоны
			}
		}//игрок присоединен к гонке
		
		
	}//Цикл для участников гонки
	FRTimer = -1; FRTimeToEnd = 900;//вынес из цикла
}//Старт гонки
