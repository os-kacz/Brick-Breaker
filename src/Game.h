#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include "PlayerController.h"
#include "Vector2.h"
#include "Visuals.h"
#include "Collision.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& game_window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  float object_speed;
  bool continue_selected = true;
  float time_passed = 5;
  sf::RenderWindow& window;
  Visuals visual;
  GameState menu;
  PlayerController player;
  Collision collision;
};

#endif // BREAKOUT_GAME_H
