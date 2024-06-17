#include <SFML/Graphics.hpp>
#include <iostream> //borrar
#include "Hacker.h"
#include "Tower.h"
#include "TowerSarF.h"

TowerSarF::TowerSarF() //elimine sf::Vector2f position   del argumento
{
	if (!_texture.loadFromFile("img/towers/torreD_1.png")) {
		throw std::runtime_error("Error img Sar F");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

	_name = "Torre Programacion 1";

	//Rango de ataque:
	_visualRange.setRadius(130);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_type = 3;
	_price = 180;
	_priceUpgrade = 240;
	_salesValue = 144;
	_damage = 3;
	_damageUpgrade = 5;
	_range = 8;
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos
	_clock.restart();
}

void TowerSarF::upgrade()
{
	switch (_upgradesAmount)
	{
	case 2:
	{
		_name = "Programacion 2";
		if (!_texture.loadFromFile("img/towers/torreD_2.png")) {
			throw std::runtime_error("Error img tower Programacion2");
		}
		_sprite.setTexture(_texture);
		_priceUpgrade = 300;
		_salesValue = 336;
		_damage = 5;
		_damageUpgrade = 7;
		_fireRate = 0.7f; //dispara mas rapido
		_upgradesAmount = 1;
	}
	break;
	case 1:
	{
		_name = "Torre MAXI F";
		if (!_texture.loadFromFile("img/towers/torreD_4.png")) {
			throw std::runtime_error("Error img tower MAXI F");
		}
		_sprite.setTexture(_texture);

		_priceUpgrade = 9990;
		_salesValue = 576;
		_damage = 7;
		//_fireRate  se mantiene
		_upgradesAmount = 0;
	}
	default:
		break;
	}
}

