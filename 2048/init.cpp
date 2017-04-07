#include <vector>
#include <stdlib.h>
#include <time.h>
#include "common_define.h"

using namespace std;

int score;
int mat[ROW][COLUMN];
vector<int> emptyBlockVec;

void draw();

int random(int a, int b) {
	srand(time(NULL));
	int c = rand() % (b - a) + a;
	return c;
}

void init() {
	score = 0;
	emptyBlockVec.clear();
	for (int i = 0; i < BLOCK_COUNT; i++) {
		mat[i / ROW][i % ROW] = 0;
		emptyBlockVec.push_back(i);
	}

	int blockIndex = random(0, emptyBlockVec.size());
	int blockId = emptyBlockVec[blockIndex];
	mat[blockId / ROW][blockId % ROW] = 2;
	draw();
}