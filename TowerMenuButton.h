#pragma once

class TowerMenuButton : public sf::Drawable, public sf::Transformable
{
private:
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::Texture _textureHover;
	sf::Sprite _spriteHover;
	bool _mouseOver;

public:
	TowerMenuButton();
	const sf::Sprite& getSprite() const;

	void setTexture(std::string);

	//void isMouseOver();

	void update();

	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const {								//-----BORRAR------//
		return getTransform().transformRect(_sprite.getGlobalBounds());
	}
};
