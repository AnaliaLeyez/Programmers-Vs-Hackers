#pragma once
#include "Tower.h"
class TowerSarF : public Tower
{
public:
	TowerSarF();
	void upgrade() override;
	void resell() override;
	void setBullet(sf::Vector2f, sf::Vector2f) override;
};

