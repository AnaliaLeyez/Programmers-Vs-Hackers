#pragma once
#include "HackerTrainee.h"
#include "HackerJunior.h"
#include "HackerSemiSr.h"
#include "HackerDios.h"
class Level1: public Level
{
private:
	int _hackersPerWave[4] = {4, 6, 8, 8};
	Hacker* _wave1[4] = {new HackerTrainee, new HackerTrainee, new HackerTrainee, new HackerTrainee };
	Hacker* _wave2[6] = {new HackerTrainee, new HackerTrainee, new HackerTrainee, new HackerJunior, new HackerJunior, new HackerTrainee };
	Hacker* _wave3[8] = {new HackerTrainee, new HackerJunior, new HackerTrainee, new HackerTrainee, new HackerJunior, new HackerJunior, new HackerJunior };
	Hacker* _wave4[8] = {new HackerTrainee, new HackerJunior, new HackerJunior, new HackerJunior, new HackerJunior, new HackerJunior, new HackerJunior, new HackerJunior};
public:
	Level1();
	void spawnWave() override;
};

