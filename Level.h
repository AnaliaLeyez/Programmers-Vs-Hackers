#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "UI.h"
#include "Map.h"
#include "TowerMenu.h"
#include "TowerMenu1.h"
#include "TowerMenu2.h"
#include "Tower.h"
#include "Spot.h"
#include "Bullet.h"
#include "BulletA.h"
#include "BulletB.h"
#include "BulletC.h"
#include "BulletD.h"

class Level: public sf::Drawable, public sf::Transformable
{
protected:
	int _idLevel;
	bool _finishedLevel;
	UI _ui;
	sf::Texture _textureUTN;
	sf::RectangleShape _UTN;
	sf::Texture _textureUTNRed;
	sf::RectangleShape _UTNRed;
	bool _dying;

	Map *_map;
	int _mapArray[20][30];
	std::vector<Spot*> _spots;
	TowerMenu* _currentMenu;
	TowerMenu1* _menu1 = new TowerMenu1();
	TowerMenu2* _menu2 = new TowerMenu2();
	int _golden;
	int _energy;
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	bool _musicPlaying;

	std::vector<Hacker*> _enemies;
	int _currentWave;
	int _totalWaves;
	int _enemiesPerWave;
	int _timeBetweenWaves;
	int _timeBetweenEnemies;
	sf::Clock _waveClock;
	sf::Clock _enemyClock;

	sf::Vector2f _hackerStartPosition;
	std::list <Tower*> _towersAvailable;
	std::list <Tower*> _activeTowers;

	std::list<Bullet*> _bullets;
	
	//NUEVO:
	sf::Clock _noCoinsClock;
	sf::Font _font;
	sf::Text _NoCoins;
	sf::Time _displayTimeNoCoins;
	bool _flagNoCoins;
	sf::Text _gameOver;
	bool _flagGameOver;
	//FIN NUEVO

	//A VER GASTON
	std::vector<sf::CircleShape> _debugShapes;

public:
	int getIdLevel() const;
	bool getFinisheLevel()const;
	UI getUI() const;
	Map getMap() const;
	int(*getMapArray())[30];
	const std::vector<Spot*> getSpots() const;
	Spot getCurrentSpot() const; //DEBERIA SER PUNTERO
	Spot getSpotByNumber(int) const; //DEBERIA SER PUNTERO
	TowerMenu getCurrentMenu() const; //DEBERIA SER PUNTERO
	int getGolden();
	int getEnergy();
	sf::SoundBuffer getBuffer() const;
	bool getMusicPlaying() const;
	sf::Sound getSound() const;
	sf::Vector2f getHackerStartPosition() const;
	const std::list<Tower*> getTowersAvailable() const;
	std::list <Tower*> getActiveTowers() const;

	void setIdLevel(int);
	void setFinishedLevel(bool);
	void setUI(const UI&);
	void setMap(const Map&);
	void setMapArray(const int(&)[20][30]);
	void setGolden(int);
	void setEnergy(int);
	void setMusicPlaying(bool);
	void setSound(bool);
	void setTowersAvailable(Tower*);
	void setActiveTowers(Tower*);
	void setSpot(Spot*); //setea la info de un spot en particular
	void setCurrentSpot(Spot); //para que el currentMenu tenga su Spot asociado
	void setCurrentMenu(TowerMenu*);

	void setNoCoinsText(); //NUEVO

	void spawnWave();

	void mouseCheck(sf::Vector2i&);
	void validateClick(int, int);
	int validateClickOnSpot(int, int);
	void manageClickOnSpot(int, int, Spot&);
	Spot manageOutOfSpotClick(int, int); //DEBERIA SER PUNTERO??????
	void clickWithMenu1Open(int, int, Spot&);
	void clickWithMenu2Open(int, int, Spot&);
	void validateClickOnSpeaker(int, int);

	bool validateSale(Tower*, bool); //nuevo
	void sell(Tower*, Spot&);
	void resellTower(Spot&);

	
	//void shoot(Bullet*, Hacker*); //ANA
	void shoot(sf::Vector2f, sf::Vector2f, int, int);
	void checkLevelCompletion();
	void setGameOverText();

	void draw(sf::RenderTarget&, sf::RenderStates) const;
	void update(sf::Vector2i&);
	~Level() { //revisar eliminar todo lo que haya sido asignado con memoria dinamica
		for (Spot* spot : _spots) {
			delete spot;
		}
	}
};

