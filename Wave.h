#pragma once
#include <list>
#include "Hacker.h"
#include "HackerTrainee.h"
class Wave
{
private:
	//REVISAR ESTO!
	std::list<std::list<Hacker>> _wave;
	std::list<Hacker> _wave1 = { HackerTrainee(), HackerTrainee() };
	std::list<Hacker> _wave2; //definimos las oleadas...
	std::list<Hacker> _wave3;
public:
	std::list<Hacker> getWave1();
	std::list<Hacker> getWave2();
	std::list<Hacker> getWave3();
	void setWave(std::list<Hacker>);
};

