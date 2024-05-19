#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"

#include "BulletA.h"

BulletA::BulletA(sf::Vector2f position, sf::Vector2f direction)
{
	setPosition(position);
	_direction = direction;
	_damage = 2; //esto ver que valores segun la torre q le corresponde
	_velocity = { 2.f,2.f }; //esto ver que valores segun la torre q le corresponde

	if (!_texture.loadFromFile("img/bullets/bola-canion.png")) {
		std::cout << "NO CARGO" << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin({ getBounds().left + getBounds().width / 2, getBounds().top + getBounds().height / 2 });
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
