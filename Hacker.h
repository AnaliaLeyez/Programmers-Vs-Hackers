#pragma once
#include "Collisionable.h"
#include <SFML/Graphics.hpp>
class Hacker :public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:

	static sf::Texture _texture;

	std::string _name;
	sf::Vector2f _velocity;
	sf::Vector2f _direction;
	int _seniority;
	int _life;
	int _damage;
	bool _isABoss;
	int _goldenDrop;
	sf::Vector2f _position;
public:
	//sf::Sprite getSprite() const;
	sf::Sprite _sprite;
	sf::Sprite& getSprite();

	sf::RectangleShape _collisionRect;

	int getLife() const;
	int getDamage() const;
	sf::Vector2f getVelocity() const;
	sf::Vector2f getDirection() const;
	bool getBoss() const;
	int getGoldenDrop() const;

	void setLife(int);
	void setDamage(float);
	void setVelocity(sf::Vector2f);
	void setDirection(sf::Vector2f);
	void setBoos(bool);
	void setGoldenDrop(float);

	//Comportamiento
	void moveHacker(int arr[][30]);
	void attack(float*);
	sf::FloatRect getBounds() const;
	void update(int arr[][30]);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	void takeDamageFromTheBulletSentFromHeavenMadeInHeavenBabyOhNyes(int);
};
