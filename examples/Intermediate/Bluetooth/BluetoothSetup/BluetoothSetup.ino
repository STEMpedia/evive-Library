/*
  evive Bluetooth Setup

  An example of using the evive to Setup HC-05 Bluetooth.
  This example changes some configurations like name, baud rate, password of 
  HC-05 module.
  In order to change all this parameters it is necessary to make sure that HC-05
  is in AT mode.
  There are two ways of getting Bluetooth in ATmode:
  
  1) For getting HC-05 in AT mode press the push button on HC-05 before powering it and keep 
  it in pushed state even after powering it. If the led of bluetooth starts blinking after time 
  duration of two seconds then bluetooth is in AT mode. Release the button after that.

  2) One can also connect 5V to EN/KEY pin of HC-05 to bring it in AT mode.
  
  The LED on HC-05 starts blinking after every 
  2 seconds approx, this blink is different from the blink of led in pairing mode.  
  
  Explore more at:   https://thestempedia.com/tutorials/bluetooth-setup/

*/
#include<evive.h>
bool response = 0;
String response_data = "";
void setup() {
  // initialize Serial3 communication of bluetooth which is on Serial3 3:
  // bluetooth setup is done at 38400 baud with New line and Carriage Return
  Serial3.begin(38400);              //Baud for communication in ATmode
  Serial.begin(250000);
  // initialize the LED pin as an output:
  pinMode(LED_BUILTIN, OUTPUT);
  while (!(response))
  {
    Serial3.print("AT+ADDR\r\n");
    response_data = Serial3.readString();
    if (response_data != '\0')                
    {
    Serial.println("AT+ADDR");
    Serial.println(response_data);
    response++;
    }
  }
  response = 0;
  while (!(response))
  {
    Serial3.print("AT+UART=115200,0,0\r\n");
    response_data = Serial3.readString();
    if (response_data == "OK\r\n")
    {
     Serial.println("AT+UART=115200,0,0");
     Serial.println(response_data);
     response++;
    }
  }
  response = 0;
  while (!(response))
  {
    Serial3.print("AT+NAME=evive\r\n");
    response_data = Serial3.readString();
    if (response_data == "OK\r\n")
     {
      Serial.println("AT+NAME=evive");
      Serial.println(response_data);
      response++;
     }
  }
  response = 0;
  while (!(response))
  {
    Serial3.print("AT+PSWD=\"0000\"\r\n");
    response_data = Serial3.readString();
    if (response_data == "OK\r\n")
    {
      Serial.println("AT+PSWD=\"0000\"");
      Serial.println(response_data);
      response++;
    }
  }
  response = 0;
  //To initialize pairing mode of HC-05
  Serial3.print("AT+INIT\r\n");     //when HC-05 responds to this command sucessfully the led on HC-05 starts blinking in speed suggesting that bluetooth is in pairing mode.
  Serial.println("AT+INIT");
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {

  // put your main code here, to run repeatedly:

}
