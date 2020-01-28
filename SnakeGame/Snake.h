#pragma once
#include <iostream>
#include <vector>
using namespace std;

struct snakeCords {
	int x, y;
};

class Snake {
	vector<snakeCords> snake;

	const int id = 1;

	int x = 10, y = 10;

	int lastX, lastY;

	int length = 1;

	bool right, left, up, down;
	bool collision = false;

public:
	Snake() {
		snakeCords head;
		head.x = x;
		head.y = y;
		snake.push_back(head);
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
		switch (key) {
			//w = 119; W = 87; Up arrow = 72
		case 119: case 87: case 72:
			if (!down)
			{
				up = true; 
				right =
				left =
				down = false;
			}
			break;			
			//a = 97; A = 65; Left arrow = 75
		case 97: case 65: case 75:
			if (!right) {
				left = true;
				right =
				up =
				down = false;
			}
			break;
			//s = 115; S = 83; Down arrow = 80
		case 115: case 83: case 80:
			if (!up) {
				down = true;
				left =
				right =
				up = false;
			}
			break;
			//d = 100; D = 68; Right arrow = 77
		case 100: case 68: case 77:
			if (!left) {
				right = true;
				down = 
				left =
				up = false;
			}
			break;
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
		int localX = snake[0].x, localY = snake[0].y;

		if (right && (map[localY][localX + 1] == -1 || map[localY][localX + 1] == 1)) collision = true;
		if (left && (map[localY][localX - 1] == -1 || map[localY][localX - 1] == 1)) collision = true;
		if (up && (map[localY - 1][localX] == -1 || map[localY - 1][localX] == 1)) collision = true;
		if (down && (map[localY + 1][localX] == -1 || map[localY + 1][localX] == 1)) collision = true;
	}
	
	void addLength() {
		snakeCords tail;
		tail.x = lastX;
		tail.y = lastY;
		snake.push_back(tail);
		length++;
	}

	void createSnake(vector<vector<int>>& map) {
		map[y][x] = id;
	}

	bool getCollision() {
		return collision;
	}

	int getId() {
		return id;
	}

	int getLength() {
		return length;
	}
};
