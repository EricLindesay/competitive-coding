#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, t;
	cin >> n >> t;
	vector<int> rs(n);
	priority_queue<pair<int, int>> ps;

	for (int i=0; i<n; i++) {
		cin >> rs[i];
	}
	int f=0;
	for (int i=0; i<n; i++) {
		cin >> f;
		ps.push(make_pair(rs[i], f));
	}

	ll ans = 0;
	if (n == 1) {
		if (ps.top().second == 0) {
			cout << ps.top().first * t << endl;
		} else {
			ll time = (ps.top().first + ps.top().second - 1) / ps.top().second;
			ll m = min(time, t);
			ans = ps.top().first*m - ps.top().second*0.5*m*(m-1);
			cout << ans << endl;
		}
		return 0;
	}

	while (t > 0) {
		// Look at the 0'th and 1'st
		// Look at how long it is worth it to stick with the i'th
		if (ps.top().first == 0) {
			break;
		}
		if (ps.top().second == 0) {
			ans += ps.top().first*t;
			break;
		}
		
		pair<int, int> pqt = ps.top();
		ps.pop();
		ll time = (pqt.first - ps.top().first + pqt.second - 1)/pqt.second;
		if (time >= t) {
			// Use up all the time you can on this
			ll inc = pqt.first*t - pqt.second*0.5*t*(t-1);
			ans += inc;
			break;
		} else {
			if (time == 0) {
				time = 1;
			}
			ll inc = pqt.first*time - pqt.second*0.5*time*(time-1);
			ans += inc;
			pqt.first = max(pqt.first-pqt.second*time, 0ll);
			ps.push(pqt);
			t -= time;
		}
	}
	cout << ans << endl;

    return 0;
}
