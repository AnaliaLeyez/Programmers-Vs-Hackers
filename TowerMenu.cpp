#include <SFML/Graphics.hpp>
#include <iostream> //una vez que todo funcione, esta libreria se va
#include "Manager.h"
#include "Level.h"
#include "Spot.h"
#include "Button.h"
#include "ButtonBrian.h"
#include "ButtonKloster.h"
#include "ButtonMaxiSar.h"
#include "ButtonMaxiWenner.h"
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

	Button* btn = new ButtonBrian(); //saque este formato de los spots.. pero necesito q cada boton sea distinto
	_buttons.push_back(btn);
	btn = new ButtonMaxiSar();
	_buttons.push_back(btn);
	btn = new ButtonMaxiWenner();
	_buttons.push_back(btn);
	btn = new ButtonKloster();
	_buttons.push_back(btn);

	_buttons[0]->setPosition(0, -100);
	_buttons[1]->setPosition(85, 0);
	_buttons[2]->setPosition(0, 85);
	_buttons[3]->setPosition(-100, 0);

	int i = 0;
	for (Button* button : _buttons) {
		button->setBtnNumber(i);
		//button->setPriceText();
		i++;
	}

	Spot sp;
	setCurrentSpot(sp);
}

bool TowerMenu::getIsVisible(){	return _isVisible; }
//const Button* TowerMenu::getButtons() const { return *_buttons; }
const std::vector <Button*> TowerMenu::getButtons() const { return _buttons; }
Button* TowerMenu::getButtonByIndex(int i) const { return _buttons[i]; }
Spot TowerMenu::getCurrentSpot() const { return _currentSpot; }
void TowerMenu::setCurrentSpot(Spot sp) { _currentSpot = sp; }
void TowerMenu::setButton(bool states, int i) { _buttons[i]->setMouseHover(states); }

void TowerMenu::hide() { _isVisible = false; }
void TowerMenu::show() { _isVisible = true; }

void TowerMenu::mouseCheck(sf::Vector2i& mousePosition)
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

Button* TowerMenu::validateClickOnButton(int mousex, int mousey, Spot& spot) { //aca deberia recibir tambien int quantityButtons
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

void TowerMenu::update(sf::Vector2i& mousePosition) {
	if (getIsVisible()) {
		for (Button* button : _buttons)
		{
			button->update(mousePosition);;
		}
	}
}
void TowerMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
	for (Button* button : _buttons)
	{
		target.draw(*button, states);
	}
}

sf::FloatRect TowerMenu::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds());
}