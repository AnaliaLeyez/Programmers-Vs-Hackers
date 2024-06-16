#include <SFML/Graphics.hpp>
#include <iostream> //borrar
#include "Hacker.h"
//#include "BulletBrian.h" //cambiar por Kloster
#include "Tower.h"
#include "TowerKloster.h"

TowerKloster::TowerKloster()
{
	if (!_texture.loadFromFile("img/towers/torreC_1.png")) {
		throw std::runtime_error("Error img Tower Kloster");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_name = "Torre SPD";

	//Rango de ataque:
	_visualRange.setRadius(130);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_type = 2;
	_price = 100;
	_priceUpgrade = 110;
	_salesValue = 80;
	_damage = 7;
	_range = 7;
	_speedAttack = 3;
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos
}

void TowerKloster::upgrade()
{
	switch (_upgradesAmount)
	{
	case 2:
	{
		_name = "ARSO";
		if (!_texture.loadFromFile("img/towers/torreC_3.png")) {
			throw std::runtime_error("Error img tower ARSO");
		}
		_sprite.setTexture(_texture);
		_priceUpgrade = 200;
		_salesValue = 168;
		_damage = 9;
		//_speedAttack = 2;  //no terminamos de definir esto como es en el juego real
		_upgradesAmount = 1;
	}
	break;
	case 1:
	{
		_name = "Torre KLOSTER";
		if (!_texture.loadFromFile("img/towers/torrec_4.png")) {
			throw std::runtime_error("Error img tower Labo3 BRIAN");
		}
		_sprite.setTexture(_texture);

		_priceUpgrade = 9990;
		_salesValue = 328;
		_damage = 13;
		//_speedAttack = 3;   //no terminamos de definir esto como es en el juego real
		_upgradesAmount = 0;
	}
	default:
		break;
	}
}
