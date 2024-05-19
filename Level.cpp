#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "UI.h"
#include "Map.h"
#include "Tower.h"

#include "Level.h"

int Level::getIdLevel() const { return _idLevel; }
bool Level::getFinisheLevel() const{ return _finisheLevel; }
UI Level::getUI() const { return _ui; }
Map Level::getMap() { return _map; }
int(*Level::getMapArray())[30]{ return _mapArray; }
sf::SoundBuffer Level::getBuffer() const { return _buffer; }
sf::Sound Level::getSound() const { return _sound; }
bool Level::getMusicPlaying() const { return _musicPlaying; }
//const std::list<Wave>& Level::getWaveList() const { return _waveList; }
const std::list<Tower>& Level::getTowersAvailable() const {
	return _towersAvailable;
}

void Level::setIdLevel(int idLevel) { _idLevel = idLevel; }
void Level::setUI(const UI& ui) { _ui = ui; }
void Level::setMap(const Map& map) { _map = map; }
void Level::setMapArray(const int(&mapArray)[20][30]) {
	std::copy(&mapArray[0][0], &mapArray[0][0] + 20 * 30, &_mapArray[0][0]);
}
void Level::setMusicPlaying(bool playing) { _musicPlaying = playing; }
void Level::setSound(bool reproducir) {
	if (reproducir)
		_sound.play();
	else
		_sound.pause();
}
//void Level::setWaveList(const std::list<Wave>& list) { _waveList = list; }
void Level::setTowersAvailable(const std::list<Tower>& towersAvailable) {
	_towersAvailable = towersAvailable;
}
void Level::update() {
	if (!getFinisheLevel()) {
		//manejar las oleadas?
	}
	else {
		//ver que sucede si se completa el nivel
	}
}
void Level::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(_map, states);
	target.draw(_ui, states);
}