#include "GoodGhost.h"

/* Thsi function change the position of good ghost*/
void::GoodGhost::changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation)
{
	if (countPacmanMoves % 3 == 0)
	{
		int x = this->getBody().getX();
		int y = this->getBody().getY();
		int direction = getDirection();
		if (countPacmanMoves % 20 >= 0 && countPacmanMoves % 20 <= 5)
		{
			if (countPacmanMoves % 20 == 0)
				direction = rand() % 4;

			// If not valid get new random direction
			while (!checkValidMove(x, y, direction, b))
				direction = rand() % 4;
			this->setDirection(direction);
			move();
			pushDirectionToVector(directionToChar());
			// If last ghost position was breadcrumb print breadcrumb
			if (b.getBoardValFromPoint(x, y) == breadCrumb)
			{
				setTextColor(Color::WHITE);
				printBreadCrumbs(x, y);
			}
		}
		else
		{
			Point newPoint = minDistance(PlayerLocation, b);
			Point tmp(-1, -1);
			int x = getBody().getX();
			int y = getBody().getY();
			if (newPoint != tmp)
			{
				changeDirectionByPoint(newPoint);
				move();
				pushDirectionToVector(directionToChar());
				// If last ghost position was breadcrumb print breadcrumb
				if (b.getBoardValFromPoint(x, y) == breadCrumb)
				{
					setTextColor(Color::WHITE);
					printBreadCrumbs(x, y);
				}
			}
		}
	}
	else
		pushDirectionToVector('S');
}