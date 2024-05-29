#pragma once
#include <iostream>
#include "Level.h"

class Manager : public sf::Drawable
{
private:
	Manager(int level=1); //Singleton
	static Manager* _currentInstance; //Singleton
	Level *_currentLevel;
public:
	static Manager& getInstance(); //Singleton
	static void setInstance(Manager&);
	Level getLevel() const;
	void setLevel(Level&);
	void setNumberLevel(int);
	void validateClick(int, int, sf::RenderWindow&);
	void mouseCheck(sf::Vector2i&);
	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

