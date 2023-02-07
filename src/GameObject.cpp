#include "GameObject.h"

GameObject::GameObject()
{
  ;
}

GameObject::~GameObject()
{
  ;
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename)){
    std::cout << "Error loading from" << filename << std::endl;
    return false;
  }
}

sf::Sprite& getSprite()
{
  // unsure how this function is intended to be defined or used
}