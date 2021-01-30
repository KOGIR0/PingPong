#ifndef PINGPONG
#define PINGPONG

#include <SFML/Graphics.hpp>
#include <vector>

#include "Ball.h"
#include "Bar.h"
#include "Text.h"
#include "Menu.h"

enum class status
{
    menu,
    server,
    client
};

class PingPong
{
public:
    PingPong(const sf::Vector2f& screenSize);
    ~PingPong();
    void ProcessEvents();
    void UpdateWindow();
    bool IsRunning();

private:
    sf::Vector2f screenSize;
    sf::RenderWindow* window;
    Ball* ball;
    Bar* leftBar;
    Bar* rightBar;
    Text* scoreTxt;
    std::vector<int> score;

    void bounceBall();
};

#endif