	if (DMTimer > 0)
	{
		DMTimer--; new String[60];
		format(String, sizeof String, "DEATHMATCH:~w~ %d sec. Players: %d", DMTimer, DMPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_DM], String);
	}
	if (DMTimeToEnd >= 0) DMTimeToEnd--;
	if (DMTimer <= 0 && DMTimeToEnd < 0)
	{//������� �� (�� ���� ����������, ���� �� ���������)
		DMTimer = GetEventRestartTime();
		while (PrevDM == DMid) DMid = random(20) + 1; //����� ����� ����� ��� ��
		PrevDM = DMid;
	}//������� �� (�� ���� ����������, ���� �� ���������)
	if (DMTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| ������� [{FFFFFF}%s{FF8C00}] �������� ����� {FFFFFF}������{FF8C00}!",DMName[DMid]);SendClientMessageToAll(COLOR_DM,string);
		SendClientMessageToAll(COLOR_DM,"| ����������� {FFFFFF}/dm{FF8C00} ���� ������ �����������");
	}

	if (DMTimer == 1)
	{//����� ��
		new String[140];
		if (DMPlayers < 2)
		{//���� ����������
			format(String,sizeof(String),"������� <<{FFFFFF}%s{FF8C00}>> �� �������, ��� ��� �� ������� ���������� (�������:{FFFFFF} 2{FF8C00})",DMName[DMid]);
			SendClientMessageToAll(COLOR_DM,String);
		}//���� ����������
		else
		{//���������� ����������
			format(String,sizeof(String),"������� <<{FFFFFF}%s{FF8C00}>> �������. �������: {FFFFFF}%d",DMName[DMid], DMPlayers);
			SendClientMessageToAll(COLOR_DM,String);
			DMTimeToEnd = 180; DMLeaderID = -1; DMLeaderKills = 0;
			for (new i = 0; i < MAX_PLAYERS; i++)
			{//���� (����� ����������� ������������ ������� for, � �� foreach)
				DMKills[i] = 0;
				if(JoinEvent[i] == EVENT_DM)
				{
					if (OnFly[i]) StopFly(i);//���������� ��� ��� ������ �� � ������ ���������
					OnStartEvent[i] = 5; LSpawnPlayer(i);
					TextDrawHideForPlayer(i, TextDrawEvent[EVENT_DM]);
					HideClanZones(i);
					AdminTPCantKill[i] = 0; //���������� ���, ����� ������ ���� ��������� �������� ����� ������������ - ��������� ��� ������ ������������
				}
			}//���� (����� ����������� ������������ ������� for, � �� foreach)
		}//���������� ����������
	}//����� ��	

	if (DMTimeToEnd == 0)
	{//����� ��
		new BonusXP, BonusCash, String[140];
		foreach(Player, did)
		{//����
			if(JoinEvent[did] == EVENT_DM)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0; InEvent[did] = 0; LSpawnPlayer(did);
				
				//50XP ������ ���� ���������� ��������
				//�� ������ 10 ������� ������ �� 25��, �� ����������� 20 ������� �� 20��, �� ����������� 15 ������ �� 10��
				//����� �� 45 ������� ����� ������� 850��. ���������� �������� ������� ��� 150�� �� ������.
				if (DMKills[did] <= 10) BonusXP = 50 + DMKills[did] * 25; //0 - 10 �������
				else if (DMKills[did] <= 30) BonusXP = 300 + (DMKills[did] - 10) * 20;//11 - 30 �������
				else if (DMKills[did] <= 45) BonusXP = 700 + (DMKills[did] - 30) * 10;//31 - 45 �������
				else BonusXP = 850;//����� 45 �������
				BonusCash = 5000 + DMKills[did] * 250;//�� 250$ �� ��������
				if (did == DMLeaderID)
				{//���������� ��������
					BonusXP += 150; BonusCash += 15000;
					MarafonUpdate(did, 2, 1);
					format(String, sizeof String, "%s[%d] ������� � �������� � %d ���������� � ������� %d XP � %d$", PlayerName[did], did, DMLeaderKills, BonusXP, BonusCash);
					SendClientMessageToAll(COLOR_DM, String);
				}//���������� ��������
				format(String,sizeof String,"�� �������� %d �� � %d$ �� ������� � �������� (�������: %d).", BonusXP, BonusCash, DMKills[did]);
				SendClientMessage(did,COLOR_YELLOW,String);
				MarafonUpdate(did, 5, BonusCash);
				MarafonUpdate(did, 0, 1);
				LGiveXP(did, BonusXP); Player[did][Cash] += BonusCash;
				QuestUpdate(did, 11, 1);//���������� ������ ������� ������� � 3 ��
				QuestUpdate(did, 18, 1);//���������� ������ ������� ������� � 5 �������������
				ShowClanZones(did); // ������� �������� ����
				//MarafonUpdate(did);
			}
		}//����
		format(String,sizeof(String),"������� <<{FFFFFF}%s{FF8C00}>> ����������",DMName[DMid]); 
		SendClientMessageToAll(COLOR_DM,String);
	}//����� ��
	
