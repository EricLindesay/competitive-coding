#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

	vector<pair<int, int>> coords(n);
	for (int i=0; i<n; i++) {
		int qr, qc;
		cin >> qr >> qc;
		coords[i] = make_pair(qr, qc);
	}

	for (int i=0; i<n; i++) {
		pair<int, int> iq = coords[i];
		for (int j=0; j<n; j++) {
			if (i == j) {
				continue;
			}
			pair<int, int> jq = coords[j];
			// check horizontal and vertical
			if (iq.first == jq.first || iq.second == jq.second) {
				cout << "INCORRECT";
				return 0;
			}
			// check diagonal
			// see if the gradient between the points is 1
			if ((double) abs(iq.second - jq.second) / abs(iq.first - jq.first) == 1) {
				// they are on the same diagonal
				cout << "INCORRECT";
				return 0;
			}
		}
	}
	cout << "CORRECT";

    return 0;
}
