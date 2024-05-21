#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Menu.h"
#include "UI.h"
#include "Manager.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 640), "Programmers Vs Hackers");
	window.setFramerateLimit(60);
	Menu menu;
	int view = 1;

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
			//la vista 2 representaria que estoy viendo ALGUN NIVEL, sin especificar cual(?
			Manager& mg = Manager::getInstance();
			mg.update();
			window.draw(mg);
		}
		break;
		}
		//RenderOjbects
		window.display();
	}

	return 0;
}