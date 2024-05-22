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
	Level getLevel() const;
	void setLevel(int);
	void validateClickRight(int, int);
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

