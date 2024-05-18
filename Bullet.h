#pragma once
#include "SFML/Graphics.hpp"
class Bullet: public sf::Drawable, public sf::Transformable
{
public:
	enum class Direction {
		Left = 0,
		Right = 1,
		Up = 2,
		Down = 3
	};
private:
	sf::RectangleShape _body;
	Direction _direction;
public:
	Bullet(sf::Vector2f position, Direction direction);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

