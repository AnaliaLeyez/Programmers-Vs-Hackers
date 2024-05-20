#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Menu.h"
#include "UI.h"
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
	Menu menu;
	Level level;
	Level1 level1;
	Map1 mapa1;
	UI ui;
	int view = 1;
	bool flag = false;

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
					menu.validateClick(mousex, mousey, menu, window, view);
					//if (view == 2) {
					//	if (!flag) {
					//		GamePlay& gp = GamePlay::getInstance();
					//		flag = true;
					//	}
					// 
					// 
						//aca la logica del nivel 1??
						//gp.validateClick(mousex, mousey); //OBJETIVO: TENER ESTA FUNCION
					//gp.validateClickOnMap(mousex, mousey, mapa);
					//gp.validateClickOnMenu(mousex, mousey, menu, window, vista);
					}
					
				}
		//Render Cycle
		window.clear();
		switch (view)
		{
		case 1:
		{
			window.draw(menu);
		}
		break;
		case 2:
		{
			window.draw(level1);
			/*window.draw(mapa1);
			window.draw(ui);*/
			//window.draw(gp);
		}
		break;
		}
		//RenderOjbects
		window.display();
	}

	return 0;
}