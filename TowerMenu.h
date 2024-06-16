#pragma once
#include "Spot.h"
#include "Button.h"
class TowerMenu : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isVisible;
	std::vector <Button*> _buttons;
	Spot _currentSpot; //DEBERIA SER PUNTERO
	int _NumberMenu;
public:
	bool getIsVisible();
	Button* getButtonByIndex(int) const;
	Spot getCurrentSpot() const; //DEBERIA SER PUNTERO
	int getNumberMenu() const;
	void setCurrentSpot(Spot);
	void setButton(bool, int);

	void hide();
	void show();

	void mouseCheck(sf::Vector2i&);
	Button* validateClickOnButton(int, int, Spot&);
	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
