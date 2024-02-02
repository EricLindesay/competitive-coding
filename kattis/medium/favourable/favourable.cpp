#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

typedef long long ll;

using namespace std;

vector<string> split(string s, char c) {
	std::stringstream test(s);
	std::string segment;
	std::vector<std::string> seglist;

	while(std::getline(test, segment, c)) {
		seglist.push_back(segment);
	}
	return seglist;
}

map<int, ll> cache;
ll numRoutes(map<int, vector<int>> &routes, map<int, string> &results, int node) {
	if (cache.count(node)) {
		return cache[node];
	}
	if (results.count(node)) {
		ll ans = (results[node][0] == 'f');
		cache[node] = ans;
		return ans;
	}
	
	ll ans = 0;
	for (int r : routes[node]) {
		ans += numRoutes(routes, results, r);
	}
	cache[node] = ans;
	return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	string line;
	getline(cin, line);
	ll t = stoi(line);

	map<int, vector<int>> route;
	map<int, string> results;

	while (t--) {
		getline(cin, line);
		ll s = stoi(line);
		string info;
		route.clear();
		results.clear();
		while (s--) {
			getline(cin, info);
			if (info[info.size() - 1] == 'y') {
				// Split it into two
				vector<string> q = split(info, ' ');
				results[stoi(q[0])] = q[1];
			} else {
				// Split it into four
				vector<string> q = split(info, ' ');
				int r = stoi(q[0]);
				for (int i=1; i<4; i++) {
					route[r].push_back(stoi(q[i]));
				}
			}
		}

		cache.clear();
		cout << numRoutes(route, results, 1) << '\n';
	}

    return 0;
}
