#ifndef BREAKOUTSFML_PLAYERCONTROLLER_H
#define BREAKOUTSFML_PLAYERCONTROLLER_H
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class PlayerController
{
 public:
  PlayerController(GameObject& paddle);
  ~PlayerController();
  void paddleMove(sf::Event& event);
  GameObject& paddle;
  float paddle_speed_multiplier;
};

#endif // BREAKOUTSFML_PLAYERCONTROLLER_H
