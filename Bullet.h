#pragma once
#include "Collisionable.h"
#include <SFML/Graphics.hpp>
class Bullet: public Collisionable, public sf::Drawable, public sf::Transformable
{
protected:
	sf::Sprite _sprite;
	//static sf::Texture _texture;
	sf::Texture _texture;
	sf::Vector2f _direction;
	int _damage;
	sf::Vector2f _velocity;
	sf::Vector2f _enemyPosition;  //dudo mucho que esto esté correcto tenerlo acá
public:
	sf::Vector2f getDirection();
	sf::Vector2f getVelocity();
	int getDamage();
	void setDirection(sf::Vector2f);
	void setVelocity(sf::Vector2f);
	void setDamage(int);

	void moveBullet(sf::Vector2f, sf::Vector2f);

	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

