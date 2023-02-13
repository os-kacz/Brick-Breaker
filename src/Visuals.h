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
  /*
    as the sf::RenderWindow is a reference it needs to be assigned in the constructor
    just like Game.h and the Game.h constructor
    Then you need to change the instance of this class to be a pointer
    and initialise it with the new keyword (and delete it after)
  */
  bool initialise(sf::RenderWindow& window, GameState& menu);
  void switchState(sf::RenderWindow& window, GameState& menu);
  sf::Texture ball_texture, paddle_texture, brick_texture;
  GameObject ball, paddle;
  static const int column = 11;
  static const int row = 4;
  GameObject brick[column*row];
  sf::Text main_text;
  sf::Font font;
  int grid_accum = 0;
 private:
  bool loadTexture();
};

#endif // BREAKOUTSFML_VISUALS_H
