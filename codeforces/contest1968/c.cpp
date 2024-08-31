#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	int n;
	vector<int> x;
	vector<int> a;
	while (t--) {
		cin >> n;
		x.clear();
		a.clear();

		x.resize(n-1);
		a.resize(n);
		for (int &i : x) {
			cin >> i;
		}

		a[0] = x[0]+1;
		// a[1] must satisfy a[0] * z1 + x[1]
		// a[2] must satisfy a[1] * z2 + x[2]  = (a[0] * z1 + x[1]) * z2 + x[2]

		a[1] = x[0];
		for (int i=1; i<n; i++) {
			a[i+1] = x[i];
			for (int j=i; j>0; j--) {
				while (a[i+1]%a[i] != x[i]) {
					a[i] += a[i-1];
				}
			}
		}

		for (int i : a) {
			cout << i << " ";
		}
		cout << endl;
	}

    return 0;
}
