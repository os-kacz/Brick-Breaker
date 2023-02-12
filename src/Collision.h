#ifndef BREAKOUTSFML_COLLISION_H
#define BREAKOUTSFML_COLLISION_H
#include "Visuals.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Collision
{
 public:
  void paddleWindowCheck(sf::RenderWindow& window, GameObject& object);
  void ballWindowCheck(sf::RenderWindow& window, GameObject object);
};

#endif // BREAKOUTSFML_COLLISION_H
