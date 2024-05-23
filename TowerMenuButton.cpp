#include <SFML/Graphics.hpp>
#include <iostream>
#include "TowerMenuButton.h"

TowerMenuButton::TowerMenuButton()
{
	_mouseOver = false;
	if (!_textureHover.loadFromFile("img/menuContextual/button_tower_menu_hover.png"))
	{
		std::cout << "Loading error. " << std::endl;
	}
	_spriteHover.setTexture(_textureHover);
	setPosition(sf::Vector2f(100.f, 100.f));
}

const sf::Sprite& TowerMenuButton::getSprite() const {  // Cambiado a const
	return _sprite;
}

void TowerMenuButton::setTexture(std::string path)
{
	if (!_texture.loadFromFile(path))
	{
		std::cout << "Loading error. " << std::endl;
	}

	_sprite.setTexture(_texture);
}

//void TowerMenuButton::isMouseOver()
//{
//	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
//
//	std::cout << "POS X: " << mousePosition.x << "POS Y: " << mousePosition.y << std::endl;
//
//
//}

void TowerMenuButton::update()
{
	//isMouseOver();
}

void TowerMenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}
