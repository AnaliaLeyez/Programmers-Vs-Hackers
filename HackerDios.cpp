#include "HackerDios.h"

HackerDios::HackerDios()
{
	if (!_texture.loadFromFile("img/hackers/god_sprite.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,64,64 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);


	_name = "BOSS";
	_currentPosition = getPosition();
	_previousPosition = _currentPosition;

	_frame = 0;
	_life = 100;
	_damage = 50;
	_velocity = { 1,1 };
	_goldenDrop = 20;
}

int HackerDios::attackUtn() {

	return 200;
}

void HackerDios::saySth()
{
	if (!_bufferHacker.loadFromFile("music/TraineeSaySth.wav")) {
		throw std::runtime_error("Error al cargar Frase Hacker Dios");
	};
	_soundHacker.setBuffer(_bufferHacker);
	_soundHacker.setVolume(25);
	_soundHacker.play();
}
