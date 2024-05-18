#include <SFML/Graphics.hpp>

#include "Collisionable.h"

bool Collisionable::collided(Collisionable& target) const
{
    return getBounds().intersects(target.getBounds());
}