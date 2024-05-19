#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Menu.h"
#include "Map.h"
#include "Map1.h"
#include "UI.h"

#include "GamePlay.h"
#include "Player.h"
#include "Bullet.h"
#include "Hacker.h"
#include "HackerTrainee.h"
#include "Tower.h"
#include "TowerLab.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 640), "Programmers Vs Hackers");
	window.setFramerateLimit(60);
	GamePlay &gp = GamePlay::getInstance();

	//Primer while
	while (window.isOpen())
	{
		//Segundowhile eventlistener
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::EventType::Closed)
				window.close();
			if (ev.key.code == sf::Keyboard::Key::Escape)
				window.close();

			//CAPTURAR EVENTO CLICK
			if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
				 {
					int mousex = ev.mouseButton.x;
					int mousey = ev.mouseButton.y;
					gp.validateClick(mousex, mousey); //OBJETIVO: TENER ESTA FUNCION
					//gp.validateClickOnMap(mousex, mousey, mapa);
					//gp.validateClickOnMenu(mousex, mousey, menu, window, vista);
				}
		}
		//Render Cycle
		window.clear();
		//RenderOjbects
		window.display();
	}

	return 0;
}