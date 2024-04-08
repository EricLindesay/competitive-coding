#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, sm;
    cin >> n >> m;

	sm = m;

	ll time = 0;
	ll t, d;
	vector<pair<int, int>> ns(n);
	while (n--) {
		cin >> t >> d;
		ns.push_back(make_pair(t, d));
		// resets to 0 if it loops the whole way around
		// You can detect a cylce and then do some maths

		if (time > t) {
			continue;
		}
		
		int presses = (t-time+d-1)/d;
		if (m > presses) {
			time += presses*d;
			m -= presses;
		} else if (m == presses) {
			time += presses*d;
			cout << time << endl;
			return 0;
		} else {
			// There is only a limited number of presses you can do
			// Do them
			time += m*d;
			cout << time << endl;
			return 0;
		}
	}

	// The first loop wasn't enough, we need to do atleast one more loop
	// It will loop perfectly again
	m = m%(sm - m);
	if (m == 0) {
		cout << 0 << endl;
		return 0;
	}
	time = 0;
	for (int i=0; i<ns.size(); i++) {
		int t = ns[i].first;
		int d = ns[i].second;
		if (time > t) {
			continue;
		}

		int presses = (t-time+d-1)/d;
		if (m > presses) {
			time += presses*d;
			m -= presses;
		} else if (m == presses) {
			cout << time << endl;
			return 0;
		} else {
			// There is only a limited number of presses you can do
			// Do them
			time += m*d;
			cout << time << endl;
			return 0;
		}
	}

    return 0;
}
