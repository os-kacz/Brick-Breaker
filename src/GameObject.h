#ifndef BREAKOUTSFML_GAMEOBJECT_H
#define BREAKOUTSFML_GAMEOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();
  bool visible = true;
  bool attached = true;
  int lives;
  Vector2 direction = Vector2(0, 0);
  void getBoundingBox();
  float top_l_x;
  float top_r_x;
  float top_l_y;
  float bot_l_y;
  enum
  {
    BRICK = 1,
    GEM = 2,
    PADDLE = 3,
  } type;
private:
  sf::Sprite* sprite = nullptr;

};


#endif // BREAKOUTSFML_GAMEOBJECT_H
