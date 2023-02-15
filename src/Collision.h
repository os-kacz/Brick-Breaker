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
  //void getBoundingBox(GameObject& object);
  void paddleWindowCheck(sf::RenderWindow& window, GameObject& object);
  void ballWindowCheck(sf::RenderWindow& window, GameObject& object,
                       GameObject& object2);
  void gameObjectCheck(GameObject& affector, GameObject& affected);
  int score;
 private:
  bool collision_detected;
};

#endif // BREAKOUTSFML_COLLISION_H
