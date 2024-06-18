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
	_musicPlaying = true;
	_sound.play();

	//texto
	if (!_font.loadFromFile("fuentes/fuenteMenu.ttf")) {
		throw std::runtime_error("Error al cargar la fuente del Menu \n");
	}
}

void Menu::setMusicPlaying(bool playing) { _musicPlaying = playing; }

void Menu::setSound(bool play) {
	if (play) {
		_sound.play();
		//_text[3].setString("Pause music");
	}
	else {
		_sound.pause();
		//_text[3].setString("Play music");
	}
}
void Menu::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_banner, states);
}