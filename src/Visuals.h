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
  GameObject brick[33];
  sf::Text main_text;
  sf::Font font;
 private:
  bool loadTexture();
};

#endif // BREAKOUTSFML_VISUALS_H
