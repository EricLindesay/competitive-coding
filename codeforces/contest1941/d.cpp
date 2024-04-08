#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int pymod(int a, int m) {
	return (((a % m) + m) % m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		cache.clear();
		int n, m, x;
		cin >> n >> m >> x;
		x--;
		vector<pair<int, char>> order(m);
		
		set<int> holdings = {x};
		set<int> newHoldings;

		int dist;
		char dir;
		for (int i=0; i<m; i++) {
			cin >> dist >> dir;
			for (int i: holdings) {
				switch (dir) {
					case '0':
						newHoldings.emplace(pymod(i+dist, n));
						break;
					case '1':
						newHoldings.emplace(pymod(i-dist, n));
						break;
					case '?':
						newHoldings.emplace(pymod(i+dist, n));
						newHoldings.emplace(pymod(i-dist, n));
						break;
				}
			}
			holdings = newHoldings;
			newHoldings.clear();
		}
		cout << holdings.size() << '\n';
		for (int i : holdings) {
			cout << i+1 << ' ';
		}
		cout << endl;
	}

    return 0;
}
