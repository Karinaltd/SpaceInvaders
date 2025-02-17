#ifndef TANK_H
#define TANK_H

#include <SFML/Graphics.hpp>

class Tank {
public:
    Tank(float x, float y);
    void handleInput();
    void render(sf::RenderWindow &window);

private:
    sf::RectangleShape tankShape;
    float speed;
};

#endif
