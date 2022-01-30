
#define MYGRAPHICS_H_

#include <windows.h>

// function prototypes

void drawLine(int x1,int y1,int x2,int y2,int colour); // draws a line between two points given their x-y coordinates in gray-scale
void drawLine(int x1,int y1,int x2,int y2,int r, int g, int b); // draws a line between two points given their x-y coordinates using RGB colouring
void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B); // draws a rectangle using top-left and bottom-right x-y coordinates with a border using RGB colouring
void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB ); // draws a rectangle using top-left and bottom-right x-y coordinates with separate border and fill colours
void drawEllipse(int x1, int y1, int x2, int y2,int R, int G, int B); // draws a rectangle-bounded ellipse using top-left and bottom-right x-y coordinates with a border using RGB colouring
void drawEllipse(int x1, int y1, int x2, int y2,int R, int G, int B, int FR, int FG, int FB); // draw a rectangle-bounded ellipse using top-left and bottom-right x-y coordinates with separate border and fill colours
void cls(); // clears the screen
void delay(int ms); // waits for some time (in milli-seconds)
char getKey(); // gets key typed into the console without waiting for the input
void getWindowDimensions(int& width, int& height); // gets width and height of the window
void getConsoleWindowDimensions(int& width, int& height); // gets width and height of console window (in character mode)
void gotoxy(int x,int y); // sets console cursor on given x-y coordinates
void showConsoleCursor(bool showFlag); // shows or hides the cursor










