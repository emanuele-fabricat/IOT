#include <Arduino.h>
#include "Scheduler.h"
#include "actuators/RedLed.h"

void setup() {
}

void loop() {
    RedLed* led = new RedLed();
    led->test();
}
