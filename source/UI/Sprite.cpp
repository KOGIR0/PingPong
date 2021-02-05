#include "Sprite.h"
#include <iostream>

Sprite::Sprite() {

}

Sprite::Sprite(const std::string& path)
{
	this->texture.setRepeated(false);
	if (!texture.loadFromFile(path))
	{
		std::cout << "Error loading texture" << std::endl;
	}
	sf::Sprite s;
	s.setTexture(texture);
	this->sprite = s;
}

sf::Sprite Sprite::getSprite()
{
	return this->sprite;
}

sf::Texture Sprite::getTexture()
{
	return this->texture;
}

void Sprite::setTexture(const std::string& path)
{
	this->texture.setRepeated(false);
	if (!texture.loadFromFile(path))
	{
		std::cout << "Error loading texture" << std::endl;
	}
	sf::Sprite s;
	s.setTexture(texture);
	this->sprite = s;
}

void Sprite::setPosition(const sf::Vector2f& pos)
{
	sprite.setPosition(pos);
}

void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(this->sprite, states);
}

void Sprite::setSize(sf::Vector2f size)
{
	sf::Vector2u textureSize = sprite.getTexture()->getSize();
	sprite.setScale(size.x / textureSize.x, size.y / textureSize.y);
}