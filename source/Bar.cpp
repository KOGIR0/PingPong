#include "Bar.h"

Bar::Bar(const sf::Vector2f& size, const sf::Vector2f& position)
{
    this->size = size;
    this->rs = sf::RectangleShape(size);
    this->rs.setFillColor(sf::Color::White);
    this->rs.setPosition(position);
}

void Bar::setPosition(const sf::Vector2f& position)
{
    this->rs.setPosition(position);
}

bool Bar::intersect(const sf::CircleShape& cs)
{
    sf::Vector2f rsPos = this->rs.getPosition();
    sf::Vector2f rsSize = this->rs.getSize();
    sf::Vector2f csPos = cs.getPosition();
    float csR = cs.getRadius();
    return (rsPos.x < csPos.x + 2*cs.getRadius()) &&
        (rsPos.x + rsSize.x >= csPos.x + cs.getRadius()) &&
        (rsPos.y < csPos.y && rsPos.y + rsSize.y > csPos.y);
}

void Bar::moveDown()
{
    this->rs.setPosition(this->rs.getPosition() + sf::Vector2f(0, SPEED));
}

void Bar::moveUp()
{
    this->rs.setPosition(this->rs.getPosition() + sf::Vector2f(0, -SPEED));
}

void Bar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->rs, states);
}

sf::Vector2f Bar::getPosition()
{
    return this->rs.getPosition();
}