#include <SFML/Graphics.hpp>
#include "Game.h"
#include <iostream>
using namespace std;

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 900), "Game of Life");
	window.setFramerateLimit(60);
	Game game(&window);
	cout << "Boje se mijenjaju u odnosu na broj susjeda.";


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		game.draw();
		window.display();
	}

	return 0;
}
