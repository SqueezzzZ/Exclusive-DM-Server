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
	{//������� ��� (�� ���� ����������, ���� �� ���������)
		TDMTimer = GetEventRestartTime();
		while (PrevTDM == TDMid) TDMid = random(MAX_TDM) + 1; //����� ����� ����� ��� ���
		PrevTDM = TDMid;
	}//������� ��� (�� ���� ����������, ���� �� ���������)
	if (TDMTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| ��������� ������� [{FFFFFF}%s{04B486}] �������� ����� {FFFFFF}������{04B486}!", TDMName[TDMid]); SendClientMessageToAll(COLOR_TDM, string);
		SendClientMessageToAll(COLOR_TDM, "| ����������� {FFFFFF}/tdm{04B486}, ���� ������ �����������.");
	}
	//��� �� ����� XP � ��������� ������� ������������
	if (TDMTimeToEnd == 2) foreach(Player, cid) if (InEvent[cid] == EVENT_TDM) EndEventFreeze(cid);

	if (TDMTimer == 1)
	{//����� ���
		new String[140];
		if (TDMPlayers < 2)
		{//���� ����������
			format(String,sizeof(String),"��������� ������� <<{FFFFFF}%s{04B486}>> �� �������, ��� ��� �� ������� ���������� (�������:{FFFFFF} 2{04B486})", TDMName[TDMid]);
			SendClientMessageToAll(COLOR_TDM, String);
			foreach(Player, cid) if (JoinEvent[cid] == EVENT_TDM) {JoinEvent[cid] = 0; TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_TDM]);} //����������� ������, ����� ����� � ���������� ������������ � �� ����� �� ���� �����
		}//���� ����������
		else
		{//���������� ����������
			format(String,sizeof(String),"��������� ������� <<{FFFFFF}%s{04B486}>> �������. �������: {FFFFFF}%d", TDMName[TDMid], TDMPlayers);
			SendClientMessageToAll(COLOR_TDM,String);
			TDMTimeToEnd = 180; TDMGroveKills = 0; TDMBallasKills = 0; 
			new nextTeam = 1;
			TDMGrove = 0; TDMBallas = 0;
			for (new i = 0; i < MAX_PLAYERS; i++)
			{//���� (����� ����������� ������������ ������� for, � �� foreach)
				TDMKills[i] = 0; TDMTeam[i] = 0;
				if(JoinEvent[i] == EVENT_TDM)
				{
					if (LastPlayerTuneStatus[i] > 0) 
					{
						SendClientMessage(i, COLOR_RED, "�� ������� ����������� ��� �� ����� ������������, ��� ��� �� ���������� � �������������� �� ����� ������!"); 
						JoinEvent[i] = 0;TextDrawHideForPlayer(i, TextDrawEvent[EVENT_TDM]);  continue;
					}
					if (OnFly[i]) StopFly(i);//���������� ��� ��� ������ ��� � ������ ���������
					InEvent[i] = EVENT_TDM; SetPlayerArmour(i, 0);
					OnStartEvent[i] = 5; ClearAnimations(i);
					//TDMStarted[i] = 1;
					AdminTPCantKill[i] = 0; //���������� ���, ����� ������ ���� ��������� �������� ����� ������������ - ��������� ��� ������ ������������
					if (nextTeam == 1) {TDMTeam[i] = 1; nextTeam = 2; TDMGrove++;} //grove
					else {TDMTeam[i] = 2; nextTeam = 1; TDMBallas++;} //ballas
					LSpawnPlayer(i); //UpdateColor(i);
					HideClanZones(i); //�������� ����
				}
			}//���� (����� ����������� ������������ ������� for, � �� foreach)
		}//���������� ����������
	}//����� ���	

	if (TDMTimeToEnd == 0)
	{//����� ���
		new BonusXP, BonusCash, String[140];
		format(String, sizeof String, "��������� ������� <<{FFFFFF}%s{04B486}>> ����������", TDMName[TDMid]); SendClientMessageToAll(COLOR_TDM, String);
		if (TDMGroveKills > TDMBallasKills)
		{
			format(String, sizeof String, "������ ������� {ffffff}WHITE{04B486} �������� ����� � ������� 300 �� � 8 000$ �� ������ (���� %d:%d)", TDMGroveKills, TDMBallasKills);
			SendClientMessageToAll(COLOR_TDM, String);
		}
		else if (TDMGroveKills < TDMBallasKills)
		{
			format(String, sizeof String, "������ ������� {000000}BLACK{04B486} �������� ����� � ������� 300 �� � 8 000$ �� ������ (���� %d:%d)", TDMBallasKills, TDMGroveKills);
			SendClientMessageToAll(COLOR_TDM, String);
		}
		else if (TDMGroveKills == TDMBallasKills)
		{
			format(String, sizeof String,"������� ������� � ����� � �������� ����� � ������� 150 XP � 4 000$ (���� %d:%d)", TDMGroveKills, TDMBallasKills);
			SendClientMessageToAll(COLOR_TDM, String);
		}
		
		foreach(Player, did)
		{//����
			if(JoinEvent[did] == EVENT_TDM)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0; InEvent[did] = 0; LSpawnPlayer(did); //UpdateColor(did);
                ShowClanZones(did); // ������� �������� ����
				//100XP ������ ���� ���������� ��������� ��������
				//�� ������ �������� ������ �� 30 xp. ����� �� 20 ������� ����� ������� 700 XP.
				//���������� ������� ������� ��� 300�� �� ������. � ������ ����� ��� ������� ������� �� 150 XP.
				if (TDMKills[did] <= 20) BonusXP = 100 + TDMKills[did] * 30;
				else BonusXP = 700;//����� 20 �������
				BonusCash = 4000 + TDMKills[did] * 500;//�� 500$ �� ��������
			
				if (TDMGroveKills > TDMBallasKills && TDMTeam[did] == 1) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else if (TDMGroveKills < TDMBallasKills && TDMTeam[did] == 2) {BonusXP += 300; BonusCash += 8000; MarafonUpdate(did, 2, 1);}
				else {BonusXP += 150; BonusCash += 4000;}				
				format(String,sizeof String,"�� �������� %d �� � %d$ �� ������� � ��������� �������� (�������: %d).", BonusXP, BonusCash, TDMKills[did]);
				SendClientMessage(did, COLOR_YELLOW, String);
				LGiveXP(did, BonusXP);
				Player[did][Cash] += BonusCash;
				QuestUpdate(did, 28, 1);//���������� ������ ������� ������� � 3 ���
				QuestUpdate(did, 18, 1);//���������� ������ ������� ������� � 5 �������������
				MarafonUpdate(did, 0, 1); //������
				MarafonUpdate(did, 5, BonusCash);//����
				//DayQuestEventsUpdate(did);//���������� ����������� ������ ������� ������� � 25 �������������
				TextDrawHideForPlayer(did, TextDrawEvent[EVENT_TDM]);
			}
		}//����
	}//����� ���
	
