#include "phases.h"
#include <Arduino.h>
#include "config.h"
#include "buttonsFun.h"
#include "lamps.h"
#include "pontAndDisp.h"



void wakeUp() {
  /*controllo tempo nel caso andare in sleep phase*/
  redPulsingOn();
  if (buttonsPress[0]) {
    phase = STARTING_GAME;
  }
}

void setLV() {
  switch (getPotLev()) {
    case INIT:
      t1 = T_0;
      break;
    case LV_1:
      t1 = T_1;
      break;
    case LV_2:
      t1 = T_2;
      break;
    case LV_3:
      t1 = T_3;
      break;
    case LV_4:
      t1 = T_4;
      break;
    default:
      break;   
  }
  writeText("GO!");
  delay(THOUSAND);
  phase = MEMORIZATION;
}

void resetStatus() {
  number = 0;
  resetButtons();
  ledsOff();

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
  writeText(text.c_str());
  delay(2 * THOUSAND);
  phase = DIGITATION;
  resetStatus();
  //prendere il tempo
  writeText("indovina");
}

void printScore() {
  String text = "Score ";
  text += String(score);
  writeText(text.c_str());
}

void attempt() {
  /*esci se superato il tempo*/
  bool right = true;
  for (int i = 0; i < 4; i ++) {
    if (buttonsPress[i]) {
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
        writeText("wrong");
        resetStatus();
      }
    } else if (number == 4 && right) {
      score ++;
      phase = MEMORIZATION;
      printScore();
      right = false;
    }
  }
}

void lose() {
  redOn();
  printScore();
  delay(2 * THOUSAND);
  writeText("Game Over");
  delay(2 * THOUSAND);
  phase = SLEEP;
}

void sleep() {
  /*
  mettere in sleep
  */
}

void playPhase(int i) {
  switch (i) {
    case WAKE_UP:
      wakeUp();
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