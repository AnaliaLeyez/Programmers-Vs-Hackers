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

	_price = 120;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 8;
	_range = 6;
	_speedAttack = 3;
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos
}

void TowerWenner::upgrade()
{
	_name = "estadistica";
	if (!_texture.loadFromFile("img/towers/torreB_2.png")) {
		throw std::runtime_error("Error img tower estadistica");
	}
	_sprite.setTexture(_texture);

	_priceUpgrade = 300;
	_salesValue = 280;
	_damage = 14;
	//_speedAttack = 1; //no terminamos de definir esto como es en el juego real
	_upgradesAmount = 1;
}
