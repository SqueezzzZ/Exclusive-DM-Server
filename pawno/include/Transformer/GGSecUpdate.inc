	if (GGTimer > 0)
	{
		GGTimer--; new String[60];
		format(String, sizeof String, "GUNGAME:~w~ %d sec. Players: %d", GGTimer, GGPlayers);
		TextDrawSetString(TextDrawEvent[EVENT_GUNGAME], String);
	}
	if (GGTimer <= 0 && GGTimeToEnd < 0)
	{
		GGTimer = GetEventRestartTime();
		while (PrevGGid == GGid) GGid = random(20) + 1; //����� ����� ����� ��� ����� ����������
		PrevGGid = GGid;
	}
	
	if (GGTimeToEnd >= 0) GGTimeToEnd--;
	if (GGTimer == 60)
	{
		new string[140];format(string,sizeof(string),"| ����� ���������� [{FFFFFF}%s{FF6666}] �������� ����� {FFFFFF}������{FF6666}!",GGName[GGid]);SendClientMessageToAll(COLOR_GG,string);
		SendClientMessageToAll(COLOR_GG,"| ����������� {FFFFFF}/gg{FF6666}, ���� ������ �����������.");
	}

	if (GGTimer == 1)
	{//�����
		new String[140];format(String,sizeof(String),"����� ���������� <<{FFFFFF}%s{FF6666}>> �� ��������, ��� ��� �� ������� ���������� (�������:{FFFFFF} 2{FF6666})",GGName[GGid]);
		if (GGPlayers < 2) SendClientMessageToAll(COLOR_GG,String);
		else
		{
			GGTimeToEnd = 1800;format(String,sizeof(String),"����� ���������� <<{FFFFFF}%s{FF6666}>> ��������. �������: {FFFFFF}%d",GGName[GGid], GGPlayers);
			SendClientMessageToAll(COLOR_GG,String);
			foreach(Player, did)
			{//����
				GGKills[did] = 0;
				if(JoinEvent[did] == EVENT_GUNGAME)
				{
					if (OnFly[did]) StopFly(did);//���������� ��� ��� ������ �� � ������ ���������
					OnStartEvent[did] = 5;LSpawnPlayer(did);FarmedXP[did] = 0;FarmedMoney[did] = 0;
					HideClanZones(did); //�������� ����
					TextDrawHideForPlayer(did, TextDrawEvent[EVENT_GUNGAME]);
					AdminTPCantKill[did] = 0; //���������� ���, ����� ������ ���� ��������� �������� ����� ������������ - ��������� ��� ������ ������������
				}
			}//����
		}
	}//�����


	if (GGTimeToEnd == 0)
	{//�����
		new String[140];
		foreach(Player, did)
		{//����
			if(JoinEvent[did] == EVENT_GUNGAME)
			{
				ResetPlayerWeapons(did);
				JoinEvent[did] = 0;LSpawnPlayer(did);LGiveXP(did, 100);
				format(String,sizeof(String),"�� �������� 100 �� �� ������� � ����� ����������. ����� �� ����� ����������: %d �� � %d$",FarmedXP[did] + 100, FarmedMoney[did]);
				SendClientMessage(did,COLOR_YELLOW,String);
				//MarafonUpdate(did, 1, 0, FarmedMoney[did], 0);
				MarafonUpdate(did, 0, 1);
				MarafonUpdate(did, 5, FarmedMoney[did]);
				ShowClanZones(did); // ������� �������� ����
			}
		}//����
		format(String,sizeof(String),"����� ���������� <<{FFFFFF}%s{FF6666}>> ����������� (����� �����).",GGName[GGid]);
		SendClientMessageToAll(COLOR_GG,String);
	}//�����	
	