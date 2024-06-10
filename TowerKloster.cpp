#include <SFML/Graphics.hpp>

#include "Hacker.h"
#include "BulletBrian.h" //cambiar por Kloster
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

	_price = 100;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 7;
	_range = 7;
	_speedAttack = 3;
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos

	//_clock.restart(); //NUEVO, ANA
	_cooldown = 0;
	//_bullet = new BulletBrian(getPosition()); //NUEVO, ANA //esto seria bulletKloster
}

void TowerKloster::upgrade()
{
	_name = "ARSO";
	if (!_texture.loadFromFile("img/towers/torreC_2.png")) {
		throw std::runtime_error("Error img tower ARSO");
	}
	_sprite.setTexture(_texture);
	_priceUpgrade = 200;
	_salesValue = 168;
	_damage = 9;
	//_speedAttack = 2;  //no terminamos de definir esto como es en el juego real
	_upgradesAmount = 1;
}

void TowerKloster::setBullet(sf::Vector2f twPos, sf::Vector2f hkPos)
{
	_bullet = new BulletBrian(twPos, hkPos); //esto seria bulletKloster
}

