#include "BestGhost.h"

/* Thsi function change the position of best ghost*/
void::BestGhost::changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation)
{
	if (countPacmanMoves % 3 == 0)
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
	else
		pushDirectionToVector('S');
}
