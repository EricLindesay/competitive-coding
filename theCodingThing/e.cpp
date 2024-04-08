#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	ll n;
	while (t--) {
		cin >> n;
		vector<int> as(n);
		for (int &a : as) {
			cin >> a;
		}
		sort(as.begin(), as.end());
		int sum = 0;
		int l = 0;
		int r = n-1;
		while (l < r) {
			sum += abs(as[r] - as[l]);
			l++;
			r--;
		}
		cout << sum << endl;
	}

    return 0;
}
