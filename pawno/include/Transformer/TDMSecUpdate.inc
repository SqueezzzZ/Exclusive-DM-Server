	if (TDMTimer > 0)
	{
		TDMTimer--; new String[60];
		format(String, sizeof String, "TEAM DM:~w~ %d sec. Players: %d", TDMTimer, TDMPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_TDM], String);
	}
	if (TDMTimeToEnd >= 0) 
	{
		TDMTimeToEnd--; new String[110];
		format(String, sizeof String, "TDM:~w~ Time to end %d sec.         WHITE %d ~u~ ~p~%d BLACK", TDMTimeToEnd, TDMGroveKills, TDMBallasKills);
		TextDrawSetString(TextDrawEvent[EVENT_TDM], String);		
	}
	if (TDMTimer <= 0 && TDMTimeToEnd < 0)
	{//Рестарт тдм (он либо закончился, либо не стартовал)
		TDMTimer = GetEventRestartTime();
		while (PrevTDM == TDMid) TDMid = random(MAX_TDM) + 1; //выбор новой карты для тдм
		PrevTDM = TDMid;
	}//Рестарт тдм (он либо закончился, либо не стартовал)
	if (TDMTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| Командный Десматч [{FFFFFF}%s{04B486}] начнется через {FFFFFF}минуту{04B486}!", TDMName[TDMid]); SendClientMessageToAll(COLOR_TDM, string);
		SendClientMessageToAll(COLOR_TDM, "| Используйте {FFFFFF}/tdm{04B486}, если хотите участвовать.");
	}
	//Баг от слива XP в последние секунды соревнования
	if (TDMTimeToEnd == 2) foreach(Player, cid) if (InEvent[cid] == EVENT_TDM) EndEventFreeze(cid);

	if (TDMTimer == 1)
	{//старт тдм
		new String[140];
		if (TDMPlayers < 2)
		{//мало участников
			format(String,sizeof(String),"Командный Десматч <<{FFFFFF}%s{04B486}>> не начался, так как не хватило участников (Минимум:{FFFFFF} 2{04B486})", TDMName[TDMid]);
			SendClientMessageToAll(COLOR_TDM, String);
			foreach(Player, cid) if (JoinEvent[cid] == EVENT_TDM) {JoinEvent[cid] = 0; TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_TDM]);} //исправление ошибки, когда игрок в неактивном соревновании и не может из него выйти
		}//мало участников
		else
		{//достаточно участников
			format(String,sizeof(String),"Командный Десматч <<{FFFFFF}%s{04B486}>> начался. Игроков: {FFFFFF}%d", TDMName[TDMid], TDMPlayers);
			SendClientMessageToAll(COLOR_TDM,String);
			TDMTimeToEnd = 180; TDMGroveKills = 0; TDMBallasKills = 0; 
			new nextTeam = 1;
			TDMGrove = 0; TDMBallas = 0;
			for (new i = 0; i < MAX_PLAYERS; i++)
			{//цикл (здесь обязательно использовать обычный for, а не foreach)
				TDMKills[i] = 0; TDMTeam[i] = 0;
				if(JoinEvent[i] == EVENT_TDM)
				{
					if (LastPlayerTuneStatus[i] > 0) 
					{
						SendClientMessage(i, COLOR_RED, "Не удалось переместить вас на старт соревнования, так как вы находились в автомастерской во время старта!"); 
						JoinEvent[i] = 0;TextDrawHideForPlayer(i, TextDrawEvent[EVENT_TDM]);  continue;
					}
					if (OnFly[i]) StopFly(i);//Исправляет баг при старте тдм в режиме супермена
					InEvent[i] = EVENT_TDM; SetPlayerArmour(i, 0);
					OnStartEvent[i] = 5; ClearAnimations(i);
					//TDMStarted[i] = 1;
					AdminTPCantKill[i] = 0; //Исправляет баг, когда игроку было запрещено стрелять после телепортации - разрешает при старте соревнования
					if (nextTeam == 1) {TDMTeam[i] = 1; nextTeam = 2; TDMGrove++;} //grove
					else {TDMTeam[i] = 2; nextTeam = 1; TDMBallas++;} //ballas
					LSpawnPlayer(i); //UpdateColor(i);
					HideClanZones(i); //скрываем зоны
				}
			}//цикл (здесь обязательно использовать обычный for, а не foreach)
		}//достаточно участников
	}//старт тдм	

	if (TDMTimeToEnd == 0)
	{//конец тдм
		new BonusXP, BonusCash, String[140];
		format(String, sizeof String, "Командный Десматч <<{FFFFFF}%s{04B486}>> закончился", TDMName[TDMid]); SendClientMessageToAll(COLOR_TDM, String);
		if (TDMGroveKills > TDMBallasKills)
		{
			format(String, sizeof String, "Игроки команды {ffffff}WHITE{04B486} получили бонус в размере 300 ХР и 8 000$ за победу (Счет %d:%d)", TDMGroveKills, TDMBallasKills);
			SendClientMessageToAll(COLOR_TDM, String);
		}
		else if (TDMGroveKills < TDMBallasKills)
		{
			format(String, sizeof String, "Игроки команды {000000}BLACK{04B486} получили бонус в размере 300 ХР и 8 000$ за победу (Счет %d:%d)", TDMBallasKills, TDMGroveKills);
			SendClientMessageToAll(COLOR_TDM, String);
		}
		else if (TDMGroveKills == TDMBallasKills)
		{
			format(String, sizeof String,"Команды сыграли в ничью и получили бонус в размере 150 XP и 4 000$ (Счет %d:%d)", TDMGroveKills, TDMBallasKills);
			SendClientMessageToAll(COLOR_TDM, String);
		}
		
		foreach(Player, did)
		{//цикл
			if(JoinEvent[did] == EVENT_TDM)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0; InEvent[did] = 0; LSpawnPlayer(did); //UpdateColor(did);
                ShowClanZones(did); // покажем клановые зоны
				//100XP дается всем участникам Командный Десматча
				//За каждое убийство дается по 30 xp. Итого за 20 убийств игрок получит 700 XP.
				//Победившая команда получит еще 300хр за победу. В случаи ничьи обе команды получат по 150 XP.
				if (TDMKills[did] <= 20) BonusXP = 100 + TDMKills[did] * 30;
				else BonusXP = 700;//более 20 убийств
				BonusCash = 4000 + TDMKills[did] * 500;//По 500$ за убийство
			
				if (TDMGroveKills > TDMBallasKills && TDMTeam[did] == 1) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else if (TDMGroveKills < TDMBallasKills && TDMTeam[did] == 2) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else {BonusXP += 150; BonusCash += 4000;}				
				format(String,sizeof String,"Вы получили %d ХР и %d$ за участие в Командном Десматче (Убийств: %d).", BonusXP, BonusCash, TDMKills[did]);
				SendClientMessage(did, COLOR_YELLOW, String);
				LGiveXP(did, BonusXP);
				Player[did][Cash] += BonusCash;
				QuestUpdate(did, 28, 1);//Обновление квеста Примите участие в 3 тдм
				QuestUpdate(did, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				MarafonUpdate(did, 0, 1); //ивенты
				MarafonUpdate(did, 5, BonusCash);//мани
				//DayQuestEventsUpdate(did);//Обновление ежедневного квеста Примите участие в 25 соревнованиях
				TextDrawHideForPlayer(did, TextDrawEvent[EVENT_TDM]);
			}
		}//цикл
	}//конец тдм
	
