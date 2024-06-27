#pragma once
#include "Menu.h"
class MenuAbstract : public sf::Drawable
{
private:
	MenuAbstract(int idMenu=1); //Singleton
	static MenuAbstract* _currentInstance; //Singleton
	Menu* _currentMenu;
	//float _soundPosition;
public:
	static MenuAbstract& getInstance(); //Singleton
	//Menu* getCurrentMenu() const;
	void setNumberMenu(int);
	void validateClick(int, int, sf::RenderWindow&, int&);

	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	~MenuAbstract();
};