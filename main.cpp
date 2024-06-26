#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

#include "MenuAbstract.h"
#include "FileLevel.h"
#include "Manager.h"
#include "SoundManager.h"

int main()
{
	FileLevels arc;
	Levels reg;
	//for (int i = 0; i < 5; i++) {   //ESTO YA SE HIZO! NO SE REPITE
	//	reg.Cargar(i);
	//	arc.save(reg);
	//	//system("pause");
	//}
	//MUESTRO COMO ESTA ACTUALMENTE EL ARCHIVO:
	for (int i = 0; i < 5; i++) {
		reg = arc.read(i);
		reg.Mostrar();
	}

	sf::RenderWindow window(sf::VideoMode(960, 640), "Programmers Vs Hackers");
	window.setFramerateLimit(60);
	sf::Image icon;
	if (!icon.loadFromFile("img/complementarias/logo.png")) {
		throw std::runtime_error("Error al cargar logo miniatura");
	}
	// Establecer el icono de la ventana
	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	int view = 1;
	sf::Vector2i mousePosition; //xq no es 2f? si despues lo terminamos pasando a 2f siempre...
	while (window.isOpen())
	{
		SoundManager& soundManager = SoundManager::getInstance();
		mousePosition = sf::Mouse::getPosition(window);

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
					mg.validateClick(mousex, mousey, window, view);
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
				MenuAbstract& menu = MenuAbstract::getInstance();
				menu.update(mousePosition);
				window.draw(menu);
			}
			break;
			case 2:
			{
				Manager& mg = Manager::getInstance();
				mg.update(mousePosition, view);
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