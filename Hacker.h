#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "Collisionable.h"

class Hacker :public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:
	sf::Texture _texture;
	sf::Sprite _sprite;
	std::string _name;
	sf::Vector2f _velocity;
	sf::Vector2f _direction;
	//audios
	sf::SoundBuffer _bufferHacker;
	sf::Sound _soundHacker;

	int _life;
	int _damage;
	bool _isABoss;
	int _goldenDrop;
	sf::Vector2f _position;
	bool _reachedEnd; // llego al final del camino ?

	bool _isFreezed;
	bool _isPoisoned;

	//Animation
	float _frame;
	sf::Vector2f _currentPosition;
	sf::Vector2f _previousPosition;

public:
	virtual int attackUtn() = 0;
	virtual void saySth() = 0;
	int getLife() const;
	int getDamage() const;
	sf::Vector2f getVelocity() const;
	sf::Vector2f getDirection() const;
	bool getBoss() const;
	int getGoldenDrop() const;
	bool getEnd() const;

	void setEnd(bool);
	void setLife(int);
	void setDamage(int);
	void setVelocity(sf::Vector2f);
	void setDirection(sf::Vector2f);
	void setBoos(bool);
	void setGoldenDrop(int);

	//Comportamiento
	void moveHacker(int arr[][30]);
	sf::FloatRect getBounds() const;
	void update(int arr[][30]);
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	void getFreezed();

	virtual void takeDamage(int,int);

	void animation(float);
};
