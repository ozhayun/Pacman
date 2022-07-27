#include "Fruit.h"

/* This functio nset fruit new score*/
void Fruit::setNewFruitScore()
{
	char num = randomBetween(53, 57);
	while (num == fruitScore)
	{
		num = randomBetween(53, 57);
	}
	fruitScore = num;
	this->setObjectIcon(fruitScore);
}

/* This function init fruit*/
void Fruit::initFruit(Board& b)
{
	initGameObject();
	setNewFruitlocation(b);
}

/* This function set new fruit location*/
void Fruit::setNewFruitlocation(Board& b)
{
	int newX = randomBetween(0, b.getBoardWidth());
	int newY = randomBetween(0, b.getBoardHight());
	bool valid = checkValidPos(newX, newY, b);

	while (!valid)
	{
		newX = randomBetween(0, b.getBoardWidth());
		newY = randomBetween(0, b.getBoardHight());
		valid = checkValidPos(newX, newY, b);
	}
	setBody(newX, newY);
}

/* This function handle Fruit move*/
void Fruit::changePosition(Board& b, int& countPacmanMoves)
{
	if (countPacmanMoves % 20 == 0)
	{
		this->setShowFruit();
		this->hideOrShowFruit(b);
		if (!this->getshowfruit())
			this->setNewFruitScore();
	}

	if (countPacmanMoves % 4 == 0 && showFruit)
	{
		int x = this->getBody().getX();
		int y = this->getBody().getY();
		int direction = randomBetween(0, 4);

		// If wall get new random direction
		while (!checkValidMove(x, y, direction, b))
			direction = randomBetween(0, 4);

		this->setDirection(direction);
		this->move();
		//Put the current direction in the vector
		pushDirectionToVector(directionToChar());

		// If last ghost position was breadcrumb print breadcrumb
		if (b.getBoardValFromPoint(x, y) == breadCrumb)
			printBreadCrumbs(x, y);
	}

	// Put stay direction in the vector 
	else
		pushDirectionToVector('S');

	//Put true show in the vector
	if (showFruit)
		isShow.push_back('T');
	//Put false show in the vector
	else 
		isShow.push_back('F');

	pushLocationToVector(static_cast<char>(pBody.getX()), static_cast<char>(pBody.getY()));
	pushScoreToVector(fruitScore);
}

/* This function hid or show the fruit on the screen*/
void Fruit::hideOrShowFruit(Board& b)
{
	if (showFruit)
		this->draw();
	else
	{
		unsigned char c = b.getBoardValFromPoint(this->getBody().getX(), this->getBody().getY());
		gotoxy(this->getBody().getX(), this->getBody().getY());
		setTextColor(Color::WHITE);
		if (c == boardGarbageVal || c == cleanGameArea)
			cout << (char)space;
		else
			cout << c;
		setNewFruitlocation(b);
	}
}

/* This function get random between two numbers*/
int Fruit::randomBetween(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}

/* This function push the location of the fruit*/
void Fruit::pushLocationToVector(char first, char second)
{ 
	std::pair<char, char> loc;
	loc.first=first;
	loc.second = second;
	Location.push_back(loc);
}

void Fruit::pushScoreToVector(char score)
{
	FruitScoreVector.push_back(score);
}

/* This function return if the fruit is show in current step count*/
char Fruit::getValueFromisShowVector(int iteration) const
{
	return isShow[iteration];
}

char Fruit::getValueFromScoreVector(int iteration) const
{
	return FruitScoreVector[iteration];
}

/* This function get the value from the location vector*/
std::pair<char, char> Fruit::getValueFromLocationVector(int iteration) const
{
	return Location[iteration];
}

/* This function clear the vectors*/
void Fruit::clearVectors()
{
	steps.clear();
	isShow.clear();
	Location.clear();
	FruitScoreVector.clear();
}

void Fruit::setFromStepFile(string loadStep)
{
	int x, y;
	char Chardirection= loadStep.length() - 1, CharshowFruit = loadStep.length() - 2, CharfruitScore = loadStep.length() - 3;
	x = loadStep[1] - '0';
	if (loadStep[2] != ',')
	{
		x = (x * 10) + loadStep[2] - '0';
		y = loadStep[4] - '0';
		if (loadStep[5] != ')')
		{
			y = (y * 10) + loadStep[5] - '0';
		}
	}
	else
	{
		y = loadStep[3] - '0';
		if (loadStep[4] != ')')
		{
			y = (y * 10) + loadStep[4] - '0';
		}
	}

	direction = charToDirection(Chardirection);

	if (CharshowFruit == 'F')
	{
		showFruit = false;
	}
	else 
		showFruit = true;

	fruitScore = CharfruitScore +'0';

}