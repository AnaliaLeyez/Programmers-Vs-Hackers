#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

using namespace std;

class Menu : public sf::Drawable
{
private:
	sf::Texture textureBanner;
	sf::RectangleShape banner;
	sf::Font font;
	sf::Text text[5];
	sf::SoundBuffer buffer;
	sf::Sound sound;
	bool musicPlaying;
public:
	Menu();
	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
	sf::Text getText1();
	sf::Text getText2();
	sf::Text getText3();
	sf::Text getText4();
	sf::Text getText5();

	//MUSICA   Podria heredarse de una clase Musica
	void validateClick(int, int, Menu&, sf::RenderWindow&, int &);
	bool getMusicPlaying();
	void setMusicPlaying(bool);
	sf::Sound getSound();
	void setSound(bool);
};

