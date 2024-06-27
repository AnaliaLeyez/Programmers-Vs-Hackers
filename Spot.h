#pragma once
#include "Tower.h"
class Spot : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Texture _textureA, _textureB;
	sf::Sprite _spriteA, _spriteB;
	int _spotNumber;
	bool _occupied;
	Tower* _currentTower;
	bool _mouseHover;
public:
	Spot();
	
	int getSpotNumber() const;
	bool getIsOccupied() const;
	Tower* getCurrentTower() const;
	bool getMouseHover() const;

	void setSpot(int, bool);
	void setSpotNumber(int);
	void setMouseHover(bool);
	void setOccupied(bool);
	void setCurrentTower(Tower*);

	void mouseCheck(sf::Vector2f&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
	void clearCurrentTower();

	~Spot();
};

