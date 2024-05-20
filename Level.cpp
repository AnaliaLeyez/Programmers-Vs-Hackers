#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "UI.h"
#include "Map.h"
#include "Tower.h"
#include "Wave.h"

#include "Level.h"

int Level::getIdLevel() const { return _idLevel; }
bool Level::getFinisheLevel() const{ return _finishedLevel; }
UI Level::getUI() const { return _ui; }
Map Level::getMap() { return _map; }
int(*Level::getMapArray())[30]{ return _mapArray; }
int Level::getGolden() { return _golden; }
int Level::getEnergy() { return _energy; }
sf::SoundBuffer Level::getBuffer() const { return _buffer; }
sf::Sound Level::getSound() const { return _sound; }
bool Level::getMusicPlaying() const { return _musicPlaying; }
std::list<Wave> Level::getWaveList() const { return _waveList; }
sf::Vector2f Level::getHackerStartPosition() const { return _hackerStartPosition; }
const std::list<Tower>& Level::getTowersAvailable() const { return _towersAvailable;}

void Level::setIdLevel(int idLevel) { _idLevel = idLevel; }
void Level::setFinishedLevel(bool finished) { _finishedLevel = finished; }
void Level::setUI(const UI& ui) { _ui = ui; }
void Level::setMap(const Map& map) { _map = map; }
void Level::setMapArray(const int(&mapArray)[20][30]) {	std::copy(&mapArray[0][0], &mapArray[0][0] + 20 * 30, &_mapArray[0][0]); }
void Level::setGolden(int golden) { _golden = golden; }
void Level::setEnergy(int energy) { _energy = energy; }
void Level::setMusicPlaying(bool playing) { _musicPlaying = playing; }
void Level::setSound(bool play) { play ? _sound.play() : _sound.pause(); }
void Level::setWaveList(const std::list<Wave>& list) { _waveList = list; }
void Level::setTowersAvailable(const std::list<Tower>& towersAvailable) {
	_towersAvailable = towersAvailable;
}
void Level::update() {
	if (!getFinisheLevel()) {
		//IMPORTANTEEEEE VER EL TEMA OLEADAS!! ESTO DE ABAJO SE ROMPE
		/*for (std::list<Wave> wave : _waveList) {
			for (Hacker& hacker : wave)
			hacker.update(getMapArray());
		}*/
	}
	else {
		//ver que sucede si se completa el nivel
	}
}
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_map, states);
	target.draw(_ui, states);
}
