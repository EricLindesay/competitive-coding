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

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	vector<int> a = Solution().sequentialDigits(100, 300);
	for (int &b: a) {
		cout << b << " ";
	}
	cout << endl;

    return 0;
}
