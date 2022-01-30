#include "Shape_7.h"

Shape_7::Shape_7() {
	rotate_enabled = true;
	allow_move = true;
	position = 1;
	counter_x = 0;
	counter_y = 0;
	x = 0;
	y = 0;
}

void Shape_7::draw(int x, int y) {
	this->x = x;
	this->y = y;
	if (position == 1) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x + 20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x + 20, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 40, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 2) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x + 20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 20, y - 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 3) {
		b[0].draw(x, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x + 20, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x + 20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 40, y, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 4) {
		b[0].draw(x, y - 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x + 20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 20, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
}

void Shape_7::clear(int x, int y) {
	if (position == 1) {
		b[0].draw(x, y, 0, 0, 0, 0,0,0);
		b[1].draw(x + 20, y, 0, 0, 0, 0, 0, 0);
		b[2].draw(x + 20, y + 20, 0, 0, 0, 0, 0, 0);
		b[3].draw(x + 40, y + 20, 0, 0, 0, 0, 0, 0);
	}
	else if (position == 2) {
		b[0].draw(x, y, 0, 0, 0,  0, 0, 0);
		b[1].draw(x, y + 20, 0, 0, 0,  0, 0, 0);
		b[2].draw(x + 20, y, 0, 0, 0,  0, 0, 0);
		b[3].draw(x + 20, y - 20, 0, 0, 0,  0, 0, 0);
	}
	else if (position == 3) {
		b[0].draw(x, y + 20, 0, 0, 0,  0, 0, 0);
		b[1].draw(x + 20, y + 20, 0, 0, 0,  0, 0, 0);
		b[2].draw(x + 20, y, 0, 0, 0,  0, 0, 0);
		b[3].draw(x + 40, y, 0, 0, 0,  0, 0, 0);
	}
	else if (position == 4) {
		b[0].draw(x, y - 20, 0, 0, 0,  0, 0, 0);
		b[1].draw(x, y, 0, 0, 0,  0, 0, 0);
		b[2].draw(x + 20, y, 0, 0, 0,  0, 0, 0);
		b[3].draw(x + 20, y + 20, 0, 0, 0,  0, 0, 0);
	}
}

void Shape_7::SetX(int x) {
	this->x = x;
}

void Shape_7::SetY(int y) {
	this->y = y;
}

int Shape_7::getX() {
	return x;
}

int Shape_7::GetY() {
	return y;
}

void Shape_7::rotate() {
	if (rotate_enabled == true) {
		Shape_7::clear(x, y);
		if (position < 4) {
			position++;
		}
		else
			position = 1;
	}
}

void Shape_7::moveX(int s) {
	if (allow_move == true) {
		if (s == 1) {
			counter_x = 20;
			Shape_7::draw(x + counter_x, y);
			Shape_7::clear(x - 20, y);
		}
		else {
			counter_x = -20;
			Shape_7::draw(x + counter_x, y);
			Shape_7::clear(x + 20, y);
		}
	}
}

void Shape_7::setRotateEnabled(int x) {
	if (x == 0)
		rotate_enabled = false;
	else
		rotate_enabled = true;
}

void Shape_7::moveY() {
	if (allow_move == true) {
		counter_y = 20;
		Shape_7::draw(x, y + counter_y);
		Shape_7::clear(x, y - 20);
	}
}

int Shape_7::getPos() {
	return position;
}

void Shape_7::CancelMovement() {
	allow_move = false;
}

int Shape_7::Type() {
	return 7;
}
int Shape_7::checkBoundary(int i, int j) {
	int x = Shape_7::getPos();
	if (j <= Boundary1)
		return 1;
	else if (j >= Boundary2)
		return 1;
	else if (i >= Boundary3)
		return 1;
	return 0;
}

void Shape_7::checkRight(int& i, int& j, Board& b) {
	int pos = Shape_7::getPos();
	if (pos == 1) {
		int c = b.check_1(i, j + 3);
		if (c == 0 && j < 16) {
			Shape_7::moveX(1);
			++j;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i, j + 2);
		if (c == 0 && j < 16) {
			Shape_7::moveX(1);
			++j;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i, j + 3);
		if (c == 0 && j < 16) {
			Shape_7::moveX(1);
			++j;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i, j + 2);
		if (c == 0 && j < 16) {
			Shape_7::moveX(1);
			++j;
		}
	}
}

void Shape_7::checkLeft(int& i, int& j, Board& b) {
	int pos = Shape_7::getPos();
	if (pos == 1) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_7::moveX(-1);
			--j;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_7::moveX(-1);
			--j;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_7::moveX(-1);
			--j;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_7::moveX(-1);
			--j;
		}
	}
}

int Shape_7::checkDown(int& i, int& j, Board& b) {
	int pos = Shape_7::getPos();
	if (pos == 1) {
		int c = b.check_1(i + 1, j);
		int b1 = b.check_1(i + 2, j + 1);
		int b2 = b.check_1(i + 2, j + 2);
		if (c == 0 && b1 == 0 && b2 == 0) {
			Shape_7::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j + 1);
			b.setMatrix(i, j);
			b.setMatrix(i + 1, j + 1);
			b.setMatrix(i + 1, j + 2);
			Shape_7::CancelMovement();
			Shape_7::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i + 1, j + 1);
		int b1 = b.check_1(i + 2, j);
		if (c == 0 && b1 == 0) {
			Shape_7::moveY();
			i++;
		}
		else {
			b.setMatrix(i - 1, j + 1);
			b.setMatrix(i, j + 1);
			b.setMatrix(i, j);
			b.setMatrix(i + 1, j);
			for (int k = i; k < i + 3; ++k)
				b.setMatrix(k, j + 1);
			Shape_7::CancelMovement();
			Shape_7::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i + 2, j);
		int b1 = b.check_1(i + 2, j+1);
		int b2 = b.check_1(i+1, j + 2);
		if (c == 0 && b1 == 0 && b2 == 0) {
			Shape_7::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j + 2);
			b.setMatrix(i, j + 1);
			b.setMatrix(i + 1, j + 1);
			b.setMatrix(i + 1, j);
			Shape_7::CancelMovement();
			Shape_7::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i + 1, j);
		int b1 = b.check_1(i + 2, j + 1);
		if (c == 0 && b1 == 0) {
			Shape_7::moveY();
			i++;
		}
		else {
			b.setMatrix(i - 1, j);
			b.setMatrix(i, j);
			b.setMatrix(i, j + 1);
			b.setMatrix(i + 1, j + 1);
			Shape_7::CancelMovement();
			Shape_7::setRotateEnabled(0);
			return 1;
		}
	}
	return 0;
}