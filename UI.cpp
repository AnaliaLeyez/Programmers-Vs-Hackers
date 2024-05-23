#include <iostream>
#include <SFML/Graphics.hpp>

#include "UI.h"

UI::UI() {
	if (!_textureCoins.loadFromFile("img/complementarias/oro.png")) {
		std::cout << "Error al cargar img. Oro";
	}
	_coin.setTexture(_textureCoins);
	_coin.setPosition(510, 20);
	_coin.setOrigin(_coin.getGlobalBounds().width / 2, _coin.getGlobalBounds().height / 2);

	if (!_textureRay.loadFromFile("img/complementarias/energia.png")) {
		std::cout << "Error al cargar img. Rayo";
	}
	_ray.setTexture(_textureRay);
	_ray.setPosition(340, 25);
	_ray.setOrigin( _ray.getGlobalBounds().width / 2, _ray.getGlobalBounds().height / 2);

	//parlante
	if (!_textureSpeaker.loadFromFile("img/complementarias/musicOn.png")) {
		std::cout << "Error al cargar img mute";
	};
	_speaker.setSize(sf::Vector2f(80, 80));
	_speaker.setTexture(&_textureSpeaker);
	_speaker.setPosition(sf::Vector2f(900, 550));
	_speaker.setOrigin(_speaker.getGlobalBounds().width / 2, _speaker.getGlobalBounds().height / 2);

	if (!_font.loadFromFile("fuentes/fuenteMenu.ttf")) {
		std::cout << "Error al cargar la fuente del Menu \n";
	}
	for (int i = 0; i < 3; i++) {
		_text[i].setFont(_font);
		_text[i].setCharacterSize(30);
		int posX, posY;
		std::string texto;
		switch (i)
		{
		case 0:
			posX = 590;
			posY = 20;
			texto = "500";
			break;
		case 1:
			posX = 400;
			posY = 20;
			texto = "600";
			break;
		case 2:
			posX = 800;
			posY = 700;
			texto = "Menu";
			break;
		default:
			break;
		}
		_text[i].setPosition(posX, posY);
		_text[i].setString(texto);
		//text[i].setOrigin(text[i].getGlobalBounds().getPosition().x / 2, text[i].getGlobalBounds().height / 2);
		_text[i].setFillColor(sf::Color(255, 255, 255));
	}
}
sf::RectangleShape UI::getSpeaker() const { return _speaker; }
sf::Texture UI::getTextureSpeaker() const { return _textureSpeaker; }
void UI::setTextureSpeaker(std::string path) {
	if (!_textureSpeaker.loadFromFile(path)) {
		std::cout << "Error al cargar img mute";
	};
	_speaker.setTexture(&_textureSpeaker);
}
void UI::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	target.draw(_ray, states);
	target.draw(_coin, states);
	target.draw(_speaker, states);
	for (int i = 0; i < 3; i++) {
		target.draw(_text[i], states);
	}
}