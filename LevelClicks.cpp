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
	if (clickSpot != 0) { //si se clickeo spot, esto devuelve el nro de spot
		currentSpot = getSpotByNumber(clickSpot);
		currentSpot.setSpotNumber(clickSpot);
		currentSpot.setOccupied(getSpotByNumber(currentSpot.getSpotNumber()).getIsOccupied());
		_currentMenu->setCurrentSpot(currentSpot);  //si se clickeo en spot e estoy diciendo a menu q se asocie a ese spot, sino nose
		manageClickOnSpot(mousex, mousey, currentSpot); //currentSpot tiene el nro de spot y el estado
	}
	else { //si NO se clickeo spot
		currentSpot = _currentMenu->getCurrentSpot();
		currentSpot = manageOutOfSpotClick(mousex, mousey);
	}
	setSpot(&currentSpot, currentSpot.getSpotNumber());

	validateClickOnSpeaker(mousex, mousey);
}
int Level::validateClickOnSpot(int mousex, int mousey) {
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
		std::cout << "aca va el menu2";
		_currentMenu2->setPosition(currentSp.getPosition());
		_currentMenu2->show();
	}
	else {  //spot libre
		_currentMenu->setCurrentSpot(currentSp); //guardo el nro de spot en el tower Menu;
		currentSp.setCurrentTower(_currentMenu->getCurrentSpot().getCurrentTower()); //me aseguro que el currentSpot esta asociado a la tower ahora
		if (!_currentMenu->getIsVisible()) { //se clickeo en un spot libre y el menu no era visible
			_currentMenu->setPosition(transformedMousePos); //ver como hacemos que la posicion de la torre quede siempre centrada en spot. O por ahora ignoramos esto
			_currentMenu->show();
		}
		else { //se clickeo en un spot libre y el menu era visible
			_currentMenu->hide();
		}
	}
	setCurrentSpot(currentSp);
	setSpot(&currentSp, currentSp.getSpotNumber());
}
Spot Level::manageOutOfSpotClick(int mousex, int mousey) {
	Spot sp = _currentMenu->getCurrentSpot(); //sp ya viene con su nro q se seteo previamente al hacer click en el spot
	if (_currentMenu->getIsVisible()) { //click fuera de spot y towerMenu estaba visible

		///TODO ESTO DEBERIA IR EN UNA FUNCION: clickWithMenu1Open(mousex, mousey, sp)  sp por REFERENCIA
		TowerMenuButton btn = _currentMenu->validateClickOnButton(mousex, mousey, sp);
		if (btn.getBtnNumber() != -1) {  //se hizo click en un boton
			if (validateSale(&btn)) { //veo si habilito venta
				Tower tower = btn.getTower();
				sell(tower, sp);
				tower.setSpotNumber(sp.getSpotNumber());
				//asi como se manda tower, hay que mandar la info del spot a level para q sepa q spot esta ocupado:
				tower.setSpotNumber(sp.getSpotNumber());

				tower._sprite.setPosition(sp.getPosition());  ///ESTO LO PUSO ADRI, VER SI PODEMOS CAMBIARLO, EL ATRIBUTO DEBE SER PRIVADO
				tower._visualRange.setPosition(sp.getPosition()); ///ESTO LO PUSO ADRI, VER SI PODEMOS CAMBIARLO, EL ATRIBUTO DEBE SER PRIVADO
				tower.setPosition(sp.getPosition());
				setActiveTowers(tower);
				setSpot(&sp, sp.getSpotNumber());
			}
			else {
				_noCoinsClock.restart(); //NUEVO reseteo el clock para que se muestre el cartel
			}
		}
		_currentMenu->hide();
		_currentMenu2->hide();
	}

	//else if(_currentMenu2->getIsVisible()){
	// TowerMenuButton btn = _currentMenu->validateClickOnButton(mousex, mousey, sp);
	// }

	_currentMenu->setCurrentSpot(sp); //guardo la informacion del spot en el Menu
	setSpot(&sp, sp.getSpotNumber());
	return sp;
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
