#include <SFML/Graphics.hpp>

#include "Hacker.h"
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
	_visualRange.setRadius(120);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_price = 100;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 7;
	_range = 9;
	_speedAttack = 3;
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos
}

void TowerKloster::update1()
{
	_priceUpgrade = 9;
	_salesValue = 7;
	_damage = 12;
	_speedAttack = 2;
	_upgradesAmount = 1;
}

