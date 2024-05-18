#pragma once
#include "Player.h"
#include "Bullet.h"
#include <SFML/Graphics.hpp>
#include <list>
class GamePlay : public sf::Drawable
{
private:
	GamePlay();
	static GamePlay* _currentInstance;
	Player _player;
	std::list<Bullet> _bullets;
public:
	static GamePlay& getInstance();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void shoot(sf::Vector2f position, Bullet::Direction direction);
};

