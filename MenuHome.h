#pragma once
#include "Menu.h"

class MenuHome : public Menu
{
public:
	MenuHome();
	void validateClick(int, int, sf::RenderWindow&, int&) override;
	void setSoundText(bool);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};