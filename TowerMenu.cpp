#include <SFML/Graphics.hpp>
#include <iostream> //una vez que todo funcione, esta libreria se va
#include "Manager.h"
#include "Level.h"
#include "Spot.h"
#include "TowerMenuButton.h"
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

	//Buttons initialization
	_buttons[0] = new ButtonBrian();
	_buttons[1] = new ButtonMaxiSar();
	_buttons[2] = new ButtonMaxiWenner();
	_buttons[3] = new ButtonKloster();

	_buttons[0]->setPosition(0, -100);
	_buttons[1]->setPosition(85, 0);
	_buttons[2]->setPosition(0, 85);
	_buttons[3]->setPosition(-100, 0);

	for (int i = 0; i < 4; i++) {
		_buttons[i]->setBtnNumber(i);
	}
	Spot sp;
	setCurrentSpot(sp);
}

bool TowerMenu::getIsVisible(){	return _isVisible; }
const TowerMenuButton* TowerMenu::getButtons() const { return *_buttons; }
TowerMenuButton* TowerMenu::getButtonByIndex(int i) const { return _buttons[i]; }
Spot TowerMenu::getCurrentSpot() const { return _currentSpot; }
void TowerMenu::setCurrentSpot(Spot sp) { _currentSpot = sp; }

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

void TowerMenu::validateClickOnButton(int mousex, int mousey, Spot& spot) {
	Manager& mg = Manager::getInstance();
	Level level = mg.getLevel();
	sf::Vector2f mousePos = sf::Vector2f(static_cast<float>(mousex), static_cast<float>(mousey));
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(mousePos);

	for (int i = 0; i < 4; i++) {
		if (_buttons[i]->getGlobalBounds().contains(transformedMousePos)) {
			if (level.validateSale(_buttons[i])) {
				level= level.sell(_buttons[i]->getTower(), _currentSpot);
				mg.setLevel(level);
			}
			else {
				std::cout << "Sos pobre: ";
			}
		}
	}
}

void TowerMenu::update(sf::Vector2i& mousePosition) {
	if (getIsVisible()) {
		//for (auto& button : _buttons)
		//{
		//	button->update(mousePosition);
		//}
		for (int i = 0; i < 4; i++) {
			_buttons[i]->update(mousePosition);
		}
	}
}
void TowerMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
		states.transform *= getTransform();
		target.draw(_sprite, states);
		for (int i = 0; i < 4; i++) {
			target.draw(*_buttons[i], states);
		}
		/*for (auto& button : _buttons)
		{
			target.draw(*button, states);
		}*/
}

sf::FloatRect TowerMenu::getGlobalBounds() const {
	return getTransform().transformRect(_sprite.getGlobalBounds());
}