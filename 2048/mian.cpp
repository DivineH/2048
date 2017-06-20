#include <iostream>
#include <vector>
#include <conio.h>
#include "common_define.h"

using namespace std;

extern vector<int> emptyBlockVec;
extern int mat[ROW][COLUMN];
extern int score;

void init();
void play(char slt);

bool mergeBlock() {
	int shiftMat[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	int tmpX, tmpY;

	for (int i = 1; i < ROW - 1; i++) {
		for (int j = 1; j < COLUMN - 1; j++) {
			for (int k = 0; k < 4; k++) {
				tmpX = i + shiftMat[k][0];
				tmpY = j + shiftMat[k][1];
				if (tmpX >= 0 && tmpX < ROW && tmpY >= 0 && tmpY < COLUMN) {
					if (mat[tmpX][tmpY] == mat[i][j])
						return true;
				}
			}
		}
	}

	if (ROW >= 2 && COLUMN) {
		if (mat[0][0] == mat[1][0] || mat[0][0] == mat[ROW - 1][0])
			return true;
	}

	if (COLUMN >= 2 && ROW) {
		if (mat[0][COLUMN - 1] == mat[0][COLUMN - 2] || mat[0][COLUMN - 1] == mat[ROW - 1][COLUMN - 2])
			return true;
	}

	return false;
}

bool game_over() {
	if (emptyBlockVec.empty() && (!mergeBlock()))
		return true;
	return false;
}

int main() {
	char slt;
	bool reStart = true;
	while (reStart) {
		init();
		do {
			slt = getch();
			if (slt == 'f' || slt == 'F') {
				reStart = true;
				break;
			}
			if (slt == 'q' || slt == 'Q') {
				reStart = false;
				break;
			}
			play(slt);
		} while (!game_over());
	}
	return 0;
}