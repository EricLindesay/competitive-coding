#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;

	ll ans = 0;
	queue<int> bottles;
	while (n--) {
		int i;
		cin >> i;
		// try to find a bottle twice the size
		bottles.push(i);
	}
	cout << ans;
    return 0;
}
