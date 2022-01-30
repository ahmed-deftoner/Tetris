#include "mygraphics.h"

// function definitions

void drawLine(int x1, int y1, int x2, int y2, int colour) {
	drawLine(x1, y1, x2, y2, colour, colour, colour);
}

void drawLine(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND consoleHandle = GetConsoleWindow();
	HDC deviceContext = GetDC(consoleHandle);

	//change the colour by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for color.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(deviceContext, pen);
	MoveToEx(deviceContext, x1, y1, NULL);
	LineTo(deviceContext, x2, y2);
	DeleteObject(pen);
	ReleaseDC(consoleHandle, deviceContext);
}

void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B) {
	drawRectangle(x1, y1, x2, y2, R, G, B, 0, 0, 0);
}

void drawRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND consoleHandle = GetConsoleWindow();
	HDC deviceContext = GetDC(consoleHandle);

	//change the colour by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(deviceContext, pen);
	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB));
	SelectObject(deviceContext, brush);
	Rectangle(deviceContext, x1, y1, x2, y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(consoleHandle, deviceContext);

}

void drawEllipse(int x1, int y1, int x2, int y2, int R, int G, int B) {
	drawEllipse(x1, y1, x2, y2, R, G, B, 0, 0, 0);
}

void drawEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int FR, int FG, int FB)
{
	HWND consoleHandle = GetConsoleWindow();
	HDC deviceContext = GetDC(consoleHandle);

	//change the colour by changing the values in RGB (from 0-255)

	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(deviceContext, pen);
	HBRUSH brush = CreateSolidBrush(RGB(FR, FG, FB)); // fill colour
	SelectObject(deviceContext, brush);
	Ellipse(deviceContext, x1, y1, x2, y2);
	DeleteObject(pen);
	DeleteObject(brush);
	ReleaseDC(consoleHandle, deviceContext);

}

void cls()
{
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	FillConsoleOutputCharacter(consoleHandle,        // Handle to console screen buffer
		(TCHAR)' ',          // Character to write to the buffer
		dwConSize,            // Number of cells to write
		coordScreen,          // Coordinates of first cell
		&cCharsWritten);     // Receive number of characters written

}

void delay(int ms)
{
	Sleep(ms);
}

char getKey()
{
	HANDLE consoleHandle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD size = 1;
	INPUT_RECORD input[1];
	DWORD events = 0;
	char key = '\0';

	if (PeekConsoleInput(consoleHandle, input, size, &events)) {
		if (input[0].EventType == KEY_EVENT) {
			key = input[0].Event.KeyEvent.uChar.AsciiChar;
			FlushConsoleInputBuffer(consoleHandle);
			return key;
		}
	}

	return key; // returns NULL if no input event recorded
}

void getWindowDimensions(int& width, int& height)
{
	HWND consoleHandle = GetConsoleWindow();
	RECT rc;
	GetClientRect(consoleHandle, &rc);
	width = rc.right;
	height = rc.bottom;
}

void getConsoleWindowDimensions(int& width, int& height)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	if (!GetConsoleScreenBufferInfo(consoleHandle, &csbi)) {
		return;
	}

	width = csbi.srWindow.Right;
	height = csbi.srWindow.Bottom;
}

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void showConsoleCursor(bool flag)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(consoleHandle, &cursorInfo);
	cursorInfo.bVisible = flag; // show or hide if flag is true or false respectively
	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}


