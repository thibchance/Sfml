#include  <SFML/Graphics.hpp>
#include "Physicalshape.h"
#include <iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	window.setFramerateLimit(60.f);

	
	
	Circle * shape =   new Circle(50, 20,50);
	Rectangle* rect = new Rectangle(200, 200, 100, 100);

	 


		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{

				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::KeyPressed)
				{
					shape->move();
				}
			}
			shape->isColliding(rect);
			
			
			window.clear();
			shape->draw(window);
			rect->draw(window);
			window.display();
		}
		delete shape;
		delete rect;
	return 0;
}