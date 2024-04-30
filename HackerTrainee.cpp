#include "HackerTrainee.h"

HackerTrainee::HackerTrainee()
{
	_texture.loadFromFile("kaker.png");
	_sprite.setTexture(_texture);
	_nombre = "Kakercito";

	_seniority = 0;
	_salud = 100;
	_tipoAtaque = 0;
	_cantidadDanio = 1;
	_velocidadMovimiento = 2;
	_dropOro = 10;

	//DESARROLLO
	_posicion = { 3,3 };
}
