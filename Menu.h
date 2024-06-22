#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class Menu :  public sf::Drawable
{
protected:
	sf::Texture _textureBanner;
	sf::RectangleShape _banner;
	sf::Font _font;
	sf::Text _text[6];
	sf::SoundBuffer _buffer;
	sf::Sound _sound;
	bool _musicPlaying;
public:
	Menu();
	virtual void validateClick(int, int, sf::RenderWindow&, int&)=0;
	sf::Text getText1() const;
	sf::Text getText2() const;
	sf::Text getText3() const;
	sf::Text getText4() const;
	sf::Text getText5() const;
	sf::Text getText6() const;
	void setMusicPlaying(bool);
	void setSound(bool);

	bool getMusicPlaying() const;
	float getSoundPosition() const;
	void setSoundPosition(float);

	//void update() {}
	void draw(sf::RenderTarget&, sf::RenderStates) const;
	~Menu();
};
