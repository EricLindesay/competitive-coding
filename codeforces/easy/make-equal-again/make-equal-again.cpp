#include <bits/stdc++.h>

#define TIMER 0

#if TIMER 
// name/difficulty/base
#include "../../../myProfiler/myTimer.h"
using namespace timer;
#else 
#define start();
#define stop(...);
#define checkpoint(...);
#define print(...);
#endif

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
		vector<int> water(n);
		// find the most frequent characters
		// Try each of these most frequent and find the one with the lowest removal cost
		map<int, int> freqs;
		int highestFreq = 0;
		vector<int> bests;
		for (int &i : water) {
			cin >> i;
			freqs[i]++;
			if (freqs[i] > highestFreq) {
				highestFreq = freqs[i];
				bests.clear();
				bests.push_back(i);
			} else if (freqs[i] == highestFreq) {
				bests.push_back(i);
			}
		}
		int lowestCost = INT_MAX;
		for (int b: bests) {
			// Now work out the cost to convert this
			int thisCost = 0;
			int l=0;
			for (int i=0; i<water.size(); i++) {
				if (water[i] == b && l > 0) {
					thisCost += (i - l) + 1;
					l = -1;
				} else if (water[i] == b) {
					l = i;
				}
			}
			lowestCost = min(lowestCost, thisCost);
		}
		cout << lowestCost << endl;
	}

    return 0;
}
