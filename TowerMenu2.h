#pragma once
#include "Tower.h"
class TowerMenu2 : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isVisible;
	std::vector <Button*> _buttons;
	Spot _currentSpot;  //el spot por el cual se muestra el menu en ese momento
public:
	TowerMenu2();
	bool getIsVisible();
	const std::vector <Button*> getButtons() const;
	Button* getButtonByIndex(int) const;
	Spot getCurrentSpot() const;
	void setCurrentSpot(Spot);
	void setButton(bool , int);
	void hide();
	void show();
	void mouseCheck(sf::Vector2i&);
	Button* validateClickOnButton(int, int, Spot&);
	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};

