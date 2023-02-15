#include "Visuals.h"
#include <iostream>

// how to properly implement "sf::RenderWindow window" and "GameState menu" in this class?

Visuals::Visuals()
{

}

Visuals::~Visuals()
{

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
  paddle.type = paddle.PADDLE;
  for (auto & i : brick)
  {
    i.initialiseSprite(
      brick_texture, "Data/Images/element_grey_rectangle.png");
    i.type = i.BRICK;
  }
  for (auto & j : gem)
  {
    j.initialiseSprite(
      gem_texture, "Data/Images/element_red_diamond_glossy.png");
    j.type = j.GEM;
  }

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

  life_text.setString("Lives Left: "+std::to_string(ball.lives));
  life_text.setFont(font);
  life_text.setCharacterSize(30);
  life_text.setFillColor(sf::Color::White);

  choice_text.setString("> Sure!\nNo, I got things to do");
  choice_text.setFont(font);
  choice_text.setCharacterSize(45);
  choice_text.setFillColor(sf::Color::White);
  choice_text.setPosition(
    main_text.getPosition().x,
    main_text.getPosition().y + main_text.getGlobalBounds().height + 20);

  score_text.setString("null");
  score_text.setFont(font);
  score_text.setCharacterSize(45);
  score_text.setFillColor(sf::Color::White);
  score_text.setPosition(
              window.getSize().x / 2,
              window.getSize().y / 2);

  ball.getSprite()->setScale(0.2,0.2);
  ball.getSprite()->setPosition(
    (window.getSize().x / 2) - (ball.getSprite()->getGlobalBounds().width / 2),
    window.getSize().y - (ball.getSprite()->getGlobalBounds().height + paddle.getSprite()->getGlobalBounds().height));

  paddle.getSprite()->setPosition(
    (window.getSize().x / 2) - (paddle.getSprite()->getGlobalBounds().width / 2),
    window.getSize().y - paddle.getSprite()->getGlobalBounds().height);

  ball.lives = 4;
  ball.direction.x = -3;
  ball.direction.y = -5;
  ball.direction.normalise();

  for (int i = 0; i < row; i++)
  {
    for (int j = 0; j < column; j++)
    {
      brick[j+grid_accum].getSprite()->setPosition(
        ((window.getSize().x / column) * j) + 20,22 + (i*50));
    }
    grid_accum += column;
  }

  for (int l = 0; l < gem_count; l++)
  {
    gem[l].getSprite()->setPosition(
      (window.getSize().x / gem_count) * l,
      -(gem[l].getSprite()->getGlobalBounds().height));
  }

  return true;
}

void Visuals::switchState(sf::RenderWindow& window, GameState& menu)
{
  switch (menu.State)
  {
    case (1):
    {
      main_text.setString("Press Enter to play Breakout");
      window.draw(main_text);
      break;
    }
    case (2):
    {
      window.draw(life_text);
      window.draw(*ball.getSprite());
      window.draw(*paddle.getSprite());
      window.draw(score_text);
      for (auto & i : brick)
      {
        if (i.visible)
          window.draw(*i.getSprite());
      }
      for (auto & j : gem)
      {
        if (j.visible)
          window.draw(*j.getSprite());
      }
      break;
    }
    case (3):
    {
      main_text.setString("You lose! Play again?");
      window.draw(main_text);
      window.draw(choice_text);
      break;
    }
    case (4):
    {
      main_text.setString("You Win! Play again?");
      window.draw(main_text);
      window.draw(choice_text);
      break;
    }
    default:
      window.draw(main_text);
      break;
  }
}
