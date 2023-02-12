#include "PlayerController.h"

PlayerController::PlayerController()
{
  paddle_speed = 0;
}

PlayerController::~PlayerController()
{

}

void PlayerController::paddleMove(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A)
  {
    paddle_speed = -10;
  }
  if (event.key.code == sf::Keyboard::D)
  {
    paddle_speed = 10;
  }
}

void PlayerController::paddleStop(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A && paddle_speed != 10)
  {
    paddle_speed = 0;
  }
  if (event.key.code == sf::Keyboard::D && paddle_speed != -10)
  {
    paddle_speed = 0;
  }
}