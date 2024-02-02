#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	int xh, yh, xw, yw;
	cin >> xh >> yh >> xw >> yw;

	int xp, yp;
	vector<vector<int>> points;
	while (t--) {
		cin >> xp >> yp;

		if (xp > max(xw, xh) || xp < min(xw, xh) || yp > max(yw, yh) || yp < min(yw, yh)) {
			// Don't include the point if its out of the range because it will never ever get visited
			continue;
		}
	}

    return 0;
}
