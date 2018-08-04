/*
 * servoControl.cpp
 *
 *  Created on: May 6, 2016
 *      Author: dhrups
 */
#include "ServoControl.h"

bool _SERVO1_EN = 0;
bool _SERVO2_EN = 0;
Servo _servo1, _servo2;
int prevAngleServo1, prevAngleServo2;
unsigned long lastServoMoveTime = 0;

void controlServo(){
	//Serial.println("ServoCtrl");
	if((millis() - lastServoMoveTime) > MIN_TIME2){
	 if(_SERVO1_EN)
	 { prevAngleServo1 = _servo1.read();
	 	 _servo1.write(int(map(pot1.getValue(),0, 1023, 0, 180)));
	 	 //Serial.println(_servo1.read());
	 }
	 if(_SERVO2_EN)
	 { prevAngleServo2 = _servo2.read();
		 _servo2.write(int(map(pot2.getValue(),0, 1023, 0, 180)));
	 }
	 lastServoMoveTime = millis();
	}
}

int prevValueServo1(){
	return prevAngleServo1;
}

int prevValueServo2(){
	return prevAngleServo2;
}

void addServo1(){
	_MOTOR1_EN = 0;
	_SERVO1_EN = 1;
	_STEPPER_EN = 0;
	_servo1.attach(SERVO1_ATTACH);
	actionAdd(controlServo, 1);
  prevAngleServo1 = _servo1.read();
  prevAngleServo2 = _servo2.read();
}

void addServo2(){
	_MOTOR2_EN = 0;
	_SERVO2_EN = 1;
	_STEPPER_EN = 0;
	_servo2.attach(SERVO2_ATTACH);
	actionAdd(controlServo, 1);
  prevAngleServo1 = _servo1.read();
  prevAngleServo2 = _servo2.read();
}

void addServo12(){
	addServo1();
	addServo2();
}
