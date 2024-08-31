#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		cout << n/2*min(2*a, b) + n%2*a << endl;
	}

    return 0;
}
