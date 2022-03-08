if (XRTimer >= 0)
{
	XRTimer--; new String[60];
	format(String, sizeof String, "LEGENDARY RACE:~w~ %d sec. Players: %d", XRTimer, XRPlayers);
	TextDrawSetString(TextDrawEvent[EVENT_XRACE], String);
}
if (XRTimeToEnd > 0) XRTimeToEnd--;

if (XRTimer == 60 && XRid == 1)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Around San Andreas{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 32;//кол-во чекпоинтов вместе со стартом и финишем
	new xrmodel;
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	for(new i = 1; i < XRCPs; i+=3)
	{//определение транспорта для чеков
		xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];
	}//определение транспорта для чеков
	XRCarCP[0] = 448;
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}
if (XRTimer == 60 && XRid == 2)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Bon Voyage{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 30;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
	XRCarCP[0] = 473;//старт обязательно на надувной лодке
	XRCarCP[1] = 446;//squallo на первом чеке
}
if (XRTimer == 60 && XRid == 3)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Up And Down{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRTypeCP[XRCPs-1] = 4;//воздушный финиш
	XRCarCP[0] = 461;//старт на PCJ
	XRCarCP[3] = 513;XRCarCP[4] = 451;XRCarCP[10] = 568;XRCarCP[21] = 513;//stuntplane, turismo, bandito, stuntplane
	XRTypeCP[3] = 3;XRTypeCP[4] = 3;XRTypeCP[21] = 3;//Воздушные чекпоинты	
}

if (XRTimer == 60 && XRid == 4)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка <<{FFFFFF}Riders On The Storm{FFD700}>> начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать");
	XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
	XRCarCP[0] = 541;//старт на Bullet
	XRCarCP[9] = 541;//bullet
	XRCarCP[5] = 473;XRCarCP[16] = 473;//надувные лодки
	XRCarCP[6] = 446;XRCarCP[17] = 446;//squallo
	XRTypeCP[5] = 3;XRTypeCP[16] = 3;//воздушные чекпоинты
}

if (XRTimer == 60 && XRid == 5)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Crazy Turns{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 62;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	new xrmodel;
	for(new i = 1; i < XRCPs; i+=4)
	{//чеки смены транспорта
		xrmodel = random(126);XRCarCP[i] = XRCars1[xrmodel];
	}//чеки смены транспорта
	XRCarCP[0] = 471;//старт на квадрацикле
	XRTypeCP[XRCPs-1] = 1;//наземный финиш	
}

if (XRTimer == 60 && XRid == 6)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Vegas Race{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 35;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRTypeCP[XRCPs-1] = 1;//наземный финиш	
	XRCarCP[0] = 441;//старт на RC Bandit
	XRCarCP[22] = 441;XRCarCP[23] = 464;//RC на крыше гаража
	XRCarCP[2] = 559;XRCarCP[8] = 522;XRCarCP[12] = 560;XRCarCP[28] = 562;//Jester, NRG, Sultan, Elegy
	XRTypeCP[23] = 3;XRTypeCP[24] = 3;XRTypeCP[25] = 3;XRTypeCP[26] = 3;XRTypeCP[27] = 3;//воздушные чекпоинты
}

if (XRTimer == 60 && XRid == 7)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Dead Air{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 3;//воздушные чеки
	}//определение транспорта для чеков
	XRTypeCP[XRCPs-1] = 4;//воздушный финиш	
	XRCarCP[0] = 461;//старт на PCJ	
	XRCarCP[1] = 464;XRCarCP[4] = 464;XRCarCP[8] = 464;XRCarCP[10] = 464;//RC
	XRCarCP[2] = 513;XRCarCP[5] = 513;XRCarCP[9] = 513;XRCarCP[12] = 513;//StuntPlane
}

if (XRTimer == 60 && XRid == 8)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Road To Farm{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 43;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//обычные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 471;//старт на квадрацикле
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
	XRTypeCP[1] = 3;//воздушный чек вортекса
	XRCarCP[1] = 539;XRCarCP[2] = 560;XRCarCP[29] = 495;//Vortex, Sultan, SandKing
}

if (XRTimer == 60 && XRid == 9)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}UnderGround{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 29;new xrmodel;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		if(i == 1 || i == 7 || i == 15 || i == 24){xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];}//чеки смены авто		
		XRTypeCP[i] = 0;//обычные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 521;//стартовый транспорт
	XRTypeCP[XRCPs-1] = 1;XRTypeCP[22] = 3;//наземный финиш и круглый чек при прыжке в воду
	XRCarCP[22] = 473;//Надувная лодка
}

if (XRTimer == 60 && XRid == 10)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}San Fierro Tour{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 25;new xrmodel;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		if(i == 1 || i == 5 || i == 15 || i == 17){xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];}//чеки смены авто		
		XRTypeCP[i] = 0;//обычные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 509;//стартовый транспорт
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}

if (XRTimer == 60 && XRid == 11)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Into The Wild{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 35;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//обычные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 468;//стартовый транспорт - Sanchez
	XRCarCP[10] = 471;//cp 10 - Quad
	XRCarCP[21] = 444;//cp 21 - Monster
	XRCarCP[31] = 468;//cp 31 - Sanchez
	
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}
if (XRTimer == 60 && XRid == 12)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Drag Race{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 10; new xrmodel;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 522;
	xrmodel = random(20);XRCarCP[1] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[6] = XRCars9[xrmodel];
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}
if (XRTimer == 60 && XRid == 13)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Need For Speed{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 30;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 461; //стартовое авто
	XRCarCP[1] = 411; //infernus на первом чеке
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}
if (XRTimer == 60 && XRid == 14)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Восьмерка{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 66;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	new xrmodel;
	for(new i = 4; i < XRCPs; i+=4)
	{//чеки смены транспорта
		xrmodel = random(126);XRCarCP[i] = XRCars1[xrmodel];
	}//чеки смены транспорта
	XRCarCP[0] = 471;//старт на квадрацикле
	XRTypeCP[XRCPs-1] = 4;//воздушный финиш
}
if (XRTimer == 60 && XRid == 15)
{
	SendClientMessageToAll(COLOR_XR,"Легендарная Гонка <<{FFFFFF}San Fierro Drift{FFD700}>> начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"Используйте {FFFFFF}/xrace{FFD700} если хотите участвовать");
	XRCPs = 54;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 510; //стартовое авто
	XRCarCP[5] = 562; //elegy на пятом чеке
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}
if (XRTimer == 60 && XRid == 16)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Mountain{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 36;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 468;//старт на sanchez
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}
if (XRTimer == 60 && XRid == 17)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Не для слабаков{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 34;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		if (5 <= i <= 32) XRTypeCP[i] = 3; //воздушные чеки
		else XRTypeCP[i] = 0; //наземные чеки
		XRCarCP[i] = -1;//без трансформации
	}//определение транспорта для чеков
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
	XRCarCP[0] = 481; XRCarCP[32] = 481;//BMX	
	XRCarCP[5] = 464;//RC
	XRCarCP[8] = 476;//Rustler
}
if (XRTimer == 60 && XRid == 18)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Dirt And Dust{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 23;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	new xrmodel;
	xrmodel = random(20);XRCarCP[3] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[14] = XRCars9[xrmodel];
	XRCarCP[0] = 468; XRCarCP[21] = 468;//sanchez
	XRTypeCP[XRCPs-1] = 4;//воздушный финиш
}
if (XRTimer == 60 && XRid == 19)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Los Santos Highway{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 37;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	new xrmodel;
	xrmodel = random(20);XRCarCP[1] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[13] = XRCars9[xrmodel];
	xrmodel = random(20);XRCarCP[25] = XRCars9[xrmodel];
	XRCarCP[0] = 571;//kart
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}
if (XRTimer == 60 && XRid == 20)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Fast And Furious{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 33;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//наземные чеки
	}//определение транспорта для чеков
	new xrmodel;
	for(new i = 1; i < XRCPs; i+=6)
	{//определение транспорта для чеков
		xrmodel = random(20);XRCarCP[i] = XRCars9[xrmodel];
	}//определение транспорта для чеков
	XRCarCP[0] = 522;//nrg
	XRTypeCP[XRCPs-1] = 1;//наземный финиш
}

if (XRTimer == 60 && XRid == 21)
{
	SendClientMessageToAll(COLOR_XR,"| Легендарная Гонка [{FFFFFF}Путь гепарда{FFD700}] начнется через {FFFFFF}минуту{FFD700}!");
	SendClientMessageToAll(COLOR_XR,"| Используйте {FFFFFF}/xrace{FFD700}, если хотите участвовать.");
	XRCPs = 22;//кол-во чекпоинтов вместе со стартом и финишем
	for(new i = 0; i < XRCPs; i++)
	{//определение транспорта для чеков
		XRCarCP[i] = -1;//без трансформации
		XRTypeCP[i] = 0;//обычные чеки
	}//определение транспорта для чеков
	XRCarCP[0] = 522;//стартовый транспорт - nrg 500
	XRCarCP[1] = 411;//cp 1 - infernus
	XRCarCP[3] = 446;//cp 3 - squalo
	XRCarCP[5] = 541;//cp 5 - bullet
	XRCarCP[8] = 522;//cp 8 - nrg 500

	XRTypeCP[XRCPs-1] = 1;//наземный финиш
	XRTypeCP[3] = 3;
}

if (XRTimeToEnd > 0)
{//Во время проведения гонки
	new eid;
	for (new i = 0; i < 25; i++) 
	{//Цикл для участников гонки
		eid = XRPlayersList[i];
		if (!IsPlayerConnected(eid) || XRStarted[eid] == 0) continue;
		
		if (LAFK[eid] >= 30)
		{
			XRCarID[eid] = 0; JoinEvent[eid] = 0; XRStarted[eid] = 0;
			SendClientMessage(eid,COLOR_RED,"Вы были кикнуты из игры за AFK на гонке более 30 секунд");
			DisablePlayerRaceCheckpoint(eid); Kick(eid); continue;
		}
		else if (LAFK[eid] >= 20){SendClientMessage(eid,COLOR_RED,"Вы будете выброшены из гонки, если не начнете двигаться!");}
		new Float: hp;	GetPlayerHealth(eid,hp); if (hp < 1.0) LeaveEvent(eid,EVENT_XRACE);//Если игрок умер - покидает гонку
		if (IsPlayerInAnyVehicle(eid) && GetPlayerVehicleID(eid) != XRCarID[eid]) RemovePlayerFromVehicle(eid);
		if (GetPlayerSurfingVehicleID(eid) != INVALID_VEHICLE_ID)
		{//Игрок на крыше чьего-то авто
			new Float: x, Float: y, Float: z; GetPlayerPos(eid, x, y, z); SetPlayerPos(eid, x, y, z + 2);
			SendClientMessage(eid, COLOR_RED, "Во время гонки запрещено стоять на крыше чужого транспорта!");
		}//Игрок на крыше чьего-то авто
		if (XRTimeToEnd == 719){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "2",1000,6);}
		if (XRTimeToEnd == 718){PlayerPlaySound(eid,1056,0.0,0.0,0.0);GameTextForPlayer(eid, "1",1000,6);}
		if (XRTimeToEnd == 717)
		{//В момент, когда игроки начинают ехать
			PlayerPlaySound(eid,1057,0.0,0.0,0.0);
			GameTextForPlayer(eid, "GO",1000,6);
			TogglePlayerControllable(eid,1);
			ResetPlayerWeapons(eid);
		}//В момент, когда игроки начинают ехать
		if (XRTimeToEnd == 1)
		{//лимит по времени
			DestroyVehicle(XRCarID[eid]); XRCarID[eid] = 0; 
			SendClientMessage(eid,COLOR_XR,"Легендарная Гонка завершена (Лимит по времени: {FFFFFF}15{FFD700} минут)");	 
			XRTimeToEnd = 0;JoinEvent[eid] = 0;XRStarted[eid] = 0;SetPlayerVirtualWorld(eid,0);
			DisablePlayerRaceCheckpoint(eid);
			ShowClanZones(eid); // покажем клановые зоны
			XRTimer = GetEventRestartTime();
			while (PrevXRid == XRid) XRid = random(MAX_XRACE) + 1; //выбор новой трассы
			PrevXRid = XRid;
		}//лимит по времени
	}//Цикл для участников гонки
	if (XRPlayers == 0)
	{
		SendClientMessageToAll(COLOR_XR,"Легендарная Гонка завершена"); XRTimeToEnd = 0;
		XRTimer = GetEventRestartTime();
		while (PrevXRid == XRid) XRid = random(MAX_XRACE) + 1; //выбор новой трассы
		PrevXRid = XRid;
	}
}//Во время гонки


if (XRTimer == 1)
{//Старт гонки
	for (new i = 0; i < 25; i++) XRPlayersList[i] = -1;//очищаем список игроков на гонке
	new i = 0; //Ниже заполняем список игроков на гонке
	foreach(Player, cid) if (JoinEvent[cid] == EVENT_XRACE) {XRPlayersList[i] = cid; i++;}

	new cid;
	for (i = 0; i < 25; i++) 
	{//Цикл для участников гонки
		cid = XRPlayersList[i];
		if (!IsPlayerConnected(cid)) continue;
		
		if (IsPlayerInRaceCheckpoint(cid))
		{//игрок в чеке старт
			DisablePlayerRaceCheckpoint(cid);FlipCount[cid] = 3;
			XRStarted[cid] = 1;LAFK[cid] = 0;
			TextDrawHideForPlayer(cid, TextDrawEvent[EVENT_XRACE]);
			
			if (XRid == 1)
			{//гонка Around San Andreas
				SetPlayerRaceCheckpoint(cid, 0, XRACE1[1][0], XRACE1[1][1], XRACE1[1][2], XRACE1[2][0], XRACE1[2][1], XRACE1[2][2], 7);
			}//гонка Around San Andreas	
			if (XRid == 2)
			{//гонка Around Bon Voyage
				SetPlayerRaceCheckpoint(cid, 0, XRACE2[1][0], XRACE2[1][1], XRACE2[1][2], XRACE2[2][0], XRACE2[2][1], XRACE2[2][2], 7);
			}//гонка Around Bon Voyage
			if (XRid == 3)
			{//гонка Around Up And Down
				SetPlayerRaceCheckpoint(cid, 0, XRACE3[1][0], XRACE3[1][1], XRACE3[1][2], XRACE3[2][0], XRACE3[2][1], XRACE3[2][2], 7);
			}//гонка Around Up And Down	
			if (XRid == 4)
			{//гонка Riders On The Storm
				SetPlayerRaceCheckpoint(cid, 0, XRACE4[1][0], XRACE4[1][1], XRACE4[1][2], XRACE4[2][0], XRACE4[2][1], XRACE4[2][2], 7);
			}//гонка Riders On The Storm	
			if (XRid == 5)
			{//гонка Crazy Turns
				SetPlayerRaceCheckpoint(cid, 0, XRACE5[1][0], XRACE5[1][1], XRACE5[1][2], XRACE5[2][0], XRACE5[2][1], XRACE5[2][2], 7);
			}//гонка Crazy Turns
			if (XRid == 6)
			{//гонка Vegas Race
				SetPlayerRaceCheckpoint(cid, 0, XRACE6[1][0], XRACE6[1][1], XRACE6[1][2], XRACE6[2][0], XRACE6[2][1], XRACE6[2][2], 7);
			}//гонка Vegas Race
			if (XRid == 7)
			{//гонка Vegas Race
				SetPlayerRaceCheckpoint(cid, 3, XRACE7[1][0], XRACE7[1][1], XRACE7[1][2], XRACE7[2][0], XRACE7[2][1], XRACE7[2][2], 7);
			}//гонка Vegas Race
			if (XRid == 8)
			{//гонка Road To Farm
				SetPlayerRaceCheckpoint(cid, 3, XRACE8[1][0], XRACE8[1][1], XRACE8[1][2], XRACE8[2][0], XRACE8[2][1], XRACE8[2][2], 7);
			}//гонка Road To Farm
			if (XRid == 9)
			{//гонка UnderGround
				SetPlayerRaceCheckpoint(cid, 0, XRACE9[1][0], XRACE9[1][1], XRACE9[1][2], XRACE9[2][0], XRACE9[2][1], XRACE9[2][2], 7);
			}//гонка UnderGround
			if (XRid == 10)
			{//гонка San Fierro Tour
				SetPlayerRaceCheckpoint(cid, 0, XRACE10[1][0], XRACE10[1][1], XRACE10[1][2], XRACE10[2][0], XRACE10[2][1], XRACE10[2][2], 7);
			}//гонка San Fierro Tour
			if (XRid == 11)
			{//гонка Into The Wild
				SetPlayerRaceCheckpoint(cid, 0, XRACE11[1][0], XRACE11[1][1], XRACE11[1][2], XRACE11[2][0], XRACE11[2][1], XRACE11[2][2], 7);
			}//гонка Into The Wild
			if (XRid == 12)
			{//гонка Drag Race
				SetPlayerRaceCheckpoint(cid, 0, XRACE12[1][0], XRACE12[1][1], XRACE12[1][2], XRACE12[2][0], XRACE12[2][1], XRACE12[2][2], 7);
			}//гонка Drag Race
			if (XRid == 13)
			{//гонка Need For Speed
				SetPlayerRaceCheckpoint(cid, 0, XRACE13[1][0], XRACE13[1][1], XRACE13[1][2], XRACE13[2][0], XRACE13[2][1], XRACE13[2][2], 7);
			}//гонка Need For Speed
			if (XRid == 14)
			{//гонка Восьмерка
				SetPlayerRaceCheckpoint(cid, 0, XRACE14[1][0], XRACE14[1][1], XRACE14[1][2], XRACE14[2][0], XRACE14[2][1], XRACE14[2][2], 7);
			}//гонка Восьмерка
			if (XRid == 15)
			{//гонка San Fierro Drift
				SetPlayerRaceCheckpoint(cid, 0, XRACE15[1][0], XRACE15[1][1], XRACE15[1][2], XRACE15[2][0], XRACE15[2][1], XRACE15[2][2], 7);
			}//гонка San Fierro Drift
			if (XRid == 16)
			{//гонка Mountain
				SetPlayerRaceCheckpoint(cid, 0, XRACE16[1][0], XRACE16[1][1], XRACE16[1][2], XRACE16[2][0], XRACE16[2][1], XRACE16[2][2], 7);
			}//гонка Mountain
			if (XRid == 17)
			{//гонка Не для слабаков
				SetPlayerRaceCheckpoint(cid, 0, XRACE17[1][0], XRACE17[1][1], XRACE17[1][2], XRACE17[2][0], XRACE17[2][1], XRACE17[2][2], 7);
			}//гонка Не для слабаков
			if (XRid == 18)
			{//гонка Dirt And Dust
				SetPlayerRaceCheckpoint(cid, 0, XRACE18[1][0], XRACE18[1][1], XRACE18[1][2], XRACE18[2][0], XRACE18[2][1], XRACE18[2][2], 7);
			}//гонка Dirt And Dust
			if (XRid == 19)
			{//гонка Los Santos Highway
				SetPlayerRaceCheckpoint(cid, 0, XRACE19[1][0], XRACE19[1][1], XRACE19[1][2], XRACE19[2][0], XRACE19[2][1], XRACE19[2][2], 7);
			}//гонка Los Santos Highway
			if (XRid == 20)
			{//гонка Fast And Furious
				SetPlayerRaceCheckpoint(cid, 0, XRACE20[1][0], XRACE20[1][1], XRACE20[1][2], XRACE20[2][0], XRACE20[2][1], XRACE20[2][2], 7);
			}//гонка Fast And Furious
			if (XRid == 21)
			{//гонка Путь гепарда
				SetPlayerRaceCheckpoint(cid, 0, XRACE21[1][0], XRACE21[1][1], XRACE21[1][2], XRACE21[2][0], XRACE21[2][1], XRACE21[2][2], 7);
			}//гонка Путь гепарда
			
			XRPlayerCP[cid] = 1;//активен чек N1
			TogglePlayerControllable(cid,0);PlayerPlaySound(cid,1056,0.0,0.0,0.0);GameTextForPlayer(cid, "3",1000,6);
			SetCameraBehindPlayer(cid);SetVehicleVelocity(GetPlayerVehicleID(cid), 0.0, 0.0, 0.0);
			GetPlayerPos(cid,XRxx[cid],XRy[cid],XRz[cid]);GetVehicleZAngle(XRCarID[cid],XRa[cid]);
			XRvx[cid] = 0.0; XRvy[cid] = 0.0; XRvz[cid] = 0.0;
		}//игрок в чеке старта
		else
		{
			if (JoinEvent[cid] == EVENT_XRACE)
			{
				SendClientMessage(cid,COLOR_RED,"Внимание! Вы не были на старте гонки");
				JoinEvent[cid] = 0;DisablePlayerRaceCheckpoint(cid); SetPlayerVirtualWorld(cid,0); LSpawnPlayer(cid); ShowClanZones(cid); // покажем клановые зоны
			}
		}
	}//Цикл для участников гонки
	new String[140];
	format (String, sizeof(String),"Легендарная Гонка <<{FFFFFF}%s{FFD700}>> стартовала. Игроков: {FFFFFF}%d",XRName[XRid], XRPlayers);
	SendClientMessageToAll(COLOR_XR,String);	
	XRTimeToEnd = 720;XRpos = 0;
}//Старт гонки
