#include <iostream>
#include <string>
#include <list>
#include <SFML/Graphics.hpp>

#include "Collisionable.h"
#include "GamePlay.h"
#include "Hacker.h"

#include "Tower.h"
//Getters

std::string Tower::getName()
{
    return _name;
}

float Tower::getCost()
{
    return _cost;
}

float Tower::getCostUpgrade()
{
    return _costUpgrade;
}

float Tower::getSalesValue()
{
    return _salesValue;
}

sf::CircleShape Tower::getVisualRange()
{
    return _visualRange;
}

sf::Sprite Tower::getSprite()
{
    return _sprite;
}

int Tower::getDamage()
{
    return _damage;
}

int Tower::getRange()
{
    return _range;
}

int Tower::getSpeedAtack()
{
    return _speedAttack;
}


int Tower::getUpgradesAmount()
{
    return _upgradesAmount;
}

//Setters
void Tower::setRange(int rango)
{
    _range = rango;
}

void Tower::setName(std::string nombre)
{
    _name = nombre;
}

void Tower::setCost(float costo)
{
    _cost = costo;
}

void Tower::setSalesValue(float valor)
{
    _salesValue = valor;
}

void Tower::setDamage(int danio)
{
    _damage = danio;
}

void Tower::setRange(int alcance)
{
    _range = alcance;
}

void Tower::setCostUpgrade(float costo)
{
    _costUpgrade = costo;
}
void Tower::setCooldown(int valor)
{
    if (valor == 0)
        _cooldown = 0;
    else
        _cooldown++;
}
//Comportamiento
/*
void Tower::shoot(Hacker& objetivo)
{
    if (_cooldown > 10)
    {
        GamePlay& gp = GamePlay::getInstance();
        gp.shoot(getPosition());
        _cooldown = 0;
    }
    objetivo.getLife() -= getDamage();
}
*/

void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_visualRange, states);
    target.draw(_sprite, states);
}

void Tower::verificarEnemigo(Hacker& enemy)
{
    // Calcula la distancia entre los centros de la torre y el objetivo
    float distancia = std::sqrt(std::pow(enemy.getPosition().x - getPosition().x, 2) + std::pow(enemy.getPosition().y - getPosition().y, 2));

    if (distancia <= _visualRange.getRadius())
    {
        //shoot(enemy);
    }    
}

sf::FloatRect Tower::getBounds() const
{
    return _sprite.getLocalBounds();
}

void Tower::update()
{
   //actualizar hacker en rango:
   // _hackersOnRange.push_back();
   
   Hacker enemy(sf::Vector2f{0,0}, sf::Vector2f{ 0,0 }, 0, sf::Vector2f{ 0,0 }, "");
   verificarEnemigo(enemy);
}