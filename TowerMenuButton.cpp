#include <SFML/Graphics.hpp>
#include "TowerMenu.h"
#include "TowerMenuButton.h"


Tower TowerMenuButton::getTower() { return *_tower; }

int TowerMenuButton::getPrice()
{
	return _tower->getPrice();
}

int TowerMenuButton::getBtnNumber() { return _btnNumber; }

void TowerMenuButton::update(sf::Vector2i& mousePosition)
{
}
void TowerMenuButton::setBtnNumber(int n) { _btnNumber = n; }
void TowerMenuButton::setPrice()
{
	if (!_textureBgPrice.loadFromFile("img/menuContextual/priceBg.png")) {
		throw std::runtime_error("Error al cargar img Oro");
	}
	_spriteBgPrice.setTexture(_textureBgPrice);
	_spriteBgPrice.setPosition(-10, 40);
	
	if (!_font.loadFromFile("fuentes/TowerPrice.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Menu \n");
	}
	_price.setFont(_font);
	_price.setCharacterSize(30);
	_price.setPosition(-10, 40);
	_price.setFillColor(sf::Color(255, 255, 255));
}
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
	target.draw(_spriteBgPrice, states);
	target.draw(_sprite, states);
	if (_mouseHover) {
		target.draw(_spriteHover, states);
	}
	
	target.draw(_price, states);
}

sf::FloatRect TowerMenuButton::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds()); 
}
