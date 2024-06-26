#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "BulletD.h"

BulletD::BulletD(sf::Vector2f position, sf::Vector2f target, int damage)
{
	_type = 4;
	setPosition(position);
	setScale({ 0.5f, 0.5f });
	_enemyPosition = target;

	_damage = damage; //esto ver que valores segun la torre q le corresponde
	_speed = 6.f;
	loadTexture();
}

void BulletD::loadTexture()
{
	if (!_texture.loadFromFile("img/bullets/shadowball.png")) {
		throw std::runtime_error("Error loading BulletD texture");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}

void BulletD::update1BulletD()
{
	_damage = 3;
}

void BulletD::update2BulletD()
{
	_damage = 4;
	_velocity = { 3.f,3.f };
}