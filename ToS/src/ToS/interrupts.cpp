#include <Arduino.h>
#include <EnableInterrupt.h>
#include "interrupts.h"
#include "buttonsFun.h"

void inGameInterrupts(){
    enableInterrupt(BUTTON_1, button1Fun, RISING);
    enableInterrupt(BUTTON_2, button2Fun, RISING);
    enableInterrupt(BUTTON_3, button3Fun, RISING);
    enableInterrupt(BUTTON_4, button4Fun, RISING);
}

void wakeUp(){}

void sleepingInterrupts(){
    disableInterrupt(BUTTON_1);
    enableInterrupt(BUTTON_1, wakeUp, RISING);
}

void turningOnInterrupts(){
    disableInterrupt(BUTTON_1);
    enableInterrupt(BUTTON_1, button1Fun, RISING);
}
