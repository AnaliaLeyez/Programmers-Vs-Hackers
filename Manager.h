#pragma once
#include <iostream>
#include "Level.h"

class Manager : public sf::Drawable
{
private:
	Manager(int level=1); //Singleton
	static Manager* _currentInstance; //Singleton
	//atributos:
	Level *_currentLevel;
	//Tower _tower;
	//std::list<Hacker> _hackers;
	//std::list<Bullet> _bullets;
public:
	static Manager& getInstance(); //Singleton
	Level getLevel() const;
	void setLevel(int);
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	//void shoot(sf::Vector2f position); // esto es algo del nivel?
	void validateClick(int mousex, int mousey);
	//void validateClickOnMap(int mousex, int mousey, Map &mapa);
	//void validateClickOnMenu(int mousex, int mousey, Menu &menu, sf::RenderWindow& window,int &vista);
};

