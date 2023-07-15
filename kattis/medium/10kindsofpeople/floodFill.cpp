#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

void floodFill(vector<vector<int>> &grid, int x, int y, int area, int type) {
	grid[y][x] = area;

	vector<pair<int, int>> neighbours {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	for (pair<int, int> n : neighbours) {
		int newX = x + n.first;
		int newY = y + n.second;
		// if its out of bounds, don't look
		if (newX < 0 || newX >= grid[0].size()) continue;
		if (newY < 0 || newY >= grid.size()) continue;

		// if it isn't the same type, don't fill
		if (grid[newY][newX] != type) continue;

		floodFill(grid, newX, newY, area, type);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long r, c;
	cin >> r >> c;

	vector<vector<int>> grid(r, vector<int>(c, 0));
	// the next r lines contain c numbers
	// get the grid
	
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			char chr;
			cin >> chr;
			grid[i][j] = chr - '0';
		}
	}

	vector<int> areaTypeMap(2, -1);

	// replace the grid with values representing the area it is in instead
	for (int i=0; i < r; i++) {
		for (int j=0; j < c; j++) {
			if (grid[i][j] < 2) {
				// create a new area
				int newArea = areaTypeMap.size();
				areaTypeMap.push_back(grid[i][j]);
							
				floodFill(grid, j, i, newArea, grid[i][j]);
			}  // if its greater than 2, its already in an area
		}
	}


	long long n;
	cin >> n;

	string words[2] = {"binary", "decimal"};
	// coordinate queries
	while (n--)
	{
		long long r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		c1--;
		r2--;
		c2--;
		// if they aren't in the same area, stop
		if (grid[r1][c1] != grid[r2][c2])
		{
			cout << "neither" << endl;
		}
		else
		{
			int type = areaTypeMap[grid[r1][c1]];
			cout << words[type] << endl;
		}
	}
	return 0;
}
