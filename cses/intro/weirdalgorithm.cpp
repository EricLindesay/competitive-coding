#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t != 1) {
		cout << t << " ";
		if (t%2 == 0) {
			t /= 2;
		} else {
			t = 3*t + 1;
		}
	}
	cout << t << endl;

    return 0;
}
