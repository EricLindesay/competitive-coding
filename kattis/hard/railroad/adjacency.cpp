#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;


	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<int>> grid(n, vector<int>(n, -1));
		vector<int> sizes(n, 0);
		// vector of nodes with their initialiser list. Node : weight
		
		int segments = m;
		
		while (m--) {
			int a, b, w;
			cin >> a >> b >> w;
			a--; b--;

			grid[a][b] = w;
			grid[b][a] = w;
			sizes[a]++;
			sizes[b]++;
		}
		
		bool change = true;
		while (change) {
			change = false;
			// loop through the nodes and remove any dobles.
			for (int i=0; i<n; i++) {
				if (sizes[i] == 2) {
					cout << "Node " << i << " has size of 2" << endl;
					change = true;

					// We need to remove this node
					// Look at the two connections between this node
					vector<pair<int, int>> connections;
					for (int j=i+1; j<n; j++) {
						if (grid[i][j] != -1) {
							// This is one we have to remove
							// j is the other node
							connections.push_back({j, grid[i][j]});
							grid[i][j] = -1;
							grid[j][i] = -1;
							sizes[i]--;
						}
					}

					// for first connection set the weight to the second connection as the sum of the weights
					grid[connections[0].first][connections[1].first] = connections[0].second + connections[1].second;
					grid[connections[1].first][connections[0].first] = connections[0].second + connections[1].second;

					segments--;
				}
			}
		}

		cout << segments << endl;
		for (int i=0; i<n; i++) {
			if (sizes[i] == 0) 
				continue;

			for (int j=i+1; j<n; j++) {
				if (grid[i][j] == -1) 
					continue;
				cout << i+1 << " " << j+1 << " " << grid[i][j] << endl;
			}
		}
		cout << endl;
	}

    return 0;
}
