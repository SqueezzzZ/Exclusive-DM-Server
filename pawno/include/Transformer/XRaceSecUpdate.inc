if (XRTimer >= 0)
{
	XRTimer--; new String[60];
	format(String, sizeof String, "LEGENDARY RACE:~w~ %d sec. Players: %d", XRTimer, XRPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_XRACE], String);
}
if (XRTimeToEnd > 0) XRTimeToEnd--;

if (XRTimer == 60 && XRid == 1)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Around San Andreas{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 32;//���-�� ���������� ������ �� ������� � �������
	new xrmodel;
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	for(new i = 1; i < XRCPs; i+=3)
	{//����������� ���������� ��� �����
		xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];
	}//����������� ���������� ��� �����
	XRCarCP[0] = 448;
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}
if (XRTimer == 60 && XRid == 2)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Bon Voyage{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 30;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRTypeCP[XRCPs-1] = 1;//�������� �����
	XRCarCP[0] = 473;//����� ����������� �� �������� �����
	XRCarCP[1] = 446;//squallo �� ������ ����
}
if (XRTimer == 60 && XRid == 3)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Up And Down{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 23;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRTypeCP[XRCPs-1] = 4;//��������� �����
	XRCarCP[0] = 461;//����� �� PCJ
	XRCarCP[3] = 513;XRCarCP[4] = 451;XRCarCP[10] = 568;XRCarCP[21] = 513;//stuntplane, turismo, bandito, stuntplane
	XRTypeCP[3] = 3;XRTypeCP[4] = 3;XRTypeCP[21] = 3;//��������� ���������	
}

if (XRTimer == 60 && XRid == 4)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� <<{FFFFFF}Riders On The Storm{FFD700}>> �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������");
	XRCPs = 23;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRTypeCP[XRCPs-1] = 1;//�������� �����
	XRCarCP[0] = 541;//����� �� Bullet
	XRCarCP[9] = 541;//bullet
	XRCarCP[5] = 473;XRCarCP[16] = 473;//�������� �����
	XRCarCP[6] = 446;XRCarCP[17] = 446;//squallo
	XRTypeCP[5] = 3;XRTypeCP[16] = 3;//��������� ���������
}

if (XRTimer == 60 && XRid == 5)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Crazy Turns{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 62;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	new xrmodel;
	for(new i = 1; i < XRCPs; i+=4)
	{//���� ����� ����������
		xrmodel = random(126);XRCarCP[i] = XRCars1[xrmodel];
	}//���� ����� ����������
	XRCarCP[0] = 471;//����� �� �����������
	XRTypeCP[XRCPs-1] = 1;//�������� �����	
}

if (XRTimer == 60 && XRid == 6)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Vegas Race{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 35;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRTypeCP[XRCPs-1] = 1;//�������� �����	
	XRCarCP[0] = 441;//����� �� RC Bandit
	XRCarCP[22] = 441;XRCarCP[23] = 464;//RC �� ����� ������
	XRCarCP[2] = 559;XRCarCP[8] = 522;XRCarCP[12] = 560;XRCarCP[28] = 562;//Jester, NRG, Sultan, Elegy
	XRTypeCP[23] = 3;XRTypeCP[24] = 3;XRTypeCP[25] = 3;XRTypeCP[26] = 3;XRTypeCP[27] = 3;//��������� ���������
}

if (XRTimer == 60 && XRid == 7)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Dead Air{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 23;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 3;//��������� ����
	}//����������� ���������� ��� �����
	XRTypeCP[XRCPs-1] = 4;//��������� �����	
	XRCarCP[0] = 461;//����� �� PCJ	
	XRCarCP[1] = 464;XRCarCP[4] = 464;XRCarCP[8] = 464;XRCarCP[10] = 464;//RC
	XRCarCP[2] = 513;XRCarCP[5] = 513;XRCarCP[9] = 513;XRCarCP[12] = 513;//StuntPlane
}

if (XRTimer == 60 && XRid == 8)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Road To Farm{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 43;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 471;//����� �� �����������
	XRTypeCP[XRCPs-1] = 1;//�������� �����
	XRTypeCP[1] = 3;//��������� ��� ��������
	XRCarCP[1] = 539;XRCarCP[2] = 560;XRCarCP[29] = 495;//Vortex, Sultan, SandKing
}

if (XRTimer == 60 && XRid == 9)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}UnderGround{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 29;new xrmodel;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		if(i == 1 || i == 7 || i == 15 || i == 24){xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];}//���� ����� ����		
		XRTypeCP[i] = 0;//������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 521;//��������� ���������
	XRTypeCP[XRCPs-1] = 1;XRTypeCP[22] = 3;//�������� ����� � ������� ��� ��� ������ � ����
	XRCarCP[22] = 473;//�������� �����
}

if (XRTimer == 60 && XRid == 10)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}San Fierro Tour{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 25;new xrmodel;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		if(i == 1 || i == 5 || i == 15 || i == 17){xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];}//���� ����� ����		
		XRTypeCP[i] = 0;//������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 509;//��������� ���������
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}

if (XRTimer == 60 && XRid == 11)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Into The Wild{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 35;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 468;//��������� ��������� - Sanchez
	XRCarCP[10] = 471;//cp 10 - Quad
	XRCarCP[21] = 444;//cp 21 - Monster
	XRCarCP[31] = 468;//cp 31 - Sanchez
	
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}
if (XRTimer == 60 && XRid == 12)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Drag Race{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 10; new xrmodel;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 522;
	xrmodel = random(20);XRCarCP[1] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[6] = XRCars9[xrmodel];
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}
if (XRTimer == 60 && XRid == 13)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Need For Speed{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 30;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 461; //��������� ����
	XRCarCP[1] = 411; //infernus �� ������ ����
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}
if (XRTimer == 60 && XRid == 14)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}���������{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 66;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	new xrmodel;
	for(new i = 4; i < XRCPs; i+=4)
	{//���� ����� ����������
		xrmodel = random(126);XRCarCP[i] = XRCars1[xrmodel];
	}//���� ����� ����������
	XRCarCP[0] = 471;//����� �� �����������
	XRTypeCP[XRCPs-1] = 4;//��������� �����
}
if (XRTimer == 60 && XRid == 15)
{
	SendClientMessageToAll(COLOR_XR,"����������� ����� <<{FFFFFF}San Fierro Drift{FFD700}>> �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"����������� {FFFFFF}/xrace{FFD700} ���� ������ �����������");
	XRCPs = 54;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 510; //��������� ����
	XRCarCP[5] = 562; //elegy �� ����� ����
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}
if (XRTimer == 60 && XRid == 16)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Mountain{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 36;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 468;//����� �� sanchez
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}
if (XRTimer == 60 && XRid == 17)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}�� ��� ��������{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 34;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		if (5 <= i <= 32) XRTypeCP[i] = 3; //��������� ����
		else XRTypeCP[i] = 0; //�������� ����
		XRCarCP[i] = -1;//��� �������������
	}//����������� ���������� ��� �����
	XRTypeCP[XRCPs-1] = 1;//�������� �����
	XRCarCP[0] = 481; XRCarCP[32] = 481;//BMX	
	XRCarCP[5] = 464;//RC
	XRCarCP[8] = 476;//Rustler
}
if (XRTimer == 60 && XRid == 18)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Dirt And Dust{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 23;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	new xrmodel;
	xrmodel = random(20);XRCarCP[3] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[14] = XRCars9[xrmodel];
	XRCarCP[0] = 468; XRCarCP[21] = 468;//sanchez
	XRTypeCP[XRCPs-1] = 4;//��������� �����
}
if (XRTimer == 60 && XRid == 19)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Los Santos Highway{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 37;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	new xrmodel;
	xrmodel = random(20);XRCarCP[1] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[13] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[25] = XRCars9[xrmodel];
	XRCarCP[0] = 571;//kart
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}
if (XRTimer == 60 && XRid == 20)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}Fast And Furious{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 33;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//�������� ����
	}//����������� ���������� ��� �����
	new xrmodel;
	for(new i = 1; i < XRCPs; i+=6)
	{//����������� ���������� ��� �����
		xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];
	}//����������� ���������� ��� �����
	XRCarCP[0] = 522;//nrg
	XRTypeCP[XRCPs-1] = 1;//�������� �����
}

if (XRTimer == 60 && XRid == 21)
{
	SendClientMessageToAll(COLOR_XR,"| ����������� ����� [{FFFFFF}���� �������{FFD700}] �������� ����� {FFFFFF}������{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| ����������� {FFFFFF}/xrace{FFD700}, ���� ������ �����������.");
	XRCPs = 22;//���-�� ���������� ������ �� ������� � �������
	for(new i = 0; i < XRCPs; i++)
	{//����������� ���������� ��� �����
		XRCarCP[i] = -1;//��� �������������
		XRTypeCP[i] = 0;//������� ����
	}//����������� ���������� ��� �����
	XRCarCP[0] = 522;//��������� ��������� - nrg 500
	XRCarCP[1] = 411;//cp 1 - infernus
	XRCarCP[3] = 446;//cp 3 - squalo
	XRCarCP[5] = 541;//cp 5 - bullet
	XRCarCP[8] = 522;//cp 8 - nrg 500

	XRTypeCP[XRCPs-1] = 1;//�������� �����
	XRTypeCP[3] = 3;
}

if (XRTimeToEnd > 0)
{//�� ����� ���������� �����
	new eid;
	for (new i = 0; i < 25; i++) 
	{//���� ��� ���������� �����
		eid = XRPlayersList[i];
		if (!IsPlayerConnected(eid) || XRStarted[eid] == 0) continue;
		
		if (LAFK[eid] >= 30)
		{
			XRCarID[eid] = 0; JoinEvent[eid] = 0; XRStarted[eid] = 0;
			SendClientMessage(eid,COLOR_RED,"�� ���� ������� �� ���� �� AFK �� ����� ����� 30 ������");
			DisablePlayerRaceCheckpoint(eid); Kick(eid); continue;
		}
		else if (LAFK[eid] >= 20){SendClientMessage(eid,COLOR_RED,"�� ������ ��������� �� �����, ���� �� ������� ���������!");}
		new Float: hp;	GetPlayerHealth(eid,hp); if (hp < 1.0) LeaveEvent(eid,EVENT_XRACE);//���� ����� ���� - �������� �����
		if (IsPlayerInAnyVehicle(eid) && GetPlayerVehicleID(eid) != XRCarID[eid]) RemovePlayerFromVehicle(eid);
		if (GetPlayerSurfingVehicleID(eid) != INVALID_VEHICLE_ID)
		{//����� �� ����� �����-�� ����
			new Float: x, Float: y, Float: z; GetPlayerPos(eid, x, y, z); SetPlayerPos(eid, x, y, z + 2);
			SendClientMessage(eid, COLOR_RED, "�� ����� ����� ��������� ������ �� ����� ������ ����������!");
		}//����� �� ����� �����-�� ����
		if (XRTimeToEnd == 719){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (XRTimeToEnd == 718){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6);}
		if (XRTimeToEnd == 717)
		{//� ������, ����� ������ �������� �����
			PlayerPlaySound(eid,1057,0.0,0.0,0.0);
			GameTextForPlayer(eid, "GO",1000,6);
			TogglePlayerControllable(eid,1);
			ResetPlayerWeapons(eid);
		}//� ������, ����� ������ �������� �����
		if (XRTimeToEnd == 1)
		{//����� �� �������
			DestroyVehicle(XRCarID[eid]); XRCarID[eid] = 0; 
			SendClientMessage(eid,COLOR_XR,"����������� ����� ��������� (����� �� �������: {FFFFFF}15{FFD700} �����)");	 
			XRTimeToEnd = 0;JoinEvent[eid] = 0;XRStarted[eid] = 0;SetPlayerVirtualWorld(eid,0);
			DisablePlayerRaceCheckpoint(eid);
			ShowClanZones(eid); // ������� �������� ����
			XRTimer = GetEventRestartTime();
			while (PrevXRid == XRid) XRid = random(MAX_XRACE) + 1; //����� ����� ������
			PrevXRid = XRid;
		}//����� �� �������
	}//���� ��� ���������� �����
	if (XRPlayers == 0)
	{
		SendClientMessageToAll(COLOR_XR,"����������� ����� ���������"); XRTimeToEnd = 0;
		XRTimer = GetEventRestartTime();
		while (PrevXRid == XRid) XRid = random(MAX_XRACE) + 1; //����� ����� ������
		PrevXRid = XRid;
	}
}//�� ����� �����


if (XRTimer == 1)
{//����� �����
	for (new i = 0; i < 25; i++) XRPlayersList[i] = -1;//������� ������ ������� �� �����
	new i = 0; //���� ��������� ������ ������� �� �����
	foreach(Player, cid) if (JoinEvent[cid] == EVENT_XRACE) {XRPlayersList[i] = cid; i++;}

	new cid;
	for (i = 0; i < 25; i++) 
	{//���� ��� ���������� �����
		cid = XRPlayersList[i];
		if (!IsPlayerConnected(cid)) continue;
		
		if (IsPlayerInRaceCheckpoint(cid))
		{//����� � ���� �����
			DisablePlayerRaceCheckpoint(cid);FlipCount[cid] = 3;
			XRStarted[cid] = 1;LAFK[cid] = 0;
			TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_XRACE]);
			
			if (XRid == 1)
			{//����� Around San Andreas
				SetPlayerRaceCheckpoint(cid, 0, XRACE1[1][0], XRACE1[1][1], XRACE1[1][2], XRACE1[2][0], XRACE1[2][1], XRACE1[2][2], 7);
			}//����� Around San Andreas	
			if (XRid == 2)
			{//����� Around Bon Voyage
				SetPlayerRaceCheckpoint(cid, 0, XRACE2[1][0], XRACE2[1][1], XRACE2[1][2], XRACE2[2][0], XRACE2[2][1], XRACE2[2][2], 7);
			}//����� Around Bon Voyage
			if (XRid == 3)
			{//����� Around Up And Down
				SetPlayerRaceCheckpoint(cid, 0, XRACE3[1][0], XRACE3[1][1], XRACE3[1][2], XRACE3[2][0], XRACE3[2][1], XRACE3[2][2], 7);
			}//����� Around Up And Down	
			if (XRid == 4)
			{//����� Riders On The Storm
				SetPlayerRaceCheckpoint(cid, 0, XRACE4[1][0], XRACE4[1][1], XRACE4[1][2], XRACE4[2][0], XRACE4[2][1], XRACE4[2][2], 7);
			}//����� Riders On The Storm	
			if (XRid == 5)
			{//����� Crazy Turns
				SetPlayerRaceCheckpoint(cid, 0, XRACE5[1][0], XRACE5[1][1], XRACE5[1][2], XRACE5[2][0], XRACE5[2][1], XRACE5[2][2], 7);
			}//����� Crazy Turns
			if (XRid == 6)
			{//����� Vegas Race
				SetPlayerRaceCheckpoint(cid, 0, XRACE6[1][0], XRACE6[1][1], XRACE6[1][2], XRACE6[2][0], XRACE6[2][1], XRACE6[2][2], 7);
			}//����� Vegas Race
			if (XRid == 7)
			{//����� Vegas Race
				SetPlayerRaceCheckpoint(cid, 3, XRACE7[1][0], XRACE7[1][1], XRACE7[1][2], XRACE7[2][0], XRACE7[2][1], XRACE7[2][2], 7);
			}//����� Vegas Race
			if (XRid == 8)
			{//����� Road To Farm
				SetPlayerRaceCheckpoint(cid, 3, XRACE8[1][0], XRACE8[1][1], XRACE8[1][2], XRACE8[2][0], XRACE8[2][1], XRACE8[2][2], 7);
			}//����� Road To Farm
			if (XRid == 9)
			{//����� UnderGround
				SetPlayerRaceCheckpoint(cid, 0, XRACE9[1][0], XRACE9[1][1], XRACE9[1][2], XRACE9[2][0], XRACE9[2][1], XRACE9[2][2], 7);
			}//����� UnderGround
			if (XRid == 10)
			{//����� San Fierro Tour
				SetPlayerRaceCheckpoint(cid, 0, XRACE10[1][0], XRACE10[1][1], XRACE10[1][2], XRACE10[2][0], XRACE10[2][1], XRACE10[2][2], 7);
			}//����� San Fierro Tour
			if (XRid == 11)
			{//����� Into The Wild
				SetPlayerRaceCheckpoint(cid, 0, XRACE11[1][0], XRACE11[1][1], XRACE11[1][2], XRACE11[2][0], XRACE11[2][1], XRACE11[2][2], 7);
			}//����� Into The Wild
			if (XRid == 12)
			{//����� Drag Race
				SetPlayerRaceCheckpoint(cid, 0, XRACE12[1][0], XRACE12[1][1], XRACE12[1][2], XRACE12[2][0], XRACE12[2][1], XRACE12[2][2], 7);
			}//����� Drag Race
			if (XRid == 13)
			{//����� Need For Speed
				SetPlayerRaceCheckpoint(cid, 0, XRACE13[1][0], XRACE13[1][1], XRACE13[1][2], XRACE13[2][0], XRACE13[2][1], XRACE13[2][2], 7);
			}//����� Need For Speed
			if (XRid == 14)
			{//����� ���������
				SetPlayerRaceCheckpoint(cid, 0, XRACE14[1][0], XRACE14[1][1], XRACE14[1][2], XRACE14[2][0], XRACE14[2][1], XRACE14[2][2], 7);
			}//����� ���������
			if (XRid == 15)
			{//����� San Fierro Drift
				SetPlayerRaceCheckpoint(cid, 0, XRACE15[1][0], XRACE15[1][1], XRACE15[1][2], XRACE15[2][0], XRACE15[2][1], XRACE15[2][2], 7);
			}//����� San Fierro Drift
			if (XRid == 16)
			{//����� Mountain
				SetPlayerRaceCheckpoint(cid, 0, XRACE16[1][0], XRACE16[1][1], XRACE16[1][2], XRACE16[2][0], XRACE16[2][1], XRACE16[2][2], 7);
			}//����� Mountain
			if (XRid == 17)
			{//����� �� ��� ��������
				SetPlayerRaceCheckpoint(cid, 0, XRACE17[1][0], XRACE17[1][1], XRACE17[1][2], XRACE17[2][0], XRACE17[2][1], XRACE17[2][2], 7);
			}//����� �� ��� ��������
			if (XRid == 18)
			{//����� Dirt And Dust
				SetPlayerRaceCheckpoint(cid, 0, XRACE18[1][0], XRACE18[1][1], XRACE18[1][2], XRACE18[2][0], XRACE18[2][1], XRACE18[2][2], 7);
			}//����� Dirt And Dust
			if (XRid == 19)
			{//����� Los Santos Highway
				SetPlayerRaceCheckpoint(cid, 0, XRACE19[1][0], XRACE19[1][1], XRACE19[1][2], XRACE19[2][0], XRACE19[2][1], XRACE19[2][2], 7);
			}//����� Los Santos Highway
			if (XRid == 20)
			{//����� Fast And Furious
				SetPlayerRaceCheckpoint(cid, 0, XRACE20[1][0], XRACE20[1][1], XRACE20[1][2], XRACE20[2][0], XRACE20[2][1], XRACE20[2][2], 7);
			}//����� Fast And Furious
			if (XRid == 21)
			{//����� ���� �������
				SetPlayerRaceCheckpoint(cid, 0, XRACE21[1][0], XRACE21[1][1], XRACE21[1][2], XRACE21[2][0], XRACE21[2][1], XRACE21[2][2], 7);
			}//����� ���� �������
			
			XRPlayerCP[cid] = 1;//������� ��� N1
			TogglePlayerControllable(cid,0);PlayerPlaySound(cid,1056,0.0,0.0,0.0);GameTextForPlayer(cid, "3",1000,6);
			SetCameraBehindPlayer(cid);SetVehicleVelocity(GetPlayerVehicleID(cid), 0.0, 0.0, 0.0);
			GetPlayerPos(cid,XRxx[cid],XRy[cid],XRz[cid]);GetVehicleZAngle(XRCarID[cid],XRa[cid]);
			XRvx[cid] = 0.0; XRvy[cid] = 0.0; XRvz[cid] = 0.0;
		}//����� � ���� ������
		else
		{
			if (JoinEvent[cid] == EVENT_XRACE)
			{
				SendClientMessage(cid,COLOR_RED,"��������! �� �� ���� �� ������ �����");
				JoinEvent[cid] = 0;DisablePlayerRaceCheckpoint(cid); SetPlayerVirtualWorld(cid,0); LSpawnPlayer(cid); ShowClanZones(cid); // ������� �������� ����
			}
		}
	}//���� ��� ���������� �����
	new String[140];
	format (String, sizeof(String),"����������� ����� <<{FFFFFF}%s{FFD700}>> ����������. �������: {FFFFFF}%d",XRName[XRid], XRPlayers);
	SendClientMessageToAll(COLOR_XR,String);	
	XRTimeToEnd = 720;XRpos = 0;
}//����� �����
