
ZBTime--;
if(ZBTime <= 0)
{
	new PlayerExp[MAX_PLAYERS]=0, str[140];
	for (new Zone=1; Zone<MAX_GZONE;Zone++)
	{
	    //проверка на пустые терры (клан владелец удалился)
    	if(GangZones[Zone][GZOwner]>0)
    	{
			new clanid = GangZones[Zone][GZOwner];
        	if(Clan[clanid][cLevel] == 0) {GangZones[Zone][GZOwner] = 0; GangZones[Zone][GZColor] = 0; GangZoneHideForAll(ClanZoneID[Zone]); ClanZoneShowForFree(ClanZoneID[Zone],ClanZoneColor[0],0,0); SaveZone(Zone);}
		}
	
	    if(GangZones[Zone][GZOwner] == 0) continue;
	    new clanid = GangZones[Zone][GZOwner];
	    Clan[clanid][ClanBank] += GangZones[Zone][GZCash];
	    Clan[clanid][InfPoints]++;
	    //ClanCash[clanid] += GangZones[Zone][GZCash];
        foreach(Player, cid) if (Player[cid][MyClan] == clanid) PlayerExp[cid] += GangZones[Zone][GZExp];
	}
	foreach(Player, cid)
	{
		if (PlayerExp[cid]>0)
		{
		    if(Player[cid][DMove] > 120 || LAFK[cid] > 120)
		    {
		        SendClientMessage(cid,COLOR_RED," Вы не получили опыт с территорий клана, так как были в афк или стояли на месте.");
		    }
		    else
		    {
		    	LGiveXP(cid, PlayerExp[cid]);
            	format(str, sizeof(str), " Вы получили %d XP со всех владений клана!", PlayerExp[cid]);
            	SendClientMessage(cid,COLOR_YELLOW,str);
            	PlayerPlaySound(cid,1084,0.0,0.0,0.0);
      		}
		}
	}
	ZBTime = 780;
	//ZBTime = 800;
}

//таймер чекер зон
for (new Zone=1; Zone<MAX_GZONE;Zone++)
{
	//проверяем, стала ли доступна зона
    if(GangZones[Zone][GZClanTime] < unixtime && GangZones[Zone][GZClanTime] != -10)
	{
	    GangZones[Zone][GZClanTime] = -10;
	    new stext[140];
        format(stext, sizeof(stext), "Зона '{FFA500}%s{AFAFAF}' [ID:%d] доступна для захвата! Навигация: /zones.", GangZones[Zone][GZName], Zone);
        SendClientMessageToAll(0xAFAFAFFF,stext);
        TextDrawSetString(ZoneStateTD[Zone], "Zone FREE");
        TextDrawColor(ZoneStateTD[Zone], 15401215);
	}

    //проверим стадию зоны
    if(GangZones[Zone][ZoneAttacked] < 1) continue;

	//зона на подготовке
    if(ZonePrepareTime[Zone] > 0)
	{
		ZonePrepareTime[Zone]--;
		new str[20];
        format(str, sizeof(str), "Zone Prepare: %s", TimeConvert(ZonePrepareTime[Zone]));
        TextDrawColor(ZoneStateTD[Zone], 0xFFBF00FF);
        TextDrawSetString(ZoneStateTD[Zone], str);
  	}
    
    if(ZonePrepareTime[Zone] == 1) //время на подготовку вышло
    {
        new stext[140];
		ZonePrepareTime[Zone] = 0;
		if(ZAtt[Zone] < 2) //атакующих кланов меньше 2 (т.е. 1 лол)
		{
		    new newowner = ZoneAttacker[Zone][0]; //новый владелец - первый атаковавший клан
		    format(stext, sizeof(stext), "CW: {afafaf}Никто не пришел на войну за зону '{FFA500}%s{AFAFAF}'! Новый владелец:%s %s", GangZones[Zone][GZName], ClanTextColor[Clan[newowner][cColor]],Clan[newowner][cName]);
        	SendClientMessageToAll(COLOUR_GANG_CHAT,stext);

        	if(GangZones[Zone][GZOwner] > 0 && Clan[GangZones[Zone][GZOwner]][cLevel] > 0)
        	{
            	Clan[GangZones[Zone][GZOwner]][ClanZones]--;
			}

			GangZones[Zone][ZoneAttacked] = 0;
			GangZones[Zone][GZOwner] = newowner;
			GangZones[Zone][GZClanTime] = unixtime+9000;
			GangZones[Zone][GZColor] = Clan[newowner][cColor];
			Clan[newowner][NowWarZone] = 0;
			for(new i=0;i<MAX_ATTACK;i++) ZoneAttacker[Zone][i] = 0;
			ZAtt[Zone]=0;
			Clan[newowner][ClanZones]++;
			GangZoneStopFlashForAll(ClanZoneID[Zone]);
			GangZoneHideForAll(ClanZoneID[Zone]);
			ClanZoneShowForFree(ClanZoneID[Zone],ClanZoneColor[GangZones[Zone][GZColor]],0,0);
			SaveClan(newowner);
			SaveZone(Zone);
			TextDrawColor(ZoneStateTD[Zone], 0x2E64FEFF);
			TextDrawSetString(ZoneStateTD[Zone], "CAPT_LOCKED");
		}
    	else //кланов 2 или более
    	{
        	format(stext, sizeof(stext), "CW: {afafaf}Битва за зону '{FFA500}%s{AFAFAF}' (%d) началась! Кланов: {FFA500}%d", GangZones[Zone][GZName], Zone, ZAtt[Zone]);
        	SendClientMessageToAll(COLOUR_GANG_CHAT,stext);
        	ZoneWarTime[Zone] = 240;
        	TextDrawColor(ZoneStateTD[Zone], 0xFF0000FF);
        	GangZones[Zone][ZoneAttacked] = 2;
    	}
    	
	}
	
	if(GangZones[Zone][ZoneAttacked] < 2) continue;
	
	//во время войны
	if(ZoneWarTime[Zone] > 0)
	{
		ZoneWarTime[Zone]--;
		new str[200],strint[50];
        format(str, sizeof(str), "Time: %s~n~~y~", TimeConvert(ZoneWarTime[Zone]));
        for(new i=0;i<ZAtt[Zone];i++) {format(strint, sizeof(strint), "%s: %d~n~", Clan[ZoneAttacker[Zone][i]][cName], ClanKills[ZoneAttacker[Zone][i]] ); strcat(str, strint);}
        strdel(str, strlen(str)-3, strlen(str));
        TextDrawSetString(ZoneStateTD[Zone], str);
        
        new addpoints=0;
        switch(ZoneWarTime[Zone])
        {
            case 210,180,130,90,60,30: addpoints=1;
			default: addpoints=0;
        }
        
        if(addpoints == 1)
        {
            foreach(Player, cid)
            {
                if(Player[cid][MyClan] > 0 && Logged[cid] == 1 && LAFK[cid] < 3 && LSpecID[cid] == -1)
                {
                    new clanID = Player[cid][MyClan];
                    if(Clan[clanID][NowWarZone] > 0 && OnZone[cid] == Clan[clanID][NowWarZone]) {ClanKills[clanID]++; GameTextForPlayer(cid, "+1", 1500, 6);PlayerPlaySound(cid,1084,0.0,0.0,0.0);}
                }
            }
        }
	}
	
	if(ZoneWarTime[Zone] == 1)
 	{
 	    ZoneWarTime[Zone] = 0;
 	    
 	    new newowner=0;
 		new winnerscore=-1;
 		new stext[140];
 		
 		//определим победителя
 		for(new i=0;i<MAX_ATTACK;i++)
 		{
     		if (ClanKills[ZoneAttacker[Zone][i]] > winnerscore)
 	 		{
 				newowner = ZoneAttacker[Zone][i];
				winnerscore = ClanKills[ZoneAttacker[Zone][i]];
 	 		}
 	 		ClanKills[ZoneAttacker[Zone][i]]=0;
 		}
 		
 		//клан защитил свою терру
 		if(newowner == GangZones[Zone][GZOwner])
 		{
 		    format(stext, sizeof(stext), "CW: {afafaf}Клан '%s%s{AFAFAF}' защитил территорию '{FFA500}%s{AFAFAF}'! Счет: %d",ClanTextColor[Clan[newowner][cColor]], Clan[newowner][cName], GangZones[Zone][GZName], winnerscore);
 		    SendClientMessageToAll(COLOUR_GANG_CHAT,stext);
   		}
   		else //клан захватил терру
   		{
 			format(stext, sizeof(stext), "CW: {afafaf}Клан '%s%s{AFAFAF}' захватил территорию '{FFA500}%s{AFAFAF}'! Счет: %d",ClanTextColor[Clan[newowner][cColor]], Clan[newowner][cName], GangZones[Zone][GZName], winnerscore);
        	SendClientMessageToAll(COLOUR_GANG_CHAT,stext);
        	if(Clan[GangZones[Zone][GZOwner]][cLevel] > 0) Clan[GangZones[Zone][GZOwner]][ClanZones]--; //если у терры был владелец, минусуем ему терры
        	GangZones[Zone][GZOwner] = newowner;
        	GangZones[Zone][GZColor] = Clan[newowner][cColor];
        	Clan[newowner][ClanZones]++; //новому владельцу добавляем
        }

        new clid = GangZones[Zone][GZOwner];
        foreach(Player, cid)
		{
		    if (Player[cid][MyClan] == clid)
		    {
		    	if(Player[cid][DMove] < 200 || LAFK[cid] < 120)
	  			{
					LGiveXP(cid, GangZones[Zone][GZExp]*8); //х8 хп за победу
            		format(stext, sizeof(stext), " Вы получили %d XP за победу в сражении за территорию!", GangZones[Zone][GZExp]*8);
            		SendClientMessage(cid,COLOR_YELLOW,stext);
	  			}
			}
		}

		GangZones[Zone][ZoneAttacked] = 0;
		GangZones[Zone][GZClanTime] = unixtime+9000+random(1000);
		
		for(new i=0;i<MAX_ATTACK;i++) {Clan[ZoneAttacker[Zone][i]][NowWarZone] = 0; ClanKills[ZoneAttacker[Zone][i]]=0; ZoneAttacker[Zone][i] = 0;}
		ZAtt[Zone]=0;
		
		GangZoneStopFlashForAll(ClanZoneID[Zone]);
		GangZoneHideForAll(ClanZoneID[Zone]);
		ClanZoneShowForFree(ClanZoneID[Zone],ClanZoneColor[GangZones[Zone][GZColor]], 0, 0);
		
		SaveZone(Zone);
		TextDrawColor(ZoneStateTD[Zone], 0x2E64FEFF);
		TextDrawSetString(ZoneStateTD[Zone], "CAPT_LOCKED");
 	}
}


