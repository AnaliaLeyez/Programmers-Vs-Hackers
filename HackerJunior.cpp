#include "HackerJunior.h"


HackerJunior::HackerJunior()
{
	if (!_texture.loadFromFile("img/hackers/Junior.png")) {
		throw std::runtime_error("Error img Hacker Junior");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setPosition(960 / 32 * 9.5, 640 / 32 * 0.5);
	//_sprite.setScale(0.1, 0.1);
	_name = "Junior";

	_seniority = 0;
	_life = 100;
	_damage = 1;
	_velocity = { 3,3 };
	_goldenDrop = 10;

	//DESARROLLO
	_position = { };
}


int HackerJunior::attackUtn() {
	
	return 5000;
}

//void HackerJunior::takeLife(Level& level) {
//	// Reducir la vida del jugador según el tipo de hacker Trainee
//	level.setEnergy(level.getEnergy() - 100);
//}

// int HackerJunior::getType() const  {
//	return 1; // Identificador único para HackerJunior
//}