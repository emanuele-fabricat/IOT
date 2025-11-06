#ifndef __BUTTONS_FUN__
#define __BUTTONS_FUN__

extern bool buttonsPress[];

enum ButtonsPin {
  BUTTON_1  = 10,
  BUTTON_2  = 11,
  BUTTON_3  = 12,
  BUTTON_4  = 13
};

void button1Fun();
void button2Fun();
void button3Fun();
void button4Fun();

#endif