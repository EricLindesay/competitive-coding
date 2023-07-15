#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

bool isValid(int rows, int cols, int x, int y) {
	if (x < 0 || x >= cols)
		return false;
	if (y < 0 || y >= rows)
		return false;
	return true;
}

bool astar(vector<vector<int>> grid, int r1, int c1, int r2, int c2)
{
	priority_queue<pair<int, int>> openCells;  // stores the coordinates of un-visited cells
	vector<vector<int>> gScore(grid.size(), vector<int>(grid[0].size(), INT32_MAX));
	vector<vector<int>> fScore(grid.size(), vector<int>(grid[0].size(), INT32_MAX)); 

	while (!openCells.empty()) {
		pair<int, int> current = openCells.top();
		openCells.pop();

		if (current.first == r2 && current.second == c2) {
			return true;
		}

		vector<pair<int, int>> neighbours {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		for (pair<int, int> neighbour : neighbours) {
			int newX = current.first + neighbour.first;
			int newY = current.second + neighbour.second;
			if (!isValid(grid.size(), grid[0].size(), newX, newY))
				continue;

			temp = gScore[current.second][current.first] + 1;
		}
	}

	return false;
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

	long long n;
	cin >> n;

	string words[2] = {"binary", "decimal"};
	// coordinate queries
	for (int i = 0; i < n; i++)
	{
		long long r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		r1--;
		c1--;
		r2--;
		c2--;
		if (grid[r1][c1] != grid[r2][c2])
		{
			cout << "neither" << endl;
		}
		else
		{
			if (astar(grid, r1, c1, r2, c2))
			{
				cout << words[grid[r1][c1]] << endl;
			}
			else
			{
				cout << "neither" << endl;
			}
		}
	}
	return 0;
}
