 /*
  * Version 2.0.3
  * This firmware is developed for evive [https://thestempedia.com].
  * This is licensed under GNU GPL V3 [http://www.gnu.org/licenses/gpl.txt].
  * Written by Dhrupal R Shah for evive platform, Agilo Research.
  * Last update: 2018, August 2, by Mimansa Maheshwari
  
  * Copyright (c) 2018 Agilo Research.  All rights reserved.
  *
  * Getting started with evive: https://thestempedia.com
  *
  * NOTE: Works with Arduino IDE 1.6.6 or later [https://www.arduino.cc/en/Main/Software]
 */

#include "evive.h"

void setup(){
  Serial.begin(BAUDRATE);			//Default BAUD Rate: 250000, edit the macro in configuration.h
	tft_init(INITR_BLACKTAB);			//Use either INITR_BLACKTAB or INITR_GREENTAB. Initialize TFT screen in library screen.cpp
}

void loop(){
  tft_update();								//Updates the TFT on any action in menu
  action();										//Runs the function in array actionFuncList. All functions/user defined programs are added in action FuncList array upon selection.
}
