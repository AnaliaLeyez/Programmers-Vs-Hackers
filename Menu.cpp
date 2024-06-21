#include "Menu.h"

#include "Menu.h"

Menu::Menu() {
	//fondo
	if (!_textureBanner.loadFromFile("img/banner/imgPortada.png")) {
		throw std::runtime_error("Error al cargar img Banner");
	}
	_banner.setSize(sf::Vector2f(1024, 768));
	_banner.setTexture(&_textureBanner);
	_banner.setPosition(sf::Vector2f(0, 0));

	//musica
	_buffer.loadFromFile("music/menuMusic.wav");
	_sound.setBuffer(_buffer);
	_sound.setVolume(5);

	//texto
	if (!_font.loadFromFile("fuentes/fuenteMenu.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Menu \n");
	}
}

void Menu::setMusicPlaying(bool playing) { _musicPlaying = playing; }

void Menu::setSound(bool play) {
	if (play) {
		_sound.play();
	}
	else {
		_sound.pause();
	}
}

bool Menu::getMusicPlaying() const {
	return _musicPlaying;
}

float Menu::getSoundPosition() const {
	return _sound.getPlayingOffset().asSeconds();
}

void Menu::setSoundPosition(float position) {
	_sound.setPlayingOffset(sf::seconds(position));
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_banner, states);
}