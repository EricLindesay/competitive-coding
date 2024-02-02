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

	int n,m,k;
	while (t--) {
		cin >> n >> m >> k;
		vector<int> jLow = {INT_MAX, INT_MAX};
		vector<int> jHigh = {0, 0};
		vector<int> gLow = {INT_MAX, INT_MAX};
		vector<int> gHigh = {0, 0};
		ll jSum = 0;

		int num;
		while (n--) {  // J's input first
			cin >> num;
			if (num < jLow[1]) {
				if (num < jLow[0]) {
					jLow[1] = num;
				} else {
					jLow[0] = num;
				}
			}
			if (num > jHigh[1]) {
				if (num > jHigh[0]) {
					jHigh[1] = num;
				} else {
					jHigh[0] = num;
				}
			}
			jSum += num;
		}
//		jSum -= jHigh[0] + jHigh[1];
//		jSum -= jLow[0] + jLow[1];
		while (m--) {  // G's input
			cin >> num;
			if (num < gLow[1]) {
				if (num < gLow[0]) {
					gLow[0] = num;
				} else {
					gLow[1] = num;
				}
			}
			if (num > gHigh[1]) {
				if (num > gHigh[0]) {
					gHigh[1] = num;
				} else {
					gHigh[0] = num;
				}
			}
		}

		// J gives their lowest for G's highest
		// G gives J their lowest for J's highest
		// J gives G their lowest, which is necessarily the same as the one G just gave them
		// But if J's lowest is higher than G's highest, do nothing.

		// Turn 1
		if (jLow[0] < gHigh[0]) {  // if J's lowest is less than G's highest
			jSum -= jLow[0];
			jSum += gHigh[0];
			// See where this new one should be placed
			if (gHigh[0] > jHigh[1]) {
				if (gHigh[0] > jHigh[0]) {
					// Its the new highest
					jHigh[1] = jHigh[0];
					jHigh[0] = gHigh[0];
				} else {
					// Its the second highest
					jHigh[1] = gHigh[0];
				}
			}
			if (gHigh[0] < jLow[1]) {
				jLow[0] = gHigh[0];
			} else {
				jLow[0] = jLow[1];
			}
		}

		k--;
		// Turn 2
		// G swaps their lowest with J's highest. This is always done because J will always have a higher value due to turn 1.
		if (k > 0) {
			jSum -= jHigh[0];
			jSum += gLow[0];
			gLow[0] = gLow[1];
			if (jHigh[0] > gHigh[1]) {
				if (jHigh[0] > gHigh[0]) {
					gHigh[1] = gHigh[0];
					gHigh[0] = jHigh[0];
				} else {
					gHigh[1] = jHigh[0];
				}
			}
			k--;
		}

		if (k%2 == 1) {
			jSum += gLow[0];
			jSum -= jHigh[0];
		}
		cout << jSum << '\n';
	}

    return 0;
}
