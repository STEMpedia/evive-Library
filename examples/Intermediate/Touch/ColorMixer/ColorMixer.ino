/*
   Colour Mixer
   
  In this program three touch pins are assigned names R,G and B signifying red ,green and blue color.
  Depending upon the number of pins touched and which pins are touched corresponding colors are displayed on screen.
  For example touching red displays Red bar on screen similarly if both red and green are touched yellow is displayed 
  on screen.  

   Made by Nihar Shah, Agilo Research.
   On 31 Dec, 2017
   Explore more on:https://thestempedia.com/tutorials/arduino-ide-touch-input/
*/
#define red 1
#define green 2
#define blue 3
#include <evive.h>
void setup() {
  tft_init(INITR_GREENTAB);              // initialize a ST7735S chip, black tab
  tft.fillScreen(ST7735_BLACK);         // clear screen
  touchPins.begin(0x5A);    
  
  // start touch
}
bool r, g, b;
void loop() {
  r = touchPins.isTouched(red);                     // check red is touched or not?
  g = touchPins.isTouched(green);                   // check green is touched or not?
  b = touchPins.isTouched(blue);                   // check blue is touched or not?
  //enter all the combinations 
  if (r & g & b)
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_WHITE);
  else if (r & g)
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_YELLOW);
  else if (r & b)
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_MAGENTA);
  else if (g & b)
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_CYAN);
  else if (r)
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_RED);
  else if (g)
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_GREEN);
  else if (b)
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_BLUE);
  else
    tft.fillRoundRect(20, 30, 120, 68, 10, ST7735_BLACK);
}
