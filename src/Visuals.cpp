#include "Visuals.h"
#include <iostream>

// how to insert a proper sf::RenderWindow window in here?

bool Visuals::loadTexture()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-bold.ttf"))
  {
    std::cout << "Error loading font";
    return false;
  }
  game_object.initialiseSprite(
    ball_texture, "Data/Images/ball.png");
  game_object.initialiseSprite(
    paddle_texture, "Data/Images/paddleBlue.png");
  game_object.initialiseSprite(
    brick_texture, "Data/Images/element_grey_rectangle.png");

  return true;
}

bool Visuals::initialise(sf::RenderWindow& window, GameState& menu)
{
  loadTexture();

  menu.State = menu.MAIN_MENU;

  main_text.setString("Press Enter to play Breakout");
  main_text.setFont(font);
  main_text.setCharacterSize(65);
  main_text.setFillColor(sf::Color::White);
  main_text.setPosition(
    (window.getSize().x / 2) - (main_text.getGlobalBounds().width / 2),
    (window.getSize().y / 2) - (main_text.getGlobalBounds().height / 2));

  ball.setTexture(ball_texture);
  paddle.setTexture(paddle_texture);
  brick.setTexture(brick_texture);

  ball.setScale(0.3,0.3);
  ball.setPosition(
    (window.getSize().x / 2) - (ball.getGlobalBounds().width / 2),
    window.getSize().y - (ball.getGlobalBounds().height + paddle.getGlobalBounds().height));

  paddle.setPosition(
    (window.getSize().x / 2) - (paddle.getGlobalBounds().width / 2),
    window.getSize().y - paddle.getGlobalBounds().height);

  return true;
}

void Visuals::switchState(sf::RenderWindow& window, GameState& menu)
{
  switch (menu.State)
  {
    case (1):
    {
      window.draw(main_text);
      break;
    }
    case (2):
    {
      window.draw(ball);
      window.draw(paddle);
      break;
    }
    case (3):
    {
      break;
    }
    default:
      window.draw(main_text);
      break;
  }
}
