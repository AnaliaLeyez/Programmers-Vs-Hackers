#pragma once
#include "TowerMenuButton.h"
class TowerMenu : public sf::Drawable, public sf::Transformable
{
private:
	sf::Sprite _sprite;
	sf::Texture _texture;
	bool _isVisible;
	std::string _pathTextures[4];
	TowerMenuButton _buttons[4];
public:
	TowerMenu();
	bool getIsVisible();
	const TowerMenuButton* getButtons() const;
	void hide();
	void show();
	void validateClickOnTower(int, int, sf::RenderWindow& window);
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	sf::FloatRect getGlobalBounds() const {								//-----BORRAR------//
		return getTransform().transformRect(_sprite.getGlobalBounds());
	}
};
