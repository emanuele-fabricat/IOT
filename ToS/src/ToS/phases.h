#ifndef __PHASES__
#define __PHASES__


enum Phases {
  WAKE_UP = 0,
  STARTING_GAME = 1,
  MEMORIZATION = 2,
  DIGITATION = 3,
  GAME_OVER = 4,
  SLEEP = 5
};

void playPhase(int i);

#endif