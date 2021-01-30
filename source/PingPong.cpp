#include "PingPong.h"
#include <string>

#include <iostream>

PingPong::PingPong(const sf::Vector2f& screenSize)
{
    this->score = {0, 0};
    this->scoreTxt = new Text("times-new-roman.ttf",
        std::to_string(score[0]) + " : " + std::to_string(score[1]));
    this->scoreTxt->setPosition({screenSize.x / 2 , this->scoreTxt->getSize().y});
    this->screenSize = screenSize;
    this->window = new sf::RenderWindow(sf::VideoMode(screenSize.x, screenSize.y), "PingPong");
    this->window->setFramerateLimit(50);
    this->ball = new Ball(5);
    this->leftBar = new Bar({5, 50}, {5, screenSize.y / 2});
    this->rightBar = new Bar({5, 50}, {screenSize.x - 10, screenSize.y / 2});
    this->ball->setPosition({screenSize.x / 2, screenSize.y / 2});
}

PingPong::~PingPong()
{
    delete this->window;
    delete this->ball;
    delete this->leftBar;
    delete this->rightBar;
    delete this->scoreTxt;
}

void PingPong::bounceBall()
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
        this->scoreTxt->setString(std::to_string(score[0]) + " : " + std::to_string(score[1]));
        sf::Vector2f newSpeed = ballSpeed - sf::Vector2f(0, ballSpeed.y * 2);
        newSpeed = {-newSpeed.x, -newSpeed.y};
        this->ball->setSpeed(newSpeed);
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

void PingPong::ProcessEvents()
{
    this->bounceBall();
    this->ball->move();
    sf::Event e;
    while(this->window->pollEvent(e))
    {
        switch(e.type)
        {
            case sf::Event::Closed:
                this->window->close();
            case sf::Event::KeyPressed:
                if(e.key.code == sf::Keyboard::Up)
                {
                    this->leftBar->moveUp();
                } else if (e.key.code == sf::Keyboard::Down)
                {
                    this->leftBar->moveDown();
                } else if (e.key.code == sf::Keyboard::W)
                {
                    this->rightBar->moveUp();
                } else if (e.key.code == sf::Keyboard::S)
                {
                    this->rightBar->moveDown();
                }
        }
    }
    // need to change 20 and 40 to bar middle
    /*if(rightBar->getPosition().y + 20 > this->ball->getPosition().y)
    {
        this->rightBar->moveUp();
    } else if(rightBar->getPosition().y + 40 < this->ball->getPosition().y){
        this->rightBar->moveDown();
    }*/
}

void PingPong::UpdateWindow()
{
    this->window->clear();
    this->window->draw(*this->leftBar);
    this->window->draw(*this->rightBar);
    this->window->draw(*this->ball);
    this->window->draw(*this->scoreTxt);
    this->window->display();
}

bool PingPong::IsRunning()
{
    return this->window->isOpen();
}