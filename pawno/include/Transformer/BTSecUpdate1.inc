if (BTTimer > -7)
{
	BTTimer--; new String[60];
	format(String, sizeof String, "BATTLE:~w~ %d sec. Players: %d", BTTimer, BTPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_BATTLE], String);
}
if (BTTimer == 0)//не началось
{
	BTTimer = 180;
	SendClientMessageToAll(COLOR_BATTLE,"Битва не началась, недостаточно игроков.");
	BTRouteID = random(MAX_BTROUTS);
}
if (BTTimeToEnd >= 0) {BTTimeToEnd--; /*new String[60]; format(String, sizeof String, "Tm %d sec. ",BTTimeToEnd); SendClientMessageToAll(0xffffffff,String);*/}

if (BTTimer == 60)
{
	//new String[140];
	//SendClientMessageToAll(0xF4E002FF,"Бит{FFD101}ва до по{FCB102}след{FC9401}него {FD6E01}BATTLEGROUNDS {FC9401}начн{FCB102}ется {FFD101}через {FFFFFF}1 минуту!");
	//SendClientMessageToAll(0xF4E002FF,"Используйте {FFFFFF}/bt{F4E002} если хотите участвовать");
	SendClientMessageToAll(0x01DF01FF," Битва до последнего {ffffff}[BATTLEGROUNDS] {01DF01}начнется через {01DF01}1 минуту{01DF01}!");
	SendClientMessageToAll(0x01DF01FF," Используйте {FFFFFF}/bt{01DF01}, если хотите участвовать.");
}



if (BTTimer <= -1 && BTTimer >= -6)
{//три секунды после старта
	foreach(Player, eid)
	{//цикл
		if (BTTimer == -2 && BTStarted[eid] == 1 && BTTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "4",1000,6);}
		if (BTTimer == -3 && BTStarted[eid] == 1 && BTTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "3",1000,6);}
		if (BTTimer == -4 && BTStarted[eid] == 1 && BTTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (BTTimer == -5 && BTStarted[eid] == 1 && BTTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6);}
		if (BTTimer == -6 && BTStarted[eid] == 1 && BTTimeToEnd >= 0){PlayerPlaySound(eid,1057,0.0,0.0,0.0);GameTextForPlayer(eid, "start",1000,6);TogglePlayerControllable(eid,1);ResetPlayerWeapons(eid);}
	}//цикл
}//три секунды после старта



if (BTTimer <= -7)
{//Во время проведения
    new Float: dx, Float: dy, Float: dz;
	foreach(Player,eid) //постоянные проверки
	{
		if (BTStarted[eid] == 1)
		{
		    if (LAFK[eid] >= 5 && GetPVarInt(eid, "inplane") == 0) {ShowHideBTMap(eid, 0); SendClientMessage(eid,COLOR_RED,"Вы были выброшены из битвы за AFK!"); JoinEvent[eid] = 0; InEvent[eid] = 0; BTStarted[eid] = 0; SetPlayerVirtualWorld(eid, 0); LSpawnPlayer(eid); ShowClanZones(eid); continue;}
			GetPlayerPos(eid,dx,dy,dz);
        	if (GetPVarInt(eid, "inplane") == 1) LACSH[eid] = 3; //чтоб не кикало в самолете
        	if (GetPVarInt(eid,"UseMap") > 0) UpdateBTPosTD(eid, dx, dy); //обновление карты
		}
	}
	
	if (BTPlayers == 0)
	{
		BTTimeToEnd = 0;
		SendClientMessageToAll(COLOR_BATTLE,"Битва до последнего завершена.");
		BTTimer = 180;
		BTRouteID = random(MAX_BTROUTS);
	}
	
	
	
	switch(BTTimeToEnd)
	{
	    case 1950: //после завершения полета самолета создаем 1 зону
	    {
	        ChangeCenter(1); UpdFirstZone(3100.0, CenX, CenY, -1);
			foreach(Player,eid)
			{
			    if (BTStarted[eid] == 1)
			    {
			        for (new i; i<4; i++) GangZoneShowForPlayer(eid, FirstZone[i], 0xFFFFFFFF);
			        if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) TextDrawShowForPlayer(eid, FirstZoneTD[i]);
			        SendClientMessage(eid,COLOR_YELLOW,"Проследуйте в игровую зону, обозначенную на карте {ffffff}белым квадратом");
			        //TextDrawShowForPlayer(eid, BTLineTD);
			    }
			}
	    }
	    case 1650..1949: //5 мин (300с) таймер до 1 зоны
	    {
	        //таймер до 1 зоны
			TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-1650));
			if(BTTimeToEnd == 1650)
			{//вычисляем, сколько нужно отнимать в секунду от Х и У
			    SecDeleteS = (6000.0 - 3100.0) / 300; LineUpd = 0.0;
				if(0.0 - CenX > 0) SecDeleteX = -floatabs(CenX)/300; else SecDeleteX = floatabs(CenX)/300;
				if(0.0 - CenY > 0) SecDeleteY = -floatabs(CenY)/300; else SecDeleteY = floatabs(CenY)/300;
			}//вычисляем, сколько нужно отнимать в секунду от Х и У
	    }
		case 1350..1649: //5 мин (300с) идет 1 зона (от 6000 до 3100)
		{
   			//апдейт линии смещения
   			LineUpd += 0.34;
   			TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-1350));
   			TextDrawHideForAll(BTLineTD);
   			TextDrawTextSize(BTLineTD, LineUpd, 6.0);
   			//сужаем зону
   			for (new i; i<4; i++) {GangZoneHideForAll(SecondZone[i]); TextDrawHideForAll(SecondZoneTD[i]);}
   			OldSize -= SecDeleteS;
  			BOldX += SecDeleteX; BOldY += SecDeleteY;
   			UpdSecondZone(OldSize, BOldX, BOldY, 58111);
   			foreach(Player,eid)
			{
			    if (BTStarted[eid] == 1)
			    {
			        for (new i; i<4; i++) GangZoneShowForPlayer(eid, SecondZone[i], 0x0000FFFF);
			        if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) TextDrawShowForPlayer(eid, SecondZoneTD[i]);
			        TextDrawShowForPlayer(eid, BTLineTD);
			    }
			}
		}
		case 1140..1349: //3.30 (210c) до 2 зоны
		{
            if(BTTimeToEnd == 1349)
			{
			    for (new i; i<4; i++) {GangZoneHideForAll(FirstZone[i]); TextDrawHideForAll(FirstZoneTD[i]);}
			    ChangeCenter(2); UpdFirstZone(1900.0, CenX, CenY, -1);
			    TextDrawHideForAll(BTLineTD);
			    TextDrawTextSize(BTLineTD, 0.2, 6.000000);
			    foreach(Player,eid)
				{
			    	if (BTStarted[eid] == 1)
			    	{
			        	for (new i; i<4; i++) GangZoneShowForPlayer(eid, FirstZone[i], 0xFFFFFFFF);
			        	if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) {TextDrawShowForPlayer(eid, FirstZoneTD[i]);}
			        	SendClientMessage(eid,COLOR_YELLOW,"Проследуйте в игровую зону, обозначенную на карте {ffffff}белым квадратом");
			        	TextDrawShowForPlayer(eid, BTLineTD);
			    	}
				}
			}
			//таймер до зоны
			TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-1140));
			
			if(BTTimeToEnd == 1140)
			{//вычисляем, сколько нужно отнимать в секунду от Х и У
				SecDeleteS = (3100.0 - 1900.0) / 140; LineUpd = 0.0;
				if(BOldX - CenX > 0) SecDeleteX = -(floatabs(BOldX-CenX)/140); else SecDeleteX = floatabs(BOldX-CenX)/140;
				if(BOldY - CenY > 0) SecDeleteY = -(floatabs(BOldY-CenY)/140); else SecDeleteY = floatabs(BOldY-CenY)/140;
			}//вычисляем, сколько нужно отнимать в секунду от Х и У
		}
		case 1000..1139: //2.20 (140c) идет 2 зона
		{
		    //апдейт линии смещения
		    LineUpd += 0.72857;
            TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-1000));
            TextDrawHideForAll(BTLineTD);
   			TextDrawTextSize(BTLineTD, LineUpd, 6.000000);
   			//сужаем зону
   			for (new i; i<4; i++) {GangZoneHideForAll(SecondZone[i]); TextDrawHideForAll(SecondZoneTD[i]);}
   			OldSize -= SecDeleteS;//7.5;
			BOldX += SecDeleteX; BOldY += SecDeleteY;
   			UpdSecondZone(OldSize, BOldX, BOldY, 58111);
   			foreach(Player,eid)
			{
			    if (BTStarted[eid] == 1)
			    {
			        for (new i; i<4; i++) GangZoneShowForPlayer(eid, SecondZone[i], 0x0000FFFF);
			        if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) TextDrawShowForPlayer(eid, SecondZoneTD[i]);
			        TextDrawShowForPlayer(eid, BTLineTD);
			    }
			}
		}
		case 850..999://2.30 (150c) время до 3 зоны
		{
            if(BTTimeToEnd == 999)
			{
			    for (new i; i<4; i++) {GangZoneHideForAll(FirstZone[i]); TextDrawHideForAll(FirstZoneTD[i]);}
			    ChangeCenter(3); UpdFirstZone(850.0, CenX, CenY, -1);
			    TextDrawHideForAll(BTLineTD);
			    TextDrawTextSize(BTLineTD, 0.2, 6.000000);
			    foreach(Player,eid)
				{
			    	if (BTStarted[eid] == 1)
			    	{
			        	for (new i; i<4; i++) GangZoneShowForPlayer(eid, FirstZone[i], 0xFFFFFFFF);
			        	if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) {TextDrawShowForPlayer(eid, FirstZoneTD[i]);}
			        	SendClientMessage(eid,COLOR_YELLOW,"Проследуйте в игровую зону, обозначенную на карте {ffffff}белым квадратом");
			        	TextDrawShowForPlayer(eid, BTLineTD);
			    	}
				}
			}
			//таймер до зоны
            TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-850));

			if(BTTimeToEnd == 850)
			{//вычисляем, сколько нужно отнимать в секунду от Х и У
			    SecDeleteS = (1900.0 - 850.0) / 90; LineUpd = 0.0;
				if(BOldX - CenX > 0) SecDeleteX = -floatabs(BOldX-CenX)/90; else SecDeleteX = floatabs(BOldX-CenX)/90;
				if(BOldY - CenY > 0) SecDeleteY = -floatabs(BOldY-CenY)/90; else SecDeleteY = floatabs(BOldY-CenY)/90;
			}//вычисляем, сколько нужно отнимать в секунду от Х и У
		}
		case 760..849: //1.30 (90sec) идет 3 зона
		{
		    //апдейт линии смещения
		    LineUpd += 1.13333333;
            TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-760));
           	TextDrawHideForAll(BTLineTD);
   			TextDrawTextSize(BTLineTD, LineUpd, 6.000000);
   			//сужаем зону
   			for (new i; i<4; i++) {GangZoneHideForAll(SecondZone[i]); TextDrawHideForAll(SecondZoneTD[i]);}
   			OldSize -= SecDeleteS;//11.666666;
			BOldX += SecDeleteX; BOldY += SecDeleteY;
   			UpdSecondZone(OldSize, BOldX, BOldY, 58111);
   			foreach(Player,eid)
			{
			    if (BTStarted[eid] == 1)
			    {
			        for (new i; i<4; i++) GangZoneShowForPlayer(eid, SecondZone[i], 0x0000FFFF);
			        if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) TextDrawShowForPlayer(eid, SecondZoneTD[i]);
			        TextDrawShowForPlayer(eid, BTLineTD);
			    }
			}
		}
		case 640..759://2.00 (120c) время до 4 зоны
		{
            if(BTTimeToEnd == 759)
			{
			    for (new i; i<4; i++) {GangZoneHideForAll(FirstZone[i]); TextDrawHideForAll(FirstZoneTD[i]);}
			    ChangeCenter(4); UpdFirstZone(450.0, CenX, CenY, -1);
			    TextDrawHideForAll(BTLineTD);
			    TextDrawTextSize(BTLineTD, 0.2, 6.000000);
			    foreach(Player,eid)
				{
			    	if (BTStarted[eid] == 1)
			    	{
			        	for (new i; i<4; i++) GangZoneShowForPlayer(eid, FirstZone[i], 0xFFFFFFFF);
			        	if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) {TextDrawShowForPlayer(eid, FirstZoneTD[i]);}
			        	SendClientMessage(eid,COLOR_YELLOW,"Проследуйте в игровую зону, обозначенную на карте {ffffff}белым квадратом");
			        	TextDrawShowForPlayer(eid, BTLineTD);
			    	}
				}
			}
			//таймер до зоны
            TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-640));

			if(BTTimeToEnd == 640)
			{//вычисляем, сколько нужно отнимать в секунду от Х и У
				SecDeleteS = (850.0 - 450.0) / 90; LineUpd = 0.0;
				if(BOldX - CenX > 0) SecDeleteX = -floatabs(BOldX-CenX)/90; else SecDeleteX = floatabs(BOldX-CenX)/90;
				if(BOldY - CenY > 0) SecDeleteY = -floatabs(BOldY-CenY)/90; else SecDeleteY = floatabs(BOldY-CenY)/90;
			}//вычисляем, сколько нужно отнимать в секунду от Х и У
		}
		case 550..639: //1.30 (90sec) идет 4 зона
		{
		    //апдейт линии смещения
		    LineUpd += 1.13333333;
            TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-550));
            TextDrawHideForAll(BTLineTD);
   			TextDrawTextSize(BTLineTD, LineUpd, 6.000000);
   			//сужаем зону
   			for (new i; i<4; i++) {GangZoneHideForAll(SecondZone[i]); TextDrawHideForAll(SecondZoneTD[i]);}
   			OldSize -= SecDeleteS;//4.4444444;
			BOldX += SecDeleteX; BOldY += SecDeleteY;
   			UpdSecondZone(OldSize, BOldX, BOldY, 58111);
   			foreach(Player,eid)
			{
			    if (BTStarted[eid] == 1)
			    {
			        for (new i; i<4; i++) GangZoneShowForPlayer(eid, SecondZone[i], 0x0000FFFF);
			        if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) TextDrawShowForPlayer(eid, SecondZoneTD[i]);
			        TextDrawShowForPlayer(eid, BTLineTD);
			    }
			}
		}
		case 430..549://2.00 (120c) время до 5 зоны
		{
            if(BTTimeToEnd == 549)
			{
			    for (new i; i<4; i++) {GangZoneHideForAll(FirstZone[i]); TextDrawHideForAll(FirstZoneTD[i]);}
			    ChangeCenter(5); UpdFirstZone(50.0, CenX, CenY, -1);
			    TextDrawHideForAll(BTLineTD);
			    TextDrawTextSize(BTLineTD, 0.2, 6.000000);
			    foreach(Player,eid)
				{
			    	if (BTStarted[eid] == 1)
			    	{
			        	for (new i; i<4; i++) GangZoneShowForPlayer(eid, FirstZone[i], 0xFFFFFFFF);
			        	if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) {TextDrawShowForPlayer(eid, FirstZoneTD[i]);}
			        	SendClientMessage(eid,COLOR_YELLOW,"Проследуйте в игровую зону, обозначенную на карте {ffffff}белым квадратом");
			        	TextDrawShowForPlayer(eid, BTLineTD);
			    	}
				}
			}
			//таймер до зоны
            TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-430));

			if(BTTimeToEnd == 430)
			{//вычисляем, сколько нужно отнимать в секунду от Х и У
				SecDeleteS = (450.0 - 50.0) / 60; LineUpd = 0.0;
				if(BOldX - CenX > 0) SecDeleteX = -floatabs(BOldX-CenX)/60; else SecDeleteX = floatabs(BOldX-CenX)/60;
				if(BOldY - CenY > 0) SecDeleteY = -floatabs(BOldY-CenY)/60; else SecDeleteY = floatabs(BOldY-CenY)/60;
			}//вычисляем, сколько нужно отнимать в секунду от Х и У
		}
		case 370..429: //1.00 (60sec) идет 5 зона
		{
		    //апдейт линии смещения
		    LineUpd += 1.7;
            TextDrawSetString(BTTimeTD, TimeConvert(BTTimeToEnd-370));
            TextDrawHideForAll(BTLineTD);
   			TextDrawTextSize(BTLineTD, LineUpd, 6.000000);
   			//сужаем зону
   			for (new i; i<4; i++) {GangZoneHideForAll(SecondZone[i]); TextDrawHideForAll(SecondZoneTD[i]);}
   			OldSize -= SecDeleteS;//6.666666;
			BOldX += SecDeleteX; BOldY += SecDeleteY;
   			UpdSecondZone(OldSize, BOldX, BOldY, 58111);
   			foreach(Player,eid)
			{
			    if (BTStarted[eid] == 1)
			    {
			        for (new i; i<4; i++) GangZoneShowForPlayer(eid, SecondZone[i], 0x0000FFFF);
			        if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) TextDrawShowForPlayer(eid, SecondZoneTD[i]);
			        TextDrawShowForPlayer(eid, BTLineTD);
			    }
			}
		}
		default: {}
	}

}//Во время проведения

if(BTTimer == 1)
{//Старт
	if (BTPlayers < 1) //3
	{//не началось
		SendClientMessageToAll(COLOR_BATTLE,"Битва до последнего не началась, так как не хватило участников (Минимум:{FFFFFF} 3{01DF01})");
		foreach(Player, eid)
		{//цикл
			if (JoinEvent[eid] == EVENT_BATTLE)
			{//единственный участник
				JoinEvent[eid] = 0; InEvent[eid] = 0; BTStarted[eid] = 0;
			}//единственный участник
		}//цикл
		BTTimer = 180; BTTimeToEnd = 0;
	}//не началось
	else
	{//стартовало
        new Float:FAngle = atan((BTRouts[BTRouteID][ftoY] - BTRouts[BTRouteID][ffY]) / (BTRouts[BTRouteID][ftoX] - BTRouts[BTRouteID][ffX]));
		SetObjectPos(PlaneObject[0], BTRouts[BTRouteID][ffX], BTRouts[BTRouteID][ffY], 1200.0);
        if(!BTRouts[BTRouteID][isback]) FAngle -= 90.0; else FAngle += 90.0;
		SetObjectRot(PlaneObject[0], 0.0, 0.0, FAngle);
	    MoveObject(PlaneObject[0], BTRouts[BTRouteID][ftoX], BTRouts[BTRouteID][ftoY], 1200.0, 95.0);
	    
	    CreateBTLoot();
	    UpdSecondZone(6000.0, 0.0, 0.0, 58111);
	    
	    TextDrawSetString(BTTimeTD, "Wait");
	    TextDrawTextSize(BTLineTD, 2.000000, 6.000000);
		new String[140];
		format (String, sizeof(String),"Players: %d", BTPlayers);
		TextDrawSetString(BTPlayersTD, String);
		
		foreach(Player, cid)
		{//Цикл для участников
			if (JoinEvent[cid] == EVENT_BATTLE)
			{//если игрок в evente
				StopFly(cid);StopVehFly(cid);
				ResetPlayerWeapons(cid);LACSH[cid] = 3;
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_BATTLE]);
				HideClanZones(cid);
				Player[cid][CarActive] = 0; //Исправляет баг с использованием навыков
				SetPlayerVirtualWorld(cid, BATTLE_WORLD);
				SetPlayerArmour(cid, 0);
				BTStarted[cid] = 1;
				LAFK[cid] = 0;
				Player[cid][CarActive] = 0;
    			SetPVarInt(cid, "inplane", 1);
				//SetPlayerPos(cid, BTRouts[BTRouteID][ffX], BTRouts[BTRouteID][ffY], 1450.0);
				SetPlayerFacingAngle(cid, FAngle+90); TogglePlayerSpectating(cid, 1); AttachCameraToObject(cid, PlaneObject[1]);
				ApplyAnimation(cid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 1000); //подгрузим анимку
    			SetPVarInt(cid, "PLoot", -1);  SetPVarInt(cid, "PBLoot", -1);
    			SetPVarInt(cid,"UseMap",1); TextDrawShowForPlayer(cid, BTMap);
				for(new i;i<3;i++) TextDrawShowForPlayer(cid, BTMainTD[i]);
				TextDrawShowForPlayer(cid, BTTimeTD); TextDrawShowForPlayer(cid, BTLineTD); TextDrawShowForPlayer(cid, BTPlayersTD);
    			//чистим инвентарь
    			for(new i;i<4;i++) PlayerInv[cid][i] = -1;
    			Slot1Bullets[cid] = 0; Slot2Bullets[cid] = 0; ThrowCount[cid] = 0; SetPVarInt(cid, "BThls", 0);
			}//если игрок в evente
		}//Цикл для участников
		BTTimer = -1; BTPosition = 1; BTTimeToEnd = 2040; OldSize=6000.0; BOldX=0.0; BOldY=0.0;
		format (String, sizeof(String),"Битва до последнего началась. Игроков: {FFFFFF}%d{01DF01}.", BTPlayers);
		SendClientMessageToAll(COLOR_BATTLE,String);
	}//стартовало

}//Старт
