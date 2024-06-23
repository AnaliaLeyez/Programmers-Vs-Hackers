#include "SoundManager.h"

SoundManager* SoundManager::_currentInstance = nullptr;

SoundManager::SoundManager() : _currentMusic() {
    // Constructor implementation
}

SoundManager& SoundManager::getInstance() {
    if (SoundManager::_currentInstance == nullptr) {
        SoundManager::_currentInstance = new SoundManager();
    }
    return *SoundManager::_currentInstance;
}

void SoundManager::loadMusic(const std::string& route)
{
    if (_currentMusic.getStatus() == sf::Music::Playing)
        return;

    if (!_currentMusic.openFromFile(route)) {
        throw std::runtime_error("Error al cargar musica: " + route);
    }
    _currentMusic.setVolume(50.0f); // Default volume
    _currentMusic.setLoop(true); // Set loop if required
    //_currentMusic.play();
}

void SoundManager::playMusic()
{
    if (_currentMusic.getStatus() == sf::Music::Playing)
        return;

    _currentMusic.play();
}

void SoundManager::stopMusic()
{
    _currentMusic.stop();
}

void SoundManager::pauseMusic()
{
    _currentMusic.pause();
}



