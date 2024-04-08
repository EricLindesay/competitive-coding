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
	string line;
	int w, h;
	cin >> h >> w;
	int totalX = 0;
	int numX = 0;
	int leftMost = INT_MAX;
	int rightMost = 0;

	while (h--) {
		// Get the average x position
		// get the left most position at the bottom
		// get the right most position at the bottom
		cin >> line;
		leftMost = INT_MAX;
		rightMost = 0;
		for (int i=0; i<w; i++) {
			if (line[i] == '.') {
				continue;
			} else {
				totalX += i;
				numX++;
				if (leftMost == INT_MAX) {
					// Only do the leftmost once
					leftMost = i;
				}
				// Update the right most everytime as you find a new right
				rightMost = i;
			}
		}
	}

	double average = round((double) totalX / (double) numX);
	if (average < leftMost) {
		cout << "left";
	} else if (average > rightMost) {
		cout << "right";
	} else {
		cout << "balanced";
	}

    return 0;
}
