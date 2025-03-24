#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet(float x, float y);
    virtual ~Bullet() = default;
    virtual void move();
    void render(sf::RenderWindow &window);

    int getXPos() { return bulletShape.getPosition().x; }
    int getYPos() { return bulletShape.getPosition().y; }
    sf::CircleShape getBulletShape() { return bulletShape; }

protected:
    sf::CircleShape bulletShape;
    float speed;
};

#endif
