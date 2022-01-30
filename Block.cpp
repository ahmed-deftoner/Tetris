#include "Block.h"

Block::Block() {
	x = 0;
	y = 0;
}

void Block::draw(int x, int y, int r, int g, int b, int R, int G, int B) {
	this->x = x;
	this->y = y;
	drawRectangle(x, y, x + size, y + size, r, g, b, R, G, B);
}
															   
void Block::SetX(int x) {
	this->x = x;
}
void Block::SetY(int y) {
	this->y = y;
}
int Block::GetX() {
	return x;
}
int Block::GetY() {
	return y;
}

void Block::SetColor(int r, int g, int b) {
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void Block::ArrayDraw(int i, int j) {
	int ys = (i + 1) * 20;
	int xs = (j + 4) * 20;
	drawRectangle(xs, ys, xs + size, ys + size, 0, 0, 0, color[0], color[1], color[2]);
}

Block::~Block() {
}