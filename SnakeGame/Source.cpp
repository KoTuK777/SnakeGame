#include <iostream>
#include <ctime>
#include <vector>
#include "Game.h"

using namespace std;

int main() {
	srand(time(nullptr));

	Game game;
	game.play();

	cout << "\n\n";
	return 0;
}