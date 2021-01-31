#include "PingPong.h"
#include <string>

#include <iostream>

PingPong::PingPong(const sf::Vector2f& screenSize)
{
    this->gameStatus = status::menu;
    this->score = {0, 0};
    this->scoreTxt = new Text("times-new-roman.ttf",
        std::to_string(score[0]) + " : " + std::to_string(score[1]));
    this->scoreTxt->setPosition({screenSize.x / 2 , this->scoreTxt->getSize().y});
    this->screenSize = screenSize;
    this->window = new sf::RenderWindow(sf::VideoMode(screenSize.x, screenSize.y), "PingPong");
    this->window->setFramerateLimit(50);
    this->ball = new Ball(5);
    this->leftBar = new Bar({10, 50}, {20, screenSize.y / 2});
    this->rightBar = new Bar({10, 50}, {screenSize.x - 30, screenSize.y / 2});
    this->ball->setPosition({screenSize.x / 2, screenSize.y / 2});
    this->menu = new Menu(screenSize, {"1 player", "2 players"});
    this->menuBtn = new Button("MenuBtn.png", 25, 25);
    this->menuBtn->setFillColor(sf::Color::White);
    this->p2BtnPressed = pressedBtn::none;
    this->p1BtnPressed = pressedBtn::none;
}

PingPong::~PingPong()
{
    delete this->window;
    delete this->ball;
    delete this->leftBar;
    delete this->rightBar;
    delete this->scoreTxt;
    delete this->menu;
}

void PingPong::processBallCollisions()
{
    sf::Vector2f ballPos = this->ball->getPosition();
    sf::Vector2f ballSpeed = this->ball->getSpeed();
    //bounse against up and down
    if(ballPos.y + this->ball->getRadius() >= this->screenSize.y || ballPos.y <= 0)
    {
        sf::Vector2f newSpeed = ballSpeed - sf::Vector2f(ballSpeed.x * 2, 0);
        newSpeed = {-newSpeed.x, -newSpeed.y};
        this->ball->setSpeed(newSpeed);
    }
    //bounce against left and right
    if(ballPos.x + this->ball->getRadius() >= this->screenSize.x || ballPos.x <= 0)
    {
        if(ballPos.x <= 0)
        {
            this->score[0]++;
        } else {
            this->score[1]++;
        }
        this->ball->setPosition({screenSize.x / 2, screenSize.y / 2});
        this->scoreTxt->setString(std::to_string(score[0]) + " : " + std::to_string(score[1]));
    }
    if(this->leftBar->intersect(this->ball->getCircleShape()))
    {
        sf::Vector2f newSpeed = ballSpeed - sf::Vector2f(0, ballSpeed.y * 2);
        newSpeed = {-newSpeed.x, -newSpeed.y};
        this->ball->setSpeed(newSpeed);   
    }
    if(this->rightBar->intersect(this->ball->getCircleShape()))
    {
        sf::Vector2f newSpeed = ballSpeed - sf::Vector2f(0, ballSpeed.y * 2);
        newSpeed = {-newSpeed.x, -newSpeed.y};
        this->ball->setSpeed(newSpeed);
    }
}

void PingPong::moveBars()
{
    if(this->p1BtnPressed != pressedBtn::none)
    {
        if(this->p1BtnPressed == pressedBtn::up)
        {
            this->leftBar->moveUp();
        } else if(this->p1BtnPressed == pressedBtn::down)
        {
            this->leftBar->moveDown();
        }
    }
    if(this->p2BtnPressed != pressedBtn::none)
    {
        if(this->p2BtnPressed == pressedBtn::up)
        {
            this->rightBar->moveUp();
        } else if(this->p2BtnPressed == pressedBtn::down)
        {
            this->rightBar->moveDown();
        }
    }
}

void PingPong::processKeyPressEvent(const sf::Event& e)
{
    if(e.key.code == sf::Keyboard::Up)
    {
        this->p1BtnPressed = pressedBtn::up;
    } else if (e.key.code == sf::Keyboard::Down)
    {
        this->p1BtnPressed = pressedBtn::down;
    }
    if(this->gameStatus == status::pvp)
    {
        if (e.key.code == sf::Keyboard::W)
        {
            this->p2BtnPressed = pressedBtn::up;
        } else if (e.key.code == sf::Keyboard::S)
        {
            this->p2BtnPressed = pressedBtn::down;
        }
    }
}

void PingPong::processKeyReleasedEvent(const sf::Event& e)
{
    if(e.key.code == sf::Keyboard::Up)
    {
        this->p1BtnPressed = pressedBtn::none;
    } else if (e.key.code == sf::Keyboard::Down)
    {
        this->p1BtnPressed = pressedBtn::none;
    } else if (e.key.code == sf::Keyboard::W && this->gameStatus == status::pvp)
    {
        this->p2BtnPressed = pressedBtn::none;
    } else if (e.key.code == sf::Keyboard::S && this->gameStatus == status::pvp)
    {
        this->p2BtnPressed = pressedBtn::none;
    }
}

void PingPong::processMouseBtnPress(const sf::Event& e)
{
    sf::Vector2i mousePosition = {e.mouseButton.x, e.mouseButton.y};
    int pressResult = this->menu->processClick(mousePosition);
    std::cout << pressResult << std::endl;
    if(pressResult != -1)
    {
        this->score = {0, 0};
        this->scoreTxt->setString(std::to_string(score[0]) + " : " + std::to_string(score[1]));
    }
    if(pressResult == 1)
    {
        this->gameStatus = status::pve;
    } else if (pressResult == 2)
    {
        this->gameStatus = status::pvp;
    }
}

void PingPong::processEvent(const sf::Event& e)
{
    switch(e.type)
    {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            this->processKeyPressEvent(e);
            break;
        case sf::Event::KeyReleased:
            this->processKeyReleasedEvent(e);
            break;
        case sf::Event::MouseButtonPressed:
            if(this->gameStatus != status::menu &&
                this->menuBtn->clicked(sf::Vector2i{e.mouseButton.x, e.mouseButton.y}))
            {
                this->gameStatus = status::menu;
            }
            if(this->gameStatus == status::menu)
            {
                this->processMouseBtnPress(e);
            }
            break;
    }
}

void PingPong::ProcessEvents()
{
    this->processBallCollisions();
    this->ball->move();
    this->moveBars();
    sf::Event e;
    while(this->window->pollEvent(e))
    {
        this->processEvent(e);
    }
    // need to change 20 and 40 to bar middle
    if(this->gameStatus == status::pve)
    {
        if(rightBar->getPosition().y + 20 > this->ball->getPosition().y)
        {
            this->rightBar->moveUp();
        } else if(rightBar->getPosition().y + 40 < this->ball->getPosition().y){
            this->rightBar->moveDown();
        }
    }
}

void PingPong::UpdateWindow()
{
    this->window->clear();
    this->window->draw(*this->leftBar);
    this->window->draw(*this->rightBar);
    this->window->draw(*this->ball);
    this->window->draw(*this->scoreTxt);
    if(this->gameStatus == status::menu)
    {
        this->window->draw(*this->menu);
    } else {
        this->window->draw(*this->menuBtn);
    }
    this->window->display();
}

bool PingPong::IsRunning()
{
    return this->window->isOpen();
}