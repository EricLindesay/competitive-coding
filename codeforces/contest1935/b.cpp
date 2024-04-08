#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
	cin >> t;

	int n;
	while (t--) {
		cin >> n;
		vector<int> as(n);
		vector<int> freqs(n, 0);
		for (int &a: as) {
			cin >> a;
			freqs[a]++;
		}
		// To split it into k subsegments, you have to make sure that there exists atleast
		// k of the smallest elements.
		// If you want to split into 5 subsections and there are 4 zeros, it won't work
		// Then you have to make sure that you can split the array so that you split all these smallest values.
		// So, count how many of each value there are, until you get a gap in a missing
		// value, this is the MEX target
		// Then try and split it
		
		// Find the first gap in the freqs array
		int mexTarget = -1;
		for (int i=0; i<n; i++) {
			if (freqs[i] == 0) {
				// This is the gap, this is the mex target
				mexTarget = i;
				break;
			}
		}
		if (mexTarget == -1) {
			// Its not possible
			cout << -1 << '\n';
			continue;
		}
		cout << "mt: " << mexTarget << endl;

		// Now find some way to split the array such that every subsection contains
		// all numbers lower than the mexTarget
		
		vector<pair<int, int>> ranges;
		// This can be done in O(n*mexTarget?), keep on going until you have accepted all
		set<int> seen;
		int l = 0;
		if (as[0] < mexTarget) {
			seen.insert(as[0]);
		}
		for (int i=0; i<n; i++) {
			if (seen.size() == mexTarget) {  // You have found a valid range
				ranges.push_back(make_pair(l, i));
				seen.clear();
				l = i+1;
			} else {
				if (as[i] < mexTarget) {
					seen.insert(as[i]);
				}
			}
		}
		// If the last range doesn't have all the numbers in then its impossible
		if (seen.size() != mexTarget) {
			cout << -1 << '\n';
			continue;
		}

		cout << ranges.size() << '\n';
		for (pair<int, int> r : ranges) {
			cout << r.first+1 << ' ' << r.second+1 << '\n';
		}
	}

    return 0;
}
