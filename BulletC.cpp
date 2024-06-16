#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "BulletC.h"

BulletC::BulletC(sf::Vector2f position, sf::Vector2f target, int damage)
{
	setPosition(position);
	_enemyPosition = target;

	_damage = damage; //esto ver que valores segun la torre q le corresponde
	_speed = 6.7f;
	loadTexture();
}

void BulletC::loadTexture()
{
	if (!_texture.loadFromFile("img/bullets/poisonball.png")) {
		throw std::runtime_error("Error loading BulletC texture");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void BulletC::update1BulletC()
{
	_damage = 3;
}

void BulletC::update2BulletC()
{
	_damage = 4;
	_velocity = { 3.f,3.f };
}