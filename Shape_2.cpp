#include "Shape_2.h"

Shape_2::Shape_2() {
	rotate_enabled = true;
	allow_move = true;
	position = 1;
	counter_x = 0;
	counter_y = 0;
	x = 0;
	y = 0;
}

void Shape_2::draw(int x, int y) {
	this->x = x;
	this->y = y;
	if (position == 1) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x+20, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x + 40, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 2) {
		b[0].draw(x, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x + 20, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x, y+40, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x, y + 60, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 3) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x - 20, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x - 40, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
	else if (position == 4) {
		b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[1].draw(x, y+20, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[2].draw(x, y + 40, 0, 0, 0, colors[0], colors[1], colors[2]);
		b[3].draw(x+20, y + 40, 0, 0, 0, colors[0], colors[1], colors[2]);
	}
}

void Shape_2::clear(int x, int y) {
	if (position == 1) {
		b[0].draw(x, y, 0, 0, 0, 0, 0, 0);
		b[1].draw(x, y + 20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x + 20, y + 20, 0, 0, 0, 0, 0, 0);
		b[3].draw(x + 40, y + 20, 0, 0, 0, 0, 0, 0);
	}
	else if (position == 2 ) {
		b[0].draw(x, y+20, 0, 0, 0, 0, 0, 0);
		b[1].draw(x + 20, y+20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x, y + 40, 0, 0, 0, 0, 0, 0);
		b[3].draw(x, y + 60, 0, 0, 0, 0, 0, 0);
	}
	else if (position == 3) {
		b[0].draw(x, y, 0, 0, 0, 0, 0, 0);
		b[1].draw(x, y+20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x - 20, y+20, 0, 0, 0, 0, 0, 0);
		b[3].draw(x - 40, y + 20, 0, 0, 0, 0, 0, 0);
	}
	else if (position == 4) {
		b[0].draw(x, y, 0, 0, 0, 0, 0, 0);
		b[1].draw(x, y + 20, 0, 0, 0, 0, 0, 0);
		b[2].draw(x, y + 40, 0, 0, 0, 0, 0, 0);
		b[3].draw(x + 20, y + 40, 0, 0, 0, 0, 0, 0);
	}
}

void Shape_2::SetX(int x) {
	this->x = x;
}

void Shape_2::SetY(int y) {
	this->y = y;
}

int Shape_2::getX() {
	return x;
}

int Shape_2::GetY() {
	return y;
}

void Shape_2::rotate() {
	if (rotate_enabled == true) {
		Shape_2::clear(x, y);
		if (position < 4) {
			position++;
		}
		else
			position = 1;
	}
}

void Shape_2::moveX(int s) {
	if (allow_move == true) {
		if (s == 1) {
			counter_x = 20;
			Shape_2::draw(x + counter_x, y);
			Shape_2::clear(x - 20, y);
		}
		else {
			counter_x = -20;
			Shape_2::draw(x + counter_x, y);
			Shape_2::clear(x + 20, y);
		}
	}
}

void Shape_2::setRotateEnabled(int x) {
	if (x == 0)
		rotate_enabled = false;
	else
		rotate_enabled = true;
}

void Shape_2::moveY() {
	if (allow_move == true) {
		counter_y = 20;
		Shape_2::draw(x, y + counter_y);
		Shape_2::clear(x, y - 20);
	}
}

int Shape_2::getPos() {
	return position;
}

void Shape_2::CancelMovement() {
	allow_move = false;
}

int Shape_2::Type() {
	return 2;
}


int Shape_2::checkBoundary(int i, int j) {
	int x = Shape_2::getPos();
	if (j <= Boundary1)
		return 1;
	else if (j >= Boundary2)
		return 1;
	else if (i >= Boundary3)
		return 1;
	return 0;
}

void Shape_2::checkRight(int& i, int& j, Board& b) {
	int pos = Shape_2::getPos();
	if (pos == 1) {
		int c = b.check_1(i, j + 3);
		if (c == 0 && j < 16) {
			Shape_2::moveX(1);
			++j;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i, j+2);
		if (c == 0 && j < 16) {
			Shape_2::moveX(1);
			++j;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i, j + 1);
		if (c == 0 && j < 16) {
			Shape_2::moveX(1);
			++j;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i, j + 2);
		if (c == 0 && j < 16) {
			Shape_2::moveX(1);
			++j;
		}
	}
}

void Shape_2::checkLeft(int& i, int& j, Board& b) {
	int pos = Shape_2::getPos();
	if (pos == 1) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_2::moveX(-1);
			--j;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_2::moveX(-1);
			--j;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i, j - 3);
		if (c == 0 && j < 16) {
			Shape_2::moveX(-1);
			--j;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i, j - 1);
		if (c == 0 && j < 16) {
			Shape_2::moveX(-1);
			--j;
		}
	}
}			  

int Shape_2::checkDown(int& i, int& j, Board& b) {
	int pos = Shape_2::getPos();
	if (pos == 1) {
		int c = b.check_1(i + 2, j);
		int b1 = b.check_1(i + 2, j + 1);
		int b2 = b.check_1(i + 2, j + 2);
		if (c == 0 && b1==0 && b2==0) {
			Shape_2::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j);
			for (int k = j; k < j + 3; ++k)
				b.setMatrix(i+1, k);
			Shape_2::CancelMovement();
			Shape_2::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 2) {
		int c = b.check_1(i + 4, j);
		int b1 = b.check_1(i + 2, j + 1);
		if (c == 0 && b1 == 0) {
			Shape_2::moveY();
			i++;
		}
		else {
			b.setMatrix(i+1, j + 1);
			for (int k = i+1; k < i + 4; ++k)
				b.setMatrix(k, j);
			Shape_2::CancelMovement();
			Shape_2::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 3) {
		int c = b.check_1(i + 2, j);
		int b1 = b.check_1(i + 2, j - 1);
		int b2 = b.check_1(i + 2, j - 2);
		if (c == 0 && b1 == 0 && b2 == 0) {
			Shape_2::moveY();
			i++;
		}
		else {
			b.setMatrix(i, j);
			for (int k = j; k >=j-2; --k)
				b.setMatrix(i + 1, k);
			Shape_2::CancelMovement();
			Shape_2::setRotateEnabled(0);
			return 1;
		}
	}
	else if (pos == 4) {
		int c = b.check_1(i + 3, j);
		int b1 = b.check_1(i + 3, j + 1);
		if (c == 0 && b1 == 0) {
			Shape_2::moveY();
			i++;
		}
		else {
			b.setMatrix(i+2, j + 1);
			for (int k = i; k < i + 3; ++k)
				b.setMatrix(k, j);
			Shape_2::CancelMovement();
			Shape_2::setRotateEnabled(0);
			return 1;
		}
	}
	return 0;
}