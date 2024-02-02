#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		vector<int> times(26, 0);
		ll n;
		string m;
		cin >> n >> m;
		for (char c : m) {
			times[c-'A']++;
		}
		int ans = 0;
		for (int i=0; i<times.size(); i++) {
			if (times[i] >= i+1) {
				ans++;
			}
		}
		cout << ans << endl;
	}

    return 0;
}
