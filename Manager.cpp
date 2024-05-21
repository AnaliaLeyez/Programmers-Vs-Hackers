#include <SFML/Graphics.hpp>
#include <list>

#include "Menu.h"
#include "Level.h"
#include "Map.h"
#include "Collisionable.h"
#include "Tower.h"
#include "Hacker.h"
#include "Bullet.h"


#include "Manager.h"

Manager* Manager::_currentInstance = nullptr;

Manager::Manager(int level) {
	setLevel(level);  //en cuanto hago esto, es decir, en cuanto especifico que sea nivel1, se rompe
}
Manager& Manager::getInstance() {
	if (Manager::_currentInstance == nullptr) {
		Manager::_currentInstance = new Manager();
	}
	return *Manager::_currentInstance;
}
Level Manager::getLevel() {
	return *_level;
}
//void GamePlay::setLevel(Level level) {
//	_level = level;
//}

void Manager::setLevel(int IdLevel) {
	switch (IdLevel)
	{
	case 1:
		_level = new Level1();
	default:
		break;
	}
}

void Manager::update()
{
	_level->update();
	//TODO ESTO ES DEL NIVEL:
	//_tower.update();
	//for (Hacker& hacker : _hackers) {
	//	hacker.update(_level->getMapArray());
	//}

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
	
}

void Manager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*_level, states);

	//for (const Bullet& bullet : _bullets) {
	//	target.draw(bullet, states);
	//}
}

void Manager::shoot(sf::Vector2f position)
{
	//_bullets.push_back(Bullet(position, _hacker.getPosition()));
}

void Manager::validateClick(int mousex, int mousey)
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
