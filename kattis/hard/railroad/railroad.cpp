#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int get_index(vector<pair<int, int>> &edgeList, int target) {
	// get the index of the target thingy in the edge list
	for (int i=0; i<edgeList.size(); i++) {
		if (edgeList[i].first == target) {
			return i;
		}
	}
	return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;


	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vector<pair<int, int>>> nodes(n);
		vector<int> sizes(n, 0);
		// vector of nodes with their initialiser list. Node : weight
		
		int segments = m;
		
		while (m--) {
			int a, b, w;
			cin >> a >> b >> w;
			a--; b--;

			if (a != b) {
				nodes[a].push_back({b, w});
				nodes[b].push_back({a, w});
				sizes[a]++;
				sizes[b]++;
			} else { // the node is connecting with itself
				nodes[a].push_back({b, w});
				sizes[a]++;
			}
		}

		bool change = true;
		while (change) {
			change = false;
			// loop through the nodes and remove any dobles.
			for (int i=0; i<n; i++) {
				if (sizes[i] == 2) {
					change = true;

					// We need to remove this node
					// Look at the two connections between this node
					pair<int, int> node1 = nodes[i][0];
					pair<int, int> node2 = nodes[i][1];

					int newWeight = node1.second + node2.second;

					// remove connection from node1 to current node
					// find the connection
					if (node1.first != node2.first) {
						int index1 = get_index(nodes[node1.first], i);
						nodes[node1.first].erase(nodes[node1.first].begin() + index1);
						int index2 = get_index(nodes[node2.first], i);
						nodes[node2.first].erase(nodes[node2.first].begin() + index2);
	
						nodes[node1.first].push_back({node2.first, newWeight});
						nodes[node2.first].push_back({node1.first, newWeight});
					} else {
						int index1 = get_index(nodes[node1.first], i);
						nodes[node1.first].erase(nodes[node1.first].begin() + index1);
						int index2 = get_index(nodes[node2.first], i);
						nodes[node2.first].erase(nodes[node2.first].begin() + index2);
	
						nodes[node1.first].push_back({node2.first, newWeight});
						sizes[node1.first] -= 2;
					}

					sizes[i] = 0;
					segments--;

					// Remove the two nodes from the current list
					nodes[i].clear();
				}
			}
		}

		cout << segments << endl;
		for (int i=0; i<n; i++) {
			if (nodes[i].size() == 0) 
				continue;

			for (pair<int, int> &p : nodes[i]) {
				if (p.first < i) 
					continue; // it has already been printed

				cout << i+1 << " " << p.first+1 << " " << p.second << endl;
			}
		}
		cout << endl;
	}

    return 0;
}
