#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Level1.h"
#include "Manager.h"

Manager* Manager::_currentInstance = nullptr;

Manager::Manager(int level) {
	setLevel(level);  //en cuanto hago esto, es decir, en cuanto especifico que sea nivel1, se rompe
}
Manager& Manager::getInstance() {
	if (Manager::_currentInstance == nullptr) {
		Manager::_currentInstance = new Manager(); //el Manage nace con nivel=1
	}
	return *Manager::_currentInstance;
}
Level Manager::getLevel() const { return *_currentLevel; }

void Manager::setLevel(int IdLevel) { //aca se cambia de un nivel a otro, eliminando siempre el anterior para liberar memoria
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

void Manager::update()
{
	_currentLevel->update();
}

void Manager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_currentLevel, states);
}
