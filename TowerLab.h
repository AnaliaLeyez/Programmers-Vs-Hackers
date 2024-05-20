#pragma once

class TowerLab : public Tower
{
public:
	//Constructor
	TowerLab(sf::Vector2f position= { 0.f,0.f });

	//Comportamiento bélico
	void updateLabo2();
};

