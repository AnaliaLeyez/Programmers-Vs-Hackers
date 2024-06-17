#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Level1.h"
#include "Level2.h"
#include "Manager.h"

Manager* Manager::_currentInstance = nullptr;

Manager& Manager::getInstance() {
	if (Manager::_currentInstance == nullptr) {
		Manager::_currentInstance = new Manager(); //el Manager nace con nivel=1
	}
	return *Manager::_currentInstance;
}

//void Manager::setInstance(Manager& mg)
//{
//	if (Manager::_currentInstance == nullptr) {
//		Manager::_currentInstance = new Manager();
//	}
//	*_currentInstance = mg;
//}

Manager::Manager(int level): _currentLevel(nullptr) {
	setNumberLevel(level);
}

Level* Manager::getLevel() const { return _currentLevel; }

void Manager::setLevel(Level& level)
{
	*_currentLevel = level;
}

void Manager::setNumberLevel(int IdLevel) {
	if (_currentLevel != nullptr) {
		delete _currentLevel;
	}
	switch (IdLevel)
	{
	case 1:
		 _currentLevel = new Level1();
		break;
	case 2:
		_currentLevel = new Level2();
		break;
	default:
		break;
	}
}

void Manager::validateClick(int mousex, int mousey, sf::RenderWindow& window) {
	_currentLevel->validateClick(mousex, mousey);
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

Manager::~Manager()
{
	//delete _currentLevel;
}
