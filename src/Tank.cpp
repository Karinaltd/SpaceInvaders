#include "Tank.h"
#include "Bullet.h"
#include "Constants.h"
#include <iostream>


Tank::Tank(float x, float y) : speed(5.0f) {
    tankShape.setSize(sf::Vector2f(50, 20));
    tankShape.setFillColor(sf::Color::Green);
    tankShape.setPosition(x, y);
}

void Tank::handleInput() {
    float leftBound = 0;
    float rightBound = WINDOW_WIDTH - tankShape.getSize().x;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && tankShape.getPosition().x > leftBound) {
        tankShape.move(-speed * 0.016f, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && tankShape.getPosition().x < rightBound) {
        tankShape.move(speed * 0.016f, 0);
    }
  }


void Tank::render(sf::RenderWindow &window) {
    window.draw(tankShape);
}
