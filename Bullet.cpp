#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, Direction direction)
{
	_direction = direction;
	setPosition(position);
	_body.setOrigin({ 0,0 }); // setear todo lo que es el body de la bala..
}

void Bullet::update()
{
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_body, states);
}
