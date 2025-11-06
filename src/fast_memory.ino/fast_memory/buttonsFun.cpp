#include "config.h"
#include "buttonsFun.h"
#include "lamps.h"
#include <Arduino.h>

int buttonsPin[] = {2, 3, 4, 5};
bool buttonsPress[] = {false, false, false, false};

void button1Fun() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(lampsPin[i], HIGH);
    Serial.print(i);
  }
}