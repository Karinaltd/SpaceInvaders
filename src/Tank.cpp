#include "Tank.h"
#include "Bullet.h"
#include "Constants.h"
#include <iostream>

Tank::Tank(): speed(5.0f), shotCooldown(0.25f) {
    tankShape.setSize(sf::Vector2f(50, 20));
    tankShape.setFillColor(sf::Color::Green);
    tankShape.setPosition(375, 550);
}

void Tank::moveLeft() {
    tankShape.move(-speed * 0.016f, 0);
  }

void Tank::moveRight() {
    tankShape.move(speed * 0.016f, 0);
  }

void Tank::render(sf::RenderWindow* window) {
    window->draw(tankShape);
    renderBullet(window); 
}

void Tank::shoot() {
  if (shotClock.getElapsedTime().asSeconds() >= SHOT_COOLDOWN) {
    bullets.emplace_back(tankShape.getPosition().x + tankShape.getSize().x / 2, tankShape.getPosition().y);
    shotClock.restart();
  }
}

void Tank::shoot1() {
  if (bulletExists == false) {
    bullet = Bullet(tankShape.getPosition().x + tankShape.getSize().x / 2, tankShape.getPosition().y);
    bulletExists = true;
  }
}

// void Tank::updateBullets() {
//   for (auto it = bullets.begin(); it != bullets.end(); ) {
//       it->move();
//       if (it->getYPos() < 0) {
//           it = bullets.erase(it); 
//       } else {
//           ++it;
//       }
//   }
// }

void Tank::updateBullet() {
  if (bulletExists == false) {
    return;
  }
  else if (bullet.getYPos() < -15) {
    bulletExists = false; 
  }else{
    bullet.move();
  }
}

// void Tank::renderBullets(sf::RenderWindow* window) {
//   for (auto& bullet : bullets) {
//       bullet.render(*window);
//   }
// }

void Tank::renderBullet(sf::RenderWindow* window) {
  bullet.render(*window);
}