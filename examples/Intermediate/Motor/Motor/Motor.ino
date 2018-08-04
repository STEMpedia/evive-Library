/*
   evive motor control through motor library

   For Motor 1: Direction digital pins are MOTOR1_D1 and MOTOR1_D2, and PWM pin is digital pin MOTOR1_EN
   For Motor 2: Direction digital pins are MOTOR2_D1 and MOTOR2_D2, and PWM pin is digital pin MOTOR2_EN

   This code demonstrates how to use motor library to start motor, stop motor, control its direction of rotation and speed..
   Here a dc motor is plugged in channel M1 on evive. And that motor is rotated clockwise and anti-clockwise at constant pwm. 
   Created by Nihar Shah.
   This code is in public domain. 
   Explore more: https://thestempedia.com/tutorials/dc-motor-driving/
*/

#include <evive.h>
Motor Motor1 = Motor(MOTOR1_D1, MOTOR1_D2, MOTOR1_EN);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  
  //Rotate motor in CW direction with PWM 200
  Motor1.moveMotor(200);
  delay(1000);
  
  // Stop Motor
  Motor1.freeMotor();
  delay(1000);
  
  // Rotate motor in CCW direction with PWM -200
  Motor1.moveMotor(-200);
  delay(1000);

  // Stop Motor
  Motor1.freeMotor();
  delay(1000);
}
