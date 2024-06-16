#pragma once
#include "Tower.h"
class TowerWenner : public Tower
{
public:
	TowerWenner();
	Tower* clone() const override { return new TowerWenner(*this); }
	void upgrade()override;
	//void setBullet(sf::Vector2f, sf::Vector2f) override;
};


