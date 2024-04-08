#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;
	string s;
    cin >> t;
	while (t--) {
		cin >> n >> s;
		vector<int> prefixSum(n+1);
		prefixSum[0] = 0;
		for (int i=0; i<n; i++) {
			prefixSum[i+1] = prefixSum[i] + s[i] - '0';
		}
		int position = -1;
		for (int i=0; i<=n; i++) {
			// Make sure there are atleast ceil(i/2) zeros to the left
			// and atelaeast ceil(n-i/2) ones to the right
			if (i - prefixSum[i] >= (i+1)/2 && prefixSum[n] - prefixSum[i] >= (n-i+1)/2) {
				if (abs(n/2.0f - i) < abs(n/2.0f - position)) {
					position = i;
				}
			}
		}
		cout << position << endl;
	}

    return 0;
}
