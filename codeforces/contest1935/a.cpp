#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t, n;
	string s;
    cin >> t;

	while (t--) {
		cin >> n >> s;
		string reversed(s.size(), '0');
		reverse_copy(s.begin(), s.end(), reversed.begin());
		if (s.compare(reversed) <= 0) {  // it is already lexographically smallest
			// do nothing
			cout << s << endl;
		} else {
			cout << reversed << s << endl;
		}
	}

    return 0;
}
