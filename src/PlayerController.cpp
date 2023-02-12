#include "PlayerController.h"

PlayerController::PlayerController()
{

}

PlayerController::~PlayerController()
{

}

void PlayerController::paddleMove(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A)
  {
    paddle_spd = -1;
  }
  if (event.key.code == sf::Keyboard::D)
  {
    paddle_spd = 1;
  }
  paddle_spd *= paddle_spd_multiplier;
}

void PlayerController::paddleStop(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A && paddle_spd != paddle_spd_multiplier)
  {
    paddle_spd = 0;
  }
  if (event.key.code == sf::Keyboard::D && paddle_spd != (paddle_spd_multiplier*-1))
  {
    paddle_spd = 0;
  }
}