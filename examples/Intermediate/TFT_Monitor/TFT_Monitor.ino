/*
	This example shows how to plot any variable on evive TFT display.

  Explore more on: https://thestempedia.com/tutorials/tft-monitor/
  Created by Dhrupal Shah.
  
  This code is in public domain.
  
*/

#include<evive.h>                         //include evive library

TftMonitor tft_Monitor;                     // Initialize a class object

void setup(){
  tft_init(INITR_BLACKTAB);               //Use either INITR_BLACKTAB or INITR_GREENTAB. Initialize TFT screen in library screen.cpp
  tft_Monitor.begin();                     // Begins tftMonitor
  pinMode(A9,INPUT);                      // Set pin as input mode (POT1 = A9) 
}

// the loop function runs continuously when you select the user defined function
void loop(){
  tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
  tft_Monitor.print("Pot 1 value: ");
  tft_Monitor.println(analogRead(A9));     // Pot1 Value is printed on TFT Monitor
  delay(50);
}
