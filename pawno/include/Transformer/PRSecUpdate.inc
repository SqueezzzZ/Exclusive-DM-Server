if (PRTimer != 0)
{
	PRTimer--; new String[60];
	format(String, sizeof String, "PARKOUR:~w~ %d sec. Players: %d", PRTimer, PRPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_PARK], String);
}
if (PRTimeToEnd >= 0) PRTimeToEnd--;
if (PRTimer == 0)
{
	PRTimer = GetEventRestartTime();
	while (PrevPR == PRid) PRid = random(MAX_PARK) + 1; //����� ����� �����
	PrevPR = PRid;
}
if (PRTimer == 60)
{
	new string[140];
	//if(PRid == 6) {format(string,sizeof(string),"������ <<{FF0000}%s{58FAF4}>> �������� ����� {FFFFFF}������{58FAF4}!",PRName[PRid]);SendClientMessageToAll(COLOR_PARK,string);}
	format(string,sizeof(string),"| ������ [{FFFFFF}%s{58FAF4}] �������� ����� {FFFFFF}������{58FAF4}!",PRName[PRid]);SendClientMessageToAll(COLOR_PARK,string);
	SendClientMessageToAll(COLOR_PARK,"| ����������� {FFFFFF}/park{58FAF4}, ���� ������ �����������.");
}


if (PRTimer <= -1)
{//�� ����� ����������
	new eid;
	for (new i = 0; i < 20; i++)
	{//���� ��� ����������
		eid = PRPlayersList[i];
		if (!IsPlayerConnected(eid) || PRStarted[eid] == 0) continue;
		
		if (LAFK[eid] >= 30 && PRTimeToEnd > 0)
		{
			JoinEvent[eid] = 0;PRStarted[eid] = 0;
			SendClientMessage(eid,COLOR_RED,"�� ���� ������� �� ���� �� AFK �� ������� ����� 30 ������"); DisablePlayerCheckpoint(eid);//DestroyDynamicPickup(PRPickup[eid]);
			Kick(eid); continue;
		}
		else if (LAFK[eid] >= 20 && PRTimeToEnd > 0) SendClientMessage(eid,COLOR_RED,"�� ������ ��������� �� �������, ���� �� ������� ���������!");
		if (PRStarted[eid] == 1)
		{//����� ������
			new Float: hp;	GetPlayerHealth(eid,hp);
			if (hp < 1.0) LeaveEvent(eid,EVENT_PARK);//���� ����� ���� - �������� ������

            if (hp < 50.0) SetPlayerHealth(eid, 100);

			new Float:Velocity[3];
			GetPlayerVelocity(eid, Velocity[0], Velocity[1], Velocity[2]);

			if(Velocity[2] < -0.4)
			{
				SendClientMessage(eid,COLOR_RED,"�� ���� ���������� �� ��������� ����������� �����, ��� ��� ������ ������!");
			    new CPid = PRPlayerLastCP[eid];
			    switch(PRid)
			    {
			        case 1:
			        {
			    		SetPlayerPos(eid, ParkCoord1[CPid][0], ParkCoord1[CPid][1],ParkCoord1[CPid][2]);
						SetPlayerFacingAngle(eid, ParkCoord1[CPid][3]);
					}
					case 2:
					{
						SetPlayerPos(eid, ParkCoord2[CPid][0], ParkCoord2[CPid][1],ParkCoord2[CPid][2]);
						SetPlayerFacingAngle(eid, ParkCoord2[CPid][3]);
					}
					case 3:
					{
						SetPlayerPos(eid, ParkCoord3[CPid][0], ParkCoord3[CPid][1],ParkCoord3[CPid][2]);
						SetPlayerFacingAngle(eid, ParkCoord3[CPid][3]);
					}
					case 4:
					{
						SetPlayerPos(eid, ParkCoord4[CPid][0], ParkCoord4[CPid][1],ParkCoord4[CPid][2]);
						SetPlayerFacingAngle(eid, ParkCoord4[CPid][3]);
					}
					case 5:
					{
						SetPlayerPos(eid, ParkCoord5[CPid][0], ParkCoord5[CPid][1],ParkCoord5[CPid][2]);
						SetPlayerFacingAngle(eid, ParkCoord5[CPid][3]);
					}
					case 6:
					{
						SetPlayerPos(eid, ParkCoord6[CPid][0], ParkCoord6[CPid][1],ParkCoord6[CPid][2]);
						SetPlayerFacingAngle(eid, ParkCoord6[CPid][3]);
					}
					/*case 6:
					{
						SetPlayerPos(eid, ParkCoord4ny[CPid][0], ParkCoord4ny[CPid][1],ParkCoord4ny[CPid][2]);
						SetPlayerFacingAngle(eid, ParkCoord4ny[CPid][3]);
					}*/
				}
			}
		}//����� ������
		if (PRTimeToEnd == 899 && PRStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (PRTimeToEnd == 898 && PRStarted[eid] == 1){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6);}
		if (PRTimeToEnd == 897 && PRStarted[eid] == 1)
		{//� ������, ����� ������ �������� �����
		    ResetPlayerWeapons(eid);
			PlayerPlaySound(eid,1057,0.0,0.0,0.0);
			GameTextForPlayer(eid, "GO",1000,6);
			TogglePlayerControllable(eid,1);
			SendClientMessage(eid,COLOR_CYAN,"���������: ������� ������� {FFFFFF}Alt{00CCCC}, ���� �� ����� ��� �������� - �� ��������� �� ��������� ��������.");
		}//� ������, ����� ������ �������� �����
		
		if (PRTimeToEnd == 1)
		{//����� �� �������
			SendClientMessage(eid,COLOR_PARK,"������ �������� (����� �� �������: {FFFFFF}15{58FAF4} �����)");
			PRTimeToEnd = -1; PRTimer = 0;JoinEvent[eid] = 0;PRStarted[eid] = 0;SetPlayerVirtualWorld(eid,0);
			//DestroyDynamicPickup(PRPickup[eid]);
			DisablePlayerCheckpoint(eid);
			LSpawnPlayer(eid);
			ShowClanZones(eid); // ������� �������� ����
		}//����� �� �������
	}//���� ��� ���������� �����
	if (PRPlayers == 0) {SendClientMessageToAll(COLOR_PARK,"������ ��������"); PRTimer = 0; PRTimeToEnd = 0;}
}//�� ����� �����


if (PRTimer == 1)
{//�����
	for (new i = 0; i < 20; i++) PRPlayersList[i] = -1;//������� ������ �������
	new i = 0; //���� ��������� ������ �������
	foreach(Player, cid) if (JoinEvent[cid] == EVENT_PARK) {PRPlayersList[i] = cid; i++;} //��������� ������ ������� �� �����

	SendClientMessageToAll(COLOR_PARK,"������ ���������.");

	new cid, String[140];
	format(String,sizeof(String)," ������������ ��������� �� ������ ������ ������!");
	for (i = 0; i < 20; i++)
	{//���� ��� ����������
		cid = PRPlayersList[i];
		if (!IsPlayerConnected(cid)) continue;
		
		if (JoinEvent[cid] == EVENT_PARK)
		{//����� �����������
				PRStarted[cid] = 1;LAFK[cid] = 0;PRpos = 0; PRTimer = -1; PRTimeToEnd = 900;
				TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_PARK]);
				HideClanZones(cid); //�������� ����
				StopFly(cid);
				SetPlayerInterior(cid,0);
				//new Float: rx, Float: ry;
				if (LSpecID[cid] != -1) callcmd::specoff(cid, "");
	
	            PRPlayerLastCP[cid] = 0;
	            
	            new plmin=random(2);
	            new Float:rnd1 = float(random(400)/100);
	            new Float:rnd2 = float(random(200)/100);
	            
	            if(plmin == 1) rnd1 = -rnd1; rnd2 = -rnd2;

                if (OnFly[cid]) StopFly(cid);//���������� ��� ��� ������ � ������ ���������

				switch (PRid)
				{
					case 1:
     				{
   					 	//PRPickup[cid] = CreateDynamicPickup(19945, 2, ParkCoord1[1][0], ParkCoord1[1][1], ParkCoord1[1][2], PARK_WORLD, 0, cid, 100.0);
   					 	SetPlayerCheckpoint(cid,ParkCoord1[1][0], ParkCoord1[1][1], ParkCoord1[1][2], 8.0);
   						SetPlayerPos(cid, ParkCoord1[0][0]+rnd1, ParkCoord1[0][1]+rnd2,ParkCoord1[0][2]);//random 0(1)
						SetPlayerFacingAngle(cid, ParkCoord1[0][3]);
					}
					case 2:
     				{
     				  	//PRPickup[cid] = CreateDynamicPickup(19605, 2, ParkCoord2[1][0], ParkCoord2[1][1], ParkCoord2[1][2], PARK_WORLD, 0, cid, 100.0);
     				  	SetPlayerCheckpoint(cid,ParkCoord2[1][0], ParkCoord2[1][1], ParkCoord2[1][2], 8.0);
						SetPlayerPos(cid, ParkCoord2[0][0]+rnd2, ParkCoord2[0][1]+rnd1,ParkCoord2[0][2]);//random 270(2)
						SetPlayerFacingAngle(cid, ParkCoord2[0][3]);
					}
					case 3:
     				{
     				  	//PRPickup[cid] = CreateDynamicPickup(19607, 2, ParkCoord3[1][0], ParkCoord3[1][1], ParkCoord3[1][2], PARK_WORLD, 0, cid, 100.0);
     				  	SetPlayerCheckpoint(cid,ParkCoord3[1][0], ParkCoord3[1][1], ParkCoord3[1][2], 8.0);
						SetPlayerPos(cid, ParkCoord3[0][0]+rnd1, ParkCoord3[0][1]+rnd2,ParkCoord3[0][2]);//random 270(2)
						SetPlayerFacingAngle(cid, ParkCoord3[0][3]);
					}
					case 4:
     				{
     				  	//PRPickup[cid] = CreateDynamicPickup(19606, 2, ParkCoord4[1][0], ParkCoord4[1][1], ParkCoord4[1][2], PARK_WORLD, 0, cid, 100.0);
     				  	SetPlayerCheckpoint(cid,ParkCoord4[1][0], ParkCoord4[1][1], ParkCoord4[1][2], 8.0);
						SetPlayerPos(cid, ParkCoord4[0][0]+rnd1, ParkCoord4[0][1]+rnd2,ParkCoord4[0][2]);//random 270(2)
						SetPlayerFacingAngle(cid, ParkCoord4[0][3]);
					}
					case 5:
     				{
     				  	//PRPickup[cid] = CreateDynamicPickup(19606, 2, ParkCoord5[1][0], ParkCoord5[1][1], ParkCoord5[1][2], PARK_WORLD, 0, cid, 100.0);
     				  	SetPlayerCheckpoint(cid,ParkCoord5[1][0], ParkCoord5[1][1], ParkCoord5[1][2], 8.0);
						SetPlayerPos(cid, ParkCoord5[0][0]+rnd1, ParkCoord5[0][1]+rnd2,ParkCoord5[0][2]);//random 270(2)
						SetPlayerFacingAngle(cid, ParkCoord5[0][3]);
					}
					case 6:
     				{
     				  	//PRPickup[cid] = CreateDynamicPickup(19606, 2, ParkCoord5[1][0], ParkCoord5[1][1], ParkCoord5[1][2], PARK_WORLD, 0, cid, 100.0);
     				  	SetPlayerCheckpoint(cid,ParkCoord6[1][0], ParkCoord6[1][1], ParkCoord6[1][2], 8.0);
						SetPlayerPos(cid, ParkCoord6[0][0]+rnd1, ParkCoord6[0][1]+rnd2,ParkCoord6[0][2]);//random 270(2)
						SetPlayerFacingAngle(cid, ParkCoord6[0][3]);
					}
					/*case 6:
     				{
     				  	PRPickup[cid] = CreateDynamicPickup(19606, 2, ParkCoord4ny[1][0], ParkCoord4ny[1][1], ParkCoord4ny[1][2], PARK_WORLD, 0, cid, 100.0);
						SetPlayerPos(cid, ParkCoord4ny[0][0]+rnd1, ParkCoord4ny[0][1]+rnd2,ParkCoord4ny[0][2]);//random 270(2)
						SetPlayerFacingAngle(cid, ParkCoord4ny[0][3]);
					}*/
				}
				
				ResetWeapons(cid);
				SendClientMessage(cid,COLOR_PARK,String);
				SetPlayerVirtualWorld(cid, PARK_WORLD);
				TogglePlayerControllable(cid,0);
				PlayerPlaySound(cid,1056,0.0,0.0,0.0);
				GameTextForPlayer(cid, "3",1000,6);
				SetCameraBehindPlayer(cid);
		}//����� �����������
		
		
	}//���� ��� ����������
	PRTimer = -1; PRTimeToEnd = 900;//����� �� �����
}//�����
