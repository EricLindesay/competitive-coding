#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int a, b, c;
	cin >> a >> b >> c;

	int out = 0;
	if (c < 2) {
		out = (a * 2);
	} else {
		if (b != 0) {
			out = (a*2) + (b * 2) + 3 + ((c - 2)/2 * 3);
		} else {
			out = (a * 2) + (c/2 * 3);
		}
	}
	cout << out;

    return 0;
}
