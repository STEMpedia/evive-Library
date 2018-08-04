/*
  Control an LED on Pin 13 with Button 

  Turns ON and OFF a On-Board light emitting diode(LED)
  when pressing pushbutton on evive.

  
  Modified 9 Sep 2017
  by Nihar Shah.

  Explore more on: https://thestempedia.com/tutorials/evive-digital-input-2/
  
  
*/

#include <evive.h>                // include evive library

//Following are called Macros. They are just nicknames. And for Tactile switches on evive nicknames are already avialable.
#define led 13                    // Wherever led will be used in sketch, it will be replaced with 13

//Use macro TACTILESW1 for tactile switch 1.
//Use macro TACTILESW2 for tactile switch 2.


//There are different types of variables like integer (..-1,0,1,2..), boolean (1 OR 0),
//character (a, b,...!,@..), float (-1.12,...0..., 100.21..), etc.
//Explore more here: https://thestempedia.com/tutorials/arduino-variable/
//Bool can either take 1 (High or True) OR 0 (Low or False). A Push button can be either be High or Low.
bool state = 0;                   // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(led, OUTPUT);          //Initialize LED pin as output (led = 13)
  pinMode(TACTILESW1, INPUT);       // initialize the pushbutton pin as an input
}

void loop() {
  // read the state of the pushbutton value:
  state = digitalRead(TACTILESW1);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (state == HIGH) {
    digitalWrite(led, HIGH);      // turn LED on:
  } 
  else {
    digitalWrite(led, LOW);       // turn LED off:
  }
}
