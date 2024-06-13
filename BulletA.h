#pragma once
#include "Bullet.h"

class BulletA : public Bullet
{
public:
	BulletA(sf::Vector2f, sf::Vector2f, int);
	void update1BulletA();
	void update2BulletA();

	void loadTexture() override;

};

