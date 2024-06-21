#include "HackerSemiSr.h"


HackerSemiSr::HackerSemiSr()
{
	if (!_texture.loadFromFile("img/hackers/sr_sprite.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,64,64 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);


	_name = "SemiSR";
	_currentPosition = getPosition();
	_previousPosition = _currentPosition;

	_frame = 0;
	_life = 20;
	_damage = 1;
	_velocity = { 2,2 };
	_goldenDrop = 10;

}

int HackerSemiSr::attackUtn() {

	return 60;
}

void HackerSemiSr::saySth()
{
	if (!_bufferHacker.loadFromFile("music/SemiSrSaySth.wav")) {
		throw std::runtime_error("Error al cargar Frase Hacker SemiSr");
	};
	_soundHacker.setBuffer(_bufferHacker);
	_soundHacker.setVolume(25);
	_soundHacker.play();
}
