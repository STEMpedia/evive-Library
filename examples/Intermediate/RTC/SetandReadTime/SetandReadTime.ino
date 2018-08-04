/*
  evive RTC Write Operation

  This code demonstrate how to set time and date on PCF8563 (a Real Time Clock) and get updated time and date from it.
  Here intially time of RTC is set.After that time and date updated by rtc are printed on evive screen.
  Created by Mimansa Maheshwari
  This code is in public domain.
  Explore more on: https://thestempedia.com/tutorials/rtc/
*/
#include <evive.h>
Rtc_Pcf8563 rtc;
String weekDay[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
void setup() {
  tft.init(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST7735_BLACK);
  
  //Draw round rectangle border on evive screen
  tft.drawRoundRect(2, 2, 156, 123, 10, ST7735_BLUE);
  
  //Print evive logo on screen
  tft.drawBitmap(45, 20, evive_logo, 71, 71, ST7735_BLUE);

  //clears all registers
  rtc.initClock();   //initialize  clock
  /* set a date to start with.
     day, weekday, month, century, year */
  rtc.setDate(28, 6, 7, 0, 18);            // century 0 for 2000 and 1 for 1999.  
  /*set time in  hr, min, sec  format*/
  rtc.setTime(19, 15, 40);
  
}

void loop() {
  //Get Date from RTC and print it on evive Screen
  tft.setCursor(7, 7);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.print(rtc.formatDate(0x01));             //0x01 for dd-mm-yyyy, 0x02 for yyyy-mm-dd ,0x04 for mm/dd/yyyy format
  
  //Get weekDay from RTC and print it on evive Screen
  tft.setCursor(135, 7);
  tft.setTextSize(1);
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.print(weekDay[rtc.getWeekday()]);
  
  //Get Time from RTC and print it on evive Screen
  tft.setTextColor(ST7735_WHITE, ST7735_BLACK);
  tft.setTextSize(2);
  tft.setCursor(33, 100);
  tft.print(rtc.formatTime(0x01));            //0x01 for Hours:minutes:seconds , 0x02 for Hours:Minutes 
}
