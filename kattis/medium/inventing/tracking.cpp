#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<vector<int>> grid(n, vector<int>(n, 0));
		for (int i=0; i<n-1; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			a--;
			b--;
			grid[a][b] = w;
			grid[b][a] = w;

			int newWeight = -1 * (w + 1);
			for (int i=0; i<n; i++) {
				if (grid[b][i] > 0) 
					continue;  // its positive so we got given it
				
				grid[b][i] = min(grid[b][i], newWeight);
				grid[i][b] = min(grid[i][b], newWeight);
			}
		}

		ll sum = 0;
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) { 
				sum += abs(grid[i][j]);
			}
		}

		cout << sum << endl;
	}

    return 0;
}
