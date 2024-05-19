#include <SFML/Graphics.hpp>

#include "Collisionable.h"

bool Collisionable::isCollision(Collisionable& target) const
{
    return getBounds().intersects(target.getBounds());
}