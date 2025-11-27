#include <Arduino.h>
#include "analogDevices.h"
#include "config.h"
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,20,4);

PotentiometerLevel getPotentiometerLv() {
  if (analogRead(POTENTIOMETER_PIN) == 0) {
    return P_L_0;
  } else if (analogRead(POTENTIOMETER_PIN) > 0 && analogRead(POTENTIOMETER_PIN) <= 341) {
    return P_L_1;
  } else if (analogRead(POTENTIOMETER_PIN) > 341 && analogRead(POTENTIOMETER_PIN) <= 682) {
    return P_L_2;
  } else if (analogRead(POTENTIOMETER_PIN) > 682 && analogRead(POTENTIOMETER_PIN) < 1022) {
    return P_L_3;
  } else {
    return P_L_4;
  }
}

void writeText(const char* str) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(str);
}

void printScore() {
  String text = "Score ";
  text += String(score);
  writeText(text.c_str());
}
