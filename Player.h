#pragma once

class Player : public sf::Drawable, sf::Transformable
{
private:
	sf::RectangleShape _body;
	unsigned int _cooldown;
public:
	Player();
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

