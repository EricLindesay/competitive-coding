#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m, k;
    cin >> n >> m >> k;
	vector<int> ns(n);
	vector<int> ms(m);

	for (int &i : ns) {
		cin >> i;
	}
	for (int &i : ms) {
		cin >> i;
	}
	sort(ns.begin(), ns.end());
	sort(ms.begin(), ms.end());

	int j = 0;
	int i = 0;
	int ans = 0;
	while (i < n && j < m) {
		if (abs(ms[j]-ns[i]) <= k) {
			// This person takes the apartment
			i++;
			j++;
			ans++;
		} else if (ms[j] < ns[i]) { // the apartment is too small so check the next
			j++;
		} else {  // the apartment is too large, so this person doesn't get a house
			i++;
		}
	}
	cout << ans;

    return 0;
}
