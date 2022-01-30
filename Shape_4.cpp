#include "Shape_4.h"

Shape_4::Shape_4() {
	rotate_enabled = true;
	allow_move = true;
	position = 1;
	counter_x = 0;
	counter_y = 0;
	x = 0;
	y = 0;
}

void Shape_4::draw(int x, int y) {
	this->x = x;
	this->y = y;
	b[0].draw(x, y, 0, 0, 0, colors[0], colors[1], colors[2]);
	b[1].draw(x+20, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
	b[2].draw(x+20, y, 0, 0, 0, colors[0], colors[1], colors[2]);
	b[3].draw(x, y + 20, 0, 0, 0, colors[0], colors[1], colors[2]);
}

void Shape_4::clear(int x, int y) {
	b[0].draw(x, y, 0, 0, 0, 0,0,0);
	b[1].draw(x + 20, y + 20, 0, 0, 0, 0, 0, 0);
	b[2].draw(x+20, y, 0, 0, 0, 0, 0, 0);
	b[3].draw(x, y + 20, 0, 0, 0, 0, 0, 0);
}

void Shape_4::SetX(int x) {
	this->x = x;
}

void Shape_4::SetY(int y) {
	this->y = y;
}

int Shape_4::getX() {
	return x;
}

int Shape_4::GetY() {
	return y;
}

void Shape_4::rotate() {
	
}

void Shape_4::moveX(int s) {
	if (allow_move == true) {
		if (s == 1) {
			counter_x = 20;
			Shape_4::draw(x + counter_x, y);
			Shape_4::clear(x - 20, y);
		}
		else {
			counter_x = -20;
			Shape_4::draw(x + counter_x, y);
			Shape_4::clear(x + 20, y);
		}
	}
}

void Shape_4::setRotateEnabled(int x) {
	if (x == 0)
		rotate_enabled = false;
	else
		rotate_enabled = true;
}

void Shape_4::moveY() {
	if (allow_move == true) {
		counter_y = 20;
		Shape_4::draw(x, y + counter_y);
		Shape_4::clear(x, y - 20);
	}
}

int Shape_4::getPos() {
	return position;
}

void Shape_4::CancelMovement() {
	allow_move = false;
}

int Shape_4::Type() {
	return 4;
}

int Shape_4::checkBoundary(int i, int j) {
	return 0;
}

void Shape_4::checkRight(int& i, int& j, Board& b) {
	int c = b.check_1(i, j + 2);
	if (c == 0 && j < 16) {
		Shape_4::moveX(1);
		++j;
	}
}

void Shape_4::checkLeft(int& i, int& j, Board& b) {
	int c = b.check_1(i, j - 1);
	if (c == 0 && j < 16) {
		Shape_4::moveX(-1);
		--j;
	}
}

int Shape_4::checkDown(int& i, int& j, Board& b) {
	int c = b.check_1(i + 2, j);
	int b1 = b.check_1(i + 2, j + 1);
	if (c == 0 && b1 == 0) {
		Shape_4::moveY();
		i++;
	}
	else {
		b.setMatrix(i, j);
		b.setMatrix(i + 1, j);
		b.setMatrix(i, j + 1);
		b.setMatrix(i + 1, j + 1);
		Shape_4::CancelMovement();
		Shape_4::setRotateEnabled(0);
		return 1;
	}
	return 0;
}