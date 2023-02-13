#ifndef BREAKOUTSFML_COLLISION_H
#define BREAKOUTSFML_COLLISION_H
#include "Visuals.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Collision
{
 public:
  Collision();
  ~Collision();
  void paddleWindowCheck(sf::RenderWindow& window, GameObject& object);
  void ballWindowCheck(sf::RenderWindow& window, GameObject& object,
                       GameObject& object2);
  void brickBallCheck(GameObject& brick, GameObject& ball);
};

#endif // BREAKOUTSFML_COLLISION_H
