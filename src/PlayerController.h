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
  float paddle_speed;
};

#endif // BREAKOUTSFML_PLAYERCONTROLLER_H
