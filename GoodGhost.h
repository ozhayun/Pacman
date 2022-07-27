#pragma once
#include "Ghost.h"

class GoodGhost : public Ghost
{
public:
	GoodGhost() {};
	~GoodGhost() override {}
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override; 
};

