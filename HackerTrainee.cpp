#include "HackerTrainee.h"

sf::Texture HackerTrainee::_texture;
HackerTrainee::HackerTrainee()
{
	if (!_texture.loadFromFile("img/hackers/Trainee.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setPosition(sf::Vector2f(300, 200)); //esto HAY QUE BORRARLO, lo puse solo para ver al hacker ahora
	_name = "Trainee";

	_seniority = 0;
	_life = 100;
	_damage = 1;
	_velocity = { 3,3 };
	_goldenDrop = 10;

	//DESARROLLO
	_position = { 3,3 };
}
