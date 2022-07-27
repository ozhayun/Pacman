#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Utilities.h"
#include <stdlib.h>

using std::cout;

enum directions
{
	Left = 0, Right = 1, Up = 2, Down = 3, Stay = 4
};

class Point
{
private:
	int x = -1, y = -1;

public:
	//constractor
	Point() = default;
	Point(int newX, int newY) : x(newX), y(newY) {};

	void draw(char ch) const;
	void move(int direction);
	void setX(int newX) { x = newX; }
	int	getX() const;
	void setY(int newY) { y = newY; }
	int	getY() const;
	friend bool operator== (const Point& pointOne, const Point& pointTwo);
	friend bool operator!= (const Point& pointOne, const Point& pointTwo);
	Point& operator= (const Point& point);
	
};

#endif