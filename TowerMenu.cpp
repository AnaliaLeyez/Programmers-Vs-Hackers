#include <SFML/Graphics.hpp>
#include <iostream> //una vez que todo funcione, esta libreria se va
#include "Spot.h"
#include "Button.h"
#include "ButtonBrian.h"
#include "TowerMenu.h"


bool TowerMenu::getIsVisible() { return _isVisible; }
Button* TowerMenu::getButtonByIndex(int i) const { return _buttons[i]; }
Spot* TowerMenu::getCurrentSpot() const { return _currentSpot; }
int TowerMenu::getNumberMenu() const { return _NumberMenu; }
void TowerMenu::setCurrentSpot(Spot* sp) { _currentSpot = sp; }
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

void TowerMenu::adjustPosition()
{
	sf::Vector2f spotPosition = _currentSpot->getPosition();
	sf::FloatRect menuBounds = _sprite.getGlobalBounds();

	// Adjust if near the left or right edge
	if (spotPosition.x - menuBounds.width / 2 < 0) {
		spotPosition.x = menuBounds.width / 2;
	}
	else if (spotPosition.x + menuBounds.width / 2 > 960) {
		spotPosition.x = 960 - menuBounds.width / 2;
	}

	// Adjust if near the top or bottom edge
	if (spotPosition.y - menuBounds.height / 2 < 0) {
		spotPosition.y = menuBounds.height / 2;
	}
	else if (spotPosition.y + menuBounds.height / 2 > 640) {
		spotPosition.y = 640 - menuBounds.height / 2;
	}

	setPosition(spotPosition);
}
