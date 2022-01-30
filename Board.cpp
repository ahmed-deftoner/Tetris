#include "Board.h"

void Board::draw() {
	int countx = 80;
	int county = 20;
	for (int i = 0; i < 20; ++i) {
		countx = 80;
		for (int j = 0; j < 16; ++j) {
			if (i == 0 || i==19) {
				b[i][j].draw(countx, county, 0, 0, 0, 22, 25, 22);
				countx += 20;
			}
			else if (j == 0 || j == 15) {
				b[i][j].draw(countx, county, 0, 0, 0, 22, 15, 22);
				countx += 20;
			}
			else  {
				b[i][j].draw(countx, county, 0, 0, 0, 0, 0, 0);
				countx += 20;
			}
		}
		county += 20;
	}							
}

void Board::matrix() {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 16; ++j) {
			cout << BoardMatrix[i][j] << " ";
		}
		cout << endl;
	}
}

int Board::check_1(int x, int y) {
	if (BoardMatrix[x][y] == 1)
		return -1;
	return 0;
}

void Board::setMatrix(int x, int y) {
	BoardMatrix[x][y] = 1;
}

void Board::resetMatrix(int x, int y) {
	BoardMatrix[x][y] = 0;
}