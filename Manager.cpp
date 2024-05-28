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
	setNumberLevel(level);
}

Level Manager::getLevel() const { return *_currentLevel; }

void Manager::setLevel(Level& level)
{
	*_currentLevel = level;
}

void Manager::setNumberLevel(int IdLevel) {
	if (_currentLevel != nullptr) {
		delete _currentInstance;
	}
	switch (IdLevel)
	{
	case 1:
		_currentLevel = new Level1();
		_currentLevel->getHackerStartPosition(); //ver como el manager informa a la oleada desde donde empezar
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
	setLevel(*_currentLevel);
}
void Manager::mouseCheck(sf::Vector2i& mousePosition)
{
	_currentLevel->mouseCheck(mousePosition);
}
void Manager::update(sf::Vector2i& mousePosition)
{
	_currentLevel->update(mousePosition);
}

void Manager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_currentLevel, states);
}