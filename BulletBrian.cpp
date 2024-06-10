#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "BulletBrian.h"

BulletBrian::BulletBrian(sf::Vector2f position, sf::Vector2f direction)
{
	setPosition(position);
	_direction = direction;
	_damage = 2; //esto ver que valores segun la torre q le corresponde
	_velocity = { 2.f,2.f }; //esto ver que valores segun la torre q le corresponde

	if (!_texture.loadFromFile("img/bullets/bola-canion.png")) {
		throw std::runtime_error("Error img bala canion");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin({ getBounds().left + getBounds().width / 2, getBounds().top + getBounds().height / 2 });
}

void BulletBrian::upgrade()
{
	_damage = 3;
}