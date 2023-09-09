#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int k, c;
		cin >> k >> c;
		// find some N candies such that (N*C) % K == 1
		// if you find a loop, its impossible
		map<int, bool> seen;

		int n = k/c;
		while (true) {
			int calc = (n * c) % k;
			if (calc == 1) {
				cout << n << endl;
				break;
			} else {
				if (seen.count(calc)) {
					// you are in a loop so its impossible
					cout << "IMPOSSIBLE" << endl;
					break;
				} else {
					seen[calc] = true;
				}
			}
			n++;
		}
	}

    return 0;
}
