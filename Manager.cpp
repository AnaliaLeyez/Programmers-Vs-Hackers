#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Level1.h"
#include "Manager.h"

Manager* Manager::_currentInstance = nullptr;

Manager& Manager::getInstance() {
	if (Manager::_currentInstance == nullptr) {
		Manager::_currentInstance = new Manager(); //el Manager nace con nivel=1
	}
	return *Manager::_currentInstance;
}

Manager::Manager(int level) {
	setLevel(level);
}

Level Manager::getLevel() const { return *_currentLevel; }

void Manager::setLevel(int IdLevel) {
	if (_currentLevel != nullptr) {
		delete _currentInstance;
	}
	switch (IdLevel)
	{
	case 1:
		_currentLevel = new Level1();
		break;
	case 2:
		//_currentLevel = new Level2();
		break;
	default:
		break;
	}
}

void Manager::validateClick(int mousex, int mousey, sf::RenderWindow& window) {
	_currentLevel->validateClick(mousex, mousey);
}
void Manager::mouseCheck(sf::RenderWindow& window)
{
	_currentLevel->mouseCheck(window);
}
void Manager::update()
{
	_currentLevel->update();
}

void Manager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_currentLevel, states);
}