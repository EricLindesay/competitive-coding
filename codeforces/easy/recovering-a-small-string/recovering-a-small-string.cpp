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
    int t;
    cin >> t;
	int n;

	while (t--) {
		cin >> n;
		// Do a three sum, find all possible solutions - 26^3 loops
		// find the solution with the lowest lexographical thingy
		bool found = false;
		for (int i=1; i<=26; i++) {
			for (int j=1; j<=26; j++) {
				for (int k=1; k<=26; k++) {
					if (i+j+k == n) {
						string output = "";
						output.push_back('a'+(i-1));
						output.push_back('a'+(j-1));
						output.push_back('a'+(k-1));
						cout << output << endl;
						found = true;
						break;
					}
				}
				if (found)
					break;
			}
			if (found)
				break;
		}
	}

    return 0;
}
