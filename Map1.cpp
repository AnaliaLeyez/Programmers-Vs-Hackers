#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>

#include "globalFunctions.h"
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

	//parlante
	if (!_textureSpeaker.loadFromFile("img/complementarias/musicOn.png")) {
		std::cout << "Error al cargar img mute";
	};
	_speaker.setSize(sf::Vector2f(80, 80));
	_speaker.setTexture(&_textureSpeaker);
	_speaker.setPosition(sf::Vector2f(900, 550));
	_speaker.setOrigin(_speaker.getGlobalBounds().width / 2, _speaker.getGlobalBounds().height / 2);

	//musica
	if (!_buffer.loadFromFile("music/nivel1.wav")) {
		std::cout << "Error al cargar musica nivel 1";
	};
	_sound.setBuffer(_buffer);
	_sound.setVolume(100);
	_musicPlaying = true;
}