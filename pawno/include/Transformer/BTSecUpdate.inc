if (BTTimer > -7)
{
	BTTimer--; new String[60];
	format(String, sizeof String, "BATTLE:~w~ %d sec. Players: %d", BTTimer, BTPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_BATTLE], String);
}
if (BTTimer == 0)//�� ��������
{
	BTTimer = 180;
	SendClientMessageToAll(COLOR_BATTLE,"����� �� ��������, ������������ �������.");
	//BTRouteID = random(MAX_BTROUTS);
}
//if (BTTimeToEnd >= 0) {BTTimeToEnd--; /*new String[60]; format(String, sizeof String, "Tm %d sec. ",BTTimeToEnd); SendClientMessageToAll(0xffffffff,String);*/}

if (BTTime > 0) BTTime--;

if (BTTimer == 60)
{
	SendClientMessageToAll(0x01DF01FF,"| ����� �� ���������� {ffffff}[BATTLEGROUNDS] {01DF01}�������� ����� {ffffff}1 ������{01DF01}!");
	SendClientMessageToAll(0x01DF01FF,"| ����������� {FFFFFF}/bt{01DF01}, ���� ������ �����������.");
	//������� ����� �����
	for(new i; i<MaxVehicleUsed;i++) if(IsValidVehicle(i) && GetVehicleVirtualWorld(i) == BATTLE_WORLD) DestroyVehicle(i); //��������� ��� ����� � ���� �����
 	CreateRandomBTVehicles(); //�������� �����
 	CreatePlaneRoute();
	SetObjectPos(PlaneObject[0], BTRouts[ffX], BTRouts[ffY], 1200.0);
	SetObjectRot(PlaneObject[0], 0.0, 0.0, BTRouts[ftoA]);
 	//for(new i; i<MAX_BTCARS;i++) {RepairVehicle(BtVehicle[i]); SetVehicleToRespawn(BtVehicle[i]);} //�������� ����� ���, ���� ������ �� ������� �����
}



if (BTTimer <= -1 && BTTimer >= -6)
{//��� ������� ����� ������
	foreach(Player, eid)
	{//����
		if (BTTimer == -2 && BTStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "4",1000,6); SetPlayerSkillLevel(eid, WEAPONSKILL_PISTOL, 500); SetPlayerSkillLevel(eid, WEAPONSKILL_SAWNOFF_SHOTGUN, 500);	SetPlayerSkillLevel(eid, WEAPONSKILL_MICRO_UZI, 500);}
		if (BTTimer == -3 && BTStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "3",1000,6);}
		if (BTTimer == -4 && BTStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (BTTimer == -5 && BTStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6);}
		if (BTTimer == -6 && BTStarted[eid] == 1){PlayerPlaySound(eid,1057,0.0,0.0,0.0);GameTextForPlayer(eid, "start",1000,6);TogglePlayerControllable(eid,1);ResetPlayerWeapons(eid);}
	}//����
}//��� ������� ����� ������



if (BTTimer <= -7)
{//�� ����� ����������
    new Float: dx, Float: dy, Float: dz;
	foreach(Player,eid) //���������� ��������
	{
		if (BTStarted[eid] == 1)
		{
		    if (LAFK[eid] >= 7 && GetPVarInt(eid, "inplane") == 0) {SendClientMessage(eid,COLOR_RED,"�� ���� ��������� �� ����� �� AFK!");  ResetPlayerWeapons(eid); PUBGRewardPlayer(eid); continue;}
			if(GetPlayerVirtualWorld(eid) != BATTLE_WORLD)  {ResetPlayerWeapons(eid); PUBGRewardPlayer(eid); continue;} // ����� �������� � ������ ����
			GetPlayerPos(eid,dx,dy,dz);
        	if (GetPVarInt(eid, "inplane") == 1) LACSH[eid] = 3; //���� �� ������ � ��������
        	if (GetPVarInt(eid,"UseMap") > 0) UpdateBTPosTD(eid, dx, dy); //���������� �����

            new btgun = GetPlayerSurfingVehicleID(eid);
        	if (btgun != INVALID_VEHICLE_ID && !IsVehicleBtBoat(btgun) ) {SetPlayerPos(eid,dx+2.0,dy,dz);/*SetPlayerVelocity(eid, 0.5, 0.5, 0.3);*/ SendClientMessage(eid, COLOR_GREY, "��������� ���������� �� ����� ���������� �� /bt!");}
        	//������������� ������ � ��������
        	
        	if( PlayerInv[eid][3] != -1 ) GetPlayerWeaponData(eid, 8, btgun, ThrowCount[eid]);
        	if(ThrowCount[eid] < 1) PlayerInv[eid][3] = -1;
   			//������������� ������ �� ������
        	new nowweapon = GetPlayerWeapon(eid);
        	UpdatePlayerBTWeapons(eid, nowweapon);
			//���� �����
        	if (BTTime < 301 && (dx < ZoneXY[0] || dx > ZoneXY[1] || dy < ZoneXY[2] || dy > ZoneXY[3]) )
        	{
        	    TextDrawShowForPlayer(eid, BTMainTD[3]);
        	    new Float: hp; GetPlayerHealth(eid, hp);
        	    SetPlayerHealth(eid, hp - BTZone[BTStage][ZoneDamage]);
        	}
        	else TextDrawHideForPlayer(eid, BTMainTD[3]);
		}
	
		if (BTStarted[eid] == 1 && BTPlayers == 1) // == 1 ����
		{//��������� ��������
			ResetPlayerWeapons(eid);
	    	PUBGRewardPlayer(eid);
		}//��������� ��������
	}
	
	if (BTPlayers == 0)
	{
		//BTTimeToEnd = 0;
		SendClientMessageToAll(COLOR_BATTLE,"����� �� ���������� ���������. ����� ��������� ����� {ffffff}3 ������{01DF01}!");
		StopObject(PlaneObject[0]);
		BTTimer = 180;
		//BTRouteID = random(MAX_BTROUTS);
		BTActiveZone = -1;
	}
	
	if(BTActiveZone == 0) //��������� ����
	{
		if(BTTime == BTZone[BTStage][PZoneTime])
		{
	    	ChangeCenter(BTStage);
			UpdFirstZone(BTZone[BTStage][ZoneSize], CenX, CenY, -1);
			foreach(Player,eid)
			{
				if (BTStarted[eid] == 1)
   				{
			    	for (new i; i<4; i++) GangZoneShowForPlayer(eid, FirstZone[i], 0xFFFFFFFF);
			    	if (GetPVarInt(eid,"UseMap") > 0) for (new i; i<4; i++) TextDrawShowForPlayer(eid, FirstZoneTD[i]);
			    	SendClientMessage(eid,COLOR_YELLOW,"����������� � ������� ����, ������������ �� ����� {ffffff}����� ���������");
			    	GameTextForPlayer(eid, "~w~Follow in zone",3000,4);
			    }
			}
		}
		if(BTTime < 301) TextDrawSetString(BTTimeTD, TimeConvert(BTTime));
		if(BTTime == 0)
		{//���������, ������� ����� �������� � ������� �� � � �
			new Float:ZTime = float(BTZone[BTStage][AZoneTime]);
			SecDeleteS = (BTZone[BTStage-1][ZoneSize] - BTZone[BTStage][ZoneSize]) / ZTime; LineSize = 0.0; LineUpd = 102.0/ZTime;
			if(BOldX - CenX > 0) SecDeleteX = -( floatabs(BOldX-CenX)/ZTime ); else SecDeleteX = floatabs(BOldX-CenX)/ZTime;
			if(BOldY - CenY > 0) SecDeleteY = -( floatabs(BOldY-CenY)/ZTime ); else SecDeleteY = floatabs(BOldY-CenY)/ZTime;
			BTActiveZone = 1; BTTime = BTZone[BTStage][AZoneTime];
			TextDrawSetString(BTTimeTD, "~r~~h~Zone!");
		}//���������, ������� ����� �������� � ������� �� � � �
	}
	else if (BTActiveZone == 1) //���� �������
	{
		LineSize += LineUpd;
   		TextDrawHideForAll(BTLineTD);
   		TextDrawTextSize(BTLineTD, LineSize, 6.0);
   		//������ ����
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
		if(BTTime == 0)
		{
	   		TextDrawHideForAll(BTLineTD);
	    	BTStage++;
	    	if(BTStage == 10) {BTActiveZone = -1; BTStage = 9;}
	    	else {BTActiveZone = 0; BTTime = BTZone[BTStage][PZoneTime]+1;}
			
		}
	}
}//�� ����� ����������

if(BTTimer == 1)
{//�����
	if (BTPlayers < 5) //5 ����
	{//�� ��������
		SendClientMessageToAll(COLOR_BATTLE,"����� �� ���������� �� ��������, ��� ��� �� ������� ���������� (�������:{FFFFFF} 5{01DF01})");
		foreach(Player, eid)
		{//����
			if (JoinEvent[eid] == EVENT_BATTLE)
			{//������������ ��������
				JoinEvent[eid] = 0; InEvent[eid] = 0; BTStarted[eid] = 0;
			}//������������ ��������
		}//����
		BTTimer = 180; //BTTimeToEnd = 0;
	}//�� ��������
	else
	{//����������
	    //CreatePlaneRoute();
		//SetObjectPos(PlaneObject[0], BTRouts[ffX], BTRouts[ffY], 1200.0);
		//SetObjectRot(PlaneObject[0], 0.0, 0.0, BTRouts[ftoA]);
	    
	    
	    for(new i; i<MAX_AREAS; i++) {if(IsValidDynamicArea(i) && AreaType[i] == 3) DestroyLoot(i);}

	    CreateBTLoot();
	    UpdSecondZone(6000.0, 0.0, 0.0, 58111);
	    
	    TextDrawSetString(BTTimeTD, "Wait");
	    TextDrawTextSize(BTLineTD, 1.000000, 6.000000);
		new String[140];
		format (String, sizeof(String),"Players: %d", BTPlayers);
		TextDrawSetString(BTPlayersTD, String);
		
		foreach(Player, cid)
		{//���� ��� ����������
			if (JoinEvent[cid] == EVENT_BATTLE)
			{//���� ����� � evente
				StopFly(cid);StopVehFly(cid);
				ResetPlayerWeapons(cid);LACSH[cid] = 3;
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_BATTLE]);
				HideClanZones(cid);
				Player[cid][CarActive] = 0; //���������� ��� � �������������� �������
				RemovePlayerFromVehicle(cid);
				SetPlayerInterior(cid,0);SetPlayerVirtualWorld(cid, BATTLE_WORLD);
				SetPlayerArmour(cid, 0);
				BTStarted[cid] = 1;
				LAFK[cid] = 0;
				Player[cid][CarActive] = 0;
    			SetPVarInt(cid, "inplane", 1);
				SetPlayerPos(cid, BTRouts[ffX], BTRouts[ffY], 1200.0);
				
				//SetPlayerCameraPos(cid,BTRouts[BTRouteID][ffX], BTRouts[BTRouteID][ffY],1200.0);
				//SetPlayerCameraLookAt(cid,BTRouts[BTRouteID][ftoX], BTRouts[BTRouteID][ftoY], 1200.0);
				//SetCameraBehindPlayer(cid);
				//TogglePlayerControllable(eid,1);
				TogglePlayerSpectating(cid, 1); AttachCameraToObject(cid, PlaneObject[1]);

				ApplyAnimation(cid, "BOMBER", "BOM_Plant", 4.0, 0, 0, 0, 0, 500); ApplyAnimation(cid, "COP_AMBIENT", "COPBROWSE_IN", 4.1, false, false, false, false, 500); //��������� ������
    			SetPVarInt(cid, "PLoot", -1);  //SetPVarInt(cid, "PBLoot", -1);
    			SetPVarInt(cid,"UseMap",1); TextDrawShowForPlayer(cid, BTMap);
				for(new i;i<3;i++) TextDrawShowForPlayer(cid, BTMainTD[i]);
				TextDrawShowForPlayer(cid, BTTimeTD); TextDrawShowForPlayer(cid, BTLineTD); TextDrawShowForPlayer(cid, BTPlayersTD);
                BTKills[cid] = 0;
				//������ ���������
    			for(new i;i<4;i++) PlayerInv[cid][i] = -1;
    			Slot1Bullets[cid] = 0; Slot2Bullets[cid] = 0; ThrowCount[cid] = 0; SetPVarInt(cid, "BThls", 0);
			}//���� ����� � evente
		}//���� ��� ����������
		BTTimer = -1; BTStartTime = unixtime; OldSize=6000.0; BOldX=0.0; BOldY=0.0; CenX=0.0; CenY=0.0; BTTime = 400; BTStage = 1; //BTTimeToEnd = 2040;
		BTStartPlayers = BTPlayers; BTActiveZone = 0;
		format (String, sizeof(String),"����� �� ���������� ��������. �������: {FFFFFF}%d{01DF01}.", BTPlayers);
		SendClientMessageToAll(COLOR_BATTLE,String);
		//��������� �������
		MoveObject(PlaneObject[0], BTRouts[ftoX], BTRouts[ftoY], 1200.0, 85.0);
	}//����������

}//�����
