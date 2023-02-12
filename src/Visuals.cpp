#include "Visuals.h"
#include <iostream>

// how to properly implement "sf::RenderWindow window" and "GameState menu" in this class?

Visuals::Visuals()
{
  ;
}

Visuals::~Visuals()
{
  ;
}

bool Visuals::loadTexture()
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-bold.ttf"))
  {
    std::cout << "Error loading font";
    return false;
  }
  ball.initialiseSprite(
    ball_texture, "Data/Images/ball.png");
  paddle.initialiseSprite(
    paddle_texture, "Data/Images/paddleBlue.png");
  brick.initialiseSprite(
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

  ball.getSprite()->setScale(0.2,0.2);
  ball.getSprite()->setPosition(
    (window.getSize().x / 2) - (ball.getSprite()->getGlobalBounds().width / 2),
    window.getSize().y - (ball.getSprite()->getGlobalBounds().height + paddle.getSprite()->getGlobalBounds().height));

  paddle.getSprite()->setPosition(
    (window.getSize().x / 2) - (paddle.getSprite()->getGlobalBounds().width / 2),
    window.getSize().y - paddle.getSprite()->getGlobalBounds().height);

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
      window.draw(*ball.getSprite());
      window.draw(*paddle.getSprite());
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
