#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include <iostream>

#include "Map.h"

void Map::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	for (const auto& tile : _tiles) {
		target.draw(tile, states);
	}
	_dying ? target.draw(_UTNRed, states) : target.draw(_UTN, states);  //la idea es que la UTN cambia de color
}