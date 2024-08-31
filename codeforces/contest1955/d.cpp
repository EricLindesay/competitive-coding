#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> as(n);
		map<int, int> bs;
		map<int, int> bsCopy;
		for (int &a: as) {
			cin >> a;
		}
		int b;
		for (int i=0; i<m; i++) {
			cin >> b;
			if (bs.count(b)) {
				bs[b]++;
				bsCopy[b]++;
			} else {
				bs[b] = 1;
				bsCopy[b] = 1;
			}
		}

		int remaining = m;  // how much remains to be seen. If m-remaining >= k, match++
		int matches = 0;

		for (int i=n-1; i>=0; i--) {
			// Add the new element
		//	cout << "See: " << as[i] << endl;
			if (bsCopy.count(as[i])) {  // it is one we care about
				if (bsCopy[as[i]] > 0) {
					remaining--;
				}
				bsCopy[as[i]]--;
			}

			// If it is now too long, remove the right most element
			if (i < n-m) {
		//		cout << "Remove: " << as[i+m] << endl;
				if (bsCopy.count(as[i+m])) {  // it is one we care about
					// We don't want to go over the limit
					bsCopy[as[i+m]] = min(bsCopy[as[i+m]]+1, bs[as[i+m]]);
					if (bsCopy[as[i+m]] > 0) {
						remaining++;
					}
				}
			}

			/*
			for (pair<int, int> b: bsCopy) {
				cout << b.first << " " << b.second << endl;
			}
			cout << "Remaining: " << remaining << endl;
			*/
			if (i <= n-m && m - remaining >= k) {
		//		cout << "Inc" << endl;
				matches++;
			}
		//	cout << "__" << endl;
		}
		cout << matches << endl;
	}


    return 0;
}
