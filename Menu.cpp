#include <iostream>

#include "Menu.h"

Menu* Menu::_currentInstance = nullptr;

Menu& Menu::getInstance() {
	if (Menu::_currentInstance == nullptr) {
		Menu::_currentInstance = new Menu();
		return *Menu::_currentInstance;
	}
}

Menu::Menu() {
	//fondo
	if (!_textureBanner.loadFromFile("img/banner/imgPortada.png")) {
		std::cout << "Error al cargar img Banner";
	}
	_banner->setSize(sf::Vector2f(1024, 768));
	_banner->setTexture(&_textureBanner);
	_banner->setPosition(sf::Vector2f(0, 0));

	//musica
	_buffer.loadFromFile("music/menuMusic.wav");
	_sound.setBuffer(_buffer);
	_sound.setVolume(100);
	_musicPlaying = true;
	_sound.play();

	//texto
	if (!_font.loadFromFile("fuentes/fuenteMenu.ttf")) {
		std::cout << "Error al cargar la fuente del Menu \n";
	}
	for (int i = 0; i < 5; i++) {
		_text[i].setFont(_font);
		_text[i].setCharacterSize(30);
		int posY;
		string texto;
		switch (i)
		{
		case 0:
			posY = 100;
			texto = "New Game";
			break;
		case 1:
			posY = 200;
			texto = "Restart Game";
			break;
		case 2:
			posY = 300;
			texto = "About";
			break;
		case 3:
			posY = 400;
			texto = "Pause music";
			break;
		case 4:
			posY = 500;
			texto = "Exit";
			break;
		default:
			break;
		}
		_text[i].setPosition(250, posY);
		_text[i].setString(texto);
		_text[i].setOrigin(_text[i].getGlobalBounds().getPosition().x / 2, _text[i].getGlobalBounds().height / 2);
		_text[i].setFillColor(sf::Color(255, 255, 255));
	}
}

sf::Text Menu::getText1() const { return _text[0]; }
sf::Text Menu::getText2() const { return _text[1]; }
sf::Text Menu::getText3() const { return _text[2]; }
sf::Text Menu::getText4() const { return _text[3]; }
sf::Text Menu::getText5() const { return _text[4]; }
bool Menu::getMusicPlaying() const { return _musicPlaying; }
sf::Sound Menu::getSound() const { return _sound; }
void Menu::setMusicPlaying(bool playing) { _musicPlaying = playing; }

void Menu::setSound(bool play) {
	if (play) {
		_sound.play();
		_text[3].setString("Pause music");
	}
	else {
		_sound.pause();
		_text[3].setString("Play music");
	}
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	//target.draw(*_currentInstance, states);

	target.draw(*_banner, states);
	//for (int i = 0; i < 5; i++) {
	//	target.draw(_text[i], states);
	//}
}

void Menu::validateClick(int mousex, int mousey, Menu& menu, sf::RenderWindow& window, int &view)
{
	if (menu.getText1().getGlobalBounds().contains(mousex, mousey)) {
				menu.setSound(false);
				menu.setMusicPlaying(false);
				view = 2;
			}
			else if (menu.getText4().getGlobalBounds().contains(mousex, mousey)) {
				if (menu.getMusicPlaying()) {
					menu.setSound(false);
					menu.setMusicPlaying(false);
				}
				else {
					menu.setSound(true);
					menu.setMusicPlaying(true);
				}
			}
			if (menu.getText5().getGlobalBounds().contains(mousex, mousey)) {
				window.close();
			}
}
