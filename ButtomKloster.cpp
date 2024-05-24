#include <SFML/Graphics.hpp>
#include <iostream>
#include "TowerKloster.h"
#include "TowerMenuButton.h"
#include "ButtomKloster.h"

ButtomKloster::ButtomKloster()
{
	_mouseOver = false;
	if (!_texture.loadFromFile("img/menuContextual/button_tower_menu_kloster.png"))
	{
		std::cout << "Loading error. " << std::endl;
	}
	_sprite.setTexture(_texture);
	_sprite.setScale(0.7f, 0.7f);
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);
	_tower = new TowerKloster();
}
