#include "Player.h"
#include "GamePlay.h"

Player::Player()
{
	//setear el _body
	_cooldown = 0;
}

void Player::update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && _cooldown>60) {
		GamePlay& gm = GamePlay::getInstance();
		gm.shoot(getPosition(), Bullet::Direction::Right);
		_cooldown = 0;
	}

	_cooldown++;
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(_body, states);
}
