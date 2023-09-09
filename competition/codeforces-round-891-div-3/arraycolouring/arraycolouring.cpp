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

		int num_odds = 0;
		while (n--) {
			int num;
			cin >> num;

			// if its even ignore it
			if (num%2) {
				++num_odds;
			}
		}
		cout << ((num_odds%2) ? "NO" : "YES") << endl;
	}

    return 0;
}
