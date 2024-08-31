#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n, k;
	cin >> n >> k;

	if (k >= n) {
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
	
	for (int i=0; i<k; i++) {
		cout << n-i << " ";
	}
	for (int i=1; i<=n-k; i++) {
		cout << i << " ";
	}

    return 0;
}
