#pragma once
#include "Tower.h"
class Spot : public sf::Drawable, public sf::Transformable
{
protected:
	static sf::Texture _textureA, _textureB;
	sf::Sprite _spriteA, _spriteB;
	int _spotNumber;
	bool _occupied;
	Tower _currentTower;
	bool _mouseHover;
public:
	Spot();
	int getSpotNumber();
	void setSpotNumber(int);
	bool getIsOccupied();
	Tower getCurrentTower();
	void setOccupied(bool);
	void setCurrentTower(Tower);
	void validateMouseHover(bool&);
	void validateClick(int, int);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

