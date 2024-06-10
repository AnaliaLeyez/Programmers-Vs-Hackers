#pragma once
#include "Tower.h"
class TowerKloster : public Tower
{
public:
	TowerKloster();
	void upgrade() override;
	void resell() override;
	void setBullet(sf::Vector2f, sf::Vector2f) override;
};
