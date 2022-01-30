#pragma once
#include "Block.h"
#include "Piece.h"
#include "Board.h"

#define Boundary1 2
#define Boundary2 13
#define Boundary3 16

class Shape_2:public Piece
{
	const int colors[3] = { 0,0,240 };
	const int height = 100;
	const int width = 30;
	Block b[4];
	bool rotate_enabled;
	bool allow_move;
	int counter_x;
	int counter_y;
	int x;
	int y;			 
	int position;

public:
	Shape_2();
	void draw(int x, int y);
	void clear(int x, int y);
	void rotate();
	void moveX(int s);
	void SetX(int x);
	void SetY(int y);
	int getX();
	int GetY();
	void moveY();
	void setRotateEnabled(int x);
	int getPos();
	void CancelMovement();
	int Type();
	int checkBoundary(int i, int j);
	void checkRight(int& i, int& j, Board& b);
	void checkLeft(int& i, int& j, Board& b);
	int checkDown(int& i, int& j, Board& b);
};

