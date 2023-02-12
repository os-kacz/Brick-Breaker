#ifndef BREAKOUTSFML_VISUALS_H
#define BREAKOUTSFML_VISUALS_H
#include "GameObject.h"
#include "GameState.h"
#include "PlayerController.h"
#include <SFML/Graphics.hpp>

class Visuals
{
 public:
  Visuals();
  ~Visuals();
  bool initialise(sf::RenderWindow& window, GameState& menu);
  void switchState(sf::RenderWindow& window, GameState& menu);
  sf::Texture ball_texture, paddle_texture, brick_texture;
  GameObject ball, paddle;
  GameObject brick[44];
  sf::Text main_text;
  sf::Font font;
  int column = 11;
  int row = 4;
  int grid_accum = 0;
 private:
  bool loadTexture();
};

#endif // BREAKOUTSFML_VISUALS_H
