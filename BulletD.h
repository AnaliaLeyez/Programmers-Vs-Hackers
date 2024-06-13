#pragma once
class BulletD : public Bullet
{
public:
	BulletD(sf::Vector2f, sf::Vector2f, int);
	void update1BulletD();
	void update2BulletD();

	void loadTexture() override;

};
