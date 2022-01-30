#include "Shape_6.h"


Shape_6::Shape_6() {
	rotate_enabled = true;
	allow_move = true;
	position = 1;
	counter_x = 0;
	counter_y = 0;
	x = 0;
	y = 0;
}

void Shape_6::draw(int x, int y) {
	this->x = x;
	this->y = y;
	if (position == 1) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x - 20, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x , y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 20, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 2) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x-20, y-20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x-20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x - 20, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 3) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x - 20, y-20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x, y - 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 20, y - 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 4) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x+20, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x + 20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 20, y - 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
}

void Shape_6::clear(int x, int y) {
	if (position == 1) {
		b[0].draw(x, y, 0, 0, 0, 0,0,0);
		b[1].draw(x - 20, y + 20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x, y + 20, 0, 0, 0, 0, 0, 0);
		b[3].draw(x + 20, y + 20, 0, 0, 0, 0, 0, 0);
	}
	else if (position == 2) {
		b[0].draw(x, y, 0, 0, 0, 0, 0, 0);
		b[1].draw(x - 20, y - 20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x-20, y, 0, 0, 0, 0, 0, 0);
		b[3].draw(x - 20, y + 20, 0, 0, 0, 0, 0, 0);
	}
	else if (position == 3) {
		b[0].draw(x, y, 0, 0, 0, 0, 0, 0);
		b[1].draw(x - 20, y - 20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x, y - 20, 0, 0, 0, 0, 0, 0);
		b[3].draw(x + 20, y - 20, 0, 0, 0, 0, 0, 0);
	}
	else if (position == 4) {
		b[0].draw(x, y, 0, 0, 0, 0, 0, 0);
		b[1].draw(x + 20, y + 20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x + 20, y, 0, 0, 0, 0, 0, 0);
		b[3].draw(x + 20, y - 20, 0, 0, 0, 0,0,0);
	}
}

void Shape_6::SetX(int x) {
	this->x = x;
}

void Shape_6::SetY(int y) {
	this->y = y;
}

int Shape_6::getX() {
	return x;
}

int Shape_6::GetY() {
	return y;
}

void Shape_6::rotate() {
	if (rotate_enabled == true) {
		Shape_6::clear(x, y);
		if (position < 4) {
			position++;
		}
		else
			position = 1;
	}
}

void Shape_6::moveX(int s) {
	if (allow_move == true) {
		if (s == 1) {
			counter_x = 20;
			Shape_6::draw(x + counter_x, y);
			Shape_6::clear(x - 20, y);
		}
		else {
			counter_x = -20;
			Shape_6::draw(x + counter_x, y);
			Shape_6::clear(x + 20, y);
		}
	}
}

void Shape_6::setRotateEnabled(int x) {
	if (x == 0)
		rotate_enabled = false;
	else
		rotate_enabled = true;
}

void Shape_6::moveY() {
	if (allow_move == true) {
		counter_y = 20;
		Shape_6::draw(x, y + counter_y);
		Shape_6::clear(x, y - 20);
	}
}

int Shape_6::getPos() {
	return position;
}

void Shape_6::CancelMovement() {
	allow_move = false;
}

int Shape_6::Type() {
	return 6;
}

int Shape_6::checkBoundary(int i, int j) {
	int x = Shape_6::getPos();
	if (i >= Boundary3)
		return 1;
	return 0;
}

void Shape_6::checkRight(int& i, int& j, Board& b) {
	int pos = Shape_6::getPos();
	if (pos == 1) {
		int c = b.check_1(i, j + 2);
		if (c == 0 && j < 16) {
			Shape_6::moveX(1);
			++j;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i, j + 1);
		if (c == 0 && j < 16) {
			Shape_6::moveX(1);
			++j;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i, j + 2);
		if (c == 0 && j < 16) {
			Shape_6::moveX(1);
			++j;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i, j + 2);
		if (c == 0 && j < 16) {
			Shape_6::moveX(1);
			++j;
		}
	}
}

void Shape_6::checkLeft(int& i, int& j, Board& b) {
	int pos = Shape_6::getPos();
	if (pos == 1) {
		int c = b.check_1(i, j - 2);
		if (c == 0 && j < 16) {
			Shape_6::moveX(-1);
			--j;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i, j - 2);
		if (c == 0 && j < 16) {
			Shape_6::moveX(-1);
			--j;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i, j - 2);
		if (c == 0 && j < 16) {
			Shape_6::moveX(-1);
			--j;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_6::moveX(-1);
			--j;
		}
	}
}

int Shape_6::checkDown(int& i, int& j, Board& b) {
	int pos = Shape_6::getPos();
	if (pos == 1) {
		int c = b.check_1(i+2, j);
		int b1 = b.check_1(i+2, j + 1);
		int b2 = b.check_1(i+2, j-1);
		if (c == 0 && b1 == 0 && b2 == 0) {
			Shape_6::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j);
			b.setMatrix(i+1, j);
			b.setMatrix(i + 1, j + 1);
			b.setMatrix(i + 1, j-1);
			Shape_6::CancelMovement();
			Shape_6::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i + 1, j);
		int b1 = b.check_1(i + 2, j-1);
		if (c == 0 && b1 == 0) {
			Shape_6::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j);
			b.setMatrix(i+1, j-1);
			b.setMatrix(i, j - 1);
			b.setMatrix(i - 1, j - 1);
			Shape_6::CancelMovement();
			Shape_6::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i +1, j);
		int b1 = b.check_1(i, j + 1);
		int b2 = b.check_1(i, j - 1);
		if (c == 0 && b1 == 0 && b2 == 0) {
			Shape_6::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j);
			b.setMatrix(i -1, j - 1);
			b.setMatrix(i-1, j );
			b.setMatrix(i - 1, j + 1);
			Shape_6::CancelMovement();
			Shape_6::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i + 1, j);
		int b1 = b.check_1(i+2, j+1);
		if (c == 0 && b1 == 0) {
			Shape_6::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j);
			b.setMatrix(i + 1, j + 1);
			b.setMatrix(i, j + 1);
			b.setMatrix(i - 1, j + 1);
			Shape_6::CancelMovement();
			Shape_6::setRotateEnabled(0);
			return 1;
		}
	}
	return 0;
}