#include "Alien.h"
#include "Bullet.h"
#include "Constants.h"
#include <iostream>

Alien::Alien() {
    position = { 0.f, 0.f };
    size = { 20.f, 20.f };
    alive = true;
}

void Alien::moveLeft() {
    position.x -= ALIEN_SIDE_STEP;
}

void Alien::moveRight() {
    position.x += ALIEN_SIDE_STEP;
}

void Alien::moveDown() {
    position.y += ALIEN_DOWN_STEP;
}

void Alien::shoot(std::vector<AlienBullet>& bullets) {
    if (shotClock.getElapsedTime().asSeconds() >= ALIEN_COOLDOWN) {
        bullets.emplace_back(position.x, position.y);
        shotClock.restart();
    }
}

void Alien::render(sf::RenderWindow* window) {
    sf::RectangleShape rect(size);
    rect.setPosition(position);
    rect.setFillColor(sf::Color::Blue);
    window->draw(rect);
}

void Alien::appendToVertexArray(sf::VertexArray& va) const {
    sf::Vertex v0, v1, v2, v3;

    v0.position = position;
    v1.position = { position.x + size.x, position.y };
    v2.position = { position.x + size.x, position.y + size.y };
    v3.position = { position.x, position.y + size.y };

    v0.color = v1.color = v2.color = v3.color = sf::Color::Blue;

    va.append(v0);
    va.append(v1);
    va.append(v2);
    va.append(v3);
}

sf::FloatRect Alien::getBounds() const {
    return sf::FloatRect(position, size);
}
