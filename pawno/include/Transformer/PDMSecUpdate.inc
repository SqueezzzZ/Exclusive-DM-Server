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
	{//������� ��� (�� ���� ����������, ���� �� ���������)
		PDMTimer = GetEventRestartTime();
		while (PrevPDM == PDMid) PDMid = random(MAX_PDM) + 1; //����� ����� ����� ��� ���
		PrevPDM = PDMid;
	}//������� ��� (�� ���� ����������, ���� �� ���������)
	if (PDMTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| ������ ����� [{FFFFFF}%s{58FA82}] �������� ����� {FFFFFF}������{58FA82}!", PDMName[PDMid]); SendClientMessageToAll(COLOR_PDM, string);
		SendClientMessageToAll(COLOR_PDM, "| ����������� {FFFFFF}/point{58FA82}, ���� ������ �����������.");
	}
	//��� �� ����� XP � ��������� ������� ������������
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
	{//����� ���
		new String[140];
		if (PDMPlayers < 1) //���� < 2
		{//���� ����������
			format(String,sizeof(String),"������ ����� <<{FFFFFF}%s{58FA82}>> �� �������, ��� ��� �� ������� ���������� (�������:{FFFFFF} 2{58FA82})", PDMName[PDMid]);
			SendClientMessageToAll(COLOR_PDM, String);
			foreach(Player, cid) if (JoinEvent[cid] == EVENT_PDM) {JoinEvent[cid] = 0; TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_PDM]);} //����������� ������, ����� ����� � ���������� ������������ � �� ����� �� ���� �����
		}//���� ����������
		else
		{//���������� ����������
			format(String,sizeof(String),"������ ����� <<{FFFFFF}%s{58FA82}>> �������. �������: {FFFFFF}%d", PDMName[PDMid], PDMPlayers);
			SendClientMessageToAll(COLOR_PDM,String);
			PDMTimeToEnd = 180; PDMBluePnt = 0; PDMRedPnt = 0;
			new nextTeam = 1;
			PDMBlue = 0; PDMRed = 0;
			for (new i = 0; i < MAX_PLAYERS; i++)
			{//���� (����� ����������� ������������ ������� for, � �� foreach)
				PDMKills[i] = 0; PDMTeam[i] = 0;
				if(JoinEvent[i] == EVENT_PDM)
				{
					if (LastPlayerTuneStatus[i] > 0) 
					{
						SendClientMessage(i, COLOR_RED, "�� ������� ����������� ��� �� ����� ������������, ��� ��� �� ���������� � �������������� �� ����� ������!"); 
						JoinEvent[i] = 0;TextDrawHideForPlayer(i, TextDrawEvent[EVENT_PDM]);  continue;
					}
					if (OnFly[i]) StopFly(i);//���������� ��� ��� ������ ��� � ������ ���������
					InEvent[i] = EVENT_PDM; SetPlayerArmour(i, 0);
					OnStartEvent[i] = 5; ClearAnimations(i);
					//PDMStarted[i] = 1;
					AdminTPCantKill[i] = 0; //���������� ���, ����� ������ ���� ��������� �������� ����� ������������ - ��������� ��� ������ ������������
					if (nextTeam == 1) {PDMTeam[i] = 1; nextTeam = 2; PDMBlue++;} //grove
					else {PDMTeam[i] = 2; nextTeam = 1; PDMRed++;} //ballas
					LSpawnPlayer(i); //UpdateColor(i);
					HideClanZones(i); //�������� ����
				}
			}//���� (����� ����������� ������������ ������� for, � �� foreach)
			DestroyDynamicArea(PDMArea);
			PDMArea = CreateDynamicCircle(PDMPoint[PDMid][0], PDMPoint[PDMid][1], 20.0, PDM_WORLD);
			ObjStatus = 0; DestroyDynamicObject(PDMObject);
		}//���������� ����������
	}//����� ���	

	if (PDMTimeToEnd == 0)
	{//����� ���
		new BonusXP, BonusCash, String[140];
		format(String, sizeof String, "������ ����� <<{FFFFFF}%s{58FA82}>> ����������", PDMName[PDMid]); SendClientMessageToAll(COLOR_PDM, String);
		if (PDMBluePnt > PDMRedPnt)
		{
			format(String, sizeof String, "������ ������� {5882FA}�����{58FA82} �������� ����� � ������� 300 �� � 8 000$ �� ������ (���� %d:%d)", PDMBluePnt, PDMRedPnt);
			SendClientMessageToAll(COLOR_PDM, String);
		}
		else if (PDMBluePnt < PDMRedPnt)
		{
			format(String, sizeof String, "������ ������� {FA5882}�������{58FA82} �������� ����� � ������� 300 �� � 8 000$ �� ������ (���� %d:%d)", PDMRedPnt, PDMBluePnt);
			SendClientMessageToAll(COLOR_PDM, String);
		}
		else if (PDMBluePnt == PDMRedPnt)
		{
			format(String, sizeof String,"������� ������� � ����� � �������� ����� � ������� 150 XP � 4 000$ (���� %d:%d)", PDMBluePnt, PDMRedPnt);
			SendClientMessageToAll(COLOR_PDM, String);
		}
		
		foreach(Player, did)
		{//����
			if(JoinEvent[did] == EVENT_PDM)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0; InEvent[did] = 0; LSpawnPlayer(did); //UpdateColor(did);
                ShowClanZones(did); // ������� �������� ����
				//100XP ������ ���� ���������� ��������� ��������
				//�� ������ �������� ������ �� 30 xp. ����� �� 20 ������� ����� ������� 700 XP.
				//���������� ������� ������� ��� 300�� �� ������. � ������ ����� ��� ������� ������� �� 150 XP.
				if (PDMKills[did] <= 20) BonusXP = 100 + PDMKills[did] * 30;
				else BonusXP = 700;//����� 20 �������
				BonusCash = 4000 + PDMKills[did] * 500;//�� 500$ �� ��������
			
				if (PDMBluePnt > PDMRedPnt && PDMTeam[did] == 1) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else if (PDMBluePnt < PDMRedPnt && PDMTeam[did] == 2) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else {BonusXP += 150; BonusCash += 4000;}
				BonusXP += FarmedXP[did];
				format(String,sizeof String,"�� �������� %d �� � %d$ �� ������� � ������� ����� (�������: %d).", BonusXP, BonusCash, PDMKills[did]);
				SendClientMessage(did, COLOR_YELLOW, String);
				LGiveXP(did, BonusXP);
				Player[did][Cash] += BonusCash;
				QuestUpdate(did, 28, 1);//���������� ������ ������� ������� � 3 ���
				QuestUpdate(did, 18, 1);//���������� ������ ������� ������� � 5 �������������
				MarafonUpdate(did, 0, 1); //������
				MarafonUpdate(did, 5, BonusCash);//����
				//DayQuestEventsUpdate(did);//���������� ����������� ������ ������� ������� � 25 �������������
				TextDrawHideForPlayer(did, TextDrawEvent[EVENT_PDM]);
				FarmedXP[did] = 0;
			}
		}//����
	}//����� ���
	