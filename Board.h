#pragma once
#include "Block.h"
#include <iostream>
using namespace std;

class Board
{
	const int height = 18;
	const int width = 6;
	Block b[20][16];
	//board checker
	int BoardMatrix[20][16] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
						        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
								{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},	 
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		                        {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
							   {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

public:
	void draw();
	void matrix();
	int check_1(int x, int y);
	void setMatrix(int x, int y);
	void resetMatrix(int x, int y);
};
