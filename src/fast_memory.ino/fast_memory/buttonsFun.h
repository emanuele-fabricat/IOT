#ifndef __BUTTONS_FUN__
#define __BUTTONS_FUN__

extern bool buttonsPress[];

enum ButtonsPin {
  BUTTON_1  = 2,
  BUTTON_2  = 3,
  BUTTON_3  = 5,
  BUTTON_4  = 7
};

void button1Fun();
void button2Fun();
void button3Fun();
void button4Fun();

#endif