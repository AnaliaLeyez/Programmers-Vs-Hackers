#pragma once
#include "Bullet.h"
#include "HackerTrainee.h"

class Tower : public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:
	//Propiedades esteticas
	sf::Texture _texture;
	
	
	std::string _name;
	//Propiedades oro
	int _price;
	int _priceUpgrade;
	int _salesValue;
	//Propiedades belicas:
	int _damage;
	int _range;
	int _speedAttack;
	int _upgradesAmount;

	int _spotNumber;
	int _type; //new

	//sf::Clock _clock;
	int _cooldown;
	float _fireRate;
	Bullet* _bullet; //NUEVO, ANA
	//std::list<Bullet*> _bullets; //NUEVO, ANA

public:
	sf::CircleShape _visualRange;
	sf::Sprite _sprite;
	virtual Tower* clone() const = 0; // Método clone para crear nuevas instancias
	virtual void upgrade()=0;

	virtual void setBullet(sf::Vector2f, sf::Vector2f) = 0;
	//Getters
	std::string getName() const;
	sf::Sprite getSprite() const;
	sf::CircleShape getVisualRange() const;
	int getPrice() const;
	int getPriceUpgrade() const;
	int getSalesValue() const;
	int getDamage() const;
	int getRange() const;
	int getSpeedAtack() const;
	int getUpgradesAmount() const;
	int getSpotNumber() const;
	Bullet* getBullet() const;
	int getType() const;

	void setSprite(sf::Sprite);
	void setVisualRange(sf::CircleShape);
	void setRangeColor(sf::Color);
	void setRange(int);
	void setName(std::string);
	void setPrice(int);
	void setPriceUpgrade(int);
	void setSalesValue(int);
	void setDamage(int);
	void setSpotNumber(int);

	//Comportamiento
	void verificarEnemigo(HackerTrainee&);
	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	bool canShoot();
};
