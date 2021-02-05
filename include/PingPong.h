#ifndef PINGPONG
#define PINGPONG

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "Ball.h"
#include "Bar.h"
#include "Text.h"
#include "Menu.h"

enum class status
{
    menu,
    pve,
    pvp
};

enum class pressedBtn
{
    up,
    down,
    none
};

class PingPong
{
public:
    PingPong(const sf::Vector2f& screenSize);
    void ProcessEvents();
    void UpdateWindow();
    bool IsRunning();

private:
    sf::Vector2f screenSize;
    std::unique_ptr<sf::RenderWindow> window;
    Ball ball;
    Bar leftBar;
    Bar rightBar;
    std::unique_ptr<Text> scoreTxt;
    std::unique_ptr<Button> menuBtn;
    std::vector<int> score;
    std::unique_ptr<Menu> menu;
    status gameStatus;
    // player1 - left; player2 - right
    pressedBtn p1BtnPressed;
    pressedBtn p2BtnPressed;

    void processBallCollisions();
    void moveBars();
    void processKeyPressEvent(const sf::Event& e);
    void processKeyReleasedEvent(const sf::Event& e);
    void processMouseBtnPress(const sf::Event& e);
    void processEvent(const sf::Event& e);
};

#endif