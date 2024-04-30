#include "Hacker.h"


float& Hacker::getSalud()
{
	return _salud;
}

int Hacker::getTipoAtaque()
{
	return _tipoAtaque;
}

float Hacker::getCantidadDanio()
{
	return _cantidadDanio;
}

float Hacker::getVelocidadMovimiento()
{
	return _velocidadMovimiento;
}

bool Hacker::getBoss()
{
	return _isABoss;
}

float Hacker::getDropOro()
{
	return _dropOro;
}

//SETTERS
void Hacker::setSalud(float salud)
{
	_salud = salud;
}

void Hacker::setTipoAtaque(int tipo)
{
	_tipoAtaque = tipo;
}

void Hacker::setCantidadDanio(float danio)
{
	_cantidadDanio = danio;
}

void Hacker::setVelocidadMovimiento(float velocidad)
{
	_velocidadMovimiento = velocidad;
}

void Hacker::setBoos(bool boss = false)
{
	_isABoss = boss;
}

void Hacker::setDrop(float drop)
{
	_dropOro = drop;
}

void Hacker::atacar(float* objetivo)
{
	*objetivo -= getCantidadDanio();

}

void Hacker::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}


//DESARROLLO
void Hacker::moverse()
{
	_sprite.move(_posicion);


	if (_sprite.getPosition().x < 0)
	{
		//_sprite.setPosition(0, _sprite.getPosition().y);
		_posicion.x = -_posicion.x * 1.1;
	}

	//Limite superior
	if (_sprite.getPosition().y < 0)
	{
		//_sprite.setPosition(_sprite.getPosition().x, 0);
		_posicion.y = -_posicion.y;
	}

	//Limite derecho
	if (_sprite.getPosition().x + _sprite.getGlobalBounds().width > 800)
	{
		//		_sprite.setPosition(800 - _sprite.getGlobalBounds().width, _sprite.getPosition().y);
		_posicion.x = -_posicion.x;
	}

	//Limite inferior
	if (_sprite.getPosition().y + _sprite.getGlobalBounds().width > 600)
	{
		//_sprite.setPosition(_sprite.getPosition().x, 600 - _sprite.getGlobalBounds().height);
		_posicion.y = -_posicion.y;
	}
}

sf::Sprite Hacker::getSprite()
{
	return _sprite;
}
