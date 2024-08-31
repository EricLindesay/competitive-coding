#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

// contest/1968/problem/A
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		vector<int> as(3);
		for (int &i : as) {
			cin >> i;
		}
		sort(as.begin(), as.end());

		cout << as[1] - as[0] + as[2] - as[1] << endl;
	}

    return 0;
}
