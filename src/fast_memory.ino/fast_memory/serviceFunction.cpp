#include "serviceFunction.h"
#include <Arduino.h>
#include "config.h"
#include "buttonsFun.h"
#include "lamps.h"


void resetStatus() {
  number = 0;
  resetButtons();
  ledsOff();
}

void takeTime() {
    startTime = millis();
}

unsigned long timePass() {
    return startTime-millis();
}
