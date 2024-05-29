#pragma once
#include "Spot.h"
#include "TowerMenuButton.h"
class TowerMenu : public sf::Drawable, public sf::Transformable
{
protected:
	TowerMenu(); //Singleton
	static TowerMenu* _currentInstance; //Singleton
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isVisible;
	std::string _pathTextures[4];
	TowerMenuButton* _buttons[4];
	Spot *_currentSpot;  //el spot por el cual se muestra el menu en ese momento
public:
	static TowerMenu& getInstance(); //Singleton
	//static void setInstance(TowerMenu&);
	bool getIsVisible();
	const TowerMenuButton* getButtons() const;
	TowerMenuButton* getButtonByIndex(int i) const;
	Spot getCurrentSpot() const;
	void setCurrentSpot(Spot&);
	void setButton(bool states, int i){ _buttons[i]->setMouseHover(states); }
	void hide();
	void show();
	void validateClickOnButton(int, int, Spot*);
	bool validateSale(TowerMenuButton*);
	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
