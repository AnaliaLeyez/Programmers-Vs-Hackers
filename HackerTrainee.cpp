#include "HackerTrainee.h"

HackerTrainee::HackerTrainee()
{
	_texture.loadFromFile("kaker.png");
	_sprite.setTexture(_texture);
	_name = "Kakercito";

	_seniority = 0;
	_life = 100;
	_tipoAtaque = 0;
	_damage = 1;
	_velocity = 2;
	_goldenDrop = 10;

	//DESARROLLO
	_position = { 3,3 };
}
