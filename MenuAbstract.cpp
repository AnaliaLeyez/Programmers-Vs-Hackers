#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MenuAbstract.h"

MenuAbstract* MenuAbstract::_currentInstance = nullptr;

MenuAbstract& MenuAbstract::getInstance() {
	if (MenuAbstract::_currentInstance == nullptr) {
		MenuAbstract::_currentInstance = new MenuAbstract();
	}
	return *MenuAbstract::_currentInstance;
}

MenuAbstract::MenuAbstract() {
	_menu = new Menu();
}

void MenuAbstract::validateClick(int mousex, int mousey, sf::RenderWindow& window, int& view)
{
	if (_menu->getText1().getGlobalBounds().contains(mousex, mousey)) {
		_menu->setSound(false);
		_menu->setMusicPlaying(false);
		view = 2;
	}
	else if (_menu->getText4().getGlobalBounds().contains(mousex, mousey)) {
		if (_menu->getMusicPlaying()) {
			_menu->setSound(false);
			_menu->setMusicPlaying(false);
		}
		else {
			_menu->setSound(true);
			_menu->setMusicPlaying(true);
		}
	}
	if (_menu->getText5().getGlobalBounds().contains(mousex, mousey)) {
		window.close();
	}
}

void MenuAbstract::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(*_menu, states);
}
void MenuAbstract::update() {
	_menu->update();
}