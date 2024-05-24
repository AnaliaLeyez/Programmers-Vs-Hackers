#pragma once
#include "Tower.h"
class Spot : public sf::Drawable
{
private:
	sf::Texture _textureA, _textureB;
	sf::Sprite _spriteA, _spriteB;
	int _spotNumber;
	sf::Vector2f _position;
	bool _occupied;
	Tower _currentTower;
	bool _mouseHover;
public:
	Spot();
	int getSpotNumber();
	void setSpotNumber(int);
	sf::Vector2f getPosition();
	bool getIsOccupied();
	Tower getCurrentTower();
	void setPosition(sf::Vector2f);
	void setOccupied(bool);
	void setCurrentTower(Tower);
	void validateMouseHover(bool&);
	void validateClick(int, int);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

