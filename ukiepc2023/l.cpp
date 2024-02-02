#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	double h1, h2, d1, d2, t1, t2;
	cin >> h1 >> d1 >> t1 >> h2 >> d2 >> t2;

	ll u1 = ceil((h2-d1) / (d1)) * t1;
	ll u2 = ceil((h1-d2) / (d2)) * t2;

	if (u1 < u2) {
		cout << "player one";
	} else if (u2 < u1) {
		cout << "player two";
	} else {
		cout << "draw";
	}
    return 0;
}
