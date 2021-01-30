#ifndef BUTTON
#define BUTTON

#include "SFML/Graphics.hpp"
#include "Sprite.h"

class Button : public sf::Drawable
{
public:
    Button(const Button& button);
    Button(const float& width = 10.f, const float& height = 10.f, const sf::Vector2f& position = { 0, 0 });
    Button(const std::string& texturePath, const float& width = 10.f,
        const float& height = 10.f, const sf::Vector2f& position = { 0, 0 });
    // checks if button was clicked
    bool clicked(const sf::Vector2f& position);
    bool clicked(const sf::Vector2i& position);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void setFillColor(sf::Color c);
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);
    sf::Vector2f getPosition();
    sf::Vector2f getSize();

private:
    sf::RectangleShape rs;
    sf::Texture texture;
};

#endif