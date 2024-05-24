#include <SFML/Graphics.hpp>
#include <iostream>
#include "TowerMenuButton.h"

//void TowerMenuButton::isMouseOver()
//{
//	sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
//
//	std::cout << "POS X: " << mousePosition.x << "POS Y: " << mousePosition.y << std::endl;
//
//}

Tower TowerMenuButton::getTower()
{
	return *_tower;
}

void TowerMenuButton::update()
{
	//isMouseOver();
}

void TowerMenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}
