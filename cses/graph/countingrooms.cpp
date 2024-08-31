#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

void floodFill(vector<string> &grid, int i, int j) {
	if (i < 0 || i >= grid.size()) return;
	if (j < 0 || j >= grid[0].size()) return;
	if (grid[i][j] == '#') return;

	grid[i].replace(j, 1, "#");
	
	floodFill(grid, i+1, j);
	floodFill(grid, i-1, j);
	floodFill(grid, i, j+1);
	floodFill(grid, i, j-1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	vector<string> grid(n);
	for (string &s: grid) {
		cin >> s;
	}

	queue<pair<int, int>> ffq;
	int rooms = 0;
	vector<pair<int, int>> neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] == '#') continue;

			// Otherwise, flood fill the empty space with walls and increment rooms
			rooms++;
			ffq.push(make_pair(i, j));
			while (!ffq.empty()) {
				pair<int, int> p = ffq.front();
				ffq.pop();
				if (grid[p.first][p.second] == '#') 
					continue;
				grid[p.first][p.second] = '#';
				for (pair<int, int> &n : neighbours) {
					int newi = p.first+n.first;
					int newj = p.second+n.second;
					if (newi < 0 || newi >= grid.size()) continue;
					if (newj < 0 || newj >= grid[0].size()) continue;
					if (grid[newi][newj] == '#') continue;
					ffq.push(make_pair(newi, newj));
				}
			}
		}
	}
	cout << rooms << endl;

    return 0;
}
