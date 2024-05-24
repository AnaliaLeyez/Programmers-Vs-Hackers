#include <SFML/Graphics.hpp>

#include "Spot.h"

Spot::Spot()
{
    _mouseHover = false;
	if (!_textureA.loadFromFile("img/maps/spot_martillo.png")) {
		throw std::runtime_error("Error img Torre Brian");
	}
	_spriteA.setTexture(_textureA);
	_spriteA.setOrigin(_spriteA.getGlobalBounds().width / 2, _spriteA.getGlobalBounds().height / 2);

	if (!_textureB.loadFromFile("img/maps/spot_martillo_hover.png")) {
		throw std::runtime_error("Error img Torre Brian");
	}
	_spriteB.setTexture(_textureB);
	_spriteB.setOrigin(_spriteB.getGlobalBounds().width / 2, _spriteB.getGlobalBounds().height / 2);
	_occupied = false;
}

int Spot::getSpotNumber(){ return 0; }

void Spot::setSpotNumber(int n){ _spotNumber = n; }

sf::Vector2f Spot::getPosition(){ return _position; }

bool Spot::getIsOccupied(){ return _occupied; }

Tower Spot::getCurrentTower(){ return _currentTower; }

void Spot::setPosition(sf::Vector2f pos){ _position = pos; }

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
    _mouseHover ? target.draw(_spriteB, states) : target.draw(_spriteA, states);
}