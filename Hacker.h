#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Hacker :public sf::Drawable
{
protected:

	sf::Sprite _sprite;
	sf::Texture _texture;
	std::string _nombre;

	int _seniority;
	float _salud;
	int _tipoAtaque;
	float _cantidadDanio;
	float _velocidadMovimiento;
	bool _isABoss;
	float _dropOro;

	//DESARROOLLO

	sf::Vector2f _posicion;

public:

	//DESARROLLO

	void moverse();
	sf::Sprite getSprite();

	//Getters
	float& getSalud();
	int getTipoAtaque();
	float getCantidadDanio();
	float getVelocidadMovimiento();
	bool getBoss();
	float getDropOro();


	//Setters
	void setSalud(float);
	void setTipoAtaque(int);
	void setCantidadDanio(float);
	void setVelocidadMovimiento(float);
	void setBoos(bool);
	void setDrop(float);
	
	//Comportamiento
	void atacar(float*);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;



};

