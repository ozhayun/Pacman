#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Menu.h"
#include "Board.h"
#include "Pacman.h"
#include "Ghost.h"
#include "Point.h"
#include "Print.h"
#include "File.h"
#include <string>
#include <stdio.h>
#include "Fruit.h"
#include "NoviceGhost.h"
#include "GoodGhost.h"
#include "BestGhost.h"

class Game
{
private:
	string currScreenGame;
	vector<string> screensNames = File::getScreensName(screenPath);
	Ghost* ghosts[4]{};
	Pacman player;
	Fruit fruit;
	Board board;
	Menu menu;
	Print print;
	Point gameInfo;
	bool b_IsColorGame = true, singleGame = false, continueGame = true;
	int gameSpeedVal = mediumGameSpeed, numOfGhosts; //GhostsLevel = GhostsLevel::Hard;
	GhostsLevel GhostsLevel = GhostsLevel::Hard;
	int countMoves = 0;
	
public:
	// Game functions
	void playGame(bool isSingleGame, string screenName, bool isSaveMode, bool isLoadMode, bool isSilentMode);
	void playSingleGame(string screenName);
	void playByMode(string screenName, bool isSaveMode, bool isLoadMode, bool isSilentMode);
	void playGameStep(bool isSaveMode);
	void initGame(bool b_color, bool isSilentGame);
	void gameSettings();
	void gameSpeed();
	void initGameObj();
	void printPreviousGame()const;
	bool checkWin()const;
	void drawGameObj()const;
	void resetGame();
	void chooseColor();
	string choseScreen();
	void gameGhostsLevel();
	void writeStepsToFile(const string& screenName);
	void writeDeathToResultFile();
	void writeWinToResultFile();
	void writeResultData();
	void resetVectors();

	// Save functions
	void playSaveSingleGame(string screenName);
	void checkAndSaveGhostsHit(Point pacmanBody);

	// Load functions
	void playLoadSingleGame(string screenName);
	string splitObjectStepsByDel(string currGameStep, string objectDelimeter, int& start, int& end);
	void playLoadSilentGame(string screenName);
	void LoadDataFromLine(int& x, int& y, int startindex, string& LineData);
	int LoadNumberFromLine(string& LineData, int index);
	void LoadsilentModeDataParameters(Point& resultPlayerloaction, char& W_or_D, int& MovesNumber, string& resultline, string objectDelimeter);
	void LoadModeDataParameters(int numOfGhost,string& currGameStep,string& objectDelimeter);

	// Silent functions
	void GhostsSilentModeMove();


	// TODO: Delete next 4 function
	bool getIsColorGame() const { return b_IsColorGame; };
	int getGameSpeedVal() const { return gameSpeedVal; }

	void setIsColorGame(bool boolean) { b_IsColorGame = boolean; }
	void setGameSpeed(int gameSpeed) { gameSpeedVal = gameSpeed; }
	void setGameObjectsPositions();
	void setGameObjectsColors();

	// Ghosts functions
	void initGameAfterGhostHit();
	bool ghostsHit(Point pacmanBody);
	bool checkGhostsHit(Point pacmanBody, bool isSilent);
	void removeGhosts();	
	void ghostsMove(Point PlayerLocation);
	bool checkGhostsCollision(Ghost& g1, Ghost& g2);

	// Pacman functions
	void pacmanMove(Board& b);
	void getUserKeyboard();
	
	// Fruit functions
	void checkPacmanHitFruit();

	// Print function
	void winGame();
	void gameOver();
	void pauseGame();
	void exitGame();
};

#endif