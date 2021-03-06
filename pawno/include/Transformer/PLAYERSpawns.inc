new Float:GroveSpawn[][4] =
{
	// Positions, (X, Y, Z and Facing Angle)
	{2470.9023,-1668.3693,13.0376,280.1771},
	{2475.0967,-1677.6030,13.0630,322.8398},
	{2487.6189,-1681.6494,13.0623,4.1245},
	{2504.8328,-1676.9895,13.0998,46.3115},
	{2506.9094,-1665.4503,13.1240,97.0017},
	{2477.2026,-1661.0345,13.0694,87.5779}
};

new Float:ChilliadSpawn[][4] =
{
	{-2338.7280,-1601.9042,483.4309,216.0404}, // ChilliadSpawn 1
	{-2354.0339,-1630.0822,483.4121,227.0056}, // ChilliadSpawn 2
	{-2336.5088,-1665.5995,483.2272,328.8633}, // ChilliadSpawn 3
	{-2340.1208,-1585.7621,483.2664,215.0930} // ChilliadSpawn 4
};

new Float:LSSPAWN[][4] = {
{2676.2874,-2529.9485,13.2056,357.1653}, // LSSPAWN Доки
{2607.8518,-2208.7073,13.3508,179.2793}, // LSSPAWN Около доков
{2489.2407,-1952.2830,13.2385,359.7734}, // LSSPAWN Около пиццерии
{2284.9202,-1674.7573,14.4778,1.0626}, // LSSPAWN Около Grove Street
{2777.4583,-1610.8589,10.7265,268.7379}, // LSSPAWN Рядом со стадионом
{2387.5339,-1541.1139,23.8038,358.1857}, // LSSPAWN Севернее Grove
{2219.9524,-2229.5232,13.3470,314.2331}, // LSSPAWN Склад не далеко от доков
{2008.6719,-2130.7031,13.3560,1.5711}, // LSSPAWN Рядом с аэропортом
{2154.8577,-1180.3140,23.6291,0.5343}, // LSSPAWN Между парком и мотелем
{1677.1804,-1107.0078,23.7114,90.9349}, // LSSPAWN Парковка под мостом
{1753.2827,-1013.3141,23.7662,166.2182}, // LSSPAWN Парковка под мостом 2
{1589.1786,-1054.7697,23.7096,309.0101}, // LSSPAWN Парковка под мостом 3
{1401.1007,-1511.0977,13.4027,166.0496}, // LSSPAWN Закоулок около ментовки
{953.0461,-1373.4423,13.1497,178.2112}, // LSSPAWN Около входа в метро
{818.4316,-1347.8162,13.3302,1.5084}, // LSSPAWN Вход в метро
{347.0736,-1809.2581,4.3280,358.4099} // LSSPAWN Пляж

};

new Float:LVSPAWN[][4] = {
{-303.7682,1019.7028,19.3996,269.4670}, // LVSPAWN Форт Карсон
{-169.7583,1223.2717,19.5439,182.5839}, // LVSPAWN Форт Карсон 2
{-295.9364,1765.4401,42.4903,179.4834}, // LVSPAWN Рядом с дамбой
{-794.1572,2426.4661,156.9347,166.0766}, // LVSPAWN Великий Трамплин
{-882.4203,2753.5452,45.6542,275.1949}, // LVSPAWN Не далеко от Великого Трамплина
{-17.2664,2356.7551,23.9326,177.2323}, // LVSPAWN У заброшенного аэропорта
{651.6041,1689.9083,6.7973,36.5497}, // LVSPAWN Заправка не делако от зоны 69
{1098.1884,1623.2543,12.2658,0.3574}, // LVSPAWN Стадион
{1644.3577,1296.1838,10.6250,271.2644}, // LVSPAWN Парковка у аэропорта
{1443.4001,978.2950,10.6216,0.0027}, // LVSPAWN Склад рядом с аэропортом
{1512.4854,2258.1536,10.6244,179.7356}, // LVSPAWN Парковка у футбольного поля
{1369.3914,2266.4277,10.6260,270.3274}, // LVSPAWN Парковка у футбольного поля 2
{2103.1799,2479.0889,10.6248,179.7342}, // LVSPAWN У въезда в Emerald Isle
{2096.5325,2401.8376,14.9265,90.1526}, // LVSPAWN Emerald Isle 2 этаж
{2069.5715,2392.9404,23.5299,270.0608}, // LVSPAWN Emerald Isle 4 этаж
{2069.5198,2393.0178,32.1313,270.3716}, // LVSPAWN Emerald Isle 6 этаж
{2074.0803,2416.1697,49.3272,178.3742}, // LVSPAWN Emerald Isle 10 этаж
{2801.8787,2583.8140,10.6204,46.6880}, // LVSPAWN Склад на северо-востоке
{1413.9545,765.5742,10.6272,268.3222}, // LVSPAWN Около доков
{1512.8682,787.3940,10.6271,180.0415}, // LVSPAWN Около доков 2
{2309.0366,1515.8634,23.4326,179.7789}, // LVSPAWN Парковка у пирамиды
{2317.4326,1517.9318,42.6236,179.7523}, // LVSPAWN Парковка у пирамиды 2
{2327.1821,1388.5953,42.6235,0.3847}, // LVSPAWN Парковка у пирамиды 3
{2395.8396,1659.1797,10.6157,180.0555}, // LVSPAWN Не далеко от калигулы
{2510.9377,1664.6693,10.6271,90.3714}, // LVSPAWN Не далеко от калигулы 2
{1961.3882,1800.5463,12.5488,180.4939}, // LVSPAWN Не далеко от калигулы 3
{1914.3246,1782.9244,18.7346,178.6908} // LVSPAWN Не далеко от калигулы 4

};

new Float:SFSPAWN[][4] = {
{-2149.3499,-950.1832,31.8277,269.5081}, // SFSPAWN Рядом с работой Домушника
{-2126.0630,-901.7463,31.8272,270.6992}, // SFSPAWN Рядом с работой Домушника 2
{-2150.1138,-775.6814,31.8265,269.5078}, // SFSPAWN Рядом с работой Домушника 3
{-2395.8162,-594.3770,132.4524,125.3470}, // SFSPAWN Около радиовышки
{-2129.8555,-413.0364,35.1426,357.2010}, // SFSPAWN Стадион
{-2120.8953,-124.3995,35.1228,177.3794}, // SFSPAWN Заброшенный завод
{-2345.0662,-124.6353,35.1163,180.4912}, // SFSPAWN Рядом с пиццерией
{-1701.4474,-87.3745,3.3611,47.0663}, // SFSPAWN Около доков (работа капитаном)
{-1968.7314,95.2993,27.4896,89.4402}, // SFSPAWN ЖД
{-2029.4891,175.6052,28.6393,273.3765}, // SFSPAWN ЖД 2
{-2515.5334,338.4007,34.9222,334.4872}, // SFSPAWN Парковка не далеко от архангелов
{-2502.1052,423.9156,27.5840,230.4817}, // SFSPAWN Парковка не далеко от архангелов 2
{-1785.3796,423.2244,16.3970,140.4128}, // SFSPAWN Под мостом
{-1817.2813,1293.9131,40.9525,5.1549}, // SFSPAWN Парковка около церкви
{-2075.6760,1413.6819,6.9074,177.8769}, // SFSPAWN Не далеко от дома удовольствий
{-2969.8340,470.5881,4.7161,271.2029} // SFSPAWN Причал у банка
};