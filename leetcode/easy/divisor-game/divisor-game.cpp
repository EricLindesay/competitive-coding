#include <bits/stdc++.h>

#define TIMER 1

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

class Solution {
public:
    bool divisorGame(int n) {
        checkpoint("func");
		vector<bool> lookup(n+1, false);
		lookup[1] = false;
		lookup[2] = true;
		for (int i=3; i<=n; i++) {
			for (int j=1; j<i; j++) {
				// For each number, can we get a winning state from the modulos?
				if (i%j == 0 && lookup[i-j] == false) {
					lookup[i] = true;
					break;
				}	
			}
		}
		return lookup[n];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	start();
	cout << Solution().divisorGame(2) << endl;
	cout << Solution().divisorGame(3) << endl;
	cout << Solution().divisorGame(1000) << endl;
	stop("func");
	stop();
	print();

    return 0;
}
