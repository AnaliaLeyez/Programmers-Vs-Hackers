#include <SFML/Graphics.hpp>
#include "Hacker.h"
#include "BulletBrian.h"
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
	_visualRange.setRadius(150);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_price = 220;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 3;
	_range = 8;
	_speedAttack = 3; //este no se esta usando me parece, esta el fireRate en su lugar...
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos

	//_clock.restart(); //NUEVO, ANA
	_cooldown = 0;
	_bullet = new BulletBrian(getPosition()); //NUEVO, ANA
}

void TowerBrian::upgrade() 
{
	_name = "Torre Laboratorio 2";
	if (!_texture.loadFromFile("img/towers/torreA_2.png")) {
		throw std::runtime_error("Error img tower Labo2");
	}
	_sprite.setTexture(_texture);

	_priceUpgrade = 460;
	_salesValue = 448;
	_damage = 5;
	//_speedAttack = 3;   //no terminamos de definir esto como es en el juego real
	_upgradesAmount = 1;
}

