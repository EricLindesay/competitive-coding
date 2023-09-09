#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

	int n, k;
	int b = 0;

	for (int c=1; c<=t; c++) {
		cin >> n >> k;
		// First, mod the number 2^n. This is just to stop wrap arounds
		int maxSnaps = 1 << n;
		k = k % maxSnaps;

		// Then, if the number is 111111 in binary, it should be accepted
		// So if it is the wrap around number - 1 it shoulbe accepted
		cout << "Case #" << c << ": ";
		if (k == maxSnaps - 1) {
			cout << "ON" << endl;
		} else {
			cout << "OFF" << endl;
		}
	}

    return 0;
}
