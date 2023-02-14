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
  bool getBoundingBox();
  bool visible = true;
  Vector2 direction = Vector2(0, 0);
private:
  sf::Sprite* sprite = nullptr;
  float bounding_box[1][1];

};


#endif // BREAKOUTSFML_GAMEOBJECT_H
