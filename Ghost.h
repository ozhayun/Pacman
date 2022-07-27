#ifndef GHOST_H
#define GHOST_H
#include "Point.h"
#include "GameObject.h"
#include <queue>

struct  QItem {
public:
	int row;
	int col;
	Point p;
	QItem(int x, int y, Point p)
		: row(x), col(y), p(p)
	{}
};

class Ghost : public GameObject
{
protected:
	Point minDistance(Point PlayerLocation, Board& board);

public:
	// Constractor
	Ghost() : GameObject(ghostIcon) {}
	virtual ~Ghost() {}
	Ghost(const Ghost&) = delete;
	Ghost& operator=(const Ghost&) = delete;
	Ghost(int x, int y) : GameObject(x, y, ghostIcon){};
	bool ghostHit(Point Body);
	virtual void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) = 0;
	static void setGhostsDirectionFromStepFile(Ghost** ghosts, int numOfGhosts, string loadStep);
	static void loadModeMove(Board& board, Ghost** ghosts, int numOfGhosts);
};

#endif