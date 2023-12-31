#ifndef BREAKOUTSFML_PLAYERCONTROLLER_H
#define BREAKOUTSFML_PLAYERCONTROLLER_H
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class PlayerController
{
 public:
  PlayerController();
  ~PlayerController();
  void paddleMove(sf::Event& event);
  void paddleStop(sf::Event& event);
  float paddle_spd = 0;
 private:
  float paddle_spd_multiplier = 1;
};

#endif // BREAKOUTSFML_PLAYERCONTROLLER_H
