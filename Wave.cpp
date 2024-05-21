#include <iostream>
#include <list>

#include "SFML/Graphics.hpp"

#include "Hacker.h"
#include "HackerTrainee.h"
#include "Wave.h"

std::list<Hacker> Wave::getWave1() const {	return _wave1; }
std::list<Hacker> Wave::getWave2() const { return _wave2; }
std::list<Hacker> Wave::getWave3() const { return _wave3; }

void Wave::setWave(std::list<Hacker> wave) { _wave.push_back(wave); }

void Wave::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	//ver QUE va aca
}