#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
	int a, b, c;
	int tents;
    cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		tents = a;
		a = 0;
		tents += b/3;
		b %= 3;
		if (b > 0) {
			if (c >= 3 - b) {
				// Fill in the remaining extrovert tent with universals
				tents++;
				c -= 3 - b;
				b = 0;
			} else {
				cout << -1 << endl;
				continue;
			}
		}
		tents += ceil(((double) c)/3.0f);
		cout << tents << endl;
	}

    return 0;
}
