#include <string>
#include <list>
#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Tower.h"

int Tower::getPrice() const { return _price; }
int Tower::getPriceUpgrade() const { return _priceUpgrade; }
int Tower::getSalesValue() const { return _salesValue; }
int Tower::getDamage() const { return _damage; }
int Tower::getDamageUpgrade() const { return _damageUpgrade; }
float Tower::getFireRate() const { return _fireRate; }
float Tower::getFireRateUpgrade() const { return _fireRateUpgrade; }
int Tower::getUpgradesAmount() const { return _upgradesAmount;}
int Tower::getSpotNumber() const { return _spotNumber; }
Bullet* Tower::getBullet() const { return _bullet; }
int Tower::getType() const { return _type; }

void Tower::setSpotNumber(int n) { _spotNumber = n; }

bool Tower::canShoot()
{
    if (_clock.getElapsedTime().asSeconds() >= _fireRate)
    {
        _clock.restart();
        return true;
    }
    return false;
}

sf::FloatRect Tower::getBounds() const {
        
    return getTransform().transformRect(_visualRange.getGlobalBounds());
}
void Tower::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(_visualRange, states);
    target.draw(_sprite, states);
}

