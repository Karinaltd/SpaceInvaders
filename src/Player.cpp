#include "Player.h"
#include "Tank.h"
#include "Bullet.h"
#include "Constants.h"
#include <iostream>


Player::Player(){
    this->health = 3;
}

void Player::handleInput() {
    float leftBound = 0;
    float rightBound = WINDOW_WIDTH - tank.getTankSize();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && tank.getXPos() > leftBound) {
        tank.moveLeft();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && tank.getXPos() < rightBound) {
        tank.moveRight();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        tank.shoot();
    }
  }

void Player::render(sf::RenderWindow* window) {
    tank.render(window);
}
