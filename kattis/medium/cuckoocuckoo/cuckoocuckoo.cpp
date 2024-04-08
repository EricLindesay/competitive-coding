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

void printTime(int h, int m) {
	if (h < 10) {
		cout << '0' << h;
	} else {
		cout << h;
	}
	cout << ':';
	if (m < 10) {
		cout << '0' << m;
	} else {
		cout << m;
	}
	cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int m, h;
	char c;
	int n;

	cin >> h >> c >> m >> n;
	if (m%15 != 0) {  // scale it to the nearest 15
		m += 15 - m%15;
	}
	while (n > 0) {
		if (m == 0) {
			n -= h;
		} else {
			n--;
		}
		if (n <= 0) break;
		m += 15;
		if (m >= 60) {
			m -= 60;
			h++;
			if (h >= 13) {
				h -= 12;
			}
		}
	}
	printTime(h, m);

    return 0;
}
