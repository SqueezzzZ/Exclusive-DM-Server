if (Logged[playerid] > 0)
{//����� ���������
	if (LACWeaponOff[playerid] > 0) LACWeaponOff[playerid]--;//������ LAC �� ������
	
	//---------------------- LAC v2.0
	if (LACPanic[playerid] > 0)
	{//�����-�� �� LAC ���������� ������ � ���������
		if (LACPanic[playerid] == 1)
		{//����� ���������� � ��������� 1 ���
			LACPanicTime[playerid]++;
			//���� � ������� ���������� � ��������� ������ 30 ������ - ������� ��� ����������
			if (LACPanicTime[playerid] == 30) {LACPanicTime[playerid] = 0; LACPanic[playerid] = 0;}
		}//����� ���������� � ��������� 1 ���
		if (LACPanic[playerid] >= 2)
		{//����� ���������� � ��������� ����� 1 ���� � ������� 30 ������
			new String[140];
			format(String,sizeof String, "{FF0000}LAC: {AFAFAF}%s[%d] ��� ������ � ������� �� ���������� � ���������.", PlayerName[playerid], playerid);
			SendClientMessageToAll(COLOR_GREY,String);GKick(playerid);
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] ��� ������ � ������� �� ���������� � ���������: %d ������������ LAC �� %d ������.", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, LACPanic[playerid], LACPanicTime[playerid]);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
			LACPanic[playerid] = 0; LACPanicTime[playerid] = 0;
			return 1;
		}//����� ���������� � ��������� ����� 1 ���� � ������� 30 ������
	}//�����-�� �� LAC ���������� ������ � ���������
	//---------------------- LAC v2.0
	
	//---------------------- ������� �� ��������
	if (GetPlayerVehicleID(playerid) == 0 && GetPlayerState(playerid) != PLAYER_STATE_SPECTATING)
	{//------ �������� ������. �������� IsPlayerInAnyVehicle ������-�� ������ �������, ��� ����� �� � ����, ����� �� � ����.
		new Float: Distance = GetPlayerDistanceFromPoint(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
		new Float: newx, Float: newy, Float: newz, cheat = 0, String[140];GetPlayerPos(playerid, newx, newy, newz);
		if (Distance > 50.0) cheat = 1;
		if (Distance == 0.0) Player[playerid][DMove]++;
		else Player[playerid][DMove]=0;

		//new st[120];
		//format(st, sizeof st, "Dist: %.3f DMove: %d ", Distance, Player[playerid][DMove]);
		//SendClientMessage(playerid, -1, st);
		
		if (Distance < 100.0 && newz  < LastPlayerZ[playerid] - 5.0) cheat = 0;//������� ����
		if (OnFly[playerid] == 1 || GetPlayerSurfingVehicleID(playerid) != INVALID_VEHICLE_ID || newz < -15.0 || LSpecID[playerid] != -1 || Player[playerid][Banned] == 1) LACTeleportOff[playerid] = 3;
		//���� ����� � ������ ��������� ��� �� ����� ���� ��� ���� ��� ����� ��� � ������� ��� ��� �������
		if (LACTeleportOff[playerid] > 0) cheat = 0;//���� LAC �� �������� �� ������ ��������		
		if (cheat == 0) GetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
		if (cheat == 1)
		{//����� �����
			SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
			LACTeleportOff[playerid] = 0; LACPanic[playerid]++;//LAC v2.0
			format(String,sizeof(String), "[�������]LAC:{AFAFAF} %s[%d] �������� ���������� ��� �� �������� (������)",PlayerName[playerid], playerid);
            foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
  			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} �� ��������������� �� ��������� ����������� �������. {FF0000}�������: {AFAFAF}�������� ��� �� �������� (������)");
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] �������� ���������� ��� �� �������� (������)", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}//����� �����		
	}//------ �������� ������ 
	else
	{//------ �������� � ������
		new Float: Distance = GetPlayerDistanceFromPoint(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
		new Float: newx, Float: newy, Float: newz, cheat = 0, String[120];GetPlayerPos(playerid, newx, newy, newz);
		if (Distance == 0.0) Player[playerid][DMove]++;
		else Player[playerid][DMove]=0;
		if (Distance > 100.0) cheat = 1;
		if (Distance < 200.0 && newz - LastPlayerZ[playerid] < -15.0) cheat = 0;//������� ����
		if (newz < -15.0 || GetPlayerVehicleSeat(playerid) != 0 || LSpecID[playerid] != -1 || Player[playerid][Banned] == 1) LACTeleportOff[playerid] = 3;
		//���� ����� ���� ��� ����� ��� � ������� ��� ��� �������	
		//--- ����������� ����� �����: LAC �� AirBrake
		if (cheat != 1)
		{//���� ��� ��������� ��� �� ��������, �� �� AirBrake �� ���������
			new Float: SPD; GetVehicleVelocity(GetPlayerVehicleID(playerid), newx,newy,newz);
		    SPD = floatsqroot(((newx*newx)+(newy*newy))+(newz*newz))*200;
			if (SPD < 1.0) TimeWithZeroSpeed[playerid]++; else TimeWithZeroSpeed[playerid] = 0;
			if (Distance > 5.0 && TimeWithZeroSpeed[playerid] >= 2) cheat = 2;//������ ������ �������������, ���� �������� ���� 0 ��� ������ �������
		}//���� ��� ��������� ��� �� ��������, �� �� AirBrake �� ���������
			//--- ����������� ����� �����: LAC �� AirBrake
		if (GetPlayerTuneStatus(playerid) > 0 && LastPlayerTuneStatus[playerid] < 0) cheat = 0; //����� ������ ������ �������
		if (GetPlayerTuneStatus(playerid) < 0 && LastPlayerTuneStatus[playerid] > 0) cheat = 0; //����� ������ �� �������
		if (LACTeleportOff[playerid] > 0) {cheat = 0; TimeWithZeroSpeed[playerid] = 0;}//���� LAC �� �������� �� ������ ��������		
		if (cheat == 0) GetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);		
		LastPlayerTuneStatus[playerid] = GetPlayerTuneStatus(playerid);	TunesPerSecond[playerid] = 0;	
		if (cheat == 1)
		{//����� ����� TP
			if (GetVehicleModel(GetPlayerVehicleID(playerid)) != 537 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 538)
			{//�� � ������			
				SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
				DestroyVehicle(GetPlayerVehicleID(playerid)); TimeTransform[playerid] = 5;
				LACTeleportOff[playerid] = 0; LACPanic[playerid]++;//LAC v2.0
				format(String,sizeof(String), "[�������]LAC:{AFAFAF} %s[%d] �������� ���������� ��� �� ��������",PlayerName[playerid], playerid);
				foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
				SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} �� ��������������� �� ��������� ����������� �������. {FF0000}�������: {AFAFAF}�������� ��� �� ��������");
				format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] �������� ���������� ��� �� ��������", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
				WriteLog("GlobalLog", String);WriteLog("LAC", String);
			}//�� � ������	
		}//����� ����� TP		
		if (cheat == 2)
		{//����� ����� AirBrake (��������� �����)
			if (GetVehicleModel(GetPlayerVehicleID(playerid)) != 537 && GetVehicleModel(GetPlayerVehicleID(playerid)) != 538)
			{//�� � ������
				SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
				DestroyVehicle(GetPlayerVehicleID(playerid)); TimeTransform[playerid] = 5;
				LACTeleportOff[playerid] = 0; LACPanic[playerid]++;//LAC v2.0
				format(String,sizeof(String), "[�������]LAC:{AFAFAF} ��������� ������ %s[%d] ���������. {FF0000}�������: {AFAFAF}�������� AirBrake",PlayerName[playerid], playerid);
                foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
    			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} ��� ��������� ��� ���������. {FF0000}�������: {AFAFAF}�������� ��� AirBrake");
				format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: ��������� ������ %s[%d] ���������. �������: �������� ��� AirBrake", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
				WriteLog("GlobalLog", String);WriteLog("LAC", String);
			}//�� � ������
		}//����� ����� AirBrake	(��������� �����)
		
		//format(String,sizeof String, "���������: %d", floatround(Distance));SendClientMessage(playerid,-1,String);
	}//------ �������� � ������
	if (LACTeleportOff[playerid] > 0) LACTeleportOff[playerid]--; 
	//---------------------- ������� �� ��������
	
	//------ ������� �� FlyHack
	new AnimLib[30], AnimName[30];
	GetAnimationName(GetPlayerAnimationIndex(playerid) , AnimLib, sizeof(AnimLib), AnimName, sizeof(AnimName));
	if (LACFlyOff[playerid] > 0 && LAFK[playerid] < 4) LACFlyOff[playerid] --;
	if (GetPlayerWeapon(playerid) == 46) LACFlyOff[playerid] = 45; //����� �� ���� ������ ������������ ����� �������� ��������
	if (GetPlayerSpeed(playerid) > 60 && Player[playerid][Banned] == 0 && OnFly[playerid] == 0 && (strcmp(AnimLib, "SWIM", true) == 0 || strcmp(AnimLib, "PARACHUTE", true) == 0) && LACFlyOff[playerid] == 0)
	{
		new cheat = 1, String[120];		
		if (CheatFlySec[playerid] < 2){CheatFlySec[playerid] += 1;cheat = 0;}
		if (strcmp(AnimLib, "PARACHUTE", true) == 0 && GetPlayerWeapon(playerid) == 46) cheat = 0;
		if (cheat == 1)
		{
			ResetPlayerWeapons(playerid); LSpawnPlayer(playerid); LACFlyOff[playerid] = 3;
			LACPanic[playerid]++;//LAC v2.0
			format(String,sizeof(String), "[�������]LAC:{AFAFAF} %s[%d] �������� ���������� ��� FlyHack",PlayerName[playerid], playerid);
			foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} �� ���� ������ ������������. {FF0000}�������: {AFAFAF}�������� ��� FlyHack");
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] �������� ���������� ��� FlyHack", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}

	}
	else{CheatFlySec[playerid] = 0;}
	//------ ������� �� FlyHack

	if (GetPlayerSpecialAction(playerid) == SPECIAL_ACTION_USEJETPACK && JetpackUsed[playerid] == 0 && Player[playerid][Banned] == 0)
	{//������ �� ��������� ��������
		new String[140]; Player[playerid][Banned] = 1; strmid(BannedBy[playerid], "LAC �� JetPack", 0, 25, 25); strmid(BanReason[playerid], "��� �� JetPack", 0, 25, 25); SavePlayer(playerid);
		format(String,sizeof(String), "{FF0000}LAC: {AFAFAF}%s[%d] ��� ������������� �������. {FF0000}�������:{AFAFAF} ��� �� Jetpack",PlayerName[playerid], playerid);
		SendClientMessageToAll(COLOR_RED,String);
		InEvent[playerid] = 0; JoinEvent[playerid] = 0;
		format(String, 120, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] ��� ������������� �������. �������: ��� �� JetPack", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
		WriteLog("GlobalLog", String);WriteLog("LAC", String);WriteLog("Bans", String);
	}//������ �� ��������� ��������
	
	//------ ������� �� SpeedHack ������ (� Slapper)
	if (LACPedSHOff[playerid] > 0 && LAFK[playerid] < 4) LACPedSHOff[playerid] --;
	if (GetPlayerSurfingVehicleID(playerid) != INVALID_VEHICLE_ID) LACPedSHOff[playerid] = 3;
	new Float:Speed, Float:vvx, Float:vvy, Float:vvz;
	GetPlayerVelocity(playerid, vvx,vvy,vvz);
	Speed = floatsqroot(((vvx*vvx)+(vvy*vvy)));
	if (Speed > 0.60 && OnFly[playerid] == 0 && LACPedSHOff[playerid] == 0 && Player[playerid][Banned] == 0)
	{
		LACPedSHTime[playerid]++;
		if (LACPedSHTime[playerid] >= 3)
		{	
			new String[140]; SetPlayerPos(playerid, LastPlayerX[playerid], LastPlayerY[playerid], LastPlayerZ[playerid]);
			LACPedSHOff[playerid] = 3; LACPanic[playerid]++;//LAC v2.0
			format(String,sizeof(String), "[�������]LAC:{AFAFAF} %s[%d] �������� ���������� ��� SpeedHack (������)",PlayerName[playerid], playerid);
			foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} �� ���� ����������. {FF0000}�������: {AFAFAF}�������� ��� SpeedHack (������)");
			format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: %s[%d] �������� ���������� ��� SpeedHack (������). Speed: %0.2f", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, Speed);
			WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}
	} 
	else LACPedSHTime[playerid] = 0;
	//------ ������� �� SpeedHack ������ (� Slapper)
	
	//------ ������������� �������� � �����
	if (NOPSetPlayerHealthAndArmourOff[playerid] > 0) NOPSetPlayerHealthAndArmourOff[playerid]--;
	new Float:xhealth, Float: xarmour;
    GetPlayerHealth(playerid,xhealth); GetPlayerArmour(playerid,xarmour);
	if (xhealth >= 1 && LAFK[playerid] < 4 && NOPSetPlayerHealthAndArmourOff[playerid] == 0 && PrestigeGM[playerid] == 0 && LSpecID[playerid] == -1)
	{//����� ��� � �����������
		new Float: deltahealth, Float: deltaarmour; //�� ������� ���������� ���������� ����� �������� � ��������
		deltahealth = xhealth - Player[playerid][PHealth];//�� ������� ���������� �������� �� ������� ������� ������, ��� �� ������� �������
		deltaarmour = xarmour - Player[playerid][PArmour];//�� ������� ���������� ����� �� ������� ������� ������, ��� �� ������� �������
/*
		new st[120];
		format(st, sizeof st, "ClientHealth: %d ServerHealth: %d HealthKick: %d/5", floatround(xhealth, floatround_round), floatround(Player[playerid][PHealth], floatround_round), NOPSetPlayerHealth[playerid]);
		SendClientMessage(playerid, -1, st);
		format(st, sizeof st, "ClientArmour: %d ServerArmour: %d ArmourKick: %d/5", floatround(xarmour, floatround_round), floatround(Player[playerid][PArmour], floatround_round), NOPSetPlayerArmour[playerid]);
		SendClientMessage(playerid, -1, st);
*/		
		if (deltahealth > 1.0 || deltahealth < -1.0) NOPSetPlayerHealth[playerid]++; else NOPSetPlayerHealth[playerid] = 0;
		if (deltaarmour > 1.0 || deltaarmour < -1.0) NOPSetPlayerArmour[playerid]++; else NOPSetPlayerArmour[playerid] = 0;
		SetPlayerHealth(playerid, Player[playerid][PHealth]);
		SetPlayerArmour(playerid, Player[playerid][PArmour]);
		
		if (NOPSetPlayerHealth[playerid] == 5)
		{//���������������� ��������
			SetPlayerChatBubble(playerid, "���������������� ��������", COLOR_RED, 225.0, 1000);
			//new String[140]; LSpawnPlayer(playerid); LACPanic[playerid]++;//LAC v2.0
			//NOPSetPlayerHealth[playerid] = 0; NOPSetPlayerArmour[playerid] = 0; 
			//format(String,sizeof(String), "[�������]LAC:{AFAFAF} �������� ������ %s[%d] �������������������. �������� ��� �� ����������",PlayerName[playerid], playerid);
			//foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			//SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} �� ���� ������ ������������. {FF0000}�������: {AFAFAF}���������������� ��������");
			//format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: �������� ������ %s[%d] �������������������. �������� ��� �� ����������", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			//WriteLog("GlobalLog", String);WriteLog("LAC", String);
			//
		}//���������������� ��������
		else if (NOPSetPlayerArmour[playerid] == 5)
		{//���������������� �����
			SetPlayerChatBubble(playerid, "���������������� �����", COLOR_RED, 225.0, 1000);
			//new String[140]; LSpawnPlayer(playerid); //LACPanic[playerid]++;//LAC v2.0
			//NOPSetPlayerHealth[playerid] = 0; NOPSetPlayerArmour[playerid] = 0; 
			//format(String,sizeof(String), "[�������]LAC:{AFAFAF} ����� ������ %s[%d] �������������������. �������� ��� �� ����������",PlayerName[playerid], playerid);
			//foreach(Player, cid) if (Player[cid][Admin] != 0 && Logged[cid] == 1) SendClientMessage(cid, COLOR_RED, String);
			//SendClientMessage(playerid, -1,"{FF0000}LAC:{AFAFAF} �� ���� ������ ������������. {FF0000}�������: {AFAFAF}���������������� �����");
			//format(String, 140, "%d.%d.%d a %d:%d:%d |   LAC: ����� ������ %s[%d] �������������������. �������� ��� �� ����������", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid);
			//WriteLog("GlobalLog", String);WriteLog("LAC", String);
		}//���������������� �����
	}//����� ��� � �����������
	else {NOPSetPlayerHealth[playerid] = 0; NOPSetPlayerArmour[playerid] = 0;}
	//------ ������������� �������� � �����
	
}//����� ���������
