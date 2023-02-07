#ifndef BREAKOUTSFML_VISUALS_H
#define BREAKOUTSFML_VISUALS_H
#include "GameState.h"
#include "Levels.h"
#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Visuals
{
 public:
  bool initialise(sf::RenderWindow& window, GameState& menu);
  void switchState(sf::RenderWindow& window, GameState& menu);
  sf::Texture ball_texture, paddle_texture, brick_texture;
  sf::Sprite ball, paddle, brick;
  sf::Text main_text;
  sf::Font font;
 private:
  bool loadTexture();
  GameObject game_object;
};

#endif // BREAKOUTSFML_VISUALS_H
