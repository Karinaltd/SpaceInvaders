#include <SFML/Graphics.hpp>
#include "Tank.h"
#include "Constants.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Space Invaders");

    Tank tank(375, 550);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        tank.handleInput();
        window.clear();
        tank.render(window);
        window.display();
    }

    return 0;
}
