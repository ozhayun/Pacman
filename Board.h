#ifndef BOARD_H
#define BOARD_H
#include <iostream>
#include <string.h>
#include "Utilities.h"
#include "Point.h"

enum sizeEnum { MAX_WIDTH = 80, MAX_HIGHT = 25 };

class Board
{
    bool isStartHightSet = false;
    unsigned char board[MAX_HIGHT][MAX_WIDTH] = {};
    int boardWidth = 0, boardHight = 0; // width and hight start from zero!!!
    int breadCrumbsLeft = 0, ghostCount = 0, boardEndHight = 0;
    Point pacmanStartingPosition;
    Point ghostStartingPositions[4] = {};
    Point infoPosition;

protected:
    bool isPacmanExist = false, isGameInfoExist = false, isValidBoard = true, isGameInfoAtBottom = false;
  
public:
    Board();
	void const printBoard() const;
    void resetBoard();
    void initBoardData(Point& gameInfo, bool isSilentMode);
    void initInfoPosition();
    void resetBoardDataMembers();
    bool checkValidBoard();

    // This function return the value in the board of request place, the x and y that requested are opposite in the board
    unsigned char getBoardValFromPoint(int x, int y)const { return board[y][x]; };
    unsigned char getBoardValFromPoint(Point point)const { return board[point.getY()][point.getX()]; };
    int getBoardWidth() const { return boardWidth; }
    int getBoardHight() const { return boardHight; } // first hight is zero
    int getNumOfGhosts() const { return ghostCount; }
    int getBreadCrumbsLeft() const { return breadCrumbsLeft; }
    bool getIsValidBoard() const { return isValidBoard; }
    const Point & getPacmanStartingPosition() const { return pacmanStartingPosition; }
    Point getGhostStartingPosition(int index) const { return ghostStartingPositions[index]; }
    Point getInfoPosition() const { return infoPosition; }
    bool getIsGameInfoAtBottom() { isGameInfoAtBottom; };

    bool isInGameInfoArea(Point point);

    void eatBreadCrumb() { breadCrumbsLeft--; }
    void setBoardValByPoint(int x, int y) { board[y][x] = boardGarbageVal; }; // Set garabge value
    void setBoardLine(const char* currFileLine);
    void setBoardWidth(int width) { boardWidth = width; };
    void setBoardHight(int boardHight) { boardHight = boardHight; }; // first hight is zero
    void setPacmanExist(bool isExist) { isPacmanExist = isExist; }

    void handleGhost(int boardHight, int x);
    void handlePacman(int boardHight, int x);
    void handleGameInfo(int boardHight, int x);
    void handleBreadCrumb(int boardHight, int x);
};
#endif
