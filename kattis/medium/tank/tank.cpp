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

	int d, l;
	cin >> d >> l;

	int sx, sy;  // start x/y
	int px, py;  // previous x/y
	int cx, cy;  // current x/y

	// Get the initial point, needed for the last calculation
	cin >> sx >> sy;
	px = sx;
	py = sy;
	t--;

	double area;
	while (t--) {
		cin >> cx >> cy;
		area += (px * cy) - (cx * py);
	}

	area += (cx * sy) - (sx * cy);
	area /= 2.0f;

	// Now we have the surface area of a side.
	// We also have the depth.
	// Multiply them for the volume
	double volume = area * d;

	// volume is in cm^3
    return 0;
}
