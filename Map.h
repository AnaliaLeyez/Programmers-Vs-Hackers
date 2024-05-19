#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <list>

class Map : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _tileMap;
	std::list<sf::Sprite> _tiles;
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	bool _musicPlaying;
	sf::Texture _textureUTN;
	sf::RectangleShape _UTN;
	sf::Texture _textureSpeaker;
	sf::RectangleShape _speaker;
public:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	sf::RectangleShape getSpeaker() { return _speaker; }
	sf::Texture getTextureSpeaker() { return _textureSpeaker; }
	void setTextureSpeaker(std::string ruta);

	//MUSICA
	bool getMusicPlaying();
	void setMusicPlaying(bool playing);
	sf::Sound getSound();
	void setSound(bool reproducir);
};

