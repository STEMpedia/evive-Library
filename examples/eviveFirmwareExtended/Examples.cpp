/*
 * addFunction.cpp
 *
 *  Created on: Jul 30, 2016
 *      Author: dhrups
 */
#include "Examples.h"

/////////////////Setup and loop functions for user defined functions/////////////////

#ifdef EXAMPLE_1
// the setup function runs once when you select the user defined function
void setup_example_1(){
	// initialize digital pin LED_BUILTIN as an output.
	pinMode(LED_BUILTIN, OUTPUT);
}
// the loop function runs continuously when you select the user defined function
void loop_example_1(){
	// Remove this example code and put your user defined (custom) code here, to run repeatedly:
	// read the value from the sensor:
	uint16_t sensorValue = analogRead(A9);
	// turn the ledPin on
	digitalWrite(LED_BUILTIN, HIGH);
	// stop the program for <sensorValue> milliseconds:
	delay(sensorValue);
	// turn the ledPin off:
	digitalWrite(LED_BUILTIN, LOW);
	// stop the program for for <sensorValue> milliseconds:
	delay(sensorValue);
}
#endif


#ifdef EXAMPLE_2
// the setup function runs once when you select the user defined function
void setup_example_2(){
	tft.setCursor(20,80);
	tft.fillRect(20, 80, 150, 8, ST7735_BLACK);
	tft.setTextColor(ST7735_RED, ST7735_BLACK);
	tft.print(F("Analog Value: "));
}

// the loop function runs continuously when you select the user defined function
void loop_example_2(){
	tft.setCursor(100,80);
	tft.setTextColor(ST7735_RED, ST7735_BLACK);
	tft.print(analogRead(A9));
	tft.print("   ");			//to remove the remaining digits of any bigger number (in terms of number of digits) printed last time
}
#endif

#ifdef EXAMPLE_3
// the setup function runs once when you select the user defined function
void setup_example_3(){
	ade791x_init();
	delay(100);
	tft.setTextColor(ST7735_RED);
	tft.setCursor(LEFT_MARGIN, TOP_MARGIN + ROW_HEIGHT * 8);
	tft.println(F("   Probe V"));
	tft.setCursor(LEFT_MARGIN, TOP_MARGIN + ROW_HEIGHT * 10);
	tft.println(F("   V"));
	Serial.println(F("Setup 4 ends"));
}
// the loop function runs continuously when you select the user defined function
void loop_example_3(){
	tft.setTextColor(ST7735_YELLOW, ST7735_BLACK);
	tft.setCursor(LEFT_MARGIN + 19, TOP_MARGIN + ROW_HEIGHT * 9);
	//adeAdc.readV();
	ade791x_read_v1();
	tft.print(ade791x_read_v1() / 1000.0);
	//tft.print(adeAdc.readVm() / 1000.0);
	//tft.print(adeAdc.readIm() / 1000.0);
	tft.println("    ");
	delay(100);
}
#endif

#ifdef EXAMPLE_4
// the setup function runs once when you select the user defined function
TftMonitor tftMonitor;
void setup_example_4(){
	tftMonitor.begin();
	pinMode(A9,INPUT);
}

// the loop function runs continuously when you select the user defined function
void loop_example_4(){
	String fa =String(analogRead(A9));
	tftMonitor.print("Pot 1 value: ");
	tftMonitor.println(fa);//Pot1 Value is Printed on TFT Monitor
	delay(1000);
}
#endif
///////////////////// Write other functions below this ////////////////////
//Same as  Arduino <XXX.ino> file
#ifdef EXAMPLE_5
uint8_t receivedData = 0, counter = 0;
bool flag = 0, clearInstructions=0;
uint8_t ModuleId = 0;
uint8_t functionId = 0;
uint8_t Arg1 = 0;
uint8_t Arg2 = 0;
uint8_t dataByte[2];

void sendBoardId()
{
	Serial3.write(0xFF);
	Serial3.write(0x00);
	Serial3.write(0x03);
	Serial3.write(0x01);
	Serial3.write(0x04);
	Serial3.write(0x02);
	Serial3.write(0x00);
	Serial3.write(0x00);
	Serial3.write(0x01);
	Serial3.write(0x00);
}

void mobileRobot()
{
if(ModuleId == 1)
 {
	 if(clearInstructions == 0)       //Clear guiding instructions
	 {
		tft.fillScreen(ST7735_BLACK);
		clearInstructions = 1;
	 }
	 
  if (functionId == 1)
  {
	if ((dataByte[1]&0x01) == 0x01)       //UP
    {
		//Serial.println("UP");
		 _motor1.moveMotor(255);
         _motor2.moveMotor(255);
         tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	     tft.setTextSize(2);
		 tft.setCursor(30,50);
         tft.print(" Forward ");		
    }
    if ((dataByte[1]&0x02) == 0x02)     //DOWN
    {
		//Serial.println("DOWN");
       _motor1.moveMotor(-255);
       _motor2.moveMotor(-255);
	   tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	   tft.setTextSize(2);
	   tft.setCursor(30,50);
	   tft.print("Backward ");
    }
    if ((dataByte[1]&0x04) == 0x04)      //LEFT
    {
		//Serial.println("LEFT");
	  _motor1.moveMotor(-255);
      _motor2.moveMotor(255);
      tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	  tft.setTextSize(2);
	  tft.setCursor(30,50);	  
      tft.print("  Left    ");	  
    }
    if ((dataByte[1]&0x08) == 0x08)    //RIGHT
    {
		//Serial.println("RIGHT");
		_motor1.moveMotor(255);
        _motor2.moveMotor(-255);	
        tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print(" Right    ");			
    }
	if(dataByte[1] == 0)   //Stop
	{
	//	Serial.println("STOP");
	    _motor1.freeMotor();
	    _motor2.freeMotor();
	    tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print("  Stop    ");		
	}
	if((dataByte[0]&0x04) == 0x04)         //Trinagle  for moving clawn up 
	{
		_servo1.write(180);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print(" Claw Up ");	
	}
	if((dataByte[0]&0x10) == 0x10)         //Cross for moving clawn down 
	{
		_servo1.write(0);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print("Claw Down");	
	}
	if((dataByte[0]&0x20) == 0x20)         //Square  for opening gripper
	{
		_servo2.write(0);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print(" Open    ");	
	}
	if((dataByte[0]&0x08) == 0x08)         //Square  for opening gripper
	{
		_servo2.write(60);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print(" Close   ");	
	}
  }
  if(functionId == 2 || functionId == 3)
  {
	  int radius = dataByte[1]& 0x07;
      int angle = (dataByte[1]>>3)*15;
      int x_axis = float(radius*(float(cos(float(angle*PI/180)))));
      int y_axis = float(radius*(float(sin(float(angle*PI/180)))));
	  if(y_axis > 3 && x_axis < 3 && x_axis > -3)
	  {
		 _motor1.moveMotor(255);
         _motor2.moveMotor(255);
         tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	     tft.setTextSize(2);
		 tft.setCursor(30,50);
         tft.print(" Forward ");			 
	  }
	  else if(x_axis < -3 && y_axis > -3 && y_axis < 3)
	  {
		 _motor1.moveMotor(255);
         _motor2.moveMotor(-255);
         tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	     tft.setTextSize(2);
		 tft.setCursor(30,50);
         tft.print(" Right    ");			 
	  }
	  else if(x_axis > 3 && y_axis > -3 && y_axis < 3)
	  {
		 _motor1.moveMotor(-255);
         _motor2.moveMotor(255);
         tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	     tft.setTextSize(2);
		 tft.setCursor(30,50);
         tft.print("  Left    ");			 
	  }
	  else if(y_axis < -3 && x_axis < 3 && x_axis > -3)
	  {
		 _motor1.moveMotor(-255);
         _motor2.moveMotor(-255);
		 tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	     tft.setTextSize(2);
		 tft.setCursor(30,50);
         tft.print(" Backward ");	
	  }
	  else
	  {
		 _motor1.freeMotor();
         _motor2.freeMotor();
		 tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	     tft.setTextSize(2);
		 tft.setCursor(30,50);
         tft.print("  Stop    ");	
	  }
	
	if((dataByte[0]&0x04) == 0x04)         //Trinagle  for moving clawn up 
	{
		_servo1.write(180);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print(" Claw Up ");	
	}
	if((dataByte[0]&0x10) == 0x10)         //Cross for moving clawn down 
	{
		_servo1.write(0);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print("Claw Down");	
	}
	if((dataByte[0]&0x20) == 0x20)         //Square  for opening gripper
	{
		_servo2.write(0);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print("  Open   ");	
	}
	if((dataByte[0]&0x08) == 0x08)         //Square  for opening gripper
	{
		_servo2.write(60);
		tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	    tft.setTextSize(2);      
	    tft.setCursor(30,50);	  
        tft.print(" Close   ");	
	}
    }
  }
}


void processBTData()
{
  while (Serial3.available() != 0)
  {
	receivedData = Serial3.read();
  //  Serial.print(receivedData);
  //  Serial.print("  ");

    if (flag == 1)
    {
      counter++;
    }
  //  Serial.println(counter);
    if (receivedData == 255)   //Start Frame
    {
	   flag = 1;
    }

    if (counter == 1)
    {
      ModuleId = receivedData;
    //  Serial.println(ModuleId);
    }
    if (counter == 2)
    {
      functionId = receivedData;
    //  Serial.println(functionId);
    }
    if (counter == 3)
    {
      Arg1 = receivedData;
    //  Serial.println(Arg1);
    }
    if (counter == 4)
    {
      Arg2 == receivedData;
    //  Serial.println(Arg2);
    }
    if (counter == 5 && (Arg1 != 0))
    {
      dataByte[0] = receivedData;
    //  Serial.print(dataByte[0]);
    //  Serial.print("  ");
    }
    if (counter == 6 && (Arg1 != 0))
    {
      dataByte[1] = receivedData;
    //  Serial.println(dataByte[1]);
    }
    if (counter == 5 && receivedData == 0 && ModuleId == 0)      // For BoardId
    {
	//  Serial.println("BoardId");	
	  sendBoardId();
      counter = 0;
      flag = 0;
    }
    if (counter == 7 && receivedData == 0)
    {
      mobileRobot();
      counter = 0;
      flag = 0;
    }
  }
}

void setup_example_5(){
	 Serial.println("example5");
	 tft.fillScreen(ST7735_BLACK);
	_motor1.attachMotor(MOTOR1_D1, MOTOR1_D2, MOTOR1_EN);
	_motor2.attachMotor(MOTOR2_D1, MOTOR2_D2, MOTOR2_EN);
	_motor1.freeMotor();
	_motor2.freeMotor();
	_servo1.attach(2);    //claw servo for pick and place
	_servo2.attach(3);    //up down servo for pick and place
	_servo1.write(0);
	_servo2.write(0);
	tft.setTextSize(1);
	tft.setTextColor(ST7735_RED,ST7735_BLACK);
	tft.setCursor(0,20);
	tft.println("Follow these steps:");
	tft.setCursor(2,30);
	tft.println("1.Mount evive and motor on  chassis.");
	tft.setCursor(2,50);
	tft.print("2.Plug HC-05 module to      evive.");
	tft.setCursor(2,70);
	tft.println("3.Connect it with Dabble    app in your Smartphone.");
	tft.setCursor(2,90);
	tft.println("4.Open Gamepad module.");
	tft.setCursor(2,100);
	tft.println("5.Use buttons or joystick   to move robot.");
	
	/*tft.setTextColor(ST7735_WHITE,ST7735_BLACK);
	tft.setTextSize(2);      
	tft.setCursor(40,50);	  
	tft.print(" Stop   ");*/	
	Serial3.begin(115200);
	
}

void loop_example_5(){
	processBTData();
}

#endif

//DO NOT EDIT FOLLOWING FUNCTION
void add_example(uint8_t funNum){
	if(funNum==1){
#ifdef EXAMPLE_1
		setup_example_1();
		actionAdd(loop_example_1, 1);
#endif
	}
#ifdef EXAMPLE_2
	else if(funNum==2){
		setup_example_2();
		actionAdd(loop_example_2, 1);
	}
#endif
#ifdef EXAMPLE_3
	else if(funNum==3){
		setup_example_3();
		actionAdd(loop_example_3, 1);
	}
#endif
#ifdef EXAMPLE_4
	else if(funNum==4){
		setup_example_4();
		actionAdd(loop_example_4, 1);
	}
#endif
#ifdef EXAMPLE_5
	else if(funNum==5){
		setup_example_5();
		actionAdd(loop_example_5, 1);
	}
#endif
}

void remove_other_example(uint8_t funNum){
#ifdef EXAMPLE_1
	if(funNum!=1){
		actionRemove(loop_example_1);
	}
#endif
#ifdef EXAMPLE_2
	if(funNum!=2){
		actionRemove(loop_example_2);
	}
#endif
#ifdef EXAMPLE_3
	if(funNum!=3){
		actionRemove(loop_example_3);
	}
#endif
#ifdef EXAMPLE_4
	if(funNum!=4){
		actionRemove(loop_example_4);
	}
#endif
#ifdef EXAMPLE_5
	if(funNum!=5){
		actionRemove(loop_example_5);
	}
#endif
}
