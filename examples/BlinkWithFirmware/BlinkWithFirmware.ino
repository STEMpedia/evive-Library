/* Here we are blinking bi-color LED "M1" of evive connected on Pin 28 and 29. 
 * Unlike basic blinking code that uses delay for blink action here blinking 
 * is achieved by switching between firmware and code of glowing LED.
 * Library of evive is included in code which makes this task possible. 
 * Intially LED glows in two colours namely red and green now as the 
 * navKey is center pressed we navigate to firmware and the uploaded code 
 * stops running hence led stops changing color for a while till we exit from the firmware
 * by using Exit from the menu. As we exit firmware the code to glow led in 
 * two colours starts again.In this code status bar is also shown for 
 * information related to battery level and variable voltage value.
 * 
 * Created by Nihar Shah.
 * This code is in public domain.
 * Explore more at https://thestempedia.com/tutorials/blink-with-firmware-on-evive
 */
 
#include <evive.h>            // Include evive library

void setup() {
  pinMode(LED28, OUTPUT);     // Set pin as output mode (LED28 = Pin 28)
  pinMode(LED29, OUTPUT);     // Set pin as output mode (LED29 = Pin 29)
  drawStatusBar();            // shows variable voltage value (VVR) and battery level
}

void loop() {
 //By center pressing navigation key evive Firmware opens.
  drawStatusBar();            // shows variable voltage value (VVR) and battery level
  digitalWrite(LED28, HIGH);  // glows led in green
  digitalWrite(LED29, LOW);
  delay(1000);                // wait for a second
  digitalWrite(LED29, HIGH);  // glows led in red
  digitalWrite(LED28, LOW);   
  delay(1000);                // wait for a second
}
