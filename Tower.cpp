#include <string>
#include <list>
#include <SFML/Graphics.hpp>

#include "Collisionable.h"
#include "HackerTrainee.h"
#include "Bullet.h"
#include "Tower.h"

//std::string Tower::getName() const { return _name;}
int Tower::getPrice() const { return _price; }
int Tower::getPriceUpgrade() const { return _priceUpgrade; }
int Tower::getSalesValue() const { return _salesValue; }
sf::Sprite Tower::getSprite() const { return _sprite; }
int Tower::getDamage() const { return _damage; }
int Tower::getRange() const { return _range; }
int Tower::getSpotNumber() const { return _spotNumber; }
Bullet* Tower::getBullet() const { return _bullet; }

void Tower::setRangeColor(sf::Color color) { _visualRange.setFillColor(color); }
void Tower::setSpotNumber(int n) { _spotNumber = n; }

int Tower::getType() const { return _type; }

void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_visualRange, states);
    target.draw(_sprite, states);
}

bool Tower::canShoot()
{
    //if (_clock.getElapsedTime().asSeconds() >= _fireRate)
    if (_cooldown >= 20)
    {
        setRangeColor(sf::Color(255, 0, 0, 120));
        //_clock.restart();
        _cooldown = 0;
        return true;
    }
    setRangeColor(sf::Color(0, 255, 0, 120));
    _cooldown++;
    return false;
}

sf::FloatRect Tower::getBounds() const {
        
    return getTransform().transformRect(_visualRange.getGlobalBounds());
}

void Tower::update()
{
}
