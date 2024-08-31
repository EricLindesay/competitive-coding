#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n, prev;
    cin >> t;
	cin >> prev;
	ll ans = 0;
	t--;

	while (t--) {
		cin >> n;
		ans += max(prev-n, 0ll);
		prev = max(prev, n);
	}

	cout << ans;
    return 0;
}
