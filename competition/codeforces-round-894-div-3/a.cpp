#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	string name = "vika";
	while (t--) {
		int n, m;
		cin >> n >> m;
		
		vector<vector<char>> grid(n, vector<char>(m));
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> grid[i][j];
			}
		}

		if (m < 4) {
			cout << "NO" << endl;
			continue;
		}

		int index = 0;
		bool stop = false;
		for (int j=0; j<m; j++) { // read through columns
			for (int i=0; i<n; i++) {
				if (grid[i][j] == name[index]) {
					index++;
					if (index == 4) {
						stop = true;
					}
					break;
				}
			}
			if (stop) {
				break;
			}
		}

		if (index == 4 || stop) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

    return 0;
}
