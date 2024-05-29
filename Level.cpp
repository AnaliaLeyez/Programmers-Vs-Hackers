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

int Level::getIdLevel() const { return _idLevel; }
bool Level::getFinisheLevel() const{ return _finishedLevel; }
UI Level::getUI() const { return _ui; }
Map Level::getMap() const { return *_map; }
int(*Level::getMapArray())[30] { return _mapArray; }
const std::vector<Spot*> Level::getSpots() const { return _spots; }
int Level::getGolden() { return _golden; }
int Level::getEnergy() const { return _energy; }
sf::SoundBuffer Level::getBuffer() const { return _buffer; }
sf::Sound Level::getSound() const { return _sound; }
bool Level::getMusicPlaying() const { return _musicPlaying; }
sf::Vector2f Level::getHackerStartPosition() const { return _hackerStartPosition; }
const std::list<Tower> Level::getTowersAvailable() const { return _towersAvailable;}
std::list<Tower> Level::getActiveTowers() const { return _activeTowers; }

void Level::setIdLevel(int idLevel) { _idLevel = idLevel; }
void Level::setFinishedLevel(bool finished) { _finishedLevel = finished; }
void Level::setUI(const UI& ui) { _ui = ui; }
void Level::setMap(const Map& map) { *_map = map; }
void Level::setMapArray(const int(&mapArray)[20][30]) {	std::copy(&mapArray[0][0], &mapArray[0][0] + 20 * 30, &_mapArray[0][0]); }
void Level::setGolden(int golden) { _golden = golden; }
void Level::setEnergy(int energy) { _energy = energy; }
void Level::setMusicPlaying(bool playing) { _musicPlaying = playing; }
void Level::setSound(bool play) { play ? _sound.play() : _sound.pause(); }
void Level::setTowersAvailable(Tower towerAvailable) { _towersAvailable.push_back(towerAvailable); }
void Level::setActiveTowers(Tower tower) { _activeTowers.push_back(tower); }
void Level::setSpot(Spot* sp, int spotNumber) {
	for (auto& spot : _spots) {
		if (spot->getSpotNumber() == spotNumber) {
			spot = sp;
			break;
		}
	}
}
//void Level::setCurrentSpot(Spot& sp){
//	*_currentSpot = sp;
//}
//void Level::shoot(sf::Vector2f position)
//{
//	//_bullets.push_back(Bullet(position, _hacker.getPosition()));
//}

void Level::mouseCheck(sf::Vector2i& mousePosition)
{
	sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(sf::Vector2f(mousePosition));
	for (auto& spot : _spots)
	{
		if (spot->getGlobalBounds().contains(transformedMousePos))
		{
			spot->setMouseHover(true);
		}
		else
		{
			spot->setMouseHover(false);
		}
	}
}
void Level::validateClick(int mousex, int mousey)
{
	TowerMenu& currentMenu= TowerMenu::getInstance();
	Spot currentSpot = currentMenu.getCurrentSpot();
	int clickSpot = validateClickOnSpot(mousex, mousey);
	if (clickSpot != 0) { //si NO se clickeo spot el spotNumber es 0
		currentSpot.setSpotNumber(clickSpot); //solo quiero guardar nro de spot !=0
	}
	
	currentMenu.setCurrentSpot(currentSpot);
	if(clickSpot!=0){ //si se clickeo spot
		manageClickOnSpot(mousex, mousey, currentSpot);
	}else { //si NO se clickeo spot
		manageOutOfSpotClick(mousex, mousey);
	}
	TowerMenu::setInstance(currentMenu);
	Manager& mg = Manager::getInstance();
	Level level = mg.getInstance().getLevel();
	//level.setCurrentMenu(currentMenu); //no me deja, si no hago esto la info del current menu se pierde
	level.setSpot(&currentSpot, currentSpot.getSpotNumber());
	mg.setLevel(level);
	Manager::setInstance(mg);
	validateClickOnSpeaker(mousex, mousey);
}
int Level::validateClickOnSpot(int mousex, int mousey) {
	TowerMenu& currentMenu = TowerMenu::getInstance();
	if (!currentMenu.getIsVisible()) {
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
	TowerMenu& currentMenu = TowerMenu::getInstance();
	currentMenu.setCurrentSpot(currentSp);
	currentMenu.setPosition(transformedMousePos); //ver como hacemos que la posicion de la torre quede siempre centrada en spot. O por ahora ignoramos esto
	//validar si el spot esta ocupado o no:
	if (currentSp.getIsOccupied()) { //spot ocupado
		//se muestra OTRO menu
		std::cout << "aca va el menu2";
	}
	else {  //spot libre
		currentMenu.setCurrentSpot(currentSp); //guardo el nro de spot en el tower Menu;
	//	if(currentMenu.getCurrentSpot().getSpotNumber()!=0) //no deberia necesitar esta linea... estoy probando si cambia en algo
			currentSp.setCurrentTower(currentMenu.getCurrentSpot().getCurrentTower()); //me aseguro que el currentSpot esta asociado a la tower ahora
		if (!currentMenu.getIsVisible()) { //se clickeo en un spot libre y el menu no era visible
			sf::Vector2f transformedMousePos = getInverseTransform().transformPoint(mousex, mousey);
			currentMenu.setPosition(transformedMousePos); //ver como hacemos que la posicion de la torre quede siempre centrada en spot. O por ahora ignoramos esto
			currentMenu.show();
		}
		else { //se clickeo en un spot libre y el menu era visible
			currentMenu.hide();
		}
		TowerMenu::setInstance(currentMenu);  //actualizo estado del current menu
		Manager& mg = Manager::getInstance();
		Level level = mg.getInstance().getLevel();
		level.setSpot(&currentSp, currentSp.getSpotNumber());
	//	level.setCurrentMenu(currentMenu); //no me deja, si no hago esto la info del current menu se pierde
		mg.setLevel(level);
		Manager::setInstance(mg);
	}
	
}
void Level::manageOutOfSpotClick(int mousex, int mousey) {
	TowerMenu& currentMenu = TowerMenu::getInstance();
	Spot sp = currentMenu.getCurrentSpot();
	if (currentMenu.getIsVisible()) { //click fuera de spot y towerMenu estaba visible
		currentMenu.validateClickOnButton(mousex, mousey, &sp);
		currentMenu.hide();
	}
	sp.setSpot(sp.getSpotNumber(), sp.getIsOccupied());
	currentMenu.setCurrentSpot(sp);
	TowerMenu::setInstance(currentMenu);
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

void Level::update(sf::Vector2i& mousePosition) {
	if (!getFinisheLevel()) {
		TowerMenu& currentMenu = TowerMenu::getInstance();
		currentMenu.update(mousePosition);
		TowerMenu::setInstance(currentMenu);
		mouseCheck(mousePosition);

	//_tower.update();

	//for (Bullet& bullet : _bullets) {
	//	bullet.update();
	//}

	//auto it = _bullets.begin();

	//while (it != _bullets.end()) {
	//	Bullet& bullet = *it;
	//	bullet.update();
	///*	if (bullet.getPosition().x > torrecitaPrueba.getRango().getLocalBounds().getSize().x) {
	//		it = _bullets.erase(it);
	//	}
	//	else {
	//		++it;
	//	}*/
	//}

		//ver como hacer esta comprobacion, asi como lo escribi sirve para vectores pero no para listas
		//auto it = *_waveList->begin();
		//if ( it != *_waveList->end()) {}
		
		//actualizo cada oleada si es que coexisten:
		//for (Wave& wave : *_waveList) {
		//	for (Hacker& hacker : wave.getWave1())
			//hacker.update(getMapArray());
		//	for (Hacker& hacker : wave.getWave2())
		//		hacker.update(getMapArray());
		//}
	}
	else {
		if (getIdLevel() < 4) { //aca digo que solo puede llegar hasta el nivel 4
			Manager::getInstance().setNumberLevel(getIdLevel() + 1); //cambia al siguiente nivel
		}
		else {
			//logica para cuando se termina el juego, cuando se pasaron todos los niveles
		}
	}
}
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	states.transform *= getTransform();
	target.draw(*_map, states);
	target.draw(_ui, states);
	for (Spot* spot : _spots) {  //luego de "comprar" torre, el spot trae basura
		target.draw(*spot, states);
		/*if (spot->getIsOccupied()) {
			target.draw(spot->getCurrentTower(), states);
		}*/
	}
	for (Tower tower : _activeTowers) {
		target.draw(tower, states);
	}
	for (std::list<Hacker> wave : _waves) {
		for (Hacker hacker : wave) {
			target.draw(hacker, states);
		}
	}
	TowerMenu& currentMenu = TowerMenu::getInstance();
	target.draw(currentMenu, states);
}