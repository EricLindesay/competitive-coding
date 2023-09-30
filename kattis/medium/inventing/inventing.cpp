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

		ll sum = 0;

		vector<vector<int>> grid(n, vector<int>(n, -1));
		vector<int> highestWeight(n, 0);
		for (int i=0; i<n-1; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			a--;
			b--;
			grid[a][b] = w;
			grid[b][a] = w;
			sum += w;

			highestWeight[a] = max(highestWeight[a], w);
			highestWeight[b] = max(highestWeight[b], w);
		}

		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (grid[i][j] == -1) {
					grid[i][j] = max(highestWeight[i], highestWeight[j]) + 1;
					grid[j][i] = max(highestWeight[i], highestWeight[j]) + 1;
					sum += max(highestWeight[i], highestWeight[j]) + 1;
				}
			}
		}

		cout << "GRID: "<< endl;
		for (int i=0; i<n; i++) {
			cout << i+1 << "| ";
			for (int j=0; j<n; j++) {
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}

		cout << sum << endl;
	}

    return 0;
}
