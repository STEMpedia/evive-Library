/*
  Using TFT Display to draw shapes

  This code shows how to use TFT display attached on evive for drawing different shapes.
  Explore more on : https://thestempedia.com/tutorials/tft-graphics/
*/

#include <evive.h>
void setup() {
  tft_init(INITR_BLACKTAB); // this is used to initialize TFT display
  tft.fillScreen(ST7735_BLACK); // this filles display with black colour
}
void loop() {
  // Drawing Lines
  tft.drawLine(10, 10, 150, 118, ST7735_BLUE);
  tft.drawLine(10, 118, 150, 10, ST7735_BLUE);
  delay(1000);
  tft.fillScreen(ST7735_BLACK);

  // Drawing Fast Verticle Lines
  for (int i = 10; i < 151; i = i + 10)
  {
    tft.drawFastVLine(i, 1, 128, ST7735_BLUE);
  }

  // Drawing Fast Horizontal Lines
  for (int i = 10; i < 121; i = i + 10)
  {
    tft.drawFastHLine(1, i, 160, ST7735_BLUE);
  }
  delay(1000);
  tft.fillScreen(ST7735_BLACK);

  // Draw Rectangle
  tft.drawRect(10, 10, 140, 108, ST7735_WHITE);
  tft.fillRect(20, 20, 120, 88, ST7735_BLUE);
  delay(1000);
  tft.fillScreen(ST7735_BLACK);

  // Draw Round Rectangle
  tft.drawRoundRect(10, 10, 140, 108, 10, ST7735_WHITE);
  tft.fillRoundRect(20, 20, 120, 88, 4, ST7735_BLUE);
  delay(1000);
  tft.fillScreen(ST7735_BLACK);

  // Draw Circle
  tft.drawCircle(80, 64, 60, ST7735_WHITE);
  tft.fillCircle(80, 64, 50, ST7735_BLUE);
  delay(1000);
  tft.fillScreen(ST7735_BLACK);

  // Draw Triangle
  tft.drawTriangle(80, 10, 10, 118, 150, 118, ST7735_WHITE);
  tft.fillTriangle(80, 30, 30, 108, 130, 108, ST7735_BLUE);
  delay(1000);
  tft.fillScreen(ST7735_BLACK);
}
