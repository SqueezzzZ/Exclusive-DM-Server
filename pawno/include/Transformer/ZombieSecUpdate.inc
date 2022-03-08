	if (ZMTimer > 0)
	{
		ZMTimer--; new String[60];
		format(String, sizeof String, "ZOMBIE:~w~ %d sec. Players: %d", ZMTimer, ZMPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_ZOMBIE], String);
	}
	if (ZMTimeToEnd >= 0) ZMTimeToEnd--;
	if (ZMTimeToFirstZombie > 0) ZMTimeToFirstZombie--;
	
	if (ZMTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| Зомби-Выживание [{FFFFFF}%s{E60020}] начнется через {FFFFFF}минуту{E60020}!",ZMName[ZMid]);SendClientMessageToAll(COLOR_ZOMBIE,string);
		SendClientMessageToAll(COLOR_ZOMBIE,"| Используйте {FFFFFF}/zombie{E60020}, если хотите участвовать.");
	}	

	if (ZMTimeToEnd > 0 && ZMTimer <= -1)
	{//Во время проведения зомби
		new zid, String[140], StringZTime[20], Float: zmx, Float: zmy, Float: zmz;
		if (ZMTimeToFirstZombie > 0) format(StringZTime, sizeof StringZTime, "~R~%d", ZMTimeToFirstZombie);
		for (new i = 0; i < 25; i++) 
		{//Цикл для участников зомби
			zid = ZMPlayersList[i];
			if (!IsPlayerConnected(zid) || ZMStarted[zid] == 0) continue;		
		
			if (LAFK[zid] >= 20)
			{
			    //SetPlayerWorldBounds(zid, 20000.0000, -20000.0000, 20000.0000, -20000.0000);
				JoinEvent[zid] = 0; InEvent[zid] = 0; ZMStarted[zid] = 0; LSpawnPlayer(zid);
				SendClientMessage(zid,COLOR_RED,"Вы были выброшены из зомби-выживания за AFK более 20 секунд");
				ZMIsPlayerIsZombie[zid] = 0; ZMIsPlayerIsTank[zid] = 0;
				GangZoneHideForPlayer(zid,ZZones[ZMid-1]);
				Player[zid][LeaveZM] = 1800;
				SendClientMessage(zid, COLOR_RED, "Вам было запрещено участвовать в зомби-выживании в течение часа из-за того, что вы бросили свою команду (AFK).");
				ShowClanZones(zid); // покажем клановые зоны
				continue;
			}
			
			//Таймер до появления первого зомби
			if (ZMTimeToFirstZombie > 0) GameTextForPlayer(zid, StringZTime, 1000, 6);
			
			//=== Чтобы люди не могли плавать
			new animlib[32], animname[32];
			GetAnimationName(GetPlayerAnimationIndex(zid),animlib,32,animname,32);
			if(!strcmp("SWIM", animlib) && ZMStarted[zid] > 0 && ZMIsPlayerIsZombie[zid] == 0) {SendClientMessage(zid, COLOR_RED, "Нельзя плавать на зомби-выживании!");LSpawnPlayer(zid);}//люди не могут плавать
			//=== Чтобы люди не могли плавать
			
			if (ZMIsPlayerIsZombie[zid] == 1 && ZMIsPlayerIsTank[zid] == 0)
			{//игрок зомби
				SetPlayerChatBubble(zid, "Зомби", 0xFF0000FF, 50.0, 1500);
				ResetPlayerWeapons(zid);
			}//игрок зомби
			else if (ZMIsPlayerIsTank[zid] == 1)
			{//игрок танк
				ResetPlayerWeapons(zid); 
				SetPlayerChatBubble(zid, "Прыгун", 0x9966CCFF, 50.0, 1500);
			}//игрок танк
			if (ZMIsPlayerIsZombie[zid] == 0 && ZMSurvivalTime[zid] != -1) ZMSurvivalTime[zid]++;//увеличивается счетчик выживания
			if ((ZMIsPlayerIsZombie[zid] != 0 || ZMTimeToEnd == 1) && ZMSurvivalTime[zid] != -1  && ZMStarted[zid] == 1)
			{//выдача ХР и денег за время, которое продержался человеком
				FarmedXP[zid] += ZMSurvivalTime[zid]*2; FarmedMoney[zid] += ZMSurvivalTime[zid]*30;
				new StringZ[140]; 
				format(StringZ, sizeof StringZ, "~Y~+~W~%d ~Y~XP   +~W~%d~Y~$", ZMSurvivalTime[zid]*2, ZMSurvivalTime[zid]*30);
				GameTextForPlayer(zid, StringZ, 3000, 6); 
				format(StringZ, sizeof StringZ, "Вы получили бонус в размере %d XP и %d$ за выживание на протяжении %d секунд.", ZMSurvivalTime[zid]*2, ZMSurvivalTime[zid]*30, ZMSurvivalTime[zid]);
				SendClientMessage(zid, COLOR_YELLOW, StringZ);
				ZMSurvivalTime[zid] = -1;
			}//выдача ХР и денег за время, которое продержался человеком
			GetPlayerPos(zid,zmx,zmy,zmz);//проверка на то, что вышел за территорию карты
			if ((zmx < ZombieZones[ZMid-1][0] || zmx > ZombieZones[ZMid-1][2] || zmy < ZombieZones[ZMid-1][1] || zmy > ZombieZones[ZMid-1][3])) {SendClientMessage(zid, COLOR_RED, "Вы вышли за пределы карты!"); LSpawnPlayer(zid);}
		}//Цикл для участников зомби		

		//вычисление необходимого кол-ва зомби в начале
		new ZMNeed;//Суть: из 3 человек 1 зомби.
		if (ZMPlayers < 4) ZMNeed = 1;
		else if (ZMPlayers < 8) ZMNeed = 2;
		else if (ZMPlayers < 12) ZMNeed = 3;
		else if (ZMPlayers < 15) ZMNeed = 4;
		else if (ZMPlayers < 18) ZMNeed = 5;
		else if (ZMPlayers < 21) ZMNeed = 6;
		else ZMNeed = 7;
		
		if (ZMZombies < ZMNeed && ZMTimeToFirstZombie <= 0 && ZMHumans > 0)
		{//нужны еще зомби
			new rand = random(25), ZombieAttempts = 0;
			while (ZMZombies < ZMNeed && ZombieAttempts < 25)
			{
				new FirstZombie = ZMPlayersList[rand]; ZombieAttempts++;
				if (!IsPlayerConnected(FirstZombie) || ZMStarted[FirstZombie] == 0 || ZMIsPlayerIsZombie[FirstZombie] > 0)
				{
					if (rand < 24) rand++; else rand = 0;
					continue;
				}
				ZMIsPlayerIsZombie[FirstZombie] = 1; ZMZombies += 1; SetPlayerHealth(FirstZombie, 0.0);
				format(String, sizeof String, "%s стал зомби!", PlayerName[FirstZombie]);	
				
				new cid;
				for (new i = 0; i < 25; i++) 
				{//Цикл для участников зомби
					cid = ZMPlayersList[i];
					if (!IsPlayerConnected(cid)) continue;
					if (ZMStarted[cid] == 1) SendClientMessage(cid, COLOR_ZOMBIE, String);
				}//Цикл для участников зомби
			}
		}//нужны еще зомби
		
		//вычисление необходимого кол-ва прыгунов
		new TankNeed;
		if (ZMPlayers > 16) TankNeed = 3;
		else if (ZMPlayers > 8) TankNeed = 2;
		else TankNeed = 1;
		
		while (ZMTankOn < TankNeed && ZMTimeToEnd <= 120 && ZMZombies > 0)
		{//нужен прыгун
			new rand = random(25), TankAttempts = 0;
			while (ZMTankOn < TankNeed && TankAttempts < 25)
			{
				new FirstZombie = ZMPlayersList[rand]; TankAttempts++;
				if (!IsPlayerConnected(FirstZombie) || ZMStarted[FirstZombie] == 0 || ZMIsPlayerIsZombie[FirstZombie] == 0  || ZMIsPlayerIsTank[FirstZombie] == 1)
				{
					if (rand < 24) rand++; else rand = 0;
					continue;
				}
				ZMIsPlayerIsTank[FirstZombie] = 1; ZMIsPlayerIsZombie[FirstZombie] = 2; ZMTankOn++;
				LSpawnPlayer(FirstZombie);
				format(String, sizeof String, "%s стал Прыгуном!!!", PlayerName[FirstZombie]);
				
				new cid;
				for (new i = 0; i < 25; i++) 
				{//Цикл для участников зомби
					cid = ZMPlayersList[i];
					if (!IsPlayerConnected(cid)) continue;
					if (ZMStarted[cid] == 1) SendClientMessage(cid,COLOR_YELLOW,String);
				}//Цикл для участников зомби	
				SendClientMessage(FirstZombie, COLOR_YELLOW, "Вы стали прыгуном! Теперь вы легко можете запрыгивать на крыши!");
			}
		}//нужен прыгун
		
		if (ZMHumans == 0)
		{//если зомби победили
			for (new i = 0; i < 25; i++) 
			{//Цикл для участников зомби
				zid = ZMPlayersList[i];
				if (!IsPlayerConnected(zid) || ZMStarted[zid] == 0) continue;
				//SetPlayerWorldBounds(zid, 20000.0000, -20000.0000, 20000.0000, -20000.0000);
				JoinEvent[zid] = 0; ZMStarted[zid] = 0; ZMIsPlayerIsZombie[zid] = 0; ZMIsPlayerIsTank[zid] = 0;
				FarmedXP[zid] += 200; FarmedMoney[zid] += 2500;
				SetPlayerVirtualWorld(zid,0);ResetPlayerWeapons(zid);LSpawnPlayer(zid);
				format(String, sizeof String, "SERVER: Вы получили %d XP и %d$ за участие в зомби-выживании.", FarmedXP[zid], FarmedMoney[zid]);
				SendClientMessage(zid, COLOR_YELLOW, String);
				//MarafonUpdate(zid, 1, 0, FarmedMoney[zid], 0);
				
				MarafonUpdate(zid, 0, 1);
				MarafonUpdate(zid, 2, 1);
				MarafonUpdate(zid, 5, FarmedMoney[zid]);
				
				LGiveXP(zid, FarmedXP[zid]); Player[zid][Cash] += FarmedMoney[zid];
				QuestUpdate(zid, 13, 1);//Обновление квеста Примите участие в 3 зомби-выживаниях
				QuestUpdate(zid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				ShowClanZones(zid); // покажем клановые зоны
				//MarafonUpdate(zid);
			}//Цикл для участников зомби
			GangZoneHideForAll(ZZones[ZMid-1]);
			ZMTimer = GetEventRestartTime(); ZMTimeToEnd = 0;
			while (PrevZM == ZMid) ZMid = random(MAX_ZOMBIE) + 1; //выбор новой карты для зомби
			PrevZM = ZMid;
			
			SendClientMessageToAll(COLOR_ZOMBIE,"Зомби-Выживание завершено: {FFFFFF}Зомби{E60020} победили.");
		}//если зомби победили
		if (ZMHumans > 0 && ZMTimeToEnd <= 1)
		{//если люди победили
			for (new i = 0; i < 25; i++) 
			{//Цикл для участников зомби
				zid = ZMPlayersList[i];
				if (!IsPlayerConnected(zid) || ZMStarted[zid] == 0) continue;
				
				if (ZMIsPlayerIsZombie[zid] > 0){FarmedXP[zid] += 230; FarmedMoney[zid] += 2500;}//Игрок зомби
				else
				{//игрок человек
					FarmedXP[zid] += 250; FarmedMoney[zid] += 7000;
					QuestUpdate(zid, 20, 1);//Обновление квеста Выживите в 2 зомби-выживаниях
					MarafonUpdate(zid, 2, 1);
				}//игрок человек
				format(String, sizeof String, "SERVER: Вы получили %d XP и %d$ за участие в зомби-выживании.", FarmedXP[zid], FarmedMoney[zid]);
				SendClientMessage(zid, COLOR_YELLOW, String);
				//SetPlayerWorldBounds(zid, 20000.0000, -20000.0000, 20000.0000, -20000.0000);
				JoinEvent[zid] = 0; ZMStarted[zid] = 0; ZMIsPlayerIsZombie[zid] = 0; ZMIsPlayerIsTank[zid] = 0;
				SetPlayerVirtualWorld(zid,0);ResetPlayerWeapons(zid);LSpawnPlayer(zid);
				//MarafonUpdate(zid, 1, 0, FarmedMoney[zid], 0);
				
				MarafonUpdate(zid, 0, 1);
				MarafonUpdate(zid, 5, FarmedMoney[zid]);
				
				LGiveXP(zid, FarmedXP[zid]); Player[zid][Cash] += FarmedMoney[zid];
				QuestUpdate(zid, 13, 1);//Обновление квеста Примите участие в 3 зомби-выживаниях
				QuestUpdate(zid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				ShowClanZones(zid); // покажем клановые зоны
				//MarafonUpdate(zid);
			}//Цикл для участников зомби
			GangZoneHideForAll(ZZones[ZMid-1]);
			ZMTimer = GetEventRestartTime(); ZMTimeToEnd = 0;
			while (PrevZM == ZMid) ZMid = random(MAX_ZOMBIE) + 1; //выбор новой карты для зомби
			PrevZM = ZMid;
			SendClientMessageToAll(COLOR_ZOMBIE,"Зомби-Выживание завершено: {FFFFFF}Люди{E60020} победили.");
		}//если люди победили
	}//Во время проведения зомби

	if (ZMTimer == 0)
	{//старт зомби
		new String[140];
		if (ZMPlayers < 2)
		{//Не началось зомби
			SendClientMessageToAll(COLOR_ZOMBIE, "Зомби-Выживание не началось, так как не хватило участников (Минимум: {FFFFFF}2{E60020})");
			ZMTimer = GetEventRestartTime(); ZMTimeToEnd = 0;
			while (PrevZM == ZMid) ZMid = random(MAX_ZOMBIE) + 1; //выбор новой карты для зомби
			PrevZM = ZMid;
			foreach(Player, zid)
			{//цикл
				if(JoinEvent[zid] == EVENT_ZOMBIE)
				{
					JoinEvent[zid] = 0; ZMStarted[zid] = 0;
					ZMIsPlayerIsZombie[zid] = 0; ZMIsPlayerIsTank[zid] = 0;
				}
			}//цикл
		}//Не началось зомби
		else
		{//Зомби стартовало
			format (String, sizeof(String),"Зомби-Выживание <<{FFFFFF}%s{E60020}>> началось. Игроков: {FFFFFF}%d",ZMName[ZMid], ZMPlayers);
			SendClientMessageToAll(COLOR_ZOMBIE,String);
			ZMTimer = -1; ZMTankOn = 0; ZMTimeToEnd = 270; ZMTimeToFirstZombie = 40;
			
			for (new i = 0; i < 25; i++) ZMPlayersList[i] = -1;//очищаем список игроков на зомби
			new i = 0; //Ниже заполняем список игроков на зомби
			foreach(Player, cid) if (JoinEvent[cid] == EVENT_ZOMBIE) {ZMPlayersList[i] = cid; i++;}
			
			new cid, RandWeap;
			for (i = 0; i < 25; i++) 
			{//Цикл для участников зомби
				cid = ZMPlayersList[i];
				if (!IsPlayerConnected(cid)) continue;
				//новое (версия 3.8
				GangZoneShowForPlayer(cid, ZZones[ZMid-1], 0xE6002099);
				if (OnFly[cid]) StopFly(cid);//Исправляет баг при старте зомби в режиме супермена
				new Float:rndFloat = float(random(20));
				SetPlayerPos(cid,ZMStartSpawn[ZMid-1][0]+rndFloat-10.0,ZMStartSpawn[ZMid-1][1]+rndFloat-10.0,ZMStartSpawn[ZMid-1][2]);
				SetPlayerVirtualWorld(cid, 663);
				SetPlayerInterior(cid,0);
				HideClanZones(cid); //скрываем зоны
				
				//SetPlayerWorldBounds(cid, ZombieZones[ZMid-1][2], ZombieZones[ZMid-1][0], ZombieZones[ZMid-1][3], ZombieZones[ZMid-1][1]);
				
				ZMStarted[cid] = 1; OnStartEvent[cid] = 5;			
				ZMKillsXP[cid] = 0; ZMSurvivalTime[cid] = 0;
				ZMIsPlayerIsZombie[cid] = 0; ZMIsPlayerIsTank[cid] = 0;
				SetPlayerHealth(cid, 100.0); SetPlayerArmour(cid, 100.0);
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_ZOMBIE]);
				AdminTPCantKill[cid] = 0; //Исправляет баг, когда игроку было запрещено стрелять после телепортации - разрешает при старте соревнования
				
				SendClientMessage(cid, COLOR_YELLOW, "КАК МОЖНО СКОРЕЕ ЗАБЕРИТЕСЬ НА КАКУЮ-НИБУДЬ КРЫШУ!");
				SendClientMessage(cid, COLOR_ZOMBIE, "После появления зомби вы не сможете бегать, прыгать и залазать на крыши!");
				
				//Выдача оружия
				ResetPlayerWeapons(cid);
				GiveWeapon(cid,24,70);//Всем обязательно дается Desert Eagle
				//Дальше идет выдача пистолет-пулемета либо дробововика
				RandWeap = random(6);
				switch(RandWeap)
				{
					case 0: GiveWeapon(cid,32,500); //Tec9
					case 1: GiveWeapon(cid,28,500); //Micro UZI
					case 2: GiveWeapon(cid,29,210); //MP5
					case 3: GiveWeapon(cid,25,60); //Shotgun
					case 4: GiveWeapon(cid,26,40); //Обрезы
					case 5: GiveWeapon(cid,27,42); //Combat Shotgun
				}
				//Дальше идет выдача автомата либо снайперской винтовки
				RandWeap = random(3);
				switch(RandWeap)
				{
					case 0: GiveWeapon(cid,30,210); //AK-47
					case 1: GiveWeapon(cid,31,200); //M4
					case 2: GiveWeapon(cid,34,8); //Снайперская винтовка
				}
			}//Цикл для участников зомби			
		}//Зомби стартовало
	}//старт зомби	
	
