#pragma once
#include "Bullet.h"
class BulletBrian : public Bullet
{
public:
	//BulletBrian(sf::Vector2f, sf::Vector2f);
	BulletBrian(sf::Vector2f, sf::Vector2f);
	void upgrade() override;
};

