#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	int n, m, k, b, c;
	int temp;
	while (t--) {
		cin >> n >> m >> k;
		vector<int> bs, cs;
		while (n--) {
			cin >> temp;
			if (temp < k) {
				bs.push_back(temp);
			}
		}
		while (m--) {
			cin >> temp;
			if (temp < k) {
				cs.push_back(temp);
			}
		}
	
		ll out = 0;
		for (int i=0; i<bs.size(); i++) {
			for (int j=0; j<cs.size(); j++) {
				if (bs[i] + cs[j] <= k) {
					out++;
				}
			}
		}
		cout << out << endl;
	}

    return 0;
}
