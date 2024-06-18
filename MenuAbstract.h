#pragma once
#include "Menu.h"
class MenuAbstract : public sf::Drawable
{
private:
	MenuAbstract(int idMenu=1); //Singleton
	static MenuAbstract* _currentInstance; //Singleton
	Menu* _currentMenu;
public:
	static MenuAbstract& getInstance(); //Singleton
	void setNumberMenu(int);
	void validateClick(int, int, sf::RenderWindow&, int&);
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};