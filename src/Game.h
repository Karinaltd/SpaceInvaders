#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "AlienSwarm.h"
#include <SFML/Graphics.hpp>

class Game{
public:
    Game();
    ~Game();
    void start();
    void gameLoop();
    void render();
    bool checkCollisions();
    void textSetup();
    void renderText();
    void updateText();
    void renderGameOver();

private:
    Player *player;
    AlienSwarm *alienSwarm;
    sf::RenderWindow window;
    bool isMovingRight = true;
    sf::Text gameText;
    sf::Font gameFont;
};

#endif
