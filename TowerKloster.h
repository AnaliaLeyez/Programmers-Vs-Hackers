#pragma once
#include "Tower.h"
class TowerKloster : public Tower
{
public:
	//Constructor
	TowerKloster(sf::Vector2f position = { 0.f,0.f });

	//Comportamiento bélico
	void update1();
};
