#ifndef __LAMPS__
#define __LAMPS__

#define RED_LED_PIN 8

extern int lampsPin[];

void setLedOn(int i);
void ledsOff();
void setRedOn(int i);
void redPulsingOn();
void redPulsingOff();
void redOn();
void redOff();

#endif