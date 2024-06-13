#include <iostream> //borrar
#include <vector>
#include <list>
#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "UI.h"
#include "Map.h"
#include "Manager.h"
#include "TowerMenu.h"
#include "Spot.h"
#include "Tower.h"
#include "Level.h"

void Level::validateClick(int mousex, int mousey)
{
	Spot currentSpot; //nuevo
	int clickSpot = validateClickOnSpot(mousex, mousey);
	if (clickSpot != 0)
	{ //si se clickeo spot, esto devuelve el nro de spot
		currentSpot = getSpotByNumber(clickSpot);
		currentSpot.setSpotNumber(clickSpot);
		currentSpot.setOccupied(getSpotByNumber(currentSpot.getSpotNumber()).getIsOccupied());
		_currentMenu->setCurrentSpot(currentSpot);  //si se clickeo en spot e estoy diciendo a menu q se asocie a ese spot, sino nose
		manageClickOnSpot(mousex, mousey, currentSpot); //currentSpot tiene el nro de spot y el estado
	}
	else 
	{ //si NO se clickeo spot
		currentSpot = _currentMenu->getCurrentSpot();
		currentSpot = manageOutOfSpotClick(mousex, mousey);
	}
	setSpot(&currentSpot);

	validateClickOnSpeaker(mousex, mousey);
}
int Level::validateClickOnSpot(int mousex, int mousey) 
{
	if (!_currentMenu->getIsVisible()) {
		for (auto& spot : _spots) {
			if (spot->getGlobalBounds().contains(mousex, mousey)) {
				return spot->getSpotNumber();
			}
		}
	}
	return 0;  //seria como decir "no se clickeo en ningun spot"
}
void Level::manageClickOnSpot(int mousex, int mousey, Spot& currentSp) {
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(mousex, mousey);
	_currentMenu->setCurrentSpot(currentSp);
	_currentMenu->setPosition(transformedMousePos); //ver como hacemos que la posicion de la torre quede siempre centrada en spot. O por ahora ignoramos esto
	//validar si el spot esta ocupado o no:
	if (currentSp.getIsOccupied()) { //spot ocupado
		_currentMenu = _menu2;
		if (!_currentMenu->getIsVisible()) { //se clickeo en un spot ocupado y el menu2 no era visible
			std::cout << "aca va el menu2" << std::endl;
			_currentMenu->setCurrentSpot(currentSp); //guardo el nro de spot en el tower Menu2;
			_currentMenu->setPosition(currentSp.getPosition());
			_currentMenu->show();
		}
		else { //se clickeo en un spot ocupado y el menu2 era visible
			_currentMenu->hide();
		}
	}
	else 
	{  //spot libre
		//_currentMenu2->hide(); //Necesario, en caso q se haya estado mostrando por otro spot
		_currentMenu = _menu1;
		currentSp.setCurrentTower(_currentMenu->getCurrentSpot().getCurrentTower()); //me aseguro que el currentSpot esta asociado a la tower ahora
		if (!_currentMenu->getIsVisible()) { //se clickeo en un spot libre y el menu no era visible
			_currentMenu->setPosition(currentSp.getPosition()); //ver como hacemos que la posicion de la torre quede siempre centrada en spot. O por ahora ignoramos esto
			_currentMenu->show();
		}
		else { //se clickeo en un spot libre y el menu era visible
			_currentMenu->hide();
		}
	}
	setCurrentSpot(currentSp);
	setSpot(&currentSp);
}
Spot Level::manageOutOfSpotClick(int mousex, int mousey) {
	Spot sp;  //DEBERIA SER PUNTERO
	if (_currentMenu->getIsVisible()) { //click fuera de spot y towerMenu estaba visible
		std::cout << "manageOutOfSpot-SP: " << sp.getPosition().x << std::endl;
		sp = _currentMenu->getCurrentSpot(); //sp ya viene con su nro q se seteo previamente al hacer click en el spot
		
		if (_currentMenu->getNumberMenu() == 1) {
			clickWithMenu1Open(mousex, mousey, sp);
		}
		else {
			clickWithMenu2Open(mousex, mousey, sp);
		}
		_currentMenu->setCurrentSpot(sp); //guardo la informacion del spot en el Menu
	}
	setSpot(&sp);
	return sp;
}
void Level::clickWithMenu1Open(int mousex, int mousey, Spot& sp)
{
	Button* btn = _currentMenu->validateClickOnButton(mousex, mousey, sp);

	std::cout << " clickWithMenu1Open sp: " << sp.getPosition().x << std::endl;

	if (btn->getBtnNumber() != -1) {  //se hizo click en un boton

		if (validateSale(btn->getTower(), true)) {
			Tower* tower = btn->getTower()->clone(); // Crear una nueva instancia de la torre
				sell(tower, sp);

				tower->setSpotNumber(sp.getSpotNumber());
				//tower->setOrigin(sp.getOrigin()); //nuevo

				std::cout<<"ANTES DE SETEAR: " << sp.getPosition().x << " " << sp.getPosition().y << std::endl;

				//tower->_sprite.setPosition(sp.getInverseTransform().transformPoint(sp.getPosition()));
				tower->_sprite.setPosition(sp.getPosition());
				//tower->_visualRange.setPosition(sp.getInverseTransform().transformPoint(sp.getPosition()));
				tower->_visualRange.setPosition(sp.getPosition());

				sf::CircleShape debugCircle(10);
				debugCircle.setFillColor(sf::Color::Red);
				debugCircle.setPosition(sp.getPosition());
				_debugShapes.push_back(debugCircle);

				std::cout << "DESPUES DE SETEAR: " << std::endl;
				//std::cout << tower->_sprite.getPosition().x << " " << tower->_sprite.getPosition().y << std::endl;
				//std::cout << tower->_visualRange.getPosition().x << " " << tower->_visualRange.getPosition().y << std::endl;
				//tower->setPosition(sp.getInverseTransform().transformPoint(sp.getPosition()));
				std::cout << " - - - - " << std::endl;


				setActiveTowers(tower);
				setSpot(&sp); //CUIDADO esta linea parece innecesaria pero la saco y se rompe el programa
				std::cout << "2# SPOT: " << sp.getPosition().x << " " << sp.getPosition().y << std::endl;
		}
		else {
			_noCoinsClock.restart(); //NUEVO reseteo el clock para que se muestre el cartel
		}
	}
	_currentMenu->hide();
}
void Level::clickWithMenu2Open(int mousex, int mousey, Spot& sp)
{
	Button* btn = _currentMenu->validateClickOnButton(mousex, mousey, sp);
	Tower* tower = sp.getCurrentTower();

	if (btn->getBtnNumber() == 1) {  //se hizo click en el boton 1 que es upgrade:
		
		std::cout << "UPGRADE" << std::endl;
		//validar si alcanza el dinero
		if (validateSale(tower, false)) {
			
				sell(tower, sp);
				tower->setSpotNumber(sp.getSpotNumber());
				tower->setOrigin(sp.getOrigin()); //nuevo
				setActiveTowers(tower);
				setSpot(&sp); //CUIDADO esta linea parece innecesaria pero la saco y se rompe el programa
				tower->upgrade();
				std::cout << "se compro: " << tower->getName() << std::endl;
				std::cout << "nuevo danio" << tower->getDamage() << std::endl;
		}
		else {
			_noCoinsClock.restart(); // reseteo el clock para que se muestre el cartel
		}
		
	}
	else if (btn->getBtnNumber() == 2) {
		resellTower(sp);
		
	}

	_currentMenu->hide();
}
void Level::validateClickOnSpeaker(int mousex, int mousey) {
	if (_ui.getSpeaker().getGlobalBounds().contains(mousex, mousey)) {
		if (getMusicPlaying()) {
			setSound(false);
			setMusicPlaying(false);
			_ui.setTextureSpeaker("img/complementarias/mute.png");
		}
		else {
			setSound(true);
			setMusicPlaying(true);
			_ui.setTextureSpeaker("img/complementarias/musicOn.png");
		}
	}
}
