#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	while (t--) {
		ll n, k;
		int a;
		cin >> n >> k;
		vector<ll> prefixSum(n+1);
		for (int i=1; i<n+1; i++) {
			cin >> a;
			prefixSum[i] = prefixSum[i-1]+a;
		}

		if (prefixSum[n] <= k) {
			cout << n << endl;
			continue;
		}

		// Go through the prefix sum until you see which ship survives
		// go through the prefix sum in reverse to find the opposite
		ll sunk = 0;
		int update = -1;
		for (int i=0; i<n+1; i++) {
			if (update == 0) {
				break;
			}
			if (update == -1 && prefixSum[i] > k/2+k%2) {
				sunk = i - 1;
				update = k/2+k%2;
				prefixSum[i-1] = 0;
			}
			if (update > 0) {
				prefixSum[i] -= update;
			}
		}
		if (update == -1) {
			// you didn't find a greater one, so you sunk them all
			cout << n << endl;
			continue;
		}
		for (int i=n; i>= 0; i--) {
			if (prefixSum[n] - prefixSum[i] > k/2) {
				sunk += n-i-1;
				break;
			}
		}
		cout << min(n, sunk) << endl;
	}

    return 0;
}
