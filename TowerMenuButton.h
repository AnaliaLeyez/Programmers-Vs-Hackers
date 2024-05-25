#pragma once
#include "Tower.h"
class TowerMenuButton : public sf::Drawable, public sf::Transformable
{
protected:
	Tower* _tower; //Nuevo, para que cada boton tenga la torre que representa
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Texture _textureHover;
	sf::Sprite _spriteHover;
	bool _mouseHover;

public:
	//void isMouseOver();
	Tower getTower();
	void update();
	void setMouseHover(bool);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const {								//-----BORRAR------//
		return getTransform().transformRect(_sprite.getGlobalBounds());
	}
};
