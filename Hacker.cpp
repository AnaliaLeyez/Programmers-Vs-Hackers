#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Collisionable.h"
#include "Hacker.h"


//sf::Sprite& Hacker::getSprite() { return _sprite; }
int Hacker::getLife() const { return _life; }
int Hacker::getDamage() const { return _damage; }
sf::Vector2f Hacker::getVelocity() const { return _velocity; }
sf::Vector2f Hacker::getDirection() const { return _direction; }
bool Hacker::getBoss() const { return _isABoss; }
int Hacker::getGoldenDrop() const { return _goldenDrop; }
bool Hacker::getEnd() const { return _reachedEnd; }

void Hacker::setEnd(bool end) { _reachedEnd = end; }
void Hacker::setLife(int life) { _life = life; }
void Hacker::setDamage(int damage) { _damage = damage; }
void Hacker::setVelocity(sf::Vector2f velocity) { _velocity = velocity; }
void Hacker::setDirection(sf::Vector2f direction) { _direction = direction; }
void Hacker::setBoos(bool boss) { _isABoss = boss; }
void Hacker::setGoldenDrop(int drop) { _goldenDrop = drop; }

//void Hacker::attack(float* hackerLife)
//{
//	*hackerLife -= getDamage();
//}
void Hacker::takeDamage(int damageBullet)
{
	std::cout << "Recibio danio tipo " << type << std::endl;
	if (type == 4)
	{
		getFreezed();
	}
	_life -= damageBullet;



}

void Hacker::animation(float _frame)
{
	//Vertical:
	if (_currentPosition.y > _previousPosition.y)
		_sprite.setTextureRect({ 0 + (int)_frame * 64, 0, 64, 64 });
	if (_currentPosition.y < _previousPosition.y)
		_sprite.setTextureRect({ 0 + (int)_frame * 64, 192, 64, 64 });

	if (_currentPosition.x > _previousPosition.x)
		_sprite.setTextureRect({ 0 + (int)_frame * 64, 128, 64, 64 });
	//if (_currentPosition.x < _previousPosition.x)
		//_sprite.setTextureRect({ 0 + (int)_frame * 64, 64, 64, 64 });

}

void Hacker::moveHacker(int arr[][30])
{
	_frame += 0.2f;

	if (_frame > 4)
	{
		_frame = 0;
	}
	_previousPosition = _currentPosition;
	_currentPosition = getPosition();
	animation(_frame);



	switch (arr[(int)getPosition().y / 32][(int)getPosition().x / 32])
	{
	case 2:
		_direction = { 1.0,0.0 };
		break;
	case 3:
		_direction = { 0.0f,-1.0f };
		break;
	case 4:
		_direction = { 0.0f,1.0f };
		break;
	case 5:
		_direction = { 0.0f,-1.0f };
		break;
	case 8:
		_direction = { 0.0f,1.0f };
		_reachedEnd = true;
		break;
	case 9:
		_direction = { -1.0f,0.0f };
		_reachedEnd = true;
		break;
	default:
		_reachedEnd = false;
		break;
	}

	move(_direction);
}

sf::FloatRect Hacker::getBounds() const { return getTransform().transformRect(_sprite.getGlobalBounds()); }

void Hacker::update(int arr[][30])
{
	moveHacker(arr);
}

void Hacker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_sprite, states);
}

void Hacker::getFreezed()
{
	_isFreezed = true;
}
