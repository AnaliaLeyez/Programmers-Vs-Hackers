#pragma once
#include <SFML/Graphics.hpp>
class UI : public sf::Drawable
{
private:
	sf::Texture _textureCoins;
	sf::Sprite _coin;
	sf::Texture _textureRay;
	sf::Sprite _ray;
	sf::Font _font;
	sf::Text _text[3];
	sf::Texture _textureSpeaker;
	sf::RectangleShape _speaker;
public:
	UI();
	sf::RectangleShape getSpeaker() const;
	sf::Texture getTextureSpeaker() const;
	void setTextureSpeaker(std::string);

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

