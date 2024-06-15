#include <SFML/Graphics.hpp>
#include <iostream> //borrar
#include "Hacker.h"
#include "BulletA.h"
#include "Tower.h"
#include "TowerBrian.h"

TowerBrian::TowerBrian()
{
	if (!_texture.loadFromFile("img/towers/torreA_1.png"))
	{
		throw std::runtime_error("Error img Torre Brian");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(64, 64);
	_name = "brian";
	_sprite.setPosition(0, 0);

	//Rango de ataque:
	_visualRange.setRadius(150);
	_visualRange.setFillColor(sf::Color(0, 255, 0, 120));
	_visualRange.setOrigin(_visualRange.getGlobalBounds().width / 2, _visualRange.getGlobalBounds().height / 2);

	_type = 1;
	_price = 10;
	_priceUpgrade = 9;
	_salesValue = 5;
	_damage = 10;
	_range = 9;
	_speedAttack = 3;
	_upgradesAmount = 2;
	_fireRate = 1.0f; // Tiempo en segundos entre disparos
}

void TowerBrian::upgrade() 
{
	std::cout << " - - - - - - - - " << std::endl;
	std::cout << "Pos" << getPosition().x << " " << getPosition().y << std::endl;
	std::cout << "ORIGIN " << getOrigin().x << " " << getOrigin().y << std::endl;
	std::cout << "Sprite: " << _sprite.getPosition().x << " " << _sprite.getPosition().y << std::endl;
	std::cout << "Origin: " << _sprite.getOrigin().x << " " << _sprite.getOrigin().y << std::endl;
	

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
		//_speedAttack = 3;   //no terminamos de definir esto como es en el juego real
		_upgradesAmount = 1;
	}
	break;
	case 1:
	{
		_name = "Torre BRIAN";
		if (!_texture.loadFromFile("img/towers/torreA_5.png")) {
			throw std::runtime_error("Error img tower Labo3 BRIAN");
		}
		_sprite.setTexture(_texture);

		_priceUpgrade = 9990;
		_salesValue = 816;
		_damage = 8;
		//_speedAttack = 3;   //no terminamos de definir esto como es en el juego real
		_upgradesAmount = 0;
	}
	default:
		break;
	}
}

void TowerBrian::setBullet(sf::Vector2f twPos, sf::Vector2f hkPos)
{
	//_bullet = new BulletA(twPos, hkPos);
}