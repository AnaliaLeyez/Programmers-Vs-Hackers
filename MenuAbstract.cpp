#include <SFML/Graphics.hpp>

#include <iostream>
#include "Menu.h"
#include "MenuHome.h"
#include "MenuLevels.h"
#include "MenuInfo.h"
#include "MenuAbstract.h"
#include "SoundManager.h"

MenuAbstract* MenuAbstract::_currentInstance = nullptr;

MenuAbstract& MenuAbstract::getInstance() {
	if (MenuAbstract::_currentInstance == nullptr) {
		MenuAbstract::_currentInstance = new MenuAbstract();
	}
	return *MenuAbstract::_currentInstance;
}

MenuAbstract::MenuAbstract(int idMenu) : _currentMenu(nullptr) {
	setNumberMenu(idMenu);
}

void MenuAbstract::setNumberMenu(int idMenu)
{
	SoundManager& _soundManger = SoundManager::getInstance();

	switch (idMenu)
	{
	case 1:
		if (_currentMenu != nullptr)
		{
			_currentMenu = new MenuHome();
		}
		else
		{
			_currentMenu = new MenuHome();
		}
		break;
	case 2:
	{
		_currentMenu = new MenuLevels();
	}
	break;
	case 3:
	{
		_currentMenu = new MenuInfo();
	}
	break;
	default:
		break;
	}
}

void MenuAbstract::validateClick(int mousex, int mousey, sf::RenderWindow& window, int& view)
{
	_currentMenu->validateClick(mousex, mousey, window, view);
}



void MenuAbstract::update(sf::Vector2i& mousePosition)
{
	_currentMenu->update(mousePosition);
}


void MenuAbstract::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(*_currentMenu, states);
}
MenuAbstract::~MenuAbstract()
{
	//if (_currentMenu) {
	//	delete _currentMenu; // Eliminar el menú actual
	//	_currentMenu = nullptr;
	//}
}