#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	string prevName = "";
	int order = 0; // ascending, descending or neither
	bool first = true;
	while (t--) {
		string name;
		cin >> name;
		if (first) {
			first = false;
			prevName = name;
			continue;
		}

		if (name < prevName) {
			if (order > 0) {
				// If it was ascending but this name is descending, so it's neither
				order = 0;
				break;
			} else {
				order = -1;
			}
		} else {
			if (order < 0) {
				order = 0;
				break;
			} else {
				order = 1;
			}
		}
		prevName = name;
	}
	if (order == 0) {
		cout << "NEITHER";
	} else if (order < 0) {
		cout << "DECREASING";
	} else if (order > 0) {
		cout << "INCREASING";
	}

    return 0;
}
