#include <iostream>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "BulletBrian.h"

BulletBrian::BulletBrian(sf::Vector2f initialPosition)
{
	//ADRI
	_collisionCircle.setRadius(10.f);
	_collisionCircle.setPosition(initialPosition);

	//if (!_texture.loadFromFile("img/Bullets/fireball.png")) {
	//	throw std::runtime_error("Error img FireBall");
	//}
	//_sprite.setTexture(_texture);
	//_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	//_sprite.setPosition(initialPosition);

	//_enemyPosition = direction;
	//_speed = 3.0f;
	//_damage = 20;




	//ANA
	setPosition(initialPosition);
	setOrigin(initialPosition);
	//_direction = direction;
	_damage = 2; //esto ver que valores segun la torre q le corresponde
	_speed = 3.0f;
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