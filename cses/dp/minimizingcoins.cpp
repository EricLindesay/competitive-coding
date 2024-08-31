#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    cin >> n >> t;
	vector<ll> coins(n);
	for (ll &i : coins) {
		cin >> i;
	}
	vector<ll> dp(t+1, INT_MAX);  // how many coins does it take to get to the current coin sum?
	dp[0] = 0;
	
	for (int i=0; i<coins.size(); i++) {
		ll coin = coins[i];
		for (int j=0; j<dp.size(); j++) {
			ll newIndex = coin + j;
			if (dp[j] == INT_MAX) 
				continue;
			if (newIndex >= dp.size())
				break;
			
			dp[newIndex] = min(dp[newIndex], dp[j]+1);
		}
	}
	if (dp[dp.size()-1] == INT_MAX) {
		cout << -1 << endl;
	} else {
		cout << dp[dp.size()-1] << endl;
	}

    return 0;
}
