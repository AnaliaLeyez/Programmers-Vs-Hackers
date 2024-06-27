#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "BulletB.h"

BulletB::BulletB(sf::Vector2f position, sf::Vector2f target, int damage)
{
	_type = 2;
	setScale({ 0.5f, 0.5f });
	setPosition(position);
	_enemyPosition = target;
	_damage = damage; //esto ver que valores segun la torre q le corresponde
	_speed = 6.f;
	loadTexture();
}

void BulletB::loadTexture()
{
	if (!_texture.loadFromFile("img/bullets/fireball.png")) {
		throw std::runtime_error("Error loading BulletB texture");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
}