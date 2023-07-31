#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int r, e, c;
		cin >> r >> e >> c;
		if (r > e - c) {
			cout << "do not advertise" << endl;
		} else if (r < e - c) {
			cout << "advertise" << endl;
		} else {
			cout << "does not matter" << endl;
		}
	}

    return 0;
}
