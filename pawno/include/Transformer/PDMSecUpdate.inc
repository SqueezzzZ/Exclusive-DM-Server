	if (PDMTimer > 0)
	{
		PDMTimer--; new String[60];
		format(String, sizeof String, "~g~POINT DM:~w~ %d sec. Players: %d", PDMTimer, PDMPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_PDM], String);
	}
/*	if (PDMTimeToEnd >= 0)
	{
		PDMTimeToEnd--; new String[110];
		format(String, sizeof String, "PDM:~w~ Time to end %d sec.         WHITE %d ~u~ ~p~%d BLACK", TDMTimeToEnd, TDMGroveKills, TDMBallasKills);
		TextDrawSetString(TextDrawEvent[EVENT_TDM], String);		
	}*/
	if (PDMTimer <= 0 && PDMTimeToEnd < 0)
	{//Рестарт тдм (он либо закончился, либо не стартовал)
		PDMTimer = GetEventRestartTime();
		while (PrevPDM == PDMid) PDMid = random(MAX_PDM) + 1; //выбор новой карты для тдм
		PrevPDM = PDMid;
	}//Рестарт тдм (он либо закончился, либо не стартовал)
	if (PDMTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| Захват точки [{FFFFFF}%s{58FA82}] начнется через {FFFFFF}минуту{58FA82}!", PDMName[PDMid]); SendClientMessageToAll(COLOR_PDM, string);
		SendClientMessageToAll(COLOR_PDM, "| Используйте {FFFFFF}/point{58FA82}, если хотите участвовать.");
	}
	//Баг от слива XP в последние секунды соревнования
//	if (PDMTimeToEnd == 2) foreach(Player, cid) if (InEvent[cid] == EVENT_TDM) EndEventFreeze(cid);

    if (PDMTimeToEnd >= 0)
	{
		PDMTimeToEnd--; new String[110];
		format(String, sizeof String, "PDM:~w~ Time to end %d sec.", PDMTimeToEnd);
		TextDrawSetString(TextDrawEvent[EVENT_PDM], String);
		
		if(BlueOnPoint > 0 && RedOnPoint == 0)
		{
			PDMBluePnt++;
			if(ObjStatus != 1) {ObjStatus = 1; DestroyDynamicObject(PDMObject);PDMObject = CreateDynamicObject(19947, PDMPoint[PDMid][0], PDMPoint[PDMid][1],PDMPoint[PDMid][2], 0.00000, 0.00000, 0.00000, PDM_WORLD, -1, -1, 500.0);}
			foreach(Player, pdid)
			{
			    if(InEvent[pdid] == EVENT_PDM && PDMTeam[pdid] == 1 && GetPVarInt(pdid,"PDMop") == 1)
			    {
			        if(PDMPlayers < 10) {GameTextForPlayer(pdid, "~b~+2 XP", 1000, 4);FarmedXP[pdid] += 2;}
			        else {GameTextForPlayer(pdid, "~b~+3 XP", 1000, 4);FarmedXP[pdid] += 3;}
			    }
			}
		}
		else if(RedOnPoint > 0 && BlueOnPoint == 0)
		{
		    PDMRedPnt++;
		    if(ObjStatus != 2) {ObjStatus = 2; DestroyDynamicObject(PDMObject);PDMObject = CreateDynamicObject(19945, PDMPoint[PDMid][0], PDMPoint[PDMid][1],PDMPoint[PDMid][2], 0.00000, 0.00000, 0.00000, PDM_WORLD, -1, -1, 500.0);}
		    foreach(Player, pdid)
			{
			    if(InEvent[pdid] == EVENT_PDM && PDMTeam[pdid] == 2 && GetPVarInt(pdid,"PDMop") == 1)
			    {
			        if(PDMPlayers < 10) {GameTextForPlayer(pdid, "~r~+2 XP", 1000, 4);FarmedXP[pdid] += 2;}
			        else {GameTextForPlayer(pdid, "~r~+3 XP", 1000, 4);FarmedXP[pdid] += 3;}
			    }
			}
		}
		else
		{
		    if(ObjStatus != 0) {ObjStatus = 0; DestroyDynamicObject(PDMObject);PDMObject = CreateDynamicObject(19946, PDMPoint[PDMid][0], PDMPoint[PDMid][1],PDMPoint[PDMid][2], 0.00000, 0.00000, 0.00000, PDM_WORLD, -1, -1, 500.0);}
		}
	}

	if (PDMTimer == 1)
	{//старт тдм
		new String[140];
		if (PDMPlayers < 1) //тута < 2
		{//мало участников
			format(String,sizeof(String),"Захват точки <<{FFFFFF}%s{58FA82}>> не начался, так как не хватило участников (Минимум:{FFFFFF} 2{58FA82})", PDMName[PDMid]);
			SendClientMessageToAll(COLOR_PDM, String);
			foreach(Player, cid) if (JoinEvent[cid] == EVENT_PDM) {JoinEvent[cid] = 0; TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_PDM]);} //исправление ошибки, когда игрок в неактивном соревновании и не может из него выйти
		}//мало участников
		else
		{//достаточно участников
			format(String,sizeof(String),"Захват точки <<{FFFFFF}%s{58FA82}>> начался. Игроков: {FFFFFF}%d", PDMName[PDMid], PDMPlayers);
			SendClientMessageToAll(COLOR_PDM,String);
			PDMTimeToEnd = 180; PDMBluePnt = 0; PDMRedPnt = 0;
			new nextTeam = 1;
			PDMBlue = 0; PDMRed = 0;
			for (new i = 0; i < MAX_PLAYERS; i++)
			{//цикл (здесь обязательно использовать обычный for, а не foreach)
				PDMKills[i] = 0; PDMTeam[i] = 0;
				if(JoinEvent[i] == EVENT_PDM)
				{
					if (LastPlayerTuneStatus[i] > 0) 
					{
						SendClientMessage(i, COLOR_RED, "Не удалось переместить вас на старт соревнования, так как вы находились в автомастерской во время старта!"); 
						JoinEvent[i] = 0;TextDrawHideForPlayer(i, TextDrawEvent[EVENT_PDM]);  continue;
					}
					if (OnFly[i]) StopFly(i);//Исправляет баг при старте тдм в режиме супермена
					InEvent[i] = EVENT_PDM; SetPlayerArmour(i, 0);
					OnStartEvent[i] = 5; ClearAnimations(i);
					//PDMStarted[i] = 1;
					AdminTPCantKill[i] = 0; //Исправляет баг, когда игроку было запрещено стрелять после телепортации - разрешает при старте соревнования
					if (nextTeam == 1) {PDMTeam[i] = 1; nextTeam = 2; PDMBlue++;} //grove
					else {PDMTeam[i] = 2; nextTeam = 1; PDMRed++;} //ballas
					LSpawnPlayer(i); //UpdateColor(i);
					HideClanZones(i); //скрываем зоны
				}
			}//цикл (здесь обязательно использовать обычный for, а не foreach)
			DestroyDynamicArea(PDMArea);
			PDMArea = CreateDynamicCircle(PDMPoint[PDMid][0], PDMPoint[PDMid][1], 20.0, PDM_WORLD);
			ObjStatus = 0; DestroyDynamicObject(PDMObject);
		}//достаточно участников
	}//старт тдм	

	if (PDMTimeToEnd == 0)
	{//конец тдм
		new BonusXP, BonusCash, String[140];
		format(String, sizeof String, "Захват точки <<{FFFFFF}%s{58FA82}>> закончился", PDMName[PDMid]); SendClientMessageToAll(COLOR_PDM, String);
		if (PDMBluePnt > PDMRedPnt)
		{
			format(String, sizeof String, "Игроки команды {5882FA}Синие{58FA82} получили бонус в размере 300 ХР и 8 000$ за победу (Счет %d:%d)", PDMBluePnt, PDMRedPnt);
			SendClientMessageToAll(COLOR_PDM, String);
		}
		else if (PDMBluePnt < PDMRedPnt)
		{
			format(String, sizeof String, "Игроки команды {FA5882}Красные{58FA82} получили бонус в размере 300 ХР и 8 000$ за победу (Счет %d:%d)", PDMRedPnt, PDMBluePnt);
			SendClientMessageToAll(COLOR_PDM, String);
		}
		else if (PDMBluePnt == PDMRedPnt)
		{
			format(String, sizeof String,"Команды сыграли в ничью и получили бонус в размере 150 XP и 4 000$ (Счет %d:%d)", PDMBluePnt, PDMRedPnt);
			SendClientMessageToAll(COLOR_PDM, String);
		}
		
		foreach(Player, did)
		{//цикл
			if(JoinEvent[did] == EVENT_PDM)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0; InEvent[did] = 0; LSpawnPlayer(did); //UpdateColor(did);
                ShowClanZones(did); // покажем клановые зоны
				//100XP дается всем участникам Командный Десматча
				//За каждое убийство дается по 30 xp. Итого за 20 убийств игрок получит 700 XP.
				//Победившая команда получит еще 300хр за победу. В случаи ничьи обе команды получат по 150 XP.
				if (PDMKills[did] <= 20) BonusXP = 100 + PDMKills[did] * 30;
				else BonusXP = 700;//более 20 убийств
				BonusCash = 4000 + PDMKills[did] * 500;//По 500$ за убийство
			
				if (PDMBluePnt > PDMRedPnt && PDMTeam[did] == 1) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else if (PDMBluePnt < PDMRedPnt && PDMTeam[did] == 2) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else {BonusXP += 150; BonusCash += 4000;}
				BonusXP += FarmedXP[did];
				format(String,sizeof String,"Вы получили %d ХР и %d$ за участие в захвате точки (Убийств: %d).", BonusXP, BonusCash, PDMKills[did]);
				SendClientMessage(did, COLOR_YELLOW, String);
				LGiveXP(did, BonusXP);
				Player[did][Cash] += BonusCash;
				QuestUpdate(did, 28, 1);//Обновление квеста Примите участие в 3 тдм
				QuestUpdate(did, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				MarafonUpdate(did, 0, 1); //ивенты
				MarafonUpdate(did, 5, BonusCash);//мани
				//DayQuestEventsUpdate(did);//Обновление ежедневного квеста Примите участие в 25 соревнованиях
				TextDrawHideForPlayer(did, TextDrawEvent[EVENT_PDM]);
				FarmedXP[did] = 0;
			}
		}//цикл
	}//конец тдм
	
