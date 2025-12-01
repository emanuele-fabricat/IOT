#include "phases.h"
#include <Arduino.h>
#include <avr/sleep.h>
#include "config.h"
#include "buttonsFun.h"
#include "lamps.h"
#include "analogDevices.h"
#include "serviceFunction.h"
#include "interrupts.h"

#define SLEEPING_SECONDS 2
#define GOOD_NIGHT_SECONDS 2
#define MEMORIZING_SECONDS 2
#define INCREMENT_OF_F 0.5
#define GAME_OVER_SECONDS 2
#define SCORE_SECONDS 2

void start() {
  if (timePass() < SLEEPING_SECONDS * ONE_SECOND) {
    redPulsingOn();
    if (buttonsPress[0]) {
      phase = STARTING_GAME;
    }
  } else {
    phase = SLEEP;
    writeText("GOOD NIGHT", FIRST_ROW);
    delay(GOOD_NIGHT_SECONDS * ONE_SECOND);
  }
}

void setLV() {
  PotentiometerLevel pLv = getPotentiometerLv();
  switch (pLv) {
    case P_L_0:
      t1 = INIT;
      break;
    case P_L_1:
      t1 = T_1;
      break;
    case P_L_2:
      t1 = T_2;
      break;
    case P_L_3:
      t1 = T_3;
      break;
    case P_L_4:
      t1 = T_4;
      break;
    default:
      break;   
  }
  writeText("GO!", FIRST_ROW);
  delay(ONE_SECOND);
  phase = MEMORIZATION;
}


void extractNumber() {
  String text = "";
  for (int i = 0; i < 4;) {
    bool duplicate = false;
    int num = random(1, 5);
    for (int j = 0; j < i ; j ++) {
      if (solution[j] == num) {
        duplicate = true;
      }
    }
    if (!duplicate) {
      solution[i] = num;
      i ++;
    }
  }
  for (int i = 0; i < 4; i ++) {
    text += String(solution[i]);
  }
  writeText(text.c_str(), FIRST_ROW);
  delay(MEMORIZING_SECONDS * ONE_SECOND);
  phase = DIGITATION;
  resetStatus();
  writeText("indovina", FIRST_ROW);
  takeTime();
}

void attempt() {
  if (timePass()  < t1-f){
    bool right = true;
    bool actualState[4] = {};
    for (int i = 0; i < 4; i ++) {
      actualState[i] = buttonsPress[i];
    }
    for (int i = 0; i < 4; i ++) {
      if (actualState[i]) {
        setLedOn(i);
        bool next = true;
        for (int j = 0; j < number && next; j ++) {
          next = guess[j] != i + 1;
        }
        if (next) {
          guess[number] = i + 1;
          number ++; 
        }
      }
    }
    for (int i = 0; i < number && right; i ++) {
      if (solution[i] != guess[i]) {
        resetStatus();
        right = false;
        if (number == 4) {
          writeText("wrong", FIRST_ROW);
          resetStatus();
        }
      } else if (number == 4 && right) {
        score ++;
        f = f + INCREMENT_OF_F * ONE_SECOND;
        phase = MEMORIZATION;
        printScore();
        delay(SCORE_SECONDS * ONE_SECOND);
        right = false;
      }
    }
  } else {
    phase = GAME_OVER;
  }
}

void lose() {
  redOn();
  writeText("Game Over", FIRST_ROW);
  delay(GAME_OVER_SECONDS * ONE_SECOND);
  printScore();
  delay(SCORE_SECONDS * ONE_SECOND);
  phase = SLEEP;
  redOff();
  writeText("GOOD NIGHT", FIRST_ROW);
  delay(GOOD_NIGHT_SECONDS * ONE_SECOND);
}

void sleep() {
  writeText("", FIRST_ROW);
  lcd.noBacklight();
  ledsOff();
  sleepingInterrupts();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);  
  sleep_enable();
  sleep_mode();  
  sleep_disable(); 
  turningOnInterrupts();
  phase = WAKE_UP;
  lcd.backlight();
  resetStatus();
  writeText("Welcome to TOS!", FIRST_ROW);
  writeText("Press B1 to Start", SECOND_ROW);
  f = 0;
  score = 0;
  takeTime();
}

void playPhase(int i) {
  switch (i) {
    case WAKE_UP:
      start();
      break;
    case STARTING_GAME:
      setLV();
      break;
    case MEMORIZATION:
      extractNumber();
      break;
    case DIGITATION:
      attempt();
      break;
    case GAME_OVER:
      lose();
      break;
    case SLEEP:
      sleep();
      break;
    default:
      break;
  }
}
