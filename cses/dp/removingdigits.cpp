#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	vector<int> dp(t+1, -1);
	dp[t] = 0;

	for (int i=t; i>=0; i--) {
		if (dp[i] == -1) continue;
		// Subtract the digits one by one and set the dp[] values
		int copy = i;
		int digit = 0;
		while (copy > 0) {
			digit = copy%10;
			copy /= 10;

			if (dp[i-digit] == -1) {
				dp[i-digit] = dp[i]+1;
			} else {
				dp[i-digit] = min(dp[i-digit], dp[i]+1);
			}
		}
	}

	cout << dp[0];

    return 0;
}
