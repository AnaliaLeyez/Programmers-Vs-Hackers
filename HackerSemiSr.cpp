#include "HackerSemiSr.h"


HackerSemiSr::HackerSemiSr()
{
	if (!_texture.loadFromFile("img/hackers/sr_sprite.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,64,64 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);

	_isFreezed = false;
	_isPoisoned = false;

	_type = 3;

	_name = "SemiSR";
	_currentPosition = getPosition();
	_previousPosition = _currentPosition;

	_frame = 0;
	_life = 50;
	_damage = 20;
	_velocity = { 0.9f,0.9f };
	_goldenDrop = 12;

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
