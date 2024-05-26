#include <SFML/Graphics.hpp>

#include "Spot.h"

sf::Texture Spot::_textureA;
sf::Texture Spot::_textureB;

Spot::Spot()
{
	_spotNumber = 0;
	_currentTower.setPrice(0);
    _mouseHover = false;
	if (!_textureA.loadFromFile("img/maps/spot_martillo.png")) {
		throw std::runtime_error("Error img Torre Brian");
	}
	_spriteA.setTexture(_textureA);
	_spriteA.setOrigin(_spriteA.getGlobalBounds().width / 2, _spriteA.getGlobalBounds().height / 2);
	_spriteA.setScale(1.5f, 1.5f);
	if (!_textureB.loadFromFile("img/maps/spot_martillo_hover.png")) {
		throw std::runtime_error("Error img Torre Brian");
	}
	_spriteB.setTexture(_textureB);
	_spriteB.setOrigin(_spriteB.getGlobalBounds().width / 2, _spriteB.getGlobalBounds().height / 2);
	_spriteB.setScale(1.5f, 1.5f);
	_occupied = false;
}

//sf::Sprite Spot::getSprite()   //para mi que esta mal
//{
//	if (_mouseHover) return _spriteB;
//	else return _spriteA;
//}

int Spot::getSpotNumber(){ return _spotNumber; }

void Spot::setSpotNumber(int n){ _spotNumber = n; }

bool Spot::getIsOccupied(){ return _occupied; }

Tower Spot::getCurrentTower(){ return _currentTower; }

void Spot::setOccupied(bool status){ _occupied = status; }

void Spot::setCurrentTower(Tower tower){ _currentTower = tower; }

void Spot::validateMouseHover(bool &_mouseHover)
{
}

void Spot::validateClick(int mousex, int mousey)
{
}

void Spot::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
    _mouseHover ? target.draw(_spriteB, states) : target.draw(_spriteA, states);
}

sf::FloatRect Spot::getGlobalBounds() const {
	return getTransform().transformRect(_spriteA.getGlobalBounds());
}