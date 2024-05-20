#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>

#include "Map.h"

#include "Map1.h"

Map1::Map1() {
	if (!_tileMap.loadFromFile("img/maps/mapa1.png")) {
		throw std::runtime_error("Error al cargar la textura del tilest");
	}
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 30; x++) {
			_sprite.setTexture(_tileMap);
			_sprite.setTextureRect(sf::IntRect(x * 32, y * 32, 32, 32));
			_sprite.setPosition(32 * x, 32 * y);
			_tiles.push_back(_sprite);
		}
	}
	//UTN
	if (!_textureUTN.loadFromFile("img/towers/utn1.png")) {
		std::cout << "Error al cargar img UTN";
	};
	_UTN.setSize(sf::Vector2f(80, 80));
	_UTN.setTexture(&_textureUTN);
	_UTN.setPosition(sf::Vector2f(850, 200));
	_UTN.setOrigin(_UTN.getGlobalBounds().width / 2, _UTN.getGlobalBounds().height / 2);
}