#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include "Vector2.h"
#include "Visuals.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  sf::RenderWindow& window;
  Visuals makeVisual;
  GameState menu;
};

#endif // BREAKOUT_GAME_H
