#include "HackerSemiSr.h"


HackerSemiSr::HackerSemiSr()
{
	if (!_texture.loadFromFile("img/hackers/hacker9.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	
	_sprite.setScale(0.1, 0.1);
	_name = "SemiSr";

	//_seniority = 0;
	_life = 20;
	_damage = 1;
	_velocity = { 2,2 };
	_goldenDrop = 10;

}

int HackerSemiSr::attackUtn() {

	return 60;
}