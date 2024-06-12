﻿#pragma once
#include "Collisionable.h"
#include <SFML/Graphics.hpp>
class Bullet : public Collisionable, public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	//static sf::Texture _texture;
	sf::Texture _texture;
	sf::Vector2f _direction;
	sf::Vector2f _velocity;
	
	int _damage;
	float _speed;
	sf::Vector2f _enemyPosition;

public:
	virtual void upgrade() = 0;

	sf::CircleShape _collisionCircle;
	Bullet(sf::Vector2f initialPosition = { 100,100 }, sf::Vector2f target = { 300,300 }); //ADRI
	void moveToward();

	sf::Vector2f getDirection() const;
	sf::Vector2f getVelocity() const;
	sf::Vector2f getEnemyPosition() const;

	int getDamage() const;
	void setDirection(sf::Vector2f);
	void setVelocity(sf::Vector2f);
	void setDamage(int);
	void setEnemyPosition(sf::Vector2f);

	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};
