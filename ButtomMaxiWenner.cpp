#include <SFML/Graphics.hpp>
#include "TowerWenner.h"
#include "TowerMenuButton.h"
#include "ButtomMaxiWenner.h"

ButtomMaxiWenner::ButtomMaxiWenner()
{
	_mouseHover = false;
	if (!_texture.loadFromFile("img/menuContextual/button_tower_menu_maxiWen.png"))
	{
		throw std::runtime_error("Error img Buttom Wenner");
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(0.7f, 0.7f);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_tower = new TowerWenner();
}
