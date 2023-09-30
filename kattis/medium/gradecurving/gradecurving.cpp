#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	double x, low, high;
	cin >> x >> low >> high;

	int hAns = -1;
	int lAns = -1;
	int count = 1;

	if (x == low) {
		lAns = 0;
		if (high == 100) { 
			hAns = INT_MAX;
		}
	}

	while (hAns == -1) {
		x = 10 * sqrt(x);
		ll tx = ceil(x);
		if (tx >= low && lAns == -1) {
			lAns = count;
			if (high == 100) {
				hAns = INT_MAX;
				break;
			}
		}
		if (tx > high) {
			hAns = count - 1;
			break;
		}
		count++;
	}

	if (hAns < lAns) {
		cout << "impossible";
		return 0;
	}
	
	if (lAns == INT_MAX) {
		cout << "inf";
	} else {
		cout << lAns;
	}
	cout << " ";

	if (hAns == INT_MAX) {
		cout << "inf";
	} else {
		cout << hAns;
	}

    return 0;
}
