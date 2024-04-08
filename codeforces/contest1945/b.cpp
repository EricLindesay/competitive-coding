#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	ll a, b, m;
	while (t--) {
		cin >> a >> b >> m;
		cout << m/a + m/b + 2 << endl;
	}

    return 0;
}
