#include "HackerTrainee.h"


HackerTrainee::HackerTrainee()
{
	if (!_texture.loadFromFile("img/hackers/Trainee.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_name = "Trainee";

	//_seniority = 0;
	_life = 5;
	_damage = 1;
	_velocity = { 3,3 };
	_goldenDrop = 10;
}


int HackerTrainee::attackUtn() 
{
	return 30;
}