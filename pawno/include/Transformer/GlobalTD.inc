    //Дата
	TextDrawDate = TextDrawCreate(547.000000,11.000000,"--");
	TextDrawFont(TextDrawDate,3);
	TextDrawLetterSize(TextDrawDate,0.399999,1.600000);
    TextDrawColor(TextDrawDate,0xffffffff);
	//Время
	TextDrawTime = TextDrawCreate(547.000000,28.000000,"--");
	TextDrawFont(TextDrawTime,3);
	TextDrawLetterSize(TextDrawTime,0.399999,1.600000);
	TextDrawColor(TextDrawTime,0xffffffff);
	
	//ивенты
	for(new et = 0; et < MAX_EVENTS; et++)
    {
		TextDrawEvent[et] = TextDrawCreate(5.202090, 425.217437, "Events");
		TextDrawLetterSize(TextDrawEvent[et], 0.418740, 1.051664);
		TextDrawAlignment(TextDrawEvent[et], 1);
		TextDrawColor(TextDrawEvent[et], -1);
		TextDrawSetShadow(TextDrawEvent[et], 0);
		TextDrawSetOutline(TextDrawEvent[et], 1);
		TextDrawBackgroundColor(TextDrawEvent[et], 255);
		TextDrawFont(TextDrawEvent[et], 3);
		TextDrawSetProportional(TextDrawEvent[et], 1);
		TextDrawSetShadow(TextDrawEvent[et], 0);
	}

	//спек, кар-спек, скорость, работа
/*	for(new ill = 0; ill < MAX_PLAYERS; ill++)
	{// текстдравы с MAX_PLAYERS

		SpecInfo[ill] = TextDrawCreate(2, 436, "spectate");
		TextDrawFont(SpecInfo[ill] , 1);
		TextDrawLetterSize(SpecInfo[ill] , 0.3, 1.2);
		TextDrawColor(SpecInfo[ill] , 0xFFFF00FF);
		TextDrawSetOutline(SpecInfo[ill] , 1);
		TextDrawSetProportional(SpecInfo[ill] , true);
		TextDrawSetShadow(SpecInfo[ill] , 0);

		SpecInfoVeh[ill] = TextDrawCreate(2, 425, "car-spectate");
		TextDrawFont(SpecInfoVeh[ill] , 1);
		TextDrawLetterSize(SpecInfoVeh[ill] , 0.3, 1.2);
		TextDrawColor(SpecInfoVeh[ill] , 0x457EFFFF);
		TextDrawSetOutline(SpecInfoVeh[ill] , 1);
		TextDrawSetProportional(SpecInfoVeh[ill] , true);
		TextDrawSetShadow(SpecInfoVeh[ill] , 0);

		TextDrawSpeedo[ill] = TextDrawCreate(40, 315, "CKOPOCTb: x Km/h");
		TextDrawFont(TextDrawSpeedo[ill] , 1);
		TextDrawLetterSize(TextDrawSpeedo[ill] , 0.3, 1.2);
		TextDrawColor(TextDrawSpeedo[ill] , 0x2EFEF7FF);
		TextDrawSetOutline(TextDrawSpeedo[ill] , 1);
		TextDrawSetProportional(TextDrawSpeedo[ill] , true);
		TextDrawSetShadow(TextDrawSpeedo[ill] , 0);

		//Таймер времени на работе
		TextDrawWorkTimer[ill] = TextDrawCreate(40, 300, "00:00");
		TextDrawFont(TextDrawWorkTimer[ill] , 1);
		TextDrawLetterSize(TextDrawWorkTimer[ill] , 0.6, 2.4);
		TextDrawColor(TextDrawWorkTimer[ill] , 0x457EFFFF);
		TextDrawSetOutline(TextDrawWorkTimer[ill] , 1);
		TextDrawSetProportional(TextDrawWorkTimer[ill] , true);
		TextDrawSetShadow(TextDrawWorkTimer[ill] , 0);
	}// текстдравы с MAX_PLAYERS
*/
	//смена интов
	IntChangeTD[0] = TextDrawCreate(418.676177, 341.667022, "");
	TextDrawLetterSize(IntChangeTD[0], 0.000000, 0.000000);
	TextDrawTextSize(IntChangeTD[0], 90.000000, 90.000000);
	TextDrawAlignment(IntChangeTD[0], 1);
	TextDrawColor(IntChangeTD[0], -1);
	TextDrawSetShadow(IntChangeTD[0], 0);
	TextDrawSetOutline(IntChangeTD[0], 0);
	TextDrawBackgroundColor(IntChangeTD[0], 0);
	TextDrawFont(IntChangeTD[0], 5);
	TextDrawSetProportional(IntChangeTD[0], 0);
	TextDrawSetShadow(IntChangeTD[0], 0);
	TextDrawSetSelectable(IntChangeTD[0], true);
	TextDrawSetPreviewModel(IntChangeTD[0], 19134);
	TextDrawSetPreviewRot(IntChangeTD[0], 180.000000, 270.000000, 90.000000, 0.843105);

	IntChangeTD[1] = TextDrawCreate(132.408966, 342.250396, "");
	TextDrawLetterSize(IntChangeTD[1], 0.000000, 0.000000);
	TextDrawTextSize(IntChangeTD[1], 90.000000, 90.000000);
	TextDrawAlignment(IntChangeTD[1], 1);
	TextDrawColor(IntChangeTD[1], -1);
	TextDrawSetShadow(IntChangeTD[1], 0);
	TextDrawSetOutline(IntChangeTD[1], 0);
	TextDrawBackgroundColor(IntChangeTD[1], 0);
	TextDrawFont(IntChangeTD[1], 5);
	TextDrawSetProportional(IntChangeTD[1], 0);
	TextDrawSetShadow(IntChangeTD[1], 0);
	TextDrawSetSelectable(IntChangeTD[1], true);
	TextDrawSetPreviewModel(IntChangeTD[1], 19134);
	TextDrawSetPreviewRot(IntChangeTD[1], 180.000000, 90.000000, 90.000000, 0.843105);

	IntChangeTD[2] = TextDrawCreate(324.033966, 341.649902, "");
	TextDrawLetterSize(IntChangeTD[2], 0.000000, 0.000000);
	TextDrawTextSize(IntChangeTD[2], 90.000000, 90.000000);
	TextDrawAlignment(IntChangeTD[2], 1);
	TextDrawColor(IntChangeTD[2], -1);
	TextDrawSetShadow(IntChangeTD[2], 0);
	TextDrawSetOutline(IntChangeTD[2], 0);
	TextDrawBackgroundColor(IntChangeTD[2], 0);
	TextDrawFont(IntChangeTD[2], 5);
	TextDrawSetProportional(IntChangeTD[2], 0);
	TextDrawSetShadow(IntChangeTD[2], 0);
	TextDrawSetSelectable(IntChangeTD[2], true);
	TextDrawSetPreviewModel(IntChangeTD[2], 19454);
	TextDrawSetPreviewRot(IntChangeTD[2], 180.000000, 180.000000, 90.000000, 0.975072);

	IntChangeTD[3] = TextDrawCreate(222.364456, 341.066558, "");
	TextDrawLetterSize(IntChangeTD[3], 0.000000, 0.000000);
	TextDrawTextSize(IntChangeTD[3], 90.000000, 90.000000);
	TextDrawAlignment(IntChangeTD[3], 1);
	TextDrawColor(IntChangeTD[3], -1);
	TextDrawSetShadow(IntChangeTD[3], 0);
	TextDrawSetOutline(IntChangeTD[3], 0);
	TextDrawBackgroundColor(IntChangeTD[3], 0);
	TextDrawFont(IntChangeTD[3], 5);
	TextDrawSetProportional(IntChangeTD[3], 0);
	TextDrawSetShadow(IntChangeTD[3], 0);
	TextDrawSetSelectable(IntChangeTD[3], true);
	TextDrawSetPreviewModel(IntChangeTD[3], 19454);
	TextDrawSetPreviewRot(IntChangeTD[3], 180.000000, 180.000000, 90.000000, 0.975072);

	IntChangeTD[4] = TextDrawCreate(342.474273, 374.333404, "EXIT");
	TextDrawLetterSize(IntChangeTD[4], 0.711097, 2.667502);
	TextDrawAlignment(IntChangeTD[4], 1);
	TextDrawColor(IntChangeTD[4], -16776961);
	TextDrawSetShadow(IntChangeTD[4], 0);
	TextDrawSetOutline(IntChangeTD[4], 1);
	TextDrawBackgroundColor(IntChangeTD[4], 255);
	TextDrawFont(IntChangeTD[4], 1);
	TextDrawSetProportional(IntChangeTD[4], 1);
	TextDrawSetShadow(IntChangeTD[4], 0);


	IntChangeTD[5] = TextDrawCreate(241.742172, 369.666717, "BUY");
	TextDrawLetterSize(IntChangeTD[5], 0.817920, 3.349999);
	TextDrawAlignment(IntChangeTD[5], 1);
	TextDrawColor(IntChangeTD[5], 8126719);
	TextDrawSetShadow(IntChangeTD[5], 0);
	TextDrawSetOutline(IntChangeTD[5], 1);
	TextDrawBackgroundColor(IntChangeTD[5], 255);
	TextDrawFont(IntChangeTD[5], 1);
	TextDrawSetProportional(IntChangeTD[5], 1);
	TextDrawSetShadow(IntChangeTD[5], 0);
	
	
 	//карта битва до последнего
	BTMap = TextDrawCreate(457.562774, 232.583175, "samaps:map");
	TextDrawLetterSize(BTMap, 0.000000, 0.000000);
	TextDrawTextSize(BTMap, 182.000000, 212.000000);
	TextDrawAlignment(BTMap, 1);
	TextDrawColor(BTMap, -1);
	TextDrawSetShadow(BTMap, 0);
	TextDrawSetOutline(BTMap, 0);
	TextDrawBackgroundColor(BTMap, 255);
	TextDrawFont(BTMap, 4);
	TextDrawSetProportional(BTMap, 0);
	TextDrawSetShadow(BTMap, 0);
	
	//защита от бага зон
	for (new i; i<4; i++) {FirstZoneTD[i] = TextDrawCreate(0.0, 0.0, " "); SecondZoneTD[i] = TextDrawCreate(0.0, 0.0, " ");}
	
	//основное на пубг
	//фон
	BTMainTD[0] = TextDrawCreate(501.500000, 109.111038, "box");
	TextDrawLetterSize(BTMainTD[0], 0.000000, 2.849997);
	TextDrawTextSize(BTMainTD[0], 606.000000, 0.000000);
	TextDrawAlignment(BTMainTD[0], 1);
	TextDrawColor(BTMainTD[0], -1);
	TextDrawUseBox(BTMainTD[0], 1);
	TextDrawBoxColor(BTMainTD[0], 70);
	TextDrawSetShadow(BTMainTD[0], 0);
	TextDrawSetOutline(BTMainTD[0], 0);
	TextDrawBackgroundColor(BTMainTD[0], 255);
	TextDrawFont(BTMainTD[0], 1);
	TextDrawSetProportional(BTMainTD[0], 1);
	TextDrawSetShadow(BTMainTD[0], 0);

	BTMainTD[1] = TextDrawCreate(503.000000, 109.577728, "LD_SPAC:white");
	TextDrawLetterSize(BTMainTD[1], 0.000000, 0.000000);
	TextDrawTextSize(BTMainTD[1], 102.000000, 6.000000);
	TextDrawAlignment(BTMainTD[1], 1);
	TextDrawColor(BTMainTD[1], 1886418175);
	TextDrawSetShadow(BTMainTD[1], 0);
	TextDrawSetOutline(BTMainTD[1], 0);
	TextDrawBackgroundColor(BTMainTD[1], 255);
	TextDrawFont(BTMainTD[1], 4);
	TextDrawSetProportional(BTMainTD[1], 0);
	TextDrawSetShadow(BTMainTD[1], 0);
	
	BTMainTD[2] = TextDrawCreate(602.000000, 138.977737, "KAPTA:_~b~N__~w~GUNS:_~b~Alt");
	TextDrawLetterSize(BTMainTD[2], 0.274998, 1.021332);
	TextDrawAlignment(BTMainTD[2], 3);
	TextDrawColor(BTMainTD[2], -1);
	TextDrawSetShadow(BTMainTD[2], 0);
	TextDrawSetOutline(BTMainTD[2], 0);
	TextDrawBackgroundColor(BTMainTD[2], 255);
	TextDrawFont(BTMainTD[2], 1);
	TextDrawSetProportional(BTMainTD[2], 1);
	TextDrawSetShadow(BTMainTD[2], 0);
	
	//красный экран
	BTMainTD[3] = TextDrawCreate(0.000000, 0.000000, "_");
	TextDrawLetterSize(BTMainTD[3], 0.500000, 50.000000);
	TextDrawTextSize(BTMainTD[3], 676.805297, 500.000000);
	TextDrawAlignment(BTMainTD[3], 1);
	TextDrawColor(BTMainTD[3], -1);
	TextDrawUseBox(BTMainTD[3], 1);
	TextDrawBoxColor(BTMainTD[3], -16777180);
	TextDrawSetShadow(BTMainTD[3], 0);
	TextDrawSetOutline(BTMainTD[3], 0);
	TextDrawBackgroundColor(BTMainTD[3], 255);
	TextDrawFont(BTMainTD[3], 1);
	TextDrawSetProportional(BTMainTD[3], 1);
	TextDrawSetShadow(BTMainTD[3], 0);
	
	//синяя линия смещения
	BTLineTD = TextDrawCreate(503.000000, 109.577728, "LD_SPAC:white");
	TextDrawLetterSize(BTLineTD, 0.000000, 0.000000);
	TextDrawTextSize(BTLineTD, 2.000000, 6.000000);
	TextDrawAlignment(BTLineTD, 1);
	TextDrawColor(BTLineTD, 3342335);
	TextDrawSetShadow(BTLineTD, 0);
	TextDrawSetOutline(BTLineTD, 0);
	TextDrawBackgroundColor(BTLineTD, 255);
	TextDrawFont(BTLineTD, 4);
	TextDrawSetProportional(BTLineTD, 0);
	TextDrawSetShadow(BTLineTD, 0);
	
	//время зоны или зона
	BTTimeTD = TextDrawCreate(503.500000, 119.066627, "0:00");
	TextDrawLetterSize(BTTimeTD, 0.326499, 1.469333);
	TextDrawAlignment(BTTimeTD, 1);
	TextDrawColor(BTTimeTD, -1);
	TextDrawSetShadow(BTTimeTD, 0);
	TextDrawSetOutline(BTTimeTD, 0);
	TextDrawBackgroundColor(BTTimeTD, 255);
	TextDrawFont(BTTimeTD, 0);
	TextDrawSetProportional(BTTimeTD, 1);
	TextDrawSetShadow(BTTimeTD, 0);
	
	//игроков на бт
	BTPlayersTD = TextDrawCreate(545.599609, 118.666625, "Players:0");
	TextDrawLetterSize(BTPlayersTD, 0.305999, 1.600000);
	TextDrawAlignment(BTPlayersTD, 1);
	TextDrawColor(BTPlayersTD, -1);
	TextDrawSetShadow(BTPlayersTD, 0);
	TextDrawSetOutline(BTPlayersTD, 0);
	TextDrawBackgroundColor(BTPlayersTD, 255);
	TextDrawFont(BTPlayersTD, 1);
	TextDrawSetProportional(BTPlayersTD, 1);
	TextDrawSetShadow(BTPlayersTD, 0);
/*
	//alt menu
	AltMenuTD[0] = TextDrawCreate(162.562225, 190.000030, "box");
	TextDrawLetterSize(AltMenuTD[0], 0.000000, 17.121520);
	TextDrawTextSize(AltMenuTD[0], 472.000000, 0.000000);
	TextDrawAlignment(AltMenuTD[0], 1);
	TextDrawColor(AltMenuTD[0], -1);
	TextDrawUseBox(AltMenuTD[0], 1);
	TextDrawBoxColor(AltMenuTD[0], 47);
	TextDrawSetShadow(AltMenuTD[0], 0);
	TextDrawSetOutline(AltMenuTD[0], 0);
	TextDrawBackgroundColor(AltMenuTD[0], 255);
	TextDrawFont(AltMenuTD[0], 1);
	TextDrawSetProportional(AltMenuTD[0], 1);
	TextDrawSetShadow(AltMenuTD[0], 0);

	AltMenuTD[1] = TextDrawCreate(168.953140, 288.583221, "LD_SPAC:white");
	TextDrawLetterSize(AltMenuTD[1], 0.000000, 0.000000);
	TextDrawTextSize(AltMenuTD[1], 89.000000, 17.000000);
	TextDrawAlignment(AltMenuTD[1], 1);
	TextDrawColor(AltMenuTD[1], 32511);
	TextDrawSetShadow(AltMenuTD[1], 0);
	TextDrawSetOutline(AltMenuTD[1], 0);
	TextDrawBackgroundColor(AltMenuTD[1], 255);
	TextDrawFont(AltMenuTD[1], 4);
	TextDrawSetProportional(AltMenuTD[1], 0);
	TextDrawSetShadow(AltMenuTD[1], 0);
	TextDrawSetSelectable(AltMenuTD[1], true);

	AltMenuTD[2] = TextDrawCreate(274.839050, 288.583099, "LD_SPAC:white");
	TextDrawLetterSize(AltMenuTD[2], 0.000000, 0.000000);
	TextDrawTextSize(AltMenuTD[2], 89.000000, 17.000000);
	TextDrawAlignment(AltMenuTD[2], 1);
	TextDrawColor(AltMenuTD[2], 32511);
	TextDrawSetShadow(AltMenuTD[2], 0);
	TextDrawSetOutline(AltMenuTD[2], 0);
	TextDrawBackgroundColor(AltMenuTD[2], 255);
	TextDrawFont(AltMenuTD[2], 4);
	TextDrawSetProportional(AltMenuTD[2], 0);
	TextDrawSetShadow(AltMenuTD[2], 0);
	TextDrawSetSelectable(AltMenuTD[2], true);

	AltMenuTD[3] = TextDrawCreate(377.445404, 288.583129, "LD_SPAC:white");
	TextDrawLetterSize(AltMenuTD[3], 0.000000, 0.000000);
	TextDrawTextSize(AltMenuTD[3], 89.000000, 17.000000);
	TextDrawAlignment(AltMenuTD[3], 1);
	TextDrawColor(AltMenuTD[3], 32511);
	TextDrawSetShadow(AltMenuTD[3], 0);
	TextDrawSetOutline(AltMenuTD[3], 0);
	TextDrawBackgroundColor(AltMenuTD[3], 255);
	TextDrawFont(AltMenuTD[3], 4);
	TextDrawSetProportional(AltMenuTD[3], 0);
	TextDrawSetShadow(AltMenuTD[3], 0);
	TextDrawSetSelectable(AltMenuTD[3], true);

	AltMenuTD[4] = TextDrawCreate(212.693252, 288.583679, "3AMEHA");
	TextDrawLetterSize(AltMenuTD[4], 0.400000, 1.600000);
	TextDrawAlignment(AltMenuTD[4], 2);
	TextDrawColor(AltMenuTD[4], 8978431);
	TextDrawSetShadow(AltMenuTD[4], 0);
	TextDrawSetOutline(AltMenuTD[4], 1);
	TextDrawBackgroundColor(AltMenuTD[4], 255);
	TextDrawFont(AltMenuTD[4], 3);
	TextDrawSetProportional(AltMenuTD[4], 1);
	TextDrawSetShadow(AltMenuTD[4], 0);

	AltMenuTD[5] = TextDrawCreate(319.984771, 288.583679, "3AMEHA");
	TextDrawLetterSize(AltMenuTD[5], 0.400000, 1.600000);
	TextDrawAlignment(AltMenuTD[5], 2);
	TextDrawColor(AltMenuTD[5], 8978431);
	TextDrawSetShadow(AltMenuTD[5], 0);
	TextDrawSetOutline(AltMenuTD[5], 1);
	TextDrawBackgroundColor(AltMenuTD[5], 255);
	TextDrawFont(AltMenuTD[5], 3);
	TextDrawSetProportional(AltMenuTD[5], 1);
	TextDrawSetShadow(AltMenuTD[5], 0);

	AltMenuTD[6] = TextDrawCreate(421.654327, 288.583679, "3AMEHA");
	TextDrawLetterSize(AltMenuTD[6], 0.400000, 1.600000);
	TextDrawAlignment(AltMenuTD[6], 2);
	TextDrawColor(AltMenuTD[6], 8978431);
	TextDrawSetShadow(AltMenuTD[6], 0);
	TextDrawSetOutline(AltMenuTD[6], 1);
	TextDrawBackgroundColor(AltMenuTD[6], 255);
	TextDrawFont(AltMenuTD[6], 3);
	TextDrawSetProportional(AltMenuTD[6], 1);
	TextDrawSetShadow(AltMenuTD[6], 0);

	AltMenuTD[7] = TextDrawCreate(168.703140, 309.249969, "LD_SPAC:white");
	TextDrawLetterSize(AltMenuTD[7], 0.000000, 0.000000);
	TextDrawTextSize(AltMenuTD[7], 251.000000, 28.829973);
	TextDrawAlignment(AltMenuTD[7], 1);
	TextDrawColor(AltMenuTD[7], 7339840);
	TextDrawSetShadow(AltMenuTD[7], 0);
	TextDrawSetOutline(AltMenuTD[7], 0);
	TextDrawBackgroundColor(AltMenuTD[7], 255);
	TextDrawFont(AltMenuTD[7], 4);
	TextDrawSetProportional(AltMenuTD[7], 0);
	TextDrawSetShadow(AltMenuTD[7], 0);
	TextDrawSetSelectable(AltMenuTD[7], true);

	AltMenuTD[8] = TextDrawCreate(250.175674, 312.500000, "MENU");
	TextDrawLetterSize(AltMenuTD[8], 0.906471, 2.253332);
	TextDrawAlignment(AltMenuTD[8], 1);
	TextDrawColor(AltMenuTD[8], -1);
	TextDrawSetShadow(AltMenuTD[8], 0);
	TextDrawSetOutline(AltMenuTD[8], 2);
	TextDrawBackgroundColor(AltMenuTD[8], 255);
	TextDrawFont(AltMenuTD[8], 3);
	TextDrawSetProportional(AltMenuTD[8], 1);
	TextDrawSetShadow(AltMenuTD[8], 0);

	AltMenuTD[9] = TextDrawCreate(423.360412, 310.166717, "LD_SPAC:white");
	TextDrawLetterSize(AltMenuTD[9], 0.000000, 0.000000);
	TextDrawTextSize(AltMenuTD[9], 43.000000, 28.000000);
	TextDrawAlignment(AltMenuTD[9], 1);
	TextDrawColor(AltMenuTD[9], -16777145);
	TextDrawSetShadow(AltMenuTD[9], 0);
	TextDrawSetOutline(AltMenuTD[9], 0);
	TextDrawBackgroundColor(AltMenuTD[9], 255);
	TextDrawFont(AltMenuTD[9], 4);
	TextDrawSetProportional(AltMenuTD[9], 0);
	TextDrawSetShadow(AltMenuTD[9], 0);
	TextDrawSetSelectable(AltMenuTD[9], true);

	AltMenuTD[10] = TextDrawCreate(437.115661, 313.666503, "X");
	TextDrawLetterSize(AltMenuTD[10], 0.562107, 2.270833);
	TextDrawAlignment(AltMenuTD[10], 1);
	TextDrawColor(AltMenuTD[10], -16776961);
	TextDrawSetShadow(AltMenuTD[10], 0);
	TextDrawSetOutline(AltMenuTD[10], 0);
	TextDrawBackgroundColor(AltMenuTD[10], 255);
	TextDrawFont(AltMenuTD[10], 1);
	TextDrawSetProportional(AltMenuTD[10], 1);
	TextDrawSetShadow(AltMenuTD[10], 0);

	AltMenuTD[11] = TextDrawCreate(161.625167, 185.916671, "box");
	TextDrawLetterSize(AltMenuTD[11], 0.000000, -0.073205);
	TextDrawTextSize(AltMenuTD[11], 474.000000, 0.000000);
	TextDrawAlignment(AltMenuTD[11], 1);
	TextDrawColor(AltMenuTD[11], -1);
	TextDrawUseBox(AltMenuTD[11], 1);
	TextDrawBoxColor(AltMenuTD[11], 24063);
	TextDrawSetShadow(AltMenuTD[11], 0);
	TextDrawSetOutline(AltMenuTD[11], 0);
	TextDrawBackgroundColor(AltMenuTD[11], 255);
	TextDrawFont(AltMenuTD[11], 1);
	TextDrawSetProportional(AltMenuTD[11], 1);
	TextDrawSetShadow(AltMenuTD[11], 0);

	AltMenuTD[12] = TextDrawCreate(161.156646, 348.666656, "box");
	TextDrawLetterSize(AltMenuTD[12], 0.000000, -0.026353);
	TextDrawTextSize(AltMenuTD[12], 474.000000, 0.000000);
	TextDrawAlignment(AltMenuTD[12], 1);
	TextDrawColor(AltMenuTD[12], -1);
	TextDrawUseBox(AltMenuTD[12], 1);
	TextDrawBoxColor(AltMenuTD[12], 24063);
	TextDrawSetShadow(AltMenuTD[12], 0);
	TextDrawSetOutline(AltMenuTD[12], 0);
	TextDrawBackgroundColor(AltMenuTD[12], 255);
	TextDrawFont(AltMenuTD[12], 1);
	TextDrawSetProportional(AltMenuTD[12], 1);
	TextDrawSetShadow(AltMenuTD[12], 0);

	AltMenuTD[13] = TextDrawCreate(159.751083, 185.916732, "box");
	TextDrawLetterSize(AltMenuTD[13], 0.000000, 18.058563);
	TextDrawTextSize(AltMenuTD[13], 159.000000, 0.000000);
	TextDrawAlignment(AltMenuTD[13], 1);
	TextDrawColor(AltMenuTD[13], -1);
	TextDrawUseBox(AltMenuTD[13], 1);
	TextDrawBoxColor(AltMenuTD[13], 24063);
	TextDrawSetShadow(AltMenuTD[13], 0);
	TextDrawSetOutline(AltMenuTD[13], 0);
	TextDrawBackgroundColor(AltMenuTD[13], 255);
	TextDrawFont(AltMenuTD[13], 1);
	TextDrawSetProportional(AltMenuTD[13], 1);
	TextDrawSetShadow(AltMenuTD[13], 0);

	AltMenuTD[14] = TextDrawCreate(479.282897, 185.916778, "box");
	TextDrawLetterSize(AltMenuTD[14], 0.000000, 18.058563);
	TextDrawTextSize(AltMenuTD[14], 471.000000, 0.000000);
	TextDrawAlignment(AltMenuTD[14], 1);
	TextDrawColor(AltMenuTD[14], -1);
	TextDrawUseBox(AltMenuTD[14], 1);
	TextDrawBoxColor(AltMenuTD[14], 24063);
	TextDrawSetShadow(AltMenuTD[14], 0);
	TextDrawSetOutline(AltMenuTD[14], 0);
	TextDrawBackgroundColor(AltMenuTD[14], 255);
	TextDrawFont(AltMenuTD[14], 1);
	TextDrawSetProportional(AltMenuTD[14], 1);
	TextDrawSetShadow(AltMenuTD[14], 0);

	AltMenuTD[15] = TextDrawCreate(377.413330, 164.333312, "MEHU_CEPBEPA");
	TextDrawLetterSize(AltMenuTD[15], 0.400000, 1.600000);
	TextDrawAlignment(AltMenuTD[15], 1);
	TextDrawColor(AltMenuTD[15], -1);
	TextDrawSetShadow(AltMenuTD[15], 0);
	TextDrawSetOutline(AltMenuTD[15], 1);
	TextDrawBackgroundColor(AltMenuTD[15], 255);
	TextDrawFont(AltMenuTD[15], 3);
	TextDrawSetProportional(AltMenuTD[15], 1);
	TextDrawSetShadow(AltMenuTD[15], 0);
*/

