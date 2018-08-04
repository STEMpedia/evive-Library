/*
   evive servo example
   This example demonstrates how to use servo motor on evive.
   For this servo is rotated as per movement of POT1 on evive.
   One can also use POT2 of evive for same purpose.

  To control servo 1(S1) use SERVO1_ATTACH.
  To control servo 2(S2) use SERVO2_ATTACH.

  
  This code is in public domain.
  
  Explore more on : https://thestempedia.com/tutorials/servo/
   
*/
#include<evive.h>
Servo myservo;  // create servo object to control a servo
int angle=0;
void setup() {
  myservo.attach(SERVO1_ATTACH);  // attaches the servo on pin S1 to the servo object
}

void loop() {
  angle = analogRead(POT1);            // reads the value of the potentiometer (value between 0 and 1023)
  angle = map(angle, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(angle);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
