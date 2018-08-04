/*
   Serial LED
   In this example control LED marked as M1 using Serial Communication

   Open the serial monitor in Arduino IDE and send 'H' to turn on LED and 'L' to turn it off.
   By Nihar Shah, Agilo Research
   On 29 December 2017

   Explore more on: https://thestempedia.com/tutorials/serial-communication/

*/
#include <evive.h>
void setup() {
  Serial.begin (115200);    // start Serial Communication at 115200
  pinMode(LED28, OUTPUT);
}
char incomingData;
void loop() {
  while (Serial.available())
  {
    incomingData = Serial.read();
  }
  if (incomingData == 'H')
    digitalWrite(LED28, HIGH);
  if (incomingData == 'L')
    digitalWrite(LED28, LOW);

}
