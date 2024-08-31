#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	
	ll n, m;
	string a, b;
	while (t--) {
		cin >> n >> m >> a >> b;

		int pb = 0;
		ll k = -1;
		for (int i=0; i<n; i++) {
			// increment pb until you get to the same character
			while (b[pb] != a[i]) {
				pb++;
				if (pb >= m)
					break;
			}
			if (pb >= m || b[pb] != a[i]) {
				break;
			}
			k = i;
			pb++;
			if (pb >= m) {
				break;
			}
		}
		cout << k+1 << endl;
	}

    return 0;
}
