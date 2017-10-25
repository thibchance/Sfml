#include "Physicalshape.h"
#include <math.h>
#include <iostream>

Physicalshape::Physicalshape(double x, double y) : x(x), y(y)
{
}

Physicalshape::~Physicalshape()
{
}





Circle::Circle(double x, double y, double radius) : Physicalshape(x, y), radius(radius)
{
	shape = sf::CircleShape(radius);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(50, 20);

}

   Circle::~Circle()
{

}



bool Circle::isColliding(Rectangle * rectangle)
{
	std::cout << "is colling test\n";
	int deltaX = x - fmax(rectangle->GetX(), fmin(x, rectangle->GetX() + rectangle->width));
	int deltaY = y - fmax(rectangle->GetY(), fmin(y, rectangle->GetY() + rectangle->heigth));

	std::cout << "radius = " << radius << ",x " << x << ", y " << y << "\n";

	return (deltaX*deltaX + deltaY*deltaY) < pow(radius, 2);
}

void Circle::draw(sf::RenderWindow & window)
{
	window.draw(shape);
	
	
}

void Circle::move()
{
	sf::Vector2f delta_move;
	float speed = 5.0f;
	//manage input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		delta_move.x -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		delta_move.x += 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		delta_move.y -= 1.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		delta_move.y += 1.0f;
	}


	shape.setPosition(shape.getPosition() + speed*delta_move);
	x = shape.getPosition().x;
	y = shape.getPosition().y;
}

Rectangle::Rectangle(double x, double y, double width, double heigth) :Physicalshape(x, y), width(width), heigth(heigth)
{
	rect = sf::RectangleShape (sf::Vector2f(width, heigth));
	rect.setFillColor(sf::Color::Blue);
	rect.setPosition(200, 200);
}

Rectangle::~Rectangle()
{
}

void Rectangle::draw(sf::RenderWindow & window)
{
	window.draw(rect);
}

double Rectangle::GetX()
{
	return y;
}

double Rectangle::GetY()
{
	return y;
}
