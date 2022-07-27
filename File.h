#ifndef FILE_H
#define FIlE_H
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream> 
#include "Utilities.h"
#include "Board.h"

using std::vector;
using std::fstream;
using std::stringstream;
using std::filesystem::directory_iterator;

class File
{
	static bool openFile(string const filePath);
	static void handleFirstLine( size_t& currLineWidth, char& firstLetter, bool& b_validScreen);

public:
	static vector<string> & getScreensName(const string& PATH);
	static bool fileToBoard(Board &board);
	static bool isValidFile(const string& fileName, Board& board);
	static string createStepfileName(const string& fileName);
	static string createResultfileName(const string& fileName);
	static void writeCharToFile(const char& ch);
	static void writeCordinateToFileAsChar(const char& ch);
	static void writeCountMovesToFileAsChar(const int& num);
	static void writeStringToFile(const string& str);
	static void createAndOpenFile(const string& fileName, int fileType);
	static void closeWrittenFile();
	static void closeFile();
	static string readFileToString(const string& fileName, int fileType);
};

#endif
