#include "HackerTrainee.h"


HackerTrainee::HackerTrainee()
{
	if (!_texture.loadFromFile("img/hackers/Trainee.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	setPosition(sf::Vector2f(960 / 32 * 9.5, 640 / 32 * 0.5));
	_name = "Trainee";

	//SI ESTO LO TIENEN TODOS DEBERIA IR EN HACKER.CPP Y ACA LLAMAMOS AL METODO QUE SE ENCARGA DE ESO
	_collisionRect.setSize({ 40,40 });
	_collisionRect.setOrigin(_collisionRect.getGlobalBounds().width / 2, _collisionRect.getGlobalBounds().height / 2);
	//_collisionRect.setFillColor(sf::Color::Red); //no lo quiero mostrar, por lo que el color no lo necesita
	//setPosition(sf::Vector2f(960 / 32 * 9.5, 640 / 32 * 0.5));
	//SI ESTO LO TIENEN TODOS DEBERIA IR EN HACKER.CPP Y ACA LLAMAMOS AL METODO QUE SE ENCARGA DE ESO

	_seniority = 0;
	_life = 100;
	_damage = 1;
	_velocity = { 3,3 };
	_goldenDrop = 10;

	//DESARROLLO
	//_position = {  };
}


int HackerTrainee::attackUtn() {

	return 50;
}