#include  <SFML/Graphics.hpp>
#include "Physicalshape.h"
#include <iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
	window.setFramerateLimit(60.f);

	
	
	Circle * shape =   new Circle(50, 20,50);
	Rectangle* rect = new Rectangle(200, 200, 100, 100);
	shape->shape.setFillColor(sf::Color::Green);
	rect->rect.setFillColor(sf::Color::Blue);

	


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
			if (shape->isColliding(rect))
			{
				shape->shape.setFillColor(sf::Color::Red);
				rect->rect.setFillColor(sf::Color::Red);
			}
			else
			{
				shape->shape.setFillColor(sf::Color::Green);
				rect->rect.setFillColor(sf::Color::Blue);
				std::cout << "test";
			}
			
			
			window.clear();
			shape->draw(window);
			rect->draw(window);
			window.display();
		}
		delete shape;
		delete rect;
	return 0;
}