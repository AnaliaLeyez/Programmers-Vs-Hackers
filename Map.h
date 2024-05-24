#pragma once
#include <SFML/Graphics.hpp>
#include <list>

class Map : public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	sf::Texture _tileMap;
	std::list<sf::Sprite> _tiles;
	sf::Texture _textureUTN;
	sf::RectangleShape _UTN;
	sf::Texture _textureUTNRed;
	sf::RectangleShape _UTNRed;
	bool _dying;
	
public:
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

