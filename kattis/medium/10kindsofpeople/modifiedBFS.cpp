#include <iostream>
#include <vector>
#include <string.h>
#include <queue>

using namespace std;

vector<vector<int>> known;

bool bfs(vector<vector<int>> grid, int r1, int c1, int r2, int c2)
{
	queue<pair<int, int>> q;		// a queue storing coordinates
	q.push(pair<int, int>{r1, c1}); // start at the start coordinates

	vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
	visited[r1][c1] = 1;

	while (!q.empty())
	{
		auto [fx, fy] = q.front();
		q.pop();

		if (fx == r2 && fy == c2)
		{ // found goal
			return true;
		}

		// add each adjacent cell to queue
		int adj[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
		for (int k = 0; k < 4; k++)
		{
			int newX = fx + adj[k][0];
			int newY = fy + adj[k][1];
			if (newX < 0 || newX >= grid.size())
				continue; // if out of range, skip
			if (newY < 0 || newY >= grid[0].size())
				continue;
			if (grid[newX][newY] != grid[r1][c1])
				continue; // don't cross borders

			if (!visited[newX][newY])
			{
				visited[newX][newY] = 1;
				q.push(pair<int, int>{newX, newY});
			}
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
	known.resize(r, vector<int>(c, -1));
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
			// have we already calculated this one?
			int type = grid[r1][c1];
			

			if (bfs(grid, r1, c1, r2, c2))
			{
				cout << words[type] << endl;
			}
			else
			{
				cout << "neither" << endl;
			}
		}
	}
	return 0;
}
