#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<ll, ll> cache;
int rec(vector<pii> &cs, int day, int m, int h) {
	if (day >= cs.size()) {
		return h;
	}
	if (cache.count(day*50 + h*1000000)) {
		return cache[day*50 + h*1000000];
	}
	// Each time he can choose to buy here or not if he has enough money
	for (int i=day; i<cs.size(); i++) {
		if (cs[i].first == 0) {
			h += cs[i].second;
			continue;
		}
		if (cs[i].first <= m) {
			int val = max(rec(cs, i+1, m-cs[i].first, h+cs[i].second), 
						rec(cs, i+1, m, h));
			cache[day*50+h*1000000] = val;
			return val;
		}
	}
	cache[day*50+h*1000000] = h;
	return h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	int m, x, c, h;
	while (t--) {
		cin >> m >> x;
		vector<pair<int, int>> cs;
		for (int i=0; i<m; i++) {
			cin >> c >> h;
			cs.push_back(make_pair(c, h));
		}

		cout << rec(cs, 0, 0, 0) << endl;
		for (pair<ll, ll> c : cache) {
			cout << c.first << " " << c.second << endl;
		}
		cout << "---" << endl;
	}

    return 0;
}
