#include <SFML/Graphics.hpp>
#include "TowerMenu.h"
#include "TowerMenuButton.h"

sf::Texture TowerMenuButton::_texture;
sf::Texture TowerMenuButton::_textureHover;

Tower TowerMenuButton::getTower() { return *_tower; }

int TowerMenuButton::getBtnNumber() { return _btnNumber; }

void TowerMenuButton::update(sf::Vector2i& mousePosition)
{
	//sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(sf::Vector2f(mousePosition));
	//	getGlobalBounds().contains(transformedMousePos) ? setMouseHover(true) : setMouseHover(false);
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
	//	target.draw(_spriteHover, states);
	}
}

//sf::FloatRect TowerMenuButton::getGlobalBounds() const {
//	sf::FloatRect bounds1 = getTransform().transformRect(_sprite.getGlobalBounds());
//	sf::FloatRect bounds2 = getTransform().transformRect(_spriteHover.getGlobalBounds());
//
//	sf::FloatRect combinedBounds = bounds1;
//	combinedBounds.left = std::min(bounds1.left, bounds2.left);
//	combinedBounds.top = std::min(bounds1.top, bounds2.top);
//	combinedBounds.width = std::max(bounds1.left + bounds1.width, bounds2.left + bounds2.width) - combinedBounds.left;
//	combinedBounds.height = std::max(bounds1.top + bounds1.height, bounds2.top + bounds2.height) - combinedBounds.top;
//
//	return combinedBounds;
//}

sf::FloatRect TowerMenuButton::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds()); 
}
