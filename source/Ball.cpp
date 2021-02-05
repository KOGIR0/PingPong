#include "Ball.h"
#include <iostream>

Ball::Ball(const float& radius)
{
    this->cs = sf::CircleShape(radius);
    this->cs.setFillColor(sf::Color::Green);
    this->cs.setOrigin({radius, radius});
    sf::Vector2f speed((float)(rand() % 11 - 5), (float)(rand() % 11 - 5));
    this->speed = speed;
}

void Ball::setPosition(const sf::Vector2f& position)
{
    this->cs.setPosition(position.x, position.y);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->cs, states);
}

void Ball::setSpeed(const sf::Vector2f& speed)
{
    this->speed = speed;
}

void Ball::move()
{
    sf::Vector2f curPos = this->cs.getPosition();
    this->cs.setPosition(curPos + speed);
}

sf::CircleShape Ball::getCircleShape()
{
    return this->cs;
}

float Ball::getRadius()
{
    return this->cs.getRadius();
}

sf::Vector2f Ball::getPosition()
{
    return this->cs.getPosition();
}

sf::Vector2f Ball::getSpeed()
{
    return this->speed;
}