#include "Game.h"
#include "Player.h"
#include "AlienSwarm.h"
#include "Tank.h"
#include "Bullet.h"
#include "Constants.h"
#include "Helper.h"
#include <iostream>


Game::Game() : window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders"){
    player = new Player();
}

Game::~Game() {
    delete player;
}

void Game::start() {
    alienSwarm = new AlienSwarm();
    textSetup();
    gameLoop();
}

void Game::textSetup() {
    if (!gameFont.loadFromFile("../assets/PressStart2P-Regular.ttf")) {
        std::cerr << "Failed to load font\n";
        return;
    }
    gameText.setFont(gameFont);
    gameText.setCharacterSize(24);
    gameText.setFillColor(sf::Color::White);
    gameText.setPosition(10, 10);
    updateText();
}

void Game::gameLoop() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(player->getLives() == 0){
            window.clear();
            renderGameOver();
            window.display();
            continue;
        }
        alienSwarm->moveAliens();
        if(getRandomNumber(0, MAX_RANDOM_ALIEN_SHOT_RANGE) == 0){
            alienSwarm->fireBullets();
        }
        alienSwarm->updateBullets();
        if (checkCollisions()){
            updateText();
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
    alienSwarm->renderAliens(&window);
    alienSwarm->renderAlienBullet(&window);
    renderText();
}

void Game::renderText() {
    window.draw(gameText);
}

void Game::renderGameOver(){
    gameText.setString("Game Over! Score: " + std::to_string(player->getScore()));
    gameText.setPosition(WINDOW_WIDTH / 2 - 250, WINDOW_HEIGHT / 2);
    window.draw(gameText);
}

void Game::updateText(){
    gameText.setString("Lives: " + std::to_string(player->getLives()) + " Score: " + std::to_string(player->getScore()));
}

bool Game::checkCollisions() {
    return(player->checkHitByAlienBullets(alienSwarm->getBullets()) || alienSwarm->checkBulletCollisions(player->getTank().getBullets(), player));
}
