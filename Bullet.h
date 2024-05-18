#pragma once

class Bullet: public sf::Drawable, public sf::Transformable, public Collisionable
{
private:
	sf::Sprite _sprite;
	static sf::Texture _texture;
	sf::Vector2f _direction;
	int _damage;
	sf::Vector2f _velocity;
	sf::Vector2f _enemyPosition;
public:
	Bullet(sf::Vector2f position, sf::Vector2f direction,int damage, sf::Vector2f velocity, std::string FileName);
	sf::FloatRect getBounds() const;
	void setDirection(sf::Vector2f);
	void moveBullet(sf::Vector2f, sf::Vector2f);
	void update();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

