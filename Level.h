#pragma once

#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "UI.h"
#include "Map.h"
#include "TowerMenu.h"
#include "Tower.h"
#include "Spot.h"

class Level: public sf::Drawable, public sf::Transformable
{
protected:
	int _idLevel;
	bool _finishedLevel;
	UI _ui;
	//sf::Texture _textureUTN;
	//sf::Sprite _spriteUTN;
	//NUEVO
	sf::Texture _textureUTN;
	sf::RectangleShape _UTN;
	sf::Texture _textureUTNRed;
	sf::RectangleShape _UTNRed;
	bool _dying;
	//NUEVO

	Map *_map;
	int _mapArray[20][30];
	std::vector<Spot*> _spots;
	TowerMenu *_currentMenu =new TowerMenu();  //el nivel tiene UN solo menu mostrandose

	int _golden;
	int _energy;
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	bool _musicPlaying;
	std::list<std::list<Hacker>> _waves;
	sf::Vector2f _hackerStartPosition;
	std::list <Tower> _towersAvailable;
	std::list <Tower> _activeTowers;
public:
	int getIdLevel() const;
	bool getFinisheLevel()const;
	UI getUI() const;
	Map getMap() const;
	int(*getMapArray())[30];
	const std::vector<Spot*> getSpots() const;
	Spot getCurrentSpot() const;
	Spot getSpotByNumber(int) const;
	TowerMenu getCurrentMenu() const;  //nuevo

	int getGolden();
	int getEnergy() const;
	sf::SoundBuffer getBuffer() const;
	bool getMusicPlaying() const;
	sf::Sound getSound() const;
	sf::Vector2f getHackerStartPosition() const;
	const std::list<Tower> getTowersAvailable() const;
	std::list <Tower> getActiveTowers() const;

	void setIdLevel(int);
	void setFinishedLevel(bool);
	void setUI(const UI&);
	void setMap(const Map&);
	void setMapArray(const int(&)[20][30]);
	void setGolden(int);
	void setEnergy(int);
	void setMusicPlaying(bool);
	void setSound(bool);
	void setTowersAvailable(Tower);
	void setActiveTowers(Tower);
	void setSpot(Spot*, int); //setea la info de un spot en particular
	void setCurrentSpot(Spot); //para que el currentMenu tenga su Spot asociado
	void setCurrentMenu(TowerMenu*);

	//void shoot(sf::Vector2f position);
	void handlerEvent(const sf::Event&);
	void mouseCheck(sf::Vector2i&);
	void validateClick(int, int);
	int validateClickOnSpot(int, int);
	void manageClickOnSpot(int, int, Spot&);
	Spot manageOutOfSpotClick(int, int);
	void validateClickOnSpeaker(int, int);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	void update(sf::Vector2i&);

	bool validateSale(TowerMenuButton*); //nuevo
	Level sell(Tower, Spot&);
};

