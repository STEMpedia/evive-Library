/*
  High power circuit switching

  Turns on and off a AC bulb connected on relay
  with help of SlideSwitch 1 on evive.

  Depeding upon which SlideSwitch and which part of Slide switch 
  is to be used keywords for pins connected to slide switch are:
  SLIDESW1_D1  Slide Switch 1 (Up direction pin 40)
  SLIDESW1_D2  Slide Switch 1 (Down direction pin 41)
  SLIDESW2_D1  Slide Switch 2 (UP direction pin 42)
  SLIDESW2_D2  Slide Switch 2 (Down direction pin 43)
  
  Explore more on: https://thestempedia.com/tutorials/interfacing-relay-with-evive/
  
*/
#include <evive.h>
#define relay 2
int state = 0;         // variable for reading the pushbutton status
void setup() {
  // put your setup code here, to run once:
  // initialize the relay pin as an output:
  pinMode(relay, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(SLIDESW1_D1, INPUT);
 
}

void loop() {
  // read the state of the pushbutton value:
  state = digitalRead(SLIDESW1_D1);
  
  // check if the pushbutton is pressed.
  // if it is, the state is HIGH:
  if (state == HIGH) {
    // turn relay on:
    digitalWrite(relay, LOW);
  } else {
    // turn relay off:
    digitalWrite(relay, HIGH);
  }
}
