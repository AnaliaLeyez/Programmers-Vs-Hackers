#include <SFML/Graphics.hpp>

#include "Hacker.h"
#include "Tower.h"
#include "TowerBrian.h"

TowerBrian::TowerBrian()
{
	if (!_texture.loadFromFile("img/towers/torreA_1.png")) {
		throw std::runtime_error("Error img Torre Brian");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_name = "Torre Laboratorio 1";

	//Rango de ataque:
	_visualRange.setRadius(120);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_price = 220;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 3;
	_range = 9;
	_speedAttack = 3;
	_upgradesAmount = 2;
}

void TowerBrian::update1()
{
	_name = "Laboratorio 2";
	_priceUpgrade = 9;
	_salesValue = 7;
	_damage = 12;
	_speedAttack = 2;
	_upgradesAmount = 1;
}

