#ifndef BREAKOUTSFML_VISUALS_H
#define BREAKOUTSFML_VISUALS_H
#include "GameState.h"
#include <SFML/Graphics.hpp>

class Visuals
{
 public:
  Visuals(sf::RenderWindow& window);
  bool initialise();
  void stateSwitch();
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Text mainText;
  sf::Font font;
  GameState menu;
};

#endif // BREAKOUTSFML_VISUALS_H
