/*
  Using TFT Display

  This code shows how to use TFT display attached on evive.
  Explore more on:https://thestempedia.com/tutorials/tft-hello/
*/

#include <evive.h>
void setup() {
tft_init(INITR_BLACKTAB); // this is used to initialize TFT display
tft.setRotation(1); // this rotates screen by 90 degree
tft.fillScreen(ST7735_BLACK); // this filles display with black colour
tft.setCursor(0,10); // this sets cursor to write on (0,10) location
tft.setTextColor(ST7735_WHITE);
tft.println("Hello World!"); //print function
tft.println("");
tft.print("My name is evive and this is my first TFT display code.");
 
// put your setup code here, to run once:
}

void loop() {
// put your main code here, to run repeatedly:

}
