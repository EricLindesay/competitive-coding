#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	vector<ll> dp(t+1, 0);
	dp[0] = 1;
	
	for (int i=1; i<t+1; i++) {
		for (int j = 1; j <= 6 && i-j >= 0; j++) {
		  (dp[i] += dp[i-j]) %= 1000000007;
		}
	}
	cout << dp[t] << endl;

    return 0;
}
