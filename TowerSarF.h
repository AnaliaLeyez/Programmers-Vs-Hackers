#pragma once
#include "Tower.h"
class TowerSarF : public Tower
{
public:
	TowerSarF();
	Tower* clone() const override { return new TowerSarF(*this); }
	void upgrade() override;
	void setBullet(sf::Vector2f, sf::Vector2f) override;
};

