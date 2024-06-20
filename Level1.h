#pragma once
class Level1: public Level
{
private:
	int _hackersPerWave[4] = {4, 6, 8, 8};
	int _wave1[4] = { 1, 1, 1, 1};
	int _wave2[6] = { 1, 1, 1, 2, 2, 1 };
	int _wave3[8] = { 1, 2, 1, 1, 2, 2, 2, 1};
	int _wave4[8] = { 2, 1, 2, 2, 2, 2, 2, 2 };
public:
	Level1();
	void spawnWave() override;
};


