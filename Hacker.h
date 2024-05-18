#pragma once

class Hacker :public sf::Drawable, public sf::Transformable, public Collisionable
{
protected:

	sf::Sprite _sprite;
	static sf::Texture _texture;
	std::string _name;
	sf::Vector2f _velocity;
	sf::Vector2f _direction;
	int _seniority;
	int _life;
	int _tipoAtaque; //podriamos sacarlo
	int _damage;
	bool _isABoss;
	int _goldenDrop;

	//DESARROLLO

	sf::Vector2f _position;

public:
	Hacker(sf::Vector2f position, sf::Vector2f direction,int damage, sf::Vector2f velocity, std::string FileName);
	//DESARROLLO

	void moveHacker();
	sf::Sprite getSprite();

	//Getters
	int& getLife();
	int getTipoAtaque(); //lo podriamos sacar
	float getDamage();
	sf::Vector2f getVelocity();
	sf::Vector2f getDirection();
	sf::Vector2f getPosition();
	bool getBoss();
	float getGoldenDrop();


	//Setters
	void setLife(int);
	void setTipoAtaque(int); //lo podriamos sacar
	void setDamage(float);
	void setVelocity(sf::Vector2f);
	void setDirection(sf::Vector2f);
	void setPosition(sf::Vector2f);
	void setBoos(bool);
	void setGoldenDrop(float);
	
	//Comportamiento
	void attack(float*);
	sf::FloatRect getBounds() const;
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

