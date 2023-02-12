#include "Collision.h"

void Collision::paddleWindowCheck(sf::RenderWindow& window, GameObject& object)
{
  if (object.getSprite()->getPosition().x < 0)
  {
    object.getSprite()->setPosition(0,
                                    object.getSprite()->getPosition().y);
  }
  if (object.getSprite()->getPosition().x >
      (window.getSize().x - object.getSprite()->getGlobalBounds().width))
  {
    object.getSprite()->setPosition(
      window.getSize().x - object.getSprite()->getGlobalBounds().width,
      object.getSprite()->getPosition().y);
  }
}

void Collision::ballWindowCheck(sf::RenderWindow& window, GameObject object)
{

}