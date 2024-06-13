#include "HackerDios.h"

HackerDios::HackerDios()
{
	if (!_texture.loadFromFile("img/hackers/Jefe1.png")) {
		throw std::runtime_error("Error img Hacker Junior");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setPosition(960 / 32 * 9.5, 640 / 32 * 0.5);
	//_sprite.setScale(0.1, 0.1);
	_name = "Junior";

	_seniority = 0;
	_life = 500;
	_damage = 1;
	_velocity = { 3,3 };
	_goldenDrop = 10;

	//DESARROLLO
	_position = { };
}


int HackerDios::attackUtn() {

	return 10000000;
}
