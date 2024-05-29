#include <iostream>
#include "UI.h"
#include "Map.h"
#include "Map1.h"
#include "Tower.h"
#include "TowerBrian.h"
#include "Level.h"
#include "Spot.h"
#include "Level1.h"

void setSpots(int arr[][30], std::vector<Spot*> &spots) {
for (int i = 0; i < 5; i++)
{
	Spot* sp = new Spot();
	spots.push_back(sp);
}
//Ubicar spots
	int index = 0;
	for (int x = 0; x < 30; x++)
	{
		for (int y = 0; y < 20; y++)
		{
			if (arr[y][x] == 6 && index<5)
			{				
				spots[index]->setPosition(32 * x, 32 * y);
				spots[index]->setSpotNumber(index + 1);
				index++;
			}
		}
	}
}

void setWaves(std::list<std::list<Hacker>> &waves) {
	std::list<Hacker> hackers1;
	hackers1.push_back(HackerTrainee());
	hackers1.push_back(HackerTrainee());
	hackers1.push_back(HackerTrainee());
	waves.push_back(hackers1);
	std::list<Hacker> hackers2;
	hackers2.push_back(HackerTrainee());
	hackers2.push_back(HackerTrainee());
	waves.push_back(hackers2);
}

Level1::Level1()
{
	_idLevel=1;
	_finishedLevel = false;
	_map = new Map1();
	int arr[20][30] = {
{0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,2,1,1,1,5},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,6,0,0,0,0,0,0,0,0,6,0},
{0,0,0,0,0,0,6,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

	};
	setSpots(arr, _spots);
	_golden = 500;
	_energy = 500;
	setMapArray(arr);
	if (!_buffer.loadFromFile("music/nivel1.wav")) {
		throw std::runtime_error("Error al cargar musica nivel 1");
	};
	_sound.setBuffer(_buffer);
	_sound.setVolume(5);
	_sound.play();
	_musicPlaying = true;
	setWaves(_waves);
	_hackerStartPosition = { 960 / 32 * 9, 640 / 32 * 1 };
	_towersAvailable.push_back(TowerBrian());
	
	//TowerMenu currentMenu = TowerMenu::getInstance();
	//_currentMenu = &currentMenu;
}
