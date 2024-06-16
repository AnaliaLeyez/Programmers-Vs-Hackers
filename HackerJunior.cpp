#include "HackerJunior.h"


HackerJunior::HackerJunior()
{
	if (!_texture.loadFromFile("img/hackers/SemiSr.png")) {
		throw std::runtime_error("Error img Hacker Junior");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setScale(1.8, 1.8);
	_name = "Junior";

	//_seniority = 0;
	_life = 10;
	_damage = 1;
	_velocity = { 3,3 };
	_goldenDrop = 10;

}


int HackerJunior::attackUtn() {
	
	return 100;
}

// int HackerJunior::getType() const  {
//	return 1; // Identificador �nico para HackerJunior
//}