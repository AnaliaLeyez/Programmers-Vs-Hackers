#include "Menu.h"

Menu::Menu() {
	//fondo
	if (!textureBanner.loadFromFile("img/banner/imgPortada.png")) {
		std::cout << "Error al cargar img Banner";
	}
	banner.setSize(sf::Vector2f(1024, 768));
	banner.setTexture(&textureBanner);
	banner.setPosition(sf::Vector2f(0, 0));

	//texto
	if (!font.loadFromFile("fuentes/fuenteMenu.ttf")) {
		std::cout << "Error al cargar la fuente del Menu \n";
	}
	for (int i = 0; i < 5; i++) {
		text[i].setFont(font);
		text[i].setCharacterSize(30);
		int posY;
		string texto;
		switch (i)
		{
		case 0:
			posY = 100;
			texto = "Juego nuevo";
			break;
		case 1:
			posY = 200;
			texto = "Reanudar partida";
			break;
		case 2:
			posY = 300;
			texto = "Creditos";
			break;
		case 3:
			posY = 400;
			texto = "Silenciar/reproducir";
			break;
		case 4:
			posY = 500;
			texto = "Salir";
			break;
		default:
			break;
		}
		text[i].setPosition(250, posY);
		text[i].setString(texto);
		text[i].setOrigin(text[i].getGlobalBounds().getPosition().x / 2, text[i].getGlobalBounds().height / 2);
		text[i].setFillColor(sf::Color(255, 255, 255));

		//musica
		buffer.loadFromFile("music/menuMusic.wav");
		sound.setBuffer(buffer);
		sound.setVolume(100);
		musicPlaying = true;
	}

}

void Menu::draw(sf::RenderTarget& rt, sf::RenderStates rs)const {
	rt.draw(banner, rs);
	for (int i = 0; i < 5; i++) {
		rt.draw(text[i], rs);
	}

}

bool Menu::getMusicPlaying() { return musicPlaying; }
void Menu::setMusicPlaying(bool playing) { musicPlaying = playing; }
sf::Sound Menu::getSound() { return sound; }
void Menu::setSound(bool reproducir) {
	if (reproducir) {
		sound.play();
		text[3].setString("Pausar música");
	}
	else {
		sound.pause();
		text[3].setString("Reanudar música");
	}
}
sf::Text Menu::getText1() { return text[0]; }
sf::Text Menu::getText2() { return text[1]; }
sf::Text Menu::getText3() { return text[2]; }
sf::Text Menu::getText4() { return text[3]; }
sf::Text Menu::getText5() { return text[4]; }