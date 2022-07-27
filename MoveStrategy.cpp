//#include "MoveStrategy.h"
//
//
/////* This function ilustrate the next move*/
//void MoveStrategy::IlustrateNextMove(int& x, int& y, int dir, Board& b)
//{
//	switch (dir)
//	{
//	case 0: // LEFT
//		x--;
//		break;
//	case 1: // RIGHT
//		x++;
//		break;
//	case 2: // UP
//		y--;
//		break;
//	case 3: // DOWN
//		y++;
//		break;
//	}
//
//}
//
/////* This function check if next move is valid */
//bool MoveStrategy::checkValidMove(int x, int y, int dir, Board& b)
//{
//	IlustrateNextMove(x, y, dir, b);
//	unsigned char charAtNextPoint = b.getBoardValFromPoint(x, y);
//
//	// If the ghost out of board
//	if ((x == 69) || (x == 0) || (y == 0) || (y == 19))
//		return false;
//
//	// If the next move is wall, tunnel or ghost this isn't valid move
//	if ((charAtNextPoint == w) || (charAtNextPoint == space) || (charAtNextPoint == ghostIcon))
//		return false;
//
//	return true;
//}
//
//bool MoveStrategy::checkValidPos(int x, int y, Board& b)
//{
//	unsigned char charAtPoint = b.getBoardValFromPoint(x, y);
//	if ((x == 69) || (x == 0) || (y == 0) || (y == 19))
//		return false;
//
//	// If wall, tunnel or ghost this isn't valid move
//	if ((charAtPoint == w) || (charAtPoint == space) || (charAtPoint == ghostIcon) || ((charAtPoint >= 53) && (charAtPoint <= 57)))
//		return false;
//
//	return true;
//
//}
//
//
//Point MoveStrategy::minDistance(Point GhostLocation, Point PlayerLocation, Board &board)
//{
//	Point Pcurr(0, 0);
//	QItem source(PlayerLocation.getX(), PlayerLocation.getY(), Pcurr);
//
//	// To keep track of visited QItems. Marking
//	// blocked cells as visited.
//	bool visited[HIGHT][WIDTH] = { false };
//
//	// init source
//	source.row = PlayerLocation.getX();
//	source.col = PlayerLocation.getY();
//
//	// applying BFS on matrix cells starting from source
//	std::queue<QItem> q;
//	q.push(source);
//	visited[source.row][source.col] = true;
//	while (!q.empty())
//	{
//		QItem curr = q.front();
//		q.pop();
//
//		// Destination found;
//		if (GhostLocation.getX() == curr.row && GhostLocation.getY() == curr.col)
//		{
//			return curr.p;
//		}
//
//		Pcurr.setX(curr.row);
//		Pcurr.setY(curr.col);
//
//
//		// moving up
//		if (curr.row - 1 >= 0 && checkValidPos(curr.row - 1, curr.col, board) && visited[curr.row - 1][curr.col] == false)
//		{
//			q.push(QItem(curr.row - 1, curr.col, Pcurr));
//			visited[curr.row - 1][curr.col] = true;
//		}
//		// moving down
//		if (curr.row + 1 < HIGHT && checkValidPos(curr.row + 1, curr.col, board) && visited[curr.row + 1][curr.col] == false)
//		{
//			q.push(QItem(curr.row + 1, curr.col, Pcurr));
//			visited[curr.row + 1][curr.col] = true;
//		}
//		// moving left
//		if (curr.col - 1 >= 0 && checkValidPos(curr.row, curr.col - 1, board) && visited[curr.row][curr.col - 1] == false)
//		{
//			q.push(QItem(curr.row, curr.col - 1, Pcurr));
//			visited[curr.row][curr.col - 1] = true;
//		}
//		// moving right
//		if (curr.col + 1 < WIDTH && checkValidMove(curr.row, curr.col, Right, board) && visited[curr.row][curr.col + 1] == false)
//		{
//			q.push(QItem(curr.row, curr.col + 1, Pcurr));
//			visited[curr.row][curr.col + 1] = true;
//		}
//	}
//	Point p1(-1, -1);
//	return p1;
//}
//
////void MoveStrategy::changePosition(Board& b)
////{
////	int x = this->getBody().getX();
////	int y = this->getBody().getY();
////	int direction = rand() % 4;
////
////	// If wall get new random direction
////	while (!checkValidMove(x, y, direction, b))
////		direction = rand() % 4;
////
////	this->setDirection(direction);
////	this->moveAndDraw();
////
////	// If last ghost position was breadcrumb print breadcrumb
////	if (b.getBoardValFromPoint(x, y) == bc)
////		printBreadCrumbs(x, y);
////}
