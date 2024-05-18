#include "SFML/Graphics.hpp"
#include <iostream>

#include "Collisionable.h"
#include "Hacker.h"

#include "Bullet.h"

sf::FloatRect Bullet::getBounds() const
{
	return _sprite.getGlobalBounds();
}
sf::Vector2f Bullet::getDirection()
{
	return _direction;
}
sf::Vector2f Bullet::getVelocity()
{
	return _velocity;
}
int Bullet::getDamage()
{
	return _damage;
}
void Bullet::setDirection(sf::Vector2f d)
{
	_direction = d;
}
void Bullet::setVelocity(sf::Vector2f velocity)
{
	_velocity = velocity;
}
void Bullet::setDamage(int damage)
{
	_damage = damage;
}
void Bullet::moveBullet(sf::Vector2f towerPosition, sf::Vector2f enemyPosition)
{
		// Calcular el vector de dirección entre la torre y el objetivo
		sf::Vector2f _direction = enemyPosition - towerPosition;

		// Lo del teorema del mago ese griego viejo
		_direction /= sqrt((float) std::pow(_direction.x,2) + (float)std::pow(_direction.y,2));

		// Mover el proyectil en la dirección calculada
		move(_direction.x * _velocity.x, _direction.y * _velocity.y);

}
void Bullet::update()
{
	//getPosition tiene la posicion inicial, la cual es fija y coincide con la torre
	moveBullet(getPosition(), _enemyPosition);  //como hacemos para tener aca la posicion del enemigo??
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}
