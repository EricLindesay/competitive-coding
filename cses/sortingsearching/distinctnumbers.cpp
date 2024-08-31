#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int defaultSort(ll n) {
	vector<int> ns(n);
	for (int &i : ns) {
		cin >> i;
	}

	sort(ns.begin(), ns.end());

	int ans = 1;
	int cur = ns[0];
	for (int i=1; i<n; i++) {
		if (ns[i] == cur) {
			continue;
		} else {
			ans++;
			cur = ns[i];
		}
	}
	return ans;
}

int usingMap(ll n) {
	map<ll, bool> m;
	int i;
	while (n--) {
		cin >> i;
		m[i] = true;
	}
	return m.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

	//cout << defaultSort(n);
	cout << usingMap(n);

    return 0;
}
