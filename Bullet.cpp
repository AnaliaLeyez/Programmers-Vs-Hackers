#include "SFML/Graphics.hpp"
#include <iostream>

#include "Collisionable.h"
#include "Hacker.h"

#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction,int damage, sf::Vector2f velocity, std::string FileName)
{
	setPosition(position);
	_direction = direction;
	_damage = damage;
	_velocity = velocity;

	if (!_texture.loadFromFile("img/bullets/"+ FileName)) {
		std::cout << "NO CARGO" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin({getBounds().left + getBounds().width / 2, getBounds().top + getBounds().height / 2});
}
sf::FloatRect Bullet::getBounds() const
{
	return _sprite.getGlobalBounds();
}
void Bullet::setDirection(sf::Vector2f d)
{
	_direction = d;
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
	moveBullet(getPosition(), _enemyPosition);
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}
