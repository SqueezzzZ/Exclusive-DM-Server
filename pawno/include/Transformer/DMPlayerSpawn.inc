	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 1)
	{//����� �� 1 ��
		new rand = random(sizeof(DM1SPAWN));
		x = DM1SPAWN[rand][0]; y = DM1SPAWN[rand][1]; z = DM1SPAWN[rand][2]; Angle = DM1SPAWN[rand][3];
		w1 = 8; w1ammo = 1;//���� ������
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 1 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 2)
	{//����� �� 2 ��
		new rand = random(sizeof(DM2SPAWN));
		x = DM2SPAWN[rand][0]; y = DM2SPAWN[rand][1]; z = DM2SPAWN[rand][2]; Angle = DM2SPAWN[rand][3];
		w1 = 24; w1ammo = 20000;//���� ����
		w2 = 29; w2ammo = 20000;//���� ��5
		w3 = 30; w3ammo = 20000;//���� ��
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 2 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 3)
	{//����� �� 3 ��
		new rand = random(sizeof(DM3SPAWN));
		x = DM3SPAWN[rand][0]; y = DM3SPAWN[rand][1]; z = DM3SPAWN[rand][2]; Angle = DM3SPAWN[rand][3];
		w1 =  34; w1ammo = 20000;//���� ������
		w2 = 8; w2ammo = 1;//���� ������
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 3 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 4)
	{//����� �� 4 ��
		new rand = random(sizeof(DM4SPAWN));
		x = DM4SPAWN[rand][0]; y = DM4SPAWN[rand][1]; z = DM4SPAWN[rand][2]; Angle = DM4SPAWN[rand][3];
		w1 = 32; w1ammo = 20000;//TEC
		w2 = 26; w2ammo = 20000;//�����
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 4 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 5)
	{//����� �� 5 ��
		new rand = random(sizeof(DM5SPAWN));
		x = DM5SPAWN[rand][0]; y = DM5SPAWN[rand][1]; z = DM5SPAWN[rand][2]; Angle = DM5SPAWN[rand][3];
		w1 = 31; w1ammo = 20000;//M4
		w2 = 27; w2ammo = 20000;//SPAS12
		w3 = 24; w3ammo = 20000;//Deagle
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 5 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 6)
	{//����� �� 6 ��
		new rand = random(sizeof(DM6SPAWN));
		x = DM6SPAWN[rand][0]; y = DM6SPAWN[rand][1]; z = DM6SPAWN[rand][2]; Angle = DM6SPAWN[rand][3];
		w1 = 31; w1ammo = 20000;//M4
		w2 = 9; w2ammo = 1;//���������
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 6 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 7)
	{//����� �� 7 ��
		new rand = random(sizeof(DM7SPAWN));
		x = DM7SPAWN[rand][0]; y = DM7SPAWN[rand][1]; z = DM7SPAWN[rand][2]; Angle = DM7SPAWN[rand][3];
		w1 = 34; w1ammo = 20000;//������
		w2 = 8; w2ammo = 1;//������
		w3 = 27; w3ammo = 20000;//SPAS12
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 7 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 8)
	{//����� �� 8 ��
		new rand = random(sizeof(DM8SPAWN));
		x = DM8SPAWN[rand][0]; y = DM8SPAWN[rand][1]; z = DM8SPAWN[rand][2]; Angle = DM8SPAWN[rand][3];
		w1 = 38; w1ammo = 20000;//�������
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 8 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 9)
	{//����� �� 9 ��
		new rand = random(sizeof(DM9SPAWN));
		x = DM9SPAWN[rand][0]; y = DM9SPAWN[rand][1]; z = DM9SPAWN[rand][2]; Angle = DM9SPAWN[rand][3];
		w1 = 32; w1ammo = 20000;//Tec9
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 9 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 10)
	{//����� �� 10 ��
		new rand = random(sizeof(DM10SPAWN));
		x = DM10SPAWN[rand][0]; y = DM10SPAWN[rand][1]; z = DM10SPAWN[rand][2]; Angle = DM10SPAWN[rand][3];
		w1 = 35; w1ammo = 20000;//RPG
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 10 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 11)
	{//����� �� 11 ��
		new rand = random(sizeof(DM11SPAWN));
		x = DM11SPAWN[rand][0]; y = DM11SPAWN[rand][1]; z = DM11SPAWN[rand][2]; Angle = DM11SPAWN[rand][3];
		w1 = 33; w1ammo = 20000;//�������� ��������
		w2 = 6; w2ammo = 1;//������
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 11 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 12)
	{//����� �� 12 ��
		new rand = random(sizeof(DM12SPAWN));
		x = DM12SPAWN[rand][0]; y = DM12SPAWN[rand][1]; z = DM12SPAWN[rand][2]; Angle = DM12SPAWN[rand][3];
		w1 = 16; w1ammo = 20000;//�������
		w2 = 22; w2ammo = 20000;//9mm
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 12 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 13)
	{//����� �� 13 ��
		new rand = random(sizeof(DM13SPAWN));
		x = DM13SPAWN[rand][0]; y = DM13SPAWN[rand][1]; z = DM13SPAWN[rand][2]; Angle = DM13SPAWN[rand][3];
		w1 = 16; w1ammo = 20000;//�������
		w2 = 27; w2ammo = 20000;//Spas
		w3 = 30; w3ammo = 20000;//��-47
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 13 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 14)
	{//����� �� 14 ��
		new rand = random(sizeof(GG7SPAWN));
		x = GG7SPAWN[rand][0]; y = GG7SPAWN[rand][1]; z = GG7SPAWN[rand][2]; Angle = GG7SPAWN[rand][3];
		w1 = 31; w1ammo = 20000;//M4
		w2 = 25; w2ammo = 20000;//shotgun
		w3 = 24; w3ammo = 20000;//Deagle
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 14 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 15)
	{//����� �� 15 ��
		new rand = random(sizeof(DM15SPAWN));
		x = DM15SPAWN[rand][0]; y = DM15SPAWN[rand][1]; z = DM15SPAWN[rand][2]; Angle = DM15SPAWN[rand][3];
		w1 = 34; w1ammo = 20000;//������
		w2 = 8; w2ammo = 1;//������
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 15 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 16)
	{//����� �� 16 ��
		new rand = random(sizeof(DM16SPAWN));
		x = DM16SPAWN[rand][0]; y = DM16SPAWN[rand][1]; z = DM16SPAWN[rand][2]; Angle = DM16SPAWN[rand][3];
		w1 = 29; w1ammo = 20000;//mp5
		w2 = 24; w2ammo = 20000;//Deagle
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 16 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 17)
	{//����� �� 17 ��
		new rand = random(sizeof(DM17SPAWN));
		x = DM17SPAWN[rand][0]; y = DM17SPAWN[rand][1]; z = DM17SPAWN[rand][2]; Angle = DM17SPAWN[rand][3];
		w1 = 30; w1ammo = 20000;//��-47
		w2 = 24; w2ammo = 20000;//Deagle
		w3 = 29; w3ammo = 20000;//mp5
		SetPlayerVirtualWorld(playerid, 1);SetPlayerInterior(playerid, 10);
	}//����� �� 17 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 18)
	{//����� �� 18 ��
		new rand = random(sizeof(DM18SPAWN));
		x = DM18SPAWN[rand][0]; y = DM18SPAWN[rand][1]; z = DM18SPAWN[rand][2]; Angle = DM18SPAWN[rand][3];
		w1 = 24; w1ammo = 20000;//Deagle
		w2 = 26; w2ammo = 20000;//������
		w3 = 31; w3ammo = 20000;//�4
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 18 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 19)
	{//����� �� 19 ��
		new rand = random(sizeof(DM19SPAWN));
		x = DM19SPAWN[rand][0]; y = DM19SPAWN[rand][1]; z = DM19SPAWN[rand][2]; Angle = DM19SPAWN[rand][3];
		w1 = 25; w1ammo = 20000;//shotgun
		w2 = 22; w2ammo = 20000;//9��
		w3 = 42; w3ammo = 20000;//������������
		SetPlayerVirtualWorld(playerid, 1);
	}//����� �� 19 ��
	if (JoinEvent[playerid] == EVENT_DM && DMTimeToEnd > 0 && DMid == 20)
	{//����� �� 20 ��
		new rand = random(sizeof(DM20SPAWN));
		x = DM20SPAWN[rand][0]; y = DM20SPAWN[rand][1]; z = DM20SPAWN[rand][2]; Angle = DM20SPAWN[rand][3];
		w1 = 10; w1ammo = 1;//���������� �����
		w2 = 24; w2ammo = 20000;//Deagle
		SetPlayerVirtualWorld(playerid, 1);SetPlayerInterior(playerid, 3);
	}//����� �� 20 ��