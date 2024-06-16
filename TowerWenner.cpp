#include <SFML/Graphics.hpp>
#include <iostream> //borrar
#include "Hacker.h"
//#include "BulletBrian.h" //cambiar por Wenner
#include "Tower.h"
#include "TowerWenner.h"

TowerWenner::TowerWenner()
{
	if (!_texture.loadFromFile("img/towers/torreB_1.png")) {
		throw std::runtime_error("Error img Tower Wenner");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_name = "wenner";

	//Rango de ataque:
	_visualRange.setRadius(120);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_type = 4;
	_price = 150;
	_priceUpgrade = 200;
	_salesValue = 120;
	_damage = 8;
	_range = 6;
	_speedAttack = 3;
	_upgradesAmount = 2;
	_fireRate = 0.8f; // Tiempo en segundos entre disparos
}

void TowerWenner::upgrade()
{
	switch (_upgradesAmount)
	{
	case 2:
	{
		_name = "estadistica";
		if (!_texture.loadFromFile("img/towers/torreB_3.png")) {
			throw std::runtime_error("Error img tower estadistica");
		}
		_sprite.setTexture(_texture);

		_priceUpgrade = 300;
		_salesValue = 280;
		_damage = 14;
		//_speedAttack = 1; //no terminamos de definir esto como es en el juego real
		_upgradesAmount = 1;
	}
	break;
	case 1:
	{
		_name = "Torre WENNER";
		if (!_texture.loadFromFile("img/towers/torreb_4.png")) {
			throw std::runtime_error("Error img tower MAXI WENNER");
		}
		_sprite.setTexture(_texture);

		_priceUpgrade = 9990;
		_salesValue = 816;
		_damage = 20;
		//_speedAttack = 3;   //no terminamos de definir esto como es en el juego real
		_upgradesAmount = 0;
	}
	default:
		break;
	}
}