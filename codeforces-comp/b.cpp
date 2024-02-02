#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		// He needs to get excited K times.
		vector<int> out(n);
		for (int i=0; i<n; i++) {
			out[i] = n-i;
		}

		for (int i=0; i<n; i++) {
			if (i%(n/k) == 0) {
				// swap this and prev
				if (i == n-1) {
					// Loop around
					int t = out[0];
					out[0] = out[n-1];
					out[n-1] = t;
				} else {
					int t = out[i];
					out[i] = out[i+1];
					out[i+1] = t;
				}
			}
		}

		for (int c : out) {
			cout << c << " ";
		}
		cout << endl;
	}

    return 0;
}
