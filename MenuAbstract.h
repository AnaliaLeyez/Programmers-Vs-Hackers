#pragma once

class MenuAbstract : public sf::Drawable
{
private:
	MenuAbstract(); //Singleton
	static MenuAbstract* _currentInstance; //Singleton
	Menu* _menu;
public:
	static MenuAbstract& getInstance(); //Singleton
	void validateClick(int, int, sf::RenderWindow&, int&);
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};