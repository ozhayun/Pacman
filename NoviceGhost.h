#pragma once
#include "Ghost.h"

class NoviceGhost :public Ghost
{
public:
	NoviceGhost() {};
	~NoviceGhost() override {}
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override;
};

