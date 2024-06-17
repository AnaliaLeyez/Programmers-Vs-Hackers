#pragma once
#include "Tower.h"
class Button : public sf::Drawable, public sf::Transformable
{
protected:
	int _type;
	Tower* _tower;
	int _price;
	int _damage;
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
	Tower* getTower() const; // Devuelve una nueva instancia
	int getPrice() const;
	int getPriceOfButton() const;
	int getDamage() const;
	int getDamageOfButton() const;
	int getBtnNumber() const;
	
	
	void setBtnNumber(int);
	void setPriceText();
	void setInfo();
	void setMouseHover(bool);
	void setSpriteHover();
	void setPrice(int);
	void setDamage(int);

	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
