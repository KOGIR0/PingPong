#include "Button.h"
#include <iostream>

Button::Button(const float& width, const float& height, const sf::Vector2f& position)
{
    rs = sf::RectangleShape({ width, height });
    rs.setPosition(position);
    rs.setFillColor(sf::Color::Red);
}

Button::Button(const std::string& texturePath, const float& width, const float& height, const sf::Vector2f& position)
{
    rs = sf::RectangleShape({ width, height });
    rs.setPosition(position);
    rs.setFillColor(sf::Color::Red);
    sf::Texture t;
    if (!t.loadFromFile(texturePath))
    {
        std::cerr << "Error loading texture" << std::endl;
    }
    t.setRepeated(false);
    this->texture = t;
    this->rs.setTexture(&this->texture);
}

sf::Vector2f Button::getSize()
{
    return this->rs.getSize();
}

void Button::setPosition(const sf::Vector2f& position)
{
    rs.setPosition(position);
}

sf::Vector2f Button::getPosition()
{
    return this->rs.getPosition();
}

void Button::setSize(const sf::Vector2f& size)
{
    rs.setSize(size);
}

bool Button::clicked(const sf::Vector2f& position)
{
    sf::Vector2f buttonPosition = rs.getPosition();
    sf::Vector2f buttonSize = rs.getSize();
    if ((position.x > buttonPosition.x && position.y > buttonPosition.y) &&
        (position.x < buttonPosition.x + buttonSize.x && position.y < buttonPosition.y + buttonSize.y))
    {
        return true;
    }
    return false;
}

bool Button::clicked(const sf::Vector2i& position)
{
    sf::Vector2f buttonPosition = rs.getPosition();
    sf::Vector2f buttonSize = rs.getSize();
    if ((position.x > buttonPosition.x && position.y > buttonPosition.y) &&
        (position.x < buttonPosition.x + buttonSize.x && position.y < buttonPosition.y + buttonSize.y))
    {
        return true;
    }
    return false;
}

void Button::setFillColor(sf::Color c)
{
    this->rs.setFillColor(c);
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->rs, states);
}