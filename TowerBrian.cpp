#include <SFML/Graphics.hpp>
#include <iostream> //borrar
#include "Hacker.h"
#include "Tower.h"
#include "TowerBrian.h"

TowerBrian::TowerBrian()
{
	if (!_texture.loadFromFile("img/towers/torreA_1.png"))
	{
		throw std::runtime_error("Error img Torre Brian");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_sprite.setPosition(0, 0);

	_name = "Torre Laboratorio 1";

	//Rango de ataque:
	_visualRange.setRadius(150);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_type = 1;
	_price = 220;
	_priceUpgrade = 340;
	_salesValue = 176;
	_damage = 3;
	_damageUpgrade = 5;
	_range = 9;
	_upgradesAmount = 2;
	_fireRate = 0.8f; // Tiempo en segundos entre disparos
	_clock.restart();
}

void TowerBrian::upgrade() 
{
	switch (_upgradesAmount)
	{
	case 2:
	{
		_name = "Torre Laboratorio 2";
		if (!_texture.loadFromFile("img/towers/torreA_2.png")) {
			throw std::runtime_error("Error img tower Labo2");
		}
		_sprite.setTexture(_texture);

		_priceUpgrade = 460;
		_salesValue = 448;
		_damage = 5;
		_damageUpgrade = 8;
		_fireRate = 1.f; //dispara mas lento
		_upgradesAmount = 1;
	}
	break;
	case 1:
	{
		_name = "Torre BRIAN";
		if (!_texture.loadFromFile("img/towers/torreA_3.png")) {
			throw std::runtime_error("Error img tower Labo3 BRIAN");
		}
		_sprite.setTexture(_texture);

		_priceUpgrade = 9990;
		_salesValue = 816;
		_damage = 8;
		_fireRate = 0.6f; //dispara mas rapido
		_upgradesAmount = 0;
	}
	default:
		break;
	}
}