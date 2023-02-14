#include "Collision.h"

Collision::Collision()
{

}

Collision::~Collision()
{

}

void Collision::paddleWindowCheck(sf::RenderWindow& window, GameObject& object)
{
  if (object.getSprite()->getPosition().x < 0)
  {
    object.getSprite()->setPosition(
      0,object.getSprite()->getPosition().y);
  }
  if (object.getSprite()->getPosition().x >
      (window.getSize().x - object.getSprite()->getGlobalBounds().width))
  {
    object.getSprite()->setPosition(
      window.getSize().x - object.getSprite()->getGlobalBounds().width,
      object.getSprite()->getPosition().y);
  }
}

void Collision::ballWindowCheck(sf::RenderWindow& window, GameObject& object,
                                GameObject& object2)
{
  if (object.getSprite()->getPosition().x < 0 ||
      object.getSprite()->getPosition().x
        > (window.getSize().x - object.getSprite()->getGlobalBounds().width))
  {
    object.direction.x *= -1;
  }
  if (object.getSprite()->getPosition().y < 0)
  {
    object.direction.y *= -1;
  }
  if (object.getSprite()->getPosition().y
      > (window.getSize().y + object.getSprite()->getGlobalBounds().height))
  {
    object.direction.y *= -1;
    object.getSprite()->setPosition(
      (object2.getSprite()->getPosition().x) +
        (object2.getSprite()->getGlobalBounds().width/2),
      window.getSize().y -
        (object.getSprite()->getGlobalBounds().height +
         object.getSprite()->getGlobalBounds().height));
  }
}

void Collision::brickBallCheck(GameObject& brick, GameObject& ball)
{
}