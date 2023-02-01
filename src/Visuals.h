#ifndef BREAKOUTSFML_VISUALS_H
#define BREAKOUTSFML_VISUALS_H
#include "GameState.h"
#include "Levels.h"
#include <SFML/Graphics.hpp>

class Visuals
{
 public:
  bool initialise(sf::RenderWindow& window, GameState& menu);
  void switchState(sf::RenderWindow& window, GameState& menu);
  Levels level;
  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Sprite paddle;
  sf::Texture paddle_texture;
  sf::Sprite brick;
  sf::Texture brick_texture;
  sf::Text main_text;
  sf::Font font;
};

#endif // BREAKOUTSFML_VISUALS_H
