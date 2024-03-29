/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Blink
*/

#include "Keyboard.h"


#define AUDIO_IN_PIN      7
//int AUDIO_IN_PIN      7
int db_val = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(AUDIO_IN_PIN, INPUT);
    Serial.begin(19200);
  // initialize control over the keyboard:
  Keyboard.begin();

}

// the loop function runs over and over again forever
void loop() {
  db_val    =  digitalRead(AUDIO_IN_PIN);  // Analog Digital converter value
  if (db_val == HIGH)
  {
    digitalWrite(LED_BUILTIN, HIGH);
      Serial.write("Switching ON");
      Keyboard.press(KEY_ARROW_DOWN);
      Keyboard.release(KEY_ARROW_DOWN);
      delay(100);
      Keyboard.write("KEY_ARROW_DOWN")

  }
  else
  {
  
    digitalWrite(LED_BUILTIN, LOW);
      Serial.write("Switching OFF");
    while (db_val != HIGH)
    {
      //Serial.write(" OFF");

      db_val    =  digitalRead(AUDIO_IN_PIN);  // Analog Digital converter value
    }

  }
      //delay(100);

 }
