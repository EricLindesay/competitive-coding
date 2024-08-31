#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
	cin >> t;

	ll x, y;
	ll base, diff;
	while (t--) {
		cin >> y >> x;
		if (x == 1 && y == 1) {
			cout << 1 << endl;
			continue;
		}
		// Choose the greater of x and y. If they are equal, the number is exactly half between 
		// when y=1, x is either an odd square or 1 greater than a square.
		// if x is odd, square it. Otherwise square +1
		if (x >= y) {
			base = (x%2==0) ? ((x-1)*(x-1)+1) : (x*x);
			// if x is odd, subtract y. Otherwise add y.
			diff = (x%2==0) ? y-1 : -(y-1);
		} else {
			// if y is even, square it. Otherwise square +1
			base = (y%2==0) ? (y*y) : ((y-1)*(y-1)+1);
			// if y is even, subtract x. Otherwise add x.
			diff = (y%2==0) ? -(x-1) : x-1;
		}
		ll ans = base+diff;
		cout << ans << endl;
	}

    return 0;
}
