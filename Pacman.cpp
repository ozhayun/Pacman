#include "Pacman.h"

/* this function init pacman*/
void Pacman::initGameObject()
{
	this->setColor(Color::WHITE);
	this->setDirection(Stay);
}

/* this function check if the next move is valid*/
bool Pacman::isValidMove(Board& b, bool& is_Tunnel)
{
	Point nextPos = this->getBody(); // current location
	nextPos.move(this->getDirection()); // next location
	unsigned char charAtnextPoint = b.getBoardValFromPoint(nextPos.getX(), nextPos.getY());
	int x = nextPos.getX(), y = nextPos.getY(), width = b.getBoardWidth(), hight = b.getBoardHight();

	if ((charAtnextPoint == breadCrumb) || (charAtnextPoint == boardGarbageVal) || (charAtnextPoint == cleanGameArea))
		return true;

	if (y <= -1 || y >= hight || x <= -1 || x >= width || charAtnextPoint == space)
	{
		if (isTunnel(b, x, y, width, hight))
		{
			is_Tunnel = true;
			return true;
		}
		else
			return false;
	}

	
	// if next move is wall or game info area return false
	else if ((charAtnextPoint == wall) || (charAtnextPoint == gameInfoArea))
		return false;
		
	return true;
}

/* This function move the pacman*/
void Pacman::changePosition(Board& b, int& countPacmanMoves)
{
	bool is_Tunnel = false;
	int x = this->getBody().getX();
	int y = this->getBody().getY();
	
	unsigned char currentLocationVal = b.getBoardValFromPoint(x, y);

	if (currentLocationVal == breadCrumb)
	{
		score++;
		b.eatBreadCrumb();
		b.setBoardValByPoint(x, y); 
	}
	
	if (isValidMove(b, is_Tunnel))
	{
		if (is_Tunnel)
			moveTunnel(b);
		else
			move();

		pushDirectionToVector(directionToChar());
	}
	else
		pushDirectionToVector('S');
	
	PushLivesToVector();
	countPacmanMoves++;
}

/* This function remove pacman last character*/
void Pacman::remove()
{
	gotoxy(this->getBody().getX(), this->getBody().getY());
	cout << (char)space;
}

/* This function check if the next location is a tunnel*/
//bool Pacman::isTunnel(Board& b, int x, int y, int width, int hight, int startBoardXMinusOne, int startBoardYMinusOne)
bool Pacman::isTunnel(Board& b, int x, int y, int width, int hight)
{
	// if top tunnel
	if (y == - 1) // check if there tunnel in bottom
		if (b.getBoardValFromPoint(x, hight) != wall && b.getBoardValFromPoint(x, hight) != gameInfoArea)
			return true;
	if (y == hight + 1)
		if (b.getBoardValFromPoint(x, 0) != wall && b.getBoardValFromPoint(x, 0) != gameInfoArea)
			return true;
	if (x == -1)
		if (b.getBoardValFromPoint(width - 1, y) != wall && b.getBoardValFromPoint(width - 1, y) != gameInfoArea)
			return true;
	if (x == width)
		if (b.getBoardValFromPoint(0, y) != wall && b.getBoardValFromPoint(0, y) != gameInfoArea)
			return true;
	return false;
}

/* This function getting the correct x and y of the pacman for getting into tunnel*/
void Pacman::moveTunnel(Board& b)
{
	int highest = 0;
	int Lowest = b.getBoardHight();
	int mostLeft = 0;
	int mostRight = b.getBoardWidth() - 1;

	if (mostLeft == getBody().getX())
		moveTunnelPrint(mostRight, getBody().getY());

	else if (mostRight == getBody().getX())
		moveTunnelPrint(mostLeft, getBody().getY());

	else if (highest == getBody().getY())
		moveTunnelPrint(getBody().getX(), Lowest);
		
	else if (Lowest == getBody().getY())
		moveTunnelPrint(getBody().getX(), highest);
}

/* This function print the pacman in the next tunnel location*/
void Pacman::moveTunnelPrint(int x, int y)
{
	remove();
	setBody(x, y);
	draw();
}

/* This function push pacman lives to vector*/
void Pacman::PushLivesToVector()
{
	Lives.push_back(life);
}

/* This function return the value from the steps vector*/
char Pacman::getValueFromLivesVector(int iteration) const
{
	return Lives[iteration];
}

/* This function fake the pacman move in load mode*/
void Pacman::setDirectionFromStepFile(string loadStep)
{
	direction = charToDirection(loadStep[0]);
}


void Pacman::loadModeMove(Board& board)
{
	bool is_Tunnel = false;
	int x = this->getBody().getX();
	int y = this->getBody().getY();

	unsigned char currentLocationVal = board.getBoardValFromPoint(x, y);

	if (currentLocationVal == breadCrumb)
	{
		score++;
		board.eatBreadCrumb();
		board.setBoardValByPoint(x, y);
	}

	if (isValidMove(board, is_Tunnel))
	{
		if (is_Tunnel)
			moveTunnel(board);
		else
			move();
	}
}

void Pacman::silentMove(Board& board, int& countPacmanMoves)
{
	bool is_Tunnel = false;
	int x = this->getBody().getX();
	int y = this->getBody().getY();

	unsigned char currentLocationVal = board.getBoardValFromPoint(x, y);

	if (currentLocationVal == breadCrumb)
	{
		score++;
		board.eatBreadCrumb();
		board.setBoardValByPoint(x, y);
	}

	if (isValidMove(board, is_Tunnel))
	{
		if (is_Tunnel)
			moveTunnel(board);
		else
			pBody.move(direction);
	}
	countPacmanMoves++;
}