/*
  Arduino Mouse Jiggler

  For Leonardo and Due boards only.
*/

#include "Mouse.h"

int distance = 200;           // number of pixels the mouse travels
unsigned long strokeDelay = 500;        // delay of the mouse (in ms) after each stroke
unsigned long jiggleInterval = 60000;    // interval between the jiggle (set of strokes) in ms

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  // initialize mouse control:
  Mouse.begin();
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second before starting the jiggle
  
  Mouse.move(distance, 0, 0);
  delay(strokeDelay);
  Mouse.move(0, distance, 0);
  delay(strokeDelay);
  Mouse.move(-distance, 0, 0);
  delay(strokeDelay);
  Mouse.move(0, -distance, 0);
  delay(strokeDelay);
  
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW

  // Mouse jiggle happens every {jiggleInterval}/1000 second
  delay(jiggleInterval);
}
