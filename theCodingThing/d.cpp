#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	int n;
	int a, b;
	while (t--) {
		cin >> n;
		int cuts = 0;
		while (n--) {
			cin >> a >> b;
			if (a-b > 0) {
				cuts++;
			}
		}
		cout << cuts << endl;
	}

    return 0;
}
