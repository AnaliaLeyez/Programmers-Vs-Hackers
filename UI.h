#pragma once
#include <SFML/Graphics.hpp>
class UI : public sf::Drawable
{
private:
	sf::Texture _textureBgPlyInfo;
	sf::Sprite _bgPlyInfo;
	sf::Texture _textureCoins;
	sf::Sprite _coin;
	sf::Texture _textureRay;
	sf::Sprite _ray;
	sf::Texture _textureSkull;
	sf::Sprite _skull;
	sf::Font _font;
	sf::Text _text[4];
	sf::Texture _textureSpeaker;
	sf::RectangleShape _speaker;
public:
	UI();
	sf::RectangleShape getSpeaker() const;
	void setText(int, std::string);
	sf::Texture getTextureSpeaker() const;
	void setTextureSpeaker(std::string);

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};