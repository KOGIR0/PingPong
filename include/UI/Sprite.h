/*
Wrapper over SFML Sprite
*/

#ifndef SPRITE
#define SPRITE

#include <SFML/Graphics.hpp>

class Sprite : public sf::Drawable
{
public:
    Sprite();
    Sprite(const Sprite& s);
    Sprite(const std::string& path);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    //void draw(sf::RenderWindow* rw);
    void setSize(sf::Vector2f size);
    void setPosition(const sf::Vector2f& position);
    void setTexture(const std::string& path);
    sf::Texture getTexture();
    sf::Sprite getSprite();

private:
    sf::Sprite sprite;
    sf::Texture texture;
};

#endif // !SPRITE
