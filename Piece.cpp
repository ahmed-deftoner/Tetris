#include "Piece.h"

void Piece::draw(int x,int y) {}
void Piece::rotate() {}
void Piece::clear(int x, int y){}

void Piece::moveX(int s){}
void Piece::SetX(int x){}
void Piece::SetY(int y){}
int Piece::getX() { return 0; }
int Piece::GetY() { return 0; }
void Piece::moveY(){}
void Piece::setRotateEnabled(int x){}
int Piece::getPos() { return 0; }
void Piece::CancelMovement(){}
int Piece::Type() { return 0; }
int Piece::checkBoundary(int i, int j) { return 0; }
void Piece::checkRight(int& i, int& j, Board& b){}
void Piece::checkLeft(int& i, int& j, Board& b){}
int Piece::checkDown(int& i, int& j, Board& b) { return 0; }