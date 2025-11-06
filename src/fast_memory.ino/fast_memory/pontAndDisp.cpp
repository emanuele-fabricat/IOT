#include <Arduino.h>
#include "pontAndDisp.h"
#include "config.h"

int getPotLev();
void writeText(char* str) {
  Serial.print(str);
};