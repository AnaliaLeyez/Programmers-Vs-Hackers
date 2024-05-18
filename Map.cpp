#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>

#include "globalFunctions.h"
#include "Map.h"

Map::Map() {
	_tileMapa.loadFromFile("img/mapas/mapa1.png");

	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 30; x++) {
			sf::Sprite _sprite(_tileMapa);
			_sprite.setTextureRect(sf::IntRect(x * 32, y * 32, 32, 32));
			_sprite.setPosition(32 * x, 32 * y);
		}
	}

	//UTN
	if (!_textureUTN.loadFromFile("img/base.png")) {
		std::cout << "Error al cargar img UTN";
	};
	_speaker.setSize(sf::Vector2f(80, 80));
	_speaker.setTexture(&_textureSpeaker);
	_speaker.setPosition(sf::Vector2f(900, 650));
	_speaker.setOrigin(_speaker.getGlobalBounds().width / 2, _speaker.getGlobalBounds().height / 2);

	//parlante
	if (!_textureSpeaker.loadFromFile("img/complementarias/musicOn.png")) {
		std::cout << "Error al cargar img mute";
	};
	_speaker.setSize(sf::Vector2f(80, 80));
	_speaker.setTexture(&_textureSpeaker);
	_speaker.setPosition(sf::Vector2f(900, 650));
	_speaker.setOrigin(_speaker.getGlobalBounds().width / 2, _speaker.getGlobalBounds().height / 2);

	//musica
	if (!_buffer.loadFromFile("music/nivel1.wav")) {
		std::cout << "Error al cargar musica nivel 1";
	};
	_sound.setBuffer(_buffer);
	_sound.setVolume(100);
	_musicPlaying = true;

}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	target.draw(_sprite, states);
	target.draw(_speaker, states);
}

void Map::setTextureSpeaker(std::string ruta) {
	if (!_textureSpeaker.loadFromFile(ruta)) {
		std::cout << "Error al cargar img mute";
	};
	_speaker.setTexture(&_textureSpeaker);
}

//MUSICA
bool Map::getMusicPlaying() { return _musicPlaying; }
void Map::setMusicPlaying(bool playing) { _musicPlaying = playing; }
sf::Sound Map::getSound() { return _sound; }
void Map::setSound(bool reproducir) {
	if (reproducir) {
		_sound.play();

	}
	else {
		_sound.pause();

	}
}