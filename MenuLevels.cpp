#include "Manager.h"
#include "FileLevel.h"
#include "MenuAbstract.h"
#include "MenuLevels.h"

MenuLevels::MenuLevels() : Menu() {
	FileLevels arc;
	Levels reg;
	//texto
	for (int i = 0; i < 5; i++) {
		_text[i].setFont(_font);
		_text[i].setCharacterSize(30);
		int posY;
		std::string texto;

		reg = arc.read(i);

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
			posY = 600;
			break;
		}

		if (reg.getStatus()) {
			texto = reg.getName();
		}
		else {
			texto = "";
		}
		
		_text[i].setPosition(250, posY);
		_text[i].setString(texto);
		_text[i].setOrigin(_text[i].getGlobalBounds().getPosition().x / 2, _text[i].getGlobalBounds().height / 2);
		_text[i].setFillColor(sf::Color(255, 255, 255));
	}
	_text[5].setFont(_font);
	_text[5].setCharacterSize(25);
	_text[5].setPosition(20, 20);
	_text[5].setString("BACK");
	_text[5].setOrigin(_text[5].getGlobalBounds().getPosition().x / 2, _text[5].getGlobalBounds().height / 2);
	_text[5].setFillColor(sf::Color(0, 0, 0));
}

sf::Text MenuLevels::getText1() const { return _text[0]; }
sf::Text MenuLevels::getText2() const { return _text[1]; }
sf::Text MenuLevels::getText3() const { return _text[2]; }
sf::Text MenuLevels::getText4() const { return _text[3]; }
sf::Text MenuLevels::getText5() const { return _text[4]; }
sf::Text MenuLevels::getText6() const { return _text[5]; }

void MenuLevels::validateClick(int mousex, int mousey, sf::RenderWindow& window, int& view)
{
	if (getText1().getGlobalBounds().contains(mousex, mousey)) {
		setSound(false);
		setMusicPlaying(false);
		Manager::getInstance().setNumberLevel(0);
		view = 2;
	}
	else if (getText2().getGlobalBounds().contains(mousex, mousey) && getText2().getString()!="") {
		setSound(false);
		setMusicPlaying(false);
		Manager::getInstance().setNumberLevel(1);
		view = 2;
	}
	//LEVEL 3:
	/*else if (getText3().getGlobalBounds().contains(mousex, mousey) && getText2().getString() != "") {
		setSound(false);
		setMusicPlaying(false);
		Manager::getInstance().setNumberLevel(2);
		view = 2;
	}*/
	//VOLVER:
	else if (getText6().getGlobalBounds().contains(mousex, mousey)) {
		MenuAbstract::getInstance().setNumberMenu(1);
	}
}

void MenuLevels::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	Menu::draw(target, states);
	for (int i = 0; i < 6; i++) {
		target.draw(_text[i], states);
	}
}