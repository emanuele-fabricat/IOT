#include "buttonsFun.h"
#include "phases.h"
#include "analogDevices.h"
#include "lamps.h"
#include "config.h"
#include "serviceFunction.h"
#include <EnableInterrupt.h>

void setup() {
  LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27,20,4);
  lcd.init();
  lcd.backlight();
  lcd.print("Welcome to TOS! Press B1 to Start");
  for (int i = 0; i < 4; i++) {
    pinMode(lampsPin[i], OUTPUT);
  }
  enableInterrupt(BUTTON_1, button1Fun,RISING);
  enableInterrupt(BUTTON_2, button2Fun,RISING);
  enableInterrupt(BUTTON_3, button3Fun,RISING);
  enableInterrupt(BUTTON_4, button4Fun,RISING);
  pinMode(RED_LED_PIN, OUTPUT);
  Serial.begin(9600);
  int t1 = INIT;
  phase = WAKE_UP;
  takeTime();
}

void loop() {
  playPhase(phase);
}
