stock PlayerLevelUp(playerid)
{//функция повышения уровня
	if(Logged[playerid] == 0) return 1;
	if(Player[playerid][Level] > 99 && Player[playerid][Prestige] < 10) {Player[playerid][Level] = 100; Player[playerid][Exp] = 0; NeedXP[playerid] = 99999999; return 1;} //баг с 100+ ур. и престижем меньше 10
	Player[playerid][Exp] -= NeedXP[playerid];Player[playerid][Level] += 1;
	//PlayerPlaySound(playerid, 19800, 0.0,0.0,0.0);//Прикольный бас
	new String[120];format(String,sizeof(String), "~g~LEVEL ~W~%d",Player[playerid][Level]); //LEVEL N
	GameTextForPlayer(playerid, String, 3000, 1);
	format(String,sizeof(String), "Вы достигли {FFFFFF}%d{FFFF00}-го уровня",Player[playerid][Level]);
	SendClientMessage(playerid,COLOR_YELLOW,String);
	//обновление NeedXP
	new Lvl = Player[playerid][Level];
	if (Player[playerid][Prestige] < 10 || Lvl < 100) NeedXP[playerid] = Levels[Lvl];
	else NeedXP[playerid] = (Lvl - 99) * 100 + 35000;
	//-------------- Открытия на уровне
	if (Player[playerid][Level] == 2){SendClientMessage(playerid,COLOR_YELLOW,"Команда /skydive теперь доступна");}
	if (Player[playerid][Level] == 3){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 2-го класса");}
	if (Player[playerid][Level] == 4){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новое личное оружие");}
	if (Player[playerid][Level] == 5){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 6){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 7){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 8){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 2-го класса и новое личное оружие");}
	if (Player[playerid][Level] == 9){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса и гидравлика в автомастерских");}
	if (Player[playerid][Level] == 10){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый стиль спавна - На авто 1-го класса");}
		if (Player[playerid][Level] == 10 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 50 метров' теперь доступен");}
	if (Player[playerid][Level] == 11){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 12){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 13){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый стиль спавна - На авто 2-го класса");}
	if (Player[playerid][Level] == 14){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 2-го класса");}
	if (Player[playerid][Level] == 15){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса и изменено место стандартного спавна - Сан Фиерро");}
	if (Player[playerid][Level] == 16){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса и новое личное оружие");}
	if (Player[playerid][Level] == 17){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса и новое личное оружие");}
	if (Player[playerid][Level] == 18){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступно новое личное оружие");}
	if (Player[playerid][Level] == 19){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса и новое личное оружие");}
	if (Player[playerid][Level] == 20){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
		if (Player[playerid][Level] == 20 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 100 метров' теперь доступен");}
	if (Player[playerid][Level] == 21){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 22){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 2-го класса");}
	if (Player[playerid][Level] == 23){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса и новое личное оружие");}
	if (Player[playerid][Level] == 24){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 25){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 25){SendClientMessage(playerid,COLOR_YELLOW,"Команда /mytime теперь доступна  и изменено место стандартного спавна - Лас Вентурас");}
		if (Player[playerid][Level] == 25 && Player[playerid][Prestige] >= 2){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 2: Навык 'Режим Полета' (для транспорта) теперь доступен");}
		if (Player[playerid][Level] == 25 && Player[playerid][Prestige] >= 8){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 8: Навык 'Режим Супермена' теперь доступен");}
	if (Player[playerid][Level] == 26){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 2-го класса");}
	if (Player[playerid][Level] == 27){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступно новое личное оружие");}
	if (Player[playerid][Level] == 28){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 29){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 30){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 2-го класса");}
	if (Player[playerid][Level] == 31){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолетов (Личное Оружие) увеличено до 140");}
	if (Player[playerid][Level] == 32){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 33){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для дробовиков (Личное Оружие) увеличено до 56");}
	if (Player[playerid][Level] == 34){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступно новое личное оружие");}
	if (Player[playerid][Level] == 35){SendClientMessage(playerid,COLOR_YELLOW,"Нитро х2 в автомастерских теперь доступно");}
		if (Player[playerid][Level] == 35 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 50 метров' (для транспорта) теперь доступен");}
	if (Player[playerid][Level] == 36){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступны новые стили драки (/style)");}
	if (Player[playerid][Level] == 37){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолет-пулеметов (Личное Оружие) увеличено до 1 000");}
	if (Player[playerid][Level] == 38){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен JetPack и стиль спавна 'На JetPack'");}
	if (Player[playerid][Level] == 39 && Player[playerid][Prestige] < 8){SendClientMessage(playerid,COLOR_YELLOW,"Максимальная ставка в казино увеличена до 250 000$");}
		if (Player[playerid][Level] == 40 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 100 метров' (для транспорта) теперь доступен");}
	if (Player[playerid][Level] == 40){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступно новое личное оружие");}
	if (Player[playerid][Level] == 41){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для автоматов (Личное Оружие) увеличено до 180");}
	if (Player[playerid][Level] == 42){SendClientMessage(playerid,COLOR_YELLOW,"Нитро х5 в автомастерских теперь доступно");}
	if (Player[playerid][Level] == 43){SendClientMessage(playerid,COLOR_YELLOW,"Количество гранат (Личное Оружие) увеличено до 20");}
	if (Player[playerid][Level] == 44){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для винтовок (Личное Оружие) увеличено до 30");}
	if (Player[playerid][Level] == 45){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
		if (Player[playerid][Level] == 45 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 200 метров' (для транспорта) теперь доступен");}
	if (Player[playerid][Level] == 46){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для RPG (Личное Оружие) увеличено до 20");}
	if (Player[playerid][Level] == 47){SendClientMessage(playerid,COLOR_YELLOW,"Команды для перекраски транспорта /paint и /paintid теперь доступны");}
	if (Player[playerid][Level] == 48){SendClientMessage(playerid,COLOR_YELLOW,"Нитро х10 в автомастерских теперь доступно");}
	if (Player[playerid][Level] == 49){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 50){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 2-го класса");}

	if (Player[playerid][Level] == 51){SendClientMessage(playerid,COLOR_YELLOW,"Навык 'Перевернуть транспорт на колеса' теперь доступен");}
	if (Player[playerid][Level] == 52){SendClientMessage(playerid,COLOR_YELLOW,"Команды для смены скина (/myskin, /myskinid) теперь доступны");}
	if (Player[playerid][Level] == 53 && Player[playerid][Prestige] < 8){SendClientMessage(playerid,COLOR_YELLOW,"Максимальная ставка в казино увеличена до 500 000$");}	
		if (Player[playerid][Level] == 53 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 200 метров' теперь доступен");}
	if (Player[playerid][Level] == 54){SendClientMessage(playerid,COLOR_YELLOW,"Доступен новый стиль спавна - На авто 3-го класса");}
	if (Player[playerid][Level] == 55){SendClientMessage(playerid,COLOR_YELLOW,"Покрасочные работы в автомастерских теперь доступны");}
		if (Player[playerid][Level] == 55 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 50 метров (cо скоростью)' (для транспорта) теперь доступен");}
	if (Player[playerid][Level] == 56){SendClientMessage(playerid,COLOR_YELLOW,"Доступен навык 'Разворот на 180' для транспорта 1-го класса");}
	if (Player[playerid][Level] == 57){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 58){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 59){SendClientMessage(playerid,COLOR_YELLOW,"Доступен навык  'Разворот на 180' для транспорта 2-го класса");}
	if (Player[playerid][Level] == 60){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступно новое личное оружие");}
		if (Player[playerid][Level] == 60 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 100 метров (cо скоростью)' (для транспорта) теперь доступен");}
	if (Player[playerid][Level] == 61){SendClientMessage(playerid,COLOR_YELLOW,"Доступен навык 'Прыжок' для транспорта 1-го класса");}
	if (Player[playerid][Level] == 62){SendClientMessage(playerid,COLOR_YELLOW,"Доступен навык 'Прыжок' для транспорта 2-го класса");}
	if (Player[playerid][Level] == 63){SendClientMessage(playerid,COLOR_YELLOW,"Доступен навык 'Трамплин' для транспорта 1-го класса");}
	if (Player[playerid][Level] == 64){SendClientMessage(playerid,COLOR_YELLOW,"Доступен навык 'Трамплин' для транспорта 2-го класса");}
	if (Player[playerid][Level] == 65){SendClientMessage(playerid,COLOR_YELLOW,"Бесконечное нитро теперь доступно в автомастерской TurboSpeed");}
		if (Player[playerid][Level] == 65 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Навык 'Телепорт на 200 метров (cо скоростью)' (для транспорта) теперь доступен");}
	if (Player[playerid][Level] == 66 && Player[playerid][Prestige] < 8){SendClientMessage(playerid,COLOR_YELLOW,"Максимальная ставка в казино увеличена до 1 000 000$");}
	if (Player[playerid][Level] == 67){SendClientMessage(playerid,COLOR_YELLOW,"Команда /myweather теперь доступна");}
	if (Player[playerid][Level] == 68){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 69){SendClientMessage(playerid,COLOR_YELLOW,"Изменено место стандартного спавна - Гора Chilliad");}
	if (Player[playerid][Level] == 70){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступна невидимость на радаре (/invisible)");}
	
	if (Player[playerid][Level] == 71){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолетов (Личное Оружие) увеличено до 210");}
	if (Player[playerid][Level] == 72){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для дробовиков (Личное Оружие) увеличено до 84");}
	if (Player[playerid][Level] == 73){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолет-пулеметов (Личное Оружие) увеличено до 1 500");}
	if (Player[playerid][Level] == 74){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для автоматов (Личное Оружие) увеличено до 270");}
	if (Player[playerid][Level] == 75){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 1-го класса");}
	if (Player[playerid][Level] == 76){SendClientMessage(playerid,COLOR_YELLOW,"Количество гранат (Личное Оружие) увеличено до 30");}
	if (Player[playerid][Level] == 77){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для винтовок (Личное Оружие) увеличено до 45");}
	if (Player[playerid][Level] == 78){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 79){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для RPG (Личное Оружие) увеличено до 30");}
	if (Player[playerid][Level] == 80){SendClientMessage(playerid,COLOR_YELLOW,"UberNitro теперь доступно в автомастерской TurboSpeed");}
	if (Player[playerid][Level] == 81){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для Минигана (Личное Оружие) увеличено до 2 000");}
	if (Player[playerid][Level] == 82){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолетов (Личное Оружие) увеличено до 280");}
	if (Player[playerid][Level] == 83){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для дробовиков (Личное Оружие) увеличено до 112");}
	if (Player[playerid][Level] == 84){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолет-пулеметов (Личное Оружие) увеличено до 2 000");}
	if (Player[playerid][Level] == 85){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
		if (Player[playerid][Level] == 85 && Player[playerid][Prestige] >= 1){SendClientMessage(playerid,COLOR_DERBY,"PRESTIGE 1: Теперь вы можете ставить любой транспорт в класс 1 и 2");}
	if (Player[playerid][Level] == 86){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для автоматов (Личное Оружие) увеличено до 360");}
	if (Player[playerid][Level] == 87){SendClientMessage(playerid,COLOR_YELLOW,"Количество гранат (Личное Оружие) увеличено до 40");}
	if (Player[playerid][Level] == 88){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для винтовок (Личное Оружие) увеличено до 60");}
	if (Player[playerid][Level] == 89){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для RPG (Личное Оружие) увеличено до 40");}
	if (Player[playerid][Level] == 90){SendClientMessage(playerid,COLOR_YELLOW,"Вам доступен новый транспорт 3-го класса");}
	if (Player[playerid][Level] == 91){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для Минигана (Личное Оружие) увеличено до 3 000");}
	if (Player[playerid][Level] == 92){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолетов (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 93){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для дробовиков (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 94){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для пистолет-пулеметов (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 95){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для автоматов (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 96){SendClientMessage(playerid,COLOR_YELLOW,"Количество гранат (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 97){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для винтовок (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 98){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для RPG (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 99){SendClientMessage(playerid,COLOR_YELLOW,"Количество боеприпасов для Минигана (Личное Оружие) увеличено до 20 000");}
	if (Player[playerid][Level] == 100)
	{
		SendClientMessage(playerid,COLOR_YELLOW,"Ускоритель для JetPack теперь доступен (Клавиша 'N')");
        format(String,sizeof(String),"Игрок {ffffff}%s [%d]{FFBF00} достиг {ffffff}100{FFBF00} уровня! Поздравляем!",PlayerName[playerid],playerid);
		SendClientMessageToAll(0xFFBF00FF,String);
	}
	if (Player[playerid][Level] == 100 && Player[playerid][Prestige] < 10){SendClientMessage(playerid,COLOR_YELLOW,"{457EFF}Внимание! Новый уровень Престижа теперь доступен! ('/prestige')");}
	if (Player[playerid][Level] == 100 && Player[playerid][Prestige] >= 10){SendClientMessage(playerid,COLOR_YELLOW,"{457EFF}Внимание! Теперь вы можете 'прокачиваться' выше 100-го уровня!");}

	if (Player[playerid][Level] == 150){SendClientMessage(playerid,COLOR_YELLOW,"Внимание! Теперь вы можете летать быстрее в 'Режиме Полета'");}
	if (Player[playerid][Level] == 200){SendClientMessage(playerid,COLOR_YELLOW,"Внимание! Теперь вы можете летать быстрее в 'Режиме Супермена'");}

    //MarafonUpdate(playerid, 2, 1);

	//-------------- Открытия на уровне	

	if (NeedXP[playerid] <= Player[playerid][Exp]) PlayerLevelUp(playerid);
	else SavePlayer(playerid);
	
	format(String, sizeof String, "%d.%d.%d a %d:%d:%d |   %s[%d] достиг %d уровня.", Day, Month, Year, hour, minute, second, PlayerName[playerid], playerid, Player[playerid][Level]);
	WriteLog("GlobalLog", String); WriteLog("LevelUps", String);
	return 1;
}//функция повышения уровня
