#pragma once
#include "Piece.h"
#include "Board.h"
#include "Block.h"

#define	Boundary1 13
#define Boundary2 17


/*POS 1	    POS 2 
 (ij)B		(ij)B B B
     B
	 B 
*/
class Shape_1:public Piece
{
	const int colors[3] = { 0,240,255 };
	const int height = 100;
	const int width = 30;
	Block b[3];
	//bool BlockShow[3] = { true,true,true };
	int BlockY[3] = { 0,0,0 };
	bool rotate_enabled;
	bool allow_move;
	int counter_x;
	int counter_y;
	int x;
	int y;			 
	int position;

public:
	bool BlockShow[3];
	Shape_1();
	void draw(int x,int y);
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
	void checkRight(int &i, int &j,Board &b);
	void checkLeft(int &i, int &j,Board &b);
	int checkDown(int& i, int& j, Board &b);
	void checkLine(int y);
	void blocky();
};

