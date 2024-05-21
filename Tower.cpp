#include <iostream>
#include <string>
#include <list>
#include <SFML/Graphics.hpp>

#include "Collisionable.h"
#include "Manager.h" //ver si esto es necesario aca
#include "HackerTrainee.h"

#include "Tower.h"
//Getters

std::string Tower::getName() const { return _name;}
float Tower::getCost() const { return _cost; }
float Tower::getCostUpgrade() const { return _costUpgrade; }
float Tower::getSalesValue() const { return _salesValue; }
sf::CircleShape Tower::getVisualRange() const { return _visualRange; }
sf::Sprite Tower::getSprite() const { return _sprite; }
int Tower::getDamage() const { return _damage; }
int Tower::getRange() const { return _range; }
int Tower::getSpeedAtack() const { return _speedAttack; }
int Tower::getUpgradesAmount() const { return _upgradesAmount; }

void Tower::setRange(int range) { _range = range; }
void Tower::setName(std::string name) { _name = name; }
void Tower::setCost(float cost) { _cost = cost; }
void Tower::setSalesValue(float value) { _salesValue = value; }
void Tower::setDamage(int damage) { _damage = damage; }
void Tower::setCostUpgrade(float cost) { _costUpgrade = cost; }
void Tower::setCooldown(int value)
{
    if (value == 0)
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

void Tower::verificarEnemigo(HackerTrainee& enemy)
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
   
   HackerTrainee enemy;
   verificarEnemigo(enemy);
}
