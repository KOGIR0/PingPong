#ifndef BALL
#define BALL

#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable
{
public:
    Ball(const float& radius = 5.f);
    void setSpeed(const sf::Vector2f& speed);
    void setPosition(const sf::Vector2f& position);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void move();
    float getRadius();
    sf::Vector2f getPosition();
    sf::Vector2f getSpeed();
    sf::CircleShape getCircleShape();

private:
    sf::CircleShape cs;
    sf::Vector2f speed;
};

#endif