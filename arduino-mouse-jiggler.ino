/*
  Arduino Mouse Jiggler

  For Leonardo and Due boards only.
*/

#include "Mouse.h"

int distance = 200;           // number of pixels the mouse travels
int strokeDelay = 500;        // delay of the mouse (in ms) after each stroke
int jiggleInterval = 1000;    // interval between the jiggle (set of strokes) in ms

void setup() {
  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  Mouse.move(distance, 0, 0);
  delay(strokeDelay);
  Mouse.move(0, distance, 0);
  delay(strokeDelay);
  Mouse.move(-distance, 0, 0);
  delay(strokeDelay);
  Mouse.move(0, -distance, 0);
  delay(strokeDelay);

  // Mouse jiggle happens every {jiggleInterval}/1000 second
  delay(jiggleInterval);
}
