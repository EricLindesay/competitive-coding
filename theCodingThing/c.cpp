#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	ll a, b, c;

	while (t--) {
		cin >> a >> b >> c;

		// Find the difference between the two volumes divide by 2
		// divide that by c
		// ceil
		double diff = abs(a-b)/2.0f;
		cout << ceil(diff/(double) c) << endl;
	}

    return 0;
}
