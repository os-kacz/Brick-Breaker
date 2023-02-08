#ifndef BREAKOUTSFML_PLAYERCONTROLLER_H
#define BREAKOUTSFML_PLAYERCONTROLLER_H
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class PlayerController
{
 public:
  void paddleMove(sf::Event& event);
  GameObject& paddle;
};

#endif // BREAKOUTSFML_PLAYERCONTROLLER_H
