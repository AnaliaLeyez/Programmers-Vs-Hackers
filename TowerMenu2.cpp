#include <SFML/Graphics.hpp>
#include <iostream> //una vez que todo funcione, esta libreria se va
#include "Manager.h" //revisar que includes son necesarios, solo los copie del towerMenu
#include "Level.h"
#include "Spot.h"
#include "Button.h"
#include "ButtonCashSale.h"
#include"ButtonBrian.h"
#include "ButtonUpgrade.h"
#include "TowerMenu.h"
#include "TowerMenu2.h"

TowerMenu2::TowerMenu2()
{
	_isVisible = false;
	if (!_texture.loadFromFile("img/menuContextual/tower_menu_circle.png")) {
		throw std::runtime_error("Error img Menu Circle");
	}
	_sprite.setTexture(_texture);
	_sprite.setOrigin(_sprite.getLocalBounds().width / 2, _sprite.getLocalBounds().height / 2);
	_sprite.setScale(0.4f, 0.4f);

	//Buttons initialization
	Button* btn = new ButtonUpgrade(); //aca va el boton de upgrade (que tiene img de espada)
	_buttons.push_back(btn);
	btn = new ButtonCashSale();  //con esta linea se rompe
	_buttons.push_back(btn);

	_buttons[0]->setPosition(0, -100);
	_buttons[1]->setPosition(0, 85);
	_buttons[0]->setBtnNumber(1);
	_buttons[1]->setBtnNumber(2);

	Spot sp;
	setCurrentSpot(sp);
}
bool TowerMenu2::getIsVisible() { return _isVisible; }
//const Button* TowerMenu2::getButtons() const { return *_buttons; }
const std::vector <Button*> TowerMenu2::getButtons() const { return _buttons; }
Button* TowerMenu2::getButtonByIndex(int i) const { return _buttons[i]; }
Spot TowerMenu2::getCurrentSpot() const { return _currentSpot; }
void TowerMenu2::setCurrentSpot(Spot sp) { _currentSpot = sp; }
void TowerMenu2::setButton(bool states, int i) { _buttons[i]->setMouseHover(states); }

void TowerMenu2::hide() { _isVisible = false; }
void TowerMenu2::show() { _isVisible = true; }

void TowerMenu2::mouseCheck(sf::Vector2i& mousePosition)
{
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(sf::Vector2f(mousePosition));
	for (auto& button : _buttons)
	{
		if (button->getGlobalBounds().contains(transformedMousePos))
		{
			button->setMouseHover(true);
		}
		else
		{
			button->setMouseHover(false);
		}
	}
}

Button* TowerMenu2::validateClickOnButton(int mousex, int mousey, Spot& spot) {
	sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(mousex), static_cast<float>(mousey));
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(mousePos);
	for (Button* button : _buttons) { //si quiero reutilizar esta funcion el 4 lo debo reemplazar por una variable xq en menu2 son 2 botones
		if (button->getGlobalBounds().contains(transformedMousePos)) {
			return button;
		}
	}
	Button* btn = new ButtonBrian();
	btn->setBtnNumber(-1);
	return btn;
}

void TowerMenu2::update(sf::Vector2i& mousePosition) {
	if (getIsVisible()) {
		for (Button* button : _buttons)
		{
			button->update(mousePosition);;
		}
	}
}
void TowerMenu2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
	for (Button* button : _buttons)
	{
		target.draw(*button, states);
	}
}

sf::FloatRect TowerMenu2::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds());
}