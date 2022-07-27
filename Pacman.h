#ifndef PACMAN_H
#define PACMAN_H
#include "Point.h"
#include "GameObject.h"

class Pacman : public GameObject
{
private:
	int score = 0;
	int life = 3;
	vector<char> Lives;
	
public:
	// Constractor
	Pacman() : GameObject(pacmanIcon) {}
	Pacman(int x, int y): GameObject(x,y,pacmanIcon) {};
	void initGameObject() override;

	int	getScore() const { return score; };
	void setScore(int x) { score = x; };
	void setPlusScore() { score++; }
	int	getLife() const { return life; };
	void setLife(int newLife) { life = newLife; };
	void remove();
	void changePosition(Board& b, int& countPacmanMoves);
	void moveTunnel(Board& b);
	void moveTunnelPrint(int x, int y);
	bool isTunnel(Board& b, int x, int y, int width, int hight);
	bool isValidMove(Board& b, bool& is_Tunnel);
	void PushLivesToVector();
	char getValueFromLivesVector(int iteration) const;
	void clearLivesVector() { Lives.clear(); }
	void setDirectionFromStepFile(string loadStep);
	void loadModeMove(Board& board);
	void silentMove(Board& board, int& countPacmanMoves);

};

#endif