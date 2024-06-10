#pragma once
#include "Tower.h"
class Button : public sf::Drawable, public sf::Transformable
{
protected:
	Tower* _tower;
	int _price;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Texture _textureHover;
	sf::Sprite _spriteHover;
	bool _mouseHover;
	int _btnNumber;
	sf::Font _font;
	sf::Text _priceText;
	sf::Texture _textureBgPrice;
	sf::Sprite _spriteBgPrice;
	sf::Text _info[4];
	sf::Texture _textureBgInfo;
	sf::Sprite _spriteBgInfo;
	sf::Texture _textureSword;
	sf::Sprite _spriteSword;
public:
	//Tower getTower();
	Tower* getTower();
	int getPrice();
	int getDamage();
	int getBtnNumber();
	int getPrice() const;
	
	void setBtnNumber(int);
	void setPriceText();
	void setInfo();
	void setMouseHover(bool);
	void setSpriteHover();
	void setPrice(int);

	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
