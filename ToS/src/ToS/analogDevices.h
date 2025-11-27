#ifndef __ANALOG_DEVICES__
#define __ANALOG_DEVICES__
#include "config.h"
#include <LiquidCrystal_I2C.h> 

#define POTENTIOMETER_PIN A2

extern LiquidCrystal_I2C lcd;

enum PotentiometerLevel {
  P_L_0 = 0,
  P_L_1 = 1,
  P_L_2 = 2,
  P_L_3 = 3,
  P_L_4 = 4,
};

PotentiometerLevel getPotentiometerLv();
void writeText(const char* str);
void printScore();

#endif
