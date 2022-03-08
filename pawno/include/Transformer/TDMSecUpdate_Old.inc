	if (FTimer > 0)
	{
		FTimer--; new String[60];
		format(String, sizeof String, "TDM:~w~ %d sec. Players: %d", FTimer, FPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_TDM], String);
	}
	if (FTimeToEnd >= 0) FTimeToEnd--;
	

	if (FTimer == 60)
	{
		new string[140];format(string,sizeof(string),"Командный десматч <<{FFFFFF}%s{00D40A}>> начнется через {FFFFFF}минуту{00D40A}!",FName[Fid]);SendClientMessageToAll(COLOR_TDM,string);
		SendClientMessageToAll(COLOR_TDM,"Используйте {FFFFFF}/tdm{00D40A} если хотите участвовать");
	}
    if (FTimeToEnd > 0 && FPlayers < 1)
	{
    		SendClientMessageToAll(COLOR_TDM,"Командный десматч завершен.");
			FTimer = GetEventRestartTime();
			FTimeToEnd = -1;
			while (PrevF == Fid) Fid = random(MAX_CTF) + 1; //выбор новой карты для ctf
			PrevF = Fid;
			ClearFlag();
	}
	if (FTimeToEnd > 0 && FTimer <= -1)
	{//Во время проведения стф
		new zid;
		new BiD, RiD;
		BiD = Fid*2;
		RiD = Fid*2+1;
		//new Float: fx, Float: fy, Float: fz;
		//if (ZMTimeToFirstZombie > 0) format(StringZTime, sizeof StringZTime, "~R~%d", ZMTimeToFirstZombie);
		for (new i = 0; i < 25; i++)
		{//Цикл для участников стф
			zid = FPlayersList[i];
			if (!IsPlayerConnected(zid) || FStarted[zid] == 0) continue;
			
            if(LooseTimer[zid] > 0) LooseTimer[zid]--;
            
			if (LAFK[zid] >= 20)
			{
			    LostFlag(zid);
				JoinEvent[zid] = 0; InEvent[zid] = 0; FStarted[zid] = 0; LSpawnPlayer(zid);
				SetPlayerVirtualWorld(zid,0);
				SendClientMessage(zid,COLOR_RED,"Вы были выброшены из битвы за AFK более 20 секунд");
				//ZMIsPlayerIsZombie[zid] = 0; ZMIsPlayerIsTank[zid] = 0;
				//GangZoneHideForPlayer(zid,ZMZone1); GangZoneHideForPlayer(zid,ZMZone2); GangZoneHideForPlayer(zid,ZMZone3); GangZoneHideForPlayer(zid,ZMZone4); GangZoneHideForPlayer(zid,ZMZone5);
				//GangZoneHideForPlayer(zid,ZMZone6); GangZoneHideForPlayer(zid,ZMZone7); GangZoneHideForPlayer(zid,ZMZone8); GangZoneHideForPlayer(zid,ZMZone9); GangZoneHideForPlayer(zid,ZMZone10);
				//GangZoneHideForPlayer(zid,ZMZone11); GangZoneHideForPlayer(zid,ZMZone12); GangZoneHideForPlayer(zid,ZMZone13); GangZoneHideForPlayer(zid,ZMZone14); GangZoneHideForPlayer(zid,ZMZone15);
				continue;
			}

			if (FPlayerTeam[zid] == 1)
			{
				SetPlayerChatBubble(zid, "Красная команда", 0xFF0000FF, 50.0, 1500);
			}
			else if (FPlayerTeam[zid] == 0)
			{
				SetPlayerChatBubble(zid, "Синяя команда", 0x0000FFFF, 50.0, 1500);
			}
			
			if(MustLostFlag[zid] == 1)
			{
			    LooseTimer[zid] = 5;
			    MustLostFlag[zid] = 0;
				LostFlag(zid);
			}
			//GetPlayerPos(zid,fx,fy,fz);//проверка на то, что вышел за территорию карты
			//if (fz < 44.0 && Fid == 2) {SendClientMessage(zid, COLOR_RED, "Вы вышли за пределы карты!"); LSpawnPlayer(zid);}
				//игрок без флага
            	if(PlayerWithFlag[zid] == 0)
				{
					if(FPlayerTeam[zid] == 0 && RFState == 0 && LooseTimer[zid] == 0 && IsPlayerInRangeOfPoint(zid, 3, FTypeInf[RiD][fPosX],FTypeInf[RiD][fPosY],FTypeInf[RiD][fPosZ]))
					{
						PlayerWithFlag[zid] = 1;
      					RFState = 1;
      					ResetWeapons(zid);
      					GiveWeapon(zid,8,1);
      					SetPlayerAttachedObject(zid, 5, 19306, 1, 0.131, -0.102, 0.0 ,4.3 ,85.0,-0.3,1.174,1.0,1.083);
      					DestroyDynamicObject(RObj);
						new String[140];
						new cid;
      					for (new id = 0; id < 25; id++)
						{
							cid = FPlayersList[id];
							if (!IsPlayerConnected(cid) || FStarted[cid] == 0) continue;
							if (FPlayerTeam[cid] == 0)
							{
               					format(String, sizeof String, "Игрок %s взял вражеский флаг!", PlayerName[zid]);
               					SendClientMessage(cid, COLOR_BLUE, String);
               					PlayerPlaySound(cid,30800,0.0,0.0,0.0);
      						}
							if (FPlayerTeam[cid] == 1)
							{
								format(String, sizeof String, "Игрок %s взял наш флаг!", PlayerName[zid]);
  								SendClientMessage(cid, COLOR_RED, String);
  								PlayerPlaySound(cid,31206,0.0,0.0,0.0);
							}
						}
					}
					if(FPlayerTeam[zid] == 1 && BFState == 0 &&  LooseTimer[zid] == 0 && IsPlayerInRangeOfPoint(zid, 3, FTypeInf[BiD][fPosX],FTypeInf[BiD][fPosY],FTypeInf[BiD][fPosZ]))
					{
					    PlayerWithFlag[zid] = 1;
      					BFState = 1;
      					ResetWeapons(zid);
      					GiveWeapon(zid,8,1);
      					SetPlayerAttachedObject(zid, 5, 19307, 1, 0.131, -0.102, 0.0 ,4.3 ,85.0,-0.3,1.174,1.0,1.083);
      					DestroyDynamicObject(BObj);
      					new String[140];
      					new cid;
      					for (new id = 0; id < 25; id++)
						{
							cid = FPlayersList[id];
							if (!IsPlayerConnected(cid) || FStarted[cid] == 0) continue;
							if (FPlayerTeam[cid] == 0)
							{
               					format(String, sizeof String, "Игрок %s взял наш флаг!", PlayerName[zid]);
               					SendClientMessage(cid, COLOR_BLUE, String);
               					PlayerPlaySound(cid,31206,0.0,0.0,0.0);
      						}
							if (FPlayerTeam[cid] == 1)
							{
								format(String, sizeof String, "Игрок %s взял вражеский флаг!", PlayerName[zid]);
  								SendClientMessage(cid, COLOR_RED, String);
  								PlayerPlaySound(cid,30800,0.0,0.0,0.0);
							}
						}
					}
				}//игрок без флага
				
				else if(PlayerWithFlag[zid] == 1) //игрок с флагом
	    		{
					if(FPlayerTeam[zid] == 0 && BFState == 0 && IsPlayerInRangeOfPoint(zid, 3, FTypeInf[BiD][fPosX],FTypeInf[BiD][fPosY],FTypeInf[BiD][fPosZ]))
					{
						PlayerWithFlag[zid] = 0;
      					RFState = 0;
      					BFlags++;
      					RemovePlayerAttachedObject(zid, 5);
      					GiveRandomWeap(zid);
     					GiveWeapon(zid,35,5);
      					new newtext[3];
    					format(newtext, sizeof(newtext), "%d", BFlags);
   						TextDrawSetString(TDBlue, newtext);
   						FarmedXP[zid] += 100; FarmedMoney[zid] += 5000;
   						GameTextForPlayer(zid, "+100 XP +5000$", 2000, 6);
   						QuestUpdate(zid, 31, 1);
                   		RObj = CreateDynamicObject(19306, FTypeInf[RiD][fPosX],FTypeInf[RiD][fPosY],FTypeInf[RiD][fPosZ],   0.00000, 0.00000, FTypeInf[RiD][fPosA], TDM_WORLD, -1, -1, 200.0);
                   		new String[140];
                   		new cid;
						for (new id = 0; id < 25; id++)
						{
							cid = FPlayersList[id];
							if (!IsPlayerConnected(cid) || FStarted[cid] == 0) continue;
							if (FPlayerTeam[cid] == 0)
							{
 								format(String, sizeof String, "Игрок %s доставил вражеский флаг!", PlayerName[zid]);
 								SendClientMessage(cid, COLOR_BLUE, String);
               					PlayerPlaySound(cid,31205,0.0,0.0,0.0);
      						}
							if (FPlayerTeam[cid] == 1)
							{
								format(String, sizeof String, "Игрок %s доставил наш флаг!", PlayerName[zid]);
								SendClientMessage(cid, COLOR_RED, String);
  								PlayerPlaySound(cid,30803,0.0,0.0,0.0);
							}
							TextDrawHideForPlayer(cid, TDRed);
                    		TextDrawBoxColor(TDRed, -16776961);
                    		TextDrawShowForPlayer(cid, TDRed);
						}
					}
					if(FPlayerTeam[zid] == 1 && RFState == 0 && IsPlayerInRangeOfPoint(zid, 3, FTypeInf[RiD][fPosX],FTypeInf[RiD][fPosY],FTypeInf[RiD][fPosZ]))
					{
					    PlayerWithFlag[zid] = 0;
      					BFState = 0;
      					RFlags++;
     					RemovePlayerAttachedObject(zid, 5);
     					GiveRandomWeap(zid);
     					GiveWeapon(zid,35,5);
      					new newtext[3];
    					format(newtext, sizeof(newtext), "%d", RFlags);
   						TextDrawSetString(TDRed, newtext);
   						FarmedXP[zid] += 100; FarmedMoney[zid] += 5000;
   						GameTextForPlayer(zid, "+100 XP +5000$", 2000, 6);
   						QuestUpdate(zid, 31, 1);
                   		BObj = CreateDynamicObject(19307, FTypeInf[BiD][fPosX],FTypeInf[BiD][fPosY],FTypeInf[BiD][fPosZ],   0.00000, 0.00000, FTypeInf[BiD][fPosA], TDM_WORLD, -1, -1, 200.0);
						new String[140];
						new cid;
						for (new id = 0; id < 25; id++)
						{
							cid = FPlayersList[id];
							if (!IsPlayerConnected(cid) || FStarted[cid] == 0) continue;
							if (FPlayerTeam[cid] == 0)
							{
 								format(String, sizeof String, "Игрок %s доставил наш флаг!", PlayerName[zid]);
 								SendClientMessage(cid, COLOR_BLUE, String);
               					PlayerPlaySound(cid,30803,0.0,0.0,0.0);
      						}
							if (FPlayerTeam[cid] == 1)
							{
								format(String, sizeof String, "Игрок %s доставил вражеский флаг!", PlayerName[zid]);
								SendClientMessage(cid, COLOR_RED, String);
  								PlayerPlaySound(cid,31205,0.0,0.0,0.0);
							}
							TextDrawHideForPlayer(cid, TDBlue);
                    		TextDrawBoxColor(TDBlue, 65535);
                    		TextDrawShowForPlayer(cid, TDBlue);
						}
					}
	    		}

				//мигание тд
				if(BFState !=0)
			    {
			    	if(BFlash == 0)
			    	{
			    	    TextDrawHideForPlayer(zid, TDBlue);
			        	TextDrawBoxColor(TDBlue, -1);
			        	TextDrawShowForPlayer(zid, TDBlue);
			        	BFlash = 1;
			    	}
					else if (BFlash == 1)
					{
						TextDrawHideForPlayer(zid, TDBlue);
                    	TextDrawBoxColor(TDBlue, 65535);
                    	TextDrawShowForPlayer(zid, TDBlue);
                    	BFlash = 0;
			    	}
	    		}
	    		if(RFState !=0)
			    {
                	if(RFlash == 0)
			    	{
			    	    TextDrawHideForPlayer(zid, TDRed);
			        	TextDrawBoxColor(TDRed, -1);
			        	TextDrawShowForPlayer(zid, TDRed);
			        	RFlash = 1;
			    	}
					else if (RFlash == 1)
					{
						TextDrawHideForPlayer(zid, TDRed);
                    	TextDrawBoxColor(TDRed, -16776961);
                    	TextDrawShowForPlayer(zid, TDRed);
                    	RFlash = 0;
			    	}
			    }
	    		//мигание тд
				//new string[140];
				//format(string,sizeof(string),"WithFlag: %d, Team: %d, R: %d, B: %d, Started: %d",PlayerWithFlag[zid],FPlayerTeam[zid],RFState, BFState,FStarted[zid]);
				//SendClientMessageToAll(COLOR_TDM,string);
			}//Цикл для участников
    if (FTimeToEnd <= 1)
		{
			new String[140];
			new Stringw[140];
			new RBonus;
			new BBonus;
   			new MBB;
   			new MRB;
			if (BFlags == RFlags)
			{
				format(Stringw, sizeof String, "Битва за флаг завершена: Ничья! Счет: {0000ff}%d {00ff00}| {ff0000}%d", BFlags, RFlags);
				RBonus = 300;
				MRB = 5000;
				BBonus = 300;
				MBB = 5000;
			}
			if (BFlags > RFlags)
			{
				format(Stringw, sizeof String, "Битва за флаг завершена: Синие победили со счетом: {0000ff}%d {00ff00}| {ff0000}%d", BFlags, RFlags);
				BBonus = 500;
				MRB = 2000;
				RBonus = 200;
				MBB = 8000;
			}
			if (RFlags > BFlags)
			{
				format(Stringw, sizeof String, "Битва за флаг завершена: Красные победили со счетом: {ff0000}%d {00ff00}| {0000ff}%d", RFlags, BFlags);
				RBonus = 500;
				MRB = 8000;
				BBonus = 200;
				MBB = 2000;
			}
			for (new i = 0; i < 25; i++)
			{//Цикл для участников
				zid = FPlayersList[i];
				if (!IsPlayerConnected(zid) || FStarted[zid] == 0) continue;
				if(FPlayerTeam[zid] == 0)
				{
					FarmedXP[zid] += BBonus; FarmedMoney[zid] += MBB;
				}
				else if(FPlayerTeam[zid] == 1)
				{
					FarmedXP[zid] += RBonus; FarmedMoney[zid] += MRB;
				}
				JoinEvent[zid] = 0;
				FStarted[zid] = 0;
				PlayerWithFlag[zid] = 0;
				SetPlayerVirtualWorld(zid,0);
				ResetPlayerWeapons(zid);
				LSpawnPlayer(zid);
				FPlayerTeam[zid] = -1;
                format(String, sizeof String, "SERVER: Вы получили %d XP и %d$ за участие в битве.", FarmedXP[zid], FarmedMoney[zid]);
                //MarafonUpdate(zid, 1, 0, FarmedMoney[zid], 0);
				MarafonUpdate(zid, 0, 1);
				MarafonUpdate(zid, 5, FarmedMoney[zid]);
                LGiveXP(zid, FarmedXP[zid]);
                Player[zid][Cash] += FarmedMoney[zid];
				SendClientMessage(zid, COLOR_YELLOW, String);
				QuestUpdate(zid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				
				//MarafonUpdate(zid);
			}//Цикл для участников
			SendClientMessageToAll(COLOR_TDM,Stringw);
			FTimer = GetEventRestartTime();
			FTimeToEnd = -1;
			ClearFlag();
		}
     //------------------------------------------------------------------------------------------------------------------------
		if (RFlags == 5)
		{//если red победили
		    new String[140];
			for (new i = 0; i < 25; i++)
			{//Цикл для участников
				zid = FPlayersList[i];
				if (!IsPlayerConnected(zid) || FStarted[zid] == 0) continue;
				JoinEvent[zid] = 0;
				FStarted[zid] = 0;
				PlayerWithFlag[zid] = 0;
				if(FPlayerTeam[zid] == 1)
				{
					FarmedXP[zid] += 400; FarmedMoney[zid] += 5000;
					SendClientMessage(zid, COLOR_YELLOW, "Ваша команда победила!");
				}
				else if(FPlayerTeam[zid] == 0)
				{
					FarmedXP[zid] += 100; FarmedMoney[zid] += 1000;
					SendClientMessage(zid, COLOR_WHITE, "Ваша команда проиграла!");
				}
				FPlayerTeam[zid] = -1;
				SetPlayerVirtualWorld(zid,0);
				ResetPlayerWeapons(zid);
				LSpawnPlayer(zid);
				
				format(String, sizeof String, "SERVER: Вы получили %d XP и %d$ за участие в битве.", FarmedXP[zid], FarmedMoney[zid]);
				SendClientMessage(zid, COLOR_YELLOW, String);
				//MarafonUpdate(zid, 1, 0, FarmedMoney[zid], 0);
				MarafonUpdate(zid, 0, 1);
				MarafonUpdate(zid, 5, FarmedMoney[zid]);
				LGiveXP(zid, FarmedXP[zid]);
				Player[zid][Cash] += FarmedMoney[zid];
				QuestUpdate(zid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				//MarafonUpdate(zid);
			}//Цикл для участников
			FTimer = GetEventRestartTime();
			FTimeToEnd = -1;
			while (PrevF == Fid) Fid = random(MAX_CTF) + 1; //выбор новой карты для ctf
			PrevF = Fid;
			format(String, sizeof String, "Битва за флаг завершена: Красные победили со счетом: {ff0000}%d {ffffff}| {0000ff}%d", RFlags, BFlags);
			SendClientMessageToAll(COLOR_TDM,String);
			ClearFlag();
		}//если red победили
		//------------------------------------------------------------------------------------------------------------------------
		if (BFlags == 5)
		{//если blue победили
		    new String[140];
			for (new i = 0; i < 25; i++)
			{//Цикл для участников
				zid = FPlayersList[i];
				if (!IsPlayerConnected(zid) || FStarted[zid] == 0) continue;
				JoinEvent[zid] = 0;
				FStarted[zid] = 0;
				PlayerWithFlag[zid] = 0;
				if(FPlayerTeam[zid] == 0)
				{
					FarmedXP[zid] += 500; FarmedMoney[zid] += 5000;
					SendClientMessage(zid, COLOR_YELLOW, "Ваша команда победила!");
				}
				else if(FPlayerTeam[zid] == 1)
				{
					FarmedXP[zid] += 200; FarmedMoney[zid] += 1000;
					SendClientMessage(zid, COLOR_WHITE, "Ваша команда проиграла!");
				}
				FPlayerTeam[zid] = -1;
				SetPlayerVirtualWorld(zid,0);
				ResetPlayerWeapons(zid);
				LSpawnPlayer(zid);
				format(String, sizeof String, "SERVER: Вы получили %d XP и %d$ за участие в битве.", FarmedXP[zid], FarmedMoney[zid]);
				SendClientMessage(zid, COLOR_YELLOW, String);
				//MarafonUpdate(zid, 1, 0, FarmedMoney[zid], 0);
				MarafonUpdate(zid, 0, 1);
				MarafonUpdate(zid, 5, FarmedMoney[zid]);
				
				LGiveXP(zid, FarmedXP[zid]);
				Player[zid][Cash] += FarmedMoney[zid];
				QuestUpdate(zid, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				//MarafonUpdate(zid);
			}//Цикл для участников
			FTimer = GetEventRestartTime();
			FTimeToEnd = -1;
			while (PrevF == Fid) Fid = random(MAX_CTF) + 1; //выбор новой карты для ctf
			PrevF = Fid;
			format(String, sizeof String, "Битва за флаг завершена: Синие победили со счетом: {0000ff}%d {ffffff}| {ff0000}%d", BFlags, RFlags);
			SendClientMessageToAll(COLOR_TDM,String);
			ClearFlag();
		}//если blue победили
		
		
		//------------------------------------------------------------------------------------------------------------------------
	
	}//Во время проведения стф

	if (FTimer == 0)
	{//старт
		new String[140];
		new BiD, RiD;
		BiD = Fid*2;
		RiD = Fid*2+1;
		if (FPlayers < 2)
		{//Не началось
			SendClientMessageToAll(COLOR_TDM, "Битва за флаг не началась, так как не хватило участников (Минимум: {FFFFFF}2{00D40A})");
			FTimer = GetEventRestartTime();
			FTimeToEnd = -1;
			while (PrevF == Fid) Fid = random(MAX_CTF) + 1; //выбор новой карты для ctf
			PrevF = Fid;
			foreach(Player, zid)
			{//цикл
				if(JoinEvent[zid] == EVENT_TDM)
				{
					JoinEvent[zid] = 0; FStarted[zid] = 0;
				}
			}//цикл
		}//Не началось
		else
		{//стартовало
			format (String, sizeof(String),"Битва за флаг <<{FFFFFF}%s{00D40A}>> началась. Игроков: {FFFFFF}%d",FName[Fid], FPlayers);
			SendClientMessageToAll(COLOR_TDM,String);
			FTimer = -1;
			FTimeToEnd = 280;
			BFlags=0;
			RFlags=0;
			for (new i = 0; i < 25; i++)
			{
				FPlayersList[i] = -1;//очищаем список игроков
				//PlayerWithFlag[i] = 0;
			}
			new i = 0; //Ниже заполняем список игроков
			foreach(Player, cid)
			{
				if (JoinEvent[cid] == EVENT_TDM)
				{

					FPlayersList[i] = cid;
					i++;
				}
			}

			RObj = CreateDynamicObject(19306, FTypeInf[RiD][fPosX],FTypeInf[RiD][fPosY],FTypeInf[RiD][fPosZ],   0.00000, 0.00000, FTypeInf[RiD][fPosA], TDM_WORLD, -1, -1, 300.0);
            BObj = CreateDynamicObject(19307, FTypeInf[BiD][fPosX],FTypeInf[BiD][fPosY],FTypeInf[BiD][fPosZ],   0.00000, 0.00000, FTypeInf[BiD][fPosA], TDM_WORLD, -1, -1, 300.0);

			new SpawnRed = 0, SpawnBlue = 0;
			new cid, RandWeap;
			for (i = 0; i < 25; i++)
			{//Цикл для участников
				cid = FPlayersList[i];
				if (!IsPlayerConnected(cid)) continue;
				//blue - 0
				//red - 1
				if(FBlue > FRed)
	  			{
	  			    FPlayerTeam[cid] = 1;
	  				FRed++;
	  			}
	  			else if(FBlue < FRed)
	  			{
	  				FPlayerTeam[cid] = 0;
	  				FBlue++;
	  			}
 				else if(FBlue == FRed)
	  			{
	  				new rnd = random(2);
	  				FPlayerTeam[cid] = rnd;
	  				if(rnd == 0) FBlue++;
	  				else if(rnd == 1) FRed++;
	  			}
	  			
	  			if (OnFly[cid]) StopFly(cid);//Исправляет баг при старте в режиме супермена
	  			
                switch (Fid)
				{//switch
					case 1:
					{
		 				if(FPlayerTeam[cid] == 1)
		 				{
		 				    SetPlayerColor(cid, 0xFF0000FF);
							SetPlayerPos(cid, F1SPAWNRED[SpawnRed][0], F1SPAWNRED[SpawnRed][1],F1SPAWNRED[SpawnRed][2]);
							SetPlayerFacingAngle(cid, F1SPAWNRED[SpawnRed][3]);
							SpawnRed++;
						}
						else if(FPlayerTeam[cid] == 0)
						{
						    SetPlayerColor(cid, 0x0000FFFF);
							SetPlayerPos(cid, F1SPAWNBLUE[SpawnBlue][0], F1SPAWNBLUE[SpawnBlue][1],F1SPAWNBLUE[SpawnBlue][2]);
							SetPlayerFacingAngle(cid, F1SPAWNBLUE[SpawnBlue][3]);
							SpawnBlue++;
						}
					}
					case 2:
					{
		 				if(FPlayerTeam[cid] == 1)
		 				{
		 				    SetPlayerColor(cid, 0xFF0000FF);
							SetPlayerPos(cid, F2SPAWNRED[SpawnRed][0], F2SPAWNRED[SpawnRed][1],F2SPAWNRED[SpawnRed][2]);
							SetPlayerFacingAngle(cid, F2SPAWNRED[SpawnRed][3]);
							SpawnRed++;
						}
						else if(FPlayerTeam[cid] == 0)
						{
						    SetPlayerColor(cid, 0x0000FFFF);
							SetPlayerPos(cid, F2SPAWNBLUE[SpawnBlue][0], F2SPAWNBLUE[SpawnBlue][1],F2SPAWNBLUE[SpawnBlue][2]);
							SetPlayerFacingAngle(cid, F2SPAWNBLUE[SpawnBlue][3]);
							SpawnBlue++;
						}
					}
					case 3:
					{
		 				if(FPlayerTeam[cid] == 1)
		 				{
		 				    SetPlayerColor(cid, 0xFF0000FF);
							SetPlayerPos(cid, F3SPAWNRED[SpawnRed][0], F3SPAWNRED[SpawnRed][1],F3SPAWNRED[SpawnRed][2]);
							SetPlayerFacingAngle(cid, F3SPAWNRED[SpawnRed][3]);
							SpawnRed++;
						}
						else if(FPlayerTeam[cid] == 0)
						{
						    SetPlayerColor(cid, 0x0000FFFF);
							SetPlayerPos(cid, F3SPAWNBLUE[SpawnBlue][0], F3SPAWNBLUE[SpawnBlue][1],F3SPAWNBLUE[SpawnBlue][2]);
							SetPlayerFacingAngle(cid, F3SPAWNBLUE[SpawnBlue][3]);
							SpawnBlue++;
						}
					}
					case 4:
					{
		 				if(FPlayerTeam[cid] == 1)
		 				{
		 				    SetPlayerColor(cid, 0xFF0000FF);
							SetPlayerPos(cid, F4SPAWNRED[SpawnRed][0], F4SPAWNRED[SpawnRed][1],F4SPAWNRED[SpawnRed][2]);
							SetPlayerFacingAngle(cid, F4SPAWNRED[SpawnRed][3]);
							SpawnRed++;
						}
						else if(FPlayerTeam[cid] == 0)
						{
						    SetPlayerColor(cid, 0x0000FFFF);
							SetPlayerPos(cid, F4SPAWNBLUE[SpawnBlue][0], F4SPAWNBLUE[SpawnBlue][1],F4SPAWNBLUE[SpawnBlue][2]);
							SetPlayerFacingAngle(cid, F4SPAWNBLUE[SpawnBlue][3]);
							SpawnBlue++;
						}
					}
					case 5:
					{
		 				if(FPlayerTeam[cid] == 1)
		 				{
		 				    SetPlayerColor(cid, 0xFF0000FF);
							SetPlayerPos(cid, F5SPAWNRED[SpawnRed][0], F5SPAWNRED[SpawnRed][1],F5SPAWNRED[SpawnRed][2]);
							SetPlayerFacingAngle(cid, F5SPAWNRED[SpawnRed][3]);
							SpawnRed++;
						}
						else if(FPlayerTeam[cid] == 0)
						{
						    SetPlayerColor(cid, 0x0000FFFF);
							SetPlayerPos(cid, F5SPAWNBLUE[SpawnBlue][0], F5SPAWNBLUE[SpawnBlue][1],F5SPAWNBLUE[SpawnBlue][2]);
							SetPlayerFacingAngle(cid, F5SPAWNBLUE[SpawnBlue][3]);
							SpawnBlue++;
						}
					}
				}
				//PlayAudioStreamForPlayer(cid, "http://f-bit.ru/uploads/687702.mp3");
				MustLostFlag[cid] = 0;
				PlayerWithFlag[cid] = 0;
				LooseTimer[cid] = 0;
				
				SetPlayerVirtualWorld(cid, TDM_WORLD);
				SetPlayerInterior(cid,0);
				FStarted[cid] = 1;
				OnStartEvent[cid] = 5;
				//ZMKillsXP[cid] = 0;
				SetPlayerHealth(cid, 100.0);
				SetPlayerArmour(cid, 100.0);
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_TDM]);
				TextDrawShowForPlayer(cid, TDRed);
				TextDrawShowForPlayer(cid, TDBlue);
				AdminTPCantKill[cid] = 0; //Исправляет баг, когда игроку было запрещено стрелять после телепортации - разрешает при старте соревнования

				if(FPlayerTeam[cid] == 0)
				{
					SendClientMessage(cid, COLOR_BLUE, "Вы играете за синюю команду!");
					SendClientMessage(cid, 0x0000FFFF, "Доставьте {ff0000}красный{0000ff} флаг на свою базу!");
				}
				else if(FPlayerTeam[cid] == 1)
				{
					SendClientMessage(cid, COLOR_RED, "Вы играете за красную команду!");
					SendClientMessage(cid, 0xFF0000FF, "Доставьте {0000ff}синий{ff0000} флаг на свою базу!");
				}
                SendClientMessage(cid, 0xAFAFAFFF, "Написать команде:{ff0000} /t [text]");
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
			}//Цикл для участников
		}//стартовало
	}//старт

