#include "PlayerController.h"

PlayerController::PlayerController(GameObject& paddle) : paddle(paddle)
{
  paddle_speed_multiplier = 3;
}

PlayerController::~PlayerController()
{

}

void PlayerController::paddleMove(sf::Event& event)
{
  if (event.key.code == sf::Keyboard::A)
  {
    paddle_speed_multiplier * -1;
  }
  if (event.key.code == sf::Keyboard::D)
  {
    paddle_speed_multiplier * 1;
  }
}