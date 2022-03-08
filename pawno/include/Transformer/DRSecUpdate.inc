
//#define COLOR_DRACE 0x4C73E6FF
if (DRTimer > -7)
{
	DRTimer--; new String[60];
	format(String, sizeof String, "DRACE:~w~ %d sec. Players: %d", DRTimer, DRPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_DRACE], String);
}
if (DRTimer == 0)//не началось
{
	DRTimer = GetEventRestartTime();
	SendClientMessageToAll(COLOR_DRACE,"Гонка на выживание не началась, так как никого не было на старте.");
	while (PrevDR == DRid) DRid = random(MAX_DRACE) + 1;
	PrevDR = DRid;
	SetRandomGVVeh();

}//Каждые 40 минут
if (DRTimeToEnd >= 0) DRTimeToEnd--;

if (DRTimer == 60)
{
	new String[140];
	format (String, sizeof(String),"| Гонка на выживание [{FFFFFF}%s{4C73E6}] начнется через {FFFFFF}минуту{4C73E6}!", DRName[DRid]);
	SendClientMessageToAll(COLOR_DRACE,String);
	SendClientMessageToAll(COLOR_DRACE,"| Используйте {FFFFFF}/drace{4C73E6} если хотите участвовать");
}

if (DRTimer <= -1 && DRTimer >= -6)
{//три секунды после старта
	foreach(Player, eid)
	{//цикл
		if (DRTimer == -2 && DRStarted[eid] == 1 && DRTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "4",1000,6);TogglePlayerControllable(eid,0);}
		if (DRTimer == -3 && DRStarted[eid] == 1 && DRTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "3",1000,6);}
		if (DRTimer == -4 && DRStarted[eid] == 1 && DRTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (DRTimer == -5 && DRStarted[eid] == 1 && DRTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6);}
		if (DRTimer == -6 && DRStarted[eid] == 1 && DRTimeToEnd >= 0)
		{
			PlayerPlaySound(eid,1057,0.0,0.0,0.0);
			GameTextForPlayer(eid, "GO",1000,6);
			TogglePlayerControllable(eid,1);
			ResetPlayerWeapons(eid);
			switch(DRid)
			{
				case 1: SetPlayerRaceCheckpoint(eid, 3, DRACE1CP[DRPointID[0]][0], DRACE1CP[DRPointID[0]][1], DRACE1CP[DRPointID[0]][2], DRACE1CP[DRPointID[0]+1][0], DRACE1CP[DRPointID[0]+1][1], DRACE1CP[DRPointID[0]+1][2], 8.0);
				case 2: SetPlayerRaceCheckpoint(eid, 3, DRACE2CP[DRPointID[0]][0], DRACE2CP[DRPointID[0]][1], DRACE2CP[DRPointID[0]][2], DRACE2CP[DRPointID[0]+1][0], DRACE2CP[DRPointID[0]+1][1], DRACE2CP[DRPointID[0]+1][2], 8.0);
				case 3: SetPlayerRaceCheckpoint(eid, 3, DRACE3CP[DRPointID[0]][0], DRACE3CP[DRPointID[0]][1], DRACE3CP[DRPointID[0]][2], DRACE3CP[DRPointID[0]+1][0], DRACE3CP[DRPointID[0]+1][1], DRACE3CP[DRPointID[0]+1][2], 8.0);
				case 4: SetPlayerRaceCheckpoint(eid, 3, DRACE4CP[DRPointID[0]][0], DRACE4CP[DRPointID[0]][1], DRACE4CP[DRPointID[0]][2], DRACE4CP[DRPointID[0]+1][0], DRACE4CP[DRPointID[0]+1][1], DRACE4CP[DRPointID[0]+1][2], 8.0);
				case 5: SetPlayerRaceCheckpoint(eid, 3, DRACE5CP[DRPointID[0]][0], DRACE5CP[DRPointID[0]][1], DRACE5CP[DRPointID[0]][2], DRACE5CP[DRPointID[0]+1][0], DRACE5CP[DRPointID[0]+1][1], DRACE5CP[DRPointID[0]+1][2], 8.0);
				case 6: SetPlayerRaceCheckpoint(eid, 3, DRACE6CP[DRPointID[0]][0], DRACE6CP[DRPointID[0]][1], DRACE6CP[DRPointID[0]][2], DRACE6CP[DRPointID[0]+1][0], DRACE6CP[DRPointID[0]+1][1], DRACE6CP[DRPointID[0]+1][2], 8.0);
                case 7: SetPlayerRaceCheckpoint(eid, 3, DRACE7CP[DRPointID[0]][0], DRACE7CP[DRPointID[0]][1], DRACE7CP[DRPointID[0]][2], DRACE7CP[DRPointID[0]+1][0], DRACE7CP[DRPointID[0]+1][1], DRACE7CP[DRPointID[0]+1][2], 8.0);
			}
		}

		if (DRTimer <= -1 && DRTimer >= -3 && DRStarted[eid] == 1 && DRTimeToEnd >= 0)
		{//исправление бага игрок не в своем авто
			if (IsPlayerInAnyVehicle(eid))
			{//игрок уже в каком-то авто
				if (GetPlayerVehicleID(eid) != DRCarID[eid])
				{//игрок в авто, но не в том, в котором должен быть (чит или баг)
					DRStarted[eid] = 0; JoinEvent[eid] = 0; InEvent[eid] = 0;
					DestroyVehicle(GetPlayerVehicleID(eid)); LSpawnPlayer(eid);
					ShowClanZones(eid); // покажем клановые зоны
				}//игрок в авто, но не в том, в котором должен быть (чит или баг)
			}//игрок уже в каком-то авто
			else
			{//игрок без авто
				if (DRCarID[eid] == -1)
				{//транспорт для игрока еще не создан
					new randcolor1 = random(200);
					new randcolor2 = random(200);
					new Float: drx, Float: dry, Float: drz, Float: dra;
					GetPlayerPos(eid, drx, dry, drz);
					GetPlayerFacingAngle(eid, dra);
					DRCarID[eid] = LCreateVehicle(DRModelCar,drx, dry, drz,dra, randcolor1, randcolor2);
					SetVehicleHealth(DRCarID[eid],1000.0);//добавил
					LinkVehicleToInterior(DRCarID[eid], GetPlayerInterior(eid));
					SetPlayerVirtualWorld(eid, DRACE_WORLD);
					SetVehicleVirtualWorld(DRCarID[eid], DRACE_WORLD);
					PutPlayerInVehicle(eid, DRCarID[eid], 0);
					SpecUpdate(eid);
					new rand = random(3);
					ChangeVehiclePaintjob(GetPlayerVehicleID(eid), rand);//случайный paintjob
				}//транспорт для игрока еще не создан
				else
				{//транспорт для игрока уже создан
					SetPlayerVirtualWorld(eid, DRACE_WORLD);
					PutPlayerInVehicle(eid, DRCarID[eid], 0);
				}//транспорт для игрока уже создан
			}//игрок без авто
		}//исправление бага игрок не в своем авто
	}//цикл
}//три секунды после старта

if (DRTimer <= -7)
{
	//----
	new eid, String[140], Float: dx, Float: dy, Float: dz;
    if(DRTransform == 0) {SetRandomGVVeh();}
	for (new i = 0; i < 25; i++) 
	{//Цикл для участников
		eid = DRPlayersList[i];
		if (!IsPlayerConnected(eid) || DRStarted[eid] == 0) continue;

		if (LAFK[eid] >= 5){SendClientMessage(eid,COLOR_RED,"Вы были выброшены из гонки на выживание за AFK!"); JoinEvent[eid] = 0; InEvent[eid] = 0; DRStarted[eid] = 0; DisablePlayerRaceCheckpoint(eid); SetPlayerVirtualWorld(eid, 0); LSpawnPlayer(eid); ShowClanZones(eid);}
		
		GetPlayerPos(eid,dx,dy,dz);
		switch(DRid) //сделать массив
		{
		    case 1: if (dz < 866.16) DestroyVehicle(DRCarID[eid]);
		    case 2: if (dz < 1998.0) DestroyVehicle(DRCarID[eid]);
		    case 3: if (dz < 460.8) DestroyVehicle(DRCarID[eid]);
		    case 4: if (dz < 34.3) DestroyVehicle(DRCarID[eid]);
		    case 5: if (dz < 2001.0) DestroyVehicle(DRCarID[eid]);
		    case 6: if (dz < 1982.0) DestroyVehicle(DRCarID[eid]);
		    case 7: if (dz < 0.0) DestroyVehicle(DRCarID[eid]);
		    default: {}
		}
		
  		if(DRTransform < 6 && DRTransform > 0) {format(String,sizeof(String),"%d",DRTransform); GameTextForPlayer(eid, String,1000,6);}
		else if(DRTransform == 0)
		{
		    new typeof = random(2);
		    if(typeof == 0)
		    {
		        GameTextForPlayer(eid, "~b~nitro",1000,6);
		        AddVehicleComponent(GetPlayerVehicleID(eid), 1010);
			}
			else if(typeof == 1)
			{
			    GameTextForPlayer(eid, "~g~car",1000,6);
			    
			    LastSpeed[eid] = 999; NeedSpeedDown[eid] = 1; LACSH[eid] = 3;//чтобы не работал LAC на SpeedHack (ложные срабатывания)
				new Float: Angle;
				new Float: vx, Float: vy, Float: vz;
				GetVehicleVelocity(DRCarID[eid], vx, vy, vz);
				GetVehicleZAngle(DRCarID[eid], Angle);
				DestroyVehicle(DRCarID[eid]);
				new col1 = random(187), col2 = random(187);
				DRCarID[eid] = LCreateVehicle(DRModelCar, dx,dy,dz, Angle, col1, col2, 0);
				SetVehicleVirtualWorld(DRCarID[eid], DRACE_WORLD);
				PutPlayerInVehicle(eid, DRCarID[eid], 0);
				SetVehicleVelocity(DRCarID[eid], vx, vy, vz);
				SpecUpdate(eid);
				new rand = random(3);
				ChangeVehiclePaintjob(GetPlayerVehicleID(eid), rand);//случайный paintjob
				//Ниже закрываем двери
				new engine, lights, alarm, doors, bonnet, boot, objective;
				GetVehicleParamsEx(DRCarID[eid], engine, lights, alarm, doors, bonnet, boot, objective);
				SetVehicleParamsEx(DRCarID[eid], engine, lights, alarm, true, bonnet, boot, objective);
			}
		}
		
		if ((!IsPlayerInVehicle(eid,DRCarID[eid]) && DRPlayers > 0) || DRTimeToEnd == 1)///если игрок не за рулем авто ВРЕМЕННО УБРАЛ //сюда DRPlayers > 1)
		{//если вышел из авто или лимит по времени
			JoinEvent[eid] = 0; InEvent[eid] = 0; DRStarted[eid] = 0;
			
			if(DRLastPlayerCP[eid] > 0)
			{
			    new koeff=20; //от 4 до 6
			    if(DRLastPlayerCP[eid] < 4) koeff = 10; //от 1 до 3
			    else if(DRLastPlayerCP[eid] > 6) koeff = 25; //от 7
			    FarmedXP[eid] = 200 + koeff * (DRPosition-1);
				FarmedMoney[eid] = 20000 + koeff*100 * (DRPosition);
				
				if (FarmedXP[eid] > 1000){FarmedXP[eid] = 1000;}//Лимит на 1000 ХР
				
				if (DRPlayers == 3 && DRpos == 2){FarmedXP[eid] += 50;format(String,sizeof(String),"%s[%d] занял третье место в гонке на выживание и получил %d XP и %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DRACE,String);}
				if (DRPlayers == 2 && DRpos == 1){FarmedXP[eid] += 100;format(String,sizeof(String),"%s[%d] занял второе место в гонке на выживание и получил %d XP и %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DRACE,String);}
                if (DRPlayers == 1 && DRpos == 0){FarmedXP[eid] += 150;format(String,sizeof(String),"%s[%d] выиграл в гонке на выживание и получил %d XP и %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DRACE,String); MarafonUpdate(eid, 2, 1);}

				LGiveXP(eid, FarmedXP[eid]);
				Player[eid][Cash] += FarmedMoney[eid];
				format(String,sizeof(String),"За участие в гонке на выживание вы получили %dXP и %d$. Вы заняли: %d-ое место",FarmedXP[eid],FarmedMoney[eid],DRPlayers);
				SendClientMessage(eid,COLOR_YELLOW,String);

				QuestUpdate(eid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				QuestUpdate(eid, 31, 1);//принять участие в дрейс
				MarafonUpdate(eid, 0, 1);
				MarafonUpdate(eid, 5, FarmedMoney[eid]);
			}
			DisablePlayerRaceCheckpoint(eid);
			DestroyVehicle(DRCarID[eid]);
			DRCarID[eid] = 0;
			DRPosition++;
			DRPlayers--;
			ResetPlayerWeapons(eid); LSpawnPlayer(eid);
			ShowClanZones(eid); // покажем клановые зоны
			continue;
		}//если вышел из авто или лимит по времени
		
		GetVehicleHealth(GetPlayerVehicleID(eid), dchealth);
		if (dchealth <= 250.0 && JoinEvent[eid] == EVENT_DRACE) DestroyVehicle(DRCarID[eid]);//?????????? ????????? ???????? ? ????

	}//Цикл для участников
	
	if(DRTransform == 0) {DRTransform = 30;}
	
	if (DRPlayers == 0)
	{
		DRTimeToEnd = 0;
		SendClientMessageToAll(COLOR_DRACE,"Гонка на выживание завершена.");
		DRTimer = GetEventRestartTime();

		while (PrevDR == DRid) DRid = random(MAX_DRACE) + 1;
		PrevDR = DRid;
		SetRandomGVVeh();
	}
	
	if (DRTransform > 0) DRTransform--;
	
}//Во время проведения

if(DRTimer == 1)
{//Старт
	if (DRPlayers < 1)//< 2 //сюда
	{//не началось
		SendClientMessageToAll(COLOR_DRACE,"Гонка на выживание не началась, так как не хватило участников (Минимум:{FFFFFF} 2{4C73E6})");
		foreach(Player, eid)
		{//цикл
			if (JoinEvent[eid] == EVENT_DRACE)
			{//единственный участник
				JoinEvent[eid] = 0;
				InEvent[eid] = 0;
				DRStarted[eid] = 0;
			}//единственный участник
		}//цикл
		DRTimer = GetEventRestartTime();
		DRTimeToEnd = 0;
	}//не началось
	else
	{//стартовало
		for (new i = 0; i < 25; i++) DRPlayersList[i] = -1;//очищаем список игроков
		new i = 0; //Ниже заполняем список игроков
		foreach(Player, cid) if (JoinEvent[cid] == EVENT_DRACE) {DRPlayersList[i] = cid; i++;}
		
		new MaxPoint;
		switch(DRid)
		{
		    case 1: {MaxPoint = sizeof(DRACE1CP)-1;DRMaxCPs = 9 + random(5);}
		    case 2: {MaxPoint = sizeof(DRACE2CP)-1;DRMaxCPs = 9 + random(5);}
		    case 3: {MaxPoint = sizeof(DRACE3CP)-1;DRMaxCPs = 5 + random(4);}
		    case 4: {MaxPoint = sizeof(DRACE4CP)-1;DRMaxCPs = 5 + random(3);}
		    case 5: {MaxPoint = sizeof(DRACE5CP)-1;DRMaxCPs = 10 + random(6);}
		    case 6: {MaxPoint = sizeof(DRACE6CP)-1;DRMaxCPs = 8 + random(6);}
		    case 7: {MaxPoint = sizeof(DRACE7CP)-1;DRMaxCPs = 7 + random(4);}
		    default: MaxPoint = 10; //min 10
		}
		
		//DRMaxCPs = 9 + random(7); //от 9 до 15
		DRPointID[0] = random(MaxPoint);
		
		for(new ic=1; ic<DRMaxCPs;ic++)
		{
			DRPointID[ic] = random(MaxPoint);
			if(DRPointID[ic] == DRPointID[ic-1])
			{
				DRPointID[ic] = random(MaxPoint);
			}
		}
		DRStartPlayers = 0;

		new cid, SpawnNumber = 0, String[140];
		for (i = 0; i < 25; i++) 
		{//Цикл для участников
			cid = DRPlayersList[i];
			if (!IsPlayerConnected(cid)) continue;
			
			if (JoinEvent[cid] == EVENT_DRACE)
			{//если игрок в ивенте
			    DRStartPlayers++;
				StopFly(cid);
				StopVehFly(cid);
				ResetPlayerWeapons(cid);
				LACSH[cid] = 3;
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_DRACE]);
				HideClanZones(cid); //скрываем зоны
				Player[cid][CarActive] = 0; //Исправляет баг с использованием навыков
				
				DRLastPlayerCP[cid] = 0;
				JumpCount[cid] = 3;
				
				SendClientMessage(cid,COLOR_RED,"Подсказка:{ffffff} используйте клавишу гудка (по умолчанию CapsLock или H англs.), чтобы {00ff00}совершить прыжок.");
				
				switch (DRid)
				{//switch
					case 1: //АТОМ
					{
						SetPlayerPos(cid, DRACE1COORD[SpawnNumber][0], DRACE1COORD[SpawnNumber][1],DRACE1COORD[SpawnNumber][2]);
						SetPlayerFacingAngle(cid, DRACE1COORD[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 2: //Стартрек
					{
						SetPlayerPos(cid, DRACE2COORD[SpawnNumber][0], DRACE2COORD[SpawnNumber][1],DRACE2COORD[SpawnNumber][2]);
						SetPlayerFacingAngle(cid, DRACE2COORD[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 3: //Undercover
					{
						SetPlayerPos(cid, DRACE3COORD[SpawnNumber][0], DRACE3COORD[SpawnNumber][1],DRACE3COORD[SpawnNumber][2]);
						SetPlayerFacingAngle(cid, DRACE3COORD[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 4: //Форт Боярд
					{
						SetPlayerPos(cid, DRACE4COORD[SpawnNumber][0], DRACE4COORD[SpawnNumber][1],DRACE4COORD[SpawnNumber][2]);
						SetPlayerFacingAngle(cid, DRACE4COORD[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 5: //Sky Cubes
					{
						SetPlayerPos(cid, DRACE5COORD[SpawnNumber][0], DRACE5COORD[SpawnNumber][1],DRACE5COORD[SpawnNumber][2]);
						SetPlayerFacingAngle(cid, DRACE5COORD[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 6: //4x4 Offroad
					{
						SetPlayerPos(cid, DRACE6COORD[SpawnNumber][0], DRACE6COORD[SpawnNumber][1],DRACE6COORD[SpawnNumber][2]);
						SetPlayerFacingAngle(cid, DRACE6COORD[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 7: //Бездорожье
					{
						SetPlayerPos(cid, DRACE7COORD[SpawnNumber][0], DRACE7COORD[SpawnNumber][1],DRACE7COORD[SpawnNumber][2]);
						SetPlayerFacingAngle(cid, DRACE7COORD[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
				}//switch

				TogglePlayerControllable(cid,0);
				SetPlayerVirtualWorld(cid, DRACE_WORLD);
				DRStarted[cid] = 1;
				LAFK[cid] = 0;
				Player[cid][CarActive] = 0;
				SetCameraBehindPlayer(cid);
				DRCarID[cid] = -1;
				SpawnNumber++;//Чтобы другой игрок заспавнился уже в другом месте
			}//если игрок в drace
		}//Цикл для участников
		DRPosition = 1;
		DRTimer = -1;
	 	DRTimeToEnd = 900;
 	 	DRTransform = 30;
 	 	DRpos = 0;
 	 	//DRLastpos = 1;
		format (String, sizeof(String),"Гонка на выживание <<{FFFFFF}%s{4C73E6}>> началась. Игроков: {FFFFFF}%d",DRName[DRid], DRPlayers);
		SendClientMessageToAll(COLOR_DRACE,String);
	}//стартовало

}//Старт
