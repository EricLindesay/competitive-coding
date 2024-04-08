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

	int cx, cy, n;

	priority_queue<double> distances;  // Queue of distances
									// Should be at most 3

	cin >> cx >> cy >> n;
	int ox, oy, radius;
	while (n--) {
		cin >> ox >> oy >> radius;
		// get distance from this listening point to the circle
		double dist = sqrt(pow(cx - ox, 2) + pow(cy - oy, 2)) - radius;
		if (distances.size() < 3) {
			distances.push(dist);
		} else if (distances.size() == 3) {
			// If there are 3 differences, if this new point is closer than previously seen, add it
			if (distances.top() > dist) {
				distances.pop();
				distances.push(dist);
			}
		}
	}
	int outputRadius = round(distances.top());

	cout << max(outputRadius, 0);
    return 0;
}
