#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Collisionable.h"

#include "Hacker.h"

Hacker::Hacker(sf::Vector2f position, sf::Vector2f direction, int damage, sf::Vector2f velocity, std::string FileName)
{
	setPosition(position);
	_direction = direction;
	_damage = damage;
	_velocity = velocity;

	if (!_texture.loadFromFile("img/hackers/" + FileName)) {
		std::cout << "NO CARGO" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin({ getBounds().left + getBounds().width / 2, getBounds().top + getBounds().height / 2 });
}

int& Hacker::getLife()
{
	return _life;
}

int Hacker::getTipoAtaque()
{
	return _tipoAtaque;
}

float Hacker::getDamage()
{
	return _damage;
}

sf::Vector2f Hacker::getVelocity()
{
	return _velocity;
}

sf::Vector2f Hacker::getDirection()
{
	return _direction;
}

sf::Vector2f Hacker::getPosition()
{
	return _position;
}

bool Hacker::getBoss()
{
	return _isABoss;
}

float Hacker::getGoldenDrop()
{
	return _goldenDrop;
}

//SETTERS
void Hacker::setLife(int salud)
{
	_life = salud;
}

void Hacker::setTipoAtaque(int tipo)
{
	_tipoAtaque = tipo;
}

void Hacker::setDamage(float danio)
{
	_damage = danio;
}

void Hacker::setVelocity(sf::Vector2f velocidad)
{
	_velocity = velocidad;
}

void Hacker::setDirection(sf::Vector2f direccion)
{
	_direction = direccion;
}

void Hacker::setPosition(sf::Vector2f posicion)
{
	_position = posicion;
}

void Hacker::setBoos(bool boss = false)
{
	_isABoss = boss;
}

void Hacker::setGoldenDrop(float drop)
{
	_goldenDrop = drop;
}

void Hacker::attack(float* objetivo)
{
	*objetivo -= getDamage();

}

sf::FloatRect Hacker::getBounds() const
{
	return _sprite.getGlobalBounds();
}

void Hacker::update()
{
	moveHacker();
}

void Hacker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}


//DESARROLLO
void Hacker::moveHacker()
{
	move(getDirection());
	if (_sprite.getPosition().x < 0)
	{
		//_sprite.setPosition(0, _sprite.getPosition().y);
		_position.x = -_position.x * 1.1;
	}

	//Limite superior
	if (_sprite.getPosition().y < 0)
	{
		//_sprite.setPosition(_sprite.getPosition().x, 0);
		_position.y = -_position.y;
	}

	//Limite derecho
	if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 800)
	{
		//		_sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
		_position.x = -_position.x;
	}

	//Limite inferior
	if (_sprite.getPosition().y + _sprite.getGlobalBounds().width > 600)
	{
		//_sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
		_position.y = -_position.y;
	}
}

sf::Sprite Hacker::getSprite()
{
	return _sprite;
}
