#pragma once
#include "Tower.h"
class TowerSarF : public Tower
{
public:
	//Constructor
	TowerSarF(sf::Vector2f position = { 0.f,0.f });

	//Comportamiento bélico
	void update1();
};

