	if (GGTimer > 0)
	{
		GGTimer--; new String[60];
		format(String, sizeof String, "GUNGAME:~w~ %d sec. Players: %d", GGTimer, GGPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_GUNGAME], String);
	}
	if (GGTimer <= 0 && GGTimeToEnd < 0)
	{
		GGTimer = GetEventRestartTime();
		while (PrevGGid == GGid) GGid = random(20) + 1; //выбор новой карты для гонки вооружений
		PrevGGid = GGid;
	}
	
	if (GGTimeToEnd >= 0) GGTimeToEnd--;
	if (GGTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| Гонка Вооружений [{FFFFFF}%s{FF6666}] начнется через {FFFFFF}минуту{FF6666}!",GGName[GGid]);SendClientMessageToAll(COLOR_GG,string);
		SendClientMessageToAll(COLOR_GG,"| Используйте {FFFFFF}/gg{FF6666}, если хотите участвовать.");
	}

	if (GGTimer == 1)
	{//Старт
		new String[140];format(String,sizeof(String),"Гонка Вооружений <<{FFFFFF}%s{FF6666}>> не началась, так как не хватило участников (Минимум:{FFFFFF} 2{FF6666})",GGName[GGid]);
		if (GGPlayers < 2) SendClientMessageToAll(COLOR_GG,String);
		else
		{
			GGTimeToEnd = 1800;format(String,sizeof(String),"Гонка Вооружений <<{FFFFFF}%s{FF6666}>> началась. Игроков: {FFFFFF}%d",GGName[GGid], GGPlayers);
			SendClientMessageToAll(COLOR_GG,String);
			foreach(Player, did)
			{//цикл
				GGKills[did] = 0;
				if(JoinEvent[did] == EVENT_GUNGAME)
				{
					if (OnFly[did]) StopFly(did);//Исправляет баг при старте гг в режиме супермена
					OnStartEvent[did] = 5;LSpawnPlayer(did);FarmedXP[did] = 0;FarmedMoney[did] = 0;
					HideClanZones(did); //скрываем зоны
					TextDrawHideForPlayer(did, TextDrawEvent[EVENT_GUNGAME]);
					AdminTPCantKill[did] = 0; //Исправляет баг, когда игроку было запрещено стрелять после телепортации - разрешает при старте соревнования
				}
			}//цикл
		}
	}//Старт


	if (GGTimeToEnd == 0)
	{//конец
		new String[140];
		foreach(Player, did)
		{//цикл
			if(JoinEvent[did] == EVENT_GUNGAME)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0;LSpawnPlayer(did);LGiveXP(did, 100);
				format(String,sizeof(String),"Вы получили 100 ХР за участие в Гонке Вооружений. Всего за Гонку Вооружений: %d ХР и %d$",FarmedXP[did] + 100, FarmedMoney[did]);
				SendClientMessage(did,COLOR_YELLOW,String);
				//MarafonUpdate(did, 1, 0, FarmedMoney[did], 0);
				MarafonUpdate(did, 0, 1);
				MarafonUpdate(did, 5, FarmedMoney[did]);
				ShowClanZones(did); // покажем клановые зоны
			}
		}//цикл
		format(String,sizeof(String),"Гонка Вооружений <<{FFFFFF}%s{FF6666}>> закончилась (Время вышло).",GGName[GGid]);
		SendClientMessageToAll(COLOR_GG,String);
	}//конец	
	
