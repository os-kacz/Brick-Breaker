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
  return visual.initialise(window, menu);
}

void Game::update(float dt)
{
  object_speed = dt * 400;
  time_passed += dt;
  if (time_passed > 5.0)
  {
    visual.gem_accum++;
    if (visual.gem_accum == 3)
    {
      visual.gem_accum = 0;
    }
    visual.gem[visual.gem_accum].visible = true;
    visual.gem[visual.gem_accum].getSprite()->setPosition(
      std::rand() % (window.getSize().x - 20) + 20,-20);
    time_passed = 0;
  }
  if (visual.ball.lives < 0)
  {
    menu.State = menu.QUIT_MENU;
  }
  if (menu.State == menu.PLAY_GAME)
  {
    for (auto& i : visual.brick)
    {
      if (i.visible)
      {
        collision.gameObjectCheck(visual.ball, i);
        if (!i.visible)
        {
          visual.brick_accum += 1;
          if (visual.brick_accum == (visual.column * visual.row))
          {
            menu.State = menu.WIN_MENU;
          }
        }
      }
    }

    if (visual.gem[visual.gem_accum].visible)
    {
      visual.gem[visual.gem_accum].getSprite()->move(0,250*dt);
      collision.gameObjectCheck(visual.gem[visual.gem_accum],visual.paddle);
    }

    collision.paddleWindowCheck(window, visual.paddle);
    collision.gameObjectCheck(visual.ball, visual.paddle);

    if (visual.ball.attached)
    {
      collision.paddleWindowCheck(window, visual.ball);
      visual.ball.getSprite()->move(player.paddle_spd * object_speed, 0);
    }
    else
    {
      collision.ballWindowCheck(window, visual.ball, visual.paddle);
      visual.ball.getSprite()->move(
        visual.ball.direction.x * object_speed,
        visual.ball.direction.y * object_speed);
    }
    visual.life_text.setString(
      "Lives Left: " + std::to_string(visual.ball.lives));
    visual.score_text.setString("Score: " + std::to_string(collision.score));
    visual.life_text.setPosition(
      (visual.paddle.getSprite()->getPosition().x) - 25,
      visual.paddle.getSprite()->getPosition().y -
        (visual.paddle.getSprite()->getGlobalBounds().height + 10));
    visual.paddle.getSprite()->move(player.paddle_spd * object_speed, 0);
  }
  if (menu.State != menu.PLAY_GAME)
  {
    if (continue_selected)
    {
      visual.choice_text.setString("> Sure!\nNo, I got things to do");
    }
    else
    {
      visual.choice_text.setString("Sure!\n> No, I got things to do");
    }
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
  if (menu.State != menu.PLAY_GAME)
  {
    if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S)
    {
      continue_selected = !continue_selected;
    }
    if (continue_selected && event.key.code == sf::Keyboard::Enter)
    {
      visual.ball.getSprite()->setPosition(
        visual.paddle.getSprite()->getPosition().x,
        visual.paddle.getSprite()->getPosition().y
          - visual.paddle.getSprite()->getGlobalBounds().height);
      visual.ball.lives = 4;
      collision.score = 0;
      for (auto & i : visual.brick)
      {
        i.visible = true;
      }
      for (auto & j : visual.gem)
      {
        j.visible = true;
        j.getSprite()->setPosition(500,-50);
      }
      menu.State = menu.PLAY_GAME;
    }
    else if (!continue_selected && event.key.code == sf::Keyboard::Enter)
    {
      window.close();
    }
  }
}

void Game::keyReleased(sf::Event event)
{
  if (menu.State == menu.PLAY_GAME)
  {
    player.paddleStop(event);
    if (event.key.code == sf::Keyboard::Space)
    {
      visual.ball.attached = false;
    }
  }
}