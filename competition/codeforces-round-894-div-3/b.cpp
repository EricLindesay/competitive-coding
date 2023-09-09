#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<int> a;

		if (n == 1) {
			int b;
			cin >> b;
			cout << 1 << endl << b << endl;
			continue;
		}
	
		// take the first element
		// find if the previou element is > it. If it isn't, add that element to the output list
		int i = 0;
		while (n--) {
			int bi;
			cin >> bi;
			if (i == 0) {
				a.push_back(bi);
			} else {
				if (a[i-1] <= bi) {
					a.push_back(bi);
				} else {
					a.push_back(1);
					a.push_back(bi);
					++i;
				}
			}
			++i;
		}

		cout << a.size() << endl;
		for (int e : a) {
			cout << e << " ";
		}
		cout << endl;
	}

    return 0;
}
