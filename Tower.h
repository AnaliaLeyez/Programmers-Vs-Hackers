#pragma once
#include "HackerTrainee.h"

class Tower : public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:
	//Propiedades estéticas
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::CircleShape _visualRange;
	std::string _name;
	//Propiedades oro
	int _price;
	int _priceUpgrade;
	int _salesValue;
	//Propiedades bélicas:
	int _damage;
	int _range;
	int _speedAttack;
	unsigned int _cooldown;
	int _upgradesAmount;
public:
	//Getters
	std::string getName() const;
	//sf::Sprite getSprite() const;
	sf::CircleShape getVisualRange() const;
	int getPrice() const;
	int getPriceUpgrade() const;
	int getSalesValue() const;
	int getDamage() const;
	int getRange() const;
	int getSpeedAtack() const;
	int getUpgradesAmount() const;

	void setRange(int);
	void setName(std::string);
	void setPrice(int);
	void setPriceUpgrade(int);
	void setSalesValue(int);
	void setDamage(int);
	void setCooldown(int);
	
	//Comportamiento
	void verificarEnemigo(HackerTrainee&);
	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

