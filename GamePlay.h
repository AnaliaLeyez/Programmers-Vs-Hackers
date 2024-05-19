#pragma once
#include <iostream>
#include <list>
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
	Tower _tower;
	std::list<Hacker> _hackers;
	std::list<Bullet> _bullets;
public:
	static GamePlay& getInstance();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void shoot(sf::Vector2f position);
	void validateClickOnMap(int mousex, int mousey, Map &mapa);
	void validateClickOnMenu(int mousex, int mousey, Menu &menu, sf::RenderWindow& window,int &vista);
};

