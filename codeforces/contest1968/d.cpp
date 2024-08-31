#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


vector<ll> perm;
vector<ll> as;
ll n;

map<ll, ll> cache;
ll rec(ll time, ll currentPos) {
	if (time == 0) {
		return 0;
	}
	ll r = as[currentPos] + max(time-1*as[currentPos], rec(time-1, perm[currentPos]));
	return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	
	ll k, pb, ps;

	while (t--) {
		perm.clear();
		as.clear();
		cin >> n >> k >> pb >> ps;
		perm.resize(n);
		as.resize(n);
		for (ll &i : perm) {
			cin >> i;
			i--;
		}
		for (ll &i : as) {
			cin >> i;
		}
		cout << "before bs" << endl;

		ll bs = rec(k, pb-1);
		cout << "after bs" << endl;
		ll ss = rec(k, ps-1);
		cout << bs << " " << ss << endl;
	}

    return 0;
}
