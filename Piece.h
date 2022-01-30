#pragma once
#include "mygraphics.h"
#include "Board.h"

class Piece
{
public:
	virtual void draw(int x, int y);
	virtual void clear(int x, int y);
	virtual void rotate();
	virtual void moveX(int s);
	virtual void SetX(int x);
	virtual void SetY(int y);
	virtual int getX();
	virtual int GetY();
	virtual void moveY();
	virtual void setRotateEnabled(int x);
	virtual int getPos();
	virtual void CancelMovement();
	virtual int Type();
	virtual int checkBoundary(int i, int j);
	virtual void checkRight(int& i, int& j, Board& b);
	virtual void checkLeft(int& i, int& j, Board& b);
	virtual int checkDown(int& i, int& j, Board& b);
};

