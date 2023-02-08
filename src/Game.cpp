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
  make_visual.initialise(window, menu);
}

void Game::update(float dt)
{

}

void Game::render()
{
  make_visual.switchState(window, menu);
}

void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Enter && menu.State == menu.MAIN_MENU)
  {
    menu.State = menu.PLAY_GAME;
  }
  if (menu.State == menu.PLAY_GAME)
  {
    player.paddleMove(event);
  }
}

void Game::keyReleased(sf::Event event)
{

}