#include "Player.h"
#include "Tank.h"
#include "Bullet.h"
#include "Alien.h"
#include "Game.h"
#include "Constants.h"
#include <iostream>


Player::Player(){
    lives = 3;
    score = 0;
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
        tank.shoot1();
    }
  }

void Player::render(sf::RenderWindow* window) {
    tank.render(window);
}

bool Player::checkHitByAlienBullets(std::vector<AlienBullet>& bullets) {
    bool tankHit = false;
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        if (it->getBulletShape().getGlobalBounds().intersects(tank.getTankShape().getGlobalBounds())) {
            tankHit = true;
            die();
            it = bullets.erase(it);
        } else {
            ++it;
        }
    }
    return tankHit;
}

