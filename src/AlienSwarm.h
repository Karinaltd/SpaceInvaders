#ifndef ALIENSWARM_H
#define ALIENSWARM_H
#include "Alien.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

class AlienSwarm{
public:
    AlienSwarm();
    ~AlienSwarm();
    void intializeAliens();     
    void moveAliens();
    void moveAliensDown();
    void renderAliens(sf::RenderWindow* window);
    void fireBullets();
    void updateBullets();
    void deleteDeadAliens();
    std::vector<std::vector<Alien>>& getAliens () { return aliens; }
    //bool checkBulletCollisions(std::vector<Bullet>& playerBullets, Player* player);
    bool checkBulletCollisions1(Bullet& playerBullet, Player* player);
    void speedUpAliens();
    std::vector<AlienBullet>& getBullets() { return bullets; }
    void renderAlienBullet(sf::RenderWindow* window);
    
private:
    std::vector<std::vector<Alien>> aliens;
    std::vector<AlienBullet> bullets;
    bool isMovingRight = true;
    bool isMovingDown = false;
    bool hitWall = false;
    sf::Clock stepTimer;
    sf::Clock fireClock; 
    float stepDelay;
};

#endif