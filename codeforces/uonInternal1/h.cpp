#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	vector<int> as(n);  // pair of value and index
	int a;
	for (int i=0; i<n; i++) {
		cin >> a;
		as[i] = i;
	}

	int f, s;
	while (q--) {
		cin >> f >> s;
		if (f == 0) {  // constant
			// print k'th poorest
			cout << as[s-1] << endl;
		} else {  // linear in n
			// distribute from richest into s poorest
			as.pop_back(); // constant

			// We need to add the changed values onto the end
			// essentially do a rotation
			rotate(as.begin(), as.begin()+s, as.end());	// linear
		}
		
		/*
		for (int i=0; i<as.size(); i++) {
			cout << as[i].first << "(" << as[i].second << ") ";
		}
		cout << endl;*/
	}

    return 0;
}
