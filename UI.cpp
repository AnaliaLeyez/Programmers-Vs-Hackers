#include "UI.h"
#include <iostream>

UI::UI() {
	if (!textureMonedas.loadFromFile("img/complementarias/oro.png")) {
		std::cout << "Error al cargar img Oro";
	};
	monedas.setSize(sf::Vector2f(80, 70));
	monedas.setTexture(&textureMonedas);
	monedas.setPosition(500, 10);
	if (!textureRayo.loadFromFile("img/complementarias/energia.png")) {
		std::cout << "Error al cargar img rayo";
	};
	rayo.setSize(sf::Vector2f(75, 75));
	rayo.setTexture(&textureRayo);
	rayo.setPosition(340, 10);
	//monedas.setOrigin(monedas.getGlobalBounds().width / 2, monedas.getGlobalBounds().height / 2);
	if (!font.loadFromFile("fuentes/fuenteMenu.ttf")) {
		std::cout << "Error al cargar la fuente del Menu \n";
	}
	for (int i = 0; i < 3; i++) {
		text[i].setFont(font);
		text[i].setCharacterSize(30);
		int posX, posY;
		std::string texto;
		switch (i)
		{
		case 0:
			posX = 590;
			posY = 20;
			texto = "500";
			break;
		case 1:
			posX = 400;
			posY = 20;
			texto = "600";
			break;
		case 2:
			posX = 800;
			posY = 700;
			texto = "Menu";
			break;
		default:
			break;
		}
		text[i].setPosition(posX, posY);
		text[i].setString(texto);
		//text[i].setOrigin(text[i].getGlobalBounds().getPosition().x / 2, text[i].getGlobalBounds().height / 2);
		text[i].setFillColor(sf::Color(255, 255, 255));
	}
}
void UI::draw(sf::RenderTarget& rt, sf::RenderStates rs) const {
	rt.draw(monedas, rs);
	rt.draw(rayo, rs);
	for (int i = 0; i < 3; i++) {
		rt.draw(text[i], rs);
	}
}