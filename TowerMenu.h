#pragma once
#include "Spot.h"
#include "Button.h"
class TowerMenu : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isVisible;
	Button* _buttons[4];
	Spot _currentSpot;  //el spot por el cual se muestra el menu en ese momento
public:
	TowerMenu();
	bool getIsVisible();
	const Button* getButtons() const;
	Button* getButtonByIndex(int i) const;
	Spot getCurrentSpot() const;
	void setCurrentSpot(Spot);
	void setButton(bool, int);
	void hide();
	void show();
	void mouseCheck(sf::Vector2i&);
	Button validateClickOnButton(int, int, Spot&);
	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
