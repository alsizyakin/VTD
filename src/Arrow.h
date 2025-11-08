#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/VertexArray.hpp"
#include "SFML/System/Vector2.hpp"
#include <SFML/Graphics.hpp>

class Arrow {
  private:
    sf::Vector2f _start;
    sf::Vector2f _end;
    sf::VertexArray _Sprite;
    sf::Color _color;
    float _length;
    float _angle;
    float _width;


  public:
    Arrow();
    void setStartPoint(sf::Vector2f point);
    void setEndPoint(sf::Vector2f point);
    void setColor(sf::Color color);
    void setAngle(float angle);
    void calculate();
    sf::VertexArray& getSprite();
    sf::Vector2f getStartPoint();
    sf::Vector2f getEndPoint();
    float getLength();
    float getAngle();
};
