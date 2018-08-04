/* This example demonstrates how to use motor with Potentiometer
   attached in evive

   For Motor 1: Direction digital pins are MOTOR1_D1 and MOTOR1_D2, and PWM pin is digital pin MOTOR1_EN
   For Motor 2: Direction digital pins are MOTOR2_D1 and MOTOR2_D2, and PWM pin is digital pin MOTOR2_EN

   Created by Nihar Shah.
   This code is in public domain.
   Explore more at :https://thestempedia.com/tutorials/dc-motor-driving/
    
*/

#include <evive.h>

Motor Motor1 = Motor(MOTOR1_D1, MOTOR1_D2, MOTOR1_EN); // defines motor 1

int potData=0;
void setup() { 
  // put your setup code here, to run once:

}

void loop() {
  potData=analogRead(POT1); // reads pot data between 0 to 1023.
  potData = map(potData,0,1023,0,255);  //motor input range is 0 to 255 hence mapping potentiometer value in this range.
  Motor1.moveMotor(potData);  // writes motor according to potentiometer value. 
}
