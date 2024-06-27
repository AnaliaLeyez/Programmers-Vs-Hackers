#pragma once
#include <SFML/Audio.hpp>


class SoundManager
{
private:
	SoundManager();
	static SoundManager* _currentInstance; //Singleton
	bool _musicOn;
	sf::Music _currentMusic;

public:
	static SoundManager& getInstance();
	bool getMusicOn();
	void setVolume(float);
	void setMusicOn(bool);

	void loadMusic(const std::string& route);
	void playMusic();
	void stopMusic();
	void pauseMusic();
};

