#include "Bullet.h"
#include "Constants.h"
#include <iostream>

Bullet::Bullet(float x, float y) {
    bulletShape.setRadius(5.0f);
    bulletShape.setFillColor(sf::Color::Green);
    bulletShape.setPosition(x, y);
    speed = BULLET_SPEED;
}

void Bullet::move() {
    bulletShape.move(0, -speed * 0.016f);
}

void Bullet::render(sf::RenderWindow &window) {
    window.draw(bulletShape);
}
