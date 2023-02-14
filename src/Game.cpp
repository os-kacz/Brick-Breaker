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
  visual.initialise(window, menu);
}

void Game::update(float dt)
{
  object_speed = dt * 400;
  if (menu.State == menu.PLAY_GAME)
  {
    for (auto & i:visual.brick)
    {
      if (i.visible)
      {
        collision.gameObjectCheck(visual.ball, i);
      }
    }
    collision.ballWindowCheck(window, visual.ball, visual.paddle);
    collision.gameObjectCheck(visual.ball, visual.paddle);
    collision.paddleWindowCheck(window, visual.paddle);

    visual.paddle.getSprite()->move(player.paddle_spd * object_speed,0);
    visual.ball.getSprite()->move(
      visual.ball.direction.x * object_speed,visual.ball.direction.y * object_speed);
  }
}

void Game::render()
{
  visual.switchState(window, menu);
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
  if (menu.State == menu.PLAY_GAME)
  {
    player.paddleStop(event);
  }
}