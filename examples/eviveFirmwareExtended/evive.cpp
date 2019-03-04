/*
 * evive.cpp
 * Created on: April 16, 2016
 * Author: dhrups
 * Last update: May 10, 2016
 * Version: 1.0
 */
#include "evive.h"

int freeRam ()
{
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}
void eviveFirmware(void)
{
	exitmenu = 1;
	Serial.begin(250000);
	tft_init(INITR_BLACKTAB);
  	while (1)
	{
		tft_update(); 	//Updates the TFT on any action in menu
		action();                 //Runs the function in array actionFuncList. All functions/user defined programs are added in action FuncList array upon selection.
		if (exitmenu == 0)
			break;
	}
	tft.fillScreen(ST7735_BLACK);
	tft.drawBitmap(45, 29, evive_logo, 71, 71, ST7735_BLUE);
}
