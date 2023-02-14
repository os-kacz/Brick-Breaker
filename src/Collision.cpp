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
    object.attached = true;
    object.lives -= 1;
    object.getSprite()->setPosition(
      (object2.getSprite()->getPosition().x) +
        (object2.getSprite()->getGlobalBounds().width/2),
      window.getSize().y -
        (object.getSprite()->getGlobalBounds().height +
         object.getSprite()->getGlobalBounds().height));
  }
}

void Collision::gameObjectCheck(GameObject& affector, GameObject& affected)
{
  affector.getBoundingBox();
  affected.getBoundingBox();
  // affector bottom right intersect affected top left
  if (affector.top_r_x > affected.top_l_x
      && affector.top_r_x < affected.top_r_x
      && affector.bot_l_y > affected.top_l_y
      && affector.bot_l_y < affected.bot_l_y)
  {
    if (affected.brick)
    {
      affected.visible = false;
    }
    if ((affector.top_r_x - affected.top_l_x) > (affector.bot_l_y - affected.top_l_y))
    {
      affector.direction.y *= -1;
    }
    else
    {
      affector.direction.x *= -1;
    }
  }
  // affector bottom left intersect affected top right
  else if (affector.top_l_x > affected.top_l_x
      && affector.top_l_x < affected.top_r_x
      && affector.bot_l_y > affected.top_l_y
      && affector.bot_l_y < affected.bot_l_y)
  {
    if (affected.brick)
    {
      affected.visible = false;
    }
    if ((affector.top_l_x - affected.top_r_x) > (affector.bot_l_y - affected.top_l_y))
    {
      affector.direction.y *= -1;
    }
    else
    {
      affector.direction.x *= -1;
    }
  }
  // affector top right intersect affected bottom left
  else if (affector.top_r_x > affected.top_l_x
      && affector.top_r_x < affected.top_r_x
      && affector.top_l_y > affected.top_l_y
      && affector.top_l_y < affected.bot_l_y)
  {
    if (affected.brick)
    {
      affected.visible = false;
    }
    if ((affector.top_r_x - affected.top_l_x) > (affector.top_l_y - affected.bot_l_y))
    {
      affector.direction.y *= -1;
    }
    else
    {
      affector.direction.x *= -1;
    }
  }
  else if (affector.top_l_x > affected.top_l_x
      && affector.top_l_x < affected.top_r_x
      && affector.top_l_y > affected.top_l_y
      && affector.top_l_y < affected.bot_l_y)
  {
    if (affected.brick)
    {
      affected.visible = false;
    }
    if ((affector.top_r_x - affected.top_r_x) > (affector.top_l_y - affected.bot_l_y))
    {
      affector.direction.y *= -1;
    }
    else
    {
      affector.direction.x *= -1;
    }
  }
}