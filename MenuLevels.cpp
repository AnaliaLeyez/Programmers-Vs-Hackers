#include "Manager.h"
#include "FileLevel.h"
#include "MenuAbstract.h"
#include "MenuLevels.h"

MenuLevels::MenuLevels(bool state)
{
	/*
	_musicPlaying = state;

	if (_soundManager.getMusicOn()) {
		_soundManager.playMusic();
	}
	else {
		_soundManager.pauseMusic();
	}
	*/
	FileLevels arc;
	Levels reg;
	
	//texto
	for (int i = 0; i < 6; i++) {
		_text[i].setFont(_font);
		_text[i].setCharacterSize(30);
		int posY, posX=250;
		std::string texto;

		switch (i)
		{
		case 0:
			posY = 100;
			break;
		case 1:
			posY = 200;
			break;
		case 2:
			posY = 300;
			break;
		case 3:
			posY = 400;
			break;
		case 4:
			posY = 500;
			break;
		case 5:
			posX = 25;
			posY = 25;
			texto = "BACK";
			break;
		}
		if (i != 5) {
			reg = arc.read(i);
			if (reg.getStatus()) {
				texto = reg.getName();
			}
			else {
				texto = "";
			}
		}		
		_text[i].setPosition(posX, posY);
		_text[i].setString(texto);
		_text[i].setOrigin(_text[i].getGlobalBounds().getPosition().x / 2, _text[i].getGlobalBounds().height / 2);
		_text[i].setFillColor(sf::Color(255, 255, 255));
	}
}

void MenuLevels::validateClick(int mousex, int mousey, sf::RenderWindow& window, int& view)
{
	if (getText1().getGlobalBounds().contains(mousex, mousey)) {
		//setSound(false);
		//setMusicPlaying(false);
		//_soundManager.setMusicOn(false);
		//MenuAbstract::getInstance().stopMusic();
		std::cout << "Menulevls validate if" << std::endl;
		Manager::getInstance().setNumberLevel(0);
		view = 2;
	}
	else if (getText2().getGlobalBounds().contains(mousex, mousey) && getText2().getString()!="") {
		//setSound(false);
		//setMusicPlaying(false);
		//_soundManager.setMusicOn(false);
		//MenuAbstract::getInstance().stopMusic();
		Manager::getInstance().setNumberLevel(1);
		std::cout << "Menulevls validate elsif" << std::endl;
		view = 2;
	}
	else if (getText3().getGlobalBounds().contains(mousex, mousey) && getText2().getString() != "") {
		//setSound(false);
		//setMusicPlaying(false);
		//_soundManager.setMusicOn(false);
		std::cout << "Menulevls validate 2eslif" << std::endl;
		Manager::getInstance().setNumberLevel(2);
		view = 2;
	}
	else if (getText4().getGlobalBounds().contains(mousex, mousey) && getText2().getString() != "") {
		//setSound(false);
		//setMusicPlaying(false);
		//_soundManager.setMusicOn(false);
		std::cout << "Menulevls validate 3eslif" << std::endl;
		Manager::getInstance().setNumberLevel(2); //ajustar para que vaya a level 4 (mandar un 3)
		view = 2;
	}
	//VOLVER:
	else if (getText6().getGlobalBounds().contains(mousex, mousey)) {
		//MenuAbstract::getInstance().saveSoundPosition();
		MenuAbstract::getInstance().setNumberMenu(1);
		//MenuAbstract::getInstance().restoreSoundPosition();
	}
}

void MenuLevels::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	Menu::draw(target, states);
	for (int i = 0; i < 6; i++) {
		target.draw(_text[i], states);
	}
}