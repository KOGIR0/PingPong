#ifndef BAR
#define BAR

#include <SFML/Graphics.hpp>

#define SPEED 10

class Bar : public sf::Drawable
{
public:
    Bar(const sf::Vector2f& size = {5.f, 20.f}, const sf::Vector2f& position = {0.f, 0.f});
    void moveUp();
    void moveDown();
    void setPosition(const sf::Vector2f& position);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    sf::Vector2f getPosition();
    bool intersect(const sf::CircleShape& cs);

private:
    sf::Vector2f size;
    sf::RectangleShape rs;
};


#endif