#include "HackerJunior.h"


HackerJunior::HackerJunior()
{
	if (!_texture.loadFromFile("img/hackers/junior_sprite.png")) {
		throw std::runtime_error("Error img Hacker Trainee");
	}
	_sprite.setTexture(_texture);
	_sprite.setTextureRect({ 0,0,64,64 });
	_sprite.setOrigin(_sprite.getGlobalBounds().width / 2, _sprite.getGlobalBounds().height / 2);


	_name = "Junior";
	_currentPosition = getPosition();
	_previousPosition = _currentPosition;

	_frame = 0;
	_life = 15;
	_damage = 10;
	_velocity = { 1.2,1.2 };
	_goldenDrop = 9;

}


int HackerJunior::attackUtn() {
	
	return 100;
}

void HackerJunior::saySth()
{
	if (!_bufferHacker.loadFromFile("music/JuniorSaySth.wav")) {
		throw std::runtime_error("Error al cargar Frase Hacker Junior");
	};
	_soundHacker.setBuffer(_bufferHacker);
	_soundHacker.setVolume(25);
	_soundHacker.play();
}
