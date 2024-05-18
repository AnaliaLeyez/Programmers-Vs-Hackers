#include <SFML/Graphics.hpp>
#include <list>

#include "Collisionable.h"
#include "Player.h"
#include "Tower.h"
#include "Hacker.h"
#include "Bullet.h"


#include "GamePlay.h"

GamePlay* GamePlay::_currentInstance = nullptr;

GamePlay::GamePlay() {

}
GamePlay& GamePlay::getInstance() {
	if (GamePlay::_currentInstance == nullptr) {
		GamePlay::_currentInstance = new GamePlay();
	}
	return *GamePlay::_currentInstance;
}

void GamePlay::update()
{
	
	_tower.update();
	_hackers.update();

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
	target.draw(_player, states);
	for (const Bullet& bullet : _bullets) {
		target.draw(bullet, states);
	}
}

void GamePlay::shoot(sf::Vector2f position)
{
	_bullets.push_back(Bullet(position, _hacker.getPosition()));
}
