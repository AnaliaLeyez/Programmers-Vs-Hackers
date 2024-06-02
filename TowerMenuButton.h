#pragma once
#include "Tower.h"
class TowerMenuButton : public sf::Drawable, public sf::Transformable
{
protected:
	Tower* _tower;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Texture _textureHover;
	sf::Sprite _spriteHover;
	bool _mouseHover;
	int _btnNumber;
	sf::Font _font;
	sf::Text _price;
	sf::Texture _textureBgPrice;
	sf::Sprite _spriteBgPrice;
public:
	Tower getTower();
	int getPrice();
	int getBtnNumber();

	void setBtnNumber(int);
	void setPrice();
	void setMouseHover(bool);
	void setSpriteHover();

	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
