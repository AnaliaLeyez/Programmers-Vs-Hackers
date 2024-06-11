#include <SFML/Graphics.hpp>
#include "Button.h"


Tower* Button::getTower() const { return _tower->clone(); }
int Button::getPrice() { return _tower->getPrice(); }
int Button::getDamage() { return _tower->getDamage(); }
int Button::getBtnNumber() { return _btnNumber; }
int Button::getPrice() const { return _price; }

void Button::setBtnNumber(int n) { _btnNumber = n; }
void Button::setPriceText()
{
	if (!_textureBgPrice.loadFromFile("img/menuContextual/priceBg.png")) {
		throw std::runtime_error("Error al cargar img Oro");
	}
	_spriteBgPrice.setTexture(_textureBgPrice);
	_spriteBgPrice.setTexture(_textureBgPrice);
	_spriteBgPrice.setOrigin(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height / 2);
	_spriteBgPrice.setPosition(0, -50);
	
	if (!_font.loadFromFile("fuentes/TowerPrice.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Price Menu \n");
	}
	_priceText.setFont(_font);
	_priceText.setCharacterSize(30);
	_priceText.setOrigin(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height / 2);
	_priceText.setPosition(5, -54);
	_priceText.setFillColor(sf::Color(255, 255, 255));
	_priceText.setString("$" + std::to_string(getPrice()));
}
void Button::setInfo()
{
	if (!_textureBgInfo.loadFromFile("img/menuContextual/priceBg.png")) {
		throw std::runtime_error("Error al cargar Background de Info/precio");
	}
	_spriteBgInfo.setTexture(_textureBgInfo);
	_spriteBgInfo.setOrigin(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height / 2);
	_spriteBgInfo.setPosition(-10, 80);
	_spriteBgInfo.setScale(1.5, 1.5);

	if (!_textureSword.loadFromFile("img/menuContextual/sword.png")) {
		throw std::runtime_error("Error al cargar img Oro");
	}
	_spriteSword.setTexture(_textureSword);
	_spriteSword.setOrigin(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height / 2);
	_spriteSword.setPosition(-25, 75);
	_spriteSword.setScale(0.4f, 0.4f);
	

	if (!_font.loadFromFile("fuentes/TowerPrice.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Info Menu \n");
	}

	for (int i = 0; i < 1; i++) {
		_info[i].setFont(_font);
		_info[i].setCharacterSize(30);
		_info[i].setOrigin(_sprite.getGlobalBounds().left + _sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().top + _sprite.getGlobalBounds().height / 2);
		_info[i].setPosition(15, 70);
		_info[i].setFillColor(sf::Color(255, 255, 255));
		_info[i].setString(std::to_string(getDamage()));
		
	}

}
void Button::setMouseHover(bool state) { _mouseHover = state; }
void Button::setSpriteHover()
{
	if (!_textureHover.loadFromFile("img/menuContextual/button_tower_menu_hover.png"))
	{
		throw std::runtime_error("Error img button Hover");
	}
	_spriteHover.setTexture(_textureHover);
	_spriteHover.setScale(0.7f, 0.7f);
	_spriteHover.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}
void Button::setPrice(int price) { _price = price; }

void Button::update(sf::Vector2i& mousePosition)
{
}
void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
	target.draw(_spriteBgPrice, states);	
	target.draw(_priceText, states);
	if (_mouseHover) {
		target.draw(_spriteBgInfo, states);
		target.draw(_spriteHover, states);
		for (int i = 0; i < 1; i++) {
			target.draw(_spriteSword, states);
			target.draw(_info[i], states);
		}
	}
	
}

sf::FloatRect Button::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds()); 
}
