#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	long double a, b, c;
	while (t--) {
		cin >> a >> b >> c;
		long double val;
		char dol;
		while (a--) {
			cin >> val >> dol;
			if (b <= 0) continue;

			long double diff = ceil(val/c);
			b -= diff*c - val;
		}
		if (b <= 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

    return 0;
}
