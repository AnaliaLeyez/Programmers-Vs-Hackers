#pragma once
#include "Bullet.h"
#include "HackerTrainee.h"

class Tower : public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:
	sf::CircleShape _visualRange;
	sf::Sprite _sprite;
	//Propiedades esteticas
	sf::Texture _texture;
	std::string _name;
	//Propiedades oro
	int _price;
	int _priceUpgrade;
	int _salesValue;
	//Propiedades belicas:
	int _damage;
	int _damageUpgrade;
	int _range;
	int _upgradesAmount;

	int _spotNumber;
	int _type; //new

	sf::Clock _clock;
	//int _cooldown;
	float _fireRate;
	Bullet* _bullet;

public:
	virtual Tower* clone() const = 0; // Método clone para crear nuevas instancias
	virtual void upgrade()=0;

	//Getters
	sf::Sprite getSprite() const;
	int getPrice() const;
	int getPriceUpgrade() const;
	int getSalesValue() const;
	int getDamage() const;
	int getDamageUpgrade() const;
	int getRange() const;
	int getUpgradesAmount() const;
	int getSpotNumber() const;
	Bullet* getBullet() const;
	int getType() const;

	void setRangeColor(sf::Color);
	void setSpotNumber(int);

	//Comportamiento
	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	bool canShoot();
};
