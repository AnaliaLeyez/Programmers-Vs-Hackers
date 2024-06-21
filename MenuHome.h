#pragma once
#include "Menu.h"

class MenuHome : public Menu
{
private:
	sf::Text _text[5];
public:
	MenuHome(bool state);
	sf::Text getText1() const;
	sf::Text getText2() const;
	sf::Text getText3() const;
	sf::Text getText4() const;
	sf::Text getText5() const;

	void validateClick(int, int, sf::RenderWindow&, int&) override;
	bool getMusicPlaying() const;
	sf::Sound getSound() const;
	void setSoundText(bool);

	void update() {}
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};