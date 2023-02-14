#include "GameObject.h"

GameObject::GameObject()
{
  sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
  if (sprite != nullptr)
  {
    delete sprite;
    sprite = nullptr;
  }
}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
  if (!texture.loadFromFile(filename)){
    std::cout << "Error loading from" << filename << std::endl;
    return false;
  }
  sprite->setTexture(texture);
  return true;
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

bool GameObject::getBoundingBox()
{

}