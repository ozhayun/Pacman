#include "Point.h"

/* This function draw requested char in point*/
void Point::draw(char ch)  const {
	gotoxy(x, y);
	cout << ch;
}

/* This function change x or y by requested direction*/
void Point::move(int dir) {
	switch (dir) {
	case Left: // LEFT
		--x;

		break;
	case Right: // RIGHT
		++x;

		break;
	case Up: // UP
		--y;

		break;
	case Down: // DOWN
		++y;
		break;
	case Stay: //Nothing

		break;
	}
}

/* This function get the x of point*/
int Point::getX ()  const
{
	return x;
}

/* This function get the y of point*/
int Point::getY()  const
{
	return y;
}

/* This freind function overloading == opeartor for point*/
bool operator== (const Point& pointOne, const Point& pointTwo)
{
	return ((pointOne.getX() == pointTwo.getX()) && (pointOne.getY() == pointTwo.getY()));
}

/* This freind function overloading != opeartor for point*/
bool operator!= (const Point& pointOne, const Point& pointTwo)
{
	return !(pointOne == pointTwo);
}

/* This freind function overloading = opeartor for point*/
Point& Point:: operator= (const Point& point)
{
	this->setX(point.getX());
	this->setY(point.getY());
	return *this;
}