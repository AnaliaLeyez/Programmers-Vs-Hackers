#include "SFML/Graphics.hpp"
#include <iostream>
#include "Collisionable.h"
#include "Hacker.h"
#include "Bullet.h"

//sf::Texture Bullet::_texture;

Bullet::Bullet(sf::Vector2f initialPosition, sf::Vector2f target)
{

	std::cout << "CONSTRUCTOR DE BULLET" << std::endl;
	std::cout << "INITIAL POSITION: " << initialPosition.x << " " << initialPosition.y << std::endl;
	std::cout << "TARGET POSITION: " << target.x << " " << target.y << std::endl;

	_collisionCircle.setRadius(40.f);
	_collisionCircle.setOrigin(_collisionCircle.getGlobalBounds().width / 2, _collisionCircle.getGlobalBounds().height / 2);
	_collisionCircle.setFillColor(sf::Color::White);
	

	
	_enemyPosition = target;

}

void Bullet::moveToward()
{
	//Calcular el vector de direccion entre la torre y el objetivo
	//sf::Vector2f _direction = _enemyPosition - _collisionCircle.getPosition(); //ADRI
	sf::Vector2f _direction = getEnemyPosition() - getPosition(); //ANA
	//Normalizar el vector de direccion
	float length = std::sqrt(_direction.x * _direction.x + _direction.y * _direction.y);
	_direction /= length;

	// Mover el proyectil en la direccion calculada
	//_collisionCircle.move(_direction * _speed); //ADRI
	move(_direction * _speed); //ANA
	//_sprite.move(_direction * _speed); //ADRI
}

sf::FloatRect Bullet::getBounds() const
{ 
	return _sprite.getTransform().transformRect(_collisionCircle.getGlobalBounds());
}
sf::Vector2f Bullet::getDirection() const { return _direction; }
sf::Vector2f Bullet::getVelocity() const { return _velocity; }
sf::Vector2f Bullet::getEnemyPosition() const {	return _enemyPosition; }
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
	//target.draw(_collisionCircle, states);
	target.draw(_sprite, states);
}