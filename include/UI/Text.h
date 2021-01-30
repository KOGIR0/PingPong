#ifndef TEXT
#define TEXT

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Text : public sf::Drawable
{
public:
    Text(const std::string& fontPath, const std::string& string = "Text",
        const int& fontSize = 24, const sf::Color& color = sf::Color::White);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setString(const std::string& string);
    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getSize();
    
private:
    sf::Text text;
    sf::Font font;
};

#endif