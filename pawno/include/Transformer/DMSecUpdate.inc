	if (DMTimer > 0)
	{
		DMTimer--; new String[60];
		format(String, sizeof String, "DEATHMATCH:~w~ %d sec. Players: %d", DMTimer, DMPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_DM], String);
	}
	if (DMTimeToEnd >= 0) DMTimeToEnd--;
	if (DMTimer <= 0 && DMTimeToEnd < 0)
	{//Рестарт дм (он либо закончился, либо не стартовал)
		DMTimer = GetEventRestartTime();
		while (PrevDM == DMid) DMid = random(20) + 1; //выбор новой карты для дм
		PrevDM = DMid;
	}//Рестарт дм (он либо закончился, либо не стартовал)
	if (DMTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| Десматч [{FFFFFF}%s{FF8C00}] начнется через {FFFFFF}минуту{FF8C00}!",DMName[DMid]);SendClientMessageToAll(COLOR_DM,string);
		SendClientMessageToAll(COLOR_DM,"| Используйте {FFFFFF}/dm{FF8C00} если хотите участвовать");
	}

	if (DMTimer == 1)
	{//старт дм
		new String[140];
		if (DMPlayers < 2)
		{//мало участников
			format(String,sizeof(String),"Десматч <<{FFFFFF}%s{FF8C00}>> не начался, так как не хватило участников (Минимум:{FFFFFF} 2{FF8C00})",DMName[DMid]);
			SendClientMessageToAll(COLOR_DM,String);
		}//мало участников
		else
		{//достаточно участников
			format(String,sizeof(String),"Десматч <<{FFFFFF}%s{FF8C00}>> начался. Игроков: {FFFFFF}%d",DMName[DMid], DMPlayers);
			SendClientMessageToAll(COLOR_DM,String);
			DMTimeToEnd = 180; DMLeaderID = -1; DMLeaderKills = 0;
			for (new i = 0; i < MAX_PLAYERS; i++)
			{//цикл (здесь обязательно использовать обычный for, а не foreach)
				DMKills[i] = 0;
				if(JoinEvent[i] == EVENT_DM)
				{
					if (OnFly[i]) StopFly(i);//Исправляет баг при старте дм в режиме супермена
					OnStartEvent[i] = 5; LSpawnPlayer(i);
					TextDrawHideForPlayer(i, TextDrawEvent[EVENT_DM]);
					HideClanZones(i);
					AdminTPCantKill[i] = 0; //Исправляет баг, когда игроку было запрещено стрелять после телепортации - разрешает при старте соревнования
				}
			}//цикл (здесь обязательно использовать обычный for, а не foreach)
		}//достаточно участников
	}//старт дм	

	if (DMTimeToEnd == 0)
	{//конец дм
		new BonusXP, BonusCash, String[140];
		foreach(Player, did)
		{//цикл
			if(JoinEvent[did] == EVENT_DM)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0; InEvent[did] = 0; LSpawnPlayer(did);
				
				//50XP дается всем участникам десматча
				//За первые 10 убийств дается по 25хр, за последующие 20 убийств по 20хр, за последующие 15 убийсв по 10хр
				//Итого за 45 убийств игрок получит 850хр. Победитель десматча получит еще 150хр за победу.
				if (DMKills[did] <= 10) BonusXP = 50 + DMKills[did] * 25; //0 - 10 убийств
				else if (DMKills[did] <= 30) BonusXP = 300 + (DMKills[did] - 10) * 20;//11 - 30 убийств
				else if (DMKills[did] <= 45) BonusXP = 700 + (DMKills[did] - 30) * 10;//31 - 45 убийств
				else BonusXP = 850;//более 45 убийств
				BonusCash = 5000 + DMKills[did] * 250;//По 250$ за убийство
				if (did == DMLeaderID)
				{//победитель десматча
					BonusXP += 150; BonusCash += 15000;
					MarafonUpdate(did, 2, 1);
					format(String, sizeof String, "%s[%d] победил в десматче с %d убийствами и получил %d XP и %d$", PlayerName[did], did, DMLeaderKills, BonusXP, BonusCash);
					SendClientMessageToAll(COLOR_DM, String);
				}//победитель десматча
				format(String,sizeof String,"Вы получили %d ХР и %d$ за участие в десматче (Убийств: %d).", BonusXP, BonusCash, DMKills[did]);
				SendClientMessage(did,COLOR_YELLOW,String);
				MarafonUpdate(did, 5, BonusCash);
				MarafonUpdate(did, 0, 1);
				LGiveXP(did, BonusXP); Player[did][Cash] += BonusCash;
				QuestUpdate(did, 11, 1);//Обновление квеста Примите участие в 3 дм
				QuestUpdate(did, 18, 1);//Обновление квеста Примите участие в 5 соревнованиях
				ShowClanZones(did); // покажем клановые зоны
				//MarafonUpdate(did);
			}
		}//цикл
		format(String,sizeof(String),"Десматч <<{FFFFFF}%s{FF8C00}>> закончился",DMName[DMid]); 
		SendClientMessageToAll(COLOR_DM,String);
	}//конец дм
	
