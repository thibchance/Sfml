#include "Physicalshape.h"
#include <math.h>

Physicalshape::Physicalshape(double x, double y)
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
	double dx = std::abs(this->x - rectangle->x);
	double dy = std::abs(rectangle->y - this->y);
	float cornerDistance;
	
	if (dx > (this->radius  + rectangle->width/2))shape.setFillColor(sf::Color::Green); return false;
	if (dy > (this->radius  + rectangle->heigth/2))rect.setFillColor(sf::Color::Blue); return false;

	if (dx <= (rectangle->width / 2))
	{
		shape.setFillColor(sf::Color::Red); return true;
}
	if (dy <= (rectangle->heigth / 2)) rect.setFillColor(sf::Color::Red); return true;

	cornerDistance = pow(dx - rectangle->width / 2.0f, 2.0f) +
		pow(dy - rectangle->heigth / 2.0f, 2.0f);

	return(cornerDistance <= pow(this->radius, 2.0f));
	
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
