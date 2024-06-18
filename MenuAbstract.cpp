#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MenuHome.h"
#include "MenuLevels.h"
#include "MenuAbstract.h"

MenuAbstract* MenuAbstract::_currentInstance = nullptr;

MenuAbstract& MenuAbstract::getInstance() {
	if (MenuAbstract::_currentInstance == nullptr) {
		MenuAbstract::_currentInstance = new MenuAbstract();
	}
	return *MenuAbstract::_currentInstance;
}

void MenuAbstract::validateClick(int mousex, int mousey, sf::RenderWindow& window, int& view)
{
	_menu->validateClick(mousex, mousey, window, view);
}

MenuAbstract::MenuAbstract() {
	_menu = new MenuHome();
	//_menu = new MenuLevels();
}

void MenuAbstract::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(*_menu, states);
}
void MenuAbstract::update() {
	_menu->update();
}