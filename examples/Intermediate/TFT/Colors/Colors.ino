/*

This Program demonstrates various colours on TFT display
made for evive platform.

Created by Nihar Shah.

This code is in public domain.

Explore more on : https://thestempedia.com/tutorials/tft-text-manipulation/
*/
#include <evive.h>
void setup() {
  Serial.begin(250000);
  tft.init(INITR_BLACKTAB);
  tft.setRotation(1);
  Serial.println("Initialized");
  tft.fillScreen(ST7735_BLACK);
}

void loop() {
  tft.setTextColor(ST7735_WHITE);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("Hello World");
  tft.println("");
  tft.println("My name is evive and this is TFT display in         white colour.");
  delay(2000);
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_RED);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("Hello World");
  tft.println("");
  tft.println("My name is evive and this is TFT display in         red colour.");
  delay(2000);
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("Hello World");
  tft.println("");
  tft.println("My name is evive and this is TFT display in         blue colour.");
  delay(2000);
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("Hello World");
  tft.println("");
  tft.println("My name is evive and this is TFT display in         yellow colour.");
  delay(2000);
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_GREEN);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("Hello World");
  tft.println("");
  tft.println("My name is evive and this is TFT display in         green colour.");
  delay(2000);
  tft.fillScreen(ST7735_BLACK);

  tft.setTextColor(ST7735_MAGENTA);
  tft.setTextSize(1);
  tft.setCursor(0, 10);
  tft.println("Hello World");
  tft.println("");
  tft.println("My name is evive and this is TFT display in         Magenta colour.");
  delay(2000);
  tft.fillScreen(ST7735_BLACK);
}
