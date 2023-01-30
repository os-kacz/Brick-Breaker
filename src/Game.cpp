#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  makeVisual.initialise();
}

void Game::update(float dt)
{

}

void Game::render()
{
  makeVisual.stateSwitch();
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