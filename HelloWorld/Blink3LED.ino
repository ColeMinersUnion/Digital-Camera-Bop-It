//Edited by Cole Hansen on 03/17/2025

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
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define BUTTON_PIN 9

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

// the loop function runs over and over again forever
void loop() {
  if (digitalRead(BUTTON_PIN)==HIGH) {
    digitalWrite(LED_1, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(500);                   // wait for a second
    digitalWrite(LED_1, LOW);   // turn the LED off by making the voltage LOW
    delay(500);
    digitalWrite(LED_2, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(500);                   // wait for a second
    digitalWrite(LED_2, LOW);   // turn the LED off by making the voltage LOW
    delay(500);
    digitalWrite(LED_3, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(500);                   // wait for a second
    digitalWrite(LED_3, LOW);   // turn the LED off by making the voltage LOW
    delay(500);
  } else {
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
  }
  // wait for a second
}
