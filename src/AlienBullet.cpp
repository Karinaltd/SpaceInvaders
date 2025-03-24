#include "AlienBullet.h"
#include "Constants.h"
#include "Helper.h"

AlienBullet::AlienBullet(float x, float y) : Bullet(x, y) { 
    bulletShape.setFillColor(sf::Color::Red);
    speed = ALIEN_BULLET_SPEED + (0.1 * getRandomNumber(1, 10)); 
}

void AlienBullet::move() {
    bulletShape.move(0, speed * 0.016f); 
}