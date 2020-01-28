#include <iostream>
#include <ctime>
#include "Game.h"
using namespace std;

void hideCursor() {
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
	structCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &structCursorInfo);
}

int main() {
	srand(time(nullptr));
	hideCursor();

	Game game;
	game.play();

	cout << "\n\n";
	return 0;
}
