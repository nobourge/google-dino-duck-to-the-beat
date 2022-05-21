
// #include "Keyboard.h" // not in arduino r3


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
