if (DerbyTimer > -7) 
{
	DerbyTimer--; new String[60];
	format(String, sizeof String, "DERBY:~w~ %d sec. Players: %d", DerbyTimer, DerbyPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_DERBY], String);
}
if (DerbyTimer == 0)//Дерби не началось
{
	DerbyTimer = GetEventRestartTime();
	SendClientMessageToAll(COLOR_DERBY,"Дерби не началось, так как никого не было на старте.");
	while (PrevDerby == Derbyid) Derbyid = random(MAX_DERBYS) + 1;
	PrevDerby = Derbyid;
	//Выбор модели авто для дерби, где оно у всех одинаковое
	if (Derbyid == 1) {new modelid = random(123);DerbyModelAll = DerbyCars[modelid];}
	if (Derbyid == 3) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
	if (Derbyid == 7) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
	if (Derbyid == 9) DerbyModelAll = 432; //World Of Tanks
	if (Derbyid == 10) DerbyModelAll = 557;
	if (Derbyid == 11) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
	if (Derbyid == 12) DerbyModelAll = 411;
	if (Derbyid == 13) DerbyModelAll = 489;
	if (Derbyid == 15) DerbyModelAll = 530;
	if (Derbyid == 18) DerbyModelAll = 430;
	//if (Derbyid == 19) DerbyModelAll = 565;
	for(new cid = 0; cid < MAX_PLAYERS; cid++) DerbyModelCar[cid] = DerbyModelAll; //обязательно обычный for
}//Каждые 40 минут
if (DerbyTimeToEnd >= 0) DerbyTimeToEnd--;

if (DerbyTimer == 60)
{
	new String[140];
	//if(Derbyid == 19){format (String, sizeof(String),"Дерби <<{FF0000}%s{9966CC}>> начнется через {FF0000}минуту{9966CC}!", DerbyName[Derbyid]);}
	format (String, sizeof(String),"| Дерби [{FFFFFF}%s{9966CC}] начнется через {FFFFFF}минуту{9966CC}!", DerbyName[Derbyid]);
	SendClientMessageToAll(COLOR_DERBY,String);
	new bool: dscan;
	switch(Derbyid-1)
	{
	    case 0: dscan = true;
	    case 1: dscan = false;
	    case 2: dscan = true;
	    case 3: dscan = false;
	    case 4: dscan = false;
	    case 5: dscan = false;
	    case 6: dscan = true;
	    case 7: dscan = false;
	    case 8: dscan = true;
	    case 9: dscan = true;
	    case 10: dscan = false;
	    case 11: dscan = true;
	    case 12: dscan = true;
	    case 13: dscan = false;
	    case 14: dscan = true;
	    case 15: dscan = false;
	    case 16: dscan = false;
	    case 17: dscan = true;
	    case 18: dscan = false;
	    case 19: dscan = false;
	    case 20: dscan = false;
	    //case 18: dscan = false; //ny
	}
	new DState[12];
	if (dscan == true) DState = "Одинаковый";
	else DState = "Случайный";
	format (String, sizeof(String),"| Транспорт: {FFFFFF}%s{9966CC}. Используйте {FFFFFF}/derby{9966CC}, если хотите участвовать", DState);
	SendClientMessageToAll(COLOR_DERBY,String);
}



if (DerbyTimer <= -1 && DerbyTimer >= -6)
{//три секунды после старта
	foreach(Player, eid)
	{//цикл
		if (DerbyTimer == -2 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "4",1000,6);TogglePlayerControllable(eid,0);}
		if (DerbyTimer == -3 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "3",1000,6);}
		if (DerbyTimer == -4 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (DerbyTimer == -5 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6); SetVehicleHealth(DerbyCarID[eid],650.0);}
		if (DerbyTimer == -6 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1057,0.0,0.0,0.0);GameTextForPlayer(eid, "GO",1000,6);TogglePlayerControllable(eid,1);ResetPlayerWeapons(eid);}

		if (DerbyTimer <= -1 && DerbyTimer >= -3 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0)
		{//исправление бага игрок не в своем авто для дерби
			if (IsPlayerInAnyVehicle(eid))
			{//игрок уже в каком-то авто
				if (GetPlayerVehicleID(eid) != DerbyCarID[eid])
				{//игрок в авто, но не в том, в котором должен быть (чит или баг)
					DerbyStarted[eid] = 0; JoinEvent[eid] = 0; InEvent[eid] = 0;
					DestroyVehicle(GetPlayerVehicleID(eid)); LSpawnPlayer(eid);
					ShowClanZones(eid); // покажем клановые зоны
				}//игрок в авто, но не в том, в котором должен быть (чит или баг)
			}//игрок уже в каком-то авто
			else
			{//игрок без авто
				if (DerbyCarID[eid] == -1)
				{//транспорт для игрока еще не создан
					new randcolor1 = random(200);
					new randcolor2 = random(200);
					new Float: drx, Float: dry, Float: drz, Float: dra;
					GetPlayerPos(eid, drx, dry, drz);
					GetPlayerFacingAngle(eid, dra);
					DerbyCarID[eid] = LCreateVehicle(DerbyModelCar[eid],drx, dry, drz,dra, randcolor1, randcolor2);
					SetVehicleHealth(DerbyCarID[eid],650.0);//добавил
					LinkVehicleToInterior(DerbyCarID[eid], GetPlayerInterior(eid));
					SetVehicleVirtualWorld(DerbyCarID[eid], 664);
					SetPlayerVirtualWorld(eid, 664);
					PutPlayerInVehicle(eid, DerbyCarID[eid], 0);
					SpecUpdate(eid);
					new rand = random(3);
					ChangeVehiclePaintjob(GetPlayerVehicleID(eid), rand);//случайный paintjob
				}//транспорт для игрока еще не создан
				else
				{//транспорт для игрока уже создан
					SetPlayerVirtualWorld(eid, 664);
					PutPlayerInVehicle(eid, DerbyCarID[eid], 0);
				}//транспорт для игрока уже создан
			}//игрок без авто
		}//исправление бага игрок не в своем авто для дерби
	}//цикл
}//три секунды после старта

if (DerbyTimer <= -7)
{//Во время проведения дерби
	//----
	/*if(DerbyTimeToEnd-DRemStats[PCTime] < 0)
	{
	    if(DRemStats[IsRActived] == 0)
	    {
	        new PoS=random(sizeof(DERBY1SPAWN));
	        switch(Derbyid)
	        {
	        	case 1: CreateRepairPoint(DERBY1SPAWN[PoS][0], DERBY1SPAWN[PoS][1], DERBY1SPAWN[PoS][2], 664, 16);
	        	case 2: CreateRepairPoint(DERBY1SPAWN[PoS][0], DERBY1SPAWN[PoS][1], DERBY1SPAWN[PoS][2], 664, 16);
	        	case 3: CreateRepairPoint(DERBY2SPAWN[PoS][0], DERBY2SPAWN[PoS][1], DERBY2SPAWN[PoS][2], 664, 15);
	        	case 4: CreateRepairPoint(DERBY2SPAWN[PoS][0], DERBY2SPAWN[PoS][1], DERBY2SPAWN[PoS][2], 664, 15);
	        	case 5: CreateRepairPoint(DERBY5SPAWN[PoS][0], DERBY5SPAWN[PoS][1], DERBY5SPAWN[PoS][2], 664, 0);
                case 6: CreateRepairPoint(DERBY6SPAWN[PoS][0], DERBY6SPAWN[PoS][1], DERBY6SPAWN[PoS][2], 664, 0);
                case 7: CreateRepairPoint(DERBY7SPAWN[PoS][0], DERBY7SPAWN[PoS][1], DERBY7SPAWN[PoS][2], 664, 0);
                case 8: CreateRepairPoint(DERBY8SPAWN[PoS][0], DERBY8SPAWN[PoS][1], DERBY8SPAWN[PoS][2], 664, 0);
                case 9: CreateRepairPoint(DERBY9SPAWN[PoS][0], DERBY9SPAWN[PoS][1], DERBY9SPAWN[PoS][2], 664, 0);
                case 10: CreateRepairPoint(DERBY10SPAWN[PoS][0], DERBY10SPAWN[PoS][1], DERBY10SPAWN[PoS][2], 664, 0);
				case 11: CreateRepairPoint(DERBY11SPAWN[PoS][0], DERBY11SPAWN[PoS][1], DERBY11SPAWN[PoS][2], 664, 0);
				case 12: CreateRepairPoint(DERBY12SPAWN[PoS][0], DERBY12SPAWN[PoS][1], DERBY12SPAWN[PoS][2], 664, 0);
                case 13: CreateRepairPoint(DERBY13SPAWN[PoS][0], DERBY13SPAWN[PoS][1], DERBY13SPAWN[PoS][2], 664, 0);
                default: printf("Ошибка системы! Нет слота ремонта для дерби!");
        	}
	    }
    }*/
	//----
	new eid, String[140], Float: dx, Float: dy, Float: dz;
	for (new i = 0; i < 25; i++) 
	{//Цикл для участников дерби
		eid = DerbyPlayersList[i];
		if (!IsPlayerConnected(eid) || DerbyStarted[eid] == 0) continue;

		GetPlayerPos(eid,dx,dy,dz);
		if (Derbyid < 3 && dz < 1039) DestroyVehicle(DerbyCarID[eid]);//вылетел с арены
		if (Derbyid == 5 && dz < 9.5) DestroyVehicle(DerbyCarID[eid]);//вылетел с арены на карте "На Грани"zs
		if (Derbyid == 6 && dz < 2.0) DestroyVehicle(DerbyCarID[eid]);//вылетел с арены на карте "Без Гарантий"
		if (Derbyid == 7 && dz < 0.5) DestroyVehicle(DerbyCarID[eid]);//вылетел с арены на карте "Перекрестки"
		if (Derbyid == 8 && dz < 135) DestroyVehicle(DerbyCarID[eid]);//вылетел с арены на карте "Пять Башен"
		if (Derbyid == 9 && (dx < 1667.7567 || dx > 1931.5044 || dy < -2695.9065 || dy > -2388.4578 || dz < 13 || dz > 40)) DestroyVehicle(DerbyCarID[eid]);//вылетел с арены на карте "World Of Tanks"
		if (Derbyid == 10 && dz < 2037.6762) DestroyVehicle(DerbyCarID[eid]); //вылет на На пирамидах
		if (Derbyid == 11 && dz < 222.6) DestroyVehicle(DerbyCarID[eid]); //вылет на свободное падение
		if (Derbyid == 12 && dz < 1003.0) DestroyVehicle(DerbyCarID[eid]); //вылет нахуй
		if (Derbyid == 13 && dz < 950.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 14 && dz < 1.09) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 15 && dz < 1017.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 16 && dz < 1949.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 17 && dz < 2879.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 19 && dz < 1533.5) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 20 && dz <  3199.12) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 21 && dz < 2170.89) DestroyVehicle(DerbyCarID[eid]);
		//if (Derbyid == 19 && dz < 143.5) DestroyVehicle(DerbyCarID[eid]);
		if (LAFK[eid] >= 3){SendClientMessage(eid,COLOR_RED,"Вы были выброшены из дерби за AFK!"); JoinEvent[eid] = 0; InEvent[eid] = 0; DerbyStarted[eid] = 0; SetPlayerVirtualWorld(eid, 0); LSpawnPlayer(eid); ShowClanZones(eid);}
		
		if ((!IsPlayerInVehicle(eid,DerbyCarID[eid]) && DerbyPlayers > 1) || DerbyTimeToEnd == 1)///если игрок не за рулем авто ВРЕМЕННО УБРАЛ
		{//если вышел из авто или лимит по времени
			JoinEvent[eid] = 0; InEvent[eid] = 0; DerbyStarted[eid] = 0; 
			if (DerbyPosition < 9){FarmedXP[eid] = 100 + DerbyPosition*45;}//Не более 8 позиций: 100 + 360
			if (DerbyPosition < 17 && DerbyPosition > 8){new x = DerbyPosition - 8;FarmedXP[eid] = 100 + 360 + x*30;}//от 9 до 16 позиций: 100 + 360 за первые 8, а за последующие по 30
			if (DerbyPosition >= 17){new x = DerbyPosition - 16;FarmedXP[eid] = 100 + 360 + 240 + x*20;}
			FarmedMoney[eid] = 5000 + 650*DerbyPosition;
			if (DerbyPlayers == 2){FarmedXP[eid] += 140;}//бонусы за призовые места
			if (DerbyPlayers == 3){FarmedXP[eid] += 85;}//бонусы за призовые места
			if (FarmedXP[eid] > 1000){FarmedXP[eid] = 1000;}//Лимит на 1000 ХР

			/*if(Derbyid == 19)
			{
				FarmedXP[eid] = FarmedXP[eid]*2;
                FarmedMoney[eid] = FarmedMoney[eid]*2;
			}*/
			
			MarafonUpdate(eid, 0, 1);
			//MarafonUpdate(eid, 1, FarmedXP[eid]);
			MarafonUpdate(eid, 5, FarmedMoney[eid]);
			
			
			LGiveXP(eid, FarmedXP[eid]); Player[eid][Cash] += FarmedMoney[eid];
			format(String,sizeof(String),"За участие в дерби вы получили %dXP и %d$. Вы заняли: %d-ое место",FarmedXP[eid],FarmedMoney[eid],DerbyPlayers);
			SendClientMessage(eid,COLOR_YELLOW,String);
			if (DerbyPlayers == 3){format(String,sizeof(String),"%s[%d] занял третье место в дерби и получил %d XP и %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DERBY,String);}
			if (DerbyPlayers == 2){format(String,sizeof(String),"%s[%d] занял второе место в дерби и получил %d XP и %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DERBY,String);}
			DestroyVehicle(DerbyCarID[eid]); DerbyCarID[eid] = 0; DerbyPosition += 1; DerbyPlayers--;
			QuestUpdate(eid, 12, 1);//Обновление квеста Примите участие в 3 дерби
			QuestUpdate(eid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
			ShowClanZones(eid); // покажем клановые зоны
			ResetPlayerWeapons(eid); LSpawnPlayer(eid); continue;
		}//если вышел из авто или лимит по времени
		if (DerbyStarted[eid] == 1 && DerbyPlayers == 1) // == 1
		{//последний выживший
			JoinEvent[eid] = 0; DerbyStarted[eid] = 0; 
			if (DerbyPosition < 9){FarmedXP[eid] = 300 + DerbyPosition*45;}//Не более 8 позиций: 300 + 360
			if (DerbyPosition < 17 && DerbyPosition > 8){new x = DerbyPosition - 8;FarmedXP[eid] = 300 + 360 + x*30;}//от 9 до 16 позиций: 300 + 360 за первые 8, а за последующие по 30
			if (DerbyPosition >= 17){new x = DerbyPosition - 16;FarmedXP[eid] = 300 + 360 + 240 + x*20;}
			FarmedMoney[eid] = 5000 + 650*DerbyPosition;			
			FarmedMoney[eid] = 5000 + 650*DerbyPosition;if (FarmedXP[eid] > 1000){FarmedXP[eid] = 1000;}//Лимит на 1000 ХР (1200 вместе с итоговыми местами)

            /*if(Derbyid == 19)
			{
				FarmedXP[eid] = FarmedXP[eid]*2;
                FarmedMoney[eid] = FarmedMoney[eid]*2;
			}*/

			MarafonUpdate(eid, 0, 1);
			MarafonUpdate(eid, 2, 1);
			MarafonUpdate(eid, 5, FarmedMoney[eid]);

			LGiveXP(eid, FarmedXP[eid]); Player[eid][Cash] += FarmedMoney[eid];
			format(String,sizeof(String),"За участие в дерби вы получили %dXP и %d$. Вы заняли: %d-ое место",FarmedXP[eid],FarmedMoney[eid],DerbyPlayers);
			SendClientMessage(eid,COLOR_YELLOW,String);
			format(String,sizeof(String),"%s[%d] победил в дерби и получил %d XP и %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DERBY,String);
			DestroyVehicle(DerbyCarID[eid]);DerbyCarID[eid] = 0;DerbyPosition += 1;
			QuestUpdate(eid, 12, 1);//Обновление квеста Примите участие в 3 дерби
			QuestUpdate(eid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
			//MarafonUpdate(eid, 1, 0, FarmedMoney[eid], FarmedXP[eid]);
			ShowClanZones(eid); // покажем клановые зоны
			ResetPlayerWeapons(eid); LSpawnPlayer(eid); continue;
		}//последний выживший
		
		/*GetVehicleHealth(GetPlayerVehicleID(eid), dchealth);
		if (dchealth <= 250.0 && JoinEvent[eid] == EVENT_DERBY) DestroyVehicle(DerbyCarID[eid]);//Ускоренное отнимание здоровья у авто
		else
		{
			format(String, sizeof String, "%0.0f hp", dchealth - 250.0);
			if (dchealth >= 500.0) SetPlayerChatBubble(eid, String, COLOR_GREEN, 200.0, 1500);
			else if (dchealth >= 350.0) SetPlayerChatBubble(eid, String, COLOR_ORANGE, 200.0, 1500);
			else SetPlayerChatBubble(eid, String, COLOR_RED, 200.0, 1500);
		}*/
		
		GetVehicleHealth(GetPlayerVehicleID(eid), dchealth);
		if (dchealth <= 250.0 && JoinEvent[eid] == EVENT_DERBY) DestroyVehicle(DerbyCarID[eid]);//
		else
		{
			if (dchealth > 650.0) SetVehicleHealth(DerbyCarID[eid], 650.0);

			format(String, sizeof String, "%0.0f hp", dchealth - 250.0);
			if (dchealth >= 500.0) SetPlayerChatBubble(eid, String, COLOR_GREEN, 200.0, 1500);
			else if (dchealth >= 350.0) SetPlayerChatBubble(eid, String, COLOR_ORANGE, 200.0, 1500);
			else SetPlayerChatBubble(eid, String, COLOR_RED, 200.0, 1500);
		}
	}//Цикл для участников дерби

	if (DerbyPlayers == 0)
	{
		DerbyTimeToEnd = 0;
		SendClientMessageToAll(COLOR_DERBY,"Дерби завершено.");
		DerbyTimer = GetEventRestartTime();
		/*if(DRemStats[IsRActived] == 1)
		{
        	DestroyDynamicObject(DRemStats[RepObj]);
        	DestroyDynamic3DTextLabel(DRemStats[rtext]);
			DestroyDynamicArea(DRemStats[RepZone]);
			DRemStats[IsRActived] = 0;
		}*/
		while (PrevDerby == Derbyid) Derbyid = random(MAX_DERBYS) + 1;
		PrevDerby = Derbyid;
		//Выбор модели авто для дерби, где оно у всех одинаковое
		if (Derbyid == 1) {new modelid = random(123);DerbyModelAll = DerbyCars[modelid];}
		if (Derbyid == 3) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
		if (Derbyid == 7) {new modelid = random(76);DerbyModelAll = DerbyCars2[modelid];}
		if (Derbyid == 9) DerbyModelAll = 432; //World Of Tanks
		if (Derbyid == 10) DerbyModelAll = 557; //4 pyramids
		if (Derbyid == 12) DerbyModelAll = 411;
		if (Derbyid == 13) DerbyModelAll = 489;
		if (Derbyid == 15) DerbyModelAll = 530;
		if (Derbyid == 18) DerbyModelAll = 430;
		//if (Derbyid == 19) DerbyModelAll = 565;
		for(new cid = 0; cid < MAX_PLAYERS; cid++) DerbyModelCar[cid] = DerbyModelAll; //обязательно обычный for
	}
}//Во время проведения дерби

if(DerbyTimer == 1)
{//Старт дерби
	if (DerbyPlayers < 2)//< 2
	{//Дерби не началось
		SendClientMessageToAll(COLOR_DERBY,"Дерби не началось, так как не хватило участников (Минимум:{FFFFFF} 2{9966CC})");
		foreach(Player, eid)
		{//цикл
			if (JoinEvent[eid] == EVENT_DERBY)
			{//единственный участник
				JoinEvent[eid] = 0; InEvent[eid] = 0; DerbyStarted[eid] = 0;
			}//единственный участник
		}//цикл
		DerbyTimer = GetEventRestartTime(); DerbyTimeToEnd = 0;
	}//Дерби не началось
	else
	{//Дерби стартовало
		for (new i = 0; i < 25; i++) DerbyPlayersList[i] = -1;//очищаем список игроков на дерби
		new i = 0; //Ниже заполняем список игроков на дерби
		foreach(Player, cid) if (JoinEvent[cid] == EVENT_DERBY) {DerbyPlayersList[i] = cid; i++;}
		
		DerbyTimer = -1; DerbyPosition = 1; DerbyTimeToEnd = 900;
		
		new cid, SpawnNumber = 0, String[140];
		for (i = 0; i < 25; i++) 
		{//Цикл для участников дерби
			cid = DerbyPlayersList[i];
			if (!IsPlayerConnected(cid)) continue;
			
			if (JoinEvent[cid] == EVENT_DERBY)
			{//если игрок в дерби
				StopFly(cid);StopVehFly(cid);
				ResetPlayerWeapons(cid);LACSH[cid] = 3;
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_DERBY]);
				HideClanZones(cid);
				Player[cid][CarActive] = 0; //Исправляет баг с использованием навыков в дерби
				switch (Derbyid)
				{//switch
					case 1:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid, DERBY1SPAWN[SpawnNumber][0], DERBY1SPAWN[SpawnNumber][1],DERBY1SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY1SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 16);
					}
					case 2:
					{
						new modelid = random(123);DerbyModelCar[cid] = DerbyCars[modelid];//выбор модели авто					
						SetPlayerPos(cid, DERBY1SPAWN[SpawnNumber][0], DERBY1SPAWN[SpawnNumber][1],DERBY1SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY1SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 16);
					}
					case 3:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid, DERBY2SPAWN[SpawnNumber][0], DERBY2SPAWN[SpawnNumber][1],DERBY2SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY2SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 15);
					}
					case 4:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//выбор модели авто					
						SetPlayerPos(cid, DERBY2SPAWN[SpawnNumber][0], DERBY2SPAWN[SpawnNumber][1],DERBY2SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY2SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 15);
					}
					case 5:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//выбор модели авто					
						SetPlayerPos(cid, DERBY5SPAWN[SpawnNumber][0], DERBY5SPAWN[SpawnNumber][1],DERBY5SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY5SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 6:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//выбор модели авто					
						SetPlayerPos(cid, DERBY6SPAWN[SpawnNumber][0], DERBY6SPAWN[SpawnNumber][1],DERBY6SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY6SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 7:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY7SPAWN[SpawnNumber][0], DERBY7SPAWN[SpawnNumber][1],DERBY7SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY7SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 8:
					{
						new modelid = random(123);DerbyModelCar[cid] = DerbyCars[modelid];//выбор модели авто					
						SetPlayerPos(cid, DERBY8SPAWN[SpawnNumber][0], DERBY8SPAWN[SpawnNumber][1],DERBY8SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY8SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0); 
					}
					case 9:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY9SPAWN[SpawnNumber][0], DERBY9SPAWN[SpawnNumber][1],DERBY9SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY9SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 10:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY10SPAWN[SpawnNumber][0], DERBY10SPAWN[SpawnNumber][1],DERBY10SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY10SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 11:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//выбор модели авто
						SetPlayerPos(cid, DERBY11SPAWN[SpawnNumber][0], DERBY11SPAWN[SpawnNumber][1],DERBY11SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY11SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 12:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY12SPAWN[SpawnNumber][0], DERBY12SPAWN[SpawnNumber][1],DERBY12SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY12SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 13:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY13SPAWN[SpawnNumber][0], DERBY13SPAWN[SpawnNumber][1],DERBY13SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY13SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 14:
					{
						new modelid = random(sizeof(DerbyJeeps));DerbyModelCar[cid] = DerbyJeeps[modelid];//выбор модели авто
						SetPlayerPos(cid,DERBY14SPAWN[SpawnNumber][0], DERBY14SPAWN[SpawnNumber][1],DERBY14SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY14SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 15:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY15SPAWN[SpawnNumber][0], DERBY15SPAWN[SpawnNumber][1],DERBY15SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY15SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 16:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//выбор модели авто
						SetPlayerPos(cid, DERBY16SPAWN[SpawnNumber][0], DERBY16SPAWN[SpawnNumber][1],DERBY16SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY16SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 17:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//выбор модели авто
						SetPlayerPos(cid, DERBY17SPAWN[SpawnNumber][0], DERBY17SPAWN[SpawnNumber][1],DERBY17SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY17SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 18:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY18SPAWN[SpawnNumber][0], DERBY18SPAWN[SpawnNumber][1],DERBY18SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY18SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 19:
					{
						new modelid = random(sizeof(DerbyJeeps));DerbyModelCar[cid] = DerbyJeeps[modelid];//выбор модели авто
						SetPlayerPos(cid,DERBY19SPAWN[SpawnNumber][0], DERBY19SPAWN[SpawnNumber][1],DERBY19SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY19SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 20:
					{
						new modelid = random(123);DerbyModelCar[cid] = DerbyCars[modelid];//выбор модели авто
						SetPlayerPos(cid, DERBY20SPAWN[SpawnNumber][0], DERBY20SPAWN[SpawnNumber][1],DERBY20SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY20SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 21:
					{
						new modelid = random(sizeof(DRFastCars));DerbyModelCar[cid] = DRFastCars[modelid];//выбор модели авто
						SetPlayerPos(cid,DERBY21SPAWN[SpawnNumber][0], DERBY21SPAWN[SpawnNumber][1],DERBY21SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY21SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					/*case 19:
					{
						DerbyModelCar[cid] = DerbyModelAll;
						SetPlayerPos(cid,DERBY19SPAWN[SpawnNumber][0], DERBY19SPAWN[SpawnNumber][1],DERBY19SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY19SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}*/
				}//switch

				TogglePlayerControllable(cid,0);
				SetPlayerVirtualWorld(cid, WORLD_DERBY);
				DerbyStarted[cid] = 1;
				LAFK[cid] = 0;
				Player[cid][CarActive] = 0;
				SetCameraBehindPlayer(cid);
				DerbyCarID[cid] = -1;
				SpawnNumber++;//Чтобы другой игрок заспавнился уже в другом месте
			}//если игрок в дерби
		}//Цикл для участников дерби
        //DRemStats[PCTime]=870;
        //DRemStats[IsRActived] = 0;
		format (String, sizeof(String),"Дерби <<{FFFFFF}%s{9966CC}>> началось. Игроков: {FFFFFF}%d",DerbyName[Derbyid], DerbyPlayers);
		SendClientMessageToAll(COLOR_DERBY,String);		
	}//Дерби стартовало

}//Старт дерби
