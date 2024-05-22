#pragma once

class TowerMenu : public sf::Drawable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isVisible;
public:
	TowerMenu();
	bool getIsVisible();
	void hide();
	void show();

	void draw(sf::RenderTarget&, sf::RenderStates) const;
};
