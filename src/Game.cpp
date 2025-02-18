#include "Game.h"
#include "Player.h"
#include "Tank.h"
#include "Bullet.h"
#include "Constants.h"
#include <iostream>


Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders"){
    player = new Player();
}

Game::~Game() {
    delete player;
}

void Game::start() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        player->handleInput();
        player->getTank().updateBullets(); 
        window.clear();
        render();
        window.display();
    }
}

void Game::render() {
    player->render(&window);
}
