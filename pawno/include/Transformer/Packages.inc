new Float:CaseSpawn[][3] =
{//начало
	{1940.6990,1628.4642,72.25},
	{2268.2720,1669.3809,94.92},
	{2239.3704,1679.0511,20.39},
	{2307.6521,1691.0959,10.82},
	{2258.3015,1804.0283,16.45},
	{2302.3704,1868.1688,10.82},
	{2308.9539,1959.6793,9.867},
	{2373.2349,1834.4331,11.65},
	{2404.1604,1831.5616,6.015},
	{2478.1152,1921.5189,13.48},
	{2600.7913,1887.6039,13.59},
	{2636.0564,1671.3822,15.03},
	{2516.8950,1568.0625,11.55},
	{2487.6794,1531.5693,30.27},
	{2488.2188,1411.4144,16.61},
	{2597.2061,1365.0737,14.76},
	{2763.9258,2069.8616,2.146},
	{2824.1538,2216.8293,11.02},
	{2811.0198,1638.8700,10.82},
	{2879.0291,1597.8693,12.10},
	{2932.1326,2118.7148,18.39},
	{2658.8328,2660.5508,38.04},
	{1743.7532,2792.6589,14.27},
	{1585.4988,2775.6179,10.82},
	{1419.4974,2737.2952,30.29},
	{1337.2313,2554.3918,24.07},
	{1328.5938,2627.0820,10.82},
	{307.6164,2542.8875,16.8163},
	{304.2173,2617.8025,17.4899},
	{128.4979,2582.5962,17.3625},
	{-163.7358,2727.8992,65.272},
	{-580.5201,2611.9758,53.934},
	{-732.9277,2755.8069,47.226},
	{-1267.9220,2727.0076,52.60},
	{-816.5768,2697.3630,54.938},
	{-1071.9329,2196.7170,94.00},
	{-880.9197,1923.7988,140.11},
	{-821.8712,1556.8407,30.665},
	{-2422.5645,2491.2756,13.15},
	{-2292.6772,2225.4333,4.982},
	{-2376.3386,2215.6377,4.984},
	{-2824.3186,2177.1445,180.7},
	{-2680.8027,1933.9589,217.2},
	{-2680.8977,1595.2128,181.5},
	{-2700.8267,1446.0171,53.89},
	{-1627.7178,1403.6986,9.224},
	{-2650.7351,1362.0323,20.72},
	{-2659.9651,1458.5284,49.61},
	{-2796.2522,1188.7592,20.91},
	{-2807.4116,1162.6146,26.25},
	{-2929.1011,1148.0001,13.53},
	{-2914.9731,1003.9070,36.69},
	{-2876.8501,839.1064,39.367},
	{-2959.8489,453.3018,1.7526},
	{-2906.6106,-145.4689,3.477},
	{-2771.8264,-231.1683,7.044},
	{-2659.1572,-289.8809,11.60},
	{-2481.9387,-283.4385,40.54},
	{-2394.2415,-253.8578,35.66},
	{-2508.3787,-675.0093,139.3},
	{-2129.7412,-825.8342,31.97},
	{-1937.5468,-924.9481,41.82},
	{-1949.1497,-1194.2970,34.8},
	{-1858.7263,-1193.9122,34.8},
	{-1502.0791,-661.9019,14.14},
	{-1356.0691,-686.3838,14.14},
	{-1563.2004,-432.2372,6.042},
	{-1211.3037,-97.7334,14.144},
	{-1686.1310,-94.2001,3.5781},
	{-1892.5769,-7.8419,27.5625},
	{-1861.0059,-31.4589,22.0879},
	{-1831.6456,6.0002,24.203},
	{-1848.0439,41.7282,44.20},
	{-1550.7166,83.9860,19.25},
	{-1587.9124,146.6977,3.71},
	{-1623.7708,148.0343,-7.2},
	{-1478.8011,328.2059,7.18},
	{-1221.1924,437.5558,7.18},
	{-1658.3961,258.3371,1.17},
	{-1521.6305,362.0060,43.3},
	{-1529.1055,564.2793,7.17},
	{-1481.3293,685.9898,1.32},
	{-1493.3429,921.7745,7.18},
	{-1455.4197,1019.2621,1.789},
	{-1452.0265,1144.8004,7.188},
	{-1574.8754,1267.5759,1.453}, 
	{-1511.2874,1375.6405,3.325}, 
	{-1583.6509,1334.3687,6.894}, 
	{-1610.9602,1342.0251,2.516}, 
	{-1660.8423,1384.8025,9.804}, 
	{-1725.0594,1430.8228,1.406},
	{-1877.5183,1458.2690,7.024},
	{-1959.5793,1492.3939,7.187},
	{-2300.3479,1545.0690,19.27}, 
	{-2384.6780,1534.9891,26.04}, 
	{-2488.9189,1548.0822,40.32},
	{-2680.3059,1593.5386,3.222},
	{-2480.8440,1284.7048,31.56},
	{-2465.4563,1145.0743,55.72},
	{-2484.6548,1050.6664,55.62},
	{-2410.2227,973.1193,51.681},
	{-2447.2510,757.7455,41.254},
	{-2408.5986,722.9214,38.273},
	{-2455.7651,757.7351,35.171},
	{-2399.9329,551.2897,24.957},
	{-2442.6533,523.1659,34.169},
	{-2491.6038,539.2601,30.078},
	{-2277.0767,537.9808,35.171},
	{-2288.0154,180.9903,36.881},
	{-2284.4734,-25.0243,35.312},
	{-2312.7646,-118.9770,35.32},
	{-2455.1328,-141.1515,26.17},
	{-2444.1560,-101.3509,31.17},
	{-2468.6804,-38.5706,30.453},
	{-2452.4780,1.1055,27.9375,},
	{-2053.1680,457.6005,139.64},
	{1942.5797,1558.3927,25.773},
	{1915.5231,1513.7037,17.682},
	{-1990.4871,902.2758,49.966},
	{-1964.0454,878.1737,47.201},
	{-1926.4720,878.3680,40.623},
	{-1882.2284,824.0149,40.782},
	{-1756.8168,812.0701,24.890},
	{-1756.0677,774.0778,44.045},
	{-1783.1633,766.9342,36.559},
	{-1783.3353,813.6235,36.554},
	{-1802.2745,749.6855,24.890},
	{-2057.7559,228.8323,35.583},
	{-2048.2500,169.0701,34.584},
	{-2122.9541,231.9432,41.412},
	{-2082.5371,253.9711,39.395},
	{-2153.9968,219.3544,52.023},
	{-2190.2585,180.1493,35.327},
	{-2210.8452,108.9521,35.320},
	{-2207.7571,93.8951,40.1719},
	{2120.9761,1495.9517,11.130},
	{2114.4968,1403.5621,16.023},
	{2116.4250,1384.8193,19.302},
	{2250.2161,1286.0647,19.169},
	{2302.4158,1280.5938,67.468},
	{2323.6719,1283.2562,97.628},
	{2818.4785,929.9768,13.7707},
	{2846.7180,983.6409,10.7500},
	{1491.5660,668.3400,11.0293},
	{-651.5017,2153.0256,60.382},
	{-806.7910,2239.2705,41.836},
	{-781.4903,2147.6667,60.382},
	{-306.8544,1539.6388,78.198},
	{-346.3501,1548.5084,75.562},
	{-346.6059,1575.2909,83.359},
	{-345.9254,1606.1655,75.895},
	{-310.2946,1797.8759,50.269},
	{-219.8794,1805.5463,103.79},
	{-196.1096,1897.4762,114.20},
	{-330.8683,1970.6246,129.16},
	{-321.4160,1945.2087,132.41},
	{270.0569,1973.5536,17.6406},
	{641.8317,1682.0114,13.1330},
	{1318.4495,1755.7338,10.820},
	{1470.0477,1170.7524,10.820},
	{2348.8633,1806.5492,19.731},
	{2443.1055,1791.2208,16.322},
	{2496.0481,1785.0005,10.820},
	{1408.0879,2003.8888,14.739},
	{1432.7921,2338.9265,12.265},
	{1867.8879,2233.9624,11.125},
	{2499.0762,1152.3397,25.391},
	{2498.4524,1181.9575,22.011},
	{2239.4385,568.4271,7.7813},
	{2335.3408,2785.8318,10.820},
	{2434.2178,2815.0854,14.822},
	{1993.0776,2131.9670,10.820},
	{2025.7979,2177.0754,13.619},
	{2065.0745,2251.0293,9.9697},
	{2005.8193,2315.0649,10.820},
	{1978.8674,2331.2415,10.820},
	{1961.6205,2322.1575,16.455},
	{1889.1671,2366.6675,14.781},
	{1853.2474,2294.3330,14.781},
	{1845.5172,2228.7104,11.125},
	{2001.2485,1914.8943,40.351},
	{1773.6571,895.5648,26.8828},
	{2232.0278,689.9390,16.6850},
	{2263.9590,665.8721,16.4051},
	{2380.4619,697.9574,16.2714},
	{2462.8171,738.3257,11.4609},
	{1273.2671,281.9448,19.5547},
	{1287.8748,313.2177,26.0555},
	{1456.0023,-83.9872,18.9914},
	{2329.6013,404.2887,22.1100},
	{2312.4263,31.4687,32.8371},
	{2320.2041,-7.8522,33.2969},
	{2329.9604,-14.2456,31.1875},
	{652.0112,-503.0018,19.73},
	{725.7720,-439.5550,16.33},
	{762.9384,-502.5503,22.42},
	{1030.6241,-661.9680,120.11},  
	{923.2629,-864.1811,96.81},
	{1240.2578,-801.5616,84.1},
	{-2153.6665,-2288.4023,33.21},
	{-2199.5193,-2243.3313,33.32},  
	{-2152.2148,-2460.9219,37.73}, 
	{-2431.9541,-1620.1530,526.6},  
	{-2255.4824,-1748.7098,487.6},  
	{-1844.0248,-1605.7998,21.75},  
	{-1467.1769,-1499.5414,110.8}, 
	{-1098.0507,-1621.1589,86.25}, 
	{-1113.5288,-1678.4059,76.36}, 
	{-1082.5015,-696.4270,32.351},
	{-1125.6425,-757.4315,32.007},
	{500.1873,1386.4465,7.54},
	{977.9096,1067.1046,10.8},
	{-99.7975,1127.2006,19.74},
	{-421.0453,1163.7112,1.80},
	{-688.2440,933.2136,13.63},
	{-640.3204,864.5737,2.000},
	{2439.5359,968.7974,14.27},
	{2491.0205,918.5959,13.69},
	{2519.4292,918.4400,20.85},
	{1535.7257,751.0555,32.74},
	{-635.4037,-2065.9797,31.0},
	{30.5255,-2652.4080,43.63},
	{-285.3909,-2151.0313,28.54}, 
	{-1558.3914,-2724.5498,48.7}, 
	{968.2604,2355.7383,11.36},
	{788.6649,1684.7426,9.682},
	{221.6134,1422.1663,10.58},
	{215.0648,1467.4646,23.73},
	{-1924.0753,454.9937,35.1},
	{-1943.0657,437.6940,64.3},
	{-1942.8425,536.7079,209.82},
	{-1772.0104,578.7294,234.89}, 
	{-1681.1224,586.5518,24.871},
	{-1618.9832,693.4760,7.187},
	{-1593.5165,716.2374,-5.24},
	{-1619.6761,648.2906,-5.24},
	{-1735.3149,776.5200,170.8},
	{-1531.5779,687.4241,133.05},
	{-1496.9072,590.7961,42.257},
	{-1394.8221,493.8862,21.681},
	{-1246.0236,501.4988,18.234},
	{2435.0293,1662.8894,15.644},
	{2516.4087,1682.4810,14.265},
	{2364.1260,1176.7179,34.257},
	{2645.8594,1073.3607,15.734},
	{1731.5320,1246.4686,40.066},
	{1947.6091,1124.5833,18.085},
	{1975.2161,1182.3380,22.518},
	{1985.1366,1028.4469,10.820},
	{2019.7399,1007.8279,47.020},
	{1941.1799,949.4611,59.6116},
	{1938.0341,919.0829,16.6315},
	{1717.1980,891.0420,13.6784},
	{1670.2570,913.7636,16.6182},
	{1632.6729,1034.9360,13.769},
	{1410.5538,2100.6753,12.015},
	{1111.9551,2121.1826,10.813},
	{258.2401,2938.5134,1.766},
	{1050.4719,2953.6641,23.8},
	{2320.4329,2352.8511,10.6},
	{2608.8206,2348.2329,17.82},
	{2640.1619,2328.7605,17.82},
	{2625.8254,2380.3540,10.82},
	{2626.9917,2418.3022,10.81},
	{2617.3022,2458.4778,10.82},
	{2118.7688,2405.0352,23.60},
	{2174.8230,2405.0967,23.59},
	{2190.4519,2421.7144,73.03},
	{2118.4175,2416.6582,49.52},
	{2009.5732,2264.7480,11.02},
	{1953.6725,1342.9800,24.63},
	{2000.4041,1584.5619,17.08},
	{-1993.1624,-444.2206,38.7},
	{-1858.0310,-379.9737,25.1},
	{-1691.1609,-163.9165,14.5},
	{-1764.4031,-188.6909,1.96},
	{-1754.3271,222.7382,3.554},
	{-1747.5975,188.9878,3.549},
	{-1475.8281,378.8937,7.194},
	{-1334.4586,486.0222,11.18},
	{-1023.1801,469.1344,19.84},
	{-2078.0371,-106.9507,35.3},
	{-2632.8289,78.4947,7.18},
	{-2647.2798,-4.3411,26.5},
	{-2749.1897,-8.8869,6.60},
	{-2734.0376,-144.0394,4.32}, 
	{-2783.5559,189.8716,10.05},
	{-2633.7405,99.1925,4.33},
	{-2116.8132,926.9468,86.07}, 
	{-2055.7410,981.0754,65.97}, 
	{-2076.1355,1066.1171,66.6},
	{-2124.2637,1103.1030,79.1},
	{-2480.1206,1148.8888,55.5},
	{-2481.1174,1210.1342,38.7},
	{-2533.3098,1216.8239,41.4},
	{-2643.8696,1273.8335,17.7},
	{-2685.4600,1262.1499,16.9},
	{66.6372,-1533.8602,12.706},
	{157.4230,-1456.3956,37.94},
	{257.1637,-1372.6653,53.10},
	{283.1161,-1281.3719,74.63},
	{409.2908,-1155.7118,76.68},
	{579.4559,-1124.6097,53.47},
	{612.7769,-1084.1167,58.82},
	{705.9838,-1056.8909,46.67},
	{837.3403,-985.2768,27.829},
	{1005.0172,-898.1267,49.05},
	{1133.6378,-888.3015,48.68},
	{1233.4181,-1010.2503,36.3},
	{1232.7563,-1084.3112,29.179},
	{1438.4268,-1095.8318,19.140},
	{1623.6250,-1042.3301,27.201},
	{1625.6600,-1138.8887,27.201},
	{1720.7584,-1116.8180,24.085},
	{1830.3882,-1145.6385,23.856},
	{1914.7274,-1066.8049,24.124},
	{1991.1250,-1068.1899,29.045},
	{2055.9709,-1066.1768,29.283},
	{2104.3879,-1039.3755,29.217},
	{2154.2678,-1079.9834,35.495},
	{2256.4275,-1070.0704,49.476},
	{2284.2556,-1046.8981,49.887},
	{2382.7441,-1130.9615,30.168},
	{2516.6375,-1126.8137,41.293},
	{2583.4766,-1142.5760,55.593},
	{2616.4810,-1104.9801,71.972},
	{2662.9023,-1106.6541,69.421},
	{2700.8562,-1106.4402,69.577},
	{2686.9824,-1145.0155,71.359},
	{2764.7961,-1190.6995,69.406},
	{2802.2378,-1203.7678,25.476},
	{2833.8884,-1294.4907,22.632},
	{2822.0073,-1336.9001,27.675},
	{2825.3296,-1413.7368,21.367},
	{2771.1003,-1405.1305,27.180},
	{2750.6436,-1419.7076,39.374},
	{2686.1543,-1568.9316,31.396},
	{2660.7197,-1572.2008,23.178},
	{2778.8345,-1707.0468,11.843},
	{2758.3042,-1840.3479,10.312},
	{2786.3662,-1921.2622,17.320},
	{2801.4404,-2001.8293,13.554},
	{2660.5222,-1980.2369,13.548},
	{2642.7732,-1951.3312,13.546},
	{2744.3765,-1944.6511,13.546},
	{2830.7263,-1950.7532,12.719},
	{2942.1729,-2051.5686,3.5480},
	{2876.5168,-2124.8010,4.1842},
	{2765.1050,-2182.4893,11.088},
	{2758.4387,-2125.0369,11.447},
	{2642.2749,-2051.9902,13.736},
	{2584.0674,-2066.9390,4.3097},
	{2515.9329,-1959.2755,21.878},
	{2509.8044,-1947.5527,14.174},
	{2775.1128,-2385.3447,16.224},
	{2742.0349,-2381.6650,17.340},
	{2730.9380,-2427.2363,17.593},
	{2632.3730,-2496.4307,30.888},
	{2589.3706,-2472.7361,3.1963},
	{2537.4963,-2346.9368,22.878},
	{2492.9375,-2425.0803,17.882},
	{2399.5703,-2492.1650,16.224},
	{2414.6418,-2515.3879,17.910},
	{2411.0737,-2620.2158,17.910},
	{2507.5317,-2640.0361,16.656},
	{2464.6082,-2568.8550,16.304},
	{2471.8726,-2696.8682,3.0000},
	{2183.5144,-2662.6125,17.882},
	{1931.6313,-2669.4534,15.550},
	{1855.1852,-2658.9077,13.546},
	{1883.8971,-2552.8486,17.236},
	{1888.6670,-2340.1750,16.703},
	{1724.1093,-2408.5105,13.554},
	{1561.6631,-2407.0691,13.554},
	{1474.6426,-2267.8464,32.489},
	{1492.1313,-2261.6575,13.546},
	{1672.9176,-2334.8599,14.516},
	{2210.8728,-2204.3887,15.171},
	{2167.6042,-2256.5940,16.958},
	{2194.8965,-2286.0496,15.818},
	{2188.8506,-2329.8379,13.554},
	{1407.5217,-2195.2058,13.539},
	{1406.8475,-2377.5518,13.539},
	{1352.2756,-2432.7747,16.656},
	{1237.9283,-2381.5278,8.3145},
	{1196.6089,-2344.1145,15.361},
	{1123.5614,-2239.1909,48.840},
	{1008.9712,-2227.6951,13.093},
	{1020.7595,-1922.6244,12.645},
	{830.1478,-1884.9403,5.7726},
	{774.5079,-1820.8314,13.0234},
	{725.0049,-1857.1177,11.4443},
	{611.5830,-1871.2990,5.7707},
	{380.3792,-1885.1333,2.08},
	{245.5796,-1872.8995,5.88},
	{158.4828,-1961.4723,3.77},
	{161.1266,-1767.4657,6.80},
	{363.6558,-1554.4835,36.4},
	{307.8406,-1524.8905,24.9},
	{415.7245,-1506.4243,34.8},
	{470.6309,-1395.6010,24.0},
	{616.2212,-1352.3595,13.5},
	{673.8406,-1275.6208,13.6},
	{732.9308,-1276.4465,13.5},
	{808.6035,-1232.8584,18.7},
	{895.2843,-1257.9880,14.9},
	{929.0886,-1189.2627,16.976},
	{998.6838,-1245.2965,19.406},
	{1008.7262,-1256.7587,23.06},
	{1040.8550,-1286.1765,25.86}, 
	{1073.8417,-1311.6283,17.05},
	{1039.9994,-1343.0994,22.21},
	{1092.6206,-1363.5685,14.28},
	{1110.9636,-1335.3884,13.78},
	{1180.1598,-1233.7000,22.14},
	{1288.7224,-1179.0671,23.64},
	{1330.7028,-1195.9635,23.57},
	{1330.5205,-1227.1201,18.13},
	{1304.7623,-1253.1754,13.55},
	{1270.3904,-1308.3237,15.16},
	{1255.6229,-1438.8203,18.70},
	{1294.6383,-1438.8429,20.47},
	{1291.0286,-1472.2451,10.04},
	{1165.2936,-1489.1746,15.20},
	{1118.2678,-1467.9707,19.07},
	{1139.4780,-1434.5441,19.08},
	{1149.1410,-1343.9330,13.67},
	{1476.4603,-1667.0685,14.55},
	{1478.8354,-1639.5928,14.14},
	{1506.7200,-1668.3193,14.04},
	{1580.6763,-1634.2979,13.56},
	{1536.7615,-1635.5909,6.218},
	{1989.9814,-1702.1777,15.96},
	{2247.1577,-1815.7621,13.55},
	{2145.3320,-1663.1073,15.08},
	{1684.2533,-1272.3771,14.81},
	{1580.1633,-1219.7014,17.51},
	{2480.9778,-1395.9041,28.83},
	{2490.8132,-1420.7308,28.83},
	{2479.5930,-1475.7096,33.50},
	{2463.5818,-1479.0067,37.19},
	{2491.5007,-1563.1830,25.93},
	{2516.0310,-1636.6367,14.19},
	{2513.9597,-1691.2373,18.51},
	{2530.3259,-1677.6495,19.93},
	{1917.5251,-1415.4065,13.57},
	{1954.3196,-1372.2906,19.64},
	{1974.0270,-1234.6886,20.04},
	{1970.4540,-1157.1747,20.96},
	{2514.6907,-1240.7605,39.02},
	{2611.1067,-1219.6445,55.23},
	{2677.3403,-1228.2468,58.53},
	{2498.3806,-1998.6836,13.54},
	{2544.4548,-2042.3304,15.43},
	{2529.8743,-2055.9736,21.56},
	{2533.5671,-2049.3364,5.352},
	{1123.4325,-1785.0309,16.59},
	{1228.5710,-1743.2952,13.59},
	{858.4413,-1553.8975,13.538},
	{852.2467,-1438.0261,15.043},
	{835.7457,-1472.0563,12.694},
	{1543.8649,-1355.8208,329.4},
	{1560.5435,-1353.2131,317.3},
	{699.7194,-1472.6312,17.695},
	{723.0135,-1495.4034,1.9343},
	{830.7993,-1563.9279,17.515},
	{1711.1522,-1702.2605,14.164},
	{1689.1289,-1673.2172,20.907},
	{1735.5240,-1629.5123,20.212},
	{1740.6190,-1562.3132,14.162},
	{1117.8545,-2037.0984,78.750},
	{1116.2084,-2004.6925,82.120},
	{1144.2852,-1937.1594,43.435},
	{1175.3558,-1877.4421,15.060},
	{1192.8998,-1876.7712,16.317},
	{2093.6479,-1328.8754,28.797},
	{2112.7498,-1352.9283,23.984},
	{2821.1580,-1578.1946,11.093},
	{2768.2317,-1628.4316,12.177},
	{2669.4458,-1437.5874,16.250},
	{-1994.8485,-1555.7983,85.21}
};//конец