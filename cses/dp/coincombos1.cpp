#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int mod = 1e9+7;

	int n, t;
	cin >> n >> t;
	vector<int> coins(n);
	for (int &i: coins) {
		cin >> i;
	}

	vector<int> dp(t+1,0);
	dp[0] = 1;
	for (int i = 1; i < t+1; i++) {
		for (int &c: coins) {
			if (i-c >= 0) {
				dp[i] += dp[i-c];
				dp[i] %= mod;
			}
		}
	}
	cout << dp[t] << endl;

    return 0;
}
