#include <SFML/Graphics.hpp>
#include <iostream> //una vez que todo funcione, esta libreria se va
#include "Manager.h" //revisar que includes son necesarios, solo los copie del towerMenu
#include "Level.h"
#include "Spot.h"
#include "TowerMenuButton.h"
#include "ButtonCashSale.h"
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
	_buttons[0] = new ButtonUpgrade(); //aca va el boton de upgrade (que tiene img de espada)
	_buttons[1] = new ButtonCashSale();  //con esta linea se rompe

	_buttons[0]->setPosition(0, -100);
	_buttons[1]->setPosition(0, 85);
	//_buttons[0]->setPrice();

	Spot sp;
	setCurrentSpot(sp);
}
bool TowerMenu2::getIsVisible() { return _isVisible; }
const TowerMenuButton* TowerMenu2::getButtons() const { return *_buttons; }
TowerMenuButton* TowerMenu2::getButtonByIndex(int i) const { return _buttons[i]; }
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

TowerMenuButton TowerMenu2::validateClickOnButton(int mousex, int mousey, Spot& spot) {
	sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(mousex), static_cast<float>(mousey));
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(mousePos);
	for (int i = 0; i < 4; i++) {
		if (_buttons[i]->getGlobalBounds().contains(transformedMousePos)) {
			return *_buttons[i];
		}
	}
	TowerMenuButton btn;
	btn.setBtnNumber(-1);
	return btn;
}

void TowerMenu2::update(sf::Vector2i& mousePosition) {
	if (getIsVisible()) {
		for (int i = 0; i < 2; i++) {
			_buttons[i]->update(mousePosition);
		}
	}
}
void TowerMenu2::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
	for (int i = 0; i < 2; i++) {
		target.draw(*_buttons[i], states);
	}
}

sf::FloatRect TowerMenu2::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds());
}