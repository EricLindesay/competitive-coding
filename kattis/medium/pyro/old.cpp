#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	vector<int> ls;
	int l;
	cin >> l;
	while (l != -1) {
		ls.push_back(l);
		cin >> l;
	}

	// map - int column -> vector the numbres with a 1 in that column

	sort(ls.begin(), ls.end());

	int n = ls.size();
	for (int i=0; i<n; ++i) {
		// Loop through all the following to find the number of matches
		int matches = 0;
		for (int j=i+1; j<n; ++j) {
			int r = ls[i] ^ ls[j];
			if (bitset<32>(r).count() <= 2) {
				++matches;
			}
		}
		cout << ls[i] << ":" << matches << endl;
	}

    return 0;
}
