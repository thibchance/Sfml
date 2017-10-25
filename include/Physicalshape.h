#ifndef SHAPE_H
#define SHAPE_H

#include  <SFML/Graphics.hpp>

class Rectangle;
class Physicalshape
{
public:
	Physicalshape(double x, double y);
	~Physicalshape();
	
	double x, y;
	
};
class Circle:public Physicalshape
{
public:
	Circle(double x, double y, double radius);
	~Circle();
	bool Circle::isColliding(Rectangle *);
	void draw(sf::RenderWindow& window);
	void move();
	sf::CircleShape shape;
	sf::RectangleShape rect;
	double radius;
	

};

class Rectangle :public Physicalshape
{
public:
	Rectangle(double x, double y, double width, double heigth);
	~Rectangle();
	void draw(sf::RenderWindow& );
	sf::RectangleShape rect;
	double width;
	double heigth;
	double GetX();
	double GetY();

};


#endif
