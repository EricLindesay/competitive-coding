#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, w;
	cin >> n >> w;
	vector<int> ps(n);
	for (int &i : ps) {
		cin >> i;
	}

	sort(ps.rbegin(), ps.rend());

	int ans = 1;
	int cur = w;
	for (int i=0; i<n; i++) {
		if (ps[i] > cur) {
			ans++;
			cur = w-ps[i];
		} else {
			cur -= ps[i];
		}
	}

	cout << ans;

    return 0;
}
