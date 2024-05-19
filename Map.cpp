#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>

#include "Map.h"

void Map::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	for (const auto& tile : _tiles) {
		target.draw(tile, states);
	}
	target.draw(_UTN, states);
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