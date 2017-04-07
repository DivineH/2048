#include <vector>
#include "common_define.h"

using namespace std;

extern int score;
extern int mat[ROW][COLUMN];
extern vector<int> emptyBlockVec;

bool moveBlock;

void draw();
int random(int mat, int b);

void moveUp() {
	int i, x, y;
	for (x = 0; x < COLUMN; x++)
		for (y = 0; y < ROW; ) {
			if (mat[y][x] == 0) {
				y++;
				continue;
			}
			else {
				for (i = y + 1; i < ROW; i++) {
					if (mat[i][x] == 0) {
						continue;
					}
					else if (mat[y][x] == mat[i][x]) {
						mat[y][x] += mat[i][x];
						mat[i][x] = 0;
						score += mat[y][x];
						break;
					}
					else {
						break;
					}
				}
				y = i;
			}
		}
	for (x = 0; x < COLUMN; x++)
		for (y = 0; y < ROW; y++) {
			if (mat[y][x] == 0) {
				continue;
			}
			else {
				for (i = y; (i > 0) && (mat[i - 1][x] == 0); i--) {
					mat[i - 1][x] = mat[i][x];
					mat[i][x] = 0;
					moveBlock = true;
				}
			}
		}
}

void moveDown() {
	int i, x, y;
	for (x = 0; x < COLUMN; x++)
		for (y = ROW - 1; y >= 0; ) {
			if (mat[y][x] == 0) {
				y--;
				continue;
			}
			else {
				for (i = y - 1; i >= 0; i--) {
					if (mat[i][x] == 0) {
						continue;
					}
					else if (mat[y][x] == mat[i][x]) {
						mat[y][x] += mat[i][x];
						mat[i][x] = 0;
						score += mat[y][x];
						break;
					}
					else {
						break;
					}
				}
				y = i;
			}
		}
	for (x = 0; x < COLUMN; x++)
		for (y = ROW - 1; y >= 0; y--) {
			if (mat[y][x] == 0) {
				continue;
			}
			else {
				for (i = y; (i < ROW - 1) && (mat[i + 1][x] == 0); i++) {
					mat[i + 1][x] = mat[i][x];
					mat[i][x] = 0;
					moveBlock = true;
				}
			}
		}
}

void moveLeft() {
	int i, x, y;
	for (y = 0; y < ROW; y++)
		for (x = 0; x < COLUMN; ) {
			if (mat[y][x] == 0) {
				x++;
				continue;
			}
			else {
				for (i = x + 1; i < COLUMN; i++) {
					if (mat[y][i] == 0) {
						continue;
					}
					else {
						if (mat[y][x] == mat[y][i]) {
							mat[y][x] += mat[y][i];
							mat[y][i] = 0;
							score += mat[y][x];
							break;
						}
						else {
							break;
						}
					}
				}
				x = i;
			}
		}
	for (y = 0; y < ROW; y++)
		for (x = 0; x < COLUMN; x++) {
			if (mat[y][x] == 0) {
				continue;
			}
			else {
				for (i = x; (i > 0) && (mat[y][i - 1] == 0); i--) {
					mat[y][i - 1] = mat[y][i];
					mat[y][i] = 0;
					moveBlock = true;
				}
			}
		}
}

void moveRight() {
	int i, x, y;
	for (y = 0; y < ROW; y++)
		for (x = COLUMN - 1; x >= 0; ) {
			if (mat[y][x] == 0) {
				x--;
				continue;
			}
			else {
				for (i = x - 1; i >= 0; i--) {
					if (mat[y][i] == 0) {
						continue;
					}
					else if (mat[y][x] == mat[y][i]) {
						mat[y][x] += mat[y][i];
						mat[y][i] = 0;
						score += mat[y][x];
						break;
					}
					else {
						break;
					}
				}
				x = i;
			}
		}
	for (y = 0; y < ROW; y++)
		for (x = COLUMN - 1; x >= 0; x--) {
			if (mat[y][x] == 0) {
				continue;
			}
			else {
				for (i = x; (i < COLUMN - 1) && (mat[y][i + 1] == 0); i++) {
					mat[y][i + 1] = mat[y][i];
					mat[y][i] = 0;
					moveBlock = true;
				}
			}
		}
}

void updateVec() {
	emptyBlockVec.clear();
	for (int i = 0; i < ROW; i++)
		for (int j = 0; j < COLUMN; j++)
			if (!mat[i][j])
				emptyBlockVec.push_back(ROW * i + j);
}

void play(char slt) {
	moveBlock = false;
	switch (slt)
	{
	case 'w':
	case 'W':
		moveUp();
		break;
	case 'a':
	case 'A':
		moveLeft();
		break;
	case 's':
	case 'S':
		moveDown();
		break;
	case 'd':
	case 'D':
		moveRight();
		break;
	default:
		break;
	}
	updateVec();
	if (moveBlock) {
		int blockIndex = random(0, emptyBlockVec.size());
		int blockId = emptyBlockVec[blockIndex];
		mat[blockId / ROW][blockId % ROW] = 2;
	}
	draw();
}