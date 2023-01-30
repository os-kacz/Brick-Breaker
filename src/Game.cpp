
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  menu.State = menu.MAIN_MENU;
  if (!font.loadFromFile("Data/Fonts/OpenSans-bold.ttf"))
  {
    std::cout << "Error loading font";
    return false;
  }
  main_menu.setString("Press Enter to play Breakout");
  main_menu.setFont(font);
  main_menu.setCharacterSize(65);
  main_menu.setFillColor(sf::Color::White);
  main_menu.setPosition(
    (window.getSize().x / 2) - (main_menu.getGlobalBounds().width / 2),
    (window.getSize().y / 2) - (main_menu.getGlobalBounds().height / 2));

  return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
 switch (menu.State)
  {
    case (1):
    {
      window.draw(main_menu);
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
      window.draw(main_menu);
      break;
  }
}

void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Enter && menu.State == menu.MAIN_MENU)
  {
    menu.State = menu.PLAY_GAME;
  }
}

void Game::keyReleased(sf::Event event)
{

}