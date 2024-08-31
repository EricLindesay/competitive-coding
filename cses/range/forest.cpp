#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

ll viola(vector<vector<ll>> &grid, int x1, int y1, int x2, int y2) {
	// Use the viola-jones thing
	ll area = grid[y2][x2];
		//- grid[y2][x1-1] - grid[y1][x2-1] + grid[y1-1][x1-1];
	if (x1 > 0) {
		area -= grid[y2][x1-1];
		if (y1 > 0) {
			area += grid[y1-1][x1-1];
		}
	}
	if (y1 > 0) {
		area -= grid[y1-1][x2];
	}
	return area;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
	cin >> n >> q;

	vector<vector<ll>> grid(n, vector<ll>(n, 0));
	char c;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> c;
			grid[i][j] = (c == '*');
			if (i > 0) {
				grid[i][j] += grid[i-1][j];
				if (j > 0) {
					grid[i][j] -= grid[i-1][j-1];
				}
			}
			if (j > 0) {
				grid[i][j] += grid[i][j-1];
			}
		}
	}

	int x1, y1, x2, y2;
	while (q--) {
		cin >> y1 >> x1 >> y2 >> x2;
		cout << viola(grid, x1-1, y1-1, x2-1, y2-1) << endl;
	}

    return 0;
}
