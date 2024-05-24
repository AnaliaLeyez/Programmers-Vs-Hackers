#pragma once
#include "Tower.h"
class TowerWenner : public Tower
{
public:
	//Constructor
	TowerWenner(sf::Vector2f position = { 0.f,0.f });

	//Comportamiento bélico
	void update1();
};


