#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class Tank {
public:
    Tank();
    void moveLeft();
    void moveRight();
    void render(sf::RenderWindow* window);
    void shoot();

    void updateBullets(); 
    void renderBullets(sf::RenderWindow* window);

    float getTankSize() { return tankShape.getSize().x; }
    int getXPos() { return tankShape.getPosition().x; }
    int getYPos() { return tankShape.getPosition().y; }
    sf::RectangleShape getTankShape() { return tankShape; }
    std::vector<Bullet>& getBullets() { return bullets; }

private:
    sf::RectangleShape tankShape;
    float speed;
    std::vector<Bullet> bullets;
    sf::Clock shotClock; 
    float shotCooldown; 
};

#endif
