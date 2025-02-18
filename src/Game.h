#ifndef Game_H
#define Game_H
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game{
public:
    Game();
    ~Game();
    void start();
    void render();

private:
    Player *player;
    sf::RenderWindow window;
};

#endif
