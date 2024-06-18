#pragma once
#include "Menu.h"

class MenuLevels : public Menu
{
private:
	sf::Text _text[5];
public:
	MenuLevels();
	sf::Text getText1() const;
	sf::Text getText2() const;
	sf::Text getText3() const;
	sf::Text getText4() const;
	sf::Text getText5() const;

	void validateClick(int, int, sf::RenderWindow&, int&) override;

	void update() {}
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};