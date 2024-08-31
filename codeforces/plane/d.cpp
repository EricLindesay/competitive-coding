#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// contest/1968/problem/D  doesn't work
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
	while (t--) {
		int n;
		string s;
		cin >> n >> s;

		int out = 0;
		for (int i=0; i<n; i++) {
			if (s[i] - '0' != 1) {
				out += s[i] - '0';
			}
		}
		cout << out << endl;
	}

    return 0;
}
