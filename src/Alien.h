#ifndef ALIEN_H
#define ALIEN_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "AlienBullet.h"

class Alien {
public:
    Alien();
    void moveLeft();
    void moveRight();
    void moveDown();
    void render(sf::RenderWindow* window);
    void shoot(std::vector<AlienBullet>& bullets);
    void die() { alive = false; }

    void setPos(float x, float y) { position = { x, y }; }
    int getXPos() const { return position.x; }
    int getYPos() const { return position.y; }
    bool isAlive() const { return alive; }

    sf::FloatRect getBounds() const;
    void appendToVertexArray(sf::VertexArray& vertexArray) const;

private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Clock shotClock; 
    bool alive;
};

#endif
