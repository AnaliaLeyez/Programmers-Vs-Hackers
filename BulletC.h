#pragma once
class BulletC : public Bullet
{
public:
	BulletC(sf::Vector2f, sf::Vector2f, int);
	void update1BulletC();
	void update2BulletC();

	void loadTexture() override;

};
