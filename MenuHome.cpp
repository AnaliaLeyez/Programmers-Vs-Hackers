#include "FileLevel.h"
#include "MenuAbstract.h"
#include "MenuHome.h"

MenuHome::MenuHome(bool state) {
	_musicPlaying = state;

	//texto
	for (int i = 0; i < 5; i++) {
		_text[i].setFont(_font);
		_text[i].setCharacterSize(30);
		int posY;
		std::string texto;
		switch (i)
		{
		case 0:
			posY = 100;
			texto = "Continue Game";
			break;
		case 1:
			posY = 200;
			texto = "Restart Game";
			break;
		case 2:
			posY = 300;
			texto = "Info";
			break;
		case 3:
			posY = 400;
			texto = "Pause music";
			break;
		case 4:
			posY = 500;
			texto = "Exit";
			break;
		default:
			break;
		}
		_text[i].setPosition(250, posY);
		_text[i].setString(texto);
		_text[i].setOrigin(_text[i].getGlobalBounds().getPosition().x / 2, _text[i].getGlobalBounds().height / 2);
		_text[i].setFillColor(sf::Color(255, 255, 255));
	}
}


bool MenuHome::getMusicPlaying() const { return _musicPlaying; }
//sf::Sound MenuHome::getSound() const { return _sound; }

void MenuHome::setSoundText(bool play) {
	if (play) {
		_text[3].setString("Pause music");
	}
	else {
		_sound.pause();
		_text[3].setString("Play music");
	}
}

void MenuHome::validateClick(int mousex, int mousey, sf::RenderWindow& window, int& view)
{
	if (getText1().getGlobalBounds().contains(mousex, mousey)) {
		//bool wasMusicPlaying = getMusicPlaying();
		//MenuAbstract::getInstance().saveSoundPosition();
		setSound(false);
		setMusicPlaying(false);
		MenuAbstract::getInstance().setNumberMenu(2);
		//MenuAbstract::getInstance().restoreSoundPosition();
		//MenuAbstract::getInstance().getCurrentMenu()->setMusicPlaying(wasMusicPlaying);
	}
	else if (getText2().getGlobalBounds().contains(mousex, mousey)) {
		FileLevels arc;
		arc.reset();
		//MenuAbstract::getInstance().saveSoundPosition();
		MenuAbstract::getInstance().setNumberMenu(2);
		//MenuAbstract::getInstance().restoreSoundPosition();
	}
	else if (getText4().getGlobalBounds().contains(mousex, mousey)) {
		if (getMusicPlaying()) {
			setSoundText(false);
			setSound(false);
			setMusicPlaying(false);
		}		 
		else {
			setSoundText(true);
			setSound(true);
			setMusicPlaying(true);
		}
	}else if (getText5().getGlobalBounds().contains(mousex, mousey)) {
		window.close();
	}
}

void MenuHome::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	Menu::draw(target, states);
	for (int i = 0; i < 5; i++) {
		target.draw(_text[i], states);
	}
}