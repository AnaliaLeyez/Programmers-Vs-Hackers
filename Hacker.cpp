#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Collisionable.h"

#include "Hacker.h"

int Hacker::getLife() const { return _life; }
float Hacker::getDamage() const { return _damage; }
sf::Vector2f Hacker::getVelocity() const { return _velocity; }
sf::Vector2f Hacker::getDirection() const { return _direction; }
sf::Vector2f Hacker::getPosition() const { return _position; }
bool Hacker::getBoss() const { return _isABoss; }
float Hacker::getGoldenDrop() const { return _goldenDrop; }

void Hacker::setLife(int salud) { _life = salud; }
void Hacker::setTipoAtaque(int tipo) { _tipoAtaque = tipo; }
void Hacker::setDamage(float danio) { _damage = danio; }
void Hacker::setVelocity(sf::Vector2f velocidad) { _velocity = velocidad; }
void Hacker::setDirection(sf::Vector2f direccion) { _direction = direccion; }
void Hacker::setPosition(sf::Vector2f posicion) { _position = posicion; }
void Hacker::setBoos(bool boss) { _isABoss = boss; }
void Hacker::setGoldenDrop(float drop) { _goldenDrop = drop; }

void Hacker::attack(float* objetivo)
{
	*objetivo -= getDamage();
}

sf::FloatRect Hacker::getBounds() const
{
	return _sprite.getGlobalBounds();
}

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

sf::Sprite Hacker::getSprite()
{
	return _sprite;
}
