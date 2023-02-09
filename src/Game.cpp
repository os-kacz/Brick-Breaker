#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window) : window(game_window), player(player.paddle)
{
  srand(time(NULL));
  game_object_speed = 10;
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
  if (menu.State == menu.PLAY_GAME)
  {
    player.paddle.getSprite()->move(
      player.paddle_speed_multiplier * game_object_speed,0);
  }
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