#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
	cin >> n;

	if (n >= 1) {
		cout << 0 << endl;
	}
	if (n >= 2) {
		cout << 6 << endl;
	}

	ll ans = 0;
	for (int i=3; i<=n; i++) {
		int j = i*i;
		if (j%2) {
			ans = j/2 * (j-1);
		} else {
			ans = j * (j-1)/2;
		}
		// For all 3x2 sections, reduce the number by two
		
		cout << ans << endl;
	}

    return 0;
}
