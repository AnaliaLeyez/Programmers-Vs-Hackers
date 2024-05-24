#pragma once
#include "SFML/Graphics.hpp"
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>
#include "UI.h"
#include "Wave.h"
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
	sf::Texture _textureUTN;
	sf::Sprite _spriteUTN;
	Map *_map;
	int _mapArray[20][30];
	std::list<Spot> *_spots;
	int _golden;
	int _energy;
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	bool _musicPlaying;
	std::list<Wave> *_waveList;
	sf::Vector2f _hackerStartPosition;
	std::list <Tower> _towersAvailable;
	TowerMenu _towerMenu;
public:
	int getIdLevel() const;
	bool getFinisheLevel()const;
	UI getUI() const;
	Map getMap() const;
	int(*getMapArray())[30];
	int getGolden() const;
	int getEnergy() const;
	sf::SoundBuffer getBuffer() const;
	bool getMusicPlaying() const;
	sf::Sound getSound() const;
	std::list<Wave> getWaveList() const;
	sf::Vector2f getHackerStartPosition() const;
	const std::list<Tower>& getTowersAvailable() const;

	void setIdLevel(int);
	void setFinishedLevel(bool);
	void setUI(const UI&);
	void setMap(const Map&);
	void setMapArray(const int(&)[20][30]);
	void setGolden(int);
	void setEnergy(int);
	void setMusicPlaying(bool);
	void setSound(bool);
	void setWaveList(const std::list<Wave>&);
	void setTowersAvailable(const std::list<Tower>&);

	//void shoot(sf::Vector2f position);
	void handlerEvent(const sf::Event&);

	void validateClick(int, int);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	void update();
};

