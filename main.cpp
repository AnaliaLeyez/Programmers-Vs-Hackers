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
	int vista = 1;

	Menu menu;
	menu.setSound(true);

	Map1 mapa;
	UI ui;

	//Cosos:
	TowerLab torrePrueba({200.f,200.f});
	HackerTrainee kaker;

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

			//HACER FUNCION PARA CAPTURAR EVENTO CLICK
			// si se recibe un evento de clic del rat n
			if (ev.type == sf::Event::MouseButtonPressed) {
				if (ev.mouseButton.button == sf::Mouse::Left) {
					// obtiene las coordenadas del clic
					int mousex = ev.mouseButton.x;
					int mousey = ev.mouseButton.y;
					gp.validateClickOnMap(mousex, mousey, mapa);
					gp.validateClickOnMenu(mousex, mousey, menu, window, vista);
					// verifica si las coordenadas del clic est n dentro del sprite
				}
			}
		}
		//Render Cycle
		window.clear();
		//RenderOjbects
		switch (vista)
		{
		case 1:
			window.draw(menu);
			break;
		case 2:
			//Pruebas:
			kaker.moveHacker();
			torrePrueba.verificarEnemigo(kaker);

			window.draw(mapa);
			window.draw(ui);
			window.draw(torrePrueba);
			window.draw(kaker);

		default:
			break;
		}
		window.display();
	}

	return 0;
}