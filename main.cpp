#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "MenuAbstract.h"
#include "Manager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(960, 640), "Programmers Vs Hackers");
	window.setFramerateLimit(60);
	int view = 1;
	while (window.isOpen())
	{
		//prueba mas directa, una vez que funcione, esto va en level:
		Manager& mg = Manager::getInstance();
		mg.mouseCheck(window);
		if (mg.getInstance().getLevel().getUTN().getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(window)))) {
			std::cout << "FUNCIONA";
		}

		sf::Event ev;
		while (window.pollEvent(ev))
		{
			
			//movi window close al final para que no pase por aca innecesariamente si ya se dio click en cerrar...
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
					mg.validateClick(mousex, mousey, window);
				}
				break;
				}
				
			}
			
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
		if (ev.type == sf::Event::EventType::Closed) {
			MenuAbstract& menu = MenuAbstract::getInstance();
			Manager& mg = Manager::getInstance();
			delete& menu;   //puse delete a ver si se corregia lo de "device not closed"
			delete& mg;
			window.close();
		}

		if (ev.key.code == sf::Keyboard::Key::Escape)
			window.close();

	}
	return 0;
}