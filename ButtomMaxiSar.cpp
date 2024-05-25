#include <SFML/Graphics.hpp>
#include <iostream>
#include "TowerSarF.h"
#include "TowerMenuButton.h"
#include "ButtomMaxiSar.h"

ButtomMaxiSar::ButtomMaxiSar()
{
	_mouseHover = false;
	if (!_texture.loadFromFile("img/menuContextual/button_tower_menu_maxiSar.png"))
	{
		throw std::runtime_error("Error img Buttom Sar F");
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(0.7f, 0.7f);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_tower = new TowerSarF();
}

