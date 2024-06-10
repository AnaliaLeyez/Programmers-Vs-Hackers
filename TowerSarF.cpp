#include <SFML/Graphics.hpp>

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
	//setPosition(position);

	_name = "Torre Programacion 1";

	//Rango de ataque:
	_visualRange.setRadius(120);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_price = 180;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 3;
	_range = 9;
	_speedAttack = 3;
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos
}

void TowerSarF::upgrade()
{
	_name = "Programacion 2";
	if (!_texture.loadFromFile("img/towers/torreD_2.png")) {
		throw std::runtime_error("Error img tower Programacion2");
	}
	_sprite.setTexture(_texture);
	_priceUpgrade = 300;
	_salesValue = 336;
	_damage = 5;
	//_speedAttack = 3;  //no terminamos de definir esto como es en el juego real
	_upgradesAmount = 1;
}