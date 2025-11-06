#ifndef __PONT_AND_DISP__
#define __PONT_AND_DISP__
#include "config.h"

#define POTENTIOMETER_PIN 3

enum TimeLevel {
  T_0 = 6 * THOUSAND,
  T_1 = 5 * THOUSAND,
  T_2 = 4 * THOUSAND,
  T_3 = 3 * THOUSAND,
  T_4 = 2 * THOUSAND
};

int getPotLev();
void writeText(char* str);

#endif