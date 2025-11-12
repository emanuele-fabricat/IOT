#ifndef __LAMPS__
#define __LAMPS__

#define RED_LED_PIN 2

extern int lampsPin[];

void setLedOn(const int i);
void ledsOff();
void redPulsingOn();
void redOn();
void redOff();

#endif
