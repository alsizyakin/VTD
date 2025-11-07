#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/ConvexShape.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>

// using namespace sf;

int main() {

    sf::RenderWindow window(sf::VideoMode(960, 540), "SFML Template window");

    // create an array of 3 vertices that define a triangle primitive
    sf::VertexArray fig1(sf::PrimitiveType::Triangles, 3);
    sf::VertexArray fig2(sf::PrimitiveType::Quads, 4);
    // define the position of the triangle's points
    fig1[0].position = sf::Vector2f(100.f, 100.f);
    fig1[1].position = sf::Vector2f(80.f, 120.f);
    fig1[2].position = sf::Vector2f(120.f, 120.f);

    fig2[0].position = sf::Vector2f(90.f, 120.f);
    fig2[1].position = sf::Vector2f(90.f, 300.f);
    fig2[2].position = sf::Vector2f(110.f, 300.f);
    fig2[3].position = sf::Vector2f(110.f, 120.f);

    // define the color of the triangle's points
    fig1[0].color = sf::Color::Red;
    fig1[1].color = sf::Color::Blue;
    fig1[2].color = sf::Color::Green;

    fig2[0].color = sf::Color::Red;
    fig2[1].color = sf::Color::Blue;
    fig2[2].color = sf::Color::Green;
    fig2[3].color = sf::Color::Yellow;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }
        }

        window.clear();

        window.draw(fig1);
        window.draw(fig2);
        window.display();
    }

    return 0;
}
