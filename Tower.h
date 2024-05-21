#pragma once
#include "HackerTrainee.h"

class Tower : public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:
	//Propiedades estéticas
	//static sf::Texture _texture;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::CircleShape _visualRange;
	std::string _name;

	//Propiedades oro
	float _cost;
	float _costUpgrade;
	float _salesValue;

	//Propiedades bélicas:
	int _damage;
	int _range;
	int _speedAttack;
	int _tipoAtaque;  //esto no se si finalmente vale la pena tenerlo
	unsigned int _cooldown;

	//Upgrades
	int _upgradesAmount;
public:
	//Getters
	std::string getName()const;
	sf::Sprite getSprite()const;
	sf::CircleShape getVisualRange()const;
	float getCost()const;
	float getCostUpgrade()const;
	float getSalesValue()const;
	int getDamage()const;
	int getRange()const;
	int getSpeedAtack()const;
	int getUpgradesAmount()const;

	// Para desarrollo:

	//Setters
	void setRange(int);
	void setName(std::string);
	void setCost(float);
	void setCostUpgrade(float);
	void setSalesValue(float);
	void setDamage(int);
	void setCooldown(int);
	
	//Comportamiento
	void verificarEnemigo(HackerTrainee&);
	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

