if (DerbyTimer > -7) 
{
	DerbyTimer--; new String[60];
	format(String, sizeof String, "DERBY:~w~ %d sec. Players: %d", DerbyTimer, DerbyPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_DERBY], String);
}
if (DerbyTimer == 0)//����� �� ��������
{
	DerbyTimer = GetEventRestartTime();
	SendClientMessageToAll(COLOR_DERBY,"����� �� ��������, ��� ��� ������ �� ���� �� ������.");
	while (PrevDerby == Derbyid) Derbyid = random(MAX_DERBYS) + 1;
	PrevDerby = Derbyid;
	//����� ������ ���� ��� �����, ��� ��� � ���� ����������
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
	for(new cid = 0; cid < MAX_PLAYERS; cid++) DerbyModelCar[cid] = DerbyModelAll; //����������� ������� for
}//������ 40 �����
if (DerbyTimeToEnd >= 0) DerbyTimeToEnd--;

if (DerbyTimer == 60)
{
	new String[140];
	//if(Derbyid == 19){format (String, sizeof(String),"����� <<{FF0000}%s{9966CC}>> �������� ����� {FF0000}������{9966CC}!", DerbyName[Derbyid]);}
	format (String, sizeof(String),"| ����� [{FFFFFF}%s{9966CC}] �������� ����� {FFFFFF}������{9966CC}!", DerbyName[Derbyid]);
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
	if (dscan == true) DState = "����������";
	else DState = "���������";
	format (String, sizeof(String),"| ���������: {FFFFFF}%s{9966CC}. ����������� {FFFFFF}/derby{9966CC}, ���� ������ �����������", DState);
	SendClientMessageToAll(COLOR_DERBY,String);
}



if (DerbyTimer <= -1 && DerbyTimer >= -6)
{//��� ������� ����� ������
	foreach(Player, eid)
	{//����
		if (DerbyTimer == -2 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "4",1000,6);TogglePlayerControllable(eid,0);}
		if (DerbyTimer == -3 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "3",1000,6);}
		if (DerbyTimer == -4 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (DerbyTimer == -5 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6); SetVehicleHealth(DerbyCarID[eid],650.0);}
		if (DerbyTimer == -6 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0){PlayerPlaySound(eid,1057,0.0,0.0,0.0);GameTextForPlayer(eid, "GO",1000,6);TogglePlayerControllable(eid,1);ResetPlayerWeapons(eid);}

		if (DerbyTimer <= -1 && DerbyTimer >= -3 && DerbyStarted[eid] == 1 && DerbyTimeToEnd >= 0)
		{//����������� ���� ����� �� � ����� ���� ��� �����
			if (IsPlayerInAnyVehicle(eid))
			{//����� ��� � �����-�� ����
				if (GetPlayerVehicleID(eid) != DerbyCarID[eid])
				{//����� � ����, �� �� � ���, � ������� ������ ���� (��� ��� ���)
					DerbyStarted[eid] = 0; JoinEvent[eid] = 0; InEvent[eid] = 0;
					DestroyVehicle(GetPlayerVehicleID(eid)); LSpawnPlayer(eid);
					ShowClanZones(eid); // ������� �������� ����
				}//����� � ����, �� �� � ���, � ������� ������ ���� (��� ��� ���)
			}//����� ��� � �����-�� ����
			else
			{//����� ��� ����
				if (DerbyCarID[eid] == -1)
				{//��������� ��� ������ ��� �� ������
					new randcolor1 = random(200);
					new randcolor2 = random(200);
					new Float: drx, Float: dry, Float: drz, Float: dra;
					GetPlayerPos(eid, drx, dry, drz);
					GetPlayerFacingAngle(eid, dra);
					DerbyCarID[eid] = LCreateVehicle(DerbyModelCar[eid],drx, dry, drz,dra, randcolor1, randcolor2);
					SetVehicleHealth(DerbyCarID[eid],650.0);//�������
					LinkVehicleToInterior(DerbyCarID[eid], GetPlayerInterior(eid));
					SetVehicleVirtualWorld(DerbyCarID[eid], 664);
					SetPlayerVirtualWorld(eid, 664);
					PutPlayerInVehicle(eid, DerbyCarID[eid], 0);
					SpecUpdate(eid);
					new rand = random(3);
					ChangeVehiclePaintjob(GetPlayerVehicleID(eid), rand);//��������� paintjob
				}//��������� ��� ������ ��� �� ������
				else
				{//��������� ��� ������ ��� ������
					SetPlayerVirtualWorld(eid, 664);
					PutPlayerInVehicle(eid, DerbyCarID[eid], 0);
				}//��������� ��� ������ ��� ������
			}//����� ��� ����
		}//����������� ���� ����� �� � ����� ���� ��� �����
	}//����
}//��� ������� ����� ������

if (DerbyTimer <= -7)
{//�� ����� ���������� �����
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
                default: printf("������ �������! ��� ����� ������� ��� �����!");
        	}
	    }
    }*/
	//----
	new eid, String[140], Float: dx, Float: dy, Float: dz;
	for (new i = 0; i < 25; i++) 
	{//���� ��� ���������� �����
		eid = DerbyPlayersList[i];
		if (!IsPlayerConnected(eid) || DerbyStarted[eid] == 0) continue;

		GetPlayerPos(eid,dx,dy,dz);
		if (Derbyid < 3 && dz < 1039) DestroyVehicle(DerbyCarID[eid]);//������� � �����
		if (Derbyid == 5 && dz < 9.5) DestroyVehicle(DerbyCarID[eid]);//������� � ����� �� ����� "�� �����"zs
		if (Derbyid == 6 && dz < 2.0) DestroyVehicle(DerbyCarID[eid]);//������� � ����� �� ����� "��� ��������"
		if (Derbyid == 7 && dz < 0.5) DestroyVehicle(DerbyCarID[eid]);//������� � ����� �� ����� "�����������"
		if (Derbyid == 8 && dz < 135) DestroyVehicle(DerbyCarID[eid]);//������� � ����� �� ����� "���� �����"
		if (Derbyid == 9 && (dx < 1667.7567 || dx > 1931.5044 || dy < -2695.9065 || dy > -2388.4578 || dz < 13 || dz > 40)) DestroyVehicle(DerbyCarID[eid]);//������� � ����� �� ����� "World Of Tanks"
		if (Derbyid == 10 && dz < 2037.6762) DestroyVehicle(DerbyCarID[eid]); //����� �� �� ���������
		if (Derbyid == 11 && dz < 222.6) DestroyVehicle(DerbyCarID[eid]); //����� �� ��������� �������
		if (Derbyid == 12 && dz < 1003.0) DestroyVehicle(DerbyCarID[eid]); //����� �����
		if (Derbyid == 13 && dz < 950.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 14 && dz < 1.09) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 15 && dz < 1017.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 16 && dz < 1949.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 17 && dz < 2879.0) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 19 && dz < 1533.5) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 20 && dz <  3199.12) DestroyVehicle(DerbyCarID[eid]);
		if (Derbyid == 21 && dz < 2170.89) DestroyVehicle(DerbyCarID[eid]);
		//if (Derbyid == 19 && dz < 143.5) DestroyVehicle(DerbyCarID[eid]);
		if (LAFK[eid] >= 3){SendClientMessage(eid,COLOR_RED,"�� ���� ��������� �� ����� �� AFK!"); JoinEvent[eid] = 0; InEvent[eid] = 0; DerbyStarted[eid] = 0; SetPlayerVirtualWorld(eid, 0); LSpawnPlayer(eid); ShowClanZones(eid);}
		
		if ((!IsPlayerInVehicle(eid,DerbyCarID[eid]) && DerbyPlayers > 1) || DerbyTimeToEnd == 1)///���� ����� �� �� ����� ���� �������� �����
		{//���� ����� �� ���� ��� ����� �� �������
			JoinEvent[eid] = 0; InEvent[eid] = 0; DerbyStarted[eid] = 0; 
			if (DerbyPosition < 9){FarmedXP[eid] = 100 + DerbyPosition*45;}//�� ����� 8 �������: 100 + 360
			if (DerbyPosition < 17 && DerbyPosition > 8){new x = DerbyPosition - 8;FarmedXP[eid] = 100 + 360 + x*30;}//�� 9 �� 16 �������: 100 + 360 �� ������ 8, � �� ����������� �� 30
			if (DerbyPosition >= 17){new x = DerbyPosition - 16;FarmedXP[eid] = 100 + 360 + 240 + x*20;}
			FarmedMoney[eid] = 5000 + 650*DerbyPosition;
			if (DerbyPlayers == 2){FarmedXP[eid] += 140;}//������ �� �������� �����
			if (DerbyPlayers == 3){FarmedXP[eid] += 85;}//������ �� �������� �����
			if (FarmedXP[eid] > 1000){FarmedXP[eid] = 1000;}//����� �� 1000 ��

			/*if(Derbyid == 19)
			{
				FarmedXP[eid] = FarmedXP[eid]*2;
                FarmedMoney[eid] = FarmedMoney[eid]*2;
			}*/
			
			MarafonUpdate(eid, 0, 1);
			//MarafonUpdate(eid, 1, FarmedXP[eid]);
			MarafonUpdate(eid, 5, FarmedMoney[eid]);
			
			
			LGiveXP(eid, FarmedXP[eid]); Player[eid][Cash] += FarmedMoney[eid];
			format(String,sizeof(String),"�� ������� � ����� �� �������� %dXP � %d$. �� ������: %d-�� �����",FarmedXP[eid],FarmedMoney[eid],DerbyPlayers);
			SendClientMessage(eid,COLOR_YELLOW,String);
			if (DerbyPlayers == 3){format(String,sizeof(String),"%s[%d] ����� ������ ����� � ����� � ������� %d XP � %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DERBY,String);}
			if (DerbyPlayers == 2){format(String,sizeof(String),"%s[%d] ����� ������ ����� � ����� � ������� %d XP � %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DERBY,String);}
			DestroyVehicle(DerbyCarID[eid]); DerbyCarID[eid] = 0; DerbyPosition += 1; DerbyPlayers--;
			QuestUpdate(eid, 12, 1);//���������� ������ ������� ������� � 3 �����
			QuestUpdate(eid, 18, 1);//���������� ������ ������� ������� � 5 �������������
			ShowClanZones(eid); // ������� �������� ����
			ResetPlayerWeapons(eid); LSpawnPlayer(eid); continue;
		}//���� ����� �� ���� ��� ����� �� �������
		if (DerbyStarted[eid] == 1 && DerbyPlayers == 1) // == 1
		{//��������� ��������
			JoinEvent[eid] = 0; DerbyStarted[eid] = 0; 
			if (DerbyPosition < 9){FarmedXP[eid] = 300 + DerbyPosition*45;}//�� ����� 8 �������: 300 + 360
			if (DerbyPosition < 17 && DerbyPosition > 8){new x = DerbyPosition - 8;FarmedXP[eid] = 300 + 360 + x*30;}//�� 9 �� 16 �������: 300 + 360 �� ������ 8, � �� ����������� �� 30
			if (DerbyPosition >= 17){new x = DerbyPosition - 16;FarmedXP[eid] = 300 + 360 + 240 + x*20;}
			FarmedMoney[eid] = 5000 + 650*DerbyPosition;			
			FarmedMoney[eid] = 5000 + 650*DerbyPosition;if (FarmedXP[eid] > 1000){FarmedXP[eid] = 1000;}//����� �� 1000 �� (1200 ������ � ��������� �������)

            /*if(Derbyid == 19)
			{
				FarmedXP[eid] = FarmedXP[eid]*2;
                FarmedMoney[eid] = FarmedMoney[eid]*2;
			}*/

			MarafonUpdate(eid, 0, 1);
			MarafonUpdate(eid, 2, 1);
			MarafonUpdate(eid, 5, FarmedMoney[eid]);

			LGiveXP(eid, FarmedXP[eid]); Player[eid][Cash] += FarmedMoney[eid];
			format(String,sizeof(String),"�� ������� � ����� �� �������� %dXP � %d$. �� ������: %d-�� �����",FarmedXP[eid],FarmedMoney[eid],DerbyPlayers);
			SendClientMessage(eid,COLOR_YELLOW,String);
			format(String,sizeof(String),"%s[%d] ������� � ����� � ������� %d XP � %d$",PlayerName[eid], eid, FarmedXP[eid], FarmedMoney[eid]); SendClientMessageToAll(COLOR_DERBY,String);
			DestroyVehicle(DerbyCarID[eid]);DerbyCarID[eid] = 0;DerbyPosition += 1;
			QuestUpdate(eid, 12, 1);//���������� ������ ������� ������� � 3 �����
			QuestUpdate(eid, 18, 1);//���������� ������ ������� ������� � 5 �������������
			//MarafonUpdate(eid, 1, 0, FarmedMoney[eid], FarmedXP[eid]);
			ShowClanZones(eid); // ������� �������� ����
			ResetPlayerWeapons(eid); LSpawnPlayer(eid); continue;
		}//��������� ��������
		
		/*GetVehicleHealth(GetPlayerVehicleID(eid), dchealth);
		if (dchealth <= 250.0 && JoinEvent[eid] == EVENT_DERBY) DestroyVehicle(DerbyCarID[eid]);//���������� ��������� �������� � ����
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
	}//���� ��� ���������� �����

	if (DerbyPlayers == 0)
	{
		DerbyTimeToEnd = 0;
		SendClientMessageToAll(COLOR_DERBY,"����� ���������.");
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
		//����� ������ ���� ��� �����, ��� ��� � ���� ����������
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
		for(new cid = 0; cid < MAX_PLAYERS; cid++) DerbyModelCar[cid] = DerbyModelAll; //����������� ������� for
	}
}//�� ����� ���������� �����

if(DerbyTimer == 1)
{//����� �����
	if (DerbyPlayers < 2)//< 2
	{//����� �� ��������
		SendClientMessageToAll(COLOR_DERBY,"����� �� ��������, ��� ��� �� ������� ���������� (�������:{FFFFFF} 2{9966CC})");
		foreach(Player, eid)
		{//����
			if (JoinEvent[eid] == EVENT_DERBY)
			{//������������ ��������
				JoinEvent[eid] = 0; InEvent[eid] = 0; DerbyStarted[eid] = 0;
			}//������������ ��������
		}//����
		DerbyTimer = GetEventRestartTime(); DerbyTimeToEnd = 0;
	}//����� �� ��������
	else
	{//����� ����������
		for (new i = 0; i < 25; i++) DerbyPlayersList[i] = -1;//������� ������ ������� �� �����
		new i = 0; //���� ��������� ������ ������� �� �����
		foreach(Player, cid) if (JoinEvent[cid] == EVENT_DERBY) {DerbyPlayersList[i] = cid; i++;}
		
		DerbyTimer = -1; DerbyPosition = 1; DerbyTimeToEnd = 900;
		
		new cid, SpawnNumber = 0, String[140];
		for (i = 0; i < 25; i++) 
		{//���� ��� ���������� �����
			cid = DerbyPlayersList[i];
			if (!IsPlayerConnected(cid)) continue;
			
			if (JoinEvent[cid] == EVENT_DERBY)
			{//���� ����� � �����
				StopFly(cid);StopVehFly(cid);
				ResetPlayerWeapons(cid);LACSH[cid] = 3;
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_DERBY]);
				HideClanZones(cid);
				Player[cid][CarActive] = 0; //���������� ��� � �������������� ������� � �����
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
						new modelid = random(123);DerbyModelCar[cid] = DerbyCars[modelid];//����� ������ ����					
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
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//����� ������ ����					
						SetPlayerPos(cid, DERBY2SPAWN[SpawnNumber][0], DERBY2SPAWN[SpawnNumber][1],DERBY2SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY2SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 15);
					}
					case 5:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//����� ������ ����					
						SetPlayerPos(cid, DERBY5SPAWN[SpawnNumber][0], DERBY5SPAWN[SpawnNumber][1],DERBY5SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY5SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 6:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//����� ������ ����					
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
						new modelid = random(123);DerbyModelCar[cid] = DerbyCars[modelid];//����� ������ ����					
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
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//����� ������ ����
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
						new modelid = random(sizeof(DerbyJeeps));DerbyModelCar[cid] = DerbyJeeps[modelid];//����� ������ ����
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
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//����� ������ ����
						SetPlayerPos(cid, DERBY16SPAWN[SpawnNumber][0], DERBY16SPAWN[SpawnNumber][1],DERBY16SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY16SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 17:
					{
						new modelid = random(76);DerbyModelCar[cid] = DerbyCars2[modelid];//����� ������ ����
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
						new modelid = random(sizeof(DerbyJeeps));DerbyModelCar[cid] = DerbyJeeps[modelid];//����� ������ ����
						SetPlayerPos(cid,DERBY19SPAWN[SpawnNumber][0], DERBY19SPAWN[SpawnNumber][1],DERBY19SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY19SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 20:
					{
						new modelid = random(123);DerbyModelCar[cid] = DerbyCars[modelid];//����� ������ ����
						SetPlayerPos(cid, DERBY20SPAWN[SpawnNumber][0], DERBY20SPAWN[SpawnNumber][1],DERBY20SPAWN[SpawnNumber][2]); SetPlayerFacingAngle(cid, DERBY20SPAWN[SpawnNumber][3]);
						SetPlayerInterior(cid, 0);
					}
					case 21:
					{
						new modelid = random(sizeof(DRFastCars));DerbyModelCar[cid] = DRFastCars[modelid];//����� ������ ����
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
				SpawnNumber++;//����� ������ ����� ����������� ��� � ������ �����
			}//���� ����� � �����
		}//���� ��� ���������� �����
        //DRemStats[PCTime]=870;
        //DRemStats[IsRActived] = 0;
		format (String, sizeof(String),"����� <<{FFFFFF}%s{9966CC}>> ��������. �������: {FFFFFF}%d",DerbyName[Derbyid], DerbyPlayers);
		SendClientMessageToAll(COLOR_DERBY,String);		
	}//����� ����������

}//����� �����
