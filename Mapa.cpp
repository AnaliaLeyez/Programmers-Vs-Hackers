#include "Mapa.h"

Mapa::Mapa() {
	//mapa
	if (!textureMapa1.loadFromFile("img/mapas/mapa1.png")) {
		std::cout << "Error al cargar img del mapa1";
	};
	mapa.setSize(sf::Vector2f(1024, 768));
	mapa.setTexture(&textureMapa1);
	mapa.setPosition(sf::Vector2f(0, 0));

	//parlante
	if (!textureParlante.loadFromFile("img/complementarias/musicOn.png")) {
		std::cout << "Error al cargar img mute";
	};
	parlante.setSize(sf::Vector2f(80, 80));
	parlante.setTexture(&textureParlante);
	parlante.setPosition(sf::Vector2f(900, 650));
	parlante.setOrigin(parlante.getGlobalBounds().width / 2, parlante.getGlobalBounds().height / 2);

	//musica
	if (!buffer.loadFromFile("music/nivel1.wav")) {
		std::cout << "Error al cargar musica nivel 1";
	};
	sound.setBuffer(buffer);
	sound.setVolume(100);
	musicPlaying = true;
}

void Mapa::draw(sf::RenderTarget& rt, sf::RenderStates rs)const {
	rt.draw(mapa, rs);
	rt.draw(parlante, rs);
}

void Mapa::setTextureParlante(std::string ruta) {
	if (!textureParlante.loadFromFile(ruta)) {
		std::cout << "Error al cargar img mute";
	};
	parlante.setTexture(&textureParlante);
}

//MUSICA
bool Mapa::getMusicPlaying() { return musicPlaying; }
void Mapa::setMusicPlaying(bool playing) { musicPlaying = playing; }
sf::Sound Mapa::getSound() { return sound; }
void Mapa::setSound(bool reproducir) {
	if (reproducir) {
		sound.play();

	}
	else {
		sound.pause();

	}
}