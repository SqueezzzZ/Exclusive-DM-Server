	switch(ZMid)
	{
		case 1: {new rand = random(sizeof(ZOMBIE1SPAWN));x = ZOMBIE1SPAWN[rand][0]; y = ZOMBIE1SPAWN[rand][1]; z = ZOMBIE1SPAWN[rand][2];Angle = ZOMBIE1SPAWN[rand][3];}
		case 2: {new rand = random(sizeof(ZOMBIE2SPAWN));x = ZOMBIE2SPAWN[rand][0]; y = ZOMBIE2SPAWN[rand][1]; z = ZOMBIE2SPAWN[rand][2];Angle = ZOMBIE2SPAWN[rand][3];}
		case 3: {new rand = random(sizeof(ZOMBIE3SPAWN));x = ZOMBIE3SPAWN[rand][0]; y = ZOMBIE3SPAWN[rand][1]; z = ZOMBIE3SPAWN[rand][2];Angle = ZOMBIE3SPAWN[rand][3];}
		case 4: {new rand = random(sizeof(ZOMBIE4SPAWN));x = ZOMBIE4SPAWN[rand][0]; y = ZOMBIE4SPAWN[rand][1]; z = ZOMBIE4SPAWN[rand][2];Angle = ZOMBIE4SPAWN[rand][3];}
		case 5: {new rand = random(sizeof(ZOMBIE5SPAWN));x = ZOMBIE5SPAWN[rand][0]; y = ZOMBIE5SPAWN[rand][1]; z = ZOMBIE5SPAWN[rand][2];Angle = ZOMBIE5SPAWN[rand][3];}
		case 6: {new rand = random(sizeof(ZOMBIE6SPAWN));x = ZOMBIE6SPAWN[rand][0]; y = ZOMBIE6SPAWN[rand][1]; z = ZOMBIE6SPAWN[rand][2];Angle = ZOMBIE6SPAWN[rand][3];}
		case 7: {new rand = random(sizeof(ZOMBIE7SPAWN));x = ZOMBIE7SPAWN[rand][0]; y = ZOMBIE7SPAWN[rand][1]; z = ZOMBIE7SPAWN[rand][2];Angle = ZOMBIE7SPAWN[rand][3];}
		case 8: {new rand = random(sizeof(ZOMBIE8SPAWN));x = ZOMBIE8SPAWN[rand][0]; y = ZOMBIE8SPAWN[rand][1]; z = ZOMBIE8SPAWN[rand][2];Angle = ZOMBIE8SPAWN[rand][3];}
		case 9: {new rand = random(sizeof(ZOMBIE9SPAWN));x = ZOMBIE9SPAWN[rand][0]; y = ZOMBIE9SPAWN[rand][1]; z = ZOMBIE9SPAWN[rand][2];Angle = ZOMBIE9SPAWN[rand][3];}
		case 10: {new rand = random(sizeof(ZOMBIE10SPAWN));x = ZOMBIE10SPAWN[rand][0]; y = ZOMBIE10SPAWN[rand][1]; z = ZOMBIE10SPAWN[rand][2];Angle = ZOMBIE10SPAWN[rand][3];}
		case 11: {new rand = random(sizeof(ZOMBIE11SPAWN));x = ZOMBIE11SPAWN[rand][0]; y = ZOMBIE11SPAWN[rand][1]; z = ZOMBIE11SPAWN[rand][2];Angle = ZOMBIE11SPAWN[rand][3];}
		case 12: {new rand = random(sizeof(ZOMBIE12SPAWN));x = ZOMBIE12SPAWN[rand][0]; y = ZOMBIE12SPAWN[rand][1]; z = ZOMBIE12SPAWN[rand][2];Angle = ZOMBIE12SPAWN[rand][3];}
		case 13: {new rand = random(sizeof(ZOMBIE13SPAWN));x = ZOMBIE13SPAWN[rand][0]; y = ZOMBIE13SPAWN[rand][1]; z = ZOMBIE13SPAWN[rand][2];Angle = ZOMBIE13SPAWN[rand][3];}
		case 14: {new rand = random(sizeof(ZOMBIE14SPAWN));x = ZOMBIE14SPAWN[rand][0]; y = ZOMBIE14SPAWN[rand][1]; z = ZOMBIE14SPAWN[rand][2];Angle = ZOMBIE14SPAWN[rand][3];}
		case 15: {new rand = random(sizeof(ZOMBIE15SPAWN));x = ZOMBIE15SPAWN[rand][0]; y = ZOMBIE15SPAWN[rand][1]; z = ZOMBIE15SPAWN[rand][2];Angle = ZOMBIE15SPAWN[rand][3];}
		case 16: {new rand = random(sizeof(ZOMBIE16SPAWN));x = ZOMBIE16SPAWN[rand][0]; y = ZOMBIE16SPAWN[rand][1]; z = ZOMBIE16SPAWN[rand][2];Angle = ZOMBIE16SPAWN[rand][3];}
	}
	
	SetPlayerVirtualWorld(playerid, 663);	
	if (ZMIsPlayerIsZombie[playerid] == 0)
	{
		if (ZMTimeToFirstZombie == 0) {ZMIsPlayerIsZombie[playerid] = 1; SendClientMessage(playerid,COLOR_ZOMBIE,"Внимание! Вы стали зомби - атакуйте выживших!");}
		else {w1 = 24; w1ammo = 70; w2 = 25; w2ammo = 50;}
	}
