#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	ll a, b;
	while (t--) {
		cin >> a >> b;
		// each screen has 2 2x2s
		// if screens have 2 2x2s, they can have 7 others
		int screens = (b+1)/2;
		a -= screens*7;
		if (b%2) {
			a -= 4;
		}
		a = max(a, 0ll);
		cout << screens + (a+14)/15 << endl;
	}
    return 0;
}
