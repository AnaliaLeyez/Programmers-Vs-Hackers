#include <SFML/Graphics.hpp>

#include "Hacker.h"
#include "Tower.h"
#include "TowerWenner.h"

TowerWenner::TowerWenner()
{
	if (!_texture.loadFromFile("img/towers/torreB_1.png")) {
		throw std::runtime_error("Error img Tower Wenner");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_name = "Torre Matematica";

	//Rango de ataque:
	_visualRange.setRadius(120);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_price = 150;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 8;
	_range = 9;
	_speedAttack = 3;
	_upgradesAmount = 2;
}

void TowerWenner::update1()
{
	_priceUpgrade = 9;
	_salesValue = 7;
	_damage = 12;
	_speedAttack = 2;
	_upgradesAmount = 1;
}
