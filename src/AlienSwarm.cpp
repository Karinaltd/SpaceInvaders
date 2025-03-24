#include "AlienSwarm.h"
#include "Alien.h"
#include "Player.h"
#include "Constants.h"
#include <iostream>
#include <random>
#include "Helper.h"

AlienSwarm::AlienSwarm() {
    intializeAliens();
    stepDelay = STEP_DELAY;
}

AlienSwarm::~AlienSwarm() {
    for (auto& row : aliens) {
        row.clear();
    }
    aliens.clear();
}

void AlienSwarm::intializeAliens() {
    for (int i = 0; i < ALIEN_ROWS; i++) {
        std::vector<Alien> row;
        for (int j = 0; j < ALIEN_COLS; j++) {
            Alien alien;
            alien.setPos(j * ALIEN_SPACING + WINDOW_PADDING, i * ALIEN_SPACING + WINDOW_PADDING);
            row.push_back(alien);
        }
        aliens.push_back(row);
    }
}

void AlienSwarm::moveAliens() {
    if (stepTimer.getElapsedTime().asMilliseconds() < stepDelay) {
        return;
    }
    stepTimer.restart();
    if (hitWall) {
        moveAliensDown();
        isMovingRight = !isMovingRight;
        hitWall = false;
    }else{
        for (auto& row : aliens) {
            for (auto& alien : row) {
                if (isMovingRight) {
                    alien.moveRight();
                    if(alien.getXPos() > WINDOW_WIDTH - ALIEN_SIZE - WINDOW_PADDING/2) {
                        hitWall = true;
                    }
                } else {
                    alien.moveLeft();
                    if(alien.getXPos() < WINDOW_PADDING/2) {
                        hitWall = true;
                    }
                }
            }
        }
    }
}

void AlienSwarm::fireBullets() {
    if (fireClock.getElapsedTime().asSeconds() >= ALIEN_COOLDOWN) {
        std::vector<Alien*> lowestAliens;

        int maxCols = 0;
        for (const auto& row : aliens) {
            if (row.size() > maxCols) maxCols = row.size();
        }
        
        for (int col = 0; col < maxCols; ++col) {
            for (int row = aliens.size() - 1; row >= 0; --row) {
                if (col < aliens[row].size() && aliens[row][col].isAlive()) {
                    lowestAliens.push_back(&aliens[row][col]);
                    break;
                }
            }
        }

        if (!lowestAliens.empty()) {
            int index = getRandomNumber(0, lowestAliens.size() - 1);
            lowestAliens[index]->shoot(bullets);
        }

        fireClock.restart();
    }
}

void AlienSwarm::moveAliensDown() {
    for (auto& row : aliens) {
        for (auto& alien : row) {
            alien.moveDown();
        }
    }
}

void AlienSwarm::renderAliens(sf::RenderWindow* window) {
    sf::VertexArray alienVertices(sf::Quads);
    for (auto& row : aliens) {
        for (auto& alien : row) {
            if (alien.isAlive()) {
                alien.appendToVertexArray(alienVertices);
            }
        }
    }
    window->draw(alienVertices);
}

void AlienSwarm::renderAlienBullet(sf::RenderWindow* window) {
    for (auto& bullet : bullets) {
        bullet.render(*window);
    }
}

void AlienSwarm::updateBullets() {
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        it->move();
        if (it->getYPos() > WINDOW_HEIGHT) {
            it = bullets.erase(it);
        } else {
            ++it;
        }
    }
}

void AlienSwarm::deleteDeadAliens() {
    for (auto& row : aliens) {
        for (auto it = row.begin(); it != row.end(); ) {
            if (!it->isAlive()) {
                it = row.erase(it);
                speedUpAliens();
            } else {
                ++it;
            }
        }
    }
}

void AlienSwarm::speedUpAliens() {
    stepDelay = stepDelay * 0.96;
}

bool AlienSwarm::checkBulletCollisions(std::vector<Bullet>& playerBullets, Player* player) {
    bool hit = false;
    for (auto bulletIt = playerBullets.begin(); bulletIt != playerBullets.end(); ) {
        sf::FloatRect bulletBounds = bulletIt->getBulletShape().getGlobalBounds();
        for (auto& row : aliens) {
            for (auto& alien : row) {
                if (!alien.isAlive()) continue;
                if (bulletBounds.top + bulletBounds.height < alien.getYPos() ||
                    bulletBounds.top > alien.getYPos() + ALIEN_SIZE) {
                    continue;
                }
                if (bulletBounds.intersects(alien.getBounds())) {
                    alien.die();
                    player->increaseScore(10);
                    bulletIt = playerBullets.erase(bulletIt);
                    hit = true;
                    break;
                }
            }
            if (hit) break; 
        }
        if (!hit) {
            ++bulletIt;
        }
    }
    return hit;
}
