#include <iostream>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;
		int cuts = 0;
		while (n--) {
			int a, b;
			cin >> a >> b;
			// find the distance to the ground. If that distance is > 0, increment
			if (a > b)
				cuts++;
		}
		cout << cuts << "\n";
	}

    return 0;
}
