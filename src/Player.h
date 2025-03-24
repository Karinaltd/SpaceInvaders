#ifndef PLAYER_H
#define PLAYER_H
#include "Tank.h"
#include "Alien.h"
#include <SFML/Graphics.hpp>

class Player {
public:
    Player();
    void handleInput();
    void render(sf::RenderWindow* window);
    Tank& getTank() { return tank; }
    void die() { lives--; }    
    void increaseScore(int reward) { score += reward; }
    bool checkHitByAlienBullets(std::vector<AlienBullet>& bullets);
    int getLives() { return lives; }
    int getScore() { return score; }
    
private:
    int lives;
    int score;
    Tank tank;
};

#endif
