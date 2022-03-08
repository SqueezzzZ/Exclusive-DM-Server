    if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0)
    {
        SetPlayerVirtualWorld(playerid, TDM_WORLD);
        new rand = random(12);
    	switch(TDMid)
        {
            case 1:
            {
            	if(TDMTeam[playerid] == 1)		{x = F1SPAWNRED[rand][0]; y = F1SPAWNRED[rand][1]; z = F1SPAWNRED[rand][2]; Angle = F1SPAWNRED[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = F1SPAWNBLUE[rand][0]; y = F1SPAWNBLUE[rand][1]; z = F1SPAWNBLUE[rand][2]; Angle = F1SPAWNBLUE[rand][3];}
				w1 = 31; w1ammo = 20000;//M4
    			w2 = 27; w2ammo = 20000;//SPAS12
				w3 = 24; w3ammo = 20000;//Deagle
            }
            case 2:
            {
            	if(TDMTeam[playerid] == 1)		{x = F2SPAWNRED[rand][0]; y = F2SPAWNRED[rand][1]; z = F2SPAWNRED[rand][2]; Angle = F2SPAWNRED[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = F2SPAWNBLUE[rand][0]; y = F2SPAWNBLUE[rand][1]; z = F2SPAWNBLUE[rand][2]; Angle = F2SPAWNBLUE[rand][3];}
                w1 = 25; w1ammo = 20000;//drobash
    			w2 = 28; w2ammo = 20000;//SPAS12
				w3 = 30; w3ammo = 20000;//Deagle
            }
            case 3:
            {
            	if(TDMTeam[playerid] == 1)		{x = F3SPAWNRED[rand][0]; y = F3SPAWNRED[rand][1]; z = F3SPAWNRED[rand][2]; Angle = F3SPAWNRED[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = F3SPAWNBLUE[rand][0]; y = F3SPAWNBLUE[rand][1]; z = F3SPAWNBLUE[rand][2]; Angle = F3SPAWNBLUE[rand][3];}
            	w1 = 31; w1ammo = 20000;
    			w2 = 32; w2ammo = 20000;
				w3 = 24; w3ammo = 20000;
				GiveWeapon(playerid,16,15);
            }
            case 4:
            {
            	if(TDMTeam[playerid] == 1)		{x = F4SPAWNRED[rand][0]; y = F4SPAWNRED[rand][1]; z = F4SPAWNRED[rand][2]; Angle = F4SPAWNRED[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = F4SPAWNBLUE[rand][0]; y = F4SPAWNBLUE[rand][1]; z = F4SPAWNBLUE[rand][2]; Angle = F4SPAWNBLUE[rand][3];}
				w1 = 31; w1ammo = 2000;
    			w2 = 16; w2ammo = 20;
				w3 = 28; w3ammo = 2000;
				GiveWeapon(playerid,4,1);
            }
            case 5:
            {
            	if(TDMTeam[playerid] == 1)		{x = F5SPAWNRED[rand][0]; y = F5SPAWNRED[rand][1]; z = F5SPAWNRED[rand][2]; Angle = F5SPAWNRED[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = F5SPAWNBLUE[rand][0]; y = F5SPAWNBLUE[rand][1]; z = F5SPAWNBLUE[rand][2]; Angle = F5SPAWNBLUE[rand][3];}
            	w1 = 31; w1ammo = 2000;
    			w2 = 33; w2ammo = 2000;
				w3 = 32; w3ammo = 2000;
				GiveWeapon(playerid,41,1000);
            }
            case 6:
            {
            	if(TDMTeam[playerid] == 1)		{x = TDM6WHITE[rand][0]; y = TDM6WHITE[rand][1]; z = TDM6WHITE[rand][2]; Angle = TDM6WHITE[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = TDM6BLACK[rand][0]; y = TDM6BLACK[rand][1]; z = TDM6BLACK[rand][2]; Angle = TDM6BLACK[rand][3];}
            	w1 = 34; w1ammo = 40;
    			w2 = 31; w2ammo = 2000;
				w3 = 24; w3ammo = 500;
            }
            case 7:
            {
            	if(TDMTeam[playerid] == 1)		{x = TDM7WHITE[rand][0]; y = TDM7WHITE[rand][1]; z = TDM7WHITE[rand][2]; Angle = TDM7WHITE[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = TDM7BLACK[rand][0]; y = TDM7BLACK[rand][1]; z = TDM7BLACK[rand][2]; Angle = TDM7BLACK[rand][3];}
				w1 = 30; w1ammo = 2000;
    			w2 = 24; w2ammo = 500;
				w3 = 25; w3ammo = 100;
            }
            case 8:
            {
            	if(TDMTeam[playerid] == 1)		{x = TDM8WHITE[rand][0]; y = TDM8WHITE[rand][1]; z = TDM8WHITE[rand][2]; Angle = TDM8WHITE[rand][3];}
            	else if(TDMTeam[playerid] == 2) {x = TDM8BLACK[rand][0]; y = TDM8BLACK[rand][1]; z = TDM8BLACK[rand][2]; Angle = TDM8BLACK[rand][3];}
            	w1 = 26; w1ammo = 500;
    			w2 = 9; w2ammo = 1;
				w3 = 31; w3ammo = 1500;
            }
            default: {}
        }
	}

//------------
/*	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 1)
	{//спавн на 1 ctf
	    //LostFlag(playerid,TDMid);
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(F1SPAWNRED));
			
			x = F1SPAWNRED[rand][0]; y = F1SPAWNRED[rand][1]; z = F1SPAWNRED[rand][2]; Angle = F1SPAWNRED[rand][3];
			w1 = 31; w1ammo = 20000;//M4
    		w2 = 27; w2ammo = 20000;//SPAS12
			w3 = 24; w3ammo = 20000;//Deagle
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(F1SPAWNBLUE));
			x = F1SPAWNBLUE[rand][0]; y = F1SPAWNBLUE[rand][1]; z = F1SPAWNBLUE[rand][2]; Angle = F1SPAWNBLUE[rand][3];
  			w1 = 31; w1ammo = 20000;//M4
    		w2 = 27; w2ammo = 20000;//SPAS12
			w3 = 24; w3ammo = 20000;//Deagle
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
	}//спавн на 1 ctf
	
	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 2)
	{//спавн на 2 ctf
	    //LostFlag(playerid,TDMid);
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(F2SPAWNRED));
			x = F2SPAWNRED[rand][0]; y = F2SPAWNRED[rand][1]; z = F2SPAWNRED[rand][2]; Angle = F2SPAWNRED[rand][3];
			w1 = 25; w1ammo = 20000;//drobash
    		w2 = 28; w2ammo = 20000;//SPAS12
			w3 = 30; w3ammo = 20000;//Deagle
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(F2SPAWNBLUE));
			x = F2SPAWNBLUE[rand][0]; y = F2SPAWNBLUE[rand][1]; z = F2SPAWNBLUE[rand][2]; Angle = F2SPAWNBLUE[rand][3];
  			w1 = 25; w1ammo = 20000;//drobash
    		w2 = 28; w2ammo = 20000;//тек
			w3 = 30; w3ammo = 20000;//ак47
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
	}//спавн на 2 ctf
	
	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 3)
	{//спавн на 3 ctf
	    //LostFlag(playerid,TDMid);
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(F3SPAWNRED));
			x = F3SPAWNRED[rand][0]; y = F3SPAWNRED[rand][1]; z = F3SPAWNRED[rand][2]; Angle = F3SPAWNRED[rand][3];
			w1 = 31; w1ammo = 20000;
    		w2 = 32; w2ammo = 20000;
			w3 = 24; w3ammo = 20000;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
			GiveWeapon(playerid,16,15);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(F3SPAWNBLUE));
			x = F3SPAWNBLUE[rand][0]; y = F3SPAWNBLUE[rand][1]; z = F3SPAWNBLUE[rand][2]; Angle = F3SPAWNBLUE[rand][3];
  			w1 = 31; w1ammo = 20000;
    		w2 = 32; w2ammo = 20000;
			w3 = 24; w3ammo = 20000;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
			GiveWeapon(playerid,16,15);
		}
	}//спавн на 3 ctf
	
	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 4)
	{//спавн на 4 ctf
	    //LostFlag(playerid,TDMid);
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(F4SPAWNRED));
			x = F4SPAWNRED[rand][0]; y = F4SPAWNRED[rand][1]; z = F4SPAWNRED[rand][2]; Angle = F4SPAWNRED[rand][3];
			w1 = 31; w1ammo = 2000;
    		w2 = 16; w2ammo = 20;
			w3 = 28; w3ammo = 2000;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
			GiveWeapon(playerid,4,1);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(F4SPAWNBLUE));
			x = F4SPAWNBLUE[rand][0]; y = F4SPAWNBLUE[rand][1]; z = F4SPAWNBLUE[rand][2]; Angle = F4SPAWNBLUE[rand][3];
  			w1 = 31; w1ammo = 2000;
    		w2 = 16; w2ammo = 20;
			w3 = 28; w3ammo = 2000;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
			GiveWeapon(playerid,4,1);
		}
	}//спавн на 4 ctf
	
	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 5)
	{//спавн на 5 ctf
	    //LostFlag(playerid,TDMid);
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(F5SPAWNRED));
			x = F5SPAWNRED[rand][0]; y = F5SPAWNRED[rand][1]; z = F5SPAWNRED[rand][2]; Angle = F5SPAWNRED[rand][3];
			w1 = 31; w1ammo = 2000;
    		w2 = 33; w2ammo = 2000;
			w3 = 32; w3ammo = 2000;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
			GiveWeapon(playerid,41,1000);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(F5SPAWNBLUE));
			x = F5SPAWNBLUE[rand][0]; y = F5SPAWNBLUE[rand][1]; z = F5SPAWNBLUE[rand][2]; Angle = F5SPAWNBLUE[rand][3];
  			w1 = 31; w1ammo = 2000;
    		w2 = 33; w2ammo = 20;
			w3 = 32; w3ammo = 2000;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
			GiveWeapon(playerid,41,1000);
		}
	}//спавн на 5 ctf
	
	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 6)
	{//спавн на 6 tdm
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(TDM6WHITE));
			x = TDM6WHITE[rand][0]; y = TDM6WHITE[rand][1]; z = TDM6WHITE[rand][2]; Angle = TDM6WHITE[rand][3];
			w1 = 34; w1ammo = 40;
    		w2 = 31; w2ammo = 2000;
			w3 = 24; w3ammo = 500;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(TDM6BLACK));
			x = TDM6BLACK[rand][0]; y = TDM6BLACK[rand][1]; z = TDM6BLACK[rand][2]; Angle = TDM6BLACK[rand][3];
  			w1 = 34; w1ammo = 40;
    		w2 = 31; w2ammo = 2000;
			w3 = 24; w3ammo = 500;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
	}//спавн на 6 tdm
	
	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 7)
	{//спавн на 7 tdm
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(TDM7WHITE));
			x = TDM7WHITE[rand][0]; y = TDM7WHITE[rand][1]; z = TDM7WHITE[rand][2]; Angle = TDM7WHITE[rand][3];
			w1 = 30; w1ammo = 2000;
    		w2 = 24; w2ammo = 500;
			w3 = 25; w3ammo = 100;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(TDM7BLACK));
			x = TDM7BLACK[rand][0]; y = TDM7BLACK[rand][1]; z = TDM7BLACK[rand][2]; Angle = TDM7BLACK[rand][3];
  			w1 = 30; w1ammo = 2000;
    		w2 = 24; w2ammo = 500;
			w3 = 25; w3ammo = 100;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
	}//спавн на 7 tdm
	
	if (JoinEvent[playerid] == EVENT_TDM && TDMTimeToEnd > 0 && TDMid == 8)
	{//спавн на 8 tdm
		if(TDMTeam[playerid] == 1)
		{
			new rand = random(sizeof(TDM8WHITE));
			x = TDM8WHITE[rand][0]; y = TDM8WHITE[rand][1]; z = TDM8WHITE[rand][2]; Angle = TDM8WHITE[rand][3];
			w1 = 26; w1ammo = 500;
    		w2 = 9; w2ammo = 1;
			w3 = 31; w3ammo = 1500;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
		else if(TDMTeam[playerid] == 2)
		{
			new rand = random(sizeof(TDM8BLACK));
			x = TDM8BLACK[rand][0]; y = TDM8BLACK[rand][1]; z = TDM8BLACK[rand][2]; Angle = TDM8BLACK[rand][3];
  			w1 = 26; w1ammo = 500;
    		w2 = 9; w2ammo = 1;
			w3 = 31; w3ammo = 1500;
			SetPlayerVirtualWorld(playerid, TDM_WORLD);
		}
	}//спавн на 8 tdm
*/
