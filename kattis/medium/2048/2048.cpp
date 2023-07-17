#include <iostream>
#include <vector>
#include <cmath>
#include <string>

typedef long long ll;

using namespace std;

void move_down(vector<vector<int>> &grid) {
	// start in the bottom row, looking at the next columns to see if they can merge in
	for (int x=0; x<4; x++) {
		int y = 3;
		int max = 3;
		while (y > 0) {
			if (grid[y][x] == grid[y-1][x] && grid[y][x] != 0)	{
				grid[y][x] = grid[y][x] * 2;
				grid[y-1][x] = 0;
				max = y-1;
			}
			if (grid[y][x] == 0 && grid[y-1][x]) {
				grid[y][x] = grid[y-1][x];
				grid[y-1][x] = 0;
				y = max;
				continue;
			}
			y--;
		}
	}
}

void move_up(vector<vector<int>> &grid) {
	// start in the top column, looking at the next columns to see if they can merge in
	for (int x=0; x<4; x++) {
		int y = 0;
		int min = 0;
		while (y < 3) {
			if (grid[y][x] == grid[y+1][x] && grid[y][x] != 0)	{
				grid[y][x] = grid[y][x] * 2;
				grid[y+1][x] = 0;
				min = y+1;
			}
			if (grid[y][x] == 0 && grid[y+1][x]) {
				grid[y][x] = grid[y+1][x];
				grid[y+1][x] = 0;
				y = min;
				continue;
			}
			y++;
		}
	}
}

void move_right(vector<vector<int>> &grid) {
	// start in the left most column, looking at the next columns to see if they can merge in
	for (int y=0; y<4; y++) {
		int x = 3;
		int max = 3;
		while (x > 0) {
			bool something = false;
			if (grid[y][x] == grid[y][x-1] && grid[y][x] != 0)	{
				grid[y][x] = grid[y][x] * 2;
				grid[y][x-1] = 0;
				max = x-1;
			}
			if (grid[y][x] == 0 && grid[y][x-1]) {
				grid[y][x] = grid[y][x-1];
				grid[y][x-1] = 0;
				x = max;
				continue;
			}
			x--;
		}
	}
}

void move_left(vector<vector<int>> &grid) {
	// start in the left most column, looking at the next columns to see if they can merge in
	for (int y=0; y<4; y++) {
		int x = 0;
		int min = 0;
		while (x < 3) {
			if (grid[y][x] == grid[y][x+1] && grid[y][x] != 0)	{
				grid[y][x] = grid[y][x] * 2;
				grid[y][x+1] = 0;
				min = x+1;
			}
			if (grid[y][x] == 0 && grid[y][x+1]) {
				grid[y][x] = grid[y][x+1];
				grid[y][x+1] = 0;
				x = min;
				continue;
			}
			x++;
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	vector<vector<int>> grid(4, vector<int>(4));

	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			cin >> grid[i][j];
		}
	}

	int user;
	cin >> user;
	switch (user) {
		case 0:
			move_left(grid);
			break;
		case 1:
			move_up(grid);
			break;
		case 2:
			move_right(grid);
			break;
		case 3:
			move_down(grid);
			break;
	}

	// print the new grid state
	for (int i=0; i<4; i++) {
		for (int j=0; j<4; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

    return 0;
}
