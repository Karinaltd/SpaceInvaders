#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(float x, float y);
    void moveUp();
    void moveDown();
    void render(sf::RenderWindow &window);

private:
    sf::CircleShape bulletShape;
    float speed;
};

#endif
