#include "Board.h"

Board::Board()
{
    resetBoard();
}

/* This function print the board
   The first boardHight is zero so we print includ the board hight*/
void const Board::printBoard() const
{  
    setTextColor(Color::WHITE);
    for (int i = 0; i <= boardHight; i++)
    {
        for (int j = 0; j < boardWidth; j++)
        {
            if ((board[i][j] == boardGarbageVal) || (board[i][j] == gameInfoArea) || (board[i][j] == cleanGameArea))
                cout << (char)space;
            else
                cout << board[i][j];
        }
        cout << endl;
    } 
};

/* This function reset the board to the begining*/
void Board::resetBoard()
{
    for (int i = 0; i < MAX_HIGHT; i++)
        for (int j = 0; j < MAX_WIDTH; j++)
                board[i][j] = ' ';
}

/* This function get the line from the board*/
void Board:: setBoardLine(const char* currFileLine)
{

    for (int x = 0; x < boardWidth && isValidBoard; x++)
    {
        // If this point isn't inside game info area
        if (!isInGameInfoArea(Point(x, boardHight)))
        {
            if (currFileLine[x] == space) // BreadCrumb
                handleBreadCrumb(boardHight, x);
            else if (currFileLine[x] == '#') // Wall
                board[boardHight][x] = wall;
            else if (currFileLine[x] == '%') // Clean game area
                board[boardHight][x] = cleanGameArea;
            else if (currFileLine[x] == '$') // Ghost
                handleGhost(boardHight, x);
            else if (currFileLine[x] == '@') // Pacman
                handlePacman(boardHight, x);
            else if (currFileLine[x] == '&') // Game info area
                handleGameInfo(boardHight, x);
            else // Invalid char in the file
                cout << "Invalid char: " << currFileLine[x] << endl;
        }
    } 
    boardHight++;
}

/* This function init the game info area in the board*/
void Board::initInfoPosition() 
{
    int j, x = infoPosition.getX(), y = infoPosition.getY();

    for (int i = y; i < y + 3 && (y + 3 < MAX_HIGHT); i++)
    {
        for (j = x; (j < x + 20) && j < MAX_WIDTH; j++) // game info area
        {
            if (board[i][j] == breadCrumb)
                breadCrumbsLeft--;
            board[i][j] = gameInfoArea;
        }

        for(j; j < boardWidth; j++) // complete the line with clean game area
            board[i][j] = cleanGameArea;

        if (i > boardHight) // if the '&' out of the board from bottom, increase the hight of the board
            boardEndHight = i;
    }
}

/* This function init board data*/
void Board:: initBoardData(Point& gameInfo, bool isSilentMode)
{
    boardHight -= 1; // After the loop of getting the data from the file the hight is increase in one two much
    if (boardEndHight > boardHight)
        boardHight = boardEndHight;
    if (!isSilentMode)
    {
        gameInfo = infoPosition;
        printBoard();
    }
}


/* This function reset board data member after new game*/
void Board::resetBoardDataMembers()
{
    isPacmanExist = isGameInfoExist = false;
    isStartHightSet = false;
    breadCrumbsLeft = ghostCount = boardWidth = boardHight = 0;
    infoPosition = { -1, -1 };
    pacmanStartingPosition = infoPosition = { -1, -1 };
    for(int i = 0; i < ghostCount; i++)
        ghostStartingPositions[i] = { -1, -1 };
}


/* This function handle getting ghost in file*/
void Board::handleGhost(int boardHight, int x)
{
    if (ghostCount <= 4)
    {
        ghostStartingPositions[ghostCount].setX(x);
        ghostStartingPositions[ghostCount].setY(boardHight);
        ghostCount++;
        handleBreadCrumb(boardHight, x);
    }
    else
    {
        isValidBoard = false;
        cout << "Too many ghosts in the board" << endl;
    }
}

/* This function handle getting pacman in file*/
void Board::handlePacman(int boardHight, int x)
{
    if (!isPacmanExist) // take only first appear of pacman in board  
    {
        isPacmanExist = true;
        pacmanStartingPosition = { x, boardHight };
        handleBreadCrumb(boardHight, x);
    }
    else // More than one apear of '@' in the file
    {
    isValidBoard = false;
    cout << "Too many pacmans in the board" << endl;
    }
}


/* This function handle getting game info in file - & 
   The area that defined to the game info area is 20*3 */
void Board::handleGameInfo(int boardHight, int x)
{
    // Handle the case there is more than & in the file
    if (!isGameInfoExist)
    {
        
        // Valid that there is enough place in the board
        if ((boardHight + 3 < MAX_HIGHT) && (x + 20 < MAX_WIDTH))
        {
            // If this is the first line the board width may be change
            if (boardHight == 0)
                if (x + 20 > boardWidth)
                    boardWidth = x + 20;

            isGameInfoExist = true;
            infoPosition = { x, boardHight };
            initInfoPosition();
        }
        else
        {
            cout << "There isn't enough place in the board for the game info area." << endl;
            isValidBoard = false;
        }
    }
    else // More than one apear of '&' in the file
    {
        cout << "There are more than one apear of '&' in the file." << endl;
        isValidBoard = false;
    }
}


/* This function check if this is the game info area*/
bool Board:: isInGameInfoArea(Point point)
{
    if (getBoardValFromPoint(point) == gameInfoArea)
        return true;
    return false;
}


/* This function add bread crumb to the game and count it*/
void Board::handleBreadCrumb(int boardHight, int x)
{
    board[boardHight][x] = breadCrumb;
    breadCrumbsLeft++;
}


/* This function check that the board include the must have game object- pacman and game info*/
bool Board::checkValidBoard()
{
    if (!isPacmanExist)
        cout << "Pacman isn't exist in file."<<endl;
    if (!isGameInfoExist)
        cout << "Game info isn't exist in file." << endl;
    return isGameInfoExist && isPacmanExist;
}
