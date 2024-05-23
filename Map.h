#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Map : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _tileMap;
	std::list<sf::Sprite> _tiles;
	sf::Texture _textureUTN; //ver si queda aca o en level
	sf::RectangleShape _UTN; //ver si queda aca o en level
	
public:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

