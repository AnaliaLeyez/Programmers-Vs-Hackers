#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Map3.h"

Map3::Map3() {
	if (!_tileMap.loadFromFile("img/maps/map3.png")) {
		throw std::runtime_error("Error al cargar la textura del tilest");
	}
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 30; x++) {
			_sprite.setTexture(_tileMap);
			_sprite.setTextureRect(sf::IntRect(x * 32, y * 32, 32, 32));
			_sprite.setPosition(32 * x, 32 * y);
			_tiles.push_back(_sprite);
		}
	}
}