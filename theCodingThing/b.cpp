#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	vector<ll> ns(t);

	for (ll &i : ns) {
		cin >> i;
	}
	for (int i=ns.size()-1; i>=0; i--) {
		cout << ns[i] << " ";
	}

    return 0;
}
