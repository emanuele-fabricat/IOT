#ifndef __LAMPS__
#define __LAMPS__

#define RED_LED_PIN 3

extern int lampsPin[];

void setLedOn(int i);
void ledsOff();
void redPulsingOn();
void redOn();
void redOff();

#endif