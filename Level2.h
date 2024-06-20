#pragma once
class Level2 : public Level
{
private:
private:
	int _hackersPerWave[3] = { 6, 8, 10 };
	int _wave1[6] = { 2, 2, 2, 2, 2, 3 };
	int _wave2[8] = { 2, 2, 2, 2, 2, 3, 3, 3 };
	int _wave3[10] = { 1, 2, 3, 3, 3, 3, 3, 3, 2, 3 };
public:
	Level2();
	void spawnWave() override;
};