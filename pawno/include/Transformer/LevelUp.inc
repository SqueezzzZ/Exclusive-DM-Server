stock PlayerLevelUp(playerid)
{//������� ��������� ������
	if(Logged[playerid] == 0) return 1;
	if(Player[playerid][Level] > 99 && Player[playerid][Prestige] < 10) {Player[playerid][Level] = 100; Player[playerid][Exp] = 0; NeedXP[playerid] = 99999999; return 1;} //��� � 100+ ��. � ��������� ������ 10
	Player[playerid][Exp] -= NeedXP[playerid];Player[playerid][Level] += 1;
	//PlayerPlaySound(playerid, 19800, 0.0,0.0,0.0);//���������� ���
	new String[120];format(String,sizeof(String), "~g~LEVEL ~W~%d",Player[playerid][Level]); //LEVEL N
	GameTextForPlayer(playerid, String, 3000, 1);
	format(String,sizeof(String), "�� �������� {FFFFFF}%d{FFFF00}-�� ������",Player[playerid][Level]);
	SendClientMessage(playerid,COLOR_YELLOW,String);
	//���������� NeedXP
	new Lvl = Player[playerid][Level];
	if (Player[playerid][Prestige] < 10 || Lvl < 100) NeedXP[playerid] = Levels[Lvl];
	else NeedXP[playerid] = (Lvl - 99) * 100 + 35000;
	//-------------- �������� �� ������
	if (Player[playerid][Level] == 2){SendClientMessage(playerid,COLOR_YELLOW,"������� /skydive ������ ��������");}
	if (Player[playerid][Level] == 3){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 2-�� ������");}
	if (Player[playerid][Level] == 4){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ������ ������");}
	if (Player[playerid][Level] == 5){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 6){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 7){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 8){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 2-�� ������ � ����� ������ ������");}
	if (Player[playerid][Level] == 9){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������ � ���������� � ��������������");}
	if (Player[playerid][Level] == 10){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ����� ������ - �� ���� 1-�� ������");}
		if (Player[playerid][Level] == 10 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 50 ������' ������ ��������");}
	if (Player[playerid][Level] == 11){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 12){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 13){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ����� ������ - �� ���� 2-�� ������");}
	if (Player[playerid][Level] == 14){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 2-�� ������");}
	if (Player[playerid][Level] == 15){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������ � �������� ����� ������������ ������ - ��� ������");}
	if (Player[playerid][Level] == 16){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������ � ����� ������ ������");}
	if (Player[playerid][Level] == 17){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������ � ����� ������ ������");}
	if (Player[playerid][Level] == 18){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ������ ������");}
	if (Player[playerid][Level] == 19){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������ � ����� ������ ������");}
	if (Player[playerid][Level] == 20){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
		if (Player[playerid][Level] == 20 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 100 ������' ������ ��������");}
	if (Player[playerid][Level] == 21){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 22){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 2-�� ������");}
	if (Player[playerid][Level] == 23){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������ � ����� ������ ������");}
	if (Player[playerid][Level] == 24){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 25){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 25){SendClientMessage(playerid,COLOR_YELLOW,"������� /mytime ������ ��������  � �������� ����� ������������ ������ - ��� ��������");}
		if (Player[playerid][Level] == 25 && Player[playerid][Prestige] >= 2){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 2: ����� '����� ������' (��� ����������) ������ ��������");}
		if (Player[playerid][Level] == 25 && Player[playerid][Prestige] >= 8){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 8: ����� '����� ���������' ������ ��������");}
	if (Player[playerid][Level] == 26){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 2-�� ������");}
	if (Player[playerid][Level] == 27){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ������ ������");}
	if (Player[playerid][Level] == 28){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 29){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 30){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 2-�� ������");}
	if (Player[playerid][Level] == 31){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 140");}
	if (Player[playerid][Level] == 32){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 33){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 56");}
	if (Player[playerid][Level] == 34){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ������ ������");}
	if (Player[playerid][Level] == 35){SendClientMessage(playerid,COLOR_YELLOW,"����� �2 � �������������� ������ ��������");}
		if (Player[playerid][Level] == 35 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 50 ������' (��� ����������) ������ ��������");}
	if (Player[playerid][Level] == 36){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ����� ����� (/style)");}
	if (Player[playerid][Level] == 37){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������-��������� (������ ������) ��������� �� 1 000");}
	if (Player[playerid][Level] == 38){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� JetPack � ����� ������ '�� JetPack'");}
	if (Player[playerid][Level] == 39 && Player[playerid][Prestige] < 8){SendClientMessage(playerid,COLOR_YELLOW,"������������ ������ � ������ ��������� �� 250 000$");}
		if (Player[playerid][Level] == 40 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 100 ������' (��� ����������) ������ ��������");}
	if (Player[playerid][Level] == 40){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ������ ������");}
	if (Player[playerid][Level] == 41){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������� (������ ������) ��������� �� 180");}
	if (Player[playerid][Level] == 42){SendClientMessage(playerid,COLOR_YELLOW,"����� �5 � �������������� ������ ��������");}
	if (Player[playerid][Level] == 43){SendClientMessage(playerid,COLOR_YELLOW,"���������� ������ (������ ������) ��������� �� 20");}
	if (Player[playerid][Level] == 44){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� �������� (������ ������) ��������� �� 30");}
	if (Player[playerid][Level] == 45){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
		if (Player[playerid][Level] == 45 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 200 ������' (��� ����������) ������ ��������");}
	if (Player[playerid][Level] == 46){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� RPG (������ ������) ��������� �� 20");}
	if (Player[playerid][Level] == 47){SendClientMessage(playerid,COLOR_YELLOW,"������� ��� ���������� ���������� /paint � /paintid ������ ��������");}
	if (Player[playerid][Level] == 48){SendClientMessage(playerid,COLOR_YELLOW,"����� �10 � �������������� ������ ��������");}
	if (Player[playerid][Level] == 49){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 50){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 2-�� ������");}

	if (Player[playerid][Level] == 51){SendClientMessage(playerid,COLOR_YELLOW,"����� '����������� ��������� �� ������' ������ ��������");}
	if (Player[playerid][Level] == 52){SendClientMessage(playerid,COLOR_YELLOW,"������� ��� ����� ����� (/myskin, /myskinid) ������ ��������");}
	if (Player[playerid][Level] == 53 && Player[playerid][Prestige] < 8){SendClientMessage(playerid,COLOR_YELLOW,"������������ ������ � ������ ��������� �� 500 000$");}	
		if (Player[playerid][Level] == 53 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 200 ������' ������ ��������");}
	if (Player[playerid][Level] == 54){SendClientMessage(playerid,COLOR_YELLOW,"�������� ����� ����� ������ - �� ���� 3-�� ������");}
	if (Player[playerid][Level] == 55){SendClientMessage(playerid,COLOR_YELLOW,"����������� ������ � �������������� ������ ��������");}
		if (Player[playerid][Level] == 55 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 50 ������ (c� ���������)' (��� ����������) ������ ��������");}
	if (Player[playerid][Level] == 56){SendClientMessage(playerid,COLOR_YELLOW,"�������� ����� '�������� �� 180' ��� ���������� 1-�� ������");}
	if (Player[playerid][Level] == 57){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 58){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 59){SendClientMessage(playerid,COLOR_YELLOW,"�������� �����  '�������� �� 180' ��� ���������� 2-�� ������");}
	if (Player[playerid][Level] == 60){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ������ ������");}
		if (Player[playerid][Level] == 60 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 100 ������ (c� ���������)' (��� ����������) ������ ��������");}
	if (Player[playerid][Level] == 61){SendClientMessage(playerid,COLOR_YELLOW,"�������� ����� '������' ��� ���������� 1-�� ������");}
	if (Player[playerid][Level] == 62){SendClientMessage(playerid,COLOR_YELLOW,"�������� ����� '������' ��� ���������� 2-�� ������");}
	if (Player[playerid][Level] == 63){SendClientMessage(playerid,COLOR_YELLOW,"�������� ����� '��������' ��� ���������� 1-�� ������");}
	if (Player[playerid][Level] == 64){SendClientMessage(playerid,COLOR_YELLOW,"�������� ����� '��������' ��� ���������� 2-�� ������");}
	if (Player[playerid][Level] == 65){SendClientMessage(playerid,COLOR_YELLOW,"����������� ����� ������ �������� � �������������� TurboSpeed");}
		if (Player[playerid][Level] == 65 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ����� '�������� �� 200 ������ (c� ���������)' (��� ����������) ������ ��������");}
	if (Player[playerid][Level] == 66 && Player[playerid][Prestige] < 8){SendClientMessage(playerid,COLOR_YELLOW,"������������ ������ � ������ ��������� �� 1 000 000$");}
	if (Player[playerid][Level] == 67){SendClientMessage(playerid,COLOR_YELLOW,"������� /myweather ������ ��������");}
	if (Player[playerid][Level] == 68){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 69){SendClientMessage(playerid,COLOR_YELLOW,"�������� ����� ������������ ������ - ���� Chilliad");}
	if (Player[playerid][Level] == 70){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����������� �� ������ (/invisible)");}
	
	if (Player[playerid][Level] == 71){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 210");}
	if (Player[playerid][Level] == 72){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 84");}
	if (Player[playerid][Level] == 73){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������-��������� (������ ������) ��������� �� 1 500");}
	if (Player[playerid][Level] == 74){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������� (������ ������) ��������� �� 270");}
	if (Player[playerid][Level] == 75){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 1-�� ������");}
	if (Player[playerid][Level] == 76){SendClientMessage(playerid,COLOR_YELLOW,"���������� ������ (������ ������) ��������� �� 30");}
	if (Player[playerid][Level] == 77){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� �������� (������ ������) ��������� �� 45");}
	if (Player[playerid][Level] == 78){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 79){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� RPG (������ ������) ��������� �� 30");}
	if (Player[playerid][Level] == 80){SendClientMessage(playerid,COLOR_YELLOW,"UberNitro ������ �������� � �������������� TurboSpeed");}
	if (Player[playerid][Level] == 81){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� �������� (������ ������) ��������� �� 2 000");}
	if (Player[playerid][Level] == 82){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 280");}
	if (Player[playerid][Level] == 83){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 112");}
	if (Player[playerid][Level] == 84){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������-��������� (������ ������) ��������� �� 2 000");}
	if (Player[playerid][Level] == 85){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
		if (Player[playerid][Level] == 85 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: ������ �� ������ ������� ����� ��������� � ����� 1 � 2");}
	if (Player[playerid][Level] == 86){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������� (������ ������) ��������� �� 360");}
	if (Player[playerid][Level] == 87){SendClientMessage(playerid,COLOR_YELLOW,"���������� ������ (������ ������) ��������� �� 40");}
	if (Player[playerid][Level] == 88){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� �������� (������ ������) ��������� �� 60");}
	if (Player[playerid][Level] == 89){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� RPG (������ ������) ��������� �� 40");}
	if (Player[playerid][Level] == 90){SendClientMessage(playerid,COLOR_YELLOW,"��� �������� ����� ��������� 3-�� ������");}
	if (Player[playerid][Level] == 91){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� �������� (������ ������) ��������� �� 3 000");}
	if (Player[playerid][Level] == 92){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 93){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ���������� (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 94){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������-��������� (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 95){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� ��������� (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 96){SendClientMessage(playerid,COLOR_YELLOW,"���������� ������ (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 97){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� �������� (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 98){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� RPG (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 99){SendClientMessage(playerid,COLOR_YELLOW,"���������� ����������� ��� �������� (������ ������) ��������� �� 20 000");}
	if (Player[playerid][Level] == 100)
	{
		SendClientMessage(playerid,COLOR_YELLOW,"���������� ��� JetPack ������ �������� (������� 'N')");
        format(String,sizeof(String),"����� {ffffff}%s [%d]{FFBF00} ������ {ffffff}100{FFBF00} ������! �����������!",PlayerName[playerid],playerid);
		SendClientMessageToAll(0xFFBF00FF,String);
	}
	if (Player[playerid][Level] == 100 && Player[playerid][Prestige] < 10){SendClientMessage(playerid,COLOR_YELLOW,"{457EFF}��������! ����� ������� �������� ������ ��������! ('/prestige')");}
	if (Player[playerid][Level] == 100 && Player[playerid][Prestige] >= 10){SendClientMessage(playerid,COLOR_YELLOW,"{457EFF}��������! ������ �� ������ '�������������' ���� 100-�� ������!");}

	if (Player[playerid][Level] == 150){SendClientMessage(playerid,COLOR_YELLOW,"��������! ������ �� ������ ������ ������� � '������ ������'");}
	if (Player[playerid][Level] == 200){SendClientMessage(playerid,COLOR_YELLOW,"��������! ������ �� ������ ������ ������� � '������ ���������'");}

    //MarafonUpdate(playerid, 2, 1);

	//-------------- �������� �� ������	

	if (NeedXP[playerid] <= Player[playerid][Exp]) PlayerLevelUp(playerid);
	else SavePlayer(playerid);
	
	format(String, sizeof String, "%d.%d.%d a %d:%d:%d |   %s[%d] ������ %d ������.", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, Player[playerid][Level]);
	WriteLog("GlobalLog", String); WriteLog("LevelUps", String);
	return 1;
}//������� ��������� ������