
#ifndef BREAKOUT_STATE_H
#define BREAKOUT_STATE_H

class GameState
{
 public:
  enum
  {
    MAIN_MENU = 1,
    PLAY_GAME = 2,
    QUIT_MENU = 3,
  } State;
};


#endif // BREAKOUT_STATE_H
