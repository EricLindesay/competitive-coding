#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;

		int num;
		int expected = 1;
		int wrong_order = 0;
		while (n--) {
			cin >> num;
			if (num != expected) {
				wrong_order++;
			} else {
				expected++;
			}
		}
		cout << wrong_order << endl;
	}

    return 0;
}
