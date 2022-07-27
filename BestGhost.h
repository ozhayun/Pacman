#pragma once
#include "Ghost.h"


class BestGhost :public Ghost
{
public:
	BestGhost() {};
	 ~BestGhost() override {}
	void changePosition(Board& b, int& countPacmanMoves, Point PlayerLocation) override;
};


