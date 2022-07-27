#include "Ghost.h"


/* This function handle ghost hit*/
bool Ghost::ghostHit(Point Body)
{
	if (this->getBody() == Body)
		return true;
	return false;
}

/* This function chase after pacman*/
Point Ghost::minDistance(Point PlayerLocation, Board& board)
{
	{
		Point Pcurr(0, 0);
		QItem source(PlayerLocation.getX(), PlayerLocation.getY(), Pcurr);
		int Hight = board.getBoardHight();
		int Width = board.getBoardWidth();

		// To keep track of visited QItems. Marking
		// blocked cells as visited.
		bool visited[MAX_HIGHT][MAX_WIDTH] = { false };
		// init source
		source.row = PlayerLocation.getX();
		source.col = PlayerLocation.getY();

		// applying BFS on matrix cells starting from source
		std::queue<QItem> q;
		q.push(source);
		visited[source.col][source.row] = true;
		while (!q.empty())
		{
			QItem curr = q.front();
			q.pop();

			// Destination found;
			if (this->getBody().getX() == curr.row && this->getBody().getY() == curr.col)
				return curr.p;

			Pcurr.setX(curr.row);
			Pcurr.setY(curr.col);

			// moving right
			if (curr.row + 1 < Width && checkValidPos(curr.row + 1, curr.col, board) && visited[curr.col][curr.row + 1] == false)
			{
				q.push(QItem(curr.row + 1, curr.col, Pcurr));
				visited[curr.col][curr.row + 1] = true;
			}
			// moving down
			if (curr.col + 1 < Hight && checkValidPos(curr.row, curr.col + 1, board) && visited[curr.col + 1][curr.row] == false)
			{
				q.push(QItem(curr.row, curr.col + 1, Pcurr));
				visited[curr.col + 1][curr.row] = true;
			}

			// moving left
			if (curr.row - 1 >= 0 && checkValidPos(curr.row - 1, curr.col, board) && visited[curr.col][curr.row - 1] == false)
			{
				q.push(QItem(curr.row - 1, curr.col, Pcurr));
				visited[curr.col][curr.row - 1] = true;
			}

			// moving up
			if (curr.col - 1 >= 0 && checkValidPos(curr.row, curr.col - 1, board) && visited[curr.col - 1][curr.row] == false)
			{
				q.push(QItem(curr.row, curr.col - 1, Pcurr));
				visited[curr.col - 1][curr.row] = true;
			}
		}
		Point p1(-1, -1);
		return p1;
	}
}

/* This function handle the move of ghost*/
void Ghost::loadModeMove(Board &board, Ghost** ghosts, int numOfGhosts)
{
	int x, y;
	for (int i = 0; i < numOfGhosts; i++)
	{
		// Save last position
		x = ghosts[i]->getBody().getX();
		y = ghosts[i]->getBody().getY();

		// Move if the direction isn't stay
		if ((ghosts[i]->direction != 4) && (ghosts[i]->checkValidMove(x, y, ghosts[i]->direction, board)))
		{
			ghosts[i]->move();
			// If last position was breadcrumb print it
			if (board.getBoardValFromPoint(x, y) == breadCrumb)
			{
				setTextColor(Color::WHITE);
				printBreadCrumbs(x, y);
			}
		}
	}
}

/* This function change the direction of ghosts from steps file*/
void Ghost:: setGhostsDirectionFromStepFile(Ghost** ghosts, int numOfGhosts, string loadStep)
{
	for (int i = 0; i < numOfGhosts; i++)
		ghosts[i]->direction = ghosts[i]->charToDirection(loadStep[i]);
}
