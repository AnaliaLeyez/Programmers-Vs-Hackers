#include <SFML/Graphics.hpp>
#include <string>

#include "Collisionable.h"
#include "Hacker.h"

//sf::Sprite Hacker::getSprite() const { return _sprite; }
int Hacker::getLife() const { return _life; }
int Hacker::getDamage() const { return _damage; }
sf::Vector2f Hacker::getVelocity() const { return _velocity; }
sf::Vector2f Hacker::getDirection() const { return _direction; }
bool Hacker::getBoss() const { return _isABoss; }
int Hacker::getGoldenDrop() const { return _goldenDrop; }

void Hacker::setLife(int life) { _life = life; }
void Hacker::setDamage(float damage) { _damage = damage; }
void Hacker::setVelocity(sf::Vector2f velocity) { _velocity = velocity; }
void Hacker::setDirection(sf::Vector2f direction) { _direction = direction; }
void Hacker::setBoos(bool boss) { _isABoss = boss; }
void Hacker::setGoldenDrop(float drop) { _goldenDrop = drop; }

void Hacker::attack(float* hackerLife)
{
	*hackerLife -= getDamage();
}

sf::FloatRect Hacker::getBounds() const { return _sprite.getGlobalBounds(); }

void Hacker::update(int arr[][30])
{
	moveHacker(arr);
}

void Hacker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}


//DESARROLLO
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
	case 5:
		_direction = { -1.0f,0.0f };
		break;
	default:
		break;
	}
	move(_direction);
}
