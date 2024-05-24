#pragma once
#include "Tower.h"
class TowerBrian : public Tower
{
public:
	//Constructor
	TowerBrian(sf::Vector2f position= { 0.f,0.f });

	//Comportamiento bélico
	void update1();
};

