#include <iostream>
#include <cstdlib> // Necesario para std::rand() y std::srand()
#include <ctime> 
#include "UI.h"
#include "Map.h"
#include "Map1.h"
#include "Tower.h"
#include "TowerBrian.h"
#include "TowerKloster.h"
#include "TowerSarF.h"
#include "TowerWenner.h"
#include "HackerTrainee.h"
#include "HackerJunior.h"
#include "HackerSemiSr.h"
#include "HackerDios.h"
#include "Level.h"
#include "Spot.h"
#include "Level1.h"

void Level1::spawnWave() {
	std::srand(std::time(nullptr));
	//los contadores son de tipo static porque asi las variables mantienen su valor incluso
	//despues de que la funcion haya terminado de ejecutarse
	static int enemyIndex = 1;
	static bool spawnedGodHacker = false;
	Hacker* hk;
	if (enemyIndex <= _enemiesPerWave) {
		// Genera un nuevo enemigo
		int randomTime = std::rand() % 4 + 1;
		if (_enemyClock.getElapsedTime().asSeconds() >= randomTime) {
			switch (_currentWave)
			{
			case 1:
			{
				hk = new HackerTrainee();
			}
			break;
			case 2:
			{
				if (enemyIndex % 2 == 0) {
					hk = new HackerTrainee();
				}
				else {
					hk = new HackerJunior();
				}
			}
			break;
			case 3:
			default:
			{
				if (enemyIndex % 3 != 0) {
					hk = new HackerSemiSr();
				}
				else {
					hk = new HackerDios();
				}
			}
			break;
			}
			hk->setPosition(_hackerStartPosition);
			_enemies.push_back(hk);
			if (enemyIndex == 1) {
				hk->saySth();
			}
			++enemyIndex;
			_enemyClock.restart();
		}
	}
	else if(_waveClock.getElapsedTime().asSeconds()>_timeBetweenWaves && _enemies.empty() && enemyIndex>_enemiesPerWave) {
		++_currentWave; // Incrementa el número de oleada
		if (_currentWave <= _totalWaves) {
			enemyIndex = 1; // Reinicia el índice para la próxima oleada
			_enemiesPerWave += 2; // Incrementa la cantidad de enemigos para la próxima oleada

			_ui.setText(2, std::to_string(getCurrentWave()));
			spawnedGodHacker = false;
			_waveClock.restart(); // Reinicia el temporizador de la oleada
		}
	}
}


Level1::Level1()
{
	_currentWave = 1;
	_totalWaves = 3;
	_enemiesPerWave = 1;
	_timeBetweenWaves = 15;
	//_timeBetweenEnemies = std::rand() % 15 + 1; ///ver si esta queda o se va 
	_waveClock.restart();
	_enemyClock.restart();
	_hackerStartPosition = { 960 / 32 * 9.5, 640 / 32 * 0.5 };

	_idLevel = 0;
	_finishedLevel = false;
	_map = new Map1();
	int arr[22][30] = {
{0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,1,1,1,3,0,0},
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
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
	setMapArray(arr);

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

	setSpots(arr, _spots, 5);
	_golden = 3000;
	_energy = 500;
	_ui.setText(0, std::to_string(getGolden()));
	_ui.setText(1, std::to_string(getEnergy()));
	_ui.setText(2, std::to_string(getCurrentWave()));
	_ui.setText(3, "/" + std::to_string(getTotalWaves()));

	if (!_buffer.loadFromFile("music/level1.wav")) {
		throw std::runtime_error("Error al cargar musica nivel 1");
	};
	_sound.setBuffer(_buffer);
	_sound.setVolume(5);
	_sound.play();
	_musicPlaying = true;

	_towersAvailable.push_back(new TowerBrian());
	_towersAvailable.push_back(new TowerKloster());
	_towersAvailable.push_back(new TowerSarF());
	_towersAvailable.push_back(new TowerWenner());

	_currentMenu = _menu1;

	setNoCoinsText(); //NUEVO
	setLevelUpText();
}
