#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// contest/1968/problem/B
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> mat(m, vector<int>(n));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> mat[j][i];
			}
		}

		// Go through each element in the thing, one by one.
		// Set it to the greatest neighbour (if all neighbours are greater)
		vector<pair<int, int>> neighbours = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				bool allLess = true;
				int highest = INT_MIN;
				for (pair<int, int> ne: neighbours) {
					int newX = i + ne.first;
					int newY = j + ne.second;
					if (newX < 0 || newX >= n || newY < 0 || newY >= m) {
						continue;
					}
					if (mat[newY][newX] >= mat[j][i]) {
						allLess = false;
						break;
					}
					highest = max(highest, mat[newY][newX]);
				}
				if (allLess) {
					// set this to the minimum of the others
					mat[j][i] = highest;
				}
			}
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cout << mat[j][i] << " ";
			}
			cout << endl;
		}
	}

    return 0;
}
