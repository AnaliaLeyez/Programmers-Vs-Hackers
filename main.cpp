#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Menu.h"
#include "Map.h"
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
	int vista = 2;

	Menu menu;
	menu.setSound(true);

	Map mapa;
	UI ui;

	//Cosos:
	TowerLab torrecitaPrueba;
	torrecitaPrueba.setPosition(200, 200);
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

					// verifica si las coordenadas del clic est n dentro del sprite
					if (menu.getText4().getGlobalBounds().contains(mousex, mousey)) {
						if (menu.getMusicPlaying()) {
							menu.setSound(false);
							menu.setMusicPlaying(false);
						}
						else {
							menu.setSound(true);
							menu.setMusicPlaying(true);
						}
					}
					if (menu.getText5().getGlobalBounds().contains(mousex, mousey)) {
						window.close();
					}

					if (menu.getText1().getGlobalBounds().contains(mousex, mousey)) {
						menu.setSound(false);
						menu.setMusicPlaying(false);
						vista = 2;
						mapa.setSound(true);
					}
					if (mapa.getParalante().getGlobalBounds().contains(mousex, mousey)) {
						if (mapa.getMusicPlaying()) {
							mapa.setSound(false);
							mapa.setMusicPlaying(false);
							mapa.setTextureParlante("img/complementarias/mute.png");
						}
						else {
							mapa.setSound(true);
							mapa.setMusicPlaying(true);
							mapa.setTextureParlante("img/complementarias/musicOn.png");
						}
					}
				}
			}
		}
		std::cout << kaker.getLife() << std::endl;
		
		if (kaker.getLife() < 0)
			std::cout << "Listo lo hizo re cajeta ya " << std::endl;

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
			torrecitaPrueba.verificarEnemigo(kaker);

			window.draw(mapa);
			window.draw(ui);
			window.draw(torrecitaPrueba);
			window.draw(kaker);

		default:
			break;
		}
		window.display();
	}

	return 0;
}