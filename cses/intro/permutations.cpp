#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	if (t == 1) {
		cout << "1" << endl;
		return 0;
	}
	if (t < 4) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	if (t == 4) {
		cout << "3 1 4 2" << endl;
		return 0;
	}

	for (int i=1; i<=t; i+=2) {
		cout << i << " ";
	}
	for (int i=2; i<=t; i+=2) {
		cout << i << " ";
	}

    return 0;
}
