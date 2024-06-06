#pragma once
#include "HackerTrainee.h"

class Tower : public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:
	//Propiedades est�ticas
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::CircleShape _visualRange;
	std::string _name;
	//Propiedades oro
	int _price;
	int _priceUpgrade;
	int _salesValue;
	//Propiedades b�licas:
	int _damage;
	int _range;
	int _speedAttack;
	unsigned int _cooldown;
	int _upgradesAmount;

	int _spotNumber;

	sf::Clock _clock;
	float _fireRate;

public:
	virtual void upgrade() {}
	//virtual void upgrade()=0;
	
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

	void setSprite(sf::Sprite);
	void setVisualRange(sf::CircleShape);
	void setRange(int);
	void setName(std::string);
	void setPrice(int);
	void setPriceUpgrade(int);
	void setSalesValue(int);
	void setDamage(int);
	void setCooldown(int);
	void setSpotNumber(int);

	//Comportamiento
	void verificarEnemigo(HackerTrainee&);
	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;

	bool canShoot();
};
