
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include "GameState.h"
#include "Vector2.h"
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

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Text main_menu;
  sf::Font font;
  GameState menu;

};

#endif // BREAKOUT_GAME_H
