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
	
	for (int i=n; i>0; i--) {
		cout << i << " ";
	}

    return 0;
}
