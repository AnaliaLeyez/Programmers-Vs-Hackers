#pragma once
class BulletB : public Bullet
{
public:
	BulletB(sf::Vector2f, sf::Vector2f, int);
	void update1BulletB();
	void update2BulletB();

	void loadTexture() override;

};