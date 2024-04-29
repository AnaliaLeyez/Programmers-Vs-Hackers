#include "funcionesGlobales.h"

void cargarSprite(sf::Sprite &sprite, sf::Texture &texture, std::string ruta, int posX, int posY, float scaleX, float scaleY) {

	if (!texture.loadFromFile(ruta)) {
		std::cout << "Error al cargar img. Ruta: " << ruta;
	}
	sprite.setTexture(texture);
	sprite.setPosition(posX, posY);
	sprite.setScale(scaleX, scaleY);
	sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
}