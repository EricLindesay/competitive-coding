#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	
	int x;
	ll out;
	ll best;
	while (t--) {
		cin >> x;
		out = 0;
		best = 0;
		for (int i=1; i<x; i++) {
			int g = __gcd(x, i)+i;
			if (g > best) {
				best = g;
				out = i;
			}
			
		}
		cout << out << endl;
	}

    return 0;
}
