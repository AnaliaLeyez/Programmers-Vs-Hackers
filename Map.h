#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>
class Map : public sf::Drawable
{
private:
	sf::Texture _textureMap;
	sf::RectangleShape _mapShape;
	//sf::Sprite mapa;   //VER DE PASARNOS A ESTA OPCION
	sf::SoundBuffer buffer;
	sf::Sound sound;
	bool musicPlaying;
	sf::Texture textureParlante;
	sf::RectangleShape parlante;
public:
	Map();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	sf::RectangleShape getMap() { return _mapShape; }
	sf::RectangleShape getParalante() { return parlante; }
	sf::Texture getTextureParlante() { return textureParlante; }
	void setTextureParlante(std::string ruta);

	//MUSICA
	bool getMusicPlaying();
	void setMusicPlaying(bool playing);
	sf::Sound getSound();
	void setSound(bool reproducir);
};

