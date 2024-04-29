#pragma once
#include <SFML/Graphics.hpp>

class UI : public sf::Drawable
{
private:
	sf::Texture textureMonedas;
	sf::Sprite moneda;
	sf::Texture textureRayo;
	sf::Sprite rayo;
	sf::Font font;
	sf::Text text[3];
public:
	UI();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

