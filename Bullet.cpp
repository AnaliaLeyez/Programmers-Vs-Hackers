#include "SFML/Graphics.hpp"

#include "Collisionable.h"
#include "Hacker.h"
#include "Bullet.h"

sf::Texture Bullet::_texture;

Bullet::Bullet(sf::Vector2f initialPosition, sf::Vector2f target)
{
	_collisionCircle.setRadius(10.f);
	_collisionCircle.setFillColor(sf::Color::White);
	_collisionCircle.setPosition(initialPosition);

	if (!_texture.loadFromFile("img/Bullets/fireball.png")) {
		throw std::runtime_error("Error img FireBall");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setPosition(initialPosition);

	_enemyPosition = target;
	_speed = 3.0f;
	_damage = 20;
}

void Bullet::moveToward()
{
	//Calcular el vector de direccion entre la torre y el objetivo
	sf::Vector2f _direction = _enemyPosition - _collisionCircle.getPosition();
	//Normalizar el vector de direccion
	float length = std::sqrt(_direction.x * _direction.x + _direction.y * _direction.y);
	_direction /= length;

	// Mover el proyectil en la direcci�n calculada
	_collisionCircle.move(_direction * _speed);
	_sprite.move(_direction * _speed);
}

sf::FloatRect Bullet::getBounds() const { return _sprite.getGlobalBounds(); }
sf::Vector2f Bullet::getDirection() const { return _direction; }
sf::Vector2f Bullet::getVelocity() const { return _velocity; }
int Bullet::getDamage() const { return _damage; }

void Bullet::setDirection(sf::Vector2f d) { _direction = d; }
void Bullet::setVelocity(sf::Vector2f velocity) { _velocity = velocity; }
void Bullet::setDamage(int damage) { _damage = damage; }

void Bullet::update()
{
	moveToward();
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}