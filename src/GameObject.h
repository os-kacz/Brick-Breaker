#ifndef BREAKOUTSFML_GAMEOBJECT_H
#define BREAKOUTSFML_GAMEOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>

class GameObject
{
 public:
  GameObject();
  ~GameObject();
  bool initialiseSprite(sf::Texture& texture, std::string filename);
  sf::Sprite* getSprite();
 private:
  sf::Sprite* sprite = nullptr;
};


#endif // BREAKOUTSFML_GAMEOBJECT_H
