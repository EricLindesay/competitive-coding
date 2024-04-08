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

	int n;
	while (t--) {
		cin >> n;
		vector<int> water(n);
		int total = 0;
		for (int &i : water) {
			cin >> i;
			total += i;
		}
		int perCup = total/n;
		
		int freeWater = 0;
		bool found = false;
		for (int i=0; i<water.size(); i++) {
			if (water[i] > perCup) {  // we have more water than we need
				freeWater += water[i] - perCup;
			} else if (water[i] < perCup) {
				// We need to fill this cup with water if we have enough
				if (perCup - water[i] > freeWater) {
					cout << "NO" << endl;
					found = true;
					break;
				} else {
					freeWater -= (perCup - water[i]);
				}
			}
		}
		if (!found) {
			cout << "YES" << endl;
		}
	}

    return 0;
}
