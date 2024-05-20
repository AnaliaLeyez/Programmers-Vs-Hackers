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
	sf::SoundBuffer _buffer;	//ESTO NO VA ACA
	sf::Sound _sound;	//ESTO NO VA ACA
	bool _musicPlaying;	//ESTO NO VA ACA
	sf::Texture _textureUTN;
	sf::RectangleShape _UTN;
	
public:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

