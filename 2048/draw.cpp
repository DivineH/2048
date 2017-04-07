#include <iostream>
#include <iomanip>
#include <vector>
#include "common_define.h"

using namespace std;

extern int score;
extern int mat[ROW][COLUMN];
extern vector<int> emptyBlockVec;

void draw_line() {
	cout << "+";
	for (int i = 0; i < COLUMN; i++) {
		cout << "！！+";
	}
	cout << endl;
}

void draw() {
	system("cls");
	//cout << "+！！+！！+！！+！！+\n|    |    |    |    |\n+！！+！！+！！+！！+" << endl;
	draw_line();
	for (int i = 0; i < ROW; i++) {
		cout << '|';
		for (int j = 0; j < COLUMN; j++) {
			if (mat[i][j]) {
				cout << setiosflags(ios::right) << setw(MAX_NUM_DIGIT) << mat[i][j] << '|';
			}
			else {
				for (int k = 0; k < MAX_NUM_DIGIT; k++) {
					cout << ' ';
				}
				cout << '|';
			}
		}
		cout << endl;
		draw_line();
	}
	cout << endl << endl;
	for (int i = 0; i < ROW / 2; i++) {
		cout << "  ";
	}
	cout << "score: " << score << endl;
}