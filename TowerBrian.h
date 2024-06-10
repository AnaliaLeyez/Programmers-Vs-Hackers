#pragma once
#include "Tower.h"
class TowerBrian : public Tower
{
public:
	TowerBrian();
	void upgrade() override;
	void setBullet(sf::Vector2f, sf::Vector2f) override;
};

