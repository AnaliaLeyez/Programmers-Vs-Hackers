#pragma once
#include "Collisionable.h"
#include <SFML/Graphics.hpp>

class Bullet : public Collisionable, public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::Vector2f _direction;
	sf::Vector2f _velocity;
	
	int _damage;
	float _speed;
	sf::Vector2f _enemyPosition;

public:
	//virtual void upgrade() = 0;

	virtual ~Bullet() {};

	virtual void moveToward();
	virtual void loadTexture() = 0;

	virtual sf::Vector2f getDirection() const;
	virtual sf::Vector2f getVelocity() const;
	sf::Vector2f getEnemyPosition() const;

	virtual int getDamage() const;
	virtual void setDirection(sf::Vector2f);
	virtual void setVelocity(sf::Vector2f);
	virtual void setDamage(int);

	void setEnemyPosition(sf::Vector2f);

	virtual sf::FloatRect getBounds() const;
	virtual void update();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};
