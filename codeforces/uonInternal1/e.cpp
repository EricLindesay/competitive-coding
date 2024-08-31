#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<int> ns(n);
	vector<int> bs(n);
	for (int &i : ns) {
		cin >> i;
	}
	for (int &i : bs) {
		cin >> i;
	}

	vector<pair<int, int>> ps(n);
	for (int i=0; i<n; i++) {
		ps[i] = make_pair(ns[i], bs[i]);
	}

	sort(ps.begin(), ps.end());
	int price = 0;
	int i=0;
	while (k > 0) {
		k -= ps[i].second;
		price = ps[i].first;
		i++;
	}
	cout << price << endl;

    return 0;
}
