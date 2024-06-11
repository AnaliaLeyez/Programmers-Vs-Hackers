#pragma once
#include "Tower.h"
class TowerKloster : public Tower
{
public:
	TowerKloster();
	Tower* clone() const override { return new TowerKloster(*this); }
	void upgrade() override;
	void setBullet(sf::Vector2f, sf::Vector2f) override;
};
