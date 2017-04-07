#include <iostream>
#include <vector>
#include <conio.h>
#include "common_define.h"

using namespace std;

extern vector<int> emptyBlockVec;
extern int score;

void init();
void play(char slt);

bool game_over() {
	if (emptyBlockVec.empty())
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