#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	int n, c, d;
	while (t--) {
		cin >> n >> c >> d;
		/*vector<int> as(n*n);
		for (int &a : as) {
			cin >> a;
		}
		sort(as.begin(), as.end());
		*/
		map<int, int> as;
		ll m = n*n;
		int a;
		int smallest = INT_MAX;
		while (m--) {
			cin >> a;
			if (as.count(a)) {
				as[a]++;
			} else {
				as[a] = 1;
			}
			if (a < smallest) {
				smallest = a;
			}
		}

		bool stop = false;
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				int calc = smallest + c*i + d*j;
				if (!as.count(calc) || as[calc] == 0) {
					cout << "NO" << endl;
					stop = true;
					break;
				}
				as[calc]--;
			}
			if (stop) break;
		}
		if (stop) continue;
		cout << "YES" << endl;
	}

    return 0;
}
