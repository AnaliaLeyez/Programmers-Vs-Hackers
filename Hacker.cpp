#include <SFML/Graphics.hpp>
#include <string>

#include "Collisionable.h"
#include "Hacker.h"
#include "Level.h"

//sf::Sprite& Hacker::getSprite() { return _sprite; }
int Hacker::getLife() const { return _life; }
int Hacker::getDamage() const { return _damage; }
sf::Vector2f Hacker::getVelocity() const { return _velocity; }
sf::Vector2f Hacker::getDirection() const { return _direction; }
bool Hacker::getBoss() const { return _isABoss; }
int Hacker::getGoldenDrop() const { return _goldenDrop; }
bool Hacker::getEnd() const { return _reachedEnd; }

void Hacker::setEnd(bool end) { _reachedEnd = end; }
void Hacker::setLife(int life) { _life = life; }
void Hacker::setDamage(int damage) { _damage = damage; }
void Hacker::setVelocity(sf::Vector2f velocity) { _velocity = velocity; }
void Hacker::setDirection(sf::Vector2f direction) { _direction = direction; }
void Hacker::setBoos(bool boss) { _isABoss = boss; }
void Hacker::setGoldenDrop(int drop) { _goldenDrop = drop; }

void Hacker::attack(float* hackerLife)
{
	*hackerLife -= getDamage();
}
void Hacker::takeDamage(int damageBullet)
{
	_life -= damageBullet;
}

void Hacker::moveHacker(int arr[][30])
{
	switch (arr[(int)_sprite.getPosition().y / 32][(int)_sprite.getPosition().x / 32])
	{
	case 2:
		_direction = { 1.0f,0.0f };
		break;
	case 3:
		_direction = { 0.0f,-1.0f };
		break;
	case 4:
		_direction = { 0.0f,1.0f };
		break;
	case 5: //esto lo podemos sacar, cambiar numeracion
		_direction = { 0.0f,-1.0f };
		
		break;
	case 8:
		_direction = { 0.0f,1.0f };
		_reachedEnd = true;
		break;
	default:
		_reachedEnd = false;
		break;
	}
	_sprite.move(_direction);
	_collisionRect.move(_direction);
}

sf::FloatRect Hacker::getBounds() const { return _sprite.getGlobalBounds(); }

void Hacker::update(int arr[][30])
{
	moveHacker(arr);
}

void Hacker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	//target.draw(_collisionRect, states); //el rectangulo rojo no lo quiero mostrar
	target.draw(_sprite, states);
}