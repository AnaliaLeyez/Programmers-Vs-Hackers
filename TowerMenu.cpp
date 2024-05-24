#include <SFML/Graphics.hpp>
#include <iostream>
#include "TowerMenuButton.h"
#include "TowerMenu.h"

TowerMenu::TowerMenu()
{
	_isVisible = false;
	if (!_texture.loadFromFile("img/menuContextual/tower_menu.png")) {
		std::cout << "NO CARGO" << std::endl;
	}
	std::string route = "img/menuContextual/";

	_pathTextures[0] = route + "button_tower_menu_brian.png";
	_pathTextures[1] = route + "button_tower_menu_maxiSar.png";
	_pathTextures[2] = route + "button_tower_menu_maxiWen.png";
	_pathTextures[3] = route + "button_tower_menu_kloster.png";

	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
	_sprite.setScale(0.5, 0.5);

	//Buttons initialization
	for (int x = 0; x < 4; x++)
	{
		_buttons[x].setTexture(_pathTextures[x]);
		_buttons[x].setScale(0.5f, 0.5f);
		_buttons[x].setOrigin(_buttons[x].getSprite().getGlobalBounds().width / 2, _buttons[x].getSprite().getGlobalBounds().height / 2);
	}

	_buttons[0].setPosition(0, -115);  //sumar la posicion relativa del menu
	_buttons[1].setPosition(115, 0);
	_buttons[2].setPosition(0, 115);
	_buttons[3].setPosition(-115, 0);

	// Set the positions relative to the menu
	for (int x = 0; x < 4; x++) {
		_buttons[x].move(_sprite.getPosition()); // This assumes _sprite's position is the menu's position
	}
	//_buttons[0].setPosition(0 + getPosition().x, -115);  //sumar la posicion relativa del menu
	//_buttons[1].setPosition(115 + getPosition().x, 0 + getPosition().y);
	//_buttons[2].setPosition(0 + getPosition().x, 115 + getPosition().y);
	//_buttons[3].setPosition(-115 + getPosition().x, 0 + getPosition().y);
}

bool TowerMenu::getIsVisible()
{
	return _isVisible;
}
const TowerMenuButton* TowerMenu::getButtons() const {
	return _buttons;
}

void TowerMenu::hide() {
	_isVisible = false; 
}

void TowerMenu::show() { 
	_isVisible = true;
}

void TowerMenu::validateClickOnTower(int mousex, int mousey, sf::RenderWindow& window) {
	sf::Vector2f worldPos = window.mapPixelToCoords(sf::Vector2i(mousex, mousey));
	for (int i = 0; i < 4; i++) {
		//std::cout << "Button bounds: (" << _buttons[i].getSprite().getGlobalBounds().left << ", " << _buttons[i].getSprite().getGlobalBounds().top << ", " << _buttons[i].getSprite().getGlobalBounds().width << ", " << _buttons[i].getSprite().getGlobalBounds().height << ")";
		if (_buttons[i].getSprite().getGlobalBounds().contains(getPosition().x - static_cast<float>(mousex), getPosition().y- static_cast<float>(mousey))) {
			std::cout << std::endl << "FUNCIONA1" << std::endl;
		}
		
		if (_buttons[i].getSprite().getGlobalBounds().contains(worldPos)) {
			std::cout << "FUNCIONA (intento original)" << std::endl;
			//obtener el tipo de boton para luego crear esa torre
		}
	}
}

void TowerMenu::update() {
	//for (auto& button : _buttons)
	//{
	//	button.update();
	//}
}
void TowerMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (_isVisible)
	{
		states.transform *= getTransform();
		target.draw(_sprite, states);
		for (int i = 0; i < 4; i++) {
			target.draw(_buttons[i], states);
		}
		//for (const auto& button : _buttons)
		//{
		//	target.draw(button, states);
		//}
	}
	
}