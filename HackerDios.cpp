#include "HackerDios.h"

HackerDios::HackerDios()
{
	if (!_texture.loadFromFile("img/hackers/Jefe1.png")) {
		throw std::runtime_error("Error img Hacker Junior");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setScale(2.2, 2.2);
	_name = "Junior";

	//_seniority = 0;
	_life = 50;
	_damage = 1;
	_velocity = { 1,1 };
	_goldenDrop = 10;
}

int HackerDios::attackUtn() {

	return 200;
}
