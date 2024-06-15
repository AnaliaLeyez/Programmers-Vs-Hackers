#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "BulletA.h"

BulletA::BulletA(sf::Vector2f position, sf::Vector2f target, int damage)
	: Bullet(position, target)
{
	setPosition(position);
	_enemyPosition = target;

	_damage = damage; //esto ver que valores segun la torre q le corresponde
	_speed = 9.0f;
	loadTexture();
}

void BulletA::loadTexture()
{
	if (!_texture.loadFromFile("img/bullets/iceball.png")) {
		throw std::runtime_error("Error loading BulletA texture");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void BulletA::update1BulletA()
{
	_damage = 3;
}

void BulletA::update2BulletA()
{
	_damage = 4;
	_velocity = { 3.f,3.f };
}