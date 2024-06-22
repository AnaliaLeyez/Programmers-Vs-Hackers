#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MenuHome.h"
#include "MenuLevels.h"
#include "MenuInfo.h"
#include "MenuAbstract.h"

MenuAbstract* MenuAbstract::_currentInstance = nullptr;

MenuAbstract& MenuAbstract::getInstance() {
	if (MenuAbstract::_currentInstance == nullptr) {
		MenuAbstract::_currentInstance = new MenuAbstract();
	}
	return *MenuAbstract::_currentInstance;
}
//Menu* MenuAbstract::getCurrentMenu() const {
//	return _currentMenu;
//}
MenuAbstract::MenuAbstract(int idMenu) : _currentMenu(nullptr) {
	setNumberMenu(idMenu);
}

void MenuAbstract::setNumberMenu(int idMenu)
{
	bool state;
	switch (idMenu)
	{
	case 1:
		if (_currentMenu != nullptr) {
			state = _currentMenu->getMusicPlaying();
			_currentMenu = new MenuHome(state);
		}
		else {
			_currentMenu = new MenuHome(true);
			_currentMenu->setSound(true);
		}
		break;
	case 2:
	{
		state = _currentMenu->getMusicPlaying();
		_currentMenu = new MenuLevels(state);
	}
	break;
	case 3:
	{
		state = _currentMenu->getMusicPlaying();
		_currentMenu = new MenuInfo(state);
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



//void MenuAbstract::saveSoundPosition() {
//	if (_currentMenu) {
//		_soundPosition = _currentMenu->getSoundPosition();
//	}
//}
//
//void MenuAbstract::restoreSoundPosition() {
//	if (_currentMenu) {
//		_currentMenu->setSoundPosition(_soundPosition);
//	}
//}
//void MenuAbstract::stopMusic() {
//	if (_currentMenu) {
//		_currentMenu->setSound(false);
//		_currentMenu->setMusicPlaying(false);
//	}
//}
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
//void MenuAbstract::update() {
//	_currentMenu->update();
//}