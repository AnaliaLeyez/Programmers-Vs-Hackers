#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"

#include "Hacker.h"
#include "HackerTrainee.h"
#include "Wave.h"

std::list<Hacker> Wave::getWave1()
{
	return _wave1;
}
std::list<Hacker> Wave::getWave2()
{
	return _wave2;
}
std::list<Hacker> Wave::getWave3()
{
	return _wave3;
}

void Wave::setWave(std::list<Hacker> wave)
{
	_wave.push_back(wave);
}
