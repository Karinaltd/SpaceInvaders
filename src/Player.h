#ifndef PLAYER_H
#define PLAYER_H
#include "Tank.h"
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void handleInput();
    void render(sf::RenderWindow* window);
    Tank& getTank() { return tank; }
private:
    int health;
    Tank tank;
};

#endif
