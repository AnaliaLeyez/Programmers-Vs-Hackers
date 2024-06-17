#include <iostream>
#include <cstdlib> // Necesario para std::rand() y std::srand()
#include <ctime> 
#include "UI.h"
#include "Map.h"
#include "Map2.h"
#include "Tower.h"
#include "TowerBrian.h"
#include "TowerKloster.h"
#include "TowerSarF.h"
#include "TowerWenner.h"
#include "HackerTrainee.h"
#include "HackerJunior.h"
#include "Level.h"
#include "Spot.h"
#include "Level2.h"

void Level2::spawnWave() {
	std::srand(std::time(nullptr));
	static int enemyIndex = 0;
	static bool spawnedGodHacker = false;

	if (enemyIndex < _enemiesPerWave) {
		// Genera un nuevo enemigo
		int randomTime = std::rand() % 8 + 1;
		if (_enemyClock.getElapsedTime().asSeconds() >= randomTime) {
			switch (_currentWave)
			{
			case 1:
			{
				HackerTrainee* hk = new HackerTrainee();
				hk->setPosition(_hackerStartPosition);
				_enemies.push_back(hk);
			}
			break;
			case 2:
			{
				if (enemyIndex % 2 == 0) {
					HackerTrainee* hk = new HackerTrainee();
					hk->setPosition(_hackerStartPosition);
					_enemies.push_back(hk);
				}
				else {
					HackerJunior* hk = new HackerJunior();
					hk->setPosition(_hackerStartPosition);
					_enemies.push_back(hk);
				}
			}
			break;
			case 3:
			{
				if (enemyIndex % 3 != 0) {
					HackerJunior* hk = new HackerJunior();
					hk->setPosition(_hackerStartPosition);
					_enemies.push_back(hk);
				}
				else {
					HackerTrainee* hk = new HackerTrainee();
					hk->setPosition(_hackerStartPosition);
					_enemies.push_back(hk);
				}
			}
			break;
			default:
				break;
			}
			++enemyIndex;
			_enemyClock.restart();
		}
	}
	else if (_waveClock.getElapsedTime().asSeconds() > _timeBetweenWaves && _enemies.empty() && enemyIndex == _enemiesPerWave) {
		++_currentWave; // Incrementa el número de oleada
		if (_currentWave <= _totalWaves) {
			enemyIndex = 0; // Reinicia el índice para la próxima oleada
			_enemiesPerWave += 1; // Incrementa la cantidad de enemigos para la próxima oleada

			_ui.setText(2, std::to_string(getCurrentWave()));
			spawnedGodHacker = false;
			_waveClock.restart(); // Reinicia el temporizador de la oleada
		}
	}
}

Level2::Level2()
{
	_currentWave = 1;
	_totalWaves = 4;
	_enemiesPerWave = 5;
	_timeBetweenWaves = 10;
	//_timeBetweenEnemies = std::rand() % 15 + 1; ///ver si esta queda o se va 
	_waveClock.restart();
	_enemyClock.restart();
	_hackerStartPosition = { 960 / 32 * 0.5, 640 / 32 * 28 };

	_idLevel = 1;
	_finishedLevel = false;
	_map = new Map2();
	int arr[22][30] = {
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,2,1,1,9},
{0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,6,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,6,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,6,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{2,1,1,1,1,1,1,1,1,3,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,1,3,0,0,0,0,0,0,0}
	};
	setMapArray(arr);

	_dying = false;
	if (!_textureUTN.loadFromFile("img/towers/facu.png")) {
		throw std::runtime_error("Error al cargar img UTN");
	};
	_UTN.setSize(sf::Vector2f(200, 173));
	_UTN.setTexture(&_textureUTN);
	_UTN.setPosition(sf::Vector2f(950, 260));
	_UTN.setOrigin(_UTN.getGlobalBounds().width / 2, _UTN.getGlobalBounds().height / 2);

	if (!_textureUTNRed.loadFromFile("img/towers/facuRed.png")) {
		throw std::runtime_error("Error al cargar img UTN");
	};
	_UTNRed.setSize(sf::Vector2f(200, 173));
	_UTNRed.setTexture(&_textureUTNRed);
	_UTNRed.setPosition(sf::Vector2f(950, 173));
	_UTNRed.setOrigin(_UTNRed.getGlobalBounds().width / 2, _UTNRed.getGlobalBounds().height / 2);

	setSpots(arr, _spots, 4);
	_golden = 5000;
	_energy = 300;
	_ui.setText(0, std::to_string(getGolden()));
	_ui.setText(1, std::to_string(getEnergy()));
	_ui.setText(2, std::to_string(getCurrentWave()));
	_ui.setText(3, "/" + std::to_string(getTotalWaves()));

	if (!_buffer.loadFromFile("music/nivel1.wav")) {
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
}