#include "Visuals.h"
#include <iostream>

Visuals::Visuals(sf::RenderWindow& game_window) : window(game_window)
{
  ;
}

bool Visuals::initialise()
{
  std::cout << "entering initialise()" << std::endl;
  menu.State = menu.MAIN_MENU;
  if (!font.loadFromFile("Data/Fonts/OpenSans-bold.ttf"))
  {
    std::cout << "Error loading font";
    return false;
  }
  mainText.setString("Press Enter to play Breakout");
  mainText.setFont(font);
  mainText.setCharacterSize(65);
  mainText.setFillColor(sf::Color::White);
  mainText.setPosition(
    (window.getSize().x / 2) - (mainText.getGlobalBounds().width / 2),
    (window.getSize().y / 2) - (mainText.getGlobalBounds().height / 2));
  std::cout << "text initialised";

  return true;
}

void Visuals::stateSwitch()
{
  switch (menu.State)
  {
    case (1):
    {
      return window.draw(mainText);
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
      return window.draw(mainText);
  }
}
