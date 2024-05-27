#pragma once
#include "Spot.h"
#include "TowerMenuButton.h"
class TowerMenu : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isVisible;
	std::string _pathTextures[4];
	TowerMenuButton* _buttons[4];
	Spot _currentSpot;
public:
	TowerMenu();
	bool getIsVisible();
	const TowerMenuButton* getButtons() const;
	Spot getCurrentSpot() const;
	void setCurrentSpot(Spot);
	void hide();
	void show();
	void validateClickOnButton(int, int, Spot*);
	bool validateSale(TowerMenuButton*, Spot*);
	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
