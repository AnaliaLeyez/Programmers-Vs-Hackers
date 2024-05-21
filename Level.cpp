#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "UI.h"
#include "Map.h"
#include "Manager.h"
#include "TowerMenu.h"
#include "Tower.h"
#include "Wave.h"

#include "Level.h"

int Level::getIdLevel() const { return _idLevel; }
bool Level::getFinisheLevel() const{ return _finishedLevel; }
UI Level::getUI() const { return _ui; }
Map Level::getMap() const { return *_map; }
int(*Level::getMapArray())[30] { return _mapArray; }
int Level::getGolden() const { return _golden; }
int Level::getEnergy() const { return _energy; }
sf::SoundBuffer Level::getBuffer() const { return _buffer; }
sf::Sound Level::getSound() const { return _sound; }
bool Level::getMusicPlaying() const { return _musicPlaying; }
std::list<Wave> Level::getWaveList() const { return *_waveList; }
sf::Vector2f Level::getHackerStartPosition() const { return _hackerStartPosition; }
const std::list<Tower>& Level::getTowersAvailable() const { return _towersAvailable;}

void Level::setIdLevel(int idLevel) { _idLevel = idLevel; }
void Level::setFinishedLevel(bool finished) { _finishedLevel = finished; }
void Level::setUI(const UI& ui) { _ui = ui; }
void Level::setMap(const Map& map) { *_map = map; }
void Level::setMapArray(const int(&mapArray)[20][30]) {	std::copy(&mapArray[0][0], &mapArray[0][0] + 20 * 30, &_mapArray[0][0]); }
void Level::setGolden(int golden) { _golden = golden; }
void Level::setEnergy(int energy) { _energy = energy; }
void Level::setMusicPlaying(bool playing) { _musicPlaying = playing; }
void Level::setSound(bool play) { play ? _sound.play() : _sound.pause(); }
void Level::setWaveList(const std::list<Wave>& list) { *_waveList = list; }
void Level::setTowersAvailable(const std::list<Tower>& towersAvailable) { _towersAvailable = towersAvailable; }

//void Level::shoot(sf::Vector2f position)
//{
//	//_bullets.push_back(Bullet(position, _hacker.getPosition()));
//}

void Level::handlerEvent(const sf::Event& ev)
{
	if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Right)
	{
		int mousex = ev.mouseButton.x;
		int mousey = ev.mouseButton.y;
		_towerMenu.setPosition(mousex, mousey);
		_towerMenu.show();
		//validateClickRight(mousex, mousey);
	}
	else if (ev.mouseButton.button == sf::Mouse::Left)
	{
		//validateClickLeft(mousex, mousey);
		_towerMenu.hide();
	}
}

void Level::validateClickRight(int mousex, int mousey)
{
	_towerMenu.setPosition(mousex, mousey);
	_towerMenu.show();

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
void Level::update() {
	if (!getFinisheLevel()) {
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
			Manager::getInstance().setLevel(getIdLevel() + 1); //cambia al siguiente nivel
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
	target.draw(_towerMenu, states);
}

//como mostrar el menu, sin tirar todo en main
//como manejar la logica de Wave
//verificar enemigo, ver como se refactoriza
