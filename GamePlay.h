#pragma once
#include <iostream>
#include <list>
#include "Level.h"
#include "Level1.h"
#include "Tower.h"
#include "Bullet.h"
#include "Hacker.h"
#include "Map.h"
#include "Menu.h"

class GamePlay : public sf::Drawable
{
private:
	GamePlay();
	static GamePlay* _currentInstance;
	Level _level;
	Tower _tower;
	std::list<Hacker> _hackers;
	std::list<Bullet> _bullets;
public:
	static GamePlay& getInstance();
	Level getLevel();
	//void setLevel(Level level = Level1()); //este funciona
	void setLevel(int);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void shoot(sf::Vector2f position);
	void validateClick(int mousex, int mousey);
	//void validateClickOnMap(int mousex, int mousey, Map &mapa);
	//void validateClickOnMenu(int mousex, int mousey, Menu &menu, sf::RenderWindow& window,int &vista);
};

