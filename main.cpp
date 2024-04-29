#include "Menu.h"
#include "Mapa.h"
#include "UI.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "Programmers Vs Hackers");
	window.setFramerateLimit(60);
	int vista = 1;

	Menu menu;
	menu.setSound(true);

	Mapa mapa;
	UI ui;

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

		//Render Cycle
		window.clear();
		//RenderOjbects
		switch (vista)
		{
		case 1:
			window.draw(menu);
			break;
		case 2:
			window.draw(mapa);
			window.draw(ui);
		default:
			break;
		}
		window.display();
	}

	return 0;
}