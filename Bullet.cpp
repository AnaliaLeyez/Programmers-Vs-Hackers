#include "SFML/Graphics.hpp"
#include <iostream>
#include "Collisionable.h"
#include "Hacker.h"
#include "Bullet.h"

void Bullet::moveToward()
{
	//Calcular el vector de direccion entre la torre y el objetivo
	sf::Vector2f direction = _enemyPosition - getPosition();
	float distanceToTarget = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (distanceToTarget < 1.0f) // Threshold distance
	{
		setPosition(_enemyPosition);
	}
	else
	{
		direction /= distanceToTarget;
		move(direction * _speed);
	}
}

sf::FloatRect Bullet::getBounds() const
{ 
	return _sprite.getTransform().transformRect(_sprite.getGlobalBounds());
}
sf::Vector2f Bullet::getDirection() const { return _direction; }
sf::Vector2f Bullet::getVelocity() const { return _velocity; }
sf::Vector2f Bullet::getEnemyPosition() const {	return _enemyPosition; }
void Bullet::setCrash(bool state)
{
	_crash = state;
}
bool Bullet::getCrash() { return _crash; }
int Bullet::getDamage() const { return _damage; }

void Bullet::setDirection(sf::Vector2f d) { _direction = d; }
void Bullet::setVelocity(sf::Vector2f velocity) { _velocity = velocity; }
void Bullet::setDamage(int damage) { _damage = damage; }
void Bullet::setEnemyPosition(sf::Vector2f position) { _enemyPosition = position; }

void Bullet::update()
{
	moveToward();
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}