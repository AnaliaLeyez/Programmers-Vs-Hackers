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

void MenuAbstract::setNumberMenu(int idMenu)
{
		if (_currentMenu != nullptr) {
			delete _currentMenu;
		}
		switch (idMenu)
		{
		case 1:
			_currentMenu = new MenuHome();
			break;
		case 2:
			_currentMenu = new MenuLevels();
			break;
		default:
			break;
		}
}

void MenuAbstract::validateClick(int mousex, int mousey, sf::RenderWindow& window, int& view)
{
	_currentMenu->validateClick(mousex, mousey, window, view);
}

MenuAbstract::MenuAbstract(int idMenu) : _currentMenu(nullptr) {
	setNumberMenu(idMenu);
}

void MenuAbstract::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(*_currentMenu, states);
}
void MenuAbstract::update() {
	_currentMenu->update();
}