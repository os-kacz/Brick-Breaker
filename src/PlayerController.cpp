#include "PlayerController.h"

void PlayerController::paddleMove(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A)
  {
    paddle.getSprite()->move(-10,0);
  }
  if (event.key.code == sf::Keyboard::D)
  {
    paddle.getSprite()->move(10,0);
  }
}