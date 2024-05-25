#include "UI.h"
#include "Map.h"
#include "Map1.h"
#include "Tower.h"
#include "TowerBrian.h"
#include "Level.h"
#include "Spot.h"
#include "Level1.h"

void setSpots(std::list<Spot> &spots) {
	Spot sp;
	sp.setSpotNumber(1);
	sp.setPosition(sf::Vector2f(200., 200));
	spots.push_back(sp);
	sp.setSpotNumber(2);
	sp.setPosition(sf::Vector2f(400, 400));
	spots.push_back(sp);
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
{0,0,0,0,0,0,0,0,1,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,2,1,1,1,5},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,6,6,6,0,0,0,0,0,0,6,6,6},
{0,0,0,0,0,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,0,0,0,0,0,0,6,6,6},
{0,0,0,0,0,6,6,6,1,0,0,0,0,0,0,0,0,1,6,6,6,0,0,0,0,0,0,6,6,6},
{0,0,0,0,0,6,6,6,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,6,6,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}

	};
	setSpots(_spots);
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
}
