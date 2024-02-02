#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, m;
	cin >> n;

	vector<pair<int, int>> collapsed;
	int collapse_num = 0;
	int num_collapse = 0;
	for (int i = 0; i<n; i++) {
		int num;
		cin >> num;
		if (collapse_num != 0 && collapse_num != num) {
			// add this number to the collpase pairs
			collapsed.push_back(make_pair(collapse_num, num_collapse));
			num_collapse = 0;
		} 
		collapse_num = num;
		num_collapse++;
	}
	collapsed.push_back(make_pair(collapse_num, num_collapse));

	cin >> m;
	while (m > 0) {
		m--;

		string cmd;
		cin >> cmd;

		if (cmd == "check") {
			int l, u;
			cin >> l >> u;
			l--;
			u--;
			// See if the local minima are increasing
			vector<int> local_minima;
			bool decreasing = true;
			for (int i=l+1; i<=u; i++) {
				if (decreasing && uids[i] > uids[i-1]) {
					decreasing = false;
					local_minima.push_back(uids[i-1]);
				} else {
					decreasing = true;
				}
			}
			if (decreasing) {
				local_minima.push_back(uids[uids.size() - 1]);
			}

			// Is the local minima array increasing
			bool valid = true;
			for (int i=1; i<local_minima.size(); i++) {
				if (local_minima[i-1] >= local_minima[i]) {
					valid = false;
				}
			}
			if (valid) {
				cout << "YES" << endl;
			} else {
				cout << "NO" << endl;
			}
		} else if (cmd == "update") {
			int l, u, a;
			cin >> l >> u >> a;
			// Update between l and u inclusive
			l--;
			u--;
			for (int i = l; i <= u; i++) {
				uids[i] += a;
			}
		}
	}

    return 0;
}
