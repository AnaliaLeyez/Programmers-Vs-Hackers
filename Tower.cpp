#include <string>
#include <list>
#include <SFML/Graphics.hpp>

#include "Collisionable.h"
#include "HackerTrainee.h"
#include "Tower.h"

std::string Tower::getName() const { return _name;}
int Tower::getPrice() const { return _price; }
int Tower::getPriceUpgrade() const { return _priceUpgrade; }
int Tower::getSalesValue() const { return _salesValue; }
sf::CircleShape Tower::getVisualRange() const { return _visualRange; }
sf::Sprite Tower::getSprite() const { return _sprite; }
int Tower::getDamage() const { return _damage; }
int Tower::getRange() const { return _range; }
int Tower::getSpeedAtack() const { return _speedAttack; }
int Tower::getUpgradesAmount() const { return _upgradesAmount; }
int Tower::getSpotNumber() const { return _spotNumber; }

void Tower::setSprite(sf::Sprite sp) { _sprite = sp; }
void Tower::setVisualRange(sf::CircleShape vsRange) { _visualRange = vsRange; }
void Tower::setRange(int range) { _range = range; }
void Tower::setName(std::string name) { _name = name; }
void Tower::setPrice(int price) { _price = price; }
void Tower::setSalesValue(int value) { _salesValue = value; }
void Tower::setDamage(int damage) { _damage = damage; }
void Tower::setPriceUpgrade(int price) { _priceUpgrade = price; }
void Tower::setCooldown(int value) { (value == 0) ? _cooldown = 0 : _cooldown++; }
void Tower::setSpotNumber(int n) { _spotNumber = n; }

void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_visualRange, states);
    target.draw(_sprite, states);
}

bool Tower::canShoot()
{
    if (_clock.getElapsedTime().asSeconds() >= _fireRate)
    {
        _clock.restart();

        return true;
    }
    return false;
}

void Tower::verificarEnemigo(HackerTrainee& enemy)
{
    // Calcula la distancia entre los centros de la torre y el objetivo
    double distancia = std::sqrt(std::pow(enemy.getPosition().x - getPosition().x, 2) + std::pow(enemy.getPosition().y - getPosition().y, 2));

    if (distancia <= _visualRange.getRadius())
    {
        //shoot(enemy);
    }    
}

sf::FloatRect Tower::getBounds() const { return _sprite.getLocalBounds(); }

void Tower::update()
{
   //actualizar hacker en rango:
   // _hackersOnRange.push_back();  
   HackerTrainee enemy;
   verificarEnemigo(enemy);
}
