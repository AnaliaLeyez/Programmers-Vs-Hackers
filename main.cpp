#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "Menu.h"
#include "MenuAbstract.h"
#include "UI.h"
#include "Manager.h"
#include "Level.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 640), "Programmers Vs Hackers");
	window.setFramerateLimit(60);
	int view = 1;
	while (window.isOpen())
	{
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::EventType::Closed)
				window.close();
			if (ev.key.code == sf::Keyboard::Key::Escape)
				window.close();

			if (ev.type == sf::Event::MouseButtonPressed && ev.mouseButton.button == sf::Mouse::Left)
			{
				int mousex = ev.mouseButton.x;
				int mousey = ev.mouseButton.y;
				switch (view)
				{
				case 1:
				{
					MenuAbstract& menu = MenuAbstract::getInstance();
					menu.validateClick(mousex, mousey, window, view);
				}
				break;
				case 2:
				{
					Manager& mg = Manager::getInstance();
					mg.validateClick(mousex, mousey);
				}
				break;
				}
				
			}
			//Render Cycle
		}
			window.clear();
			switch (view)
			{
			case 1:
			{
				//Menu& menu = Menu::getInstance();
				MenuAbstract& menu = MenuAbstract::getInstance();
				window.draw(menu);
			}
			break;
			case 2:
			{
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