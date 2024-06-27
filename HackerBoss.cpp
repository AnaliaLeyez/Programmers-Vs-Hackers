#include "HackerBoss.h"

HackerBoss::HackerBoss()
{
	if (!_texture.loadFromFile("img/hackers/Boss_sprite.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,124,125 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height);

	_isFreezed = false;
	_type = 5;

	_currentPosition = getPosition();
	_previousPosition = _currentPosition;

	_frame = 0;
	_life = 100;
	_velocity = { 0.4f,0.4f };
	_goldenDrop = 900;
}

int HackerBoss::attackUtn() {

	return 200;
}

void HackerBoss::saySth()
{
	if (!_bufferHacker.loadFromFile("music/TraineeSaySth.wav")) {
		throw std::runtime_error("Error al cargar Frase Hacker Dios");
	};
	_soundHacker.setBuffer(_bufferHacker);
	_soundHacker.setVolume(25);
	_soundHacker.play();
}