#include "Arrow.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/ConvexShape.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/System/Clock.hpp"
#include "SFML/System/Time.hpp"
#include "SFML/System/Vector2.hpp"
#include "SFML/Window/Keyboard.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

// using namespace sf;

int main() {

    sf::RenderWindow window(sf::VideoMode(960, 540), "SFML Template window");
    sf::Clock timer;
    timer.restart();
    float speed = 30;
    // create an array of 3 vertices that define a triangle primitive
    Arrow fig1;
    //fig1.setColor(sf::Color::Red);
    fig1.setStartPoint(sf::Vector2f(180, 200));
    fig1.setEndPoint(sf::Vector2f(480, 200));
    std::cout << fig1.getLength() << " " << fig1.getAngle() << std::endl;
    std::cout << fig1.getSprite()[0].position.x << " "
              << fig1.getSprite()[0].position.y << " "
              << fig1.getSprite()[1].position.x << " "
              << fig1.getSprite()[1].position.y << " "
              << fig1.getSprite()[2].position.x << " "
              << fig1.getSprite()[2].position.y << std::endl;
    // define the position of the triangle's points

    sf::CircleShape cir1(10);
    cir1.setOrigin(10, 10);
    while (window.isOpen()) {

        float dt = timer.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }

            if (event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        fig1.setStartPoint(
            sf::Vector2f(180, fig1.getStartPoint().y + speed * dt));
        cir1.setPosition(fig1.getStartPoint());

        window.clear();

        window.draw(fig1.getSprite());
        window.draw(cir1);

        window.display();
    }

    return 0;
}
