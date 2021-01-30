#include "Menu.h"

Menu::Menu(const sf::Vector2f& screenSize, const std::vector<std::string> btnTxt)
{
    this->screenSize = screenSize;
    float textDist = (screenSize.y) / (btnTxt.size() + 1);
    this->btns.resize(btnTxt.size());
    this->txts.resize(btnTxt.size());
    for(int i = 0; i < btnTxt.size(); i++)
    {
        this->btns[i] = new Button(200, 40, {screenSize.x / 2 - 100, (i + 1)*textDist});
        this->btns[i]->setFillColor(sf::Color::Green);
        this->txts[i] = new Text("times-new-roman.ttf", btnTxt[i]);

        // put text in center of button
        sf::Vector2f btnSize = this->btns[i]->getSize();
        sf::Vector2f btnPos = this->btns[i]->getPosition();
        sf::Vector2f newTxtPos = btnPos + sf::Vector2f({btnSize.x / 2.0f, btnSize.y / 2.0f});
        txts[i]->setPosition(newTxtPos);
    }
}

Menu::~Menu()
{
    for(Button* p : this->btns)
    {
        delete p;
    }
    for(Text* p : this->txts)
    {
        delete p;
    }
    this->btns.clear();
    this->txts.clear();
}

void Menu::resizeMenu(const sf::Vector2f& screenSize)
{
    this->screenSize = screenSize;
    float textDist = (this->screenSize.y) / (this->btns.size() + 1);
    for(int i = 0; i < this->btns.size(); i++)
    {
        this->btns[i]->setPosition({screenSize.x / 2 - 100, (i + 1) * textDist});
        sf::Vector2f btnSize = this->btns[i]->getSize();
        sf::Vector2f btnPos = this->btns[i]->getPosition();
        sf::Vector2f newTxtPos = btnPos + sf::Vector2f({btnSize.x / 2.0f, btnSize.y / 2.0f});
        this->txts[i]->setPosition(newTxtPos);
    }
}

// from top to bottom
// returns 1 if first button was clicked
// returns 2 if second
// returns -1 if none was clicked
int Menu::processClick(const sf::Vector2i& position)
{
    for(int i = 0; i < this->btns.size(); i++)
    {
        if(this->btns[i]->clicked(position))
            return i + 1;
    }
    return -1;
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    for(int i = 0; i < this->btns.size(); i++)
    {
        target.draw(*this->btns[i], states);
        target.draw(*this->txts[i], states);
    }
}