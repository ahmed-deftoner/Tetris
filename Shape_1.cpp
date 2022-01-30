#include "Shape_1.h"

Shape_1::Shape_1() {
	rotate_enabled = true;
	allow_move = true;
	position = 1;
	counter_x = 0;
	counter_y = 0;
	x = 0;
	y = 0;
}

void Shape_1::draw(int x,int y) {
	this->x = x;
	this->y = y;
	if (position == 1 || position == 3) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x, y+40, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 2 || position == 4) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x+20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x+40, y, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
}

void Shape_1::clear(int x, int y) {
	if (position == 1 || position == 3) {
		b[0].draw(x, y, 0, 0, 0, 0,0,0);
		b[1].draw(x, y + 20, 0, 0, 0, 0,0,0);
		b[2].draw(x, y + 40, 0, 0, 0, 0,0,0);
	}
	else if (position == 2 || position == 4) {
		b[0].draw(x, y, 0, 0, 0, 0, 0, 0);
		b[1].draw(x+20, y, 0, 0, 0, 0, 0, 0);
		b[2].draw(x+40, y, 0, 0, 0, 0, 0, 0);
	}
}

void Shape_1::SetX(int x) {
	this->x = x;
}

void Shape_1::SetY(int y) {
	this->y = y;
}

int Shape_1::getX() {
	return x;
}

int Shape_1::GetY() {
	return y;
}

void Shape_1::rotate(){
	if (rotate_enabled == true) {
		if (position == 1 || position == 3)
			Shape_1::clear(x, y);
		else if (position == 2 || position == 4)
			Shape_1::clear(x, y);
		if (position < 4) {
			position++;
		}
		else
			position = 1;
	}
}

void Shape_1::moveX(int s) {
	if (allow_move == true) {
		if (s == 1) {
			counter_x = 20;
			if (position == 1 || position == 3) {
				Shape_1::draw(x + counter_x, y);
				Shape_1::clear(x - 20, y);
			}
			else if (position == 2 || position == 4) {
				Shape_1::draw(x + counter_x, y);
				Shape_1::clear(x - 20, y);
			}
		}
		else {
			counter_x = -20;
			if (position == 1 || position == 3) {
				Shape_1::draw(x + counter_x, y);
				Shape_1::clear(x + 20, y);
			}
			else if (position == 2 || position == 4) {
				Shape_1::draw(x + counter_x, y);
				Shape_1::clear(x + 20, y);
			}
		}
	}
}

void Shape_1::setRotateEnabled(int x) {
	if (x == 0)
		rotate_enabled = false;
	else
	    rotate_enabled = true;
}

void Shape_1::moveY() {
	if (allow_move == true) {
		counter_y = 20;
		if (position == 1 || position == 3) {
			Shape_1::draw(x, y + counter_y);
			Shape_1::clear(x, y - 20);
		}
		else if (position == 2 || position == 4) {
			Shape_1::draw(x, y + counter_y);
			Shape_1::clear(x, y - 20);
		}
	}
}

int Shape_1::getPos() {
	return position;
}

void Shape_1::CancelMovement() {
	allow_move = false;
}

int Shape_1::Type() {
	return 1;
}

int Shape_1::checkBoundary(int i, int j) {
	int x=Shape_1::getPos();
	if (i >= Boundary2)
		return 1;
	else if (j >= Boundary1)
		return 1;
	return 0;
}

void Shape_1::checkRight(int &i, int &j,Board &b) {
	int pos = Shape_1::getPos();
	if (pos == 1 || pos == 3) {
		int c = b.check_1(i, j + 1);
		if (c == 0 && j < 16) {
			Shape_1::moveX(1);
			++j;
		}
	}
	else if (pos == 2 || pos == 4) {
		int c = b.check_1(i, j + 3);
		if (c == 0 && j < 16) {
			Shape_1::moveX(1);
			++j;
		}
	}
}

void Shape_1::checkLeft(int &i, int &j,Board &b) {
	int c = b.check_1(i, j - 1);
	if (c == 0 && j > 0) {
		Shape_1::moveX(-1);
		--j;
	}
}

int Shape_1::checkDown(int& i, int& j, Board& b) {
	int pos = Shape_1::getPos();
	if (pos == 1 || pos == 3) {
		int c = b.check_1(i + 3, j);
		if (c == 0) {
			Shape_1::moveY();
			i++;
		}
		if (b.check_1(i + 3, j) == -1) {
			for (int k = i; k < i + 3; ++k)
				b.setMatrix(k, j);
			Shape_1::CancelMovement();
			Shape_1::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 2 || pos == 4) {
		int c = b.check_1(i + 1, j);
		int b1 = b.check_1(i + 1, j + 1);
		int b2 = b.check_1(i + 1, j + 2);
		if (c == 0 && b1==0 && b2==0) {
			Shape_1::moveY();
			i++;
		}
		if (c == -1 || b1==-1 || b2==-1) {
			for (int k = j; k < j + 3; ++k)
				b.setMatrix(i, k);
			Shape_1::CancelMovement();
			Shape_1::setRotateEnabled(0);
			return 1;
		}
	}
	return 0;
}

void Shape_1::checkLine(int y) {
	int x=Shape_1::getPos();
	for (int i = 0; i < 3; ++i) {
		if (b[i].GetY() == y && x==1) {
			BlockShow[i] = false;
		}
	}
}

void Shape_1::blocky() {
	for (int i = 0; i < 3; ++i) {
		BlockY[i] = b[i].GetY();
		cout << BlockY[i]<< " ";
	}
}