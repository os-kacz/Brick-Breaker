#include "Visuals.h"
#include <iostream>

bool Visuals::initialise(sf::RenderWindow& window, GameState& menu)
{
  if (!font.loadFromFile("Data/Fonts/OpenSans-bold.ttf"))
  {
    std::cout << "Error loading font";
    return false;
  }
  if (!ball_texture.loadFromFile("Data/Images/ball.png"))
  {
    std::cout << "Error loading ball texture";
    return false;
  }
  if (!paddle_texture.loadFromFile("Data/Images/paddleBlue.png"))
  {
    std::cout << "Error loading paddle texture";
    return false;
  }
  if (!brick_texture.loadFromFile("Data/Images/element_grey_rectangle.png"))
  {
    std::cout << "Error loading brick texture";
    return false;
  }

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

  level.spawn();

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
      ;
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
