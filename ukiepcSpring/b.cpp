#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;
	int a, b, c;
	while (t--) {
		cin >> a >> b >> c;
		if (a == 0 || b == 0 || c >= 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

    return 0;
}
