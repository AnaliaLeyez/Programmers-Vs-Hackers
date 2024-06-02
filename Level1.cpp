#include <iostream>
#include "UI.h"
#include "Map.h"
#include "Map1.h"
#include "Tower.h"
#include "TowerBrian.h"
#include "TowerKloster.h"
#include "TowerSarF.h"
#include "TowerWenner.h"
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

void Level::spawnWave() {
	static int enemyIndex = 0;

	// Verifico si todavía hay enemigos para agregar en esta oleada
	if (enemyIndex < _enemiesPerWave) {
		// Genero un nuevo enemigo
		if (_enemyClock.getElapsedTime().asSeconds() >= _timeBetweenEnemies) {

			HackerTrainee* hacker = new HackerTrainee();
			_enemies.push_back(hacker);
			//std::cout << "Wave " << _currentWave << ": Enemigo " << enemyIndex + 1 << " de " << _enemiesPerWave << std::endl;
			_enemyClock.restart();
			++enemyIndex;
		}
	}
	else {
		// Si ya agregue todos los enemigos de esta oleada
		enemyIndex = 0; // Reinicio el índice para la próxima oleada
		_enemiesPerWave += 10; // Incremento la cantidad de enemigos para la próxima oleada
		++_currentWave; // Incremento el número de oleada
		/*std::cout << "Comenzando Wave " << _currentWave << std::endl;*/
		_waveClock.restart(); // Reinicio el temporizador de la oleada
	}
}

Level1::Level1()
{
	_currentWave = 1;
	_enemiesPerWave = 5;
	_timeBetweenWaves = 10;
	_timeBetweenEnemies = 2;
	_waveClock.restart();
	_enemyClock.restart();

	_idLevel=1;
	_finishedLevel = false;
	_map = new Map1();
	int arr[20][30] = {
{0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,2,1,1,1,5},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,6,0,1,0,0,0,0,0,0,0,0,1,0,0,6,0,0,0,0,0,0,6,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,3,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};

	_dying = false;
	if (!_textureUTN.loadFromFile("img/towers/facu.png")) {
		throw std::runtime_error("Error al cargar img UTN");
	};
	_UTN.setSize(sf::Vector2f(200, 173));
	_UTN.setTexture(&_textureUTN);
	_UTN.setPosition(sf::Vector2f(850, 130));
	_UTN.setOrigin(_UTN.getGlobalBounds().width / 2, _UTN.getGlobalBounds().height / 2);

	if (!_textureUTNRed.loadFromFile("img/towers/facuRed.png")) {
		throw std::runtime_error("Error al cargar img UTN");
	};
	_UTNRed.setSize(sf::Vector2f(200, 173));
	_UTNRed.setTexture(&_textureUTNRed);
	_UTNRed.setPosition(sf::Vector2f(850, 130));
	_UTNRed.setOrigin(_UTNRed.getGlobalBounds().width / 2, _UTNRed.getGlobalBounds().height / 2);

	setSpots(arr, _spots);
	_golden = 500;
	_energy = 500;
	_ui.setText(0, std::to_string(getGolden()));
	setMapArray(arr);
	if (!_buffer.loadFromFile("music/nivel1.wav")) {
		throw std::runtime_error("Error al cargar musica nivel 1");
	};
	_sound.setBuffer(_buffer);
	_sound.setVolume(5);
	_sound.play();
	_musicPlaying = true;
	/*setWaves(_waves);*/
	_hackerStartPosition = { 960 / 32 * 9, 640 / 32 * 1 };
	_towersAvailable.push_back(TowerBrian());
	_towersAvailable.push_back(TowerKloster());
	_towersAvailable.push_back(TowerSarF());
	_towersAvailable.push_back(TowerWenner());
}
