#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

	ll ans = 0;
	ll freq = 0;

	while (n % 2 == 0) {
		freq++;
		ans = 2;
		n /= 2;
	}

	double rt = sqrt(n);
	for (int i=3; i <= rt; i += 2) {
		ll thisFreq = 0;
		while (n % i == 0) {
			++thisFreq;
			n /= i;
		}
		if (thisFreq > freq) {
			ans = i;
			freq = thisFreq;
		}
	}

	if (freq == 0) {
		cout << n;  // if the number itself is prime
	} else {
		cout << ans;
	}

    return 0;
}
