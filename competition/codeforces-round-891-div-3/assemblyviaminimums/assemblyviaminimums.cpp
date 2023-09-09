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
		vector<ll> a(n, INT64_MAX);

		int bSize = (n * (n-1)) / 2;
		map<int, int> unique;
		for (int i=0; i<bSize; i++) {
			int num;
			cin >> num;
			if (unique.count(num)) {
				++unique[num];
			} else {
				unique[num] = 1;
			}
		}

		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> sorted;
		for (pair<int, int> val : unique)
			//sorted.push_back({val.second, val.first});
			sorted.push({val.first, val.second});

	//	sort(sorted.rbegin(), sorted.rend());

		// look through the map, do the smallest first
		int remaining = n;
		while (!sorted.empty()) {
			// get the smallest key
			pair<int, int> top = sorted.top();
			sorted.pop();
			
			int amount = remaining - top.second;
			while (amount < 0) {
				// try and put it in the left most position
				for (int i=0; i<a.size(); i++) {
					if (a[i] == INT64_MAX) {
						// its safe to overwrite
						a[i] = top.first;
						break;
					}
				}
				amount -= remaining;
				remaining--;
			}
		}
	}

    return 0;
}
