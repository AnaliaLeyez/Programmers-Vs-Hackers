#pragma once
#include <SFML/Audio.hpp>


class SoundManager
{
private:
	SoundManager();
	SoundManager(const SoundManager&) = delete;
	SoundManager& operator=(const SoundManager&) = delete;
	static SoundManager* _currentInstance; //Singleton
	bool _musicOn;
	sf::Music _currentMusic;

public:
	static SoundManager& getInstance();

	void loadMusic(const std::string& route);
	void playMusic();
	void stopMusic();
	void pauseMusic();

	void setVolume(float);

	void setMusicOn(bool);
	bool getMusicOn();
};

