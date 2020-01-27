#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "Snake.h"
#include "Food.h"

using namespace std;

void showChar(int x, int y, char character) {
	COORD cord;
	//1 unit = 0.5 width and 1 height
	cord.X = x * 2;
	cord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
	cout << character;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cord);
}

class Game {
	const int width = 20;
	const int heigth = 20;

	Snake snake;

	Food food;

	vector<vector<int>> map;

	vector<vector<int>> showMap;

public:
	Game() {
		map = vector<vector<int>>(heigth, vector<int>(width, 0));
		showMap = vector<vector<int>>(heigth, vector<int>(width, 0));
		//Generate walls
		for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				if (i == 0 || j == 0 || i == heigth - 1 || j == width - 1)
					map[i][j] = -1;
			}
		}

		updateMap();
	}

	void updateMap() {
		for (int i = 0; i < heigth; i++) {
			for (int j = 0; j < width; j++) {
				if (showMap[i][j] != map[i][j]) {
					showMap[i][j] = map[i][j];
					if (showMap[i][j] == 0)
						showChar(j, i, ' ');
					else if (showMap[i][j] == -1)
						showChar(j, i, '#');
					else if (showMap[i][j] == 1)
						showChar(j, i, '#');
					else if (showMap[i][j] == 2)
						showChar(j, i, '0');
				}
			}
		}
	}

	void play() {
		do {
			if (_kbhit()) snake.updateDir(_getch(), map);
			snake.moves(map);
			snake.updateSnake(map);

			updateMap();

			food.checkFood(map);
			if (!food.getIsFood()) {
				snake.addLength();
				food.createFood(map);
			}

			Sleep(200);
		} while (!snake.getCollision());
	}
};