#pragma once
#include "mygraphics.h"

//class for one single block
class Block
{
	const int size = 20;
	int x;
	int y;

public:
	int color[3] = { 0,0,0 };
	Block();
	void draw(int x, int y, int r, int g, int b, int R, int G, int B);
	void SetX(int x);
	void SetY(int y);
	void SetColor(int r, int g, int b);
	void ArrayDraw(int i, int j);
	int GetX();
	int GetY();
	~Block();
};

