#pragma once
#include "Menu.h"

class MenuHome : public Menu
{
private:
	sf::Text _text[5];
public:
	MenuHome();
	sf::Text getText1() const;
	sf::Text getText2() const;
	sf::Text getText3() const;
	sf::Text getText4() const;
	sf::Text getText5() const;

	void validateClick(int, int, sf::RenderWindow&, int&) override;
	//void validateClick(int, int, Menu&, sf::RenderWindow&, int&);
	bool getMusicPlaying() const;
	void setMusicPlaying(bool);
	sf::Sound getSound() const;
	void setSound(bool);

	void update() {}
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};