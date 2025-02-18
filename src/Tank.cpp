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
    renderBullets(window); 
}

void Tank::shoot() {
  if (shotClock.getElapsedTime().asSeconds() >= shotCooldown) {
    bullets.emplace_back(tankShape.getPosition().x + tankShape.getSize().x / 2, tankShape.getPosition().y);
    shotClock.restart();
  }
}

void Tank::updateBullets() {
  for (auto it = bullets.begin(); it != bullets.end(); ) {
      it->moveUp();
      if (it->getYPos() < 0) {
          it = bullets.erase(it); 
      } else {
          ++it;
      }
  }
}

void Tank::renderBullets(sf::RenderWindow* window) {
  for (auto& bullet : bullets) {
      bullet.render(*window);
  }
}