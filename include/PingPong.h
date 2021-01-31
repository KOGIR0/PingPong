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
    Button* menuBtn;
    std::vector<int> score;
    Menu* menu;
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