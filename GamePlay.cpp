#include <SFML/Graphics.hpp>
#include <list>

#include "Menu.h"
#include "Level.h"
#include "Map.h"
#include "Collisionable.h"
#include "Player.h"
#include "Tower.h"
#include "Hacker.h"
#include "Bullet.h"


#include "GamePlay.h"

GamePlay* GamePlay::_currentInstance = nullptr;

GamePlay::GamePlay(int level) {
	setLevel(level);  //en cuanto hago esto, es decir, en cuanto especifico que sea nivel1, se rompe
}
GamePlay& GamePlay::getInstance() {
	if (GamePlay::_currentInstance == nullptr) {
		GamePlay::_currentInstance = new GamePlay();
	}
	return *GamePlay::_currentInstance;
}
Level GamePlay::getLevel() {
	return *_level;
}
//void GamePlay::setLevel(Level level) {
//	_level = level;
//}

void GamePlay::setLevel(int IdLevel) {
	switch (IdLevel)
	{
	case 1:
		_level = new Level1();
	default:
		break;
	}
}

void GamePlay::update()
{
	_level->update();
	_tower.update();
	for (Hacker& hacker : _hackers) {
		hacker.update(_level->getMapArray());
	}

	for (Bullet& bullet : _bullets) {
		bullet.update();
	}

	auto it = _bullets.begin();

	while (it != _bullets.end()) {
		Bullet& bullet = *it;
		bullet.update();
	/*	if (bullet.getPosition().x > torrecitaPrueba.getRango().getLocalBounds().getSize().x) {
			it = _bullets.erase(it);
		}
		else {
			++it;
		}*/

	}
}

void GamePlay::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_level, states);
	for (const Bullet& bullet : _bullets) {
		target.draw(bullet, states);
	}
}

void GamePlay::shoot(sf::Vector2f position)
{
	//_bullets.push_back(Bullet(position, _hacker.getPosition()));
}

void GamePlay::validateClick(int mousex, int mousey)
{

}

//void GamePlay::validateClickOnMap(int mousex, int mousey, Map &mapa) {
//
//	if (mapa.getSpeaker().getGlobalBounds().contains(mousex, mousey)) {
//		if (mapa.getMusicPlaying()) {
//			mapa.setSound(false);
//			mapa.setMusicPlaying(false);
//			mapa.setTextureSpeaker("img/complementarias/mute.png");
//		}
//		else {
//			mapa.setSound(true);
//			mapa.setMusicPlaying(true);
//			mapa.setTextureSpeaker("img/complementarias/musicOn.png");
//		}
//	}
// 
//}
