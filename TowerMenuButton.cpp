#include <SFML/Graphics.hpp>
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
void TowerMenuButton::setMouseHover(bool state) {
	_mouseHover = state;
}
void TowerMenuButton::setSpriteHover()
{
	if (!_textureHover.loadFromFile("img/menuContextual/button_tower_menu_hover.png"))
	{
		throw std::runtime_error("Error img button Hover");
	}
	_spriteHover.setTexture(_textureHover);
	_spriteHover.setScale(0.7f, 0.7f);
	_spriteHover.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}
void TowerMenuButton::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
	if (_mouseHover) {
		target.draw(_spriteHover, states);
	}
}

sf::FloatRect TowerMenuButton::getGlobalBounds() const { return getTransform().transformRect(_sprite.getGlobalBounds()); }
