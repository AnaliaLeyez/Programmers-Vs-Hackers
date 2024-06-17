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
		if (currentSp.getCurrentTower()->getUpgradesAmount() != 0) {
			_currentMenu = _menu2;
			if (!_currentMenu->getIsVisible()) { //se clickeo en un spot ocupado y el menu2 no era visible
				std::cout << "--- ACA VA EL MENU 2 ---" << std::endl;
				_currentMenu->setCurrentSpot(currentSp); //guardo el nro de spot en el tower Menu2;
				_currentMenu->setCurrentTower(currentSp.getCurrentTower());

				Tower* tower = currentSp.getCurrentTower(); // CREAR UNA FUNCION PARA ESTAS LINEAS
				Button* btnUp = _currentMenu->getButtonByIndex(1);
				btnUp->setPrice(tower->getPriceUpgrade());
				btnUp->setDamage(tower->getDamageUpgrade());
				btnUp->setPriceText();
				btnUp->setInfo();
				Button* btnCashSale = _currentMenu->getButtonByIndex(0);
				btnCashSale->setPrice(tower->getSalesValue());
				btnCashSale->setPriceText();
				_currentMenu->setPosition(currentSp.getPosition());
				_currentMenu->show();
			}
			else { //se clickeo en un spot ocupado y el menu2 era visible
				_currentMenu->hide();
			}
		}
		else {
			_currentMenu = _menu3;
			if (!_currentMenu->getIsVisible()) { //se clickeo en un spot ocupado y el menu2 no era visible
				std::cout << "--- ACA VA EL MENU 3 ---" << std::endl;
				_currentMenu->setCurrentSpot(currentSp); //guardo el nro de spot en el tower Menu2;
				_currentMenu->setCurrentTower(currentSp.getCurrentTower());

				Tower* tower = currentSp.getCurrentTower(); // Crear una nueva instancia de la torre
				Button* btnCashSale = _currentMenu->getButtonByIndex(0);
				btnCashSale->setPrice(tower->getSalesValue());
				btnCashSale->setPriceText();
				_currentMenu->setPosition(currentSp.getPosition());
				_currentMenu->show();
			}
			else { //se clickeo en un spot ocupado y el menu3 era visible
				_currentMenu->hide();
			}
		}
	}
	else 
	{  //spot libre
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
	if (_currentMenu->getIsVisible())
	{
		//click fuera de spot y towerMenu estaba visible
		sp = _currentMenu->getCurrentSpot(); //sp ya viene con su nro q se seteo previamente al hacer click en el spot
		
		if (_currentMenu->getNumberMenu() == 1) 
		{
			clickWithMenu1Open(mousex, mousey, sp);
		}
		else 
		{
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
	
	if (btn->getBtnNumber() != -1) {  //se hizo click en un boton

		if (validateSale(btn->getTower(), true)) {
			Tower* tower = btn->getTower()->clone(); // Crear una nueva instancia de la torre
				sell(tower, sp);

				tower->setSpotNumber(sp.getSpotNumber());
				//tower->setOrigin(sp.getOrigin()); //nuevo

				//tower->_sprite.setPosition(sp.getInverseTransform().transformPoint(sp.getPosition()));
				tower->setPosition(0,0);
				//tower->_visualRange.setPosition(sp.getInverseTransform().transformPoint(sp.getPosition()));
				//tower->setPosition(sp.getPosition());

				setActiveTowers(tower);
				setSpot(&sp); //CUIDADO esta linea parece innecesaria pero la saco y se rompe el programa
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
