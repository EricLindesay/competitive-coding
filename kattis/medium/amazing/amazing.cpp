#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>

typedef long long ll;

using namespace std;

#define UP 0
#define LEFT 1
#define DOWN 2
#define RIGHT 3
#define WALL 1
#define EMPTY 0

string text[4] {"up", "left", "down", "right"};
int opposite[4] {DOWN, RIGHT, UP, LEFT};

class Cell {
public:
	bool isWall(int direction) {
		return wall[direction] == 1;
	}

	void set(int direction, int thing) {
		wall[direction] = thing;
	}

	void mark() {
		marked++;
	}

	void tried(int dir) {
		left[dir] = 1;
	}

	int hasTried(int dir) {
		return left[dir];
	}

	vector<int> wall {-1, -1, -1, -1};  // -1 = unknown, 0 = no wall, 1 = wall
	vector<int> left {0, 0, 0, 0};  // -1 = unknown, 0 = no wall, 1 = wall
	int marked = 0;
};

// the maze is at most 100 x 100
vector<vector<Cell>> maze(220, vector<Cell>(220));

int tryDirection(int x, int y, int dir, int dirOpp, int dx, int dy) {
	string result;
	cout << text[dir] << endl;
	cin >> result;
	if (result == "wall") {
		maze[x][y].set(dir, WALL);
		maze[x+dx][y+dy].set(dirOpp, WALL);
	} else if (result == "ok") {
		maze[x][y].set(dir, EMPTY);
		maze[x+dx][y+dy].set(dirOpp, EMPTY);
		// move back down to the previous cell
		cout << text[dirOpp] << endl;
		cin >> result;
	} else {  // it is solved or wrong, so just stop
		return 1;
	}
	return 0;
}

int move(int &x, int &y, int dir, int dirOpp, int dx, int dy) {
	string result;
	cout << text[dir] << endl;
	cin >> result;
	maze[x][y].tried(dir);
	if (result == "wall") {
		maze[x][y].set(dir, WALL);
		maze[x+dx][y+dy].set(dirOpp, WALL);
		return 1;
	} else if (result == "ok") {
		maze[x][y].set(dir, EMPTY);
		maze[x+dx][y+dy].set(dirOpp, EMPTY);
		x += dx;
		y += dy;
		return 0;
	} else {  // it is solved or wrong, so just stop
		return 2;
	}
}

int mapCell(int x, int y) {
	int res = 0;
	res += tryDirection(x, y, UP, DOWN, 0, -1);
	res += tryDirection(x, y, DOWN, UP, 0, 1);
	res += tryDirection(x, y, RIGHT, LEFT, 1, 0);
	res += tryDirection(x, y, LEFT, RIGHT, -1, 0);
	return res;
}

int main() {
	// start in the middle of the maze
	int x = 110;
	int y = 110;
	
	string result;
	stack<int> movement;
	int lastMovement = LEFT;
	pair<int, int> changes[] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
	int dirs[] = {UP, LEFT, DOWN, RIGHT};

	bool end = false;
	while (!end) {
		// try and move in a direction
		int order[4];
		int orderIndex = 0;
		for (int i=0; i<4; i++) {
			if (dirs[i] != opposite[lastMovement]) {
				order[orderIndex++] = dirs[i];
			}
		}
		order[3] = opposite[lastMovement];

		for (int dir : order) {
			if (!maze[x][y].hasTried(dir)) {  // try moving up
				int moveResult = move(x, y, dir, opposite[dir], changes[dir].first, changes[dir].second);
				if (moveResult == 2) { // it is now solved or wrong
					end = true;
					break;
				} else if (moveResult == 0) {  // you successfully moved
					lastMovement = dir;
					break;
				}
			}
		}
	}

    return 0;
}
