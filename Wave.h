#pragma once
#include <list>
#include "Hacker.h"
#include "HackerTrainee.h"
class Wave : public sf::Drawable
{
private:
	std::list<std::list<Hacker>> _wave;
	std::list<Hacker> _wave1 = { HackerTrainee(), HackerTrainee() };
	std::list<Hacker> _wave2 = { HackerTrainee(), HackerTrainee() };//definimos las oleadas...
	std::list<Hacker> _wave3 = { HackerTrainee(), HackerTrainee() };
public:
	std::list<Hacker> getWave1() const;
	std::list<Hacker> getWave2() const;
	std::list<Hacker> getWave3() const;
	void setWave(std::list<Hacker>);

	void draw(sf::RenderTarget&, sf::RenderStates) const;
};

