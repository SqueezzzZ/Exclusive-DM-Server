#define AIRDROP_HUNGRYGAMES1 1
#define AIRDROP_HUNGRYGAMES2 2
#define AIRDROP_HUNGRYGAMES3 3
#define AIRDROP_HUNGRYGAMES4 4
#define AIRDROP_HUNGRYGAMES5 5

#define AIRDROP_SNIPER 6 //Снайперка из шашки
#define AIRDROP_RPG 7 //RPG из шашки
#define AIRDROP_GLOBAL 8 //Глобальный AirDrop, который спавнится сервером каждые 30 минут

CreateAirDrop(type, Float: x, Float: y, Float: z, worldid = 0, time = 30, Float: speed = 2.0)
{
	new objectid;
	switch(worldid)
	{
		case 0: objectid = CreateDynamicObjectEx(18849, x, y, z + 6.5 + time * speed, 0.00000, 0.00000, 0.00000, 5000.000, 5000.000, {0});
		case 702: objectid = CreateDynamicObjectEx(18849, x, y, z + 6.5 + time * speed, 0.00000, 0.00000, 0.00000, 5000.000, 5000.000, {702});
		default: objectid = CreateDynamicObjectEx(18849, x, y, z + 6.5 + time * speed, 0.00000, 0.00000, 0.00000, 5000.000, 5000.000, {-1});
	}
	MoveDynamicObject(objectid, x, y, z + 6.5, speed);
	SetTimerEx("OnAirDropLanded" , time * 1000, false, "ddfffd", type, objectid, x, y, z, worldid);
	return 1;
}

forward OnAirDropLanded(type, objectid, Float: x, Float: y, Float: z, worldid);
public OnAirDropLanded(type, objectid, Float: x, Float: y, Float: z, worldid)
{
	DestroyDynamicObject(objectid);
	
	switch(type)
	{
		case AIRDROP_HUNGRYGAMES1 .. AIRDROP_HUNGRYGAMES5: //AirDrop на голодных играх
			CreateHungryGamesWeapon(type, x, y, z);
		case AIRDROP_SNIPER, AIRDROP_RPG: //AirDrop оружия из шашки
			CreateAirDropPickup(type, x, y, z);
		case AIRDROP_GLOBAL: //Global AirDrop
			CreateAirDropPickup(type, x, y, z);
	}
	
	
	return 1;
}


///////////////////////////AirDrop Pickup
CreateAirDropPickup(type, Float: x, Float: y, Float: z)
{
	new pickupid = CreateDynamicPickup(2919, 1, x, y, z, 0);
	DynamicPickup[pickupid][Type] = PICKUP_AIRDROP;//тип пикапа - AirDrop
	DynamicPickup[pickupid][ID] = type;
	
	switch(type)
	{
		case AIRDROP_HUNGRYGAMES1 .. AIRDROP_HUNGRYGAMES5: //AirDrop на голодных играх
		{
			DynamicPickup[pickupid][MapIconID] = CreateDynamicMapIcon(x, y, z, 18, 0, 702, -1, -1, 300.0);
			DynamicPickup[pickupid][DestroyTimerID] = SetTimerEx("DestroyAirDropPickup" , 300 * 1000, false, "i", pickupid);
		}
		case AIRDROP_SNIPER, AIRDROP_RPG: //AirDrop оружия из шашки
		{
			DynamicPickup[pickupid][MapIconID] = CreateDynamicMapIcon(x, y, z, 18, 0, 0, -1, -1, 300.0);
			DynamicPickup[pickupid][DestroyTimerID] = SetTimerEx("DestroyAirDropPickup" , 300 * 1000, false, "i", pickupid);
		}
		case AIRDROP_GLOBAL: //Global AirDrop
		{
			DynamicPickup[pickupid][MapIconID] = CreateDynamicMapIcon(x, y, z, 37, 0, 0, -1, -1, 999999.0, MAPICON_GLOBAL);
			DynamicPickup[pickupid][DestroyTimerID] = SetTimerEx("DestroyAirDropPickup" , 18000 * 1000, false, "i", pickupid);
		}
	}

	return 1;
}

forward DestroyAirDropPickup(pickupid);
public DestroyAirDropPickup(pickupid)
{//уничтожение пикапа, который никто не успел подобрать
	DestroyDynamicMapIcon(DynamicPickup[pickupid][MapIconID]);
	DestroyDynamicPickup(pickupid);
	DynamicPickup[pickupid][Type] = 0;
	DynamicPickup[pickupid][ID] = 0; 
	DynamicPickup[pickupid][DestroyTimerID] = 0; 
	DynamicPickup[pickupid][MapIconID] = 0;
	return 1;
}//уничтожение пикапа, который никто не успел подобрать