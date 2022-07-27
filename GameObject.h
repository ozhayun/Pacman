#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "Point.h"
#include "Board.h"
#include "MoveStrategy.h"

class GameObject
{
protected:
	// GameObject data members
	Point pBody;
	Color color = Color::WHITE;
	char objectIcon;
	int direction = 3;
	vector<char> steps;

public:
	GameObject(char objectIcon) : objectIcon(objectIcon) {}
	// Constractor
	GameObject(int x, int y, char icon) : pBody(x, y), objectIcon(icon) {};

	// GameObject functions
	void setBody(Point point);
	void setBody(int x, int y);
	Point getBody() const {	return pBody;};
	int getDirection() { return direction; }
	void setDirection(int direction);
	Color getColor() const { return color; };
	void setColor(Color color);
	void setObjectIcon(char icon) { objectIcon = icon; }
	char getObjectIcon() { return objectIcon; }

	void move();
	void draw() const;
	virtual void initGameObject();
	static void printBreadCrumbs(int x, int y);
	void changeDirectionByPoint(Point p);
	static bool checkValidPos(int x, int y, Board& b);
	static bool checkValidMove(int x, int y, int dir, Board &b);
	static void IlustrateNextMove(int& x, int& y, int dir);
	void removeObject(Board& b);
	char directionToChar();
	int charToDirection(char charDirection);
	void pushDirectionToVector(char dir);
	//virtual void setDirectionFromStepFile(string loadStep);
	static char getValueFromVector(vector<char>& v,int iteration);
	char getValueFromStepsVector(int iteration) const;
	void clearStepsVector() { steps.clear(); }
	void moveSilent();
};

#endif