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
		map<ll, ll> hashing;
		vector<ll> points(n);
		for (ll &point : points)
			cin >> point;

		for (int i=0; i<n; i++) {
			ll s = points[i];
			if (hashing.count(s)) {  // if we have already done a point with the same value, don't do it again
				cout << hashing[s] << " ";
				continue;
			}
			ll sum = 0;
			for (int j=0; j<n; j++)
				sum += abs(points[j] - s) + 1;
			hashing[s] = sum;
			cout << sum << " ";
		}
		cout << endl;
		// find the sum of the distnace between points[i] and s (inclusive) 
	}

    return 0;
}
