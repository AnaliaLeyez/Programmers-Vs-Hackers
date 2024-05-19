#pragma once
#include "UI.h"
#include "Wave.h"
#include "Map.h"
#include "Tower.h"
class Level: public sf::Drawable
{
protected:
	int _idLevel;
	bool _finisheLevel;
	UI _ui;
	Map _map;
	int _mapArray[20][30];
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	bool _musicPlaying;
	std::list<Wave> _waveList;
	std::list <Tower> _towersAvailable;
public:
	// Getters
	int getIdLevel() const;
	bool getFinisheLevel()const;
	UI getUI() const;
	Map getMap();
	int(*getMapArray())[30];
	sf::SoundBuffer getBuffer() const;
	bool getMusicPlaying() const;
	sf::Sound getSound() const;
	std::list<Wave> getWaveList() const;
	const std::list<Tower>& getTowersAvailable() const;

	// Setters
	void setIdLevel(int);
	void setFinishedLevel(bool);
	void setUI(const UI&);
	void setMap(const Map&);
	void setMapArray(const int(&)[20][30]);
	void setMusicPlaying(bool);
	void setSound(bool);
	void setWaveList(const std::list<Wave>& list);
	void setTowersAvailable(const std::list<Tower>&);
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	void update();
};

