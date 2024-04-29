#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>
class Mapa : public sf::Drawable
{
private:
	sf::Texture textureMapa1;
	sf::RectangleShape mapa;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	bool musicPlaying;
	sf::Texture textureParlante;
	sf::RectangleShape parlante;
public:
	Mapa();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	sf::RectangleShape getMapa() { return mapa; }
	sf::RectangleShape getParalante() { return parlante; }
	sf::Texture getTextureParlante() { return textureParlante; }
	void setTextureParlante(std::string ruta);

	//MUSICA
	bool getMusicPlaying();
	void setMusicPlaying(bool playing);
	sf::Sound getSound();
	void setSound(bool reproducir);
};

