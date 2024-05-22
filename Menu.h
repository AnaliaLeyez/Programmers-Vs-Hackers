#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

using namespace std;

class Menu : public sf::Drawable
{
private:
	Menu(); //Singleton
	static Menu* _currentInstance; //Singleton
	sf::Texture _textureBanner;
	sf::RectangleShape *_banner;
	sf::Font _font;
	sf::Text _text[5];
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	bool _musicPlaying;
public:
	//Menu();
	static Menu& getInstance(); //Singleton
	sf::Text getText1() const;
	sf::Text getText2() const;
	sf::Text getText3() const;
	sf::Text getText4() const;
	sf::Text getText5() const;

	//MUSICA   Podria heredarse de una clase Musica
	void validateClick(int, int, Menu&, sf::RenderWindow&, int &);
	bool getMusicPlaying() const;
	void setMusicPlaying(bool);
	sf::Sound getSound() const;
	void setSound(bool);

	virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};

