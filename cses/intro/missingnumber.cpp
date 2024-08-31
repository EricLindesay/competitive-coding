#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	vector<ll> numbers(t+1, 0);
	t--;
	ll n;
	while (t--) {
		cin >> n;
		numbers[n] = 1;
	}
	for (int i=1; i<numbers.size(); i++) {
		if (!numbers[i]) {
			cout << i << endl;
			break;
		}
	}

    return 0;
}
