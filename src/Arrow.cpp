#include "Arrow.h"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/System/Vector2.hpp"
#include <cmath>
#include <cstdio>
#include <math.h>

Arrow::Arrow() : _Sprite(sf::Triangles, 12) {

    // define the color of the triangle's points
    _Sprite[0].color = sf::Color::White;
    _Sprite[1].color = sf::Color::White;
    _Sprite[2].color = sf::Color::White;

    _Sprite[3].color = sf::Color::White;
    _Sprite[4].color = sf::Color::White;
    _Sprite[5].color = sf::Color::White;
    _Sprite[6].color = sf::Color::White;
    _Sprite[7].color = sf::Color::White;
    _Sprite[8].color = sf::Color::White;
    _Sprite[9].color = sf::Color::White;
    _Sprite[10].color = sf::Color::White;
    _Sprite[11].color = sf::Color::White;
}

void Arrow::setStartPoint(sf::Vector2f point) {
    _start = point;
    calculate();
}

void Arrow::setEndPoint(sf::Vector2f point) {
    _end = point;
    calculate();
}

void Arrow::setColor(sf::Color color) {
    for (int i = 0; i < _Sprite.getVertexCount(); i++) {
        _Sprite[i].color = color;
    }
}

sf::VertexArray& Arrow::getSprite() {
    return _Sprite;
}

void Arrow::setAngle(float angle) {}

void Arrow::calculate() {
    float x_dist = _end.x - _start.x;
    float y_dist = _end.y - _start.y;

    _length = sqrt(x_dist * x_dist + y_dist * y_dist);
    _angle = atan2(y_dist, x_dist);
    _width = _length * 0.05f;
    float tipAngle = 30;
    float lowTipAngle = 15;

    float arrowLength = _length * 0.2f;
    if (arrowLength < 20) {
        arrowLength = 20;
    }

    float dx[_Sprite.getVertexCount()];
    float dy[_Sprite.getVertexCount()];

    dx[0] = 0;
    dy[0] = 0;

    dx[1] = arrowLength * cos((180 + tipAngle / 2) / 180 * M_PI);
    dy[1] = arrowLength * sin((180 + tipAngle / 2) / 180 * M_PI);

    dx[2] = -arrowLength * 2 / 3;
    dy[2] = 0;

    dx[3] = 0;
    dy[3] = 0;

    dx[4] = dx[1];
    dy[4] = -dy[1];

    dx[5] = dx[2];
    dy[5] = dy[2];

    dx[6] = dx[2];
    dy[6] = -_width / 2;

    dx[7] = -_length;
    dy[7] = dy[6];

    dx[8] = dx[7];
    dy[8] = -dy[6];

    dx[9] = dx[8];
    dy[9] = dy[8];

    dx[10] = dx[6];
    dy[10] = dy[8];

    dx[11] = dx[6];
    dy[11] = dy[6];

    for (int i = 0; i < _Sprite.getVertexCount(); i++) {
        _Sprite[i].position.x =
            _end.x + dx[i] * cos(_angle) - dy[i] * sin(_angle);
        _Sprite[i].position.y =
            _end.y + dx[i] * sin(_angle) + dy[i] * cos(_angle);
    }
}

sf::Vector2f Arrow::getEndPoint() {
    return _end;
}

sf::Vector2f Arrow::getStartPoint() {
    return _start;
}

float Arrow::getLength() {
    return _length;
}

float Arrow::getAngle() {
    return _angle;
}
