#include "Text.h"

Text::Text(const std::string& fontPath, const std::string& string,
    const int& fontSize, const sf::Color& color)
{
    if (!this->font.loadFromFile(fontPath))
    {
        std::cout << "Error loading font" << std::endl;
    }
    this->text.setFont(this->font);
    this->text.setCharacterSize(fontSize);
    this->text.setFillColor(color);
    this->text.setString(string);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);
}

sf::Vector2f Text::getSize()
{
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width/2.0f,
               textRect.top  + textRect.height/2.0f);
    return {this->text.getLocalBounds().width, this->text.getLocalBounds().height};
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->text, states);
}

void Text::setString(const std::string& string)
{
    this->text.setString(string);
}

void Text::setPosition(const sf::Vector2f& position)
{
    this->text.setPosition(position);
}