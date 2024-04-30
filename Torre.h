#pragma once
#include <SFML/Graphics.hpp>
#include "Hacker.h"
#include <string>

class Torre : public sf::Drawable
{
protected:
	//Propiedades estéticas
	sf::Sprite _sprite;
	sf::Texture _texture;
	sf::CircleShape _rango;
	std::string _nombre;


	//Propiedades oro
	float _costo;
	float _costoUpgrade;
	float _valorVenta;

	//Propiedades bélicas:
	float _danioCausante;
	int _alcance;
	int _velocidadAtaque;
	int _tipoAtaque;

	//Upgrades
	int _cantidadUpgrades;
public:


	//Getters
	std::string getNombre();
	sf::Sprite getSprite();
	sf::CircleShape getRango();

	float getCosto();
	float getCostoUpgrade();
	float getValorVenta();
	float getDanioCausante();

	int getAlcance();
	int getVelocidadAtaque();
	int getTipoAtaque();

	int getCantidadUpgrades();

	// Para desarrollo:

	void setPosition(float, float);

	//Setters
	void setRango();
	void setNombre(std::string);
	void setCosto(float);
	void setCostoUpgrade(float);
	void setValorVenta(float);
	void setDanioCausante(float);
	void setAlcance(int);
	
	//Comportamiento

	void dispararObjetivo(Hacker&);
	void verificarEnemigo(Hacker&);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

