#include "Shape_1.h"
#include "Shape_2.h"
#include "Shape_3.h"
#include "Shape_4.h"
#include "Shape_5.h"
#include "Shape_6.h"
#include "Shape_7.h"
#include "Board.h"
#include <random>

int main(){

	 //Splash Screen
	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	cout << "\n\n\n";
	cout << "   ***********************      ***************     ***********************  *************      *****      ****************\n";
	cout << "             *                  *                              *             *           *        *        *               \n";
	cout << "             *                  *                              *             *           *        *        *               \n";
	cout << "             *                  *                              *             *           *        *        *               \n";
	cout << "             *                  ***************                *             ************         *        ****************\n";
	cout << "             *                  *                              *             * **                 *                       *\n";
	cout << "             *                  *                              *             *    **              *                       *\n";
	cout << "             *                  *                              *             *       **           *                       *\n";
	cout << "             *                  ***************                *             *          **      *****      ****************\n";
	SetConsoleTextAttribute(hConsole, 9);
	cout << "\n\t\t\t\t\t\tWELCOME\n";
	SetConsoleTextAttribute(hConsole, 14);
	cout << "\t\t\t\t\t3000 points - GOLD\n";
	cout << "\t\t\t\t\t1000 points - SILVER\n";
	cout << "\t\t\t\t\t500 points - BRONZE\n";
	cout << "\t\t\t\t\t200 points - NOOB\n";
	
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\n\n\n\t\t\t\t\tPress <SPACEBAR> to continue.....\n";
	while (true) {
		if (GetKeyState(VK_SPACE) & 0x8000)
			break;
	}

	//next screen
	cls();
	showConsoleCursor(true);

	//score output
	SetConsoleTextAttribute(hConsole, 23);
	gotoxy(70, 2);
	cout << "SCORE\n";
	int score = 0;
	gotoxy(70, 4);
	SetConsoleTextAttribute(hConsole, 15);
	cout <<"  "<< score;

	//random generator
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(1, 7);
	Piece* s[150];	  //pieces
	for (int i = 0; i < 150; ++i) {
		int x = distr(gen);
		//randomly selects shape
		if (x == 1) {
			s[i] = new Shape_1;
		}
		else if (x == 2) {
			s[i] = new Shape_2;
		}
		else if (x == 3) {
			s[i] = new Shape_3;
		}
		else if (x == 4) {
			s[i] = new Shape_4;
		}
		else if (x == 5) {
			s[i] = new Shape_5;
		}
		else if (x == 6) {
			s[i] = new Shape_6;
		}
		else if (x == 7) {
			s[i] = new Shape_7;
		}
	} 													   
	
	// Initialising
	int w = 0, h = 0;
	//getWindowDimensions(w,h);

	//cls();
	showConsoleCursor(false);

	
	Board b;  //board
	
	Block block[19][15];
	// main event loop
	int x = 0;
	int xs = 200;		 //initial position x
	int ys = 40;		 //initial position y
	//setting positions
	for (int i = 0; i < 150; ++i) {
		s[i]->SetX(xs);
		s[i]->SetY(ys);
	}		

	int i = (ys / 20) - 1;		   //counter of y
	int j = (xs / 20) - 4;	   //counter of x
	int counter = 0;		//counter for pieces
	int ch = -1;
	int line_count = 1;
	while (true){
		b.draw();	//drawing board
		if (counter < 150) {
			//check if player has lost
			
			bool lost = false;
			for (int k = 1; k < 15; ++k) {
				if (b.check_1(1, k) == -1) {
					lost = true;
					break;
				}
			}
			if (lost == true) {
				break;
			}
			for (int c = 1; c < 19; ++c) {
				for (int d = 1; d < 15; ++d) {
					if (b.check_1(c, d) == 0)
						continue;
					else
						block[c][d].ArrayDraw(c, d);
				}
			}
			s[counter]->draw(s[counter]->getX(), s[counter]->GetY());
			delay(100);
			s[counter]->draw(s[counter]->getX(), s[counter]->GetY());
			char cd = getKey();

			//space pressed
			if (GetKeyState(VK_SPACE) & 0x8000) {
				//rotate
				ch = s[counter]->checkBoundary(i, j);
				if (ch == 0)
					s[counter]->rotate();
			}
			//right key pressed
			if (GetKeyState(VK_RIGHT) & 0x8000) {
				s[counter]->checkRight(i, j, b);
			}
			//left key pressed
			if (GetKeyState(VK_LEFT) & 0x8000) {
				s[counter]->checkLeft(i, j, b);
			}
			//if (GetKeyState(VK_DOWN) & 0x8000) {
				int x = s[counter]->checkDown(i, j, b);
				if (x == 1) {
					//block checker
					int pos = s[counter]->getPos();
					//using types
					if (s[counter]->Type() == 1) {
						if (pos == 1 || pos == 3) {
							block[i][j].SetColor(0, 240, 255);
							block[i+1][j].SetColor(0, 240, 255);
							block[i+2][j].SetColor(0, 240, 255);
						}
						else if (pos == 2 || pos == 4) {
							block[i][j].SetColor(0, 240, 255);
							block[i][j+1].SetColor(0, 240, 255);
							block[i][j+2].SetColor(0, 240, 255);
						}
					}
					else if (s[counter]->Type() == 2) {
						if (pos == 1) {
							block[i][j].SetColor(0, 0, 240);
							block[i+1][j].SetColor(0, 0, 240);
							block[i+1][j+1].SetColor(0, 0, 240);
							block[i+1][j+2].SetColor(0, 0, 240);
						}
						else if (pos == 2) {
							block[i+1][j].SetColor(0, 0, 240);
							block[i + 1][j+1].SetColor(0, 0, 240);
							block[i + 2][j].SetColor(0, 0, 240);
							block[i + 3][j].SetColor(0, 0, 240);
						}
						else if (pos == 3) {
							block[i][j].SetColor(0, 0, 240);
							block[i + 1][j].SetColor(0, 0, 240);
							block[i + 1][j - 1].SetColor(0, 0, 240);
							block[i + 1][j - 2].SetColor(0, 0, 240);
						}
						else if (pos == 4) {
							block[i][j].SetColor(0, 0, 240);
							block[i + 1][j].SetColor(0, 0, 240);
							block[i + 2][j].SetColor(0, 0, 240);
							block[i + 2][j + 1].SetColor(0, 0, 240);
						}
					}
					else if (s[counter]->Type() == 3) {
						if (pos == 1) {
							block[i][j].SetColor(255, 200, 0);
							block[i + 1][j].SetColor(255, 200, 0);
							block[i + 1][j-1].SetColor(255, 200, 0);
							block[i + 1][j - 2].SetColor(255, 200, 0);
						}
						else if (pos == 2) {
							block[i][j].SetColor(255, 200, 0);
							block[i + 1][j].SetColor(255, 200, 0);
							block[i + 2][j].SetColor(255, 200, 0);
							block[i + 2][j + 1].SetColor(255, 200, 0);
						}
						else if (pos == 3) {
							block[i][j].SetColor(255, 200, 0);
							block[i + 1][j].SetColor(255, 200, 0);
							block[i][j + 1].SetColor(255, 200, 0);
							block[i][j + 2].SetColor(255, 200, 0);
						}
						else if (pos == 4) {
							block[i][j].SetColor(255, 200, 0);
							block[i][j+1].SetColor(255, 200, 0);
							block[i + 1][j + 1].SetColor(255, 200, 0);
							block[i + 2][j + 1].SetColor(255, 200, 0);
						}
					}
					else if (s[counter]->Type() == 4) {
						block[i][j].SetColor(240, 255, 0);
						block[i+1][j + 1].SetColor(240, 255, 0);
						block[i][j + 1].SetColor(240, 255, 0);
						block[i + 1][j].SetColor(240, 255, 0);
					}
					else if (s[counter]->Type() == 5) {
						if (pos == 1) {
							block[i+1][j].SetColor(0, 240, 0);
							block[i + 1][j + 1].SetColor(0, 240, 0);
							block[i][j + 1].SetColor(0, 240, 0);
							block[i][j+2].SetColor(0, 240, 0);
						}
						else if (pos == 2) {
							block[i - 1][j].SetColor(0, 240, 0);
							block[i][j].SetColor(0, 240, 0);
							block[i][j + 1].SetColor(0, 240, 0);
							block[i+1][j + 1].SetColor(0, 240, 0);
						}
						else if (pos == 3) {
							block[i][j].SetColor(0, 240, 0);
							block[i][j + 1].SetColor(0, 240, 0);
							block[i+1][j + 1].SetColor(0, 240, 0);
							block[i+1][j + 2].SetColor(0, 240, 0);
						}
						else if (pos == 4) {
							block[i][j].SetColor(0, 240, 0);
							block[i + 1][j].SetColor(0, 240, 0);
							block[i][j + 1].SetColor(0, 240, 0);
							block[i-1][j + 1].SetColor(0, 240, 0);
						}
					}
					else if (s[counter]->Type() == 6) {
						if (pos == 1) {
							block[i][j].SetColor(255, 0, 240);
							block[i + 1][j-1].SetColor(255, 0, 240);
							block[i+1][j].SetColor(255, 0, 240);
							block[i + 1][j + 1].SetColor(255, 0, 240);
						}
						else if (pos == 2) {
							block[i][j].SetColor(255, 0, 240);
							block[i - 1][j - 1].SetColor(255, 0, 240);
							block[i][j-1].SetColor(255, 0, 240);
							block[i + 1][j - 1].SetColor(255, 0, 240);
						}
						else if (pos == 3) {
							block[i][j].SetColor(255, 0, 240);
							block[i - 1][j - 1].SetColor(255, 0, 240);
							block[i - 1][j].SetColor(255, 0, 240);
							block[i - 1][j + 1].SetColor(255, 0, 240);
						}
						else if (pos == 4) {
							block[i][j].SetColor(255, 0, 240);
							block[i + 1][j + 1].SetColor(255, 0, 240);
							block[i][j+1].SetColor(255, 0, 240);
							block[i - 1][j + 1].SetColor(255, 0, 240);
						}
					}
					else if (s[counter]->Type() == 7) {
					 if (pos == 1) {
						 block[i][j].SetColor(250, 0, 0);
						 block[i][j + 1].SetColor(250, 0, 0);
						 block[i + 1][j + 1].SetColor(250, 0, 0);
						 block[i + 1][j + 2].SetColor(250, 0, 0);
					}
					else if (pos == 2) {
						 block[i][j].SetColor(250, 0, 0);
						 block[i + 1][j].SetColor(250, 0, 0);
						 block[i][j + 1].SetColor(250, 0, 0);
						 block[i - 1][j + 1].SetColor(250, 0, 0);
					}
					else if (pos == 3) {
						 block[i + 1][j].SetColor(250, 0, 0);
						 block[i + 1][j + 1].SetColor(250, 0, 0);
						 block[i][j + 1].SetColor(250, 0, 0);
						 block[i][j + 2].SetColor(250, 0, 0);
					}
					else if (pos == 4) {
						 block[i - 1][j].SetColor(250, 0, 0);
						 block[i][j].SetColor(250, 0, 0);
						 block[i][j + 1].SetColor(250, 0, 0);
						 block[i + 1][j + 1].SetColor(250, 0, 0);
					}				
					}
					bool line = false;
					for (int c = 1; c < 19; ++c) {
						for (int d = 1; d < 15; ++d) {
							if (b.check_1(c, d) == -1) {
								line = true;
								line_count = c;
								//score += 23;
							}
							else {
								line = false;
								break;
							}
						}
						if (line == true) {
							for (int a = line_count-1; a > 1; --a) {
								for (int d = 1; d < 16; ++d) {
									if (b.check_1(a, d) == -1) {
										b.setMatrix(a + 1, d);
										block[a + 1][d].SetColor(block[a][d].color[0], block[a][d].color[1], block[a][d].color[2]);
									}
									else {
										b.resetMatrix(a + 1, d);
										block[a + 1][d].SetColor(0,0,0);
										block[a + 1][d].ArrayDraw(a + 1, d);
									}
								}
							}
						}
					}
					i = (ys / 20) - 1;
					j = (xs / 20) - 4;
					counter++;
					score += 10;
					gotoxy(70, 4);
					cout << score;
				}
				if (j >= 17)
					j--;
				s[counter]->draw(s[counter]->getX(), s[counter]->GetY());
				delay(120);
				s[counter]->draw(s[counter]->getX(), s[counter]->GetY());
				//space pressed
				if (GetKeyState(VK_SPACE) & 0x8000) {
					//rotate
					ch = s[counter]->checkBoundary(i, j);
					if (ch == 0)
						s[counter]->rotate();
				}
				//right key pressed
				if (GetKeyState(VK_RIGHT) & 0x8000) {
					s[counter]->checkRight(i, j, b);
				}
				//left key pressed
				if (GetKeyState(VK_LEFT) & 0x8000) {
					s[counter]->checkLeft(i, j, b);
				}
				s[counter]->draw(s[counter]->getX(), s[counter]->GetY());
			//}
		}
	}
	cls();
	SetConsoleTextAttribute(hConsole, 12);
	gotoxy(0, 0);
	cout << "\t **           **     ***     **       *  *    *  ******\n";
	cout << "\t * *         * *   *     *   * *      *  *  *    *\n";
	cout << "\t *   *      *  *  *       *  *   *    *  **      ****\n";
	cout << "\t *     *  *    *   *     *   *     *  *  *  *    *\n";
	cout << "\t *      **     *     ***     *       **  *    *  ******\n";
	
	SetConsoleTextAttribute(hConsole, 11);
	cout << "\n\n\n\n\n\t\t\t\tSCORE:\t" << score << "\n\n\n";
	cout << "\n\n\n\t\t\t\t\tPress <SPACEBAR> to continue.....\n";
	while (true) {
		if (GetKeyState(VK_SPACE) & 0x8000)
			break;
	}
	
	return 0;
}

