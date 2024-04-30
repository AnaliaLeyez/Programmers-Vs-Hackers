#include "TorreLab.h"

TorreLab::TorreLab()
{
	_texture.loadFromFile("torrecita.png");
	_sprite.setTexture(_texture);
	_nombre = "torrecita";

	//Rango de ataque:
	_rango.setRadius(120);
	_rango.setFillColor(sf::Color(0, 255, 0, 120));

	_costo = 10;
	_costoUpgrade = 9;
	_valorVenta = 5;

	_danioCausante = 10;
	_alcance = 9;
	_velocidadAtaque = 3;
	_tipoAtaque = 1;

	_cantidadUpgrades = 2;

}

void TorreLab::actualizarLabo2()
{
	_costoUpgrade = 9;
	_valorVenta = 7;
	_danioCausante = 12;
	_velocidadAtaque = 2;
	_cantidadUpgrades = 1;

}
