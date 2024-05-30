#pragma once
#include "Tower.h"
class TowerMenuButton : public sf::Drawable, public sf::Transformable
{
protected:
	Tower* _tower;
	sf::Texture _texture;
	//static sf::Texture _texture, _textureHover;
	sf::Sprite _sprite;
	sf::Texture _textureHover;
	sf::Sprite _spriteHover;
	bool _mouseHover;
	int _btnNumber;
public:
	Tower getTower();
	int getBtnNumber();
	void setBtnNumber(int);
	void setMouseHover(bool);
	void setSpriteHover();
	void update(sf::Vector2i&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const;
};
