#pragma once
#include <iostream>
#include <vector>

using namespace std;

struct snakeCords {
	int x, y;
};

class Snake {
	vector<snakeCords> snake;

	int x = 10, y = 10;

	int lastX, lastY;

	int length = 2;

	bool right, left, up, down;
	bool collision = false;

public:
	Snake() {
		snakeCords head;
		head.x = x;
		head.y = y;
		snake.push_back(head);
		//cout << snake.size() << endl;
	}

	void updateSnake(vector<vector<int>>& map) {
		lastX = snake[snake.size() - 1].x;
		lastY = snake[snake.size() - 1].y;
		snake.pop_back();

		snakeCords newHead;
		newHead.x = x;
		newHead.y = y;
		auto iter = snake.cbegin();
		snake.insert(iter, newHead);

		for (size_t i = 0; i < snake.size(); i++) {
			map[snake[i].y][snake[i].x] = 1;
		}
		map[lastY][lastX] = 0;
	}

	void updateDir(int key, vector<vector<int>>& map) {
		right =
			left =
			down =
			up = false;
		switch (key) {
			//w = 119; W = 87; Up arrow = 72
		case 119: case 87: case 72:
			up = true; break;
			//a = 97; A = 65; Left arrow = 75
		case 97: case 65: case 75:
			left = true; break;
			//s = 115; S = 83; Down arrow = 80
		case 115: case 83: case 80:
			down = true; break;
			//d = 100; D = 68; Right arrow = 77
		case 100: case 68: case 77:
			right = true; break;
		}
	}

	void moves(vector<vector<int>> & map) {		
		if (!collision) {
			if (right) x++;
			if (left) x--;
			if (up) y--;
			if (down) y++;
			checkCollison(map);
		}
	}	

	void checkCollison(vector<vector<int>>& map) {
		if (right && (map[y][x + 1] == -1 || map[y][x + 1] == 1)) collision = true;
		if (left && (map[y][x - 1] == -1 || map[y][x - 1] == 1)) collision = true;
		if (up && (map[y - 1][x] == -1 || map[y - 1][x] == 1)) collision = true;
		if (down && (map[y + 1][x] == -1 || map[y + 1][x] == 1)) collision = true;
	}
	
	void addLength() {
		snakeCords tail;
		tail.x = lastX;
		tail.y = lastY;

		snake.push_back(tail);
	}

	bool getCollision() {
		return collision;
	}
};