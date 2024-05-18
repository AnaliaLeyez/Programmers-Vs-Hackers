#pragma once
class Collisionable
{
private:
public:
	virtual sf::FloatRect getBounds() const = 0;
	bool collided(Collisionable&) const;
};

