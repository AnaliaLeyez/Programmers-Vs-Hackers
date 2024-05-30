#include <SFML/Graphics.hpp>
#include "TowerMenu.h"
#include "TowerMenuButton.h"


Tower TowerMenuButton::getTower() { return *_tower; }

int TowerMenuButton::getBtnNumber() { return _btnNumber; }

void TowerMenuButton::update(sf::Vector2i& mousePosition)
{
}
void TowerMenuButton::setBtnNumber(int n) { _btnNumber = n; }
void TowerMenuButton::setMouseHover(bool state) { _mouseHover = state; }
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

sf::FloatRect TowerMenuButton::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds()); 
}
