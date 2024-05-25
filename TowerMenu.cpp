#include <SFML/Graphics.hpp>
#include <iostream> //una vez que todo funcione, esta libreria se va
#include "TowerMenuButton.h"
#include "ButtomBrian.h"
#include "ButtomKloster.h"
#include "ButtomMaxiSar.h"
#include "ButtomMaxiWenner.h"
#include "TowerMenu.h"

TowerMenu::TowerMenu()
{
	_isVisible = false;
	if (!_texture.loadFromFile("img/menuContextual/tower_menu_circle.png")) {
		throw std::runtime_error("Error img Menu Circle");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
	_sprite.setScale(0.4f, 0.4f);

	//Buttons initialization
	_buttons[0] = new ButtomBrian();
	_buttons[1] = new ButtomMaxiSar();
	_buttons[2] = new ButtomMaxiWenner();
	_buttons[3] = new ButtomKloster();

	_buttons[0]->setPosition(0, -100);  //sumar la posicion relativa del menu
	_buttons[1]->setPosition(85, 0);
	_buttons[2]->setPosition(0, 85);
	_buttons[3]->setPosition(-100, 0);

	// Set the positions relative to the menu
	//for (int x = 0; x < 4; x++) {
	//	_buttons[x]->move(_sprite.getPosition()); // This assumes _sprite's position is the menu's position
	//}
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
	return *_buttons;
}

void TowerMenu::hide() {
	_isVisible = false; 
}

void TowerMenu::show() { 
	_isVisible = true;
}

void TowerMenu::validateClickOnTower(int mousex, int mousey) {

	sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(mousex), static_cast<float>(mousey));
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(mousePos);
	for (int i = 0; i < 4; i++) {
	//	sf::FloatRect buttonBounds =;
		if (_buttons[i]->getGlobalBounds().contains(transformedMousePos)) {
			std::cout << "se clickeo en: " << _buttons[i]->getTower().getName() << std::endl;
			//validateSale();
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
			target.draw(*_buttons[i], states);
		}
		//for (const auto& button : _buttons)
		//{
		//	target.draw(button, states);
		//}
	}
	
}