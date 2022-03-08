    if (JoinEvent[playerid] == EVENT_PDM && PDMTimeToEnd > 0)
    {
        SetPlayerVirtualWorld(playerid, PDM_WORLD);
        
        if(PDMTeam[playerid] == 1)		{x = PDMBlueSpawns[PDMid][0]-10.0+frandom(20); y = PDMBlueSpawns[PDMid][1]-10.0+frandom(20); z = PDMBlueSpawns[PDMid][2]; Angle = PDMBlueSpawns[PDMid][3];}
        else if(PDMTeam[playerid] == 2) {x = PDMRedSpawns[PDMid][0]-10.0+frandom(20); y = PDMRedSpawns[PDMid][1]-10.0+frandom(20); z = PDMRedSpawns[PDMid][2]; Angle = PDMRedSpawns[PDMid][3];}
        
    	switch(PDMid)
        {
            case 1:
            {
				w1 = 31; w1ammo = 20000;//M4
    			w2 = 27; w2ammo = 20000;//SPAS12
				w3 = 24; w3ammo = 20000;//Deagle
            }
            case 2:
            {
                w1 = 25; w1ammo = 20000;//drobash
    			w2 = 28; w2ammo = 20000;//SPAS12
				w3 = 30; w3ammo = 20000;//Deagle
            }
            default: {}
        }
	}
