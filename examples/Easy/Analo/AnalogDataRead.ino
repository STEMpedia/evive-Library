/* Analog Data Read
 * Read analog data of Potentiometer 1 (A9) on evive and publish it Tft screen.
 * 
 * Explore more on: https://thestempedia.com/tutorials/evive-analog-input/
 */

#include <evive.h>          //include evive library

void setup() {
tft.init(INITR_BLACKTAB);
tft.setRotation(1);
tft.fillScreen(ST7735_BLACK);
pinMode(POT1,INPUT);        //Set pin as input mode (POT1 = A9)
}

int potData;                //variable to store analog reading of potentiometer 1

void loop() {
//print text "Analog Read Value:" on tft screen
tft.drawRoundRect(20, 30, 120, 68, 10, ST7735_WHITE);
tft.setTextColor(ST7735_WHITE);
tft.setTextSize(1);
tft.setCursor(25, 40);
tft.println("Analog Read Value: ");
//read analog data of potentiometer on Pin A9
potData = analogRead(POT1);
tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
tft.setTextSize(2);
tft.setCursor(55, 70);
//To prevent overwrite problem the analogvalues are printed in the following manner 
if(potData < 10)
{
 tft.print(potData);
 tft.print("   ");      //3 spaces
}
else if(potData < 100)
{
 tft.print(potData);
 tft.print("  ");      //2 spaces
}
else if(potData < 1000)
{
 tft.print(potData);
 tft.print(" ");      //1 spaces
}
else
{
  tft.print(potData);
}
delay(100);                 //delay of 100 milli seconds in each loop
}

